## sub_4DDB70_004ddb70 — Pit Lane Speed and Track Violation Detection

**Summary:** Per-frame check for pit-lane speeding, wrong-way driving, cut-track penalties, riding-wall, blue-flag ignoring, and excessive speed violations in a racing game. Dispatches warnings/penalties via sub_4DC690 and sub_4DCCC0.

**Called by:** sub_42E720 (0042e720)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4404 | R | — | On-track flag (byte at *(obj+17412)) |
| obj | 0x449C | R | — | Speed-scalar for pit speeding accumulation (flt at obj+17548) |
| obj | 0x44C4 | R | — | Position X component (flt at obj+17520) |
| obj | 0x44C8 | R | — | Position Y component (flt at obj+17524) |
| obj | 0x44CC | R | — | Position Z component (flt at obj+17528) |
| obj | 0x44DC | R | — | Velocity X (flt at obj+17544) |
| obj | 0x44E0 | R | — | Velocity Y (flt at obj+17548) |
| obj | 0x44E4 | R | — | Velocity Z (flt at obj+17552) |
| obj | 0x44F0 | R | — | Vehicle lateral/longitudinal scalar (flt at obj+17564) |
| obj | 0x4560 | R | — | Some speed/state for riding-wall check (flt at obj+17676) |
| obj | 0x4B71 | R | — | Flag for pit-lane detection (byte at obj+19229) |
| this | 0x0 | R | — | Pointer to object (vtable/self) |
| this | 0x4 | R | — | Car index/player ID |
| this | 0xC | R | — | Lap/position counter |
| this | 0x10 | R | — | Lap/position reference |
| this | 0x30 | R | — | Player/race state |
| this | 0x40 | R | — | Count of active penalty/warning slots |
| this | 0x44 | R | — | Penalty type enum per slot |
| this | 0x74 | RW | 1 | Pit-lane speeding accumulation timer/state (0,1,2) |
| this | 0xBC | RW | 0 | Sped-into-pit-lane flag |
| this | 0xC0 | RW | 0 | Sped-out-of-pit-lane flag |
| this | 0xC4 | RW | 1 | Pit-lane active flag (byte, 1=in pit) |
| this | 0xC5 | RW | 1 | Pit-lane speeding was excessive flag |
| this | 0xC6 | RW | 0 | Pass-through penalty serving flag |
| this | 0xC8 | RW | 0 | Pit speeding accumulated distance |
| this | 0xCC | RW | 1 | Wall-riding warning flag |
| this | 0xD0 | RW | 0 | Wall-riding accumulated distance |
| this | 0xD4 | RW | 0 | Wall-riding accumulated lateral distance |
| this | 0xE4 | R | — | Race state/session flag |
| this | 0xF8 | RW | 1 | Wrong-way detection active flag |
| this | 0xFC | RW | — | Wrong-way accumulated counter |
| this | 0x100 | RW | — | Cut-track state (bool) |
| this | 0x104 | RW | — | Cut-track accumulated distance/score |
| this | 0x108 | RW | — | Cut-track reference distance |
| this | 0x10C | RW | 0 | Cut-track reference lap time |
| this | 0x110 | RW | — | Cut-track reference speed |
| this | 0x114 | R | — | Cut-track violation count |
| this | 0x13C | R | — | Blue-flag ignore flag |
| this | 0x140 | RW | — | Blue-flag ignore accumulated time |
| this | 0x144 | RW | 0 | Blue-flag ignore reference car index |

