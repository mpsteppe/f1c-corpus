## sub_58A0BF_0058a0bf — HeapSlotValidateAll

**Summary:** Iterates all thread heap slots from the global slot array (dword_8D4A24), acquires per-slot critical sections, and validates open file streams via MemoryBlockValidationCheck. Mode a1=1 counts valid streams; mode a1=0 returns -1 if any writable stream has errors.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** LockCallUnlockWrapper (00589ffd), ThunkToSub58A0BF (0058a0b6)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008d4a24 | dword_8D4A24 | R | HeapSlotArrayPtr [DERIVED] |
| 008d5a40 | dword_8D5A40 | R | ThreadPoolCount [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a02c | MemoryBlockValidationCheck | Validate file stream buffer and handle |
| 0058c1e0 | CriticalSectionEnter | Enter per-slot critical section |
| 0058c232 | CriticalSectionLeave_c232 | Leave per-slot critical section |
| 0058dfea | CriticalSectionLazyInitEnter | Enter global critical section (slot 2) |
| 0058e04b | CritSectLeave | Leave global critical section |

**Guard conditions:** Always enters global critical section (slot 2) first. PASSES when slot pointer is non-null and its file flags (offset +12) have bit 0x83 set — enters per-slot critical section and calls MemoryBlockValidationCheck. BLOCKED (skipped) when slot is null or file not open. Mode a1==1 counts successful validations; mode a1==0 returns -1 on first write-error stream.
