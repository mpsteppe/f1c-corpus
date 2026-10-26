## TrackSessionClassesReader_00432a70 — TrackSessionClassListProcessor

**Summary:** Iterates through track session class entries, matching each against known vtable types (UI widget, message box, and two others). Stores matched UI widget handle at offset 0x10 and processes entries sequentially via loop.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AutoLoadEntryListLoader (00432e70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | RW | — | UI widget handle stored when a UI widget class entry is matched |

**Written-by note (persistence):**
- this 0x10: set once when matching a UI widget vtable entry. External poke survives until next call overwrites it.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c3f8c | off_5C3F8C | R | Unknown_Ptr_5C3F8C [DERIVED] |
| 005c3f90 | off_5C3F90 | R | VTable_5C3F90 [DERIVED] |
| 005c3f94 | off_5C3F94 | R | vtable_UIWidget_00432a70 [DERIVED] |
| 005c3f98 | off_5C3F98 | R | MsgBoxVtable [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005651b0 | sub_5651B0 | Reads next entry from session class list; returns 0=success, 1=end, other=skip |
| 005654a0 | sub_5654A0 | Checks if entry matches a specific vtable type |
| 00565520 | sub_565520 | Checks if entry matches UI widget vtable type |
| 00566650 | StringCopyWithBufferRealloc | Copies string with automatic buffer reallocation |
| 00566cc0 | ConditionalDispatchBasedOnFlag | Controls loop continuation based on internal flag state |
| 00587f59 | SingleFunctionCallWrapper_7f59 | Wraps/transforms matched UI widget string into handle |

**Guard conditions:** a2 and *a2 must be non-null for processing to proceed; otherwise returns 1 immediately. ConditionalDispatchBasedOnFlag controls loop entrance and continuation — if it returns 0 at either point, function returns 0. sub_5651B0 return value: 0 continues loop, 1 returns 0 (end of list), other values skip to next iteration. Entries matching off_5C3F8C, off_5C3F90, or off_5C3F98 vtables cause loop break via break statement. Matching off_5C3F94 (UI widget vtable) stores result at this[0x10].
