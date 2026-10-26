## TireForce_004e9100 — tire force friction-circle computation with table lookups

**Summary:** Computes tire force using friction-circle model with sign-selected lookup tables, linear interpolation, and aerodynamic drag term. Part of tire dynamics system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PhysicsNodePropagationWithDistanceFalloff (00401c90), AIRacingLine (00425920)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3514 | R | — | sprung mass factor (vertical force scaling) |
| this | 0x3518 | R | — | tire force scaling multiplier (applied to final force) |
| this | 0x3A70 | R | — | force coefficient for squared slip velocity |
| this | 0x3BFC | R | — | aerodynamic table lookup scaling factor |
| this | 0x3C00 | R | — | start of 14-entry aerodynamic/aero-force lookup table (this[3840..3853]) |
| this | 0x3C3C | R | — | positive-force branch selector threshold (this[3855]) |
| this | 0x3C40 | R | — | start of 14-entry positive force lookup table (this[3856..3869]) |
| this | 0x3C7C | R | — | negative-force branch selector threshold (this[3871]) |
| this | 0x3C80 | R | — | start of 14-entry negative force lookup table (this[3872..3885]) |
| this | 0x3D3C | R | — | tire force maximum cap (this[3919]) |
| this | 0x3D44 | R | — | additional drag/force coefficient (this[3921]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005895a2 | sub_5895A2 | unknown — called with computed intermediate values, return not used |

**Guard conditions:** Sign flag (v10|v11) selects positive (0x3C40) vs negative (0x3C80) lookup table. Table index < 0 → use index 0 entry. Index >= 14 → clamped to 13. v19 <= 0.0 (friction circle saturated) → force component = 0. BLOCKED via final cap at this[3919].
