## FileHandleDestructorWithModeCheck_00534ee0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_534B10 (00534b10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1C | R | — | [LLM] |
| this | 0x38 | R | — | [LLM] |
| this | 0x40 | R | — | [LLM] |
| this | 0x44 | R | — | [LLM] |
| this | 0x48 | R | — | [LLM] |
| this | 0x50 | R | — | [LLM] |
| this | 0x54 | R | — | [LLM] |
| this | 0x5C | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00535660 | GuardedFunctionCallCleanup | [LLM] |
| 005361d0 | sub_5361D0 | [LLM] |
| 00587d02 | FileCloseWithLock | [LLM] |
| 0058aa6f | sub_58AA6F | [LLM] |
| 0058afcf | TLSOffsetGetter | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x38 | < | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
