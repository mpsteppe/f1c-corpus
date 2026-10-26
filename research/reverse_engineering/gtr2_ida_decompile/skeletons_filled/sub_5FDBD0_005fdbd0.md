## sub_5FDBD0_005fdbd0 — Destructor: release holder and free owned blocks

**Summary:** Destructor for the dynamic geometry object: if the holder (this+0x40) has a non-null field at +4 it is released through sub_5EA540 and zeroed; then the list reset (sub_5FDB10) runs and each owned allocation is freed — blocks at this+0x60, +0x50 and +0x58, the holder itself at +0x40, the 132-byte-stride record array at +0x34 (via the MSVC `eh vector destructor iterator' with its count cookie), and the pointer list at +0x38. Always returns 0.

**Called by:** sub_5FDD80 (005fdd80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x40) | 0x4 | RW | 0 | Holder field released via sub_5EA540 and then zeroed (resource handle/pointer inside the holder object) |
| this | 0x34 | R | — | Record array pointer (with MSVC allocation cookie at -4); elements are 0x84 bytes each and are destroyed by the vector destructor iterator |
| this | 0x38 | R | — | Pointer list array; freed directly if non-null |
| this | 0x40 | R | — | Holder object; passed through the no-op stub then freed |
| this | 0x50 | R | — | Owned block (source template data); freed if non-null |
| this | 0x58 | R | — | Owned block (index pattern data); freed if non-null |
| this | 0x60 | R | — | Owned data area (flush source); freed if non-null |

**Written-by note (persistence):**
- *(this+0x40) 0x4: conditionally zeroed once, immediately after the release call, only when the value was nonzero; during destruction the object is being torn down anyway, so persistence beyond this call is irrelevant.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005f2f60 | j_nullsub_7 | R | No-op stub (thunk to nullsub_7) used as the element destructor for the vector destructor iterator and called directly on the holder before freeing it |
| 00fb27f8 | dword_FB27F8 | R | Global context/manager passed as first argument to sub_5EA540 for the release of holder+4 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005ea540 | sub_5EA540 | Releases/detaches the resource referenced by holder+4 (manager-level free/detach call with a2 and flags 0) |
| 005f2f60 | j_nullsub_7 | No-op element destructor used by the vector destructor iterator; also called on the holder object |
| 005fdb10 | sub_5FDB10 | Resets the active record list and invokes the global no-arg reset callback |
| 006308d3 | j__free | CRT free for the owned blocks and arrays |
| 0063093b | ??_M@YGXPAXIHP6EX0@Z@Z | MSVC `eh vector destructor iterator' — destroys each 0x84-byte record with j_nullsub_7 using the element count stored before the array |

**Guard conditions:** No function-level early exit; each step is individually guarded by its pointer being non-null: the release + zeroing runs only when holder+4 is nonzero; each j__free (this+0x60, +0x50, +0x58, holder at +0x40, record array at +0x34, list at +0x38) runs only when its pointer is non-null. The vector destructor iterator runs when the record array pointer (this+0x34) is non-null, using the element count found just before the array. Return value is always 0.
