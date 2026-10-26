## __lock_file_00636f7e — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** _fclose (00631710), sub_6318A2 (006318a2), _fseek (0063197d), sub_631E50 (00631e50), _fgets (00633b87), _fgetc (00634116), _fputc (00634166), sub_634320 (00634320), _fflush (006345e7), _vfprintf (00634640), _fprintf (0063469d), _fputs (00634eb4) … +1 more

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x20 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f1264 | EnterCriticalSection | R | [LLM] |
| 00912dd0 | off_912DD0 | R | [LLM] |
| 00913030 | stru_913030 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00636cbb | __lock | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
