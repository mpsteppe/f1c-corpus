## CameraTargetNameResolver_0040db00 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RaceCommentaryDirectorSystem (0040d4c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | [LLM] |
| this | 0x8C | R | — | [LLM] |
| this | 0x90 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005beb10 | aNone | R | NoneString [DERIVED] |
| 005beb18 | aAnyTrackside | R | AnyTracksideString [DERIVED] |
| 005beb28 | aLast | R | Str_Last [DERIVED] |
| 005beb30 | aOriginal | R | StringOriginal [DERIVED] |
| 005beb3c | aPlayer_1 | R | PlayerString [DERIVED] |
| 005ea510 | dword_5EA510 | R | SessionManager [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040c890 | TracksideCameraTargetLookup | [LLM] |
| 0040d0b0 | ModeDispatchedSubsystemCall | [LLM] |
| 00588410 | sub_588410 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
