## MemoryObjectAllocator_00562b50 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetworkReplayBufferInit (0045d260)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005640f0 | sub_5640F0 | R | [LLM] |
| 005645a0 | sub_5645A0 | R | [LLM] |
| 00564600 | IndirectDwordCompare | R | [LLM] |
| 00564630 | sub_564630 | R | [LLM] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00564660 | NetworkStartup | [LLM] |
| 005646d0 | AllocateIntArrayViaFactory | [LLM] |
| 00564810 | Malloc0x18ByteStructWithInnerBuffer | [LLM] |
| 0058a935 | MallocWrapperForNhMalloc | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
