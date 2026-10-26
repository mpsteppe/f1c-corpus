## ConfigFileParser_004330d0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AddVehicleConfigEntryToLinkedList (00433b60), sub_4B0770 (004b0770)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x28) | 0x0 | R | — | [LLM] |
| this | 0x1C | R | — | [LLM] |
| this | 0x24 | RW | — | [LLM] |
| this | 0x28 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x24: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00432bf0 | AutoLoadEntryWriter | [LLM] |
| 00432cf0 | PhysicsFilePathBuild | [LLM] |
| 005668b0 | ZeroInitSmallStruct | [LLM] |
| 005668d0 | SubCallWithConditionalFieldFree | [LLM] |
| 00566940 | sub_566940 | [LLM] |
| 00566b90 | ConditionalFileHandleCloseWithFlagDispatch | [LLM] |
| 00568620 | sub_568620 | [LLM] |
| 0058ba36 | ToggleFileReadOnlyAttributeViaWin32API | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
