// SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note
/*
 *
 * (C) COPYRIGHT 2018-2023 ARM Limited. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU license.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, you can access it online at
 * http://www.gnu.org/licenses/gpl-2.0.html.
 *
 */

#include "hwcnt/mali_kbase_hwcnt_types.h"

#include <linux/slab.h>

int kbase_hwcnt_metadata_create(const struct kbase_hwcnt_description *desc,
				const struct kbase_hwcnt_metadata **out_metadata)
{
	char *buf;
	struct kbase_hwcnt_metadata *metadata;
	struct kbase_hwcnt_group_metadata *grp_mds;
	size_t grp;
	size_t enable_map_count; /* Number of u64 bitfields (inc padding) */
	size_t dump_buf_count; /* Number of u64 values (inc padding) */
	size_t avail_mask_bits; /* Number of availability mask bits */
	size_t block_state_count;
	size_t size;
	size_t offset;

	if (!desc || !out_metadata)
		return -EINVAL;

	/* The maximum number of clock domains is 64. */
	if (desc->clk_cnt > (sizeof(u64) * BITS_PER_BYTE))
		return -EINVAL;

	/* Calculate the bytes needed to tightly pack the metadata */

	/* Top level metadata */
	size = 0;
	size += sizeof(struct kbase_hwcnt_metadata);

	/* Group metadata */
	size += sizeof(struct kbase_hwcnt_group_metadata) * desc->grp_cnt;

	/* Block metadata */
	for (grp = 0; grp < desc->grp_cnt; grp++) {
		size += sizeof(struct kbase_hwcnt_block_metadata) * desc->grps[grp].blk_cnt;
	}

	/* Single allocation for the entire metadata */
	buf = kmalloc(size, GFP_KERNEL);
	if (!buf)
		return -ENOMEM;

	/* Use the allocated memory for the metadata and its members */

	/* Bump allocate the top level metadata */
	offset = 0;
	metadata = (struct kbase_hwcnt_metadata *)(buf + offset);
	offset += sizeof(struct kbase_hwcnt_metadata);

	/* Bump allocate the group metadata */
	grp_mds = (struct kbase_hwcnt_group_metadata *)(buf + offset);
	offset += sizeof(struct kbase_hwcnt_group_metadata) * desc->grp_cnt;

	enable_map_count = 0;
	dump_buf_count = 0;
	block_state_count = 0;
	avail_mask_bits = 0;

	for (grp = 0; grp < desc->grp_cnt; grp++) {
		size_t blk;

		const struct kbase_hwcnt_group_description *grp_desc = desc->grps + grp;
		struct kbase_hwcnt_group_metadata *grp_md = grp_mds + grp;

		size_t group_enable_map_count = 0;
		size_t group_dump_buffer_count = 0;
		size_t group_avail_mask_bits = 0;
		size_t group_state_count = 0;

		/* Bump allocate this group's block metadata */
		struct kbase_hwcnt_block_metadata *blk_mds =
			(struct kbase_hwcnt_block_metadata *)(buf + offset);
		offset += sizeof(struct kbase_hwcnt_block_metadata) * grp_desc->blk_cnt;

		/* Fill in each block in the group's information */
		for (blk = 0; blk < grp_desc->blk_cnt; blk++) {
			const struct kbase_hwcnt_block_description *blk_desc = grp_desc->blks + blk;
			struct kbase_hwcnt_block_metadata *blk_md = blk_mds + blk;
			const size_t n_values = blk_desc->hdr_cnt + blk_desc->ctr_cnt;

			blk_md->type = blk_desc->type;
			blk_md->inst_cnt = blk_desc->inst_cnt;
			blk_md->hdr_cnt = blk_desc->hdr_cnt;
			blk_md->ctr_cnt = blk_desc->ctr_cnt;
			blk_md->enable_map_index = group_enable_map_count;
			blk_md->enable_map_stride = kbase_hwcnt_bitfield_count(n_values);
			blk_md->dump_buf_index = group_dump_buffer_count;
			blk_md->dump_buf_stride = KBASE_HWCNT_ALIGN_UPWARDS(
				n_values,
				(KBASE_HWCNT_BLOCK_BYTE_ALIGNMENT / KBASE_HWCNT_VALUE_BYTES));
			blk_md->avail_mask_index = group_avail_mask_bits;
			blk_md->blk_stt_index = group_state_count;
			blk_md->blk_stt_stride = KBASE_HWCNT_BLOCK_STATE_STRIDE;

			group_enable_map_count += blk_md->enable_map_stride * blk_md->inst_cnt;
			group_dump_buffer_count += blk_md->dump_buf_stride * blk_md->inst_cnt;
			group_avail_mask_bits += blk_md->inst_cnt;
			group_state_count += blk_md->inst_cnt * blk_md->blk_stt_stride;
		}

		/* Fill in the group's information */
		grp_md->type = grp_desc->type;
		grp_md->blk_cnt = grp_desc->blk_cnt;
		grp_md->blk_metadata = blk_mds;
		grp_md->enable_map_index = enable_map_count;
		grp_md->dump_buf_index = dump_buf_count;
		grp_md->avail_mask_index = avail_mask_bits;
		grp_md->blk_stt_index = block_state_count;

		enable_map_count += group_enable_map_count;
		dump_buf_count += group_dump_buffer_count;
		avail_mask_bits += group_avail_mask_bits;
		block_state_count += group_state_count;
	}

	/* Fill in the top level metadata's information */
	metadata->grp_cnt = desc->grp_cnt;
	metadata->grp_metadata = grp_mds;
	metadata->enable_map_bytes = enable_map_count * KBASE_HWCNT_BITFIELD_BYTES;
	metadata->dump_buf_bytes = dump_buf_count * KBASE_HWCNT_VALUE_BYTES;
	metadata->blk_stt_bytes = block_state_count * KBASE_HWCNT_BLOCK_STATE_BYTES;
	metadata->avail_mask = desc->avail_mask;
	metadata->clk_cnt = desc->clk_cnt;

	WARN_ON(size != offset);
	/* Due to the block alignment, there should be exactly one enable map
	 * bit per 4 bytes in the dump buffer.
	 */
	WARN_ON(metadata->dump_buf_bytes !=
		(metadata->enable_map_bytes * BITS_PER_BYTE * KBASE_HWCNT_VALUE_BYTES));

	*out_metadata = metadata;
	return 0;
}

