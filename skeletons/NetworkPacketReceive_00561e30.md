## NetworkPacketReceive_00561e30 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |
| this | 0xE4 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008cef80 | buf | RW | NetReceiveBuffer [DERIVED] (also: ` — receive buffer (256 bytes) |
| ff00000000005435 | byte_FF00000000005435 | W | [LLM] |
| ff00000000005436 | byte_FF00000000005436 | W | [LLM] |
| ff00000000005438 | byte_FF00000000005438 | W | [LLM] |
| ff00000000005439 | byte_FF00000000005439 | W | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005622c0 | FilePathNameLookup | [LLM] |
| 0059864e | recvfrom | [LLM] |
| 00598654 | select | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
