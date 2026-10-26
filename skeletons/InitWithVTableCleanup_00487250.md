## InitWithVTableCleanup_00487250 — SetVTableAndCleanup

**Summary:** Sets vtable pointer to WidgetBase (off_5AB968) then calls sub_485EB0 cleanup/destructor handler. Destructor path that resets vtable before cleanup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DestructorConditionalDelete (0046fd30), ConstructorWithVTableAndSubInit_5510 (00485510), ShortComputation_5540 (00485540), ShortComputation_5570 (00485570), DestructorConditionalDelete_55a0 (004855a0), DestructorWithVTableReset_55d0 (004855d0), DestructorWithConditionalFree_5600 (00485600), DestructorWithVTable (00485630), DestructorWithConditionalFree_5660 (00485660), sub_485690 (00485690), ShortComputation_56c0 (004856c0), ObjectConstructor_56f0 (004856f0), LinkedListBufferDestructor (004857e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer — set to off_5AB968 (WidgetBase) before cleanup |

**Written-by note (persistence):**
- this 0x0: set unconditionally every call; external poke overwritten (destructor path, set before cleanup)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ab968 | off_5AB968 | R | VTable_WidgetBase [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None (unconditional — sets vtable then calls cleanup).