void kbase_hwcnt_metadata_destroy(const struct kbase_hwcnt_metadata *metadata)
{
	kfree(metadata);
}

int kbase_hwcnt_enable_map_alloc(const struct kbase_hwcnt_metadata *metadata,
				 struct kbase_hwcnt_enable_map *enable_map)
{
	u64 *enable_map_buf;

	if (!metadata || !enable_map)
		return -EINVAL;

	if (metadata->enable_map_bytes > 0) {
		enable_map_buf = kzalloc(metadata->enable_map_bytes, GFP_KERNEL);
		if (!enable_map_buf)
			return -ENOMEM;
	} else {
		enable_map_buf = NULL;
	}

	enable_map->metadata = metadata;
	enable_map->hwcnt_enable_map = enable_map_buf;
	return 0;
}

void kbase_hwcnt_enable_map_free(struct kbase_hwcnt_enable_map *enable_map)
{
	if (!enable_map)
		return;

	kfree(enable_map->hwcnt_enable_map);
	enable_map->hwcnt_enable_map = NULL;
	enable_map->metadata = NULL;
}

int kbase_hwcnt_dump_buffer_alloc(const struct kbase_hwcnt_metadata *metadata,
				  struct kbase_hwcnt_dump_buffer *dump_buf)
{
	size_t dump_buf_bytes;
	size_t clk_cnt_buf_bytes;
	size_t block_state_bytes;
	u8 *buf;

	if (!metadata || !dump_buf)
		return -EINVAL;

	dump_buf_bytes = metadata->dump_buf_bytes;
	clk_cnt_buf_bytes = sizeof(*dump_buf->clk_cnt_buf) * metadata->clk_cnt;
	block_state_bytes = metadata->blk_stt_bytes;

