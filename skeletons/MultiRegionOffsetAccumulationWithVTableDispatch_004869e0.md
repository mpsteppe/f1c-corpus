## MultiRegionOffsetAccumulationWithVTableDispatch_004869e0 — ScrollOffsetAccumulateAndNotify

**Summary:** Offsets four rectangle bounds (left, right, top, bottom) by (a3, a2), renders the union of old+new rectangle as damaged area, notifies self via vtable offset 44, and propagates offset recursively to child elements. Returns result of vtable offset 160 (end-state handler). Part of UI scroll/pan region system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LinkedListAppend_8eb0 (00498eb0), ObjectRegistration (00499360)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x11C) | 0x8C | R | — | child node's next pointer (offset 140) for linked-list traversal |
| obj | 0x2C | R | — | vtable offset 44 — self-notify method after offset update |
| obj | 0xA0 | R | — | vtable offset 160 — end-state getter/handler, return value of function |
| this | 0x0 | R | — | vtable pointer |
| this | 0x4 | RW | — | left coordinate of scroll region |
| this | 0x8 | RW | — | right coordinate of scroll region |
| this | 0xC | RW | — | top coordinate of scroll region |
| this | 0x10 | RW | — | bottom coordinate of scroll region |
| this | 0x90 | R | — | pointer to head of child linked list |

**Written-by note (persistence):**
- this 0x4: incremented by a3 every call; external poke overwritten each call
- this 0x8: incremented by a3 every call; external poke overwritten each call
- this 0xC: incremented by a2 every call; external poke overwritten each call
- this 0x10: incremented by a2 every call; external poke overwritten each call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004869e0 | MultiRegionOffsetAccumulationWithVTableDispatch | recursive self-call to propagate offset to child elements |
| 00499050 | GuardedSubRectangleRenderDispatch | render the union rectangle of old and new positions (damaged area) |

**Guard conditions:** None (no early-return branches). Computes bounding union, dispatches render, updates all four offsets unconditionally, then notifies and recurses to children.
