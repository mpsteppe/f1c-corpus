## ObjectNameComparison_00477280 — ViewportObjectNameMatcher

**Summary:** Compares name strings at offset 0x34 of two objects (this[39] and `a2`). If names match, searches a linked list for `a2`; if not found, creates a new viewport node, appends it, and recalculates layout.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SwitchOnActionIDVirtualCall (004670e0), VTableDispatchWithConditionalCreation (0046fdc0), ResourceCheckDispatch (0046fdf0), StateCheckConditionalDispatch (0046fe20), ConditionalUISubsystemDispatch (0046fe50), SessionSetupScreenSetup (00470960), VirtualFactoryPathFormat (00472400), SceneGraphQueryConditionalCall (00472bc0), ResourceCheckVirtualCall (00473650), ConditionalInitWithGlobalRefSetup (00473b90), CommandDispatchWithGuard (00479ca0), ShortComputation_9d00 (00479d00), ResourceCheckDispatch_9e80 (00479e80), VTableDispatch (0047a260), CommandDispatchWithGuard_a640 (0047a640), DualStateCheckedDispatch (0047e680)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xF0) | 0x30 | R | — | data pointer at offset 0x30 from first list node |
| this | 0x9C | R | — | pointer to first comparison object (name at offset 0x34) |
| this | 0xD0 | R | — | unknown |
| this | 0xF0 | R | — | linked list head |
| this | 0xF8 | R | — | unknown |
| this | 0xFC | R | — | list count / bound for iteration |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048f5d0 | DoublyLinkedListAppend_f5d0 | appends a node to the doubly linked list |
| 0048f640 | UIViewportLayoutCalculator | recalculates viewport layout after list modification |
| 0048fd60 | Constructor_fd60 | constructs a new viewport node object (52 bytes) |
| 0048fdb0 | ViewportRectSizeCalc | calculates viewport rectangle size for a2 |
| 00587c03 | OperatorNewNhMallocWrapper | allocates heap memory (52 bytes for new node) |

**Guard conditions:** `this[39]` (offset 0x9C) must be non-null AND `*(a2+156)` must be non-null → proceed; `strcmp()` must return 0 (names at offset 0x34 match) → enter list search; list iteration bound `i < this[63]`; node at offset 0x30 equals `a2` → found path (skip creation)
