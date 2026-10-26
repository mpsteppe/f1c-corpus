## QOrder0000BmpQualifyingOrderReset_0046c820 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x40 | R | — | [LLM] |
| this | 0x174 | R | — | [LLM] |
| this | 0x178 | RW | 18446744073709551615 | [LLM] |

**Written-by note (persistence):**
- this 0x178: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005c6674 | off_5C6674 | R | [LLM] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007cd2b8 | dword_7CD2B8 | W | CollisionGridArrayBase [DERIVED] |
| 007cd470 | dword_7CD470 | R | CollisionGridArrayBase2 [DERIVED] (also: ` — array bases) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00497ad0 | sub_497AD0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
