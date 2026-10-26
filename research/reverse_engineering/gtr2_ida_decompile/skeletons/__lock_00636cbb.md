## __lock_00636cbb — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** ??1type_info@@UAE@XZ_0 (0063164e), ___updatetlocinfo (006323cd), _setlocale (00632a8b), __lockexit (00633d28), _doexit (00633dbc), _flsall (00634512), _free (00634919), _realloc (006349c9), __heap_alloc (00634b76), __getcwd (00635047), _calloc (006353f3), __freefls@4 (00636709) … +16 more

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f1264 | EnterCriticalSection | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006346fb | __amsg_exit | [LLM] |
| 00636c1b | __mtinitlocknum | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
