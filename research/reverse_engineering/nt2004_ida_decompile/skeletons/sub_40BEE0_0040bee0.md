## sub_40BEE0_0040bee0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_40B4A0 (0040b4a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x44) | 0x1C | R | — | [LLM] |
| *(this+0x44) | 0x20 | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x28 | R | — | [LLM] |
| this | 0x2C | R | — | [LLM] |
| this | 0x30 | R | — | [LLM] |
| this | 0x34 | R | — | [LLM] |
| this | 0x44 | R | — | [LLM] |
| this | 0x48 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x48: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d54e0 | flt_5D54E0 | R | [LLM] |
| 005fb99c | aCockpit | R | [LLM] |
| 006152e8 | dword_6152E8 | R | [LLM] |
| 006152ec | dword_6152EC | R | [LLM] |
| 0062bf64 | unk_62BF64 | R | [LLM] |
| 0075aac4 | dword_75AAC4 | R | [LLM] |
| 0075aacc | dword_75AACC | R | [LLM] |
| 0076617c | byte_76617C | R | [LLM] |
| 00768318 | flt_768318 | R | [LLM] |
| 0076833c | flt_76833C | R | [LLM] |
| 00768360 | flt_768360 | R | [LLM] |
| 00768384 | flt_768384 | R | [LLM] |
| 007d79f4 | flt_7D79F4 | R | [LLM] |
| 007e8cdc | dword_7E8CDC | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042dba0 | sub_42DBA0 | [LLM] |
| 00459b80 | PathAccessor_28e0 [structural] | [LLM] |
| 00579100 | EulerToRotationMatrix [exact] | [LLM] |
| 00593430 | sub_593430 | [LLM] |
| 00593460 | sub_593460 | [LLM] |
| 00593b30 | sub_593B30 | [LLM] |
| 00593e60 | sub_593E60 | [LLM] |
| 00593f30 | sub_593F30 | [LLM] |
| 00593f70 | sub_593F70 | [LLM] |
| 0059cb40 | PackedArrayIndexLookup [exact] | [LLM] |
| 0059e0c0 | TripleFieldQuery [exact] | [LLM] |
| 0059e140 | ArithmeticComparison_b4a0 [exact] | [LLM] |
| 005bf290 | __strcmpi | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `Cockpit`