	/* Make a single allocation for dump_buf, clk_cnt_buf and block_state_buf. */
	buf = kzalloc(dump_buf_bytes + clk_cnt_buf_bytes + block_state_bytes, GFP_KERNEL);
	if (!buf)
		return -ENOMEM;

	dump_buf->metadata = metadata;
	dump_buf->dump_buf = (u64 *)buf;
	dump_buf->clk_cnt_buf = (u64 *)(buf + dump_buf_bytes);
	dump_buf->blk_stt_buf = (blk_stt_t *)(buf + dump_buf_bytes + clk_cnt_buf_bytes);

	return 0;
}

void kbase_hwcnt_dump_buffer_free(struct kbase_hwcnt_dump_buffer *dump_buf)
{
	if (!dump_buf)
		return;

	kfree(dump_buf->dump_buf);
	memset(dump_buf, 0, sizeof(*dump_buf));
}

void kbase_hwcnt_dump_buffer_zero(struct kbase_hwcnt_dump_buffer *dst,
				  const struct kbase_hwcnt_enable_map *dst_enable_map)
{
	const struct kbase_hwcnt_metadata *metadata;
	size_t grp, blk, blk_inst;

	if (WARN_ON(!dst) || WARN_ON(!dst_enable_map) ||
	    WARN_ON(dst->metadata != dst_enable_map->metadata))
		return;

	metadata = dst->metadata;

	kbase_hwcnt_metadata_for_each_block(metadata, grp, blk, blk_inst)
	{
		u64 *dst_blk;
		size_t val_cnt;

		if (!kbase_hwcnt_enable_map_block_enabled(dst_enable_map, grp, blk, blk_inst))
			continue;

		dst_blk = kbase_hwcnt_dump_buffer_block_instance(dst, grp, blk, blk_inst);
		val_cnt = kbase_hwcnt_metadata_block_values_count(metadata, grp, blk);

		kbase_hwcnt_dump_buffer_block_zero(dst_blk, val_cnt);
	}

	memset(dst->clk_cnt_buf, 0, sizeof(*dst->clk_cnt_buf) * metadata->clk_cnt);
	memset(dst->blk_stt_buf, 0, metadata->blk_stt_bytes);
}

void kbase_hwcnt_dump_buffer_zero_strict(struct kbase_hwcnt_dump_buffer *dst)
{
	if (WARN_ON(!dst))
		return;

	memset(dst->dump_buf, 0, dst->metadata->dump_buf_bytes);
	memset(dst->clk_cnt_buf, 0, sizeof(*dst->clk_cnt_buf) * dst->metadata->clk_cnt);
	memset(dst->blk_stt_buf, 0, dst->metadata->blk_stt_bytes);
}

void kbase_hwcnt_dump_buffer_zero_non_enabled(struct kbase_hwcnt_dump_buffer *dst,
					      const struct kbase_hwcnt_enable_map *dst_enable_map)
{
	const struct kbase_hwcnt_metadata *metadata;
	size_t grp, blk, blk_inst;

	if (WARN_ON(!dst) || WARN_ON(!dst_enable_map) ||
	    WARN_ON(dst->metadata != dst_enable_map->metadata))
		return;

	metadata = dst->metadata;

	kbase_hwcnt_metadata_for_each_block(metadata, grp, blk, blk_inst)
	{
		u64 *dst_blk = kbase_hwcnt_dump_buffer_block_instance(dst, grp, blk, blk_inst);
		blk_stt_t *dst_blk_stt =
			kbase_hwcnt_dump_buffer_block_state_instance(dst, grp, blk, blk_inst);
		const u64 *blk_em =
			kbase_hwcnt_enable_map_block_instance(dst_enable_map, grp, blk, blk_inst);
		size_t val_cnt = kbase_hwcnt_metadata_block_values_count(metadata, grp, blk);

		/* Align upwards to include padding bytes */
		val_cnt = KBASE_HWCNT_ALIGN_UPWARDS(
			val_cnt, (KBASE_HWCNT_BLOCK_BYTE_ALIGNMENT / KBASE_HWCNT_VALUE_BYTES));

		if (kbase_hwcnt_metadata_block_instance_avail(metadata, grp, blk, blk_inst)) {
			/* Block available, so only zero non-enabled values */
			kbase_hwcnt_dump_buffer_block_zero_non_enabled(dst_blk, blk_em, val_cnt);

			if (!kbase_hwcnt_enable_map_block_enabled(dst_enable_map, grp, blk,
								  blk_inst))
				kbase_hwcnt_block_state_set(dst_blk_stt, KBASE_HWCNT_STATE_UNKNOWN);

		} else {
			/* Block not available, so zero the entire thing */
			kbase_hwcnt_dump_buffer_block_zero(dst_blk, val_cnt);
			kbase_hwcnt_block_state_set(dst_blk_stt, KBASE_HWCNT_STATE_UNKNOWN);
		}
	}
}

