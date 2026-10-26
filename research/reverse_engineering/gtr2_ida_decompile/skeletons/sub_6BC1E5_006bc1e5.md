## sub_6BC1E5_006bc1e5 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_6C6A81 (006c6a81)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00739ef8 | aCentroid | R | [LLM] |
| 00747428 | aInvalidTypeUse | R | [LLM] |
| 00747450 | aSSemanticsSHas | R | [LLM] |
| 0074748c | aInvalidInputSe | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00630fe0 | sub_630FE0 | [LLM] |
| 00631abd | j__atol | [LLM] |
| 00631c0d | __stricmp | [LLM] |
| 00633848 | sub_633848 | [LLM] |
| 00633887 | StringComparisonWithConstantDispatch [structural] | [LLM] |
| 00681c52 | sub_681C52 | [LLM] |
| 00686791 | sub_686791 | [LLM] |
| 00686816 | sub_686816 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `centroid`
- `invalid type used for '%s' %s semantics`
- `%s semantics '%s' has been deprecated; use '%s%d' instead`
- `invalid input semantic '%s', only _centroid allowed`
