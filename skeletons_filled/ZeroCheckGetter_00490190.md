## ZeroCheckGetter_00490190 — ZeroCheckGetter

**Summary:** Returns whether a state flag at offset 0xE0 is zero. Simple boolean getter for UI component state.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ParameterValueClampingAcrossArray (0047a080), SuspensionFloatClamp (0047a290)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xE0 | R | — | State flag being tested for zero |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xE0 | == | 0 | State flag tested for zero |

**Guard interpretation:** PASSES (returns true) when `this[56]` equals 0. BLOCKED (returns false) when non-zero.
