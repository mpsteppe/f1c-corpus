## sub_4BFF70_004bff70 — Grid position assignment

**Summary:** Assigns starting grid positions to all vehicles based on qualifying performance or randomized order. Handles both qualifying-session grid ordering and non-qualifying random placement.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DynMan_Init (0042c1a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec6d0 | unk_5EC6D0 | R | base of vehicle data array |
| 005f070c | unk_5F070C | R | VEH[0] offset 0x4034 — score/performance field for sorting |
| 005f0734 | unk_5F0734 | R | VEH[0] offset 0x405C — qualifying session time |
| 005f0cf8 | unk_5F0CF8 | R | VEH[0] offset 0x4620 — driver name string |
| 007c54e8 | dword_7C54E8 | R | pointer to player vehicle |
| 007ce668 | dword_7CE668 | R | track name display string pointer |
| 007d0110 | dword_7D0110 | R | current car display index for player |
| 007d0410 | dword_7D0410 | R | championship mode flag (1-5) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042bc10 | ScoringGateCheck | check if qualifying scoring gate is active |
| 004bc2f0 | ConditionalFieldSetter | set grid position field with conditional check |
| 004c0260 | sub_4C0260 | get qualifying position for a driver name |
| 004c02d0 | sub_4C02D0 | get qualifying time for a driver name |
| 005884ed | RandLCGRandomNumberGenerator | generate random starting position for player in non-qualifying sessions |

**Guard conditions:** Returns early if ChampionshipMode is not between 1 and 5. If dword_7D0110 == dword_7D011C (same display index): performs score-based grid sorting using three-field records (performance score, qualifying time, vehicle index). Otherwise: handles non-qualifying grid with optional player position randomization and sequential assignment for remaining vehicles.
