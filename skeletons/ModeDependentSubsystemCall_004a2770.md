## ModeDependentSubsystemCall_004a2770 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PitCrewAnimationLoader (004a2a90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x2 | RW | — | [LLM] |
| this | 0x48 | RW | — | [LLM] |
| this | 0x64 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x2: [LLM: once/conditional? does external poke survive?]
- this 0x48: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004a2010 | PitCrewMeshLoader | [LLM] |
| 0054c030 | FlagFieldBitManipulation | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
