## ConditionalDelegation_6460_00486460 — SubObjectIndexedNodeLookup

**Summary:** Looks up a node by zero-based index within a linked list reachable through a sub-object at this+0xC8. Returns the node pointer at the requested index, or null if the sub-object is absent or the index exceeds the bound.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AIOvertakeGapCalc (0047ab35), TimedAnimationTrigger (00486730), ScrollbarAreaRendering (004868c0), UIScrollViewRender (00486ac0), UITextBoxRendererWithScrollbar (004883d0), sub_489D00 (00489d00), F_2DSurfaceBlitWithViewportClipping (0048a240), TextInputRender (0048b9c0), sub_48CCB0 (0048ccb0), MediaBufferPlaybackManager (0048d9d0), UIDimensionCapture (0048ebd0), ConditionalDispatchWithCleanup (0048fdf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0xD0)+0x24) | 0x24 | R | — | next-pointer (offset 0x24) within a linked list node |
| this | 0xC8 | R | — | pointer to sub-object containing list metadata (head at +0x8, bound at +0xC) |
| this | 0xD0 | R | — | intermediate pointer in sub-object chain used for node access |
| this | 0xD4 | R | — | unused in this function (present in struct layout) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** checks this[50] (offset 0xC8, sub-object pointer) != NULL → if null, returns 0 (BLOCKED). Checks a2 > bound value at subobject+0xC → if exceeded, returns 0 (BLOCKED). Then traverses a2 steps following next pointers at node+0x24; null node mid-traversal returns that null (BLOCKED). Returns node at index a2 (PASSES).
