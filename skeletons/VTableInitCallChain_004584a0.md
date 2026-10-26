## VTableInitCallChain_004584a0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ArrayObjectDestructorWithDeallocation (0040b5c0), MainView (0040b850)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059f00c | off_59F00C | R | VTable_CameraNode [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00457cf0 | ConditionalFreeAndStructZeroInit | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
