## CameraTargetUpdateOnPlayerChange_0040c7a0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MainCameraDirectorUpdate (0040ca30), GameStateDispatchChain (0040d240)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x38 | RW | — | [LLM] |
| this | 0x48CC | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x38: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ecdc8 | unk_5ECDC8 | R | VEH[0].0x6F0 [LLM: field purpose] |
| 007c54dc | dword_7C54DC | R | CurrentPlayerIndex [CONFIRMED] |
| 007c54e0 | dword_7C54E0 | R | postProcessInput [CONFIRMED] (also: unknown (near PlayerVehiclePtr +0x8)) |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007c5bc8 | byte_7C5BC8 | R | ScoringDBEndSentinel [DERIVED] |
| 007cfcc8 | dword_7CFCC8 | R | QueuedModeFlag [DERIVED] (also: ` — queued mode flag (docs/09) |
| 007cfdc4 | dword_7CFDC4 | R | DispatchModeSelector [CONFIRMED] (also: Dispatch mode selector (0-3) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040c8d0 | StateCheckWithTernaryLogic | [LLM] |
| 004e0ed0 | AudioSoundEffectController | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
