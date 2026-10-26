## VehicleDataLoader_004c4240 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VehicleFileLoader (004c3d80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008ac390 | dword_8AC390 | R | VehicleFileCount [DERIVED] |
| 008ac394 | dword_8AC394 | R | VehicleArray (stride 0x424) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00415c30 | NullSafePointerDereference | [LLM] |
| 004c3050 | sub_4C3050 | [LLM] |
| 004c3130 | MultiFieldCleanup | [LLM] |
| 004c3890 | CompositeStringCompare | [LLM] |
| 004c45d0 | VehicleDataCopy | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
