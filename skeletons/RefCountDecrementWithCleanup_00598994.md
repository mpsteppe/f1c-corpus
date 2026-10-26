## RefCountDecrementWithCleanup_00598994 — [LLM: short descriptive name]

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
| 005e9ef4 | dword_5E9EF4 | W | RefCount [DERIVED] (also: ` — reference counter) |
| 008d4210 | dword_8D4210 | R | ExceptionTypeDesc [DERIVED] (also: ` — passed as second argument; not in docs/12) |
| 008d42a0 | unk_8D42A0 | R | ExceptionTypeDescriptor [DERIVED] (also: ` — static type descriptor used in MSVC exception handling data) |
| 008d43c8 | dword_8D43C8 | R | LocaleManagementStruct [DERIVED] (also: ` — locale management structure) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00598aa0 | StatusCheckWithErrorDispatch | [LLM] |
| 0059a54d | sub_59A54D | [LLM] |
| 0059a5e9 | sub_59A5E9 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
