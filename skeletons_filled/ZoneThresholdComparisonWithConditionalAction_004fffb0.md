## ZoneThresholdComparisonWithConditionalAction_004fffb0 — ZoneBasedThresholdAction

**Summary:** Compares an incoming value against two thresholds (upper at this+0xC, lower at this+0x1BC) and triggers different actions via ArithmeticComparison_3a90 depending on which zone the value falls into. For zone/region state management in networking.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetworkMessageDispatch (004b54e0), sub_4B9000 (004b9000)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | Upper zone threshold (triggers action A when v3 > a2 && v3 < this+0xC) |
| this | 0x1BC | R | — | Lower zone threshold (v3 <= this+0x1BC blocks all actions) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b3a90 | ArithmeticComparison_3a90 | Compare and store zone-dependent action data |

**Guard conditions:** `v3` (value at a3+4) compared against `a2` and this+0x1BC. If v3 > a2 AND v3 < this+0xC → upper zone action. If v3 in (this+0x1BC, a2] → middle zone action. If v3 <= this+0x1BC → no action (lower zone, blocked).
