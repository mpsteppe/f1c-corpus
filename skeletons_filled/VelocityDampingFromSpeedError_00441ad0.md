## VelocityDampingFromSpeedError_00441ad0 — VelocityDampingFromSpeedError

**Summary:** Computes aerodynamic velocity damping based on speed error (deviation from reference speed 8.0). Computes body speed from velocity vector, calculates damping force proportional to the speed error, applies direction-dependent scaling, and accumulates the result into the body's force buffer. Part of vehicle aerodynamics/damping system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PhysicsIntegrationStep (00441d60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x15F0) | 0x2C | R | — | body velocity X component |
| *(this+0x15F0) | 0x44 | R | — | body velocity Y component |
| *(this+0x15F0) | 0x5C | R | — | body velocity Z component |
| *(this+0x15F0) | 0x64 | R | — | body orientation matrix row (used for directional damping) |
| *(this+0x15F0) | 0x6C | R | — | body orientation matrix row |
| *(this+0x15F0) | 0x74 | R | — | body orientation matrix row |
| *(this+0x15F0) | 0x134 | RW | — | accumulated damping force X component |
| *(this+0x15F0) | 0x13C | RW | — | accumulated damping force Y component |
| *(this+0x15F0) | 0x144 | RW | — | accumulated damping force Z component |
| *(this+0x1F00) | 0x344C | R | — | state field (byte enable flag for damping) |
| *(this+0x1F00) | 0x3450 | R | — | state field (dword, compared to 3 to skip damping) |
| this | 0x48 | R | — | multiplier/direction factor for damping |
| this | 0x15F0 | R | — | pointer to rigid body state |
| this | 0x1EF0 | R | — | direction sign selector (compare to -1) |
| this | 0x1F00 | R | — | pointer to secondary state struct |

**Written-by note (persistence):**
- *(this+0x15F0) 0x134: recalc every frame — external poke does NOT persist
- *(this+0x15F0) 0x13C: recalc every frame — external poke does NOT persist
- *(this+0x15F0) 0x144: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059ed40 | dbl_59ED40 | R | SpeedErrorGain [DERIVED] |
| 0059ed48 | dbl_59ED48 | R | RefSpeed_Aero [DERIVED] (also: ` — reference speed (double) |
| 007ce838 | byte_7CE838 | R | DampingEnableFlag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0x1F00) | 0x3450 | != | 3 | state identifier — damping skipped when state == 3 |
| this | 0x1EF0 | != | 18446744073709551615 | direction sign — -1 means reverse damping direction |

**Guard interpretation:** If byte at *(this+0x1F00)+0x344C is zero, entire function is blocked (early return). If state dword at *(this+0x1F00)+0x3450 == 3, damping is skipped. If global byte_7CE838 (DampingEnableFlag) is zero, damping is skipped. If computed speed error <= 0 (body speed >= 8.0), damping force is not applied. Direction sign at this+0x1EF0: if == -1, damping direction is positive; if != -1, damping direction is negated.
