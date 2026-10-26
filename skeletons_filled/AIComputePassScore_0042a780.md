## AIComputePassScore_0042a780 — AIComputePassScore

**Summary:** Computes a weighted overtaking/passing score from AI ability factors and opponent vehicle data. Score = (input * a1[0x4504] + a1[0x4500]) * a1[0x4580] * a1[0x453C] * opponent[0x84]. Calls TireForceSolver on opponent tire data. Used by AIRacingLine for pass decision.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIRacingLine (00425920)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4500 | R | — | pass score additive weight (added to scaled input) |
| this | 0x4504 | R | — | pass score multiplicative weight (scales input a2) |
| this | 0x453C | R | — | pass score scaling factor for AI ability |
| this | 0x4580 | R | — | pass score global multiplier |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004e8ce0 | TireForceSolver | computes tire forces for opponent vehicle (context for pass scoring) |

**Guard conditions:** No guard conditions — always computes and returns score.
