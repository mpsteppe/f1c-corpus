## UILoadingPercentDisplay_0047c860 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xB4 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0xFC | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e6f8 | flt_59E6F8 | R | SignedShortScale [DERIVED] (also: ` — scale factors) |
| 005c37cc | aD | R | FormatSpecifierD [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ea618 | flt_5EA618 | R | PointerTableEntry [DERIVED] |
| 008ac494 | byte_8AC494 | R | SceneArrayFirstSceneName [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00418970 | ThresholdGatedVirtualDispatch | [LLM] |
| 004c8900 | GlobalDispatchWithGuard | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00587bdc | CRTFtol | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xFC | == | 232 | [LLM] |
| this | 0xFC | == | 230 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
