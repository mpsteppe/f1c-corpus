## SceneRenderUpdate_004c6d90 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AICommandMessageQueueDispatcher (00424cd0), PitStopDecisionTireCompound (0042a3d0), DynMan_Restart (0042c3b0), NetCommPlayerSlotSync (0045fc50), sub_4A00A0 (004a00a0), sub_4A0250 (004a0250), ProcessDriverEntries (004b8da0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x48B4 | RW | 18446744073701163007 | [LLM] |

**Written-by note (persistence):**
- this 0x48B4: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005ea408 | flt_5EA408 | R | SessionMaxTime [DERIVED] (also: ` — threshold) |
| 005ea560 | dword_5EA560 | R | GlobalInstance_5EA560 [CONFIRMED] |
| 008acee0 | dword_8ACEE0 | R | ForceFeedbackBase [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00410b60 | DelegationWrapperToFUN0040ed10 | [LLM] |
| 00424790 | AIDriverStructInit | [LLM] |
| 004bb810 | sub_4BB810 | [LLM] |
| 004c6b60 | sub_4C6B60 | [LLM] |
| 004d10e0 | SingleFunctionDispatch_10e0 | [LLM] |
| 004d1100 | ConditionalDelegateDispatch | [LLM] |
| 004d1140 | RenderCallWithGuard | [LLM] |
| 004d1180 | sub_4D1180 | [LLM] |
| 004d1670 | sub_4D1670 | [LLM] |
| 004e0800 | VehicleRespawnReset | [LLM] |
| 004e45b0 | LargeConfigFunctionWithPhysicsConstants | [LLM] |
| 004e4910 | CollisionWrapperWithLock | [LLM] |
| 004ef7c0 | AIVehiclePathPositionTracking | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
