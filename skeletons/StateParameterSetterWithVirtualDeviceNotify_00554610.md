## StateParameterSetterWithVirtualDeviceNotify_00554610 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StateFieldSetWithChainedInit (00553fa0), MultiFieldSetterDispatchingTo7SubSetters (005546a0), UICleanupIterator (00554d70), D3DResourceListCleanup (00554e10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |
| this | 0x30 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x30: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b89a0 | dword_8B89A0 | R | GameDeviceObject [DERIVED] (also: ` — global game state device object (virtual dispatch) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
