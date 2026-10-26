## MSVCRTSEHFrameUnwinder_005888a6 — SEHFrameUnwindToTryLevel

**Summary:** Unwinds MSVC CRT SEH scope table from current trylevel down to target trylevel. Iterates through scope entries calling registered unwind handlers for each level. Core of CRT `_local_unwind`.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ScriptFrameProcessor (0058895c), LocalUnwindWrapper (00588a19), LongjmpMSVCCRT (0058a770), SEHWrapperAroundCRTFunctionCall (005938b4)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | Pointer to scope table (array of trylevel entries, 3 DWORDs each) |
| this | 0xC | RW | — | Current trylevel value; updated each iteration as unwind progresses |

**Written-by note (persistence):**
- this 0xC: Updated every iteration as unwinding steps through scope table; final value is target trylevel or -1

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00588884 | FlagCheckHandler | R | SEH flag check callback passed to unwind handler |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058893a | sub_58893A | Check/report when scope entry has no handler (called with code 257 = unwind action) |

**Guard conditions:** Reads field at this+0xC (current trylevel). If value == -1 OR value == target trylevel (a2), loop exits immediately — unwind complete. Otherwise, continues to next scope entry.
