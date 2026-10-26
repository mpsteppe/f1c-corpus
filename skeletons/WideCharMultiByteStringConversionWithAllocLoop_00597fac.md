## WideCharMultiByteStringConversionWithAllocLoop_00597fac — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_596D81 (00596d81), sub_598323 (00598323)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e228 | WideCharToMultiByte | R | [LLM] |
| 008d3e98 | dword_8D3E98 | R | WideStrLinkedList [DERIVED] (also: ` — linked list of wide strings (command-line args / locale strings) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a935 | MallocWrapperForNhMalloc | [LLM] |
| 00598323 | sub_598323 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
