## CriticalSectionEnterWithLazyInit_00595a61 — CRTFileCriticalSectionEnter

**Summary:** Enters the critical section for a CRT file descriptor index (a1). Lazily initializes the CRITICAL_SECTION at offset+12 via CriticalSectionLazyInitEnter/CritSectLeave guard if the init count at offset+8 is zero.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_58C331 (0058c331), sub_58C724 (0058c724), sub_58C9B4 (0058c9b4), sub_58E22B (0058e22b), sub_592891 (00592891), sub_595801 (00595801), sub_595F11 (00595f11), sub_59B650 (0059b650), sub_59B760 (0059b760)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e16c | InitializeCriticalSection | R | Windows API — initializes CRITICAL_SECTION at offset+12 in entry |
| 0059e174 | EnterCriticalSection | R | Windows API — enters the initialized critical section |
| 008d4920 | dword_8D4920 | R | CriticalSectionArray (stride 0x24) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058dfea | CriticalSectionLazyInitEnter | acquires guard lock (slot 17) for thread-safe lazy init |
| 0058e04b | CritSectLeave | releases guard lock (slot 17) after lazy init |

**Guard conditions:** Checks `*(_DWORD*)(v2 + 8) == 0` (init flag / refcount). If zero, performs lazy init: acquires guard lock, double-checks flag, calls InitializeCriticalSection, increments flag, releases guard. Then always calls EnterCriticalSection. PASSES: always enters the critical section. Blocked only if guard lock fails internally.
