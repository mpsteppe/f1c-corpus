## ResourcePathBuilder_00493e20 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_492160 (00492160), sub_492460 (00492460), sub_492710 (00492710), sub_492A40 (00492a40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | [LLM] |
| this | 0x194 | R | — | [LLM] |
| this | 0x19A | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c2c18 | aS_4 | R | FmtStr_PercentS [DERIVED] |
| 005c30b4 | word_5C30B4 | R | ConfigSubstringToken [DERIVED] |
| 005c32d8 | word_5C32D8 | R | HotExtension (.HOT) [DERIVED] |
| 005c406c | word_5C406C | R | InitStringConstant [DERIVED] (also: global string constant used for initialization) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005887b1 | StringFormatWithNestedIO | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
