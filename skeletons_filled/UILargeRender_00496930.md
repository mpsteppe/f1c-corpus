## UILargeRender_00496930 — Main UI render/dispatch frame handler

**Summary:** Per-frame UI rendering and input dispatch handler: resolves active UI element via collision classification, manages element lifecycle (creation/destruction), dispatches per-type rendering (string accessors, alpha blend, FPS overlay), processes input action map, and handles click events. Part of the UI system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_485B90 (00485b90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x156C)+0x0) | 0x48 | R | — | UI element vtable function pointer (offset 0x48) |
| *(*(this+0x156C)+0x0) | 0x4C | R | — | UI element vtable function pointer (offset 0x4C) |
| *(*(this+0x156C)+0x0) | 0x50 | R | — | UI element vtable function pointer (offset 0x50) |
| *(*(this+0x156C)+0x0) | 0x5C | R | — | UI element vtable function pointer (offset 0x5C) |
| *(*(this+0x156C)+0x0) | 0x60 | R | — | UI element vtable function pointer (offset 0x60) |
| *(*(this+0x156C)+0x0) | 0x64 | R | — | UI element vtable function pointer (offset 0x64) |
| *(*(this+0x156C)+0x0) | 0x78 | R | — | UI element vtable function pointer (offset 0x78) |
| *(*(this+0x156C)+0x0) | 0x7C | R | — | UI element vtable function pointer (offset 0x7C) |
| *(*(this+0x156C)+0x0) | 0x8C | R | — | UI element vtable function pointer (offset 0x8C) |
| *(*(this+0x156C)+0x0) | 0x90 | R | — | UI element vtable function pointer (offset 0x90) |
| *(*(this+0x156C)+0x0) | 0x94 | R | — | UI element vtable function pointer (offset 0x94) |
| *(*(this+0x18)+0x0) | 0x38 | R | — | sub-element vtable function pointer (offset 0x38) |
| *(*(this+0x18)+0x0) | 0x3C | R | — | sub-element vtable function pointer (offset 0x3C) |
| *(*(this+0x20)+0x0) | 0x58 | R | — | additional sub-element vtable function (offset 0x58) |
| *(this+0x156C) | 0x0 | R | — | active UI element vtable pointer (first word) |
| *(this+0x18) | 0x0 | R | — | previous frame UI element vtable pointer |
| *(this+0x20) | 0x0 | R | — | additional previous element vtable pointer |
| this | 0x18 | R | — | pointer to previous UI element (for lifecycle comparison) |
| this | 0x20 | R | — | pointer to additional previous sub-element |
| this | 0x28 | RW | 2 | UI state mode (forced to 2 if not already 2) |
| this | 0x58 | R | — | current viewport x position |
| this | 0x5C | R | — | current viewport y position |
| this | 0x60 | R | — | current viewport width |
| this | 0x64 | R | — | current viewport height |
| this | 0x68 | R | — | additional viewport dimension |
| this | 0x6C | R | — | additional viewport dimension |
| this | 0x74 | RW | — | collision response type (set by CollisionResponseTypeClassification) |
| this | 0x78 | RW | — | copy of viewport x for previous-frame tracking |
| this | 0x7C | RW | — | copy of viewport y for previous-frame tracking |
| this | 0x80 | RW | — | copy of viewport width for previous-frame tracking |
| this | 0x84 | RW | — | copy of viewport height for previous-frame tracking |
| this | 0x88 | RW | — | copy of additional viewport dimension |
| this | 0x8C | RW | — | copy of additional viewport dimension |
| this | 0x94 | RW | — | previous-frame collision response type |
| this | 0xC0 | R | — | input device count (for action map loop) |
| this | 0xC4 | RW | 0 | input action map loop index (reset to 0 each frame) |
| this | 0xCC | RW | — | accumulated scroll offset (float, += delta in case 5) |
| this | 0xD0 | R | — | scroll offset base |
| this | 0xD4 | R | — | scroll offset max/clamp |
| this | 0x1558 | R | — | file path buffer pointer for UI element loading |
| this | 0x1560 | R | — | additional path buffer pointer |
| this | 0x1564 | R | — | flags/status field for file loading |
| this | 0x156C | RW | 0 | active UI element pointer (set by ObjectSearchWithDoubleIteration) |
| this | 0x1598 | RW | 0 | multiplayer UI sub-mode flag |

