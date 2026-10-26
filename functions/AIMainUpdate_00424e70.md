## AIMainUpdate_00424e70 — Per-frame AI controller tick

**Summary:** Per-frame AI driver update. Entry guard on this+0x32C8 (pass 0,1; block 2+). Computes heading vector (-sin(yaw), -cos(yaw)) at 0x448C/0x4494. Pit scheduling state machine at 0x4510: values 4/5 = pit entry, 0/6 = racing, 1 = sub_4258C0, 2 = FieldZeroSetter+return, 3 = distance check, 7 = coast. Writes final actuator outputs (throttle/brake/steering) to 0x357C/0x3580/0x3584 each frame. ON_FRAME_PATH — no external poke survives.

**Struct fields accessed:**

| Offset (dec) | Offset (hex) | Read/Write | Init value (if written as literal) | Purpose inferred from code |
|---|---|---|---|---|
| 13000 | 0x32C8 | Read | — | Entry guard: pass 0-1, block 2+ |
| 13536 | 0x34E0 | Read | — | Vehicle position X (used in distance check state 3) |
| 13544 | 0x34E8 | Read | — | Vehicle position Z (used in distance check state 3) |
| 13552 | 0x34F0 | Read | — | Yaw angle (radians), source for heading vector |
| 13692 | 0x357C | Write | 0 | Brake output (actuator value sent to physics) |
| 13696 | 0x3580 | Write | 0 | Steering output (actuator value sent to physics) |
| 13700 | 0x3584 | Write | 1065353216 = 0x3F800000 = 1.0f | Throttle output (actuator value sent to physics) |
| 14724 | 0x3984 | Read | — | Speed threshold (compared vs 0.001) |
| 14748 | 0x399C | Read | — | Front speed reference (used in distance computation) |
| 14752 | 0x39A0 | Read | — | Rear speed reference (used in distance computation) |
| 15724 | 0x3D6C | Read | — | Flag check (==2 triggers special handling at LABEL_86) |
| 15728 | 0x3D70 | Write | Random indexed write | AI waypoint timing array (indexed by *v22, 0-4) |
| 16424 | 0x4028 | Write | 0 | Reset flag (cleared in init block) |
| 16484 | 0x4064 | Read | — | DQ state (value 2 clears AI flag byte at 0x45F4) |
| 16488 | 0x4068 | Write | Random 3/7/8 | AI random mode select |
| 16540 | 0x409C | Read | — | AI base speed (used as speed cap) |
| 16700 | 0x413C | Write, Read | dbl_8AFEA0+2.0, 2139095039=0x7F7FFFFF=FLT_MAX | AI timer/expiry sentinel (compares vs dbl_8AFEA0) |
| 16708 | 0x4144 | Read | — | Array of 5×2 DWORD structs for pit scheduling |
| 16712 | 0x4148 | Read | — | Array index pointer (v22 traverses stride 8) |
| 16748 | 0x4178 | Write | 1109393408=0x42194000=38.3125f or random | AI random wait base / waypoint timing |
| 16752 | 0x4170 | Read, Write | Random+const, 2139095039=FLT_MAX | Pit entry trigger threshold (compared vs 0x4480) |
| 17400 | 0x43F8 | Write | 0 | AI flag cleared on pit entry |
| 17412 | 0x4404 | Read, Write | 0x4480+4.0 | AI ability threshold (updated when 0x4480 exceeds it) |
| 17440 | 0x4420 | Write | 0 | AI proximity flag cleared |
| 17444 | 0x4424 | Write | 0 | AI state flag cleared |
| 17448 | 0x4428 | Read | — | ABS value used in LABEL_86 special handling |
| 17452 | 0x442C | Write, Read | 0 | Steering computed value (copied to 0x3580) |
| 17460 | 0x4434 | Write, Read | 0 or computed or 1065353216=1.0f | Brake computed value (copied to 0x357C) |
| 17464 | 0x4438 | Write, Read | 1065353216=1.0f or 0.2f or computed | Throttle computed value (copied to 0x3584) |
| 17468 | 0x443C | Write | 0 | AI flag cleared on pit entry |
| 17472 | 0x4440 | Read | — | State 7 timer (if <0.2, sets 0x4510=0) |
| 17480 | 0x4448 | Read, Write | -0.025 decrement | AI ring buffer decay timer |
| 17484 | 0x444C | Read, Write | dword_7C56A8 | AI ring buffer state tracker |
| 17532 | 0x447C | Write | dbl_8AFEA0+4.0 | Pit re-entry timer |
| 17536 | 0x4480 | Write, Read | dbl_8AFEA0 | AI master clock / frame reference |
| 17540 | 0x4484 | Write | 1232348144 | Threshold value (written before AIRacingLine) |
| 17548 | 0x448C | Write | -sin(this+0x34F0) | Heading vector X |
| 17556 | 0x4494 | Write | -cos(this+0x34F0) | Heading vector Z |
| 17680 | 0x4510 | Write, Read | 0, 3, 4, 5 | AI state machine: 4=pit(race),5=pit(non-race),0=racing,1=sub,2=zero,3=dist,6=racing,7=coast |
| 17700 | 0x4524 | Write | 0 | AI flag cleared on pit entry |
| 17716 | 0x4534 | Read, Write | dbl_8AFEA0+4.0 | Pit timer gate (compared vs dbl_8AFEA0) |
| 17740 | 0x454C | Write | 0 | AI flag cleared on pit entry |
| 17744 | 0x4550 | Write, Read | 1 | Pit exit lap counter (compared vs dword_5EA2CC) |
| 17760 | 0x4560 | Read, Write | dbl_8AFEA0, toggles | AI speed reference timer (toggled by 0x4568) |
| 17764 | 0x4564 | Read, Write | Random+const range | AI speed target (recalculated every other frame) |
| 17768 | 0x4568 | Read, Write | 0/1 toggle | AI speed timer toggle flag |
| 17800 | 0x4588 | Read | — | Pit completion counter (compared vs 0x45E0) |
| 17888 | 0x45E0 | Read | — | Pit entry counter (compared vs 0x4588) |
| 17908 | 0x45F4 | Read, Write | 0 | AI active flag byte (cleared by DQ state 2 or pit complete) |
| 17916 | 0x45FC | Write, Read | 0 | AI processing gate flag |
| 17948 | 0x461C | Read, Write | Distance squared | Proximity distance in state 3 (updated each frame) |
| *this+13000 | *(DWORD*)this+0x32C8 | Read | — | Indirect guard (==1 needed for main init and AI logic) |
| *this+18596 | *(DWORD*)this+0x48A4 | Read | — | Track data index used in ArrayOfStructIndexedFieldCopy |