**Written-by note (persistence):**
- this 0x74: written once per update cycle when entering/exiting pit; external poke would be overwritten next frame
- this 0xBC: set on detection of sped-into-pit-lane event; survives until cleared by penalty dispatch
- this 0xC0: set on detection of sped-out-of-pit-lane event; survives until cleared by penalty dispatch
- this 0xC4: written every frame based on pit-lane status; external poke overwritten next frame
- this 0xC5: set once when excessive pit speeding detected; cleared on re-entry
- this 0xC6: set when serving pass-through penalty; external poke may survive briefly
- this 0xC8: accumulated per frame when in pit lane; external poke overwritten next frame
- this 0xCC: set on wall-riding detection; cleared when below threshold
- this 0xD0: accumulated per frame during wall-ride; external poke overwritten next frame
- this 0xD4: accumulated per frame; external poke overwritten next frame
- this 0xF8: set once when wrong-way detected; cleared when resolved
- this 0xFC: recalculated per frame based on position vs direction; external poke overwritten next frame
- this 0x100: recalculated per frame; external poke overwritten next frame
- this 0x104: recalculated per frame; external poke overwritten next frame
- this 0x108: recalculated per frame; external poke overwritten next frame
- this 0x10C: set once at cut-track start; may survive briefly
- this 0x110: recalculated per frame; external poke overwritten next frame
- this 0x140: accumulated per frame; external poke overwritten next frame
- this 0x144: set once per blue-flag target; may survive briefly

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d54dc | flt_5D54DC | R | Delta time multiplier |
| 005d54e0 | flt_5D54E0 | R | Physics constant |
| 005d54f0 | flt_5D54F0 | R | Physics constant |
| 005d5508 | flt_5D5508 | R | Speed threshold scalar |
| 005d5708 | flt_5D5708 | R | Cut-track score threshold |
| 005d5adc | flt_5D5ADC | R | Pit speeding threshold |
| 005d5b78 | flt_5D5B78 | R | Cut-track trigger threshold |
| 005d5b88 | flt_5D5B88 | R | Wall-riding threshold |
| 005d5bc0 | flt_5D5BC0 | R | Wrong-way threshold |
| 005d5bd4 | flt_5D5BD4 | R | Blue-flag timeout |
| 005d5c18 | flt_5D5C18 | R | Cut-track timeout |
| 005d5c40 | flt_5D5C40 | R | Speed normalization constant |
| 005d5c4c | flt_5D5C4C | R | Speed threshold for cut-track |
| 005d5c5c | flt_5D5C5C | R | Acceleration constant |
| 005d5ca0 | dbl_5D5CA0 | R | Pit excessive speed threshold (~150.0) |
| 005d5d18 | dbl_5D5D18 | R | Pit minor speed threshold (~15.0) |
| 005d65b8 | flt_5D65B8 | R | Lap distance constant |
| 005ea2f4 | flt_5EA2F4 | R | Cut-track angle threshold |
| 005ea6f0 | dbl_5EA6F0 | R | Pit-lane base speed limit |
| 005ea6f8 | flt_5EA6F8 | R | Pit-lane speed threshold 1 |
| 005ea6fc | flt_5EA6FC | R | Pit-lane speed threshold 2 |
| 005ea700 | flt_5EA700 | R | Pit-lane speed threshold 3 |
| 005ea704 | flt_5EA704 | R | Pit-lane speed threshold 4 |
| 005ea708 | flt_5EA708 | R | Pit-lane speed threshold 5 |
| 005ea70c | flt_5EA70C | R | Pit-lane speed threshold 6 |
| 005ea710 | dbl_5EA710 | R | Pit-lane speed limit max |
| 005fc890 | aSpeedingInPitl | R | String: "Excessive Speeding In Pitlane" |
| 005fc8cc | aRidingWall | R | String: "Riding Wall" |
| 005fd340 | NumOfElements | R | Number of cars in race |
| 00610210 | aIgnoredBlueFla | R | String: "Ignored Blue Flags" |
| 00610224 | aWrongWay | R | String: "Wrong Way" |
| 00610230 | aLapWillNotCoun | R | String: "Lap Will Not Count" |
| 00610244 | aCutTrack | R | String: "Cut Track" |
| 00610250 | aLapTimeWillNot_0 | R | String: "Lap Time Will Not Count: Riding Wall" |
| 00610278 | aSpedIntoPitLan_0 | R | String: "Sped Into Pit Lane While Serving A Pass Through Penalty" |
| 006102b0 | aSpedIntoAndOut | R | String: "Sped Into And Out Of Pit Lane" |
| 006102d0 | aSpedOutOfPitLa | R | String: "Sped Out Of Pit Lane" |
| 006102e8 | aSpedIntoPitLan | R | String: "Sped Into Pit Lane" |
| 006102fc | aExcessiveSpeed | R | String: "Excessive Speeding In Pitlane" |
| 006290d0 | flt_6290D0 | R | Lap distance base constant |
| 006290dc | flt_6290DC | R | Lap time scalar |
| 00629120 | byte_629120 | R | Empty string (zero byte) |
| 00629328 | flt_629328 | R | Physics constant |
| 0062a170 | dword_62A170 | R | Pointer to string table for BinarySearch |
| 0062a17c | Destination | R | Global string buffer for messages |
| 0062a37b | byte_62A37B | W | Flag to clear message buffer |
| 0075aac0 | dword_75AAC0 | R | Player car index |
| 0075aac8 | dword_75AAC8 | R | Player car index (duplicate) |
| 0075aad0 | dword_75AAD0 | R | Car object array base |
| 0075cbb0 | dword_75CBB0 | R | Race session state (5=practice, 7=race) |
| 0075cbb4 | dword_75CBB4 | R | Race session type |
| 00764d68 | byte_764D68 | R | Display/UI message system object |
| 00767310 | dword_767310 | R | Race state flag (>=1 = active) |
| 007d74dc | flt_7D74DC | R | Pit-lane speed base limit |
| 007d7540 | dword_7D7540 | R | Penalty system state |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041b490 | sub_41B490 | Trigger wrong-way penalty callback |
| 0041f230 | BinarySearchInStringTable [structural] | Check if string already exists in message table |
| 0045d100 | sub_45D100 | Display HUD message to player |
| 004dc580 | sub_4DC580 | Dispatch warning (first occurrence, plays sound) |
| 004dc690 | sub_4DC690 | Dispatch penalty (repeat occurrence or immediate) |
| 004dc9c0 | sub_4DC9C0 | Apply pass-through penalty |
| 004dccc0 | sub_4DCCC0 | Dispatch excessive-speed penalty |
| 004dd0c0 | sub_4DD0C0 | Get lap progress for a car |
| 004dd160 | sub_4DD160 | Check if penalty system is active |
| 004de880 | sub_4DE880 | Reset riding-wall warning state |
| 004deb10 | sub_4DEB10 | Check if car is in pit-lane |
| 004deb50 | sub_4DEB50 | Set/reset blue-flag ignore state |
| 004debe0 | sub_4DEBE0 | Process riding-wall accumulation |
| 00514ee0 | sub_514EE0 | Get vehicle state/telemetry object |
| 0051c630 | sub_51C630 | Get lap distance |
| 0051c7a0 | sub_51C7A0 | Get track position/distance |
| 0051ca30 | sub_51CA30 | Get lap time |
| 005beab0 | _strncpy | Copy string to message buffer |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x40 | > | 0 | Has active penalties; PASSES if any penalty slot populated |
| this | 0x44 | == | 2 | Penalty type is "pass-through"; BLOCKS if not pass-through |
| this | 0x74 | != | 2 | Pit lane state not "exited"; BLOCKS re-entry logic |
| this | 0x74 | == | 2 | Pit lane state is "exited"; allows penalty dispatch |
| this | 0xE4 | >= | 0 | Race session valid; PASSES if active session |
| this | 0x114 | > | 1 | More than 1 cut-track violation; triggers immediate penalty |

**Guard interpretation:** Multiple layered guard checks control penalty flow. The pit speeding logic only activates when on-track AND in a active race session (dword_75CBB4 >= 5). The wrong-way check fires when accumulated distance crosses 10.0. The cut-track check triggers when score exceeds 1.75 and race is active. Riding wall fires when sideways velocity exceeds threshold. Blue-flag ignore accumulates when car doesn't yield position. All guard conditions gate whether a warning or penalty is dispatched via sub_4DC580/sub_4DC690.

**String literals referenced (deterministic):**

- `Riding Wall`
- `Riding Wall`
- `Ignored Blue Flags`
- `Wrong Way`
- `Wrong Way`
- `Wrong Way`
- `Lap Will Not Count`
- `Lap Will Not Count`
- `Cut Track`
- `Cut Track`
- `Lap Time Will Not Count: Riding Wall`
- `Lap Time Will Not Count: Riding Wall`
- `Sped Into Pit Lane While Serving A Pass Through Penalty`
- `Sped Into And Out Of Pit Lane`
- `Sped Out Of Pit Lane`
- `Sped Into Pit Lane`
- `Excessive Speeding In Pitlane`
