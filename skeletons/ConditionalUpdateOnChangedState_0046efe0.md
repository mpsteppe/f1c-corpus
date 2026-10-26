## ConditionalUpdateOnChangedState_0046efe0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x174 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x174: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c73e0 | dword_7C73E0 | R | ModuleCallbackTable [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00432a60 | VtableGetterAtOffset0x1c | [LLM] |
| 0046f170 | ExtensionStripperForAllListEntries | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
