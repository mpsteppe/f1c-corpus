## UITextFieldInitialization_00470300 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xE5 | RW | 1 | [LLM] |
| this | 0x2E8 | RW | 0 | [LLM] |
| this | 0x2FC | RW | — | [LLM] |
| this | 0x304 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xE5: [LLM: once/conditional? does external poke survive?]
- this 0x2E8: [LLM: once/conditional? does external poke survive?]
- this 0x2FC: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004703e0 | jpt_470317 | R | [LLM] |
| 005c6e2c | aWwwwwwwwwwwwww | R | [LLM] |
| 005c6e40 | aWwwwwwwwwwwwww_0 | R | [LLM] |
| 007cd818 | byte_7CD818 | RW | TrackDB_Byte_7CD818 [DERIVED] |
| 007cd834 | byte_7CD834 | RW | TrackDB_Buffer_7CD834 [DERIVED] |
| 007cd850 | byte_7CD850 | RW | MultiClientPassword [DERIVED] |
| 007cd860 | unk_7CD860 | R | TrackDataBuffer [DERIVED] |
| 007cd880 | byte_7CD880 | RW | TrackNameBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048b7e0 | UtilityFunction_b7e0 | [LLM] |
| 0048b8f0 | BoundedFieldSetter | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
