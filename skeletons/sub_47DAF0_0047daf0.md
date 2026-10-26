## sub_47DAF0_0047daf0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |
| this | 0xEC | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0xEC: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a6b20 | off_5A6B20 | R | off_5A6B20 [DERIVED] |
| 005c72dc | aRemoveBookmark | R | Str_RemoveBookmark [DERIVED] |
| 005c72ec | aDropBookmark | R | StringDropBookmark [DERIVED] |
| 005c72fc | aForwardScanFas | R | ForwardScanFastString [DERIVED] |
| 005c7310 | aForwardScan | R | ForwardScanString [DERIVED] |
| 005c7320 | aPlay | R | PlayString [DERIVED] |
| 005c7328 | aStop | R | StopCmdString [DERIVED] |
| 005c7330 | aPlaybackwards | R | PlayBackwardsString [DERIVED] |
| 005c7340 | aReverseScan | R | ReverseScanField [DERIVED] |
| 005c7350 | aReverseScanFas | R | UI_ReverseScanFast [DERIVED] |
| 005c7364 | off_5C7364 | R | VTablePtr_5C7364 [DERIVED] |
| 005c7368 | aBegin | R | BeginString [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486f30 | LinkedListInsertWithNodeAllocation | [LLM] |
| 00488b00 | ConstructorInitVTable | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
