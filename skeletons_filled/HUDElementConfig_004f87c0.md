## HUDElementConfig_004f87c0 — indexed HUD element force feedback configuration

**Summary:** Configures an indexed HUD element with force feedback gain and magnitude values. Selects gain source based on a flag in a sub-struct and clamps output index to [0,3].

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** Gearbox (00443b70), VehicleMainPhysicsUpdate (004441f0), VisualStateChange (00447c70), sub_4E51A0 (004e51a0), sub_4F0430 (004f0430), VehicleSoundTrigger (004f12e0), PerIndexStructFieldSetter (004f8850), SoundEffectTrigger (004f88a0), SoundEffectTrigger_89a0 (004f89a0), RandomParameterDispatch (004f8a70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x32C8 | R | — | flag selecting force feedback gain source (non-zero = ForceFeedbackGain, zero = Flt_ForceFeedbackMult) |
| this | 0x0 | R | — | pointer to sub-struct containing configuration flag |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cf338 | flt_7CF338 | R | Flt_ForceFeedbackMult [DERIVED] |
| 007cf35c | flt_7CF35C | R | ForceFeedbackGain [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Flag at obj+0x32C8: non-zero → uses ForceFeedbackGain, keeps a3 index unchanged. Zero → uses Flt_ForceFeedbackMult, increments a3 by 1. a3 is then clamped to [0, 3].
