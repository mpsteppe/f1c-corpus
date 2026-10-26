## MutexSynchronizationObjectInit_00406130 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LinkedListNodeInsert_78a0 (004078a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |
| this | 0x4 | RW | 1065353216 → 1.0f | [LLM] |
| this | 0x8 | RW | — | [LLM] |
| this | 0xC | RW | 0 | [LLM] |
| this | 0x10 | RW | 0 | [LLM] |
| this | 0x14 | RW | 18446744073709551615 | [LLM] |
| this | 0x18 | RW | 18446744073709551615 | [LLM] |
| this | 0x1C | RW | 18446744073709551615 | [LLM] |
| this | 0x20 | RW | 0 | [LLM] |
| this | 0x50 | RW | 0 | [LLM] |
| this | 0x54 | RW | 18446744073709551615 | [LLM] |
| this | 0x58 | RW | 1 | [LLM] |
| this | 0x5C | RW | 18446744073709551615 | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x8: [LLM: once/conditional? does external poke survive?]
- this 0xC: [LLM: once/conditional? does external poke survive?]
- this 0x10: [LLM: once/conditional? does external poke survive?]
- this 0x14: [LLM: once/conditional? does external poke survive?]
- this 0x18: [LLM: once/conditional? does external poke survive?]
- this 0x1C: [LLM: once/conditional? does external poke survive?]
- this 0x20: [LLM: once/conditional? does external poke survive?]
- this 0x50: [LLM: once/conditional? does external poke survive?]
- this 0x54: [LLM: once/conditional? does external poke survive?]
- this 0x58: [LLM: once/conditional? does external poke survive?]
- this 0x5C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1ac | CreateMutexA | R | [LLM] |
| 0059e4ec | off_59E4EC | R | ThreadObjectVTable [DERIVED] |
| 0059e50c | off_59E50C | R | VTable_FileMutex [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| ff00000000005450 | byte_FF00000000005450 | W | [LLM] |
| ff00000000005451 | byte_FF00000000005451 | W | [LLM] |
| ff00000000005452 | byte_FF00000000005452 | W | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00406700 | MutexLockWithTimeout | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
