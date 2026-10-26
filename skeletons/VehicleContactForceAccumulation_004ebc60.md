## VehicleContactForceAccumulation_004ebc60 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ModeDispatchWithSwitch (0040f4b0), ParticleEffectUpdateDispatch (004eb430), VehicleYawRotationRecoveryController (004f1c40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4894 | R | — | [LLM] |
| this | 0x0 | R | — | postProcessInput [CONFIRMED] |
| this | 0x32BC | R | — | [LLM] |
| this | 0x34B0 | R | — | [LLM] |
| this | 0x34B4 | R | — | [LLM] |
| this | 0x34B8 | R | — | elapsedTime (alt) [CONFIRMED] |
| this | 0x34BC | R | — | [LLM] |
| this | 0x34C0 | R | — | [LLM] |
| this | 0x34C4 | R | — | [LLM] |
| this | 0x34C8 | R | — | [LLM] |
| this | 0x34CC | R | — | [LLM] |
| this | 0x34D0 | R | — | [LLM] |
| this | 0x34EC | RW | — | [LLM] |
| this | 0x34F0 | RW | — | RenderX [FACT] |
| this | 0x34F4 | RW | — | RenderY [FACT] |
| this | 0x34F8 | RW | — | RenderZ [FACT] |
| this | 0x34FC | RW | — | [LLM] |
| this | 0x3500 | RW | — | [LLM] |
| this | 0x3504 | RW | — | [LLM] |
| this | 0x3508 | RW | — | [LLM] |
| this | 0x350C | RW | — | [LLM] |
| this | 0x3518 | R | — | [LLM] |
| this | 0x3528 | R | — | [LLM] |
| this | 0x352C | R | — | [LLM] |
| this | 0x3530 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x34EC: recalc every frame — external poke does NOT persist
- this 0x34F0: recalc every frame — external poke does NOT persist
- this 0x34F4: recalc every frame — external poke does NOT persist
- this 0x34F8: recalc every frame — external poke does NOT persist
- this 0x34FC: recalc every frame — external poke does NOT persist
- this 0x3500: recalc every frame — external poke does NOT persist
- this 0x3504: recalc every frame — external poke does NOT persist
- this 0x3508: recalc every frame — external poke does NOT persist
- this 0x350C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e86c | flt_59E86C | R | FloatToInt64Scale [DERIVED] |
| 007c7428 | dbl_7C7428 | R | RaceTimeElapsed [DERIVED] |
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0043e5d0 | AccumulateAngularImpulse | [LLM] |
| 0045eb00 | Vector3ScalarMultiply | [LLM] |
| 00463dc0 | ConditionalStridePointerComputation | [LLM] |
| 004b2480 | UtilityFunction_2480 | [LLM] |
| 004b2580 | ShortVectorToFloatWithScale | [LLM] |
| 004ea930 | sub_4EA930 | [LLM] |
| 004ec020 | F_3DVectorAddition | [LLM] |
| 004ec050 | F_6FieldStructInit | [LLM] |
| 004ec1a0 | CollisionSparkParticleEffects | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
