## VtableEntryNotifyCleanup_00408520 — VTable Entry Notify Cleanup

**Summary:** Switches vtable to VTable_59E60C, iterates 9 sub-object pointers at this+0x10..0x30 calling virtual function (arg=1, one at +0x28 uses arg=3) on each non-null entry, then switches vtable to VTable_SceneNodeChain. Acts as a notify-and-teardown sequence for child nodes.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConditionalFreeByFlag (00408500)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x10) | 0x0 | R | — | Sub-object 0 vtable pointer (first child node) |
| *(this+0x14) | 0x0 | R | — | Sub-object 1 vtable pointer |
| *(this+0x18) | 0x0 | R | — | Sub-object 2 vtable pointer |
| *(this+0x1C) | 0x0 | R | — | Sub-object 3 vtable pointer |
| *(this+0x20) | 0x0 | R | — | Sub-object 4 vtable pointer |
| *(this+0x24) | 0x0 | R | — | Sub-object 5 vtable pointer |
| *(this+0x28) | 0x0 | R | — | Sub-object 6 vtable pointer (called with arg=3 instead of 1) |
| *(this+0x2C) | 0x0 | R | — | Sub-object 7 vtable pointer |
| *(this+0x30) | 0x0 | R | — | Sub-object 8 vtable pointer |
| this | 0x0 | RW | — | Vtable pointer (switched twice) |
| this | 0x10 | R | — | Offset to first sub-object pointer |
| this | 0x14 | R | — | Offset to second sub-object pointer |
| this | 0x18 | R | — | Offset to third sub-object pointer |
| this | 0x1C | R | — | Offset to fourth sub-object pointer |
| this | 0x20 | R | — | Offset to fifth sub-object pointer |
| this | 0x24 | R | — | Offset to sixth sub-object pointer |
| this | 0x28 | R | — | Offset to seventh sub-object pointer |
| this | 0x2C | R | — | Offset to eighth sub-object pointer |
| this | 0x30 | R | — | Offset to ninth sub-object pointer |

**Written-by note (persistence):**
- this 0x0: Written twice in function (to off_59E60C then off_59E634). External poke does NOT survive — both writes originate here.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e60c | off_59E60C | R | VTable_59E60C [DERIVED] |
| 0059e634 | off_59E634 | R | VTable_SceneNodeChain [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** For each of the 9 sub-object pointers at offsets 0x10, 0x14, 0x18, 0x1C, 0x20, 0x24, 0x28, 0x2C, 0x30: if pointer is non-null, calls its first vtable entry (index 0) with argument 1 (or 3 for offset 0x28); if null, skips that sub-object.
