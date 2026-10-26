## sub_4DAD80_004dad80 — CheckAllVehiclesFinished

**Summary:** Checks whether all vehicles have finished the race by comparing position counts against vehicle tally and verifying trailing vehicles' finish states. Returns 1 when race completion is confirmed. Part of race management system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4DA840 (004da840)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x20 | R | — | Stored count of finished/advanced vehicles (from sub_4DA990) |
| this | 0x28 | RW | 1 | One-shot flag: tracks whether trailing-vehicle finish check has been performed |

**Written-by note (persistence):**
- this 0x28: Written once from init 1 → 1 (set unconditionally on entry to the inner block); effectively one-shot marker

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005f073c | dword_5F073C | R | VEH[0].0x4064 = FinishState [FACT] |
| 007c54e8 | dword_7C54E8 | R | PlayerVehiclePtr [FACT] |
| 008acee0 | dword_8ACEE0 | R | ForceFeedbackBase [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d1b50 | sub_4D1B50 | Resolves vehicle index from ForceFeedbackBase and position offset |
| 004da990 | sub_4DA990 | Counts vehicles at or beyond lap threshold |
| 004dae80 | ArithmeticComparison_ae80 | Returns boolean for race-end condition (likely timer or leader check) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x28 | == | 1 | One-shot flag: first time checking trailing vehicles |

**Guard interpretation:**
- Line 13: `ArithmeticComparison_ae80()` returns true OR `this+0x20 == VehicleCount`. PASS: set v2=1 (race-end condition met). BLOCK: continue checking.
- Line 16: `sub_4DA990(this) == player_position_index` AND `position != VehicleCount`. PASS: enter trailing-vehicle check. BLOCK: skip, use current v2.
- Line 19: `*(this+0x28) == 1` (one-shot). PASS: execute trailing-vehicle scan. BLOCK: skip scan (already done once).
- Line 27: Trailing vehicle FinishState is 0 (not finished). PASS: break loop (straggler exists → v2 stays 1). BLOCK: continue scanning.
- Line 34: All trailing vehicles finished (`v6 == VehicleCount`). PASS: set v2=0 (not ready — wait for them). BLOCK: v2 stays 1.
