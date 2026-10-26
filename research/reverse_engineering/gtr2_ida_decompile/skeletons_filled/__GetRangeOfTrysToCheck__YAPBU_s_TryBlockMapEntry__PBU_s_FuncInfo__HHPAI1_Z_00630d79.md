## ?_GetRangeOfTrysToCheck@@YAPBU_s_TryBlockMapEntry@@PBU_s_FuncInfo@@HHPAI1@Z_00630d79 — _GetRangeOfTrysToCheck (try-block range selector)

**Summary:** MSVC C++ EH support routine: walks the function's try-block map backward from nTryBlocks, skipping a2 entries and matching a3 against each entry's try/catch span, to select the range of try-block entries to inspect. Writes the selected low index and count through a4/a5 and returns a pointer into the map. Called by the handler-search routines.

**Called by:** ?FindHandlerForForeignException@@YAXPAUEHExceptionRecord@@PAUEHRegistrationNode@@PAU_CONTEXT@@PAXPBU_s_FuncInfo@@HH1@Z (0063630e), ?FindHandler@@YAXPAUEHExceptionRecord@@PAUEHRegistrationNode@@PAU_CONTEXT@@PAXPBU_s_FuncInfo@@EH1@Z (006363cc)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | FuncInfo::nTryBlocks — number of try-block map entries |
| this | 0x10 | R | — | FuncInfo::pTryBlockMap — array of try-block map entries |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00635d4c | sub_635D4C | Consistency/inconsistency failure routine — invoked when try-block indices run out of range |

**Guard conditions:** If a2 >= 0 a reverse scan runs: each iteration indexes pTryBlockMap[--nTryBlocks]; an entry is "retired" (a2 decremented, range trackers rotated) when tryHigh < a3 <= catchHigh, or when nTryBlocks has just become -1. Encountering nTryBlocks == -1 mid-scan calls sub_635D4C (abort/inconsistency path). After the scan, if the tracked high bound exceeds a1->nTryBlocks or the low bound exceeds it, sub_635D4C is called too; otherwise the range is written to *a4/*a5 and &pTryBlockMap[v10] is returned.
