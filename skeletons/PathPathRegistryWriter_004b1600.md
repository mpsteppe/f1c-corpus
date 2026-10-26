## PathPathRegistryWriter_004b1600 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AutoJoinRetryLoop (004637a0), MultiplayerSessionJoinHandler (0046de10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1A4 | R | — | [LLM] |
| this | 0x1AC | R | — | [LLM] |
| this | 0x1B4 | R | — | [LLM] |
| this | 0x1F8C | R | — | [LLM] |
| this | 0x1F94 | R | — | [LLM] |
| this | 0x1F9C | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566650 | StringCopyWithBufferRealloc | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
