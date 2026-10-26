## VehicleSoundTrigger_004f12e0 — VehicleSoundTrigger

**Summary:** Triggers vehicle sound/HUD events based on wheel contact/force surface types, velocity change, timer state, and rigid body status. Part of vehicle audio/HUD system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4F0430 (004f0430)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x3668)+0x54) | 0x30 | R | — | Wheel force surface type identifier |
| *(*(this+0x3668)+0x54) | 0x34 | R | — | Wheel contact surface type identifier |
| *(this+0x3668) | 0x54 | R | — | Surface type struct within wheel contact data |
| this | 0x5FC | RW | 0 | HUD timer flag (cleared when timer expires) |
| this | 0x7A4 | R | — | Timer/countdown value (triggers HUD timer element) |
| this | 0x32BC | R | — | Rigid body constraint pointer (warnings trigger) |
| this | 0x34EC | R | — | Force direction X (velocity delta calculation) |
| this | 0x34F0 | R | — | RenderX [FACT] |
| this | 0x34F4 | R | — | RenderY [FACT] |
| this | 0x3668 | R | — | Wheel array base pointer (4 wheels, stride 248) |
| this | 0x39B8 | R | — | Climb vibration level (warning threshold check) |
| this | 0x39C4 | R | — | Climb vibration threshold (comparison) |
| this | 0x3A58 | R | — | Current position X (velocity delta) |
| this | 0x3A5C | R | — | Current position Y |
| this | 0x3A60 | R | — | Current position Z |

**Written-by note (persistence):**
- this 0x5FC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e800 | flt_59E800 | R | AmplitudeLimit [DERIVED] (also: ` — under-relaxation upper bound) |
| 0059e824 | flt_59E824 | R | AIDynamicsThreshold [DERIVED] |
| 005ac988 | flt_5AC988 | R | UVCoordScaleFactor [DERIVED] (also: ` — UV coordinate scale factor) |
| 005ad238 | flt_5AD238 | R | WeightTransferMultiplier [DERIVED] |
| 007c9138 | dbl_7C9138 | R | FuelConsumptionMult [DERIVED] |
| 007c9150 | dbl_7C9150 | R | Unknown_Double_Damage [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004f0f40 | WheelContactForceAggregation | Aggregates contact forces per surface type for sound |
| 004f1120 | WheelForceAggregation | Aggregates wheel forces per surface type for sound |
| 004f87c0 | HUDElementConfig | Configures HUD elements: 5=vibration, 42=timer, 38=warning |

**Guard conditions:** Checks a2 (enable flag): PASSES (processes wheel contacts/forces + velocity sound) when nonzero; BLOCKED when zero. For each wheel: valid pointer + unique surface type collection. Velocity delta magnitude > 0 triggers HUD vibration. Timer (this+0x7A4): >0 triggers HUD timer, <=0 clears flag. Rigid body ptr (this+0x32BC): null + fuel/damage condition triggers HUD warning; ptr==1 + climb vibration > threshold triggers HUD warning.
