# Arm Mali Open Source Drivers

This repo includes arm mali gpu drivers. You can get all of them from [Arm official website](https://developer.arm.com/downloads/-/mali-drivers/bifrost-kernel)

# Mali GPU Driver Vulnerabilities

## Mali GPU Kernel Driver allows improper GPU memory processing operations

**CVE**: CVE-2024-3655  
**Date of issue**: 3rd September 2024

**Affects**:

- Bifrost GPU Kernel Driver: All versions from r43p0 – r49p0
- Valhall GPU Kernel Driver: All versions from r43p0 – r49p0
- Arm 5th Gen GPU Architecture Kernel Driver: All versions from r43p0 – r49p0

**Impact**: A local non-privileged user can make improper GPU memory processing operations to gain access to already freed memory.

**Resolution**: This issue is fixed in Bifrost, Valhall, and Arm 5th Gen GPU Architecture Kernel Driver r49p1 and r50p0. Users are recommended to upgrade if they are impacted by this issue.

**Credit**: n/a

---

## Mali GPU Kernel Driver allows improper GPU memory processing operations

**CVE**: CVE-2024-2937  
**Date of issue**: 5th August 2024

**Affects**:

- Bifrost GPU Kernel Driver: All versions from r41p0 – r49p0
- Valhall GPU Kernel Driver: All versions from r41p0 – r49p0
- Arm 5th Gen GPU Architecture Kernel Driver: All versions from r41p0 – r49p0

**Impact**: A local non-privileged user can make improper GPU memory processing operations to gain access to already freed memory.

**Resolution**: This issue is fixed in Bifrost, Valhall, and Arm 5th Gen GPU Architecture Kernel Driver r49p1 and r50p0. Users are recommended to upgrade if they are impacted by this issue.

**Credit**: n/a

---

## Mali GPU Firmware allows improper GPU processing operations

**CVE**: CVE-2024-0153  
**Date of issue**: 1st July 2024

**Affects**:

- Valhall GPU Firmware: All versions from r29p0 to r46p0
- Arm 5th Gen GPU Architecture Firmware: All versions from r41p0 to r46p0

**Impact**: A local non-privileged user can make improper GPU processing operations to access a limited amount outside of buffer bounds. If the operations are carefully prepared, then this in turn could give them access to all system memory.

**Resolution**: This issue is fixed in Valhall and Arm 5th Gen GPU Architecture Firmware r47p0. Users are recommended to upgrade if they are impacted by this issue.

**Credit**: n/a

---

## Mali GPU Kernel Driver allows improper GPU memory processing operations

**CVE**: CVE-2024-4610  
**Date of issue**: 7th June 2024

**Affects**:

- Bifrost GPU Kernel Driver: All versions from r34p0 to r40p0
- Valhall GPU Kernel Driver: All versions from r34p0 to r40p0

**Impact**: A local non-privileged user can make improper GPU memory processing operations to gain access to already freed memory.

**Resolution**: This issue is fixed in Bifrost and Valhall GPU Kernel Driver r41p0. Arm is aware of reports of this vulnerability being exploited in the wild. Users are recommended to upgrade if they are impacted by this issue.

**Credit**: n/a

---

## Mali GPU Kernel Driver allows improper GPU memory processing operations

**CVE**: CVE-2024-1395  
**Date of issue**: 3rd May 2024

**Affects**:

- Arm 5th Gen GPU Architecture Kernel Driver: All versions from r41p0 to r47p0

**Impact**: If the system's memory is carefully prepared by a local non-privileged user, they can issue improper GPU memory processing operations to gain access to already freed memory.

**Resolution**: This issue is fixed in Arm 5th Gen GPU Architecture Kernel Driver r48p0. Users are recommended to upgrade if they are impacted by this issue.

**Credit**: n/a

---

## Mali GPU Kernel Driver allows improper GPU memory processing operations

**CVE**: CVE-2024-1067  
**Date of issue**: 3rd May 2024

**Affects**:

- Bifrost GPU Kernel Driver: All versions from r41p0 to r47p0
- Valhall GPU Kernel Driver: All versions from r41p0 to r47p0
- Arm 5th Gen GPU Architecture Kernel Driver: All versions from r41p0 to r47p0

**Impact**: A local non-privileged user can make improper GPU memory processing operations. On Armv8.0 cores, certain combinations of the Linux Kernel and Mali GPU kernel driver configurations would allow the GPU operations to affect the userspace memory of other processes.

**Resolution**: This issue is fixed in Bifrost, Valhall, and Arm 5th Gen GPU Architecture Kernel Driver r48p0. Users are recommended to upgrade if they are impacted by this issue.

**Credit**: n/a

---

## Mali GPU Kernel Driver allows improper GPU processing operations

**CVE**: CVE-2023-6363  
**Date of issue**: 3rd May 2024

**Affects**:

- Valhall GPU Kernel Driver: All versions from r41p0 to r47p0
- Arm 5th Gen GPU Architecture Kernel Driver: All versions from r41p0 to r47p0

**Impact**: If the system is carefully prepared by the user, a local non-privileged user can make improper GPU memory processing operations to gain access to already freed memory.

**Resolution**: This issue is fixed in Valhall and Arm 5th Gen GPU Architecture Kernel Driver r48p0. Users are recommended to upgrade if they are impacted by this issue.

**Credit**: n/a

---

## Mali GPU Kernel Driver allows improper GPU memory processing operations

**CVE**: CVE-2024-1065  
**Date of issue**: 19th April 2024

**Affects**:

- Bifrost GPU Kernel Driver: All versions from r45p0 to r48p0
- Valhall GPU Kernel Driver: All versions from r45p0 to r48p0
- Arm 5th Gen GPU Architecture Kernel Driver: All versions from r45p0 to r48p0

**Impact**: A local non-privileged user can make improper GPU memory processing operations to gain access to already freed memory.

**Resolution**: This issue is fixed in Bifrost, Valhall, and Arm 5th Gen GPU Architecture Kernel Driver r49p0. Users are recommended to upgrade if they are impacted by this issue.

**Credit**: n/a

---

## Mali GPU Kernel Driver allows improper GPU memory processing operations

**CVE**: CVE-2024-0671  
**Date of issue**: 19th April 2024

**Affects**:

- Midgard GPU Kernel Driver: All versions from r19p0 to r32p0
- Bifrost GPU Kernel Driver: All versions from r7p0 to r48p0
- Valhall GPU Kernel Driver: All versions from r19p0 to r48p0
- Arm 5th Gen GPU Architecture Kernel Driver: All versions from r41p0 to r48p0

**Impact**: A local non-privileged user can make improper GPU memory processing operations to gain access to already freed memory.

**Resolution**: This issue is fixed in Bifrost, Valhall, and Arm 5th Gen GPU Architecture Kernel Driver r49p0. Users are recommended to upgrade if they are impacted by this issue. Please contact Arm support for Midgard GPUs.

**Credit**: n/a

---

## Mali GPU Kernel Driver allows improper GPU memory processing operations

**CVE**: CVE-2023-6241  
**Date of issue**: 4th March 2024

**Affects**:

- Midgard GPU Kernel Driver: All versions from r13p0 to r32p0
- Bifrost GPU Kernel Driver: All versions from r11p0 to r25p0
- Valhall GPU Kernel Driver: All versions from r19p0 to r25p0 and r29p0 to r46p0
- Arm 5th Gen GPU Architecture Kernel Driver: All versions from r41p0 to r46p0

**Impact**: A local non-privileged user can exploit a software race condition to perform improper memory processing operations. If the system’s memory is carefully prepared by the user, this can cause a use-after-free.

**Resolution**: This issue is fixed in the Bifrost Kernel Driver in r26p0, in the Valhall Kernel Driver in releases r26p0 and r47p0, and in the Arm 5th Gen GPU Architecture Kernel Driver in r47p0. Users are recommended to upgrade if they are impacted by this issue. Please contact Arm support for Midgard GPUs.

**Credit**: Thank you to Man Yue Mo of GitHub Security Lab for reporting this vulnerability.

---

## Mali GPU Kernel Driver allows improper GPU memory processing operations

**CVE**: CVE-2023-6143  
**Date of issue**: 4th March 2024

**Affects**:

- Midgard GPU Kernel Driver: All versions from r13p0 to r32p0
- Bifrost GPU Kernel Driver: All versions from r1p0 to r18p0
- Valhall GPU Kernel Driver: All versions from r37p0 to r46p0
- Arm 5th Gen GPU Architecture Kernel Driver: All versions from r41p0 to r46p0

**Impact**: A local non-privileged user can exploit a software race condition to perform improper memory processing operations. If the system’s memory is carefully prepared by the user and the system is under heavy load, this can cause a use-after-free.

**Resolution**: This issue is fixed in the Bifrost Kernel Driver in r19p0 and in the Valhall and Arm 5th Gen GPU Architecture Kernel Drivers in r47p0. Users are recommended to upgrade if they are impacted by this issue. Please contact Arm support for Midgard GPUs.

**Credit**: n/a

---

## Mali GPU Kernel Driver allows improper GPU memory processing operations

**CVE**: CVE-2023-5643  
**Date of issue**: 5th February 2024

**Affects**:

- Bifrost GPU Kernel Driver: All versions from r41p0 to r45p0
- Valhall GPU Kernel Driver: All versions from r41p0 to r45p0
- Arm 5th Gen GPU Architecture Kernel Driver: All versions from r41p0 to r45p0

**Impact**: A local non-privileged user can make improper GPU memory processing operations. Depending on the configuration of the Mali GPU Kernel Driver, and if the system’s memory is carefully prepared by the user, this could write to memory outside of buffer bounds.

**Resolution**: This issue is fixed in Bifrost, Valhall, and Arm 5th Gen GPU Architecture Kernel Driver r46p0. Users are recommended to upgrade if they are impacted by this issue.

**Credit**: n/a

---

## Mali GPU Kernel Driver allows improper GPU memory processing operations

**CVE**: CVE-2023-5249  
**Date of issue**: 5th February 2024

**Affects**:

- Bifrost GPU Kernel Driver: All versions from r35p0 to r40p0
- Valhall GPU Kernel Driver: All versions from r35p0 to r40p0

**Impact**: A local non-privileged user can make improper memory processing operations to exploit a software race condition. If the system’s memory is carefully prepared by the user, this can cause a use-after-free.

**Resolution**: This issue is fixed in the Bifrost and Valhall Kernel Driver in r41p0. Users are recommended to upgrade if they are impacted by this issue.

**Credit**: n/a

---

## Mali GPU Kernel Driver allows improper GPU processing operations

**CVE**: CVE-2023-5091  
**Date of issue**: 8th January 2024

**Affects**:

- Valhall GPU Kernel Driver: All versions from r37p0 to r40p0

**Impact**: A local non-privileged user can make improper GPU processing operations to gain access to already freed memory.

**Resolution**: This issue is fixed in Valhall GPU Kernel Driver r41p0. Users are recommended to upgrade if they are impacted by this issue.

**Credit**: n/a

---

## Mali GPU Userspace Driver can make an Out-of-Bounds access

**CVE**: CVE-2023-32804  
**Date of issue**: 4th December 2023

**Affects**:

- Midgard GPU Userspace Driver: All versions from r0p0 to r32p0
- Bifrost GPU Userspace Driver: All versions from r0p0 to r44p0
- Valhall GPU Userspace Driver: All versions from r19p0 to r44p0
- Arm 5th Gen GPU Architecture Userspace Driver: All versions from r41p0 to r44p0

**Impact**: A local non-privileged user can write a constant pattern to a limited amount of memory not allocated by the userspace driver.

**Resolution**: This issue is fixed in Bifrost, Valhall, and Arm 5th Gen GPU Architecture Userspace Driver r44p1 and r45p0. Users are recommended to upgrade if they are impacted by this issue. Please contact Arm support for Midgard GPUs.

**Credit**: n/a

---

## Mali GPU Kernel Driver allows improper GPU processing operations

**CVE**: CVE-2023-5427  
**Date of issue**: 1st December 2023

**Affects**:

- Bifrost GPU Kernel Driver: All versions from r44p0 to r45p0
- Valhall GPU Kernel Driver: All versions from r44p0 to r45p0
- Arm 5th Gen GPU Architecture Kernel Driver: All versions from r44p0 to r45p0

**Impact**: A local non-privileged user can make improper GPU processing operations to gain access to already freed memory.

**Resolution**: This issue is fixed in Bifrost, Valhall, and Arm 5th Gen GPU Architecture Kernel Driver r46p0. Users are recommended to upgrade if they are impacted by this issue.

**Credit**: n/a

---

## Mali GPU Kernel Driver allows improper GPU memory processing operations

**CVE**: CVE-2023-4295  
**Date of issue**: 7th November 2023

**Affects**:

- Valhall GPU Kernel Driver: All versions from r29p0 to r42p0
- Arm 5th Gen GPU Architecture Kernel Driver: All versions from r41p0 to r42p0

**Impact**: A local non-privileged user can make improper GPU memory processing operations to gain access to already freed memory.

**Resolution**: This issue is fixed in Valhall and Arm 5th Gen GPU Architecture Kernel Driver r43p0. Users are recommended to upgrade if they are impacted by this issue.

**Credit**: n/a

---

## Mali GPU Kernel Driver exposes sensitive data from freed memory

**CVE**: CVE-2023-4272  
**Date of issue**: 7th November 2023

**Affects**:

- Midgard GPU Kernel Driver: All versions from r8p0 to r32p0
- Bifrost GPU Kernel Driver: All versions from r0p0 to r41p0
- Valhall GPU Kernel Driver: All versions from r19p0 to r41p0
- Arm 5th Gen GPU Architecture Kernel Driver: r41p0

**Impact**: A local non-privileged user can make GPU processing operations that expose sensitive data from previously freed memory.

**Resolution**: This issue is fixed in Bifrost, Valhall, and Arm 5th Gen GPU Architecture Kernel Driver r42p0. Users are recommended to upgrade if they are impacted by this issue. Please contact Arm support for Midgard GPUs.

**Credit**: n/a

---

## Mali GPU Kernel Driver allows improper GPU memory processing operations

**CVE**: CVE-2023-3889  
**Date of issue**: 7th November 2023

**Affects**:

- Valhall GPU Kernel Driver: r38p0 to r44p0

**Impact**: A local non-privileged user can make improper GPU memory processing operations. If the operations are carefully prepared, they could be used to gain access to already freed memory.

**Resolution**: This issue is fixed in Valhall GPU Kernel Driver r44p1 and r45p0. Users are recommended to upgrade if they are impacted by this issue.

**Credit**: n/a

---

## Mali GPU Kernel Driver allows improper GPU memory processing operations

**CVE**: CVE-2023-4211  
**Date of issue**: 2nd October 2023

**Affects**:

- Midgard GPU Kernel Driver: All versions from r12p0 to r32p0
- Bifrost GPU Kernel Driver: All versions from r0p0 to r42p0
- Valhall GPU Kernel Driver: All versions from r19p0 to r42p0
- Arm 5th Gen GPU Architecture Kernel Driver: All versions from r41p0 to r42p0

**Impact**: A local non-privileged user can make improper GPU memory processing operations to gain access to already freed memory.

**Resolution**: This issue is fixed in Bifrost, Valhall, and Arm 5th Gen GPU Architecture Kernel Driver r43p0. There is evidence that this vulnerability may be under limited, targeted exploitation. Users are recommended to upgrade if they are impacted by this issue. Please contact Arm support for Midgard GPUs.

**Credit**: Thanks to Maddie Stone of Google's Threat Analysis Group and Jann Horn of Google Project Zero for reporting this vulnerability.

---

## Mali GPU Kernel Driver allows improper GPU memory processing operations

**CVE**: CVE-2023-33200  
**Date of issue**: 2nd October 2023

**Affects**:

- Bifrost GPU Kernel Driver: All versions from r17p0 to r44p0
- Valhall GPU Kernel Driver: All versions from r19p0 to r44p0
- Arm 5th Gen GPU Architecture Kernel Driver: All versions from r41p0 to r44p0

**Impact**: A local non-privileged user can make improper GPU processing operations to exploit a software race condition. If the system’s memory is carefully prepared by the user, this could give them access to already freed memory.

**Resolution**: This issue is fixed in Bifrost, Valhall, and Arm 5th Gen GPU Architecture Kernel Driver r44p1 and r45p0. Users are recommended to upgrade if they are impacted by this issue.

**Credit**: n/a

---

## Mali GPU Kernel Driver allows improper GPU memory processing operations

**CVE**: CVE-2023-34970  
**Date of issue**: 2nd October 2023

**Affects**:

- Valhall GPU Kernel Driver: r44p0
- Arm 5th Gen GPU Architecture Kernel Driver: r44p0

**Impact**: A local non-privileged user can make improper GPU processing operations to access a limited amount outside of buffer bounds or to exploit a software race condition. If the system’s memory is carefully prepared by the user, this could give them access to already freed memory.

**Resolution**: This issue is fixed in Valhall and Arm 5th Gen GPU Architecture Kernel Driver r44p1 and r45p0. Users are recommended to upgrade if they are impacted by this issue.

**Credit**: n/a

---

## Mali GPU Kernel Driver allows improper GPU memory processing operations

**CVE**: CVE-2023-28469  
**Date of issue**: 1st June 2023

**Affects**:

- Valhall GPU Kernel Driver: All versions from r29p0 to r42p0
- Arm 5th Gen GPU Architecture Kernel Driver: All versions from r41p0 to r42p0

**Impact**: A non-privileged user can make improper GPU processing operations to gain access to already freed memory.

**Resolution**: This issue is fixed in Valhall and Arm 5th Gen GPU Architecture Kernel Driver r43p0. Users are recommended to upgrade if they are impacted by this issue.

**Credit**: n/a

---

---

## Mali GPU Kernel Driver allows improper GPU memory processing operations

**CVE**: CVE-2023-28147  
**Date of issue**: 1st June 2023

**Affects**:

- Midgard GPU Kernel Driver: All versions from r29p0 – r32p0
- Bifrost GPU Kernel Driver: All versions from r17p0 – r42p0
- Valhall GPU Kernel Driver: All versions from r19p0 – r42p0
- Arm 5th Gen GPU Architecture Kernel Driver: All versions from r41p0 – r42p0

**Impact**: A non-privileged user can make improper GPU processing operations to gain access to already freed memory.

**Resolution**: This issue is fixed in Bifrost, Valhall, and Arm 5th Gen GPU Architecture Kernel Driver r43p0. Users are recommended to upgrade if they are impacted by this issue. Please contact Arm support for Midgard GPUs.

**Credit**: n/a

---

## Mali GPU Kernel Driver allows improper GPU memory processing operations

**CVE**: CVE-2022-46396  
**Date of issue**: 4th April 2023

**Affects**:

- Valhall GPU Kernel Driver: All versions from r29p0 to r41p0
- Arm 5th Gen GPU Architecture Kernel Driver: r41p0

**Impact**: A non-privileged user can make improper GPU memory processing operations to access a limited amount outside of buffer bounds.

**Resolution**: This issue is fixed in Valhall and Arm 5th Gen GPU Architecture Kernel Driver r42p0. Users are recommended to upgrade if they are impacted by this issue.

**Credit**: n/a

---

## Mali GPU Kernel Driver allows improper GPU memory processing operations

**CVE**: CVE-2022-46781  
**Date of issue**: 4th April 2023

**Affects**:

- Valhall GPU Kernel Driver: All versions from r29p0 to r41p0
- Arm 5th Gen GPU Architecture Kernel Driver: r41p0

**Impact**: A non-privileged user can make improper GPU memory processing operations to access a limited amount outside of buffer bounds.

**Resolution**: This issue is fixed in Valhall and Arm 5th Gen GPU Architecture Kernel Driver r42p0. Users are recommended to upgrade if they are impacted by this issue.

**Credit**: n/a

---

## Arm Reference Gralloc allows buffer over-read

**CVE**: CVE-2023-22808  
**Date of issue**: 4th April 2023

**Affects**:

- Arm 5th Gen GPU Architecture Android Gralloc Module: r41p0
- Valhall Android Gralloc Module: All versions from r24p0 to r41p0
- Bifrost Android Gralloc Module: All versions from r24p0 to r41p0

**Impact**: A non-privileged user can read a small portion of the allocator process memory.

**Resolution**: This issue is fixed in Android Gralloc Module version r42p0. Users are recommended to upgrade if they are impacted by this issue.

**Credit**: n/a

---

## Mali GPU Kernel Driver exposes sensitive kernel metadata

**CVE**: CVE-2023-26083  
**Date of issue**: 31st March 2023

**Affects**:

- Midgard GPU Kernel Driver: All versions from r6p0 to r32p0
- Bifrost GPU Kernel Driver: All versions from r0p0 to r42p0
- Valhall GPU Kernel Driver: All versions from r19p0 to r42p0
- Arm 5th Gen GPU Architecture Kernel Driver: All versions from r41p0 to r42p0

**Impact**: A non-privileged user can make valid GPU processing operations that expose sensitive kernel metadata.

**Resolution**: This issue is fixed in Bifrost, Valhall, and Arm 5th Gen GPU Architecture Kernel Driver r43p0. There is evidence that this vulnerability may be under limited, targeted exploitation. Users are recommended to upgrade if they are impacted by this issue. Please contact Arm support for Midgard GPUs.

**Credit**: Thanks to Clément Lecigne of Google's Threat Analysis Group for reporting this vulnerability.

---

## Mali GPU Kernel Driver allows improper GPU memory processing operations

**CVE**: CVE-2022-46395  
**Date of issue**: 4th December 2022

**Affects**:

- Midgard GPU Kernel Driver: All versions from r0p0 to r32p0
- Bifrost GPU Kernel Driver: All versions from r0p0 to r41p0
- Valhall GPU Kernel Driver: All versions from r19p0 to r41p0
- Arm 5th Gen GPU Architecture Kernel Driver: r41p0

**Impact**: A non-privileged user can make improper GPU processing operations to gain access to already freed memory.

**Resolution**: This issue is fixed in Bifrost, Valhall, and Arm 5th Gen GPU Architecture Kernel Driver r42p0. Users are recommended to upgrade if they are impacted by this issue. Please contact Arm support for Midgard GPUs.

**Credit**: Thank you to Man Yue Mo of GitHub Security Lab for reporting this vulnerability.

---

## Mali GPU Kernel Driver allows improper GPU memory processing operations

**CVE**: CVE-2022-46394  
**Date of issue**: 4th December 2022

**Affects**:

- Valhall GPU Kernel Driver: All versions from r39p0 to r41p0
- Arm 5th Gen GPU Architecture Kernel Driver: r41p0

**Impact**: A non-privileged user can make improper GPU processing operations to gain access to already freed memory.

**Resolution**: This issue is fixed in Valhall and Arm 5th Gen GPU Architecture Kernel Driver r42p0. Users are recommended to upgrade if they are impacted by this issue.

**Credit**: n/a

---

## Mali GPU Kernel Driver allows improper GPU memory processing operations

**CVE**: CVE-2022-46891  
**Date of issue**: 9th December 2022

**Affects**:

- Midgard GPU Kernel Driver: All versions from r13p0 to r32p0
- Bifrost GPU Kernel Driver: All versions from r1p0 to r40p0
- Valhall GPU Kernel Driver: All versions from r19p0 to r40p0

**Impact**: A non-privileged user can make improper GPU processing operations to gain access to already freed memory.

**Resolution**: This issue is fixed in Bifrost and Valhall GPU Kernel Driver r41p0. Users are recommended to upgrade if they are impacted by this issue. Please contact Arm support for Midgard GPUs.

**Credit**: n/a

---

## Mali GPU Kernel Driver allows improper GPU memory processing operations

**CVE**: CVE-2022-42716  
**Date of issue**: 10th October 2022

**Affects**:

- Valhall GPU Kernel Driver: All versions from r29p0 to r40p0

**Impact**: A non-privileged user can make improper GPU processing operations to gain access to already freed memory.

**Resolution**: This issue is fixed in Valhall GPU Kernel Driver r41p0. Users are recommended to upgrade if they are impacted by this issue.

**Credit**: Thanks to Jann Horn from Google Project Zero for reporting this vulnerability.

---

## Mali GPU Kernel Driver allows improper GPU memory processing operations

**CVE**: CVE-2022-41757  
**Date of issue**: 29th September 2022

**Affects**:

- Valhall GPU Kernel Driver: All versions from r29p0 to r38p1, and r39p0

**Impact**: A non-privileged user can make improper GPU memory processing operations to gain write access to read-only memory or obtain access to already freed memory.

**Resolution**: This issue is fixed in Valhall GPU Kernel Driver r38p2 and r40p0. Users are recommended to upgrade if they are impacted by this issue.

**Credit**: Thanks to Le Wu from Baidu Security for reporting this vulnerability.

---

## Mali GPU Kernel Driver allows improper GPU memory processing operations

**CVE**: CVE-2022-38181  
**Date of issue**: 12th August 2022

**Affects**:

- Midgard GPU Kernel Driver: All versions from r4p0 to r32p0
- Bifrost GPU Kernel Driver: All versions from r0p0 to r38p1, and r39p0
- Valhall GPU Kernel Driver: All versions from r19p0 to r38p1, and r39p0

**Impact**: A non-privileged user can make improper GPU processing operations to gain access to already freed memory.

**Resolution**: This issue is fixed in Bifrost and Valhall GPU Kernel Driver r38p2 and r40p0. Users are recommended to upgrade if they are impacted by this issue. Please contact Arm support for Midgard GPUs.

**Credit**: Thank you to Man Yue Mo of GitHub Security Lab for reporting this vulnerability.

---

## Mali GPU Kernel Driver allows improper GPU memory processing operations

**CVE**: CVE-2022-36449  
**Date of issue**: 24th July 2022

**Affects**:

- Midgard GPU Kernel Driver: All versions from r4p0 to r32p0
- Bifrost GPU Kernel Driver: All versions from r0p0 to r38p0, and r39p0
- Valhall GPU Kernel Driver: All versions from r19p0 to r38p0, and r39p0

**Impact**: A non-privileged user can make improper GPU processing operations to gain access to already freed memory, write a limited amount outside of buffer bounds, or disclose details of memory mappings.

**Resolution**: This issue is fixed in Bifrost and Valhall GPU Kernel Driver r38p1 and r40p0. Users are recommended to upgrade if they are impacted by this issue. Please contact Arm support for Midgard GPUs.

**Credit**: n/a

---

## Mali GPU Kernel Driver allows access to already freed memory

**CVE**: CVE-2022-34830  
**Date of issue**: 29th June 2022

**Affects**:

- Utgard GPU Kernel Driver: All versions from r11p0 to r12p0

**Impact**: A non-privileged user can make improper GPU processing operations to gain access to already freed memory.

**Resolution**: This issue is fixed in Utgard GPU Kernel Driver r13p0. Users are recommended to upgrade if they are impacted by this issue.

**Credit**: Thanks to Le Wu from Baidu Security for reporting this vulnerability.

---

## Mali Kernel Driver allows improper GPU processing operations

**CVE**: CVE-2022-33917  
**Date of issue**: 17th June 2022

**Affects**:

- Valhall GPU Kernel Driver: All versions from r29p0 to r38p0

**Impact**: A non-privileged user can make improper GPU processing operations to gain access to already freed memory.

**Resolution**: This issue is fixed in Valhall GPU Kernel Driver versions r38p1 and r39p0. Users are recommended to upgrade if they are impacted by this issue.

**Credit**: n/a

---

## Mali GPU Kernel Driver allows access to already freed memory

**CVE**: CVE-2022-28349  
**Date of issue**: 2nd April 2022

**Affects**:

- Midgard GPU Kernel Driver: All versions from r28p0 to r29p0
- Bifrost GPU Kernel Driver: All versions from r17p0 to r23p0
- Valhall GPU Kernel Driver: All versions from r19p0 to r23p0

**Impact**: A non-privileged user can obtain access to already freed memory.

**Resolution**: This issue is fixed in Bifrost and Valhall GPU Kernel Driver version r24p0 and in Midgard GPU Kernel Driver version r30p0. Users are recommended to upgrade if they are impacted by this issue.

**Credit**: n/a

---

## Mali GPU Kernel Driver allows improper GPU processing operations

**CVE**: CVE-2022-28350  
**Date of issue**: 2nd April 2022

**Affects**:

- Valhall GPU Kernel Driver: All versions from r29p0 to r36p

**Impact**: A non-privileged user can make improper GPU processing operations to gain access to already freed memory.

**Resolution**: This issue is fixed in Valhall GPU Kernel Driver r37p0. Users are recommended to upgrade if they are impacted by this issue.

**Credit**: Thank you to Le Wu from Baidu Security for reporting this vulnerability.

---

## Mali GPU Kernel Driver allows improper operations on GPU memory

**CVE**: CVE-2022-28348  
**Date of issue**: 2nd April 2022

**Affects**:

- Midgard GPU Kernel Driver: All versions from r4p0 to r31p0
- Bifrost GPU Kernel Driver: All versions from r0p0 to r36p0
- Valhall GPU Kernel Driver: All versions from r19p0 to r36p0

**Impact**: A non-privileged user can make improper operations on GPU memory to enter into a use-after-free scenario.

**Resolution**: This issue is fixed in Bifrost and Valhall GPU Kernel Driver r37p0 and in Midgard Kernel Driver r32p0. Users are recommended to upgrade if they are impacted by this issue.

**Credit**: n/a

---

## Mali GPU Kernel Driver may elevate CPU RO pages to writable

**CVE**: CVE-2022-22706 (also reported in CVE-2021-39793)  
**Date of issue**: 6th January 2022

**Affects**:

- Midgard GPU Kernel Driver: All versions from r26p0 to r31p0
- Bifrost GPU Kernel Driver: All versions from r0p0 to r35p0
- Valhall GPU Kernel Driver: All versions from r19p0 to r35p0

**Impact**: A non-privileged user can get write access to read-only memory pages.

**Resolution**: This issue is fixed in Bifrost and Valhall GPU Kernel Driver r36p0 and in Midgard Kernel Driver r32p0. There is evidence that this vulnerability may be under limited, targeted exploitation. Users are recommended to upgrade if they are impacted by this issue.

**Credit**: n/a

---

## Mali GPU Kernel Driver elevates CPU RO pages to writable

**CVE**: CVE-2021-44828  
**Date of issue**: 11th December 2021

**Affects**:

- Midgard GPU Kernel Driver: All versions from r26p0 to r31p0
- Bifrost GPU Kernel Driver: All versions from r0p0 to r34p0
- Valhall GPU Kernel Driver: All versions from r19p0 to r34p0

**Impact**: A non-privileged user can get write access to read-only memory and may be able to gain root privilege, corrupt memory, and modify the memory of other processes.

**Resolution**: This issue is fixed in Bifrost and Valhall GPU Kernel Driver r35p0 and in Midgard Kernel Driver r32p0. Users are recommended to upgrade if they are impacted by this issue.

**Credit**: n/a

---

## Mali GPU Kernel Driver allows improper operations on GPU memory

**CVE**: CVE-2021-28663  
**Date of issue**: 18th March 2021

**Affects**:

- Midgard GPU Kernel Driver: All versions from r4p0 to r30p0
- Bifrost GPU Kernel Driver: All versions from r0p0 to r28p0
- Valhall GPU Kernel Driver: All versions from r19p0 to r28p0

**Impact**: A non-privileged user can make improper operations on GPU memory to enter into a use-after-free scenario and may be able to gain root privilege and/or disclose information.

**Resolution**: This issue is fixed in Bifrost and Valhall GPU Kernel Driver r29p0 and in Midgard Kernel Driver r31p0. Users are recommended to upgrade if they are impacted by this issue.

**Credit**: n/a

---

## Mali GPU Kernel Driver elevates CPU RO pages to writable

**CVE**: CVE-2021-28664  
**Date of issue**: 18th March 2021

**Affects**:

- Midgard GPU Kernel Driver: All versions from r8p0 to r30p0
- Bifrost GPU Kernel Driver: All versions from r0p0 to r29p0
- Valhall GPU Kernel Driver: All versions from r19p0 to r29p0

**Impact**: A non-privileged user can get write access to read-only memory and may be able to gain root privilege, corrupt memory, and modify the memory of other processes.

**Resolution**: This issue is fixed in Bifrost and Valhall GPU Kernel Driver r30p0 and in Midgard GPU Kernel Driver r31p0. Users are recommended to upgrade if they are impacted by this issue.

**Credit**: n/a

---

## Mali GPU Kernel Driver allows improper operations on GPU memory

**CVE**: CVE-2021-29256  
**Date of issue**: 26th March 2021

**Affects**:

- Midgard GPU Kernel Driver: All versions from r28p0 to r30p0
- Bifrost GPU Kernel Driver: All versions from r16p0 to r29p0
- Valhall GPU Kernel Driver: All versions from r19p0 to r29p0

**Impact**: A non-privileged user can make improper operations on GPU memory to gain access to already freed memory and may be able to gain root privilege and/or disclose information.

**Resolution**: This issue is fixed in Bifrost and Valhall GPU Kernel Driver r30p0 and in Midgard Kernel Driver r31p0. Users are recommended to upgrade if they are impacted by this issue.

**Credit**: Thanks to Brice Berna of the Apple Media Products RedTeam for reporting this vulnerability.

---