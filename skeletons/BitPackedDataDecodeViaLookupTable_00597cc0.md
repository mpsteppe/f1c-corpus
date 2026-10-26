## BitPackedDataDecodeViaLookupTable_00597cc0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_596245 (00596245), sub_5976E8 (005976e8)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005e9c38 | dword_5E9C38 | R | CodePageTableEnd [DERIVED] |
| 005e9d98 | unk_5E9D98 | R | CRTDecimalLookup [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00597aa0 | sub_597AA0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
