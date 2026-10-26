## TrackSessionClassesReader_00432a70 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AutoLoadEntryListLoader (00432e70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x10: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c3f8c | off_5C3F8C | R | Unknown_Ptr_5C3F8C [DERIVED] |
| 005c3f90 | off_5C3F90 | R | VTable_5C3F90 [DERIVED] |
| 005c3f94 | off_5C3F94 | R | vtable_UIWidget_00432a70 [DERIVED] |
| 005c3f98 | off_5C3F98 | R | MsgBoxVtable [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005651b0 | sub_5651B0 | [LLM] |
| 005654a0 | sub_5654A0 | [LLM] |
| 00565520 | sub_565520 | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00566cc0 | ConditionalDispatchBasedOnFlag | [LLM] |
| 00587f59 | SingleFunctionCallWrapper_7f59 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
