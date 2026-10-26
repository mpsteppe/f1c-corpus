## RenderDispatchWithIteration_004993d0 — Render dispatch with rect clamping and child iteration

**Summary:** Renders clamped sub-rectangles from a linked list onto a drawing surface, then iterates child linked list calling draw method. Core render dispatch function in UI render system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** FieldSetterWithGuardedCall (004970e0), GuardedDrawRenderDispatch (00498fe0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x44) | 0x44 | R | — | vtable slot 0x44 of child list node (draw virtual) |
| *(this+0x58) | 0x1C | R | — | sub-struct field at offset 0x1C from pointer at this+0x58 |
| *(this+0x58) | 0x20 | R | — | sub-struct field at offset 0x20 from pointer at this+0x58 |
| obj | 0x2C | R | — | vtable offset 44 (0x2C) virtual call on this (clear/reset) |
| this | 0x0 | R | — | vtable pointer for virtual dispatch |
| this | 0x4 | R | — | X offset relative to parent |
| this | 0xC | R | — | Y offset relative to parent |
| this | 0x44 | R | — | child linked list head for per-node draw dispatch |
| this | 0x4C | R | — | pointer checked against NULL; guard for continue/return |
| this | 0x50 | R | — | pointer to sub-struct containing rect bounds (+4 = y1, +12 = x1) |
| this | 0x54 | R | — | sub-struct field at offset +4 from *(this+0x50): y1/top |
| this | 0x58 | R | — | pointer to sub-struct with rect fields at offsets 0x1C and 0x20 |
| this | 0x5C | R | — | sub-struct field at offset +16 from *(this+0x50): x2/right |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cde00 | unk_7CDE00 | R | Unknown_Render_CDE00 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486320 | StructFieldAccessor | returns next child linked list node |
| 00490920 | Accessor | returns render surface/context pointer |
| 00491300 | MultiShortStructWriter | packs 4 shorts into a rectangle struct |
| 00491600 | RectangleClampConstraint | clamps rectangle to clipping region bounds |
| 00491cf0 | LinkedListFollow0x1cPointer | starts linked list traversal via offset-0x1c pointer chain |
| 00491d10 | LinkedListFieldReader | reads next node from linked-list traversal |
| 00494a30 | F_10ParamForwarder | forwards 10 rendering parameters (rect, offsets, context) |
| 00495150 | GlobalAccessor_5150 | returns global value used in render parameter calculation |
| 004b0170 | EmptyStub_0170 | cleanup/stub call per rectangle and at function exit |

**Guard conditions:** Guard: `this+0x4C != 0` — PASSES into render body; BLOCKED returns -1. Inner guard: clamped rect width (v17) > 0 AND height (v18) > 0 — PASSES issues render call; BLOCKED skips per-rect render.
