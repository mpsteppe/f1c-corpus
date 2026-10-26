## SceneListCleanup_004c4cf0 — SceneLinkedListFree

**Summary:** Frees a linked list of scene/layer nodes, conditionally freeing each node's embedded data buffer based on a flag byte, then zeros the head pointers. Part of scene/layer management system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Delegation_2fe0 (004c2fe0), ArithmeticComparison_4930 (004c4930), sub_4C4D50 (004c4d50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xC) | 0x4 | R | — | linked list node's next pointer at offset 4 within each node |
| this | 0x8 | RW | 0 | linked list head pointer (loop starts iteration from here) |
| this | 0xC | RW | 0 | second scene pointer (zeroed after cleanup) |
| this | 0x10 | RW | 0 | third scene pointer (zeroed after cleanup) |
| this | 0x14 | RW | 0 | fourth scene pointer (zeroed after cleanup) |
| this | 0x18 | RW | 0 | fifth scene pointer (zeroed after cleanup) |

**Written-by note (persistence):**
- this 0x8: unconditionally zeroed at end — list head reset to NULL each call
- this 0xC: unconditionally zeroed at end
- this 0x10: unconditionally zeroed at end
- this 0x14: unconditionally zeroed at end
- this 0x18: unconditionally zeroed at end

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566650 | StringCopyWithBufferRealloc | copies/reallocates string buffer for default path |
| 00587bcf | FreeWrapper_7bcf | frees a heap-allocated block (wrapper around free) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x10 | == | 0 | one of five scene pointer fields; only zeroed at end, not tested as loop guard |

**Guard interpretation:** Code tests this+0x8 (linked list head) for non-zero. If 0, list empty — loop and all cleanup skipped. Fields 0x8-0x18 zeroed unconditionally after loop regardless.
