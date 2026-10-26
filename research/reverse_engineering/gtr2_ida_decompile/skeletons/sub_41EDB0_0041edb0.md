## sub_41EDB0_0041edb0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x50 | RW | 0 | [LLM] |
| this | 0x74 | RW | — | [LLM] |
| this | 0x78 | RW | — | [LLM] |
| this | 0x7C | RW | — | [LLM] |
| this | 0x80 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x50: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x74: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x78: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x7C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x80: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006e166c | SEH_41EDB0 | R | [LLM] |
| 006f16bc | WindowName | R | [LLM] |
| 006f1f34 | aSS | R | [LLM] |
| 006f3048 | aUnlockpass | R | [LLM] |
| 006f3054 | aUnlockgold | R | [LLM] |
| 006f3060 | aGdb | R | [LLM] |
| 0091ca70 | dword_91CA70 | R | [LLM] |
| 0091ca80 | dword_91CA80 | R | [LLM] |
| 00faecbc | dword_FAECBC | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041ed50 | sub_41ED50 | [LLM] |
| 0048d380 | sub_48D380 | [LLM] |
| 00615860 | StringCopyWithBufferRealloc [structural] | [LLM] |
| 00615a50 | sub_615A50 | [LLM] |
| 00615ce0 | LinkedListNodePeek [exact] | [LLM] |
| 00615d30 | ShortComputation_5f70 [exact] | [LLM] |
| 00615d40 | sub_615D40 | [LLM] |
| 00615fe0 | sub_615FE0 | [LLM] |
| 00616840 | FileStreamReader [structural] | [LLM] |
| 00616f90 | sub_616F90 | [LLM] |
| 00617030 | sub_617030 | [LLM] |
| 00617060 | sub_617060 | [LLM] |
| 00630739 | ??2@YAPAXI@Z | [LLM] |
| 006308d8 | j_j__free | [LLM] |
| 00631761 | _sprintf | [LLM] |
| 00631a35 | _atol | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `%s%s`
- `UnlockPass`
- `UnlockGold`
- `*.GDB`
