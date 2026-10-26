## ShortComputation_8900_00418900 — SoundAudioObjectCleanup

**Summary:** Cleanup on sound exit: dispatches global vtable queries (0/1), frees drawable resources from cleanup list, and releases audio object at this+0xAF4 via vtable release call, then nulls the pointer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Sound_Exit (004c8d00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xAF4) | 0x0 | R | — | vtable pointer of audio object (for release call) |
| this | 0xAF4 | RW | 0 | Pointer to audio object; released and nulled |

**Written-by note (persistence):**
- this 0xAF4: set to 0 after vtable release (unconditional if non-null)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea5e8 | dword_5EA5E8 | R | MemoryCleanupList3 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00411740 | GlobalVTableDispatchWithQuery | Dispatches global vtable query (0 then 1) |
| 004150c0 | DrawableResourceCleanup | Frees drawable resources from cleanup list |

**Guard conditions:** Only if this+0xAF4 (audio object pointer) is non-null — release virtual method is called and pointer is zeroed. If null, skipped.
