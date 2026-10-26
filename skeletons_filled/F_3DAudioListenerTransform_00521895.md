## F_3DAudioListenerTransform_00521895 — 3DNow! 3D audio listener orientation normalization

**Summary:** Processes 4-component listener orientation vector a2: checks if the 4th component (high dword of a2[1]) is >= 1.0 → copies directly to output. If < 1.0, computes SquareRootApproximation, checks if |4th component| >= small threshold (0x34000000), and if so scales all vector components by refined reciprocal of 4th component via pfrcp + Newton-Raphson. Writes normalized orientation to a1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | First half of output listener orientation vector (xy) |
| this | 0x8 | R | — | Second half of output listener orientation vector (zw) |

**Written-by note (persistence):**
- this 0x0: Written once at function end; purely output, no persistence.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005af940 | qword_5AF940 | R | ThreeDNow_AndMask_Packed [DERIVED] |
| 005af948 | qword_5AF948 | R | SIMDCompareThreshold [DERIVED] |
| 005af950 | qword_5AF950 | R | SIMDQuadMask [DERIVED] |
| 005af988 | qword_5AF988 | R | PackedMathOne [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00529000 | SquareRootApproximation | Reciprocal sqrt approximation (Newton-Raphson step) |
| 00529700 | sub_529700 | 3DNow! helper for listener orientation refinement (partial computation) |

**Guard conditions:** First guard: `pfcmpge(v5, 0x3F8000003F800000LL)` checks if 4th component >= 1.0. BLOCKED (>= 1.0): directly copies a2 to a1, skips all normalization. PASSES (< 1.0): enters normalization path. Second guard: `pfcmpge(pand(|v5|), 0x3400000034000000LL)` checks if |4th component| >= tiny threshold (~5.9e-8). BLOCKED (below threshold): skips reciprocal scaling.
