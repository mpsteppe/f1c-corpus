## PitStateUpdateMachine_004a6e50 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsModeDispatcher (004e4930)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x32C8 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x180 | R | — | [LLM] |
| this | 0x184 | R | — | [LLM] |
| this | 0x188 | R | — | [LLM] |
| this | 0x190 | RW | 0 | [LLM] |
| this | 0x1AC | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x190: recalc every frame — external poke does NOT persist
- this 0x1AC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005acb08 | flt_5ACB08 | R | FloatThreshold_5ACB08 [DERIVED] (also: ` — upper bound threshold (undocumented) |
| 005ea510 | dword_5EA510 | R | SessionManager [DERIVED] |
| 007c54dc | dword_7C54DC | R | CurrentPlayerIndex [CONFIRMED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007c5698 | dword_7C5698 | R | SessionTickCounter [DERIVED] |
| 007ce258 | dword_7CE258 | W | InitZeroFieldSet [DERIVED] |
| 008ad298 | dword_8AD298 | R | SessionModeIdentifier [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040d410 | ShortComputation_d410 | [LLM] |
| 004a5c80 | StateChangeNotify | [LLM] |
| 004a5f20 | sub_4A5F20 | [LLM] |
| 004a5fa0 | VehicleProximityCollisionDetection | [LLM] |
| 004a6200 | PitStopReadyCheck | [LLM] |
| 004a68b0 | PitStopProgress | [LLM] |
| 004a6b80 | CollisionAvoidanceCheck | [LLM] |
| 004a6db0 | VehicleControlEnabled | [LLM] |
| 004d8840 | ConditionalIndexSetter | [LLM] |
| 004e9630 | PositionChangeMonitor | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x184 | != | 3 | [LLM] |
| this | 0x184 | == | 2 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
