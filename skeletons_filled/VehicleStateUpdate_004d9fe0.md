## VehicleStateUpdate_004d9fe0 — Vehicle lap gap state update

**Summary:** Compares player vehicle's lap/segment times (from offsets 16592/16596) to compute a gap value via LapTimeGapCalculation. Sets comparison type flag (this[6]=0/1) and stores the reference time. Triggers VTableDispatchWithFieldClear on gap success or zero-gap threshold.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4D9F80 (004d9f80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | R | — | Gap time result (float); read for zero-threshold check; triggers dispatch if <= 0 |
| this | 0x18 | RW | 0 | Comparison type flag (byte): 1 = using offset 16592, 0 = using offset 16596 |
| this | 0x1C | RW | — | Reference time value copied from vehicle's comparison slot |

**Written-by note (persistence):**
- this 0x18: Set to 0 or 1 based on which vehicle slot was used. External poke survives.
- this 0x1C: Set to the time value from the active comparison slot. External poke survives.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 007c54e0 | dword_7C54E0 | R | postProcessInput [CONFIRMED] — current player vehicle pointer |
| 007ce234 | unk_7CE234 | R | DriverAppearanceFlag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049b6d0 | LapTimeGapCalculation | Computes time gap between two vehicle time values; writes gap to this+0x14 |
| 004d7e30 | VTableDispatchWithFieldClear | Dispatches vtable callback and clears struct field on success condition |

**Guard conditions:** Both `dword_7C54E0+16592` and `dword_7C54E0+16596` zero → BLOCKED from comparison paths (goto LABEL_6). `dword_7C54E0+16592` non-zero → path A (flag=1); else path B (flag=0). `LapTimeGapCalculation` result non-zero → triggers dispatch. `this+20` (gap float) <= 0.0 → triggers dispatch. `v6` non-zero → triggers dispatch.