**Guard conditions:**

| Field | Checked values | What PASSES | What is BLOCKED |
|---|---|---|---|
| this+0x32C8 | >1 | 0, 1 | 2+ (early return) |
| byte_45F4 (0x45F4) | ==0 AND *(DWORD*)this+0x32C8==1 | byte=0 AND indirect==1 | byte!=0 OR indirect!=1 (skip init block) |
| sub_426430(this) | return value | non-zero AND *(DWORD*)this+0x32C8==1 | zero OR indirect!=1 (return after heading compute) |
| this+0x4510 | ==4 or ==5 | pit entry state (skip AI driving, use pit logic) | NOT 4 and NOT 5 (enter AI driving state machine) |
| this+0x15724 | ==2 | special handling at LABEL_86 (throttle/brake based on 0x4428) | normal computation |
| this+0x4064 | ==2 | clears byte at 0x45F4 | no action |

**Written-by note:** Writes ~30 fields. Critical per-frame outputs at 0x357C (brake), 0x3580 (steering), 0x3584 (throttle) — written every frame. State machine field 0x4510 written conditionally. Heading vector 0x448C/0x4494 recomputed every call. ON_FRAME_PATH → all fields overwritten each frame; external poke to ANY field will NOT persist.

**Globals referenced:**

| Address | IDA name | Read/Write | Role |
|---|---|---|---|
| 0x008AFEA0 | dbl_8AFEA0 | Read | Master game time/clock double |
| 0x007C56A8 | dword_7C56A8 | Read | Session sub-state (5=session, 1=practice, 8=race complete?) |
| 0x007C56A4 | dword_7C56A4 | Read | SessionType (7=race) |
| 0x005C329C | dword_5C329C | Read | VehicleCount |
| 0x005C3160 | byte_5C3160 | Read, Write | AI global gate flag (set to 1 when 0x444C==4) |
| 0x005EA2CC | dword_5EA2CC | Read | AI pit exit threshold |
| 0x005EA2C0 | dword_5EA2C0 | Read | Track data structure pointer |
| 0x005C3144 | dword_5C3144 | Read | Indexed speed table |
| 0x005C30E0 | unk_5C30E0 | Read | Indexed data near 0x5C30E0 |
| 0x008ACFB8 | flt_8ACFB8 | Read | Float constant |

**Functions called:**

| Address | IDA name | Inferred purpose |
|---|---|---|
| 0x00424BC0 | AIRingBufferFieldInit | Initialize AI ring buffer |
| 0x00424B60 | SessionCleanupFlagClear | Clear session cleanup flag |
| 0x0042B570 | ConditionalGate | Gate check on this+12 |
| 0x0042B540 | RandLCGRandomNumberGenerator | LCG random number |
| 0x0042B440 | CRTFtol | C runtime ftol (float-to-long conversion) |
| 0x004A5AE0 | RaceStartCountdownStateUpdate | Update countdown state |
| 0x00426430 | sub_426430 | AI subsystem guard check |
| 0x00428D50 | AIStateFlagSetter | Set AI state flag |
| 0x00445420 | AIPushLap | Push lap data for AI |
| 0x004A4110 | sub_4A4110 | AI state query |
| 0x0042BD10 | AIAbility | Ability check calculation |
| 0x004264B0 | AIClearStateFlags | Clear AI state flags |
| 0x00421DE0 | VehicleClimbAdjust | Climb adjustment reset |
| 0x004275A0 | OpponentProximityScanTeamRecognition | Proximity scan with team recognition |
| 0x004244E0 | AIRacingLine | Racing line computation |
| 0x00427250 | AISteering | Steering computation |
| 0x00426100 | sub_426100 | AI subsystem update |
| 0x004242D0 | AISteeringCorrection | Steering correction |
| 0x004282E0 | PhysicsGearShiftLogicWithThresholds | Gear shift logic |
| 0x00427740 | SteeringAngleController | Steering angle control |
| 0x004258C0 | sub_4258C0 | AI state 1 handler |
| 0x00425EF0 | FieldZeroSetter | Zero field and return |
| 0x0042B5C0 | RandomWeightedTierSelection | Weighted random tier selection |
| 0x0042B5F0 | LoopWithConditionalSubCall | Loop with conditional sub-call |

**Call frequency:** per-frame tick (ON_FRAME_PATH, via MainGameTickUpdate)