void kbase_hwcnt_dump_buffer_copy(struct kbase_hwcnt_dump_buffer *dst,
				  const struct kbase_hwcnt_dump_buffer *src,
				  const struct kbase_hwcnt_enable_map *dst_enable_map)
{
	const struct kbase_hwcnt_metadata *metadata;
	size_t grp, blk, blk_inst;
	size_t clk;

	if (WARN_ON(!dst) || WARN_ON(!src) || WARN_ON(!dst_enable_map) || WARN_ON(dst == src) ||
	    WARN_ON(dst->metadata != src->metadata) ||
	    WARN_ON(dst->metadata != dst_enable_map->metadata))
		return;

	metadata = dst->metadata;

	kbase_hwcnt_metadata_for_each_block(metadata, grp, blk, blk_inst)
	{
		u64 *dst_blk;
		const u64 *src_blk;
		blk_stt_t *dst_blk_stt;
		const blk_stt_t *src_blk_stt;
		size_t val_cnt;

		if (!kbase_hwcnt_enable_map_block_enabled(dst_enable_map, grp, blk, blk_inst))
			continue;

		dst_blk = kbase_hwcnt_dump_buffer_block_instance(dst, grp, blk, blk_inst);
		src_blk = kbase_hwcnt_dump_buffer_block_instance(src, grp, blk, blk_inst);
		dst_blk_stt = kbase_hwcnt_dump_buffer_block_state_instance(dst, grp, blk, blk_inst);
		src_blk_stt = kbase_hwcnt_dump_buffer_block_state_instance(src, grp, blk, blk_inst);
		val_cnt = kbase_hwcnt_metadata_block_values_count(metadata, grp, blk);

		kbase_hwcnt_dump_buffer_block_copy(dst_blk, src_blk, val_cnt);
		kbase_hwcnt_block_state_copy(dst_blk_stt, src_blk_stt);
	}

	kbase_hwcnt_metadata_for_each_clock(metadata, clk)
	{
		if (kbase_hwcnt_clk_enable_map_enabled(dst_enable_map->clk_enable_map, clk))
			dst->clk_cnt_buf[clk] = src->clk_cnt_buf[clk];
	}
}

