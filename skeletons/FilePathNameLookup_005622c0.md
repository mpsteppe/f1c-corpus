## FilePathNameLookup_005622c0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetworkPacketReceive (00561e30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0056250c | jpt_562391 | R | [LLM] |
| 005e4cd4 | off_5E4CD4 | R | SceneFileDataPtr [DERIVED] |
| 005e4dfc | off_5E4DFC | R | NetworkSocketPtr [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00562530 | sub_562530 | [LLM] |
| 00562610 | sub_562610 | [LLM] |
| 005626b0 | StackBufferZeroInitWithCallback | [LLM] |
| 00562830 | StackBufferZeroInitWithVTableCall | [LLM] |
| 00562890 | BufferZeroInitWithVirtualMethodCall | [LLM] |
| 005628f0 | LargeStackStructZeroInitWithVtableCall | [LLM] |
| 00562950 | sub_562950 | [LLM] |
| 005629b0 | sub_5629B0 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 59 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
