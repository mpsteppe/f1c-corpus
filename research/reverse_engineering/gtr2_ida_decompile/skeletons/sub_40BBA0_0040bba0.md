## sub_40BBA0_0040bba0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x40) | 0x0 | R | — | [LLM] |
| this | 0x38 | R | — | [LLM] |
| this | 0x40 | RW | — | [LLM] |
| this | 0x44 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x40: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006e0fbe | SEH_40BBA0 | R | [LLM] |
| 006f16bc | WindowName | R | [LLM] |
| 006f1ec0 | aRb | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040a860 | sub_40A860 | [LLM] |
| 0040a8e0 | sub_40A8E0 | [LLM] |
| 0040b350 | sub_40B350 | [LLM] |
| 005fdfb0 | sub_5FDFB0 | [LLM] |
| 00615860 | StringCopyWithBufferRealloc [structural] | [LLM] |
| 00615a50 | sub_615A50 | [LLM] |
| 00630739 | ??2@YAPAXI@Z | [LLM] |
| 006308d3 | j__free | [LLM] |
| 006308d8 | j_j__free | [LLM] |
| 00631710 | _fclose | [LLM] |
| 00631a22 | _fopen | [LLM] |
| 00631c0d | __stricmp | [LLM] |
| 006dfbfc | __fileno | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
