## CriticalSectionEnterWithLazyInit_00595a61 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_58C331 (0058c331), sub_58C724 (0058c724), sub_58C9B4 (0058c9b4), sub_58E22B (0058e22b), sub_592891 (00592891), sub_595801 (00595801), sub_595F11 (00595f11), sub_59B650 (0059b650), sub_59B760 (0059b760)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e16c | InitializeCriticalSection | R | [LLM] |
| 0059e174 | EnterCriticalSection | R | [LLM] |
| 008d4920 | dword_8D4920 | R | CriticalSectionArray (stride 0x24) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058dfea | CriticalSectionLazyInitEnter | [LLM] |
| 0058e04b | CritSectLeave | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
