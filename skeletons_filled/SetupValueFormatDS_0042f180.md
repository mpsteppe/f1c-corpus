## SetupValueFormatDS_0042f180 — SetupValueFormatDS

**Summary:** Formats a vehicle setup value as degrees/seconds ("%d %s"). Computes scaled value from index×multiplier+base, converts with 0.001 factor, optionally applies degrees-to-something multiplier (~5.71) when format flag is 1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SetupValueFormatDispatcher (0042f2f0), VehicleSetupValueFormatter (0042f470)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | Format flag: 1 applies degree conversion factor (~5.71), 0 uses raw value |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059ea00 | dbl_59EA00 | R | DynSolverConvergenceThreshold [DERIVED] |
| 0059ea08 | dbl_59EA08 | R | CollisionSkinThickness [DERIVED] (also: ` — clock sync tolerance) |
| 005c3778 | aDS | R | aDS [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058815f | StringFormatWithBufferOverflowCheck | Safe vsnprintf-style format string with overflow guard |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x4 | == | 1 | Format flag == 1 |

**Guard interpretation:** this[1] == 1: PASSES (multiply value by 5.71 degree conversion factor). != 1: BLOCKED (uses raw computed value). Both paths format via StringFormatWithBufferOverflowCheck.