void kbase_hwcnt_dump_buffer_copy_strict(struct kbase_hwcnt_dump_buffer *dst,
					 const struct kbase_hwcnt_dump_buffer *src,
					 const struct kbase_hwcnt_enable_map *dst_enable_map)
{
	const struct kbase_hwcnt_metadata *metadata;
	size_t grp, blk, blk_inst;
	size_t clk;

	if (WARN_ON(!dst) || WARN_ON(!src) || WARN_ON(!dst_enable_map) || WARN_ON(dst == src) ||
	    WARN_ON(dst->metadata != src->metadata) ||
	    WARN_ON(dst->metadata != dst_enable_map->metadata))
		return;

	metadata = dst->metadata;

	kbase_hwcnt_metadata_for_each_block(metadata, grp, blk, blk_inst)
	{
		u64 *dst_blk = kbase_hwcnt_dump_buffer_block_instance(dst, grp, blk, blk_inst);
		const u64 *src_blk =
			kbase_hwcnt_dump_buffer_block_instance(src, grp, blk, blk_inst);
		blk_stt_t *dst_blk_stt =
			kbase_hwcnt_dump_buffer_block_state_instance(dst, grp, blk, blk_inst);
		const blk_stt_t *src_blk_stt =
			kbase_hwcnt_dump_buffer_block_state_instance(src, grp, blk, blk_inst);
		const u64 *blk_em =
			kbase_hwcnt_enable_map_block_instance(dst_enable_map, grp, blk, blk_inst);
		size_t val_cnt = kbase_hwcnt_metadata_block_values_count(metadata, grp, blk);
		/* Align upwards to include padding bytes */
		val_cnt = KBASE_HWCNT_ALIGN_UPWARDS(
			val_cnt, (KBASE_HWCNT_BLOCK_BYTE_ALIGNMENT / KBASE_HWCNT_VALUE_BYTES));

		kbase_hwcnt_dump_buffer_block_copy_strict(dst_blk, src_blk, blk_em, val_cnt);

		if (kbase_hwcnt_enable_map_block_enabled(dst_enable_map, grp, blk, blk_inst))
			kbase_hwcnt_block_state_copy(dst_blk_stt, src_blk_stt);
		else
			kbase_hwcnt_block_state_set(dst_blk_stt, KBASE_HWCNT_STATE_UNKNOWN);
	}

	kbase_hwcnt_metadata_for_each_clock(metadata, clk)
	{
		bool clk_enabled =
			kbase_hwcnt_clk_enable_map_enabled(dst_enable_map->clk_enable_map, clk);

		dst->clk_cnt_buf[clk] = clk_enabled ? src->clk_cnt_buf[clk] : 0;
	}
}

void kbase_hwcnt_dump_buffer_accumulate(struct kbase_hwcnt_dump_buffer *dst,
					const struct kbase_hwcnt_dump_buffer *src,
					const struct kbase_hwcnt_enable_map *dst_enable_map)
{
	const struct kbase_hwcnt_metadata *metadata;
	size_t grp, blk, blk_inst;
	size_t clk;

	if (WARN_ON(!dst) || WARN_ON(!src) || WARN_ON(!dst_enable_map) || WARN_ON(dst == src) ||
	    WARN_ON(dst->metadata != src->metadata) ||
	    WARN_ON(dst->metadata != dst_enable_map->metadata))
		return;

	metadata = dst->metadata;

	kbase_hwcnt_metadata_for_each_block(metadata, grp, blk, blk_inst)
	{
		u64 *dst_blk;
		const u64 *src_blk;
		blk_stt_t *dst_blk_stt;
		const blk_stt_t *src_blk_stt;
		size_t hdr_cnt;
		size_t ctr_cnt;

		if (!kbase_hwcnt_enable_map_block_enabled(dst_enable_map, grp, blk, blk_inst))
			continue;

		dst_blk = kbase_hwcnt_dump_buffer_block_instance(dst, grp, blk, blk_inst);
		src_blk = kbase_hwcnt_dump_buffer_block_instance(src, grp, blk, blk_inst);
		dst_blk_stt = kbase_hwcnt_dump_buffer_block_state_instance(dst, grp, blk, blk_inst);
		src_blk_stt = kbase_hwcnt_dump_buffer_block_state_instance(src, grp, blk, blk_inst);
		hdr_cnt = kbase_hwcnt_metadata_block_headers_count(metadata, grp, blk);
		ctr_cnt = kbase_hwcnt_metadata_block_counters_count(metadata, grp, blk);

		kbase_hwcnt_dump_buffer_block_accumulate(dst_blk, src_blk, hdr_cnt, ctr_cnt);
		kbase_hwcnt_block_state_accumulate(dst_blk_stt, src_blk_stt);
	}

	kbase_hwcnt_metadata_for_each_clock(metadata, clk)
	{
		if (kbase_hwcnt_clk_enable_map_enabled(dst_enable_map->clk_enable_map, clk))
			dst->clk_cnt_buf[clk] += src->clk_cnt_buf[clk];
	}
}