**Written-by note (persistence):**
- this 0x28: recalc every frame — external poke does NOT persist
- this 0x74: recalc every frame — external poke does NOT persist
- this 0x78: recalc every frame — external poke does NOT persist
- this 0x7C: recalc every frame — external poke does NOT persist
- this 0x80: recalc every frame — external poke does NOT persist
- this 0x84: recalc every frame — external poke does NOT persist
- this 0x88: recalc every frame — external poke does NOT persist
- this 0x8C: recalc every frame — external poke does NOT persist
- this 0x94: recalc every frame — external poke does NOT persist
- this 0xC4: recalc every frame — external poke does NOT persist
- this 0xCC: recalc every frame — external poke does NOT persist
- this 0x156C: recalc every frame — external poke does NOT persist
- this 0x1598: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00496dd8 | jpt_49698B | R | jump table for collision response type switch dispatch |
| 00496de0 | byte_496DE0 | R | switch case byte data for type routing |
| 00496dec | jpt_496A74 | R | jump table for UI element render type switch |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005ac994 | flt_5AC994 | R | Flt_AiSteeringGain_C994 [DERIVED] |
| 005cc9e8 | dword_5CC9E8 | R | SessionInitState [CONFIRMED] (also: ` — multiplayer active flag) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007cb218 | dword_7CB218 | R | InputDeviceCount [DERIVED] |
| 007cb21c | word_7CB21C | R | InputActionMap [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486240 | UIStringAccessor | get string data from UI element (type 1/2/6 path) |
| 00486260 | UIStringAccessor_6260 | get string data from UI element (type 3/7 path) |
| 00486280 | UIStringAccessor_6280 | get string data from UI element (type 4 path) |
| 004862a0 | UIStringAccessor_62a0 | get string data from UI element (type 5/8 path) |
| 00495440 | FPSOverlayDraw | draw FPS counter overlay |
| 004957a0 | UIClickEventDispatch | dispatch mouse click events to UI elements |
| 00495980 | ObjectSearchWithDoubleIteration | find active UI element via double-iteration search |
| 00496880 | sub_496880 | multiplayer-specific UI handler |
| 00496e20 | sub_496E20 | early-exit guard check before main render |
| 004979c0 | Setter | set/update UI element property |
| 00497e80 | sub_497E80 | render string/get render context from string accessor |
| 00498030 | RendererAlphaBlendSetter | set alpha blend state for renderer |
| 004986a0 | RenderStateReset | reset render state after drawing |
| 00498720 | CollisionSpeedSetter | set collision response speed |
| 00498740 | InitViewportDimensions | initialize viewport dimensions from render state |
| 004987b0 | CollisionResponseTypeClassification | classify mouse position into UI collision response type |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x28 | != | 2 | UI state mode not already 2 — force set to 2 |
| this | 0x74 | == | 1 | collision type 1 with active element — call Setter |
| this | 0x74 | == | 2 | collision type 2 — trigger vtable call 92 |
| this | 0x74 | == | 5 | collision type 5 — accumulate scroll offset |
| this | 0x1598 | > | 0 | multiplayer sub-mode active — call sub_496880 |

**Guard interpretation:** UI state mode (0x28) is always forced to 2 if not already 2 — unconditional normal mode enforcement. Collision type (0x74) drives the main render switch: types 1-2 use basic string rendering, type 3/7 include file-loading sub-paths, type 4 handles element lifecycle transitions, types 5/8 handle scroll accumulation, type 6 mirrors type 2, types 12-13 call dedicated vtable methods, and default types have no action. Multiplayer sub-mode (0x1598 > 0) triggers additional UI processing via sub_496880 when session state is 5.
