## MultiLineTextDraw_0040bd10 — File Load And Dispatch To Camera Entries

**Summary:** Loads a file (removing read-only attribute), dispatches its content to each entry in a stride-208 array at this+0xC (count at this+0x10) via vtable+8 calls. Returns 0 if any entry received data, 1 if none.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | Base pointer of stride-208 camera entry array (dispatched to each entry) |
| this | 0x10 | R | — | Entry count of the array (loop bound, must be > 0) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005668b0 | ZeroInitSmallStruct | Zero-initializes the file-loading temp struct on stack |
| 005668d0 | SubCallWithConditionalFieldFree | Frees temp struct fields if allocated |
| 00566940 | sub_566940 | Opens file for reading (a3 non-zero path) |
| 00566a70 | sub_566A70 | Opens file for reading (a3 zero path) |
| 00566b90 | ConditionalFileHandleCloseWithFlagDispatch | Closes file handle after loading |
| 0058ba36 | ToggleFileReadOnlyAttributeViaWin32API | Removes FILE_ATTRIBUTE_READONLY (128) from file |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x10 | > | 0 | Entry count of the dispatch array |

**Guard interpretation:** lpFileName must be non-null AND this[3] (offset 0xC, array base) must be non-null or function returns 1 immediately. v8[0] must be non-zero after file load or dispatch is skipped (goto LABEL_7). Loop runs only when this[4] (offset 0x10) > 0.