void kbase_hwcnt_dump_buffer_accumulate_strict(struct kbase_hwcnt_dump_buffer *dst,
					       const struct kbase_hwcnt_dump_buffer *src,
					       const struct kbase_hwcnt_enable_map *dst_enable_map)
{
	const struct kbase_hwcnt_metadata *metadata;
	size_t grp, blk, blk_inst;
	size_t clk;

	if (WARN_ON(!dst) || WARN_ON(!src) || WARN_ON(!dst_enable_map) || WARN_ON(dst == src) ||
	    WARN_ON(dst->metadata != src->metadata) ||
	    WARN_ON(dst->metadata != dst_enable_map->metadata))
		return;

	metadata = dst->metadata;

	kbase_hwcnt_metadata_for_each_block(metadata, grp, blk, blk_inst)
	{
		u64 *dst_blk = kbase_hwcnt_dump_buffer_block_instance(dst, grp, blk, blk_inst);
		const u64 *src_blk =
			kbase_hwcnt_dump_buffer_block_instance(src, grp, blk, blk_inst);
		const u64 *blk_em =
			kbase_hwcnt_enable_map_block_instance(dst_enable_map, grp, blk, blk_inst);
		blk_stt_t *dst_blk_stt =
			kbase_hwcnt_dump_buffer_block_state_instance(dst, grp, blk, blk_inst);
		const blk_stt_t *src_blk_stt =
			kbase_hwcnt_dump_buffer_block_state_instance(src, grp, blk, blk_inst);

		size_t hdr_cnt = kbase_hwcnt_metadata_block_headers_count(metadata, grp, blk);
		size_t ctr_cnt = kbase_hwcnt_metadata_block_counters_count(metadata, grp, blk);
		/* Align upwards to include padding bytes */
		ctr_cnt = KBASE_HWCNT_ALIGN_UPWARDS(
			hdr_cnt + ctr_cnt,
			(KBASE_HWCNT_BLOCK_BYTE_ALIGNMENT / KBASE_HWCNT_VALUE_BYTES) - hdr_cnt);

		kbase_hwcnt_dump_buffer_block_accumulate_strict(dst_blk, src_blk, blk_em, hdr_cnt,
								ctr_cnt);

		if (kbase_hwcnt_enable_map_block_enabled(dst_enable_map, grp, blk, blk_inst))
			kbase_hwcnt_block_state_accumulate(dst_blk_stt, src_blk_stt);
		else
			kbase_hwcnt_block_state_set(dst_blk_stt, KBASE_HWCNT_STATE_UNKNOWN);
	}

	kbase_hwcnt_metadata_for_each_clock(metadata, clk)
	{
		if (kbase_hwcnt_clk_enable_map_enabled(dst_enable_map->clk_enable_map, clk))
			dst->clk_cnt_buf[clk] += src->clk_cnt_buf[clk];
		else
			dst->clk_cnt_buf[clk] = 0;
	}
}

void kbase_hwcnt_dump_buffer_block_state_update(struct kbase_hwcnt_dump_buffer *dst,
						const struct kbase_hwcnt_enable_map *dst_enable_map,
						blk_stt_t blk_stt_val)
{
	const struct kbase_hwcnt_metadata *metadata;
	size_t grp, blk, blk_inst;

	if (WARN_ON(!dst) || WARN_ON(!dst_enable_map) ||
	    WARN_ON(dst->metadata != dst_enable_map->metadata))
		return;

	metadata = dst->metadata;

	kbase_hwcnt_metadata_for_each_block(metadata, grp, blk, blk_inst)
	{
		if (kbase_hwcnt_metadata_block_instance_avail(metadata, grp, blk, blk_inst) &&
		    kbase_hwcnt_enable_map_block_enabled(dst_enable_map, grp, blk, blk_inst)) {
			blk_stt_t *dst_blk_stt = kbase_hwcnt_dump_buffer_block_state_instance(
				dst, grp, blk, blk_inst);

			/* Block is available and enabled, so update the block state */
			*dst_blk_stt |= blk_stt_val;
		}
	}
}
