## RefCountDecrementWithCheck_00599ad9 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea04c | dword_5EA04C | W | ReferenceCounter [DERIVED] |
| 008d4400 | dword_8D4400 | R | DynamicsSolverBase_8D4400 [DERIVED] |
| 008d4440 | dword_8D4440 | R | DynamicsConstraintData [DERIVED] |
| 008d4568 | byte_8D4568 | R | ExceptionTypeDescriptor [DERIVED] (also: ` — static type descriptor used in MSVC exception handling data) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00598aa0 | StatusCheckWithErrorDispatch | [LLM] |
| 0059a54d | sub_59A54D | [LLM] |
| 0059a5e9 | sub_59A5E9 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
