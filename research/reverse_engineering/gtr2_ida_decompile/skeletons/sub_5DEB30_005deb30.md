## sub_5DEB30_005deb30 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4D4D20 (004d4d20), sub_5912A0 (005912a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006ec5fb | SEH_5DEB30 | R | [LLM] |
| 00fb28bc | dword_FB28BC | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005dcef0 | sub_5DCEF0 | [LLM] |
| 005de340 | sub_5DE340 | [LLM] |
| 005fdfb0 | sub_5FDFB0 | [LLM] |
| 00630739 | ??2@YAPAXI@Z | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
