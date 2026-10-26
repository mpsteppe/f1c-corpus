## FloatClampWithEventDispatch_004082b0 — FloatClampWithEventDispatch

**Summary:** Clamps a float value toward a target bound with exponential cooling/lerp, dispatches conditional events based on zero/non-zero state, and renders 2D fill rectangles for UI overlay. Part of physics/UI integration system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SafeDivisionWithZeroGuard (00408450), ShortComputation_f070 (0049f070)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Current float value, clamped toward target each frame |
| this | 0x4 | R | — | Clamp target/bound value |
| this | 0x8 | R | — | Cooling rate multiplier applied to global dbl_8AFE90 |
| this | 0xC | R | — | Rectangle height/coordinate for blit fill |
| this | 0x10 | R | — | Scale factor multiplied with base value for computed render size |
| this | 0x15 | RW | 1 | Event dispatch flag (byte), tracks whether conditional event was dispatched |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist
- this 0x15: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005be8f8 | flt_5BE8F8 | R | SerializationScaleFactor [DERIVED] (also: ` — global float constant (serialization constant area, docs/12) |
| 008ad298 | dword_8AD298 | R | SessionModeIdentifier [DERIVED] |
| 008ad2a0 | dword_8AD2A0 | R | EventDispatchEnable [DERIVED] (also: Event dispatch enable flag) |
| 008afe90 | dbl_8AFE90 | R | EngineCoolingRate [DERIVED] (also: ` — cooling rate per frame) |
| 008b78a0 | dword_8B78A0 | R | SoundManager [DERIVED] |
| 008b8dc8 | dword_8B8DC8 | R | RenderDevicePtr [DERIVED] (also: RenderDevicePtr (D3D device/renderer interface, docs/12, docs/19) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d8860 | ConditionalBranchByFlag | Dispatches conditional event (0 = active/start, 1 = done/stop) based on zero state |
| 005404d0 | F_2DSurfaceBlitFill | Renders a filled rectangle on the 2D surface for UI overlay |
| 00587bdc | CRTFtol | Converts float to long (int) for pixel coordinate rendering |

**Guard conditions:** this[0] == 0.0 → event-done path (ConditionalBranchByFlag(1), flag cleared). this[0] != 0.0 AND dword_8AD2A0 != -1 → event-active path (ConditionalBranchByFlag(0), flag set). this[0] < this[1] → ramp up toward target. this[0] > this[1] → ramp down toward target. Both ramps clamped to exactly this[1].
