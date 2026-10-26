## UIFocusChange_0054f7a0 — SceneFocusAndRenderUpdate

**Summary:** Updates UI focus state, prepares rendering batch transform, processes render list elements, and runs scene batch collision detection. Called per-frame for scene/interaction updates.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SwitchBasedStateHandler (0040f380), SphereProximityTag (004bdb10), AIRacingLinePathFollowing (004e9ca0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1E0 | R | — | pointer to scene render state descriptor (null check guard) |
| this | 0x204 | R | — | pointer to render batch node for transform setup |
| this | 0x218 | RW | — | focus collision/result count (written via dword_8C5F40 from RenderListIteration) |

**Written-by note (persistence):**
- this 0x218: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b8f24 | dword_8B8F24 | R | D3DDeviceWrapperPtr [DERIVED] (also: ` — D3D device wrapper / scene manager singleton vtable (docs/22) |
| 008c5f40 | dword_8C5F40 | W | AudioOutputHandle [DERIVED] |
| 008c5f44 | dword_8C5F44 | W | UIFocusFlag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054b570 | sub_54B570 | prepares render batch for drawing (enables transform pipeline) |
| 0054f5c0 | SceneBatchRenderCheck | checks batch visibility and runs collision detection |
| 0054f710 | RenderListIteration | processes render list elements, applies D3D transforms, counts type-2 elements |

**Guard conditions:** If a2 == this (self-reference) OR this[120] (this+0x1E0) is null → skip entire function (BLOCKED). PASSES: a2 != this AND render state descriptor non-null.
