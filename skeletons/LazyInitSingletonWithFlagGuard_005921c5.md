## LazyInitSingletonWithFlagGuard_005921c5 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_589E6C (00589e6c), sub_591EDF (00591edf)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008d4078 | dword_8D4078 | RW | CRTInitFlag [DERIVED] (also: Initialization flag (0 = uninitialized, >0 = initialized) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058dfea | CriticalSectionLazyInitEnter | [LLM] |
| 0058e04b | CritSectLeave | [LLM] |
| 005921f3 | sub_5921F3 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
