## FloatClampWithEventDispatch_004082b0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SafeDivisionWithZeroGuard (00408450), ShortComputation_f070 (0049f070)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x15 | RW | 1 | [LLM] |

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
| 004d8860 | ConditionalBranchByFlag | [LLM] |
| 005404d0 | F_2DSurfaceBlitFill | [LLM] |
| 00587bdc | CRTFtol | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
