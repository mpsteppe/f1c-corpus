## VehicleObjectConstructor_004c6920 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RepeatedCallLoop (0042bb50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4894 | RW | 18446744073709551615 | [LLM] |

**Written-by note (persistence):**
- this 0x4894: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423e80 | RaceStructInit | [LLM] |
| 00424040 | LargeStructFieldSetterWithStoredReference | [LLM] |
| 004c79e0 | VehicleDriverInfoClear | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
