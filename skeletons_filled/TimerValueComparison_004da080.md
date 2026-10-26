## TimerValueComparison_004da080 — Reference time validation check

**Summary:** Validates that the stored reference time (this[7]) still matches the current player vehicle's comparison slot, selected by type flag (this[6]). Returns 1 if match confirmed, 0 if gap is invalid, reference is zero, or vehicle state has changed.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4D9F80 (004d9f80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | R | — | Gap float (this+20); must be >= 0 for validation to proceed |
| this | 0x18 | R | — | Comparison type flag (byte): 1 compares against vehicle+16592, 0 against vehicle+16596 |
| this | 0x1C | R | — | Stored reference time value; compared against current vehicle slot |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 007c54e0 | dword_7C54E0 | R | postProcessInput [CONFIRMED] — current player vehicle pointer |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** `this+20` (gap) < 0.0 → BLOCKED (return 0). `this[7]` (reference time) == 0 → BLOCKED (return 0). For type 1 (`this[6]` non-zero): PASSES if reference == vehicle+16592. For type 0: PASSES if reference == vehicle+16596. All other cases → return 0.
