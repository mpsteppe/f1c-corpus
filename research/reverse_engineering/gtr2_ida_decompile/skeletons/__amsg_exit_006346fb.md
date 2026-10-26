## __amsg_exit_006346fb — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** __purecall (006316b0), start (00634744), __getptd (00636698), __lock (00636cbb), __fptrap (00640b8e), _copy_environ (00643a68)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00912b00 | off_912B00 | R | [LLM] |
| 00fb81e0 | dword_FB81E0 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00633e90 | __exit | [LLM] |
| 0063f0db | __NMSG_WRITE | [LLM] |
| 0063f252 | __FF_MSGBANNER | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
