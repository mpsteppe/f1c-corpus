## VehicleControlEnabled_004a6db0 — Vehicle control-enable gate with disqualification and health checks

**Summary:** Returns `true` if the vehicle has active control (steering/throttle allowed). Three gates must all pass: (a) SessionType is race (7) or menu (0); (b) either `dword_7CE814` is true OR all 8 health fields on the sub-object at `*this` are nonzero, AND the DQ state at offset +0x4064 is NOT 1 or 3; (c) `sub_4D21D0(&dword_8ACEE0)` returns nonzero. Value 2 for DQ state does NOT disable control — consistent with confirmed struct knowledge (0=normal, 1=DQ pending, 2=something, 3=DQ final; 1 and 3 block).

**Struct fields accessed:**

All on the sub-object pointed to by `v1 = *this` (separate from the main `this` struct):

| Offset (dec) | Offset (hex) | Read/Write | Purpose inferred from code |
|---|---|---|---|
| `+2100` (int) | +0x834 | Read | Health/status field 1 (int group) |
| `+2164` (byte) | +0x874 | Read | Health/status field 1 (byte flag) |
| `+2396` (int) | +0x95C | Read | Health/status field 2 (int group) |
| `+2460` (byte) | +0x99C | Read | Health/status field 2 (byte flag) |
| `+2692` (int) | +0xA84 | Read | Health/status field 3 (int group) |
| `+2756` (byte) | +0xAC4 | Read | Health/status field 3 (byte flag) |
| `+2988` (int) | +0xBAC | Read | Health/status field 4 (int group) |
| `+3052` (byte) | +0xBEC | Read | Health/status field 4 (byte flag) |
| **`+16484` (int)** | **+0x4064** | Read | **DQ state**: 0=normal, 1=DQ pending (BLOCKED), 3=DQ final (BLOCKED), 2=passes |

Pattern: 4 groups, each with int (at base) + byte flag (at base+0x40), stride 0xE8 between groups — likely 4 wheel/suspension or tire health indicators.

**Guard conditions:**

| Check | Values checked | PASSES (enabled=true) | BLOCKED (enabled=false) |
|---|---|---|---|
| `dword_7C56A4` (SessionType) | 7 or 0 vs other | SessionType is 7 (race) or 0 (menu) | Other session types |
| 8 health fields at *this (+0x834..+0xBEC) | Each compared with zero | ALL nonzero (or `dword_7CE814` is true) | Any field is zero AND `dword_7CE814` is false |
| DQ state at +0x4064 | 0, 1, 2, 3 | **0 or 2** | **1 (DQ pending) or 3 (DQ final)** |
| `sub_4D21D0(&dword_8ACEE0)` | return value | nonzero | zero |

**Written-by note:** This function only READS fields; it writes nothing. All checks are stateless boolean tests. External writes to the DQ field (+0x4064) or health fields will be read on next call — because Frame-path is ON_FRAME_PATH, this function runs every tick and will observe the new values. However, a separate function (like AIAbility) may overwrite DQ state independently; the read here reflects whatever the DQ state is at tick time.

**Globals referenced:**

| Address | IDA name | Read/Write | Role |
|---|---|---|---|
| 0x007C56A4 | dword_7C56A4 (SessionType) | Read | Session type guard (7=race, 0=menu pass; others block) |
| 0x007CE814 | dword_7CE814 | Read | Bypass flag: if true, skips 8-field health check |
| 0x008ACEE0 | dword_8ACEE0 | Read | Passed by address to `sub_4D21D0` |

**Functions called:**

| Address | IDA name | Inferred purpose |
|---|---|---|
| — | sub_4D21D0 | Returns nonzero if some global condition is enabled |

**Call frequency:** per-frame tick (ON_FRAME_PATH from MainGameTickUpdate; called by AIStateMachineWithModeDispatch and PitStateUpdateMachine)
