## sub_58DFC1_0058dfc1 — CriticalSectionArrayInit

**Summary:** Initializes four critical sections (lpCriticalSection, off_5E6CB4, off_5E6CA4, off_5E6C84) via InitializeCriticalSection. Called once at startup to prepare synchronization primitives for allocation/thread management.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TLSAllocationThreadIDInit (0058e060)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e16c | InitializeCriticalSection | R | Win32 API import — initialize a critical section object |
| 005e6c84 | off_5E6C84 | R | CriticalSection_Ptr4 [DERIVED] — fourth critical section pointer |
| 005e6ca4 | off_5E6CA4 | R | CriticalSectionPtr [DERIVED] — third critical section pointer |
| 005e6cb4 | off_5E6CB4 | R | CriticalSectionPtr [DERIVED] — second critical section pointer |
| 005e6cc4 | lpCriticalSection | R | CriticalSectionPtr [DERIVED] — first critical section pointer |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — straight-line function, always initializes all 4 critical sections.
