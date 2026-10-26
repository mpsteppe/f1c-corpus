## TireSuspensionForceComputation_00431850 — TireSuspensionForceCalc

**Summary:** Computes tire suspension force from compound properties, aero/suspension mode, and session state. Looks up compound index, selects force coefficient based on mode selector (aerodynamic vs suspension), applies scaling factors, and divides by session state value.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_475A90 (00475a90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xBC4 | R | — | Compound index value passed to CompoundIndexLookup |
| this | 0x1570 | R | — | Suspension force scaling factor (double) |
| this | 0x1578 | R | — | Suspension force multiplier (double) |
| this | 0x1584 | R | — | Suspension force numerator offset (int) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |
| 0059ea70 | dbl_59EA70 | R | SuspForceConst [DERIVED] |
| 008ad254 | dword_8AD254 | R | StateFlagPair [DERIVED] |
| 008adb88 | unk_8ADB88 | R | TireDatasetHandle [DERIVED] |
| 008aeec0 | dword_8AEEC0 | R | AeroSuspensionModeSelector [DERIVED] (also: ` — aero/suspension mode selector (0=fixed, 1=blended, 2=fixed-alt) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042ed00 | SessionStateIndexedLookup | Looks up session state value (e.g., speed or RPM) used as denominator |
| 004d7570 | CompoundIndexLookup | Resolves compound index to compound data structure pointer |
| 004d7880 | TireBrandLookup | Checks if tire brand data is available; returns non-zero if valid |

**Guard conditions:** TireBrandLookup must return non-zero (tire brand data must exist) or function returns 0.0. CompoundIndexLookup must return non-null pointer (compound data must be available) or returns 0.0. Global dword_8AEEC0 selects force coefficient mode: value 0 uses aero-derived coefficient, 1 blends aero and suspension coefficients, 2 uses pure suspension coefficient; any other value returns 0.0. Final computed force must be > 0.0 or returns 0.0.
