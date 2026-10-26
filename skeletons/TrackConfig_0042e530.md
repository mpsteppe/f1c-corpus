## TrackConfig_0042e530 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIGearSelectionSet (0042eaa0), ListSelectionClamp (0042eb60), TheSvmHdvVehicleFileParser (004f4270)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x130 | R | — | [LLM] |
| this | 0x138 | R | — | [LLM] |
| this | 0x144 | R | — | [LLM] |
| this | 0x3F0 | R | — | [LLM] |
| this | 0x3F8 | R | — | [LLM] |
| this | 0x400 | R | — | [LLM] |
| this | 0x404 | RW | — | [LLM] |
| this | 0x6B0 | R | — | [LLM] |
| this | 0x6B8 | R | — | [LLM] |
| this | 0x6C4 | R | — | [LLM] |
| this | 0x970 | R | — | [LLM] |
| this | 0x978 | R | — | [LLM] |
| this | 0x980 | R | — | [LLM] |
| this | 0x984 | RW | — | [LLM] |
| this | 0xBC4 | RW | 0 | [LLM] |
| this | 0xCC0 | R | — | [LLM] |
| this | 0xCC4 | RW | — | [LLM] |
| this | 0x12B0 | R | — | [LLM] |
| this | 0x12B8 | R | — | [LLM] |
| this | 0x12C0 | R | — | [LLM] |
| this | 0x12C4 | RW | — | [LLM] |
| this | 0x1988 | R | — | [LLM] |
| this | 0x1990 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x404: recalc every frame — external poke does NOT persist
- this 0x984: recalc every frame — external poke does NOT persist
- this 0xBC4: recalc every frame — external poke does NOT persist
- this 0xCC4: recalc every frame — external poke does NOT persist
- this 0x12C4: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e9f8 | dbl_59E9F8 | R | SceneLoadTimeout [DERIVED] |
| 005c3704 | aRoadCourse | R | RoadCourseConfigStr [DERIVED] |
| 005c3710 | aTrackType | R | TrackTypeString [DERIVED] |
| 005c371c | aRearspoilerang | R | RearSpoilerAngleField [DERIVED] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042e470 | EventTriggerOnStateChange | [LLM] |
| 0042e4a0 | WeightedSumComparatorWithBinaryAdjustment | [LLM] |
| 004c58a0 | StringCopyWithValidation | [LLM] |
| 00588410 | sub_588410 | [LLM] |
| 0058850f | sub_58850F | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1990 | != | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
