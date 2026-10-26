## __amsg_exit_005c1556 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** FAILWRONGDESCRIPTION_42e0 [structural] (005be830), __purecall (005bee86), ___initstdio (005c31f9), __getptd (005c5128), CriticalSectionLazyInitEnter [structural] (005c52b4), __ioinit (005c532a), __setenvp (005ca1ca), __setargv (005ca283), __fptrap (005ccc53), NullTerminatedIntArrayCopyWithAlloc [structural] (005cf9f7)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00625270 | off_625270 | R | [LLM] |
| 007ff164 | dword_7FF164 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005c0b89 | __exit | [LLM] |
| 005ca7d4 | __FF_MSGBANNER | [LLM] |
| 005ca80d | __NMSG_WRITE | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
