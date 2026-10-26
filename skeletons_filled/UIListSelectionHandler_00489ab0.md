## UIListSelectionHandler_00489ab0 — List item selection handler

**Summary:** Sets selection index (this[0x168]), optionally scrolls to make it visible. Walks linked list to selected node, reads 4 text strings, passes them to vtable display method at offset 168 (0xA8). Returns 0 on success, -1 on invalid index.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DualCallWrapper_af00 (0046af00), UIListSearchAndSelect (00489ba0), UIListManagementHandler (0048a3c0), SessionStateDispatch (004a0df0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xA8 | R | — | vtable method offset 168 — updates selected item display with 4 strings |
| this | 0x0 | R | — | vtable pointer |
| this | 0x90 | R | — | this[36] — linked list head pointer |
| this | 0x94 | R | — | this[37] — total items count (max selection index bound) |
| this | 0x14C | RW | — | this[83] — scroll offset / first visible item index |
| this | 0x164 | R | — | this[89] — visible items count per page |
| this | 0x168 | RW | 18446744073709551615 | this[90] — current selection index (0-based, init -1 = none) |
| this | 0x1A8 | R | — | unknown — not directly referenced in this function |
| this | 0x1BC | R | — | unknown — not directly referenced in this function |
| this | 0x1C4 | R | — | unknown — not directly referenced in this function |
| this | 0x1CC | R | — | unknown — not directly referenced in this function |
| this | 0x1D4 | R | — | unknown — not directly referenced in this function |

**Written-by note (persistence):**
- this 0x14C: written when selection is out of visible range and a3 scroll flag is set, or set to -1 on invalid index; survives across calls until overwritten
- this 0x168: written on every call (a2-1) or -1 on invalid selection; init value is -1 (none)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00489d00 | sub_489D00 | recalculates list state after scroll offset change |
| 00489e90 | FloatToIntConversion | updates scroll position/animation after scroll adjustment |

**Guard conditions:** a2 (1-based selection index) must be within [1, this[0x94]]; if out of range, sets this[0x168] = -1 and returns -1. Linked list head (this[0x90]) must be non-null; if null, returns -1. Traversal must reach target index before end of list.
