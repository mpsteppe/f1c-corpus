## CarPositionTargetCheck_004fe060 — CarPositionTargetCheck

**Summary:** Checks car position (this+0x8) against computed target via sub_4FC910. Sets match flag (this+0x4) to 2.0f if within 0.5 threshold, else 0.0f. Blocked in multiplayer when scoring gate is active. Calls RangeInterpolationTable after evaluation.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B3400 (004b3400)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | 0 | match flag (2.0f = target within tolerance, 0.0f = not matched) |
| this | 0x8 | R | — | current position value (compared against computed target) |

**Written-by note (persistence):**
- this 0x4: conditionally set to 2.0f or 0.0f each call; overwritten each evaluation

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | degrees-to-radians constant (not directly referenced in this C code) |
| 007c56a0 | dword_7C56A0 | R | multiplayer flags (bit 0 tested for multiplayer mode) |
| 008ab6e4 | dword_8AB6E4 | R | scoring gate value (compared to 2) |
| 008ab6ec | dword_8AB6EC | R | scoring data pointer (passed to PackedFlagRead_9a00) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b9a00 | PackedFlagRead_9a00 | reads packed flag from scoring data structure |
| 004fc910 | sub_4FC910 | computes target value from position at this+0x20 |
| 004fd6f0 | RangeInterpolationTable | calls interpolation/mapping table function |

**Guard conditions:** function body BLOCKED when multiplayer flag is set (dword_7C56A0 & 1) AND (dword_8AB6E4 != 2 OR PackedFlagRead_9a00 returns true). PASSES (evaluation proceeds) in single-player OR when scoring gate is not matching.
