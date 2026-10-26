## UILoadingPercentDisplay_0047c860 — LoadingPercentDisplayUpdate

**Summary:** Reads loading progress float via vtable dispatch, converts to percentage string with "%d%%" format, and conditionally dispatches events based on field 0xFC mode (230 = threshold-gated dispatch, 232 = global dispatch).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xB4 | R | — | vtable offset for function that returns loading progress float pointer |
| this | 0x0 | R | — | vtable pointer for virtual dispatch |
| this | 0xFC | R | — | dispatch mode selector: 230=threshold gate, 232=global dispatch |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] — not directly used; referenced in same compilation unit |
| 0059e6f8 | flt_59E6F8 | R | SignedShortScale [DERIVED] — not directly used; referenced in same compilation unit |
| 005c37cc | aD | R | FormatSpecifierD [DERIVED] — not directly used; referenced in same compilation unit |
| 005ea438 | byte_5EA438 | R | default application directory path, used as prefix for string buffer init |
| 005ea618 | flt_5EA618 | R | PointerTableEntry [DERIVED] — threshold/dispatch parameter for ThresholdGatedVirtualDispatch |
| 008ac494 | byte_8AC494 | R | SceneArrayFirstSceneName [DERIVED] — not directly used; referenced in same compilation unit |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00418970 | ThresholdGatedVirtualDispatch | dispatch loading event with threshold gating (mode 230) |
| 004c8900 | GlobalDispatchWithGuard | dispatch loading event globally (mode 232) |
| 00566650 | StringCopyWithBufferRealloc | copy formatted percentage string to output buffer |
| 00587bdc | CRTFtol | convert float to integer (loading percentage) |
| 0058815f | StringFormatWithBufferOverflowCheck | safe format string with "%d%%" pattern |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xFC | == | 232 | dispatch mode for GlobalDispatchWithGuard |
| this | 0xFC | == | 230 | dispatch mode for ThresholdGatedVirtualDispatch |

**Guard interpretation:** If this+0xFC == 230, dispatches through ThresholdGatedVirtualDispatch path; if == 232, dispatches through GlobalDispatchWithGuard path; if neither, skips both dispatches and only updates the percentage text string.
