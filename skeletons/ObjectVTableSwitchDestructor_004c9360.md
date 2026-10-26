## ObjectVTableSwitchDestructor_004c9360 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ace2c | off_5ACE2C | R | VTableRef_5ACE2C [DERIVED] |
| 005ace4c | off_5ACE4C | R | PTR_VTABLE_5ACE4C [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c94d0 | sub_4C94D0 | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
