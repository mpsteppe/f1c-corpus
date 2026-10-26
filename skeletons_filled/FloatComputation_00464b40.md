## FloatComputation_00464b40 — Collision response dispatch with flag clearing

**Summary:** Processes collision data from a2: if sensor value at this+0x71 < a2+4 or flag XOR mismatch, dispatches to VehicleOrientationFromEulerAngles or ArithmeticComparison_3a90 based on a2's type field, then clears 104 bit flags via BitFlagSetter.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_465300 (00465300)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x70 | R | — | Flag byte XORed with a2+3 to check collision type mismatch |
| this | 0x71 | R | — | Sensor float value compared with a2+4 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004649f0 | BitFlagSetter | Sets or clears bit 7 on each of 104 flag bytes (clears all here) |
| 004b2dd0 | VehicleOrientationFromEulerAngles | Sets vehicle orientation from Euler angle input |
| 004b3a90 | ArithmeticComparison_3a90 | Performs arithmetic comparison operation on a2 |

**Guard conditions:** PASSES (enters body) when: float at this+0x71 < a2+4, OR XOR of byte at a2+3 and this+0x70 has any of bits 0-2 set. BLOCKED (skips body) when: this+0x71 >= a2+4 AND XOR bits 0-2 all zero.
