## SetDriverVisibility_004c7aa0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CollisionContactIteration (00460dd0), LoadingPhase2 (004b8940)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4894 | R | — | [LLM] |
| this | 0x48BC | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x48BC: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea510 | dword_5EA510 | R | SessionManager [DERIVED] |
| 007c54dc | dword_7C54DC | R | CurrentPlayerIndex [CONFIRMED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040c8d0 | StateCheckWithTernaryLogic | [LLM] |
| 004e0ed0 | AudioSoundEffectController | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
