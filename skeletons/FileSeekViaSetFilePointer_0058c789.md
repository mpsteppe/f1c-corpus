## FileSeekViaSetFilePointer_0058c789 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_58C724 (0058c724), sub_58CA19 (0058ca19), sub_58E290 (0058e290), sub_595AF9 (00595af9), sub_59797B (0059797b)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e168 | SetFilePointer | R | [LLM] |
| 0059e188 | GetLastError | R | [LLM] |
| 008d4920 | dword_8D4920 | R | CriticalSectionArray (stride 0x24) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058af5c | ErrorIDLookupTable | [LLM] |
| 0058afcf | TLSOffsetGetter | [LLM] |
| 00595a1f | sub_595A1F | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
