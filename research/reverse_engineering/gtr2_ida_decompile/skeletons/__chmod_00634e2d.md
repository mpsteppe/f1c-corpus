## __chmod_00634e2d — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_40D950 (0040d950), sub_40F140 (0040f140), sub_41B6F7 (0041b6f7), sub_4B01A0 (004b01a0), sub_613B90 (00613b90), sub_617680 (00617680)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f10dc | GetFileAttributesA | R | [LLM] |
| 006f1168 | GetLastError | R | [LLM] |
| 006f1228 | SetFileAttributesA | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006351f2 | CollisionParameterClampAndStore [structural] | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
