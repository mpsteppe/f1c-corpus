# Struct Offset Reference
## New Struct Offset Summary (Session 2)
### New Struct Offset Summary (Session 2)

**Physics vehicle instance:**

| Offset | Type | Field |
|--------|------|-------|
| +0x1db4 | double | Effective engine lifetime |
| +0x1dbc | double | LifetimeEngineRPM min |
| +0x1dc4 | double | 1 / LifetimeEngineRPM max |
| +0x1dcc | double | LifetimeOilTemp min |
| +0x1dd4 | double | 1 / LifetimeOilTemp max |
| +0x1140–+0x115c | double×8 | Front tire telemetry |
| +0x1160 | byte[16] | Front compound flags |
| +0x1170 | int | Current front compound index |
| +0x1174–+0x117c | int×3 | Compound selections: stops 2–4 |
| +0x1180 | uint | PitStopFlag bitmask |
| +0x153c–+0x1558 | double×8 | Rear tire telemetry |
| +0x155c | byte[16] | Rear compound flags |

**Player options struct (FUN_004aa270):**

| Offset | Stride | Count | Content |
|--------|--------|-------|---------|
| +0x5c8 | 0x24 | 7 | FailureRate[0..6]: {current=2, min=0, max=3} |

**Wheel corner struct (FUN_004f2c60, per wheel):**

| Offset | Field | Notes |
|--------|-------|-------|
| +0xb8 | BrakeOptimumTemp | +273.15 K applied at load |
| +0xf0 | BrakeWearRate | |
| +0xf8 | BrakeFailure min | |
| +0x100 | BrakeFailure max | |

---



---

## Source: docs/06-session-race-logic.md

# Struct Offset Synthesis — Worker A

Source: `docs/06-session-race-logic.md` (845 functions, 287 struct offset sections, 996 offset observations)

Generated: 2026-07-15

---

## VehicleStruct (param_1 — vehicle struct)

Largest observed struct. Range 0x0000–0x48C0. Used by physics, AI, session, and replay functions.

Based on 48+ function observations. Confidence: **high**.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x0000–0x07 | various | VTable / object header | multiple | Standard MSVC object header |
| +0x08 | float | PositionX | FUN_004e2130, FUN_004e2070 | World position; aligned |
| +0x0c | float | PositionY | FUN_004e2130, FUN_004e2070 | |
| +0x10 | float | PositionZ | FUN_004e2130, FUN_004e2070 | |
| +0x14 | float[4] | Orientation | FUN_004e2130 | Quaternion (x,y,z,w) |
| +0x20–+0x40 | float[3][3] | RotationMatrix | FUN_004e2130, FUN_004ed420, FUN_004e9bd0, FUN_004ef180, FUN_004f17d0, FUN_004eff00, FUN_004e9980 | Column-major, 9 floats |
| +0x34b0 | float | RotationMatrix[0][0] | FUN_004e9bd0, FUN_004ed420, FUN_004ef180, FUN_004f17d0 | Row 0 |
| +0x34b8 | float | CoolingCoeff1 / DirX | FUN_004e87e0, FUN_004eff00 | Direction/thermal |
| +0x34bc | float | RotMatrix_row1[0] | FUN_004ed420 | |
| +0x34c4 | float | GridForwardDirX / DirY | FUN_004d0110, FUN_004eff00 | |
| +0x34c8 | float | RotMatrix_row2[0] | FUN_004ed420 | |
| +0x34d0 | float | GridForwardDirY / DirZ | FUN_004d0110, FUN_004eff00, FUN_004e9980 | |
| +0x34d4 | float | TranslationX / PosX | FUN_004e9bd0, FUN_004ef6c0, FUN_004e9980, FUN_004e9630 | World position X |
| +0x34d8 | float | PosY | FUN_004ef6c0, FUN_004e9980, FUN_004e9630 | World position Y |
| +0x34dc | float | PosZ / GridForwardDirZ | FUN_004d0110, FUN_004ef6c0, FUN_004e9980, FUN_004e9630, FUN_004f0050 | World position Z |
| +0x34e0 | ptr | AIStateStructBase | FUN_0042add0 | Pointer to AI substate |
| +0x34ec–+0x34f4 | float[3] | InputVector / Velocity | FUN_004eff00, FUN_004f1aa0 | Force/velocity input |
| +0x34f8 | float | Velocity/PositionZ | FUN_004d0110 | |
| +0x34fc | float | Velocity/PositionY | FUN_004d0110 | |
| +0x3500 | float | Velocity/PositionX | FUN_004d0110, FUN_004e87e0 | Also BrakePadTemp |
| +0x3504 | float | VarA | FUN_004e4e60 | Physics integration state |
| +0x3508 | float | VarB | FUN_004e4e60 | |
| +0x350c | float | VarC | FUN_004e4e60 | |
| +0x3514 | float | ForceScaleFactor / DampingCoeff | FUN_004e9100, FUN_004e9300, FUN_004e8010, FUN_004e8b80 | Scales force terms |
| +0x3518 | float | OutputScaleFactor / GripMultiplier / ScaleFactor | FUN_004e9100, FUN_004e9300, FUN_004e8010, FUN_004e8b80 | Final force scaling |
| +0x3534 | float[3] | InputVec | FUN_004f17d0 | Input vector XYZ |
| +0x3540–+0x3548 | float[3] | OutputVec | FUN_004f17d0 | Transformed result |
| +0x3570 | float | CoolingVelocity / SpeedRatio / ForceScaling | FUN_004e5080, FUN_004e513e, FUN_004ee230 | Clamped velocity/force |
| +0x3578 | float | Speed | FUN_004ef930 | Race start speed |
| +0x3580+0x90 | float | RearAxleRef | FUN_004e9300 | Rear axle parameter |
| +0x358c/+0x3594 | float | SuspensionDeflection_L/R | FUN_004e8010 | L/R front suspension |
| +0x3594 | float[4] | ElementArray | FUN_004ed420 | Per-element position+radius, stride 0xf8 |
| +0x35b0 | float | LateralForce1 | FUN_004ed810 | Per-wheel lateral force |
| +0x35d8 | float | WheelCoeffs[0] | FUN_004ed810 | Per-wheel coefficient |
| +0x35dc | float | WheelForcePrev[0] | FUN_004ed810 | Per-wheel previous force |
| +0x35f0 | float[4] | WheelOutputs | FUN_004e4e60 | Per-wheel outputs, stride ~0x3e |
| +0x3610/+0x362c | float | WheelForceBase | FUN_004e8010 | Wheel force base values |
| +0x361c | float[4] | PitchScale | FUN_004f1510 | 4 floats, stride 0x3e |
| +0x3664 | int | WheelForce[0] | FUN_004f1ba0 | Per-wheel force param |
| +0x3668 | int | ContactID | FUN_004ef180 | Per wheel contact ID (stride 0xf8) |
| +0x3684/+0x368c | float | SuspensionVelocity_L/R | FUN_004e8010 | |
| +0x36a8 | float | LateralForce2 | FUN_004ed810 | |
| +0x36d0 | float | WheelCoeffs[1] | FUN_004ed810 | |
| +0x36d4 | float | WheelForceCopy[0] | FUN_004ed810 | |
| +0x3708/+0x377c/+0x3784 | float | SuspensionDeflectionVelocity_Rear | FUN_004e8010 | |
| +0x375c | int | WheelForce[1] | FUN_004f1ba0 | |
| +0x3770+0x90 | float | FrontAxleRef | FUN_004e9300 | Front axle parameter |
| +0x37a0 | float | LateralForce3 | FUN_004ed810 | |
| +0x37c8 | float | WheelCoeffs[2] | FUN_004ed810 | |
| +0x37cc | float | WheelForcePrev2[0] | FUN_004ed810 | |
| +0x3800/+0x3874/+0x387c | float | SpringForceRear | FUN_004e8010 | |
| +0x3854 | int | WheelForce[2] | FUN_004f1ba0 | |
| +0x3898 | float | LateralForce4 | FUN_004ed810, FUN_004f1ba0 | |
| +0x38c0 | float | WheelCoeffs[3] | FUN_004ed810 | |
| +0x38c4 | float | WheelForceCopy2[0] | FUN_004ed810 | |
| +0x38f8 | float | AntiRollBarForceFront | FUN_004e8010 | |
| +0x394c | int | WheelForce[3] | FUN_004f1ba0 | |
| +0x3978 | float | LocalValue / EffectParam3 | FUN_004f1890, FUN_004f17a0, FUN_004ef930 | Scaled value |
| +0x397c | float | EffectScale | FUN_004f17a0 | Multiplier |
| +0x3984 | float | GlobalJitterScale | FUN_004f1510 | |
| +0x3990 | float | CurrentSpeed | FUN_004e5080, FUN_004ef930 | |
| +0x3994 | float | TargetSpeed / CurrentValue / SpeedOffset | FUN_004e5080, FUN_004ee230, FUN_004e513e, FUN_004ef930 | Current RPM/load |
| +0x3998 | float | ForceThreshold / MaxValue | FUN_004e9300, FUN_004ee230, FUN_004ef930 | Comparison/maximum |
| +0x399c | float | (unnamed) | FUN_004ef930 | |
| +0x39a4 | ptr | JitterBuffer0 | FUN_004f1510 | RNG-adjusted pointer |
| +0x39a8 | float | Friction | FUN_004e87e0 | Friction component |
| +0x39ac | float | CaliperTemp | FUN_004e87e0 | |
| +0x39b0 | ptr | JitterBuffer0Len | FUN_004f1510 | |
| +0x39b4 | int | AxleType / BrakeTCMode | FUN_004e9300, FUN_004e8010 | 0=off, 1=TC, 2=other, 2=rear |
| +0x39c8 | float | BrakeTemp | FUN_004e87e0 | Brake rotor temp |
| +0x39d0 | float | SpeedRatio | FUN_004e9300 | Velocity scaling |
| +0x39ec | byte | BrakeEnabled / Trigger | FUN_004e5080, FUN_004ef930 | |
| +0x39ee | byte | Disable | FUN_004ef930 | |
| +0x39f0 | int/float | OutputTimer / Counter | FUN_004e5080, FUN_004ef930 | |
| +0x39f8 | int | TireStateFlag / JitterBuffer1Len | FUN_004e9300, FUN_004f1510 | Grip model selector |
| +0x39fc | float | HighTarget / SessionSubType | FUN_004ef930, FUN_004c0cc0 | |
| +0x3a00 | float | LowTarget | FUN_004ef930 | |
| +0x3a04 | float | BrakeTimer / Current | FUN_004e5080, FUN_004ef930 | Counts down |
| +0x3a08 | int | BrakeState / State | FUN_004e5080, FUN_004ef930 | 1=releasing |
| +0x3a30/+0x3a44 | float | TireRoadFrictionMu | FUN_004e8010 | Front/rear pair |
| +0x3a38–+0x3a54 | float[4] | TuningCoeffs | FUN_004ed810 | Force multipliers per wheel |
| +0x3a3c–+0x3a50 | float[4] | DampingCoeffs | FUN_004ed810 | Damping factors |
| +0x3a58/5c/60 | float[3] | AirSpeedComps | FUN_004e87e0 | Airflow velocity |
| +0x3a6c | float | CurrentValue / CamberRelaxation | FUN_004ed0f0, FUN_004e8010 | Accumulator / camber |
| +0x3a70 | float | StiffnessTerm / SelectedValue / DragCoeffA / SpringCoeff | FUN_004e9100, FUN_004e9300, FUN_004e8b80, FUN_004ed0f0, FUN_004ed030 | Base stiffness/drag/spring |
| +0x3a78 | float | TargetValue / BaseThreshold | FUN_004ed030, FUN_004ed0f0 | |
| +0x3a7c | float | ValueOptionA | FUN_004ed030 | |
| +0x3a80 | float | ValueOptionB / ResetDecay | FUN_004ed030, FUN_004ed0f0 | |
| +0x3a9c | ptr | ReplayStatePtr / CurrentID | FUN_004f1c20, FUN_004e9630 | Replay/object ID |
| +0x3aa0 | float | CurrentPosX | FUN_004e9630 | |
| +0x3aa4 | float | CurrentPosY | FUN_004e9630 | |
| +0x3aa8 | float | CurrentPosZ | FUN_004e9630 | |
| +0x3b54 | float[3] | InputVector | FUN_004e9bd0 | Input to transform |
| +0x3b60 | float[3] | OutputVector / ContactVel | FUN_004e9bd0, FUN_004e9980 | Transformed result / contact velocity |
| +0x3b64 | float | ContactVelY | FUN_004e9980 | |
| +0x3b68 | float | ContactVelZ | FUN_004e9980 | |
| +0x3b6c | float | MinSlipSpeed | FUN_004e9980 | Clamp threshold |
| +0x3b78 | byte | ContactFlag0 | FUN_004ef560 | Per-wheel contact |
| +0x3b79 | byte | ContactFlag1 | FUN_004ef560 | Per-wheel contact |
| +0x3b88 | float | ContactPosX | FUN_004ef560 | |
| +0x3b8c | float | ContactPosY | FUN_004ef560 | |
| +0x3b90 | float | ContactPosZ | FUN_004ef560 | |
| +0x3bf4 | float | CurrentPlaybackSpeed / Unknown | FUN_004f1510, FUN_004e8010 | Inverse for wet scaling |
| +0x3bfc | float[14] | TableIndexB / TireStiffness | FUN_004e9100, FUN_004e8010, FUN_004e8b80 | Second lookup table / area coeff |
| +0x3c00 | float[14] | TableValueB / TableBase | FUN_004e9100, FUN_004e8010, FUN_004e8b80 | Values for second table |
| +0x3c04 | float[14] | TableValueB_Next | FUN_004e9100 | Next entry for interpolation |
| +0x3c3c | float[14] | SlipTableLow / LowGripTable | FUN_004e9100, FUN_004e9300 | Low regime table, stride 0x40 |
| +0x3c40 | float[14] | SlipTableLow_Val | FUN_004e9100 | Low regime values |
| +0x3c44 | float[14] | SlipTableLow_Next | FUN_004e9100 | |
| +0x3c7c | float[14] | SlipTableHigh / HighGripTable | FUN_004e9100, FUN_004e9300 | High regime table |
| +0x3c80 | float[14] | SlipTableHigh_Val | FUN_004e9100 | |
| +0x3c84 | float[14] | SlipTableHigh_Next | FUN_004e9100 | |
| +0x3cbc | float | TireStiffness[3] | FUN_004e8010 | |
| +0x3cfc | float | CombinedStiffnessFactor | FUN_004e8010 | |
| +0x3d00–+0x3d3b | float[15] | SolvedSlipRatios | FUN_004e8010 | |
| +0x3d3c | float | MaxClamp / MaxForce / TotalForceOutput | FUN_004e9100, FUN_004e8b80, FUN_004e8010 | Output clamp upper |
| +0x3d40 | float | AreaCoeff / AntiRollContribution | FUN_004e87e0, FUN_004e8010 | Brake area / anti-roll |
| +0x3d44 | float | OutputBiasScale / LinearDragCoeff / AligningMoment | FUN_004e9100, FUN_004e8b80, FUN_004e8010 | Bias/aligning moment |
| +0x3d48 | float | DefaultOutput1 | FUN_004ee230 | |
| +0x3d4c | float | DefaultOutput2 | FUN_004ee230 | |
| +0x3d50 | float | DefaultOutput3 | FUN_004ee230 | |
| +0x3d60 | int | StateFlag | FUN_004ed030, FUN_004ed0f0 | |
| +0x3d40/44 | float | Area/Coeff | FUN_004e87e0 | Brake area and coefficient |
| +0x4024 | float | DownforceMultiplier | FUN_004e8010 | |
| +0x403c | int | SeasonPoints | FUN_004c0cc0, FUN_0049f870 | |
| +0x4044 | float | PenaltyFloat | FUN_004c0cc0 | |
| +0x4058 | int | QualifyingPosition | multiple | |
| +0x405c | float | QualifyingTime | multiple | |
| +0x4060 | int | FinishPosition | FUN_004c0cc0, FUN_0049f870, FUN_004a0ba0 | 1=winner |
| +0x4064 | int | FinishState | FUN_004c0cc0 | 0=running,1=finished,2=DNF,3=DSQ |
| +0x4068 | int | ReasonCode | FUN_004c0cc0 | Retirement reason |
| +0x409c | float | BestLapTime | multiple | |
| +0x4354 | int | AIStateFlags | FUN_0042add0, FUN_0042ae00 | AI state flags (80 bytes) |
| +0x44a8 | ptr | SubsystemPtr | FUN_00424010 | Allocated subsystem |
| +0x4500 | float | PassScoreBiasAdd | FUN_0042a780 | AI passing score |
| +0x4504 | float | PassScoreBiasMult | FUN_0042a780 | |
| +0x4538 | float | Parameter | FUN_0042acd0 | Vehicle/driver parameter |
| +0x453c | float | TrackCorneringFactor / OutputForce | FUN_0042a780, FUN_0042ad00 | |
| +0x454c | int | AISpeedDelta / AIFlag | FUN_0042aca0, FUN_0042ac70 | AI speed delta / state flag |
| +0x4550 | int | AITargetParam | FUN_0042add0 | |
| +0x4580 | float | AggressionFactor | FUN_0042a780 | |
| +0x44f4 | float | ForceCoefficient | FUN_0042ad00 | Lateral force calc |
| +0x4588 | int | StateCountIndex | FUN_0042ae90 | State/count index |
| +0x4590 | uint[] | StateTable | FUN_0042ae90 | Table at stride 0x10 |
| +0x45f4 | byte | NeedsUpdateFlag / AIControlFlag | FUN_0042adb0, FUN_0042af40 | |
| +0x45f8 | int | LastSelection | FUN_0042ae20 | AI driver random selector |
| +0x45fc | int | CurrentSelection | FUN_0042ae20 | AI drivers count |
| +0x4620 | char[64] | DriverName | FUN_004c6980, FUN_004c0cc0, FUN_004b5120, FUN_004c79e0 | Wide string |
| +0x4678 | char[] | VehicleDescription | FUN_004c79e0 | |
| +0x46f8 | char[] | DriverNameAlt | FUN_004c0cc0 | Driver name string |
| +0x4708 | char[7] | NameBuffer | FUN_004c69b0 | Short name |
| +0x470f | byte | NullTerminator | FUN_004c69b0 | Always 0 |
| +0x4710 | uint | NameHash / DriverNameAbbrev | FUN_004c69b0, FUN_004c0cc0 | Computed hash |
| +0x4714 | char[] | FilePath / PathBuffer | FUN_004c69e0, FUN_004b5120 | Path string |
| +0x4894 | int | TeamID | FUN_004c6920, FUN_004c0cc0, FUN_004c77d0, FUN_004ec080, FUN_004c6960 | -1=unassigned |
| +0x4898 | int | UnknownID1 | FUN_004c79e0 | -1=unset |
| +0x489c | int | DriverNumber | FUN_004c79e0, FUN_004c0cc0 | -1=unset |
| +0x48a0 | int | UnknownID2 | FUN_004c79e0 | -1=unset |
| +0x48a4 | int | ResourceID / UnknownID3 | FUN_004d1100, FUN_004d1140, FUN_004c79e0 | Handle/resource ID |
| +0x48a8 | int | ResourceSubID / UnknownID4 | FUN_004d1140, FUN_004c79e0 | |
| +0x48ac | int | UnknownFlag | FUN_004c79e0 | 0 |
| +0x48b0 | short | UnknownShort | FUN_004c79e0 | 0 |
| +0x48b4 | float | BestLapTimeReset | FUN_004c79e0, FUN_004c6d90 | -FLT_MAX |
| +0x48b8 | float/int | TireTemp / UnknownTime | FUN_004c77d0, FUN_004c79e0 | |
| +0x48bc | int | AIControlFlags / FinishState | FUN_004c7a70, FUN_004c79e0 | Bit 0=AI enable |
| +0x4fc | float | LapTimeDelta | FUN_004c0cc0 | |
| +0x69c | float | OvertakeGap | FUN_004c0cc0 | |
| +0x77c | float | Output1 | FUN_004ee230 | Throttle/brake output |
| +0x790 | float | Output2 | FUN_004ee230 | |
| +0x7a4 | float | Output3 | FUN_004ee230 | |
| +0x828 | int[4] | ElementFlags | FUN_004ed420 | Per-element flags, stride 0x128 |
| +0x82c | float[3] | WheelPosLocal | FUN_004ef180 | Per wheel, stride 0x128 |
| +0x83c | float | OvertakeTarget | FUN_004c0cc0 | |
| +0x8cc | float[4] | ClampedOutput | FUN_004ed810 | Final clamped force |
| +0x8e8 | float | VecInX | FUN_004e1fd0 | Input vector X |
| +0x8ec | float | VecInY | FUN_004e1fd0 | |
| +0x8f0 | float | VecInZ | FUN_004e1fd0 | |
| +0x8f4 | float[3] | LocalOffset1 | FUN_004e2070 | First offset component |
| +0x900 | float[3] | LocalOffset2 | FUN_004e2070 | |
| +0x90c | ptr | OutputBuffer | FUN_004e2070 | Passed to transform |
| +0x918 | float[3] | LocalOffset | FUN_004e2130 | Local-space offset |
| +0x934 | int | CellCounter / RenderCounter | FUN_004be340, FUN_004be4e0 | Incrementing counter |
| +0x144 + i*0x128 | int | WheelActive[i] | FUN_004e17c0 | Wheel activation flag |
| +0x184 + i*0x128 | char | WheelReady[i] | FUN_004e17c0 | Wheel ready flag |
| +0x5e4 | int | SystemA | FUN_004e17c0 | Dedicated system |
| +0x628 | int | SystemB | FUN_004e17c0 | Dedicated system |
| +0x66c + i*0x44 | int | Subsystem[i] | FUN_004e17c0 | 8 subsystems |
| +0x4c | float | RestHeight | FUN_004e24a0 | Suspension rest position |
| +0xcc | int | WheelID | FUN_004e24a0 | |
| +0xd4 | struct[4] | SuspArray | FUN_004e24a0 | Per-wheel suspension, stride 0x128 |
| +0x1cc | float | SpringBias | FUN_004e24a0 | |
| +0x200 | float | PrevForce | FUN_004e24a0 | |

**Cross-file consistency:** Offsets +0x3500–+0x3d44 appear consistently across ~15 physics functions. Vehicle strut 0x4620 (DriverName) used by FUN_004c6980 and FUN_004c79e0. Offsets +0x1130/+0x1132 NOT in this struct (DirectX false positive, no D3D calls in these functions).

---

## ReplaySaveStruct (param_1 — replay context)

Based on 2 function observations (FUN_004b7500 replay save, FUN_004ba1f0 replay load). Confidence: **high**.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x6c0 | ptr | ListHead | FUN_004b81a0, FUN_004b84f0, FUN_004b85d0, FUN_004bbfc0 | Sorted linked list anchor |
| +0x6c4 | ptr | ListTail | FUN_004b81a0, FUN_004b84f0, FUN_004b85d0, FUN_004b8360 | Linked list tail |
| +0x6c8 | ptr | ListCursor / CurrentNode | FUN_004b81a0, FUN_004b84f0, FUN_004b85d0, FUN_004b8360 | Iterator position |
| +0x6cc | int | ListCount / ItemCount | FUN_004b81a0, FUN_004b84f0, FUN_004b85d0, FUN_004b8360 | Element count |
| +0x6d0 | byte | SortedFlag / DirtyFlag | FUN_004b81a0, FUN_004b7500, FUN_004b8360 | 1=sorted, set to 1 on change |
| +0x6d4 | ptr | LinkedListHead0 | FUN_004b5a30 | Linked list of widgets |
| +0x6e4 | int | ReplayDataPresent | FUN_004b7500 | Flag |
| +0x6e8 | int | HeaderDataSource | FUN_004b7500 | |
| +0x700 | int | SaveState | FUN_004b7500 | 0/1 |
| +0x704 | ptr | InputDataSource / ComponentPtr4 | FUN_004b7500, FUN_004b5a30 | |
| +0x70c | char[] | TrackName / ComponentPtr3 | FUN_004b7500, FUN_004b5a30 | File path base |
| +0x714 | ptr | EntryLinkedListHead | FUN_004b7500, FUN_004b7c80, FUN_004b5f60 | Linked list anchor |
| +0x718 | ptr | EntryLinkedListTail | FUN_004b7500, FUN_004b7c80, FUN_004b5f60 | |
| +0x71c | ptr | TraversalCursor | FUN_004b7500, FUN_004b7c80, FUN_004b5f60 | |
| +0x720 | int | LinkedListCount | FUN_004b5f60 | |
| +0x724 | ptr | ComponentPtr2 | FUN_004b5a30 | Freed object |
| +0x72c | ptr | ComponentPtr1 | FUN_004b5a30 | Freed object |
| +0x9a4 | int | SubfolderIndex | FUN_004b7500 | 0–4 |
| +0xf30 | float | LapTimeStart / MinValue | FUN_004b7500, FUN_004b86e0 | Session timing |
| +0xf34 | float | LapTimeEnd / MaxValue | FUN_004b7500, FUN_004b86e0 | |
| +0xf38 | float | Value/Threshold/ScoreValue | FUN_004b81a0, FUN_004b84f0, FUN_004b85d0, FUN_004b8360, FUN_004b8790, FUN_004b86e0 | Sort key / comparison |
| +0xf3c | float | PreviousValue | FUN_004b86e0 | |
| +0xf81 | byte | Mode | FUN_004b86e0 | 0=wrap, non-0=clamp |
| +0xf8c | int | ServiceAnimState | FUN_004b9e40 | Wheel service animation |
| +0xf94 | char[] | OutputFilePath / ComponentPtr0 | FUN_004b7500, FUN_004b5a30 | Output path |

---

## ScoringDB / StandingsEntry (per-driver season data)

Based on 4+ function observations. Confidence: **high**.

Stride 0x1B4 between entries.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | int | CategoryID | FUN_00435390 | -1=unset |
| +0x04 | int | Reserved0 | FUN_00435390 | Zeroed |
| +0x10 | float | Weight | FUN_00435390 | ~1.875 |
| +0x18 | int[48] | FINISHPOSITION | FUN_004c03f0, FUN_004c07f0 | Max 48 races |
| +0xd8 | int[48] | FINISHPOINTS | FUN_004c03f0, FUN_004c07f0 | Points per race |
| +0x198 | int | SEASONPOINTS | FUN_004c03f0, FUN_004c0f60 | AccumulatorA |
| +0x19c | int | POINTSPOSITION | FUN_004c03f0 | AccumulatorB |
| +0x1a0 | int | POLESTAKEN | FUN_004c03f0 | AccumulatorC |
| +0x1a4 | int | ORIGINALGRIDPOSITION | FUN_004c03f0 | Reserved |
| +0x1a8 | int | CURRENTGRIDPOSITION | FUN_004c03f0 | Sentinel -1 |
| +0x1ac | int | CONTROLTYPE | FUN_004c03f0 | Sentinel -1 |
| +0x1b0 | byte | ACTIVE | FUN_004c03f0, FUN_004c0f60, FUN_004c1370 | Bool, stride 0x1b4 |
| +0xb108 | int | RankEntry0 | FUN_004c0f60 | Rank count |
| +0xb120 | ptr | PitAllocA | FUN_004c0b10 | Freed on cleanup |
| +0xb128 | ptr | PitAllocB | FUN_004c0b10 | Freed on cleanup |
| +0xb144 | int | SeasonStatus | FUN_004c03f0 | |
| +0xb148 | int | CurrentRace / UnknownFlags | FUN_004c03f0, FUN_004c11d0 | |
| +0xb14c | int | RaceSession / SessionType / TireWearValue | FUN_004c03f0, FUN_004c0f60, FUN_004c11c0, FUN_004c15a0 | Compared to 7 (race) |
| +0xb150 | byte | RaceOver / RankingsDirtyFlag / PitPhaseSubStep | FUN_004c03f0, FUN_004c0f60, FUN_004c15a0 | 0=needs compute |

---

## OpponentStateStruct (param_2 — opponent/driver in overtaking)

Based on FUN_0042a780 (AI pass score) and FUN_004c0cc0. Confidence: **medium**.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x70 | float | OpponentSpeed | FUN_0042a780 | |
| +0x74 | float | OpponentDistance | FUN_0042a780 | |
| +0x78 | float | OpponentPosition | FUN_0042a780 | |
| +0x84 | float | OpponentSpeedDelta | FUN_0042a780 | |
| +0x4fc | float | LapTimeDelta | FUN_004c0cc0 | |
| +0x69c | float | OvertakeGap | FUN_004c0cc0 | |
| +0x83c | float | OvertakeTarget | FUN_004c0cc0 | |

---

## VibrationEffectController (param_1/unaff_ESI — controller)

Based on FUN_00545d00 and FUN_005169ac. Confidence: **high**.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x10 | int | activeFlag | FUN_00545d00 | Master enable |
| +0x14 | int | state | FUN_00545d00, FUN_005169ac | State ID |
| +0x16 | int | active | FUN_00545d00 | Active flag |
| +0x19 | byte | mode | FUN_00545d00 | Mode (3=triggered) |
| +0x1d | byte | subState | FUN_00545d00 | Sub-state for mode 3 |
| +0x20 | int | ModeA | FUN_005169ac | Must be 3 |
| +0x24 | int | ModeB | FUN_005169ac | Must be 3 |
| +0x28 | int | ModeC | FUN_005169ac | Must be 2 |
| +0x32 | byte | altMode | FUN_00545d00 | Alternative mode flag |
| +0x41 | byte | processingFlag | FUN_00545d00 | Processing path selector |
| +0x46 | byte | durationMultiplier | FUN_00545d00 | Scales effect duration |
| +0x48 | byte | FlagA | FUN_005169ac | Must be 0 |
| +0x4a | byte | globalEnable | FUN_00545d00 | Master enable byte |
| +0x59 | byte | flagRight | FUN_00545d00 | Right-side trigger |
| +0x5a | byte | flagLeft | FUN_00545d00 | Left-side trigger |
| +0x64 | int | ModeD | FUN_005169ac | Must be 3 |
| +0x69 | byte | intensity | FUN_00545d00 | Effect intensity |
| +0xc4 | ptr | SubStructPtr | FUN_005169ac | Pointer to sub-struct |
| +0xc9 | byte | extendedFlag | FUN_00545d00 | Extended processing flag |
| +0x108 | byte | FlagB | FUN_005169ac | Must be 0 |
| +0x114 | int | MatchID | FUN_005169ac | Cross-check value |

---

## Texture/VertexDecoder (param_1 — texture context)

Shared decoder struct. Offsets in 0x1000–0x10xx range. Used by ~12 functions.
Confidence: **high**.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x10 | int | PostProcessFlag | FUN_00509e85, FUN_0050a34b, FUN_00509644 | Enables post-processing |
| +0x18 | int | PixelDataStart / BaseIndex | FUN_00509e85, FUN_00509de6, FUN_005086dd, FUN_0050a34b, FUN_00509644 | Base offset / index |
| +0x2c | ptr | ColorTableBase / PaletteArrayPtr / SourceDataPtr | FUN_00508c22, FUN_0050930b, FUN_005078b5, FUN_00508d2d, FUN_00507bc5, FUN_005084f5, FUN_005082d1, FUN_005085c5, FUN_00508b1d | Float[4] palette entries |
| +0x38 | float[4]×256 | ReferenceVerts / ReferenceArray | FUN_005086dd, FUN_005085c5 | 256×4 floats |
| +0x60 | uint | RenderFlags | FUN_0051378b | Checked against 0x602000 |
| +0x104 | ptr | PixelDataPtr | FUN_0051378b | RGB pixel data |
| +0x108 | ushort | PixelCount | FUN_0051378b | |
| +0x116 | byte | ColorDepthMode | FUN_0051378b | 3=triggers processing |
| +0x138 | int | ColorOffset | FUN_0051378b | Additive offset per channel |
| +0x150 | byte | ShiftR | FUN_0051378b | Clamped 0–8 |
| +0x151 | byte | ShiftG | FUN_0051378b | |
| +0x152 | byte | ShiftB | FUN_0051378b | |
| +0x1034 | int | OffsetA | FUN_0050aeae | Row offset |
| +0x1040 | int | OffsetB | FUN_0050aeae | Column offset |
| +0x1048 | int | TransformFlag / DataTransformFlag / EncryptedFlag | FUN_00508c22, FUN_0050930b, FUN_005078b5, FUN_00508d2d, FUN_00507bc5, FUN_005084f5, FUN_005082d1, FUN_005086dd, FUN_0050aeae, FUN_005085c5, FUN_00508b1d, FUN_005093f9 | Non-zero = apply matrix |
| +0x1050 | int | TexStrideX / StrideX / InputStride / WidthFactor | FUN_00509e85, FUN_00509de6, FUN_0050a223, FUN_0050a92d, FUN_0050a34b, FUN_005086dd, FUN_00509644 | Texture/vertex width stride |
| +0x1054 | int | TexStrideY / StrideY / OutputStride / HeightFactor | FUN_00509e85, FUN_00509de6, FUN_0050a223, FUN_0050a92d, FUN_0050a34b, FUN_005086dd, FUN_00509644 | Texture/vertex height stride |
| +0x1058 | int | PixelCount / VertexCount / EntryCount | FUN_00509e85, FUN_00509de6, FUN_00508c22, FUN_0050930b, FUN_005078b5, FUN_0050a223, FUN_0050a34b, FUN_00508d2d, FUN_00507bc5, FUN_005084f5, FUN_005082d1, FUN_005086dd, FUN_0050aeae, FUN_005093f9, FUN_005085c5, FUN_00508b1d, FUN_00509644, FUN_00507845 | Number of pixels/vertices |
| +0x106c | float[8] | InputVertexArray / DestBuffer | FUN_0050a92d, FUN_0050aeae, FUN_0050b27c | Per-vertex input |
| +0x1070 | int | CurrentIndex / RowPitch / Scale | FUN_0050a92d, FUN_0050aeae, FUN_0050b27c | Vertex index / row pitch |
| +0x1078 | int | VertexCount | FUN_0050a92d | Total vertices |
| +0x1080 | int | OutputRowStride | FUN_0050a92d | |
| +0x108c | ptr/int | InputBuffer / CopyCompleteFlag | FUN_0050a92d, FUN_0050aeae | Dirty flag / flag |
| +0x1090 | ptr | OutputBuffer | FUN_0050a92d | Output buffer |
| +0x1094 | int | ChannelBitShift0 | FUN_0050a92d | Bit shift for channel 0/2 |
| +0x1098 | int | ChannelBitShift1 | FUN_0050a92d | Bit shift for channel 1/3 |

---

## SceneNode / DrawableList (param_1 — scene graph node)

Based on 5+ functions. Confidence: **high**.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | int | ActiveFlag | FUN_00545d00, FUN_00512322 | -1 = inactive |
| +0x0c | int | param_1[3] | FUN_0040f130 | Data passed to dispatch |
| +0x1c | int | param_1[7] | FUN_0040f130 | State selector (0-5) |
| +0x04 | uint | CullFlags | FUN_0054a0a0 | 1=inside, 2=outside, 4=partial |
| +0x0c | int | LastAppended | FUN_00545d00 | Node list node |
| +0x10 | int | Count | FUN_00545d00 | List count |
| +0x14 | uint | Flags / CullFlags | FUN_0054d030, FUN_0054d910 | Bit 0x8000000=children dirty |
| +0x18 | float | NearPlaneDist | FUN_00549fb0 | Frustum near plane |
| +0x20 | int | TypeTag | FUN_00545d00 | 6=vehicle/player |
| +0x24–0x2c | float[3] | BoxVertices / SphereOffset | FUN_0054a0a0, FUN_00549fb0 | AABB / sphere |
| +0x3c | int | SomeFlag | FUN_00545d00 | 0=init |
| +0x40 | ptr | ParentPtr | FUN_0054b770 | Parent transform/container |
| +0x50 | int | TypeTag | FUN_00545d00 | 6=vehicle/player object type |
| +0x7c–0x84 | float[3] | FrustumPosition | FUN_00549fb0 | Camera/frustum world pos |
| +0x94 | ptr | AltTransformDest | FUN_0054b770 | Used with bit0 flag |
| +0xd4 | float[16] | LocalMatrix | FUN_0054b770 | 4×4 matrix |
| +0xfc | int | ElementCount | FUN_0054d910 | Elements to test |
| +0x100 | ptr | NodeChainHead / HeadPtr | FUN_005453a0, FUN_0054a2d0 | Linked list pointer |
| +0x104 | float[4]×6 | FrustumPlanes | FUN_00549fb0 | 6 planes (a,b,c,d) |
| +0x108 | ptr | DefaultNode | FUN_005453a0 | Fallback node |
| +0x114 | float[16] | WorldMatrix | FUN_0054b770 | Computed 4×4 |
| +0x118 | int | ChildCount / RecordCount | FUN_0054d030, FUN_0054e100, FUN_0054e120, FUN_00519986 | Number of children/records |
| +0x11c | ptr | ChildArrayPtr / RecordArrayPtr | FUN_0054d030, FUN_0054e100, FUN_0054e120 | Stride 0x40 |
| +0x120 | int | FrameCount / ObjectCount | FUN_00519986, FUN_0054e080 | |
| +0x124 | ptr | FrameArray / ObjectArrayPtr | FUN_00519986, FUN_0054e080 | Array of frame/object data |
| +0x194 | float | ScaleX | FUN_0054b770 | Row0 multiplier |
| +0x198 | float | ScaleY | FUN_0054b770 | Row1 multiplier |
| +0x19C | float | ScaleZ | FUN_0054b770 | Row2 multiplier |
| +0x1A0 | float[16] | OutputMatrix | FUN_0054b770 | Result 4×4 |
| +0x204 | ptr | AnimNodeListHead / ListHead | FUN_0054bf60, FUN_0054ac30, FUN_0054abe0 | Anim node/anchor |

---

## AudioStreamBuffer (param_1 — audio stream)

Based on FUN_00519720, FUN_0051bd61, FUN_0051bcfc. Confidence: **high**.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x030 | byte | ReadyFlag | FUN_00519720 | 0=needs init, 1=ready |
| +0x034 | uint | Position | FUN_00519720 | Current read position |
| +0x038 | ptr | SourcePointer | FUN_00519720 | Varies by buffer index |
| +0x040 | uint | BufferIndex | FUN_00519720 | Double-buffer toggle (xor 1) |
| +0x044 | int | FillState | FUN_00519720 | 0=idle, 1=filling, 2=switch |
| +0x048 | uint | BufferSize | FUN_00519720 | |
| +0x04c | int | BufferCounter | FUN_00519720 | Completed fills |
| +0x114 | int | BufferSizeBase | FUN_00519720 | Size reference |
| +0x118 | int | TotalBuffers | FUN_00519720 | |
| +0x180 | ptr | StreamPtr | FUN_00519720 | Stream state |
| +0x184 | ptr | VtableDecoder / VTablePtrA | FUN_00519720, FUN_0051bcfc, FUN_00515db8 | Method +0xc=data available |
| +0x188 | ptr | VtableFiller / BufferObj / RenderContext | FUN_00519720, FUN_0051bd61, FUN_0051bcfc | Method +4=buffer fill |
| +0x19c | ptr | PlayCallback / WriteVtable | FUN_0051bd61, FUN_0051bcfc | Vtable for playback/write |
| +0x1a4 | ptr | FlushCallback / FlushVtable | FUN_0051bd61, FUN_0051bcfc | Vtable for flush |

---

## CameraStruct (param_1 — camera/projection)

Based on FUN_00541b70, FUN_00545670, FUN_0054e190. Confidence: **medium**.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x004 | float | NearPlane | FUN_00541b70 | |
| +0x008 | float | FarPlane | FUN_00541b70 | |
| +0x01c | float | FocalX | FUN_00541b70 | |
| +0x020 | float | FocalY | FUN_00541b70 | |
| +0x080 | byte | Flags | FUN_00541b70 | Bit 0x10=mirror |
| +0x11c | float | CameraPosX | FUN_00545670 | |
| +0x120 | float | CameraDistance | FUN_0054e190 | |
| +0x124 | float | CameraPosY | FUN_00545670 | |
| +0x15c | float[16] | ViewMatrix | FUN_00541b70 | 4×4 matrix |
| +0x18c | ptr | CameraObjPtr | FUN_00515ecd | Allocated director camera |

---

## TireForceQuadraticModel (param_1 — per-tire force model)

Based on FUN_004f6950 and FUN_004f68b0. Confidence: **high**.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x1ec | char | TireActive | FUN_004f68b0 | |
| +0x1f8 | double | ForceConst1 | FUN_004f68b0 | |
| +0x200 | double | ForceLinCoeff | FUN_004f68b0 | |
| +0x208 | double | ForceQuadCoeff | FUN_004f68b0 | |
| +0x210 | double | ForceConst2 | FUN_004f68b0 | |
| +0x218 | double | TorqueLinCoeff | FUN_004f68b0 | |
| +0x220 | double | TorqueQuadCoeff | FUN_004f68b0 | |
| +0x228 | double | TorqueCamberCoeff | FUN_004f68b0 | |
| +0x250 | double | LatForcePeak | FUN_004f68b0 | |
| +0x288 | double | LongForcePeak | FUN_004f68b0 | |
| +0x2e8 | double | CamberAngle | FUN_004f68b0 | |
| +0x2f8 | byte | ModelEnabledFlag | FUN_004f6950 | |
| +0x2fc | double | QuadraticC | FUN_004f6950 | Constant term |
| +0x304 | double | QuadraticA | FUN_004f6950 | Linear term |
| +0x30c | double | QuadraticB | FUN_004f6950 | Quadratic term |
| +0x314 | double | OutputQuadC | FUN_004f6950 | Output constant |
| +0x31c | double | OutputQuadA | FUN_004f6950 | Output linear |
| +0x324 | double | OutputQuadB | FUN_004f6950 | Output quadratic |
| +0x34c | double | AbsOutput1 | FUN_004f6950 | |
| +0x384 | double | AbsOutput2 | FUN_004f6950 | |

---

## SessionStruct / SessionTimers (param_1 — session struct)

Based on FUN_004d0f10 and FUN_00411120, FUN_004a5e10. Confidence: **high**.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x14 | int | ActiveFlag | FUN_004a5e60, FUN_004a5e80 | Non-zero = active |
| +0x24 | int | Count1 | FUN_00411120 | Stride 0x24 group 1 |
| +0x30 | int | Count2 | FUN_00411120 | |
| +0x3c | int | Count3 | FUN_00411120 | |
| +0x44 | ptr | ListHead | FUN_0046ae60 | Session entries list |
| +0x48 | int | Count | FUN_0046ae60 | |
| +0x4c | int | Count | FUN_0046ae60 | |
| +0x50 | int | Count | FUN_0046ae60 | |
| +0x54 | int | Count4 | FUN_00411120 | |
| +0x60 | int | Count5 | FUN_00411120 | |
| +0xac | int | BestTime | FUN_004d0f10 | 0x7fffffff = DNF |
| +0xb8 | float | MaxSessionTime | FUN_004d0f10 | 7200.0 (2 hours) |
| +0xbc | float | TimeMultiplier | FUN_004d0f10 | 1.0 |
| +0x128 | int[26] | SectorFlags | FUN_004d0f10 | Initialized to -1 |
| +0x180 | byte | StateFlag / FlagA | FUN_004a5e60, FUN_004a5e80 | |
| +0x184 | int | SessionState / FlagB | FUN_004a5e10, FUN_004a5e60, FUN_004a5e80 | 0=idle, 1=active, 4=finished |
| +0x190 | short | LapCount | FUN_004d0f10 | 0xffff |
| +0x192 | byte | CurrentSector | FUN_004d0f10 | 0xff |
| +0x280 | int[52] | PitWindowHistory | FUN_004d0f10 | Zeroed |

---

## AnimationNode / BoneGroup

Based on FUN_0054bf60 and FUN_004be9e0. Confidence: **medium**.

**Anim node:**
| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x10 | ptr | NextNode | FUN_0054bf60 | Linked list next |
| +0x118 | int | BoneGroupCount | FUN_0054bf60 | |
| +0x11c | ptr | BoneGroupArray | FUN_0054bf60 | |

**Bone group:**
| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | int | GroupID | FUN_0054bf60 | Matches param_2 |
| +0x04 | int | BoneCount | FUN_0054bf60 | |
| +0x08 | ptr | BoneDataArray | FUN_0054bf60 | Bone transforms |
| +0x30 | int | DirtyFlags | FUN_0054bf60 | Bitmask |

**Animation state:**
| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x340 | byte | AnimFlag1 | FUN_004be9e0, FUN_004be700 | Animation state flag |
| +0x341 | byte | AnimFlag2 | FUN_004be9e0, FUN_004be700 | Animation state flag |
| +0x342 | byte | FlagC | FUN_004be700 | 0 |
| +0x344 | int/float | MultiplierA / AnimValue1 | FUN_004be9e0, FUN_004be700 | |
| +0x348 | float | MultiplierB | FUN_004be700 | |
| +0x34C | float | ThresholdRef | FUN_004be700 | From DAT_005ACDAC |
| +0x350 | float | FloatLimit / AnimValue2 | FUN_004be9e0, FUN_004be700 | 10.0 |
| +0x35C | int | IterationCount | FUN_004be700 | 10 |
| +0x360 | int | SubIterationCount | FUN_004be700 | 5 |

---

## PitStop / PitCrewStruct (param_1 — pit state)

Based on FUN_004a5600, FUN_004b6940, FUN_004b5da0, FUN_004a47e0. Confidence: **high**.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x8 | ptr | CurrentPitState | FUN_004a5600 | byte* animation state |
| +0x184 | int | PitMode | FUN_004a5600 | 3=repair |
| +0x190 | byte | RepairDoneFlag | FUN_004a5600 | Blocks transitions |
| +0x9b0 | int | PitActionBase / DataArrayBase | FUN_004b6940, FUN_004b6130, FUN_004b68c0, FUN_004b6920 | Base pointer |
| +0x9b4 | int | PitActionIndex / Capacity | FUN_004b6940, FUN_004b5da0, FUN_004b68c0, FUN_004b69a0 | Index / modulo limit |
| +0x9b8 | int | PitActionCounter / Head | FUN_004b6940, FUN_004b5da0, FUN_004b68c0, FUN_004b69a0, FUN_004b69f0 | Counter / CoordX |
| +0x9bc | int | Tail / CoordY | FUN_004b68c0, FUN_004b69f0 | |

---

## Session/Rankings ScoringGate

Based on FUN_00411440. Confidence: **medium**.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x48 | int | EntryCount | FUN_00411440 | Race entries |
| +0x4c | ptr | EntryRosterPtr | FUN_00411440 | Stride 0x24 |
| +0x50 | byte[] | EntryArray | FUN_00411440 | Stride 0xca |
| +0x54 | int | QualiCount | FUN_00411440 | |
| +0x58 | ptr | QualiRosterPtr | FUN_00411440 | Stride 0x24 |
| +0x5c | byte[] | QualiArray | FUN_00411440 | Stride 0xc6 |
| +0x60 | int | PracticeCount | FUN_00411440 | |
| +0x64 | ptr | PracticeRosterPtr | FUN_00411440 | Stride 0x24 |
| +0x68 | byte[] | PracticeArray | FUN_00411440 | Stride 0xc6 |

---

## SpriteOverlayList (param_1 — display list)

Based on FUN_004b81a0, FUN_004b84f0, FUN_004b85d0, FUN_004b8360, FUN_004b8480. Confidence: **high**.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x6c0 | ptr | ListHead | FUN_004b81a0, FUN_004b84f0, FUN_004b85d0, FUN_004b8360, FUN_004b8480 | Linked list head |
| +0x6c4 | ptr | ListTail | FUN_004b81a0, FUN_004b84f0, FUN_004b85d0, FUN_004b8360, FUN_004b8480 | |
| +0x6c8 | ptr | ListCursor | FUN_004b81a0, FUN_004b84f0, FUN_004b85d0, FUN_004b8360 | |
| +0x6cc | int | ListCount | FUN_004b81a0, FUN_004b84f0, FUN_004b85d0, FUN_004b8360, FUN_004b8480 | |
| +0x6d0 | byte | DirtyFlag/CleanupFlag | FUN_004b81a0, FUN_004b8360, FUN_004b8480 | |
| +0xf38 | float | ScoreValue/Threshold | FUN_004b81a0, FUN_004b84f0, FUN_004b85d0, FUN_004b8360 | Sort key |

---

## AudioSoundInstance (param_1 — sound instance)

Based on FUN_00541810. Confidence: **low** (unusual offset encoding).

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x000 | undefined4 | AudioResult | FUN_00541810 | Stores last op result |
| +0x4f6×4 | int | SoundSystemPtr | FUN_00541810 | Null guard |
| +0x440×4 | int | SoundSystemVtable | FUN_00541810 | |
| +0x557×4 | int | InstanceCount | FUN_00541810 | |
| +0x558×4 | int[] | InstanceIDs | FUN_00541810 | Array of sound IDs |

---

## Linked List Node (generic, multiple layouts)

Multiple linked-list implementations coexist. Common patterns:

**Layout A (offset 0x100):** Used by FUN_0054a2d0, FUN_0054a270
| +0x100 | ptr | HeadPtr | Linked list head |
| +0x104 | ptr | NextPtr | Per-node next pointer |

**Layout B (offset +0x204 head):** Used by FUN_0054abe0, FUN_0054ac30
| +0x204 | ptr | ListHead | Linked list head |
| +0x10 | ptr | NextNode | Next pointer |
| +0x140 | ptr | PrevNode | Previous pointer |

**Layout C (offset +0x1ac parent):** Used by FUN_005419d0
| +0x1ac | ptr | ParentPtr | Parent node |
| +0x1b0 | ptr | ListHead | Child list head |
| +0x1b4 | ptr | PrevPtr | Previous sibling |
| +0x1b8 | ptr | NextPtr | Next sibling |

**Layout D (offset +0x1e4):** Used by FUN_0053c5d0
| +0x1e4 | ptr | PrevPtr | Previous node |
| +0x1e8 | ptr | NextPtr | Next node |

**Layout E (offset +0xf8 list):** Used by FUN_00545090
| +0xf8 | ptr | ListHead | List anchor |
| +0x1b4 | ptr | Prev | Previous node (param_2) |
| +0x1b8 | ptr | Next | Next node (param_2) |

---

## BitStreamWriter (param_1 — bit stream encoder)

Based on FUN_00539690, FUN_00537f30, FUN_00539720. Confidence: **high**.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x008 | byte* | OutputBufferPtr | FUN_00537f30, FUN_00539720 | Destination buffer |
| +0x014 | int | BufferPosition / WritePosition | FUN_00539690, FUN_00537f30, FUN_00539720 | Current write offset |
| +0x16ab | ushort | BitAccumLow / BitAccumulator / CharBuffer[0] | FUN_00539690, FUN_00537f30, FUN_00539720 | Pending bits / char byte |
| +0x16ac | byte | BitAccumHigh / CharBuffer[1] | FUN_00539690, FUN_00537f30, FUN_00539720 | Pending high bits |
| +0x16ad | int | BitCount / BitsRemaining / Accumulator | FUN_00539690, FUN_00537f30, FUN_00539720 | Valid bits count |

---

## PenaltySlipAngleStruct

Based on FUN_0042e400. Confidence: **medium**.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x1cb8 | byte | Flag | FUN_0042e400 | Enabled flag |
| +0x1cbc | float | SpeedThreshold | FUN_0042e400 | 295.0, penalty trigger |
| +0x1cd4 | byte[4] | CornerFlags | FUN_0042e400 | Per corner |
| +0x1cd8 | float[4] | CornerThresholds | FUN_0042e400 | Per corner |
| +0x1cec | float[4][3] | CornerTimers | FUN_0042e400 | 3 floats per corner, ~359.0 |

---

## ViewportStruct (param_1 — viewport/render target)

Based on FUN_005425a0, FUN_0054c110. Confidence: **medium**.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x54 | int | Width | FUN_005425a0 | Viewport width |
| +0x58 | int | Height | FUN_005425a0 | Viewport height |
| +0x68 | int | XOffset | FUN_005425a0 | Viewport X origin |
| +0x15c | ptr | LocalData | FUN_005425a0 | Renderer data |
| +0x234 | int | RenderTarget1 | FUN_0054c110 | |
| +0x238 | int | RenderTarget2 | FUN_0054c110 | |
| +0x03c | uint | DirtyFlags | FUN_0054c110 | Bitmask |

---

## VehicleTelemetryBroadcast (param_1 — telemetry)

Based on FUN_004ec080. Confidence: **low** (single function).

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0xcaf | int | BroadcastMode | FUN_004ec080 | 0=full broadcast, 2=team-filtered |
| +0xd2c | ptr | RotationPtr | FUN_004ec080 | Transform input |
| +0xd35 | float | PosX | FUN_004ec080 | Accumulator |
| +0xd36 | int | PosY | FUN_004ec080 | Accumulator |
| +0xd37 | int | PosZ | FUN_004ec080 | Accumulator |
| +0xd38 | float | PosFloat | FUN_004ec080 | Position for transform |

---

## CarPartVisibility (damaged parts)

Based on FUN_004ae490. Confidence: **low** (single function).

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0xb10 | int | PartFrontWing1 | FUN_004ae490 | Visibility flag |
| +0xb34 | int | PartFrontWing2 | FUN_004ae490 | |
| +0xb58 | int | PartFrontWing3 | FUN_004ae490 | |
| +0x1ac8 | int | RepairState | FUN_004ae490 | 0=none, 1=repairing, 2=not |
| +0x1c30 | int | PartRearWing | FUN_004ae490 | |
| +0x2348 | float | AnimParamA | FUN_004ae490 | 0.05f or 0.5f |
| +0x236c | float | AnimParamB | FUN_004ae490 | 0.05f or 0.5f |
| +0x26f0–0x2834 | int[7] | BodyParts | FUN_004ae490 | Additional flags |

---

## AIStateBuffer (param_1 — AI history buffer)

Based on FUN_0042ec60, FUN_0042ebc0. Confidence: **medium**.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x000 | byte | InitializedFlag | FUN_0042ec60 | Set to 1 |
| +0x0c4 | dword[4][11] | HistoryBuffer1 | FUN_0042ec60 | Stride 0x40 |
| +0xbc4 | dword[55] | HistoryBuffer2 | FUN_0042ec60 | Stride 0x40 |
| +0x1ca8 | float[4] | SmoothCoeff | FUN_0042ec60, FUN_0042e320 | 0.5f |

---

## CollisionContactState

Based on FUN_0054d7a0, FUN_00507845. Confidence: **medium**.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x14 | uint | CollisionStateFlags | FUN_0054d7a0 | Bits 0-2 state, bit 4 mode |
| +0x18 | float | ContactMargin | FUN_0054d7a0 | Tolerance |
| +0xf4 | float | OuterRadius | FUN_0054d7a0 | Bounding sphere outer |
| +0xf8 | float | InnerRadius | FUN_0054d7a0 | Bounding sphere inner |
| +0xfc | int | ContactIteration | FUN_0054d7a0 | Solver iteration count |
| +0x1c | float | RefX | FUN_00507845 | Reference X for contact matching |
| +0x20 | float | RefY | FUN_00507845 | |
| +0x24 | float | RefZ | FUN_00507845 | |
| +0x28 | float | RefW | FUN_00507845 | Penetration/distance |
| +0x1058 | int | ContactCount | FUN_00507845 | Contact entries |

---

## UIListComboBox (list/combo control)

Based on FUN_0051a4f2, FUN_0051bc88. Confidence: **medium**.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x20 | int | ItemCount | FUN_0051a4f2, FUN_0051bc88 | |
| +0xc4 | ptr[] | ItemArray | FUN_0051a4f2, FUN_0051bc88 | Stride 0x50/0x15×4 |
| +0x184 | ptr | ListDataPtr | FUN_0051a4f2 | Allocated storage |
| +0x198 | ptr | ListDataPtr | FUN_0051bc88 | Control header |

---

## ChecksumCompute (checksum/hash context)

Based on FUN_0051e5d7, FUN_0051e6ec. Confidence: **medium**.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x5c | int | BlockSize / OutputElementCount | FUN_0051e6ec, FUN_0051e5d7 | Bytes per block |
| +0x64 | int | EntryCount / TableCount | FUN_0051e6ec, FUN_0051e5d7 | Number of parallel streams |
| +0x1a4 | ptr | TableBase / TableArrayPtr | FUN_0051e6ec, FUN_0051e5d7 | Checksum context |

---

## AudioRingBuffer (buffer manager)

Based on FUN_004b3af0, FUN_004b3b30. Confidence: **low** (large stride).

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x6c000–+0x6c00c | various | RingBuffer | FUN_004b3af0, FUN_004b3b30 | Base/end/current pointers |
| +0x6c004 | ptr | EndPtr | FUN_004b3af0 | |
| +0x6c008 | ptr | StartPtr / SourceValue | FUN_004b3af0, FUN_004b3b30 | |
| +0x6c00c | ptr | CurrentPtr / DestValue | FUN_004b3af0, FUN_004b3b30 | |

---

## GeometryProximityTest (per-element wheel collision)

Based on FUN_004ed420. Confidence: **low** (single function).

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x828 | int[4] | ElementFlags | FUN_004ed420 | Per-element flags, stride 0x128 |
| +0x3594 | float[4] | ElementArray | FUN_004ed420 | Stride 0xf8: position+radius |

---

## GridCellIterate (grid counter)

Based on FUN_004be340, FUN_004be4e0. Confidence: **medium**.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x934 | int | CellCounter / RenderCounter | FUN_004be340, FUN_004be4e0 | Incremented per call |

---

## PlayerOptionsFailureRates (FailureRate slots)

Based on FUN_004aa270 (mentioned in 06-session-race-logic.md). Confidence: **medium**.

| Offset | Stride | Count | Field Name | Notes |
|--------|--------|-------|------------|-------|
| +0x5c8 | 0x24 | 7 | FailureRate[0..6] | {current=2, min=0, max=3} |

---

## UNUSED / ABSENT OFFSETS

Offsets +0x1130 and +0x1132 do NOT appear in any 06-session-race-logic function entries.
These are confirmed DirectX false positives in this document.

---

**End of Worker A struct synthesis. Total consolidated: 30 struct definitions from 996 offset observations across 287 struct sections.**

---

## Source: docs/20-math-utilities.md

# Consolidated Struct Definitions from docs/20-math-utilities.md

Generated from 235 struct offset observations across 172 function entries in `20-math-utilities.md`. 
Most observations (163) are from single-function structs — unique to individual functions.
Only 9 observations have 2+ functions sharing the same struct pattern.

---

## Summary

| Category | Distinct Struct Patterns | Functions | Cross-Function? |
|----------|------------------------|-----------|-----------------|
| Buffer/Stream Descriptor | 5 | 6 | Yes (buffer_descriptor) |
| Timer Struct | 2 | 2 | Yes |
| Dynamic Array | 2 | 2 | Yes |
| Linked List Node | 6 | 5 | Yes (node_entry, linked_list) |
| Array Container | 2 | 2 | Yes |
| Vehicle Struct (high offsets) | 5 | 5 | No |
| FILE* struct | 1 | 1 | No |
| Single-function utility structs | ~160 | ~160 | No |
| **Total** | **~180 struct patterns** | **172** | |

---

## Multi-Function Struct Groups (Cross-Function Confirmation)

These structs have 2+ functions confirming the same offset layout, providing higher confidence.

### Buffer Descriptor (param_2 / param_1)

Functions: FUN_0052a5d7, FUN_005698e0, FUN_0058d78e
Confidence: medium (offset ranges differ — may be different buffer types)

| Offset | Field | Type | Notes | Observed in |
|--------|-------|------|-------|-------------|
| +0x00 | CurrentPtr | int32* | Current write position in buffer | FUN_0058d78e |
| +0x04 | RemainingCount | int32 | Bytes left before flush needed | FUN_0058d78e |
| +0x18 | MatrixA | float[12] | 3x4 matrix (via FUN_0056c3a0) | FUN_005698e0 |
| +0x28 | BufferStart | ? | Start of buffer (wrap target) | FUN_0052a5d7 |
| +0x2c | BufferEnd | ? | End of buffer (wrap limit) | FUN_0052a5d7 |
| +0x30 | ReadPtr | ? | Current read position | FUN_0052a5d7 |
| +0x34 | EndPtr | ? | Buffer end pointer | FUN_0052a5d7 |
| +0x38 | Callback | ? | Optional callback function | FUN_0052a5d7 |
| +0x3c | CallbackCtx | ? | Callback context | FUN_0052a5d7 |
| +0x78 | ExtraInt1 | int | Written from param_5 | FUN_005698e0 |
| +0x7c | ExtraInt2 | int | Written from param_3 | FUN_005698e0 |
| +0x80 | ExtraByte | byte | Written from param_4 | FUN_005698e0 |

### Simple Buffer Descriptor (param_2)

Functions: FUN_0052a5d7, FUN_0058d78e
Confidence: medium (partial overlap)

| Offset | Field | Type | Notes | Observed in |
|--------|-------|------|-------|-------------|
| +0x00 | CurrentPtr | int32* | Write position | FUN_0058d78e |
| +0x04 | RemainingCount | int32 | Bytes remaining | FUN_0058d78e |
| +0x28 | BufferStart | ? | Wrap target | FUN_0052a5d7 |
| +0x2c | BufferEnd | ? | Wrap limit | FUN_0052a5d7 |
| +0x30 | ReadPtr | ? | Read position | FUN_0052a5d7 |
| +0x34 | EndPtr | ? | Buffer end | FUN_0052a5d7 |
| +0x38 | Callback | ? | Optional callback | FUN_0052a5d7 |
| +0x3c | CallbackCtx | ? | Callback context | FUN_0052a5d7 |

### Timer/Performance State Struct (param_1)

Functions: FUN_00568be0, FUN_00569da0
Confidence: high (identical offset layout)

| Offset | Field | Type | Notes | Observed in |
|--------|-------|------|-------|-------------|
| +0x00 | FrequencyLowPart | uint | QPC frequency low DWORD | FUN_00568be0 |
| +0x08 | InvFrequencyScaled | double | scaling_constant / freq | FUN_00568be0 |
| +0x10–+0x14 | AccLow/AccHigh | uint | Zeroed accumulators | FUN_00568be0 |
| +0x18–+0x1c | CounterLow/CounterHigh | uint | QPC init sample | FUN_00568be0 |
| +0x20–+0x24 | LastSampleLow/High | uint | Copy of init sample | FUN_00568be0 |
| +0x28–+0x2c | Acc/Overflow | uint | Zeroed | FUN_00568be0 |
| +0x48 | Mode | uint | Timer mode flags | FUN_00568be0 |
| +0x00 | StartTime | double | QPC start time | FUN_00569da0 |
| +0x08 | Frequency | double | QPC frequency | FUN_00569da0 |
| +0x10 | ElapsedS | double | Elapsed seconds | FUN_00569da0 |
| +0x18 | ElapsedMS | double | Elapsed ms | FUN_00569da0 |

### Dynamic Array Container (param_1)

Functions: FUN_00457cf0, FUN_004bd900
Confidence: medium (different field layouts)

| Offset | Field | Type | Notes | Observed in |
|--------|-------|------|-------|-------------|
| +0x0c | Capacity | ? | Current capacity (elements) | FUN_004bd900 |
| +0x10 | Count | ? | Current element count | FUN_004bd900 |
| +0x14 | Data | ? | Array data pointer | FUN_004bd900 |
| [0] (+0x00) | HeapPtr | int* | Heap pointer, freed via FUN_00587bcf | FUN_00457cf0 |
| [1]–[6] (+0x04–+0x18) | DataFields | int | Zeroed unconditionally | FUN_00457cf0 |

### Linked List Node Layout

Functions: FUN_00407c90, FUN_0050b6f0, FUN_00512a20, FUN_005bf450, FUN_005e3b60
Confidence: high (consistent pattern)

| Offset | Field | Type | Notes | Observed in |
|--------|-------|------|-------|-------------|
| +0x00 | Key / ID | int32 | Match key or pointer | FUN_00407c90, FUN_0050b6f0, FUN_00512a20, FUN_005e3b60 |
| +0x04 | NextPtr | int32* | Next node in list | FUN_00407c90, FUN_0050b6f0, FUN_00512a20, FUN_005e3b60 |
| +0x08 | Flags/Data | byte[4] | Bit 0 = destroy on removal | FUN_00407c90, FUN_0050b6f0, FUN_00512a20 |
| +0x0c | PrevPtr | int32* | Previous node (double-linked) | FUN_0050b6f0 |

### Generic Array Container

Functions: FUN_0056a350, FUN_005e0810
Confidence: medium

| Offset | Field | Type | Notes | Observed in |
|--------|-------|------|-------|-------------|
| +0x00 | ArrayPtr | int* | Pointer to element array | FUN_0056a350, FUN_005e0810 |
| +0x04 | ElementCount | int | Number of elements | FUN_0056a350, FUN_005e0810 |
| +0x08 | ElementCapacity | int | Allocated capacity | FUN_0056a350, FUN_005e0810 |
| +0x0c | ElementSize | int | Size of each element | FUN_0056a350 |

### Ring Buffer (audio/network)

Functions: FUN_0057b530, FUN_0057b630
Confidence: high

| Offset | Field | Type | Notes | Observed in |
|--------|-------|------|-------|-------------|
| +0x1000 | ReadCursor | short | Head index in ring buffer | FUN_0057b530, FUN_0057b630 |
| +0x1002 | AvailableData | ushort | Tail index / available data | FUN_0057b530, FUN_0057b630 |

### File Handle State Struct

Function: FUN_00587d33 (single observation — MSVC CRT FILE struct internal layout)

| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x0c | _flag | int | Mode flags |
| +0x10 | _file | int | OS file handle |
| +0x1c | _tmpfname | char* | Temp filename (freed if non-null) |

---

## Single-Function Struct Observations

These ~163 observations represent unique struct layouts used by a single function each. 
Listed below by functional category.

### Linked List Controller (param_1)

**FUN_00407c90 — List Controller:**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x18 | Head | int32* | Linked list head |
| +0x1c | Tail | int32* | Linked list tail |
| +0x20 | Current | int32* | Current iterator |
| +0x24 | Count | int32 | Number of nodes |

**FUN_0050b6f0 — List Container:**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | Head | int32* | First node |
| +0x04 | NodeCount | int32 | Total node count |

**FUN_00512a20 — Resource List Container:**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x08 | Head | int32* | List head |
| +0x0c | TailOrCount | int32* | Tail or count |
| +0x10 | NodeCount | int32 | Number of nodes |
| +0x14 | DataPtr | void* | Associated data |
| +0x18 | AllocFunc | func* | Allocation function |
| +0x1c | FreeFunc | func* | Deallocation function |

**FUN_00565f20 — List Container:**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | HeadPtr | int* | Current list head |
| *(headPtr)+0x08 | NextPtr | int* | Next entry in list |

### Stream Object (param_1)

**FUN_005e3b60:**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | StreamPtr | byte* | Data stream pointer |
| +0x04 | StreamEnd | byte* | End of stream marker |

### Ring Buffer (param_1)

**FUN_00569da0:**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | Buffer | byte* | Data buffer |
| +0x04 | Capacity | int | Max capacity |
| +0x08 | HeadIdx | int | Write index |
| +0x0c | TailIdx | int | Read index |
| +0x10 | WrapFlag | int | Overflow flag |
| +0x14 | ElementSize | int | Per-element size |

### Processing State Machine (param_1)

**FUN_00404460 — Multi-Phase Processing:**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x130 | Cap | int32 | Max iteration count per phase |
| +0x16c | Phase | int32 | 0, 1, 2 — state machine |
| +0x170 | FloatVal | float | Computed threshold value |
| +0x174 | IterIdx | int32 | Current iteration index |

### Per-Element Struct (param_1 — per element)

**FUN_0053c790 — Per-Element Data:**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | OwnerPtr | void* | Container pointer |
| +0x04 | Index | int | Element index |
| +0x14 | Val1 | float | First float value |
| +0x18 | Val2 | float | Second float value |
| +0x1c | Flag1 | int | Flag |
| +0x20 | Val3 | float | Third float value |
| +0x24 | Dim | byte | Dimension/count |

### FILE* Stream (MSVC CRT)

**FUN_00587d33 — FILE struct internals:**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x0c | _flag | int | CRT FILE flag field |
| +0x10 | _file | int | OS file descriptor |
| +0x1c | _tmpfname | char* | Temporary filename |

### VTable Object Header

**FUN_00408520 — VTable Swap:**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | vtable | pointer | Initial→final vtable swap |
| +0x10–+0x30 | SubObj[4..12] | pointer[] | 9 sub-object slots |

---

## Vehicle/AI Struct Offsets (High Offset Ranges)

These offsets (>0x1000 or known AI offsets) suggest vehicle or AI struct access rather than utility struct access. From docs/20-math-utilities.md.

| Offset | Field | Type | Notes | Function |
|--------|-------|------|-------|----------|
| +0x1000 | ReadCursor | short | Ring buffer head | FUN_0057b530 (?) |
| +0x1000 | ReadCursor | short | | FUN_0057b630 (?) |
| +0x1002 | AvailableData | ushort | Ring buffer tail | FUN_0057b530 (?) |
| +0x1002 | AvailableData | ushort | | FUN_0057b630 (?) |
| +0x1040 | Scale | float | Graphics scale factor | FUN_00530b50 (?) |
| +0x105c | ObjectIndex | int | Object/vertex index | FUN_00530b50 (?) |
| +0x1b79c | ? | ? | | FUN_005a7320 (?) |
| +0x32d0 | ? | int | | FUN_004A3570 (?) |
| +0x3e18 | ? | int | | FUN_005a0d00 (?) |
| +0x3fc4 | SessionState | int | | FUN_004AB040 (?), FUN_004AB230 (?) |
| +0x4034 | ? | int | | FUN_004a1dc0 (?) |
| +0x4038 | ? | int | | FUN_004A3570 (?) |
| +0x4354 | AIStateFlags | int | Overtaking zone flag | FUN_0052bbe8 (?) |

Note: These offsets appear in math-utility-targeted functions that may actually belong to game-logic subsystems despite being filed under docs/20.

---

## Unused Empty Struct Offset Headers

The following functions have `**Struct offsets**` headers but no data rows:

FUN_0053e410, FUN_0058afe3, FUN_005984d3, FUN_00597bdc, FUN_0059bd00, 
FUN_005820c0, FUN_00584340, FUN_005866f0, FUN_005888e0, FUN_00588910,
FUN_00588a5e, FUN_00589a53, FUN_0058af53, FUN_0058b10d, FUN_0058b2e5,
FUN_00590458, FUN_00593dd0, FUN_005a6060, FUN_00586bd0, FUN_00587070,
FUN_00588958, FUN_00588f86, FUN_0058a366, FUN_0058cb90, FUN_0058d1e0,
FUN_0058da50, FUN_00599ef2, FUN_0059b761, FUN_0059bb92, FUN_0059d490,
FUN_0059ef70, FUN_005a0b10, FUN_005a48a0, FUN_005a6610 (63 total)

---

Generated from `extracted_offsets_20.json` — 235 observations, 172 with offset data, 63 empty headers.

---

## Source: docs/01-engine-architecture.md

Source: `docs/01-engine-architecture.md` (778 entries, 593 offset observations)

Total extracted observations: 523

## 1. HighResTimer (inferred)

Performance counter timer. FUN_005564b0, FUN_00556510, FUN_00568c60, FUN_00568cb0.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | int32 | Enabled/ActiveFlag | FUN_005564b0, FUN_00568c60, FUN_00568cb0 | 0=disabled |
| +0x08 | double | ScaleFactor | FUN_00556510 | Multiplier for elapsed high part |
| +0x10 | int32 | OtherAccum0 | FUN_00568c60 | Zeroed on reset |
| +0x14 | int32 | OtherAccum1 | FUN_00568c60 | Zeroed on reset |
| +0x18 | uint32 | CurrentLow | FUN_00568c60, FUN_00556510 | QPC low part |
| +0x1c | uint32 | CurrentHigh | FUN_00568c60, FUN_00556510 | QPC high part |
| +0x20 | uint32 | LastLow | FUN_00568c60, FUN_00556510 | Previous sample low |
| +0x24 | uint32 | LastHigh | FUN_00568c60, FUN_00556510 | Previous sample high |
| +0x28 | uint32 | AccumLow | FUN_00568c60 | Accumulated time low |
| +0x2c | uint32 | AccumHigh | FUN_00568c60 | Accumulated time high |
| +0x48 | int/byte | TimerModeFlags | FUN_005564b0, FUN_00568c60, FUN_00568cb0 | Bit 0=QPC mode, bit 1=alternate |

## 2. LinkedList (inferred)

Standard 4-field linked list container.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | ptr | HeadPtr | FUN_005819c0, FUN_00581a20, FUN_00586000 | First node |
| +0x04 | ptr | TailPtr | FUN_005819c0, FUN_00586000 | Last node |
| +0x08 | int | Count | FUN_005819c0, FUN_00586000 | Node count |
| +0x0c | int | Capacity | FUN_005819c0 | Max capacity |

## 3. LinkedListNode (inferred)

Node with data, next, and optional free flag.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | ptr | DataPtr | Multiple | Pointer to node data |
| +0x04 | ptr | NextPtr | Multiple | Next node in list |
| +0x08 | byte | FreeFlag | Multiple | If non-zero, free data on destroy |

## 4. MutexGuard (inferred)

Mutex/critical section synchronization struct. Multiple instances at different base offsets within larger structs.

| Offset (base) | Type | Field Name | Observed in | Notes |
|---------------|------|------------|-------------|-------|
| +0x1c/+0x24 | HANDLE+byte | MutexHandle+MutexActive | FUN_005865c0 | Mutex at +0x1c, flag at +0x24 |
| +0x54/+0x5c | HANDLE+byte | MutexHandle+ValidFlag | FUN_00586560 | Mutex at +0x54, flag at +0x5c |
| +0xec/+0xf0/+0xf4 | int+HANDLE+DWORD | SharedValue+MutexHandle+Timeout | FUN_00585770 | Thread-safe read |
| +0x5b4/+0x5b8/+0x5bc | ptr+HANDLE+DWORD | WriteTarget+MutexHandle+Timeout | FUN_00585cd0, FUN_005932f5 | Thread-safe write |
| +0x50/+0x54 | HANDLE+DWORD | MutexHandle+Timeout | FUN_005941ee, FUN_005936ff | From FUN_0058bb79 group |
| +0x08/+0x0c | int32+CRITICAL_SECTION | InitFlag+CriticalSection | FUN_00595a61 | Array of CS at stride 0x24 |
| +0x554/+0x558 | HANDLE+DWORD | MutexHandle+Timeout | FUN_005932f5 |  |

## 5. CamMan (docs/01)

Camera manager struct (FUN_0040c9e0, FUN_0040cce0).

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | ptr | MAINVIEWSceneNode | FUN_0040cce0 |  |
| +0x08 | ptr | CurrentCamera | FUN_0040cce0 |  |
| +0x18 | ptr | CameraObject1 | FUN_0040cce0 |  |
| +0x1c | ptr | CameraObject2 | FUN_0040cce0 |  |
| +0x20 | ptr | CameraObject3 | FUN_0040cce0 |  |
| +0x2e | byte | Flag | FUN_0040c9e0 |  |
| +0x38 | int | CameraIndex | FUN_0040c9e0 | -1=none |

## 6. GameConfig (inferred — FUN_004216f0)

Config directory/option table. Range +0xb8 to +0xe8.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0xb8 | int | Field_0xb8 | FUN_004216f0 |  |
| +0xbc | int | Field_0xbc | FUN_004216f0 |  |
| +0xc0 | int | Field_0xc0 | FUN_004216f0 |  |
| +0xc4 | int | Field_0xc4 | FUN_004216f0 | Default 22 (0x16) |
| +0xc8 | bool | Field_0xc8 | FUN_004216f0 | Default 1 |
| +0xcc | int | Field_0xcc | FUN_004216f0 |  |
| +0xd0 | int | Field_0xd0 | FUN_004216f0 |  |
| +0xd4 | byte | Field_0xd4 | FUN_004216f0 |  |
| +0xd5 | byte | Field_0xd5 | FUN_004216f0 | Default 1 |
| +0xd6 | byte | Field_0xd6 | FUN_004216f0 |  |
| +0xd8 | int | Field_0xd8 | FUN_004216f0 | Default 1 |
| +0xdc | int | Field_0xdc | FUN_004216f0 | Default 1 |
| +0xe0 | int | Field_0xe0 | FUN_004216f0 |  |
| +0xe4 | int | Field_0xe4 | FUN_004216f0 | Default 1 |
| +0xe8 | float | Field_0xe8 | FUN_004216f0 | -1.0f (disabled) |

## 7. UIObjectList (inferred — FUN_0047e960)

UI option list manager.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x44 (0x11) | ptr | ItemListHead | FUN_0047e960 |  |
| +0x48 (0x12) | ptr | ItemListTail | FUN_0047e960 |  |
| +0x4c (0x13) | ptr | CurrentItem | FUN_0047e960 |  |
| +0x50 (0x14) | int | ItemCount | FUN_0047e960 |  |
| +0xec (0x3b) | int | InitField | FUN_0047e960 | zeroed |
| +0xf0 (0x3c) | int | EndMarker | FUN_0047e960 | -1 |
| +0xf4 (0x3d) | int | OptionID | FUN_0047e960 |  |

## 8. PauseStringTable (inferred — FUN_004541d0)

Pause menu string table manager.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0xc88 | int | EntryCount | FUN_004541d0 | Max string count |
| +0xc8c | int | CurrentID | FUN_004541d0 | Current string ID |

## 9. RaceModeBackup (inferred — FUN_00404890, FUN_004049d0)

Race mode save/restore struct.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x14 | byte | InitFlag | FUN_00404890, FUN_004049d0 | WasInitialized |
| +0x15 | byte | InitFlag2 | FUN_00404890 |  |
| +0x20 | byte | StateCondition | FUN_00404890, FUN_004049d0 | 1=active |
| +0x50 | int | SavedSessionType | FUN_00404890, FUN_004049d0 | Backup DAT_007d2e44 |
| +0x54 | int | SavedRaceMode | FUN_00404890, FUN_004049d0 | Backup DAT_007d0410 |

## 10. DynamicBuffer (inferred — FUN_00564930)

Growing buffer with accumulator and realloc.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x04 | int | AccumSize | FUN_00564930 | Accumulated count |
| +0x08 | int | ElemSize | FUN_00564930 | Per-element size |
| +0x0c | int | Addend | FUN_00564930 | Growth amount |
| +0x14 | ptr | Buffer | FUN_00564930 | Allocated buffer |

## 11. SceneExtents (inferred — FUN_004bdc10)

Scene bounding box extents.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x924 | float | MinX | FUN_004bdc10 |  |
| +0x928 | float | ScaleX | FUN_004bdc10 | 1/(maxX-minX) |
| +0x92c | float | MinZ | FUN_004bdc10 |  |
| +0x930 | float | ScaleZ | FUN_004bdc10 | 1/(maxZ-minZ) |

## 12. DoublyLinkedList (inferred)

Doubly-linked list node and container. Multiple offset variants.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x1c/+0x2c | ptr | PrevPtr | FUN_005519e0, FUN_0055c2e0 | Previous node; offset varies by container |
| +0x20/+0x30 | ptr | NextPtr | FUN_005519e0, FUN_0055c2e0 | Next node; offset varies by container |
| +0x118/+0x1518 | ptr | ListHead | FUN_005519e0, FUN_0055c2e0 | Head pointer; offset varies by container |

## 13. BoolFloatToggle (inferred — FUN_0059d6ff)

Boolean-to-float conversion toggle.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x1065 | byte | BoolFlag | FUN_0059d6ff | Toggle |
| +0x3584 | float | FloatParam | FUN_0059d6ff | 0.0 or 1.0 |

## 14. AnimationList (inferred)

Animation/sprite list container.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x204 | ptr | ListHead | FUN_00585bf0, FUN_004f2e90 | Linked list of anim objects |
| +0x10 (node) | ptr | NextPtr | FUN_004f2e90 | Node next ptr |
| +0x118 | int | ElementCount | FUN_004f2e90 | Per-node sub-element count |
| +0x11c | ptr | ElementBase | FUN_004f2e90 | Per-element data array |

## 15. ArrayContainer (various)

Multiple stride-based array container variants.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x04/+0x0c | int | Count | Multiple | Element count |
| +0x08/+0x10/+0x34 | ptr | ArrayBase | Multiple | Array pointer |
| +0x18/+0x2c | int | SlotCount | FUN_00558cf0, FUN_0056eb30 |  |
| +0x1c | ptr | ElementArray | FUN_0056eb30 | Stride 0x48 |
| +0xa4 | int | TableCount | FUN_0058a638 |  |
| +0xa8 | ptr | TableBase | FUN_0058a638 | Stride 0x94 |

## 16. InputDevice (inferred)

Input device binding struct and controller array.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x13E8 | int | BindingValueA | FUN_0040be70 | Read when state 0x10 |
| +0x13EC | int | InputDeviceHandle | FUN_0040be70 | Handle/ptr |
| +0x1544 | int | ControlID | FUN_0040be70 sibling |  |
| +0x1f98 | ptr | ControllerArray | FUN_00455da0 | Stride 0xb, max 0x21 entries |

## 17. NetworkMessage (inferred)

Network message/packet struct with event code and string buffer.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x5C4 | uint | EventCode | FUN_004a3ef0 |  |
| +0x5C8 | char[] | StringBuffer | FUN_004a3ef0 |  |
| +0x618 | HANDLE | BufferMutex | FUN_004a3ef0 |  |
| +0x910 | uint16 | HeaderField | FUN_00591583 |  |
| +0xAC8 | ptr | ListBase | FUN_00591583 |  |
| +0xAD8 | HANDLE | ListMutex | FUN_00591583 |  |
| +0xADC | DWORD | MutexTimeout | FUN_00591583 |  |

## 18. FreeableMultiPtr (inferred)

Struct with 3-7 freeable pointer fields, often freed in cleanup loops.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x0c..+0x24 | void*[7] | FreeablePtrs | FUN_0058f8eb | Freed if not sentinel |
| +0x224..+0x240 | ptr*3+int*3 | SubBuffers | FUN_005913d0 | 3 ptrs + counters |
| +0x0c/+0x1c/+0x20 | ptr*3 | ResourcePtrs | FUN_0059a17b | Freed with release+free |

## 19. Bounds2D (inferred)

2D bounding box int pair.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x120 | int | XMin | FUN_005977c4 |  |
| +0x124 | int | XMax | FUN_005977c4 |  |
| +0x140 | int | YMin | FUN_005977c4 |  |
| +0x144 | int | YMax | FUN_005977c4 |  |

## 20. Unmatched / Single-Observation Offsets

Offsets appearing once or without clear struct identity.

| Offset | Type | Field | Function | Line |
|--------|------|-------|----------|------|
| +0x1C | int | int | FUN_00405630 — - Struct Init with VTable Dispatch and Zero Fill | 7042 |
| +0x34 | int | int* | FUN_00405630 — - Struct Init with VTable Dispatch and Zero Fill | 7044 |
| +0x18 | ptr | int* | FUN_00408050 — - Linked List Node Search by ID + Operation | 7068 |
| +0x20 | ptr | int* | FUN_00408050 — - Linked List Node Search by ID + Operation | 7069 |
| +0x1A0 | int | int* | FUN_00418df0 — - Linked List Destructor with Conditional Cleanup | 7169 |
| +0x1A4 | int | int | FUN_00418df0 — - Linked List Destructor with Conditional Cleanup | 7170 |
| +0x1A8 | int | int | FUN_00418df0 — - Linked List Destructor with Conditional Cleanup | 7171 |
| +0x1AC | int | int | FUN_00418df0 — - Linked List Destructor with Conditional Cleanup | 7172 |
| +0x20 | ptr | ModuleObject | FUN_00465300 — Message Dispatch Node Allocator | 880 |
| +0x00 | int | ActiveFlag | FUN_00465300 — Message Dispatch Node Allocator | 944 |
| +0x48 | int | TimerModeFlags | FUN_00465300 — Message Dispatch Node Allocator | 945 |
| +0x00 | ptr | HeadPtr | FUN_00465300 — Message Dispatch Node Allocator | 1081 |
| +0x04 | ptr | TailPtr | FUN_00465300 — Message Dispatch Node Allocator | 1082 |
| +0x08 | int | Count | FUN_00465300 — Message Dispatch Node Allocator | 1083 |
| +0x0C | int | Capacity | FUN_00465300 — Message Dispatch Node Allocator | 1084 |
| +0xEC | int | SharedValue | FUN_00465300 — Message Dispatch Node Allocator | 1111 |
| +0xF0 | HANDLE | MutexHandle | FUN_00465300 — Message Dispatch Node Allocator | 1112 |
| +0xF4 | DWORD | WaitTimeout | FUN_00465300 — Message Dispatch Node Allocator | 1113 |
| +0x54 | HANDLE | MutexHandle | FUN_00465300 — Message Dispatch Node Allocator | 1141 |
| +0x5C | byte | MutexValidFlag | FUN_00465300 — Message Dispatch Node Allocator | 1142 |
| +0x1065 | byte | BoolFlag | FUN_00465300 — Message Dispatch Node Allocator | 1485 |
| +0x3584 | float | FloatParam | FUN_00465300 — Message Dispatch Node Allocator | 1486 |
| +0x00 | int32 | Frequency | FUN_00465300 — Message Dispatch Node Allocator | 1567 |
| +0x08 | double | ScaleFactor | FUN_00465300 — Message Dispatch Node Allocator | 1568 |
| +0x20 | int32 | TimestampLow | FUN_00465300 — Message Dispatch Node Allocator | 1569 |
| +0x24 | int32 | TimestampHigh | FUN_00465300 — Message Dispatch Node Allocator | 1570 |
| +0x2C | int32 | SlotCount | FUN_00465300 — Message Dispatch Node Allocator | 1595 |
| +0x34 | int32 | SlotArray | FUN_00465300 — Message Dispatch Node Allocator | 1596 |
| +0x04 | int32 | ElementCount | FUN_00465300 — Message Dispatch Node Allocator | 1621 |
| +0x08 | int32 | PointerArray[0] | FUN_00465300 — Message Dispatch Node Allocator | 1622 |
| +0x00 | int32 | Enabled | FUN_00465300 — Message Dispatch Node Allocator | 1674 |
| +0x48 | byte | FlagByte | FUN_00465300 — Message Dispatch Node Allocator | 1675 |
| +0x18 | int32 | CurrentLow | FUN_00465300 — Message Dispatch Node Allocator | 1676 |
| +0x1C | int32 | CurrentHigh | FUN_00465300 — Message Dispatch Node Allocator | 1677 |
| +0x20 | int32 | LastLow | FUN_00465300 — Message Dispatch Node Allocator | 1678 |
| +0x24 | int32 | LastHigh | FUN_00465300 — Message Dispatch Node Allocator | 1679 |
| +0x28 | int32 | AccumLow | FUN_00465300 — Message Dispatch Node Allocator | 1680 |
| +0x2C | int32 | AccumHigh | FUN_00465300 — Message Dispatch Node Allocator | 1681 |
| +0x10 | int32 | OtherAccum0 | FUN_00465300 — Message Dispatch Node Allocator | 1682 |
| +0x14 | int32 | OtherAccum1 | FUN_00465300 — Message Dispatch Node Allocator | 1683 |
| +0x00 | ptr | ObjectPtr | FUN_00465300 — Message Dispatch Node Allocator | 1727 |
| +0x00 | ptr | ListHead | FUN_00465300 — Message Dispatch Node Allocator | 1768 |
| +0x10 | HANDLE | Handle | FUN_00465300 — Message Dispatch Node Allocator | 1769 |
| +0x18 | byte | HandleFlag | FUN_00465300 — Message Dispatch Node Allocator | 1770 |
| +0x60 | int32 | SomeField | FUN_00465300 — Message Dispatch Node Allocator | 1810 |
| +0x1C | HANDLE | MutexHandle | FUN_00465300 — Message Dispatch Node Allocator | 1834 |
| +0x24 | byte | MutexActive | FUN_00465300 — Message Dispatch Node Allocator | 1835 |
| +0x10 | int32 | FieldA | FUN_00465300 — Message Dispatch Node Allocator | 1860 |
| +0x14 | int32 | Sentinel | FUN_00465300 — Message Dispatch Node Allocator | 1861 |
| +0x18 | byte | Flag1 | FUN_00465300 — Message Dispatch Node Allocator | 1862 |
| +0x19 | byte | Flag2 | FUN_00465300 — Message Dispatch Node Allocator | 1863 |
| +0x04 | byte | unknown | FUN_00465300 — Message Dispatch Node Allocator | 2223 |
| +0x54 | int | unknown | FUN_00465300 — Message Dispatch Node Allocator | 2224 |
| +0x13C | int | unknown | FUN_00465300 — Message Dispatch Node Allocator | 2255 |
| +0x20 | int | unknown | FUN_00465300 — Message Dispatch Node Allocator | 2278 |
| +0x24 | int | unknown | FUN_00465300 — Message Dispatch Node Allocator | 2279 |
| +0x28 | int | unknown | FUN_00465300 — Message Dispatch Node Allocator | 2280 |
| +0x2C | int | unknown | FUN_00465300 — Message Dispatch Node Allocator | 2281 |
| +0x30 | int | unknown | FUN_00465300 — Message Dispatch Node Allocator | 2282 |
| +0x34 | int | unknown | FUN_00465300 — Message Dispatch Node Allocator | 2283 |
| +0x38 | int | unknown | FUN_00465300 — Message Dispatch Node Allocator | 2284 |
| +0x3C | int | unknown | FUN_00465300 — Message Dispatch Node Allocator | 2285 |
| +0x04 | int | accumSize | FUN_00465300 — Message Dispatch Node Allocator | 2347 |
| +0x08 | int | elemSize | FUN_00465300 — Message Dispatch Node Allocator | 2348 |
| +0x0C | int | addend | FUN_00465300 — Message Dispatch Node Allocator | 2349 |
| +0x14 | int | buffer | FUN_00465300 — Message Dispatch Node Allocator | 2350 |
| +0x00 | int | enabled | FUN_00465300 — Message Dispatch Node Allocator | 2374 |
| +0x12 | byte | flags | FUN_00465300 — Message Dispatch Node Allocator | 2375 |
| +0x00 | ptr | objectPtr | FUN_00465300 — Message Dispatch Node Allocator | 2520 |
| +0x08 | byte | activeFlag | FUN_00465300 — Message Dispatch Node Allocator | 2521 |
| +0x118 | ptr | ListHead | FUN_00465300 — Message Dispatch Node Allocator | 2906 |
| +0x2C | ptr | PrevNode | FUN_00465300 — Message Dispatch Node Allocator | 2911 |
| +0x30 | ptr | NextNode | FUN_00465300 — Message Dispatch Node Allocator | 2912 |
| +0x00 | int | field_0 | FUN_00465300 — Message Dispatch Node Allocator | 2940 |
| +0x24 | int | field_24 | FUN_00465300 — Message Dispatch Node Allocator | 2941 |
| +0x28 | int | field_28 | FUN_00465300 — Message Dispatch Node Allocator | 2942 |
| +0x2C | int | field_2c | FUN_00465300 — Message Dispatch Node Allocator | 2943 |
| +0x30 | int | field_30 | FUN_00465300 — Message Dispatch Node Allocator | 2944 |
| +0x34 | int | field_34 | FUN_00465300 — Message Dispatch Node Allocator | 2945 |
| +0x38 | int | field_38 | FUN_00465300 — Message Dispatch Node Allocator | 2946 |
| +0x3C | int | field_3c | FUN_00465300 — Message Dispatch Node Allocator | 2947 |
| +0x40 | int | field_40 | FUN_00465300 — Message Dispatch Node Allocator | 2948 |
| +0x1518 | ptr | ListHead | FUN_00465300 — Message Dispatch Node Allocator | 2976 |
| +0x1C | ptr | PrevNode | FUN_00465300 — Message Dispatch Node Allocator | 2981 |
| +0x20 | ptr | NextNode | FUN_00465300 — Message Dispatch Node Allocator | 2982 |
| +0x18 | int | ElementCount | FUN_00465300 — Message Dispatch Node Allocator | 3043 |
| +0x1C | byte | ElementArray | FUN_00465300 — Message Dispatch Node Allocator | 3044 |
| +0x00 | ptr | InnerPtr | FUN_00465300 — Message Dispatch Node Allocator | 3072 |
| +0x5B4 | ptr | WriteTarget | FUN_00465300 — Message Dispatch Node Allocator | 3155 |
| +0x5B8 | HANDLE | MutexHandle | FUN_00465300 — Message Dispatch Node Allocator | 3156 |
| +0x5BC | DWORD | WaitTimeout | FUN_00465300 — Message Dispatch Node Allocator | 3157 |
| +0x19 | byte | Counter | FUN_00465300 — Message Dispatch Node Allocator | 3183 |
| +0x18 | ptr | ListHead | FUN_00465300 — Message Dispatch Node Allocator | 3572 |
| +0x20 | ptr | CurrentPtr | FUN_00465300 — Message Dispatch Node Allocator | 3573 |
| +0x0C | byte | ElementArray | FUN_00465300 — Message Dispatch Node Allocator | 3598 |
| +0x10 | int | ElementCount | FUN_00465300 — Message Dispatch Node Allocator | 3599 |
| +0x3FC4 | int | StateMode | FUN_00465300 — Message Dispatch Node Allocator | 3675 |
| +0x174 | int | FreeablePtr | FUN_00465300 — Message Dispatch Node Allocator | 3754 |
| +0x39 | byte | ConfigByte | FUN_00465300 — Message Dispatch Node Allocator | 3777 |
| +0xE0 | int | CommandResult | FUN_00465300 — Message Dispatch Node Allocator | 3851 |
| +0x1518 | int | StringField | FUN_00465300 — Message Dispatch Node Allocator | 4012 |
| +0x08 | int | ListHead | FUN_00465300 — Message Dispatch Node Allocator | 4036 |
| +0x0C | int | ElementCount | FUN_00465300 — Message Dispatch Node Allocator | 4037 |
| +0x00 | int | Head | FUN_00465300 — Message Dispatch Node Allocator | 4102 |
| +0x04 | int | Tail | FUN_00465300 — Message Dispatch Node Allocator | 4103 |
| +0x08 | int | Count | FUN_00465300 — Message Dispatch Node Allocator | 4104 |
| +0x0C | int | Size | FUN_00465300 — Message Dispatch Node Allocator | 4105 |
| +0x11C | int | Count | FUN_00465300 — Message Dispatch Node Allocator | 4246 |
| +0x120 | ptr | Head | FUN_00465300 — Message Dispatch Node Allocator | 4247 |
| +0xA4 | int | int | FUN_00465300 — Message Dispatch Node Allocator | 4386 |
| +0xA8 | int | pointer | FUN_00465300 — Message Dispatch Node Allocator | 4387 |
| +0x08 | int | int | FUN_00465300 — Message Dispatch Node Allocator | 4506 |
| +0x10 | int | int | FUN_00465300 — Message Dispatch Node Allocator | 4507 |
| +0x18 | int | int | FUN_00465300 — Message Dispatch Node Allocator | 4508 |
| +0x5B4 | int | undefined4 | FUN_00465300 — Message Dispatch Node Allocator | 4568 |
| +0x5B8 | int | HANDLE | FUN_00465300 — Message Dispatch Node Allocator | 4569 |
| +0x5BC | int | DWORD | FUN_00465300 — Message Dispatch Node Allocator | 4570 |
| +0x204 | ptr | AnimationListHead | FUN_00465300 — Message Dispatch Node Allocator | 4927 |
| +0x10 | ptr | NextNode | FUN_00465300 — Message Dispatch Node Allocator | 4928 |
| +0x118 | int | ElementCount | FUN_00465300 — Message Dispatch Node Allocator | 4929 |
| +0x11C | ptr | ElementBase | FUN_00465300 — Message Dispatch Node Allocator | 4930 |
| +0x618 | HANDLE | BufferMutex | FUN_00465300 — Message Dispatch Node Allocator | 4977 |
| +0x5C4 | int | EventCode | FUN_00465300 — Message Dispatch Node Allocator | 4978 |
| +0x5C8 | char | StringBuffer | FUN_00465300 — Message Dispatch Node Allocator | 4979 |
| +0x10 | int | Field1 | FUN_00465300 — Message Dispatch Node Allocator | 5027 |
| +0x14 | int | Field2 | FUN_00465300 — Message Dispatch Node Allocator | 5028 |
| +0x18 | byte | Field3 | FUN_00465300 — Message Dispatch Node Allocator | 5029 |
| +0x0 | int | ResourceKey | FUN_00465300 — Message Dispatch Node Allocator | 5142 |
| +0x10 | int | LookupModeFlag | FUN_00465300 — Message Dispatch Node Allocator | 5143 |
| +0x910 | int | HeaderField | FUN_00465300 — Message Dispatch Node Allocator | 5189 |
| +0xAD8 | HANDLE | ListMutex | FUN_00465300 — Message Dispatch Node Allocator | 5190 |
| +0xADC | DWORD | MutexTimeout | FUN_00465300 — Message Dispatch Node Allocator | 5191 |
| +0xAC8 | ptr | ListBase | FUN_00465300 — Message Dispatch Node Allocator | 5192 |
| +0x13EC | int | InputDeviceHandle | FUN_00465300 — Message Dispatch Node Allocator | 5242 |
| +0x10 | ptr | CleanupField1 | FUN_00465300 — Message Dispatch Node Allocator | 5266 |
| +0x128 | ptr | CleanupField2 | FUN_00465300 — Message Dispatch Node Allocator | 5267 |
| +0x4 | int | InitFlag | FUN_00465300 — Message Dispatch Node Allocator | 5292 |
| +0xD8 | int | LastActivityTick | FUN_00465300 — Message Dispatch Node Allocator | 5293 |
| +0xE8 | char | IdleCounter | FUN_00465300 — Message Dispatch Node Allocator | 5294 |
| +0x204 | ptr | LinkedListHead | FUN_00465300 — Message Dispatch Node Allocator | 5365 |
| +0xA4 | int | TableCount | FUN_00465300 — Message Dispatch Node Allocator | 5370 |
| +0xA8 | ptr | TableBase | FUN_00465300 — Message Dispatch Node Allocator | 5371 |
| +0x48 | int | RowActiveCount | FUN_00465300 — Message Dispatch Node Allocator | 5372 |
| +0x50 | int | RowValue | FUN_00465300 — Message Dispatch Node Allocator | 5373 |
| +0x38 | int | CurrentState | FUN_00465300 — Message Dispatch Node Allocator | 5426 |
| +0x144 | int | NodeCount | FUN_00465300 — Message Dispatch Node Allocator | 5457 |
| +0x148 | ptr | HeadPtr | FUN_00465300 — Message Dispatch Node Allocator | 5458 |
| +0x64 | ptr | Prev | FUN_00465300 — Message Dispatch Node Allocator | 5463 |
| +0x68 | ptr | Next | FUN_00465300 — Message Dispatch Node Allocator | 5464 |
| +0x1544 | int | ControlID | FUN_00465300 — Message Dispatch Node Allocator | 5493 |
| +0x13E8 | int | BindingValueA | FUN_00465300 — Message Dispatch Node Allocator | 5494 |
| +0x13EC | int | BindingValueB | FUN_00465300 — Message Dispatch Node Allocator | 5495 |
| +0x000 | ptr | PrimaryPtr | FUN_00465300 — Message Dispatch Node Allocator | 5527 |
| +0x224 | int | Field_0x224 | FUN_00465300 — Message Dispatch Node Allocator | 5528 |
| +0x228 | int | Field_0x228 | FUN_00465300 — Message Dispatch Node Allocator | 5529 |
| +0x22C | int | Field_0x22c | FUN_00465300 — Message Dispatch Node Allocator | 5530 |
| +0x230 | ptr | SubBufferA | FUN_00465300 — Message Dispatch Node Allocator | 5531 |
| +0x234 | int | Field_0x234 | FUN_00465300 — Message Dispatch Node Allocator | 5532 |
| +0x238 | ptr | SubBufferB | FUN_00465300 — Message Dispatch Node Allocator | 5533 |
| +0x23C | int | Field_0x23c | FUN_00465300 — Message Dispatch Node Allocator | 5534 |
| +0x240 | ptr | SubBufferC | FUN_00465300 — Message Dispatch Node Allocator | 5535 |
| +0x14 | ptr | SourceDataPtr | FUN_00465300 — Message Dispatch Node Allocator | 5600 |
| +0x24 | int | BitField | FUN_00465300 — Message Dispatch Node Allocator | 5601 |
| +0x10 | HANDLE | Win32Handle | FUN_00465300 — Message Dispatch Node Allocator | 5626 |
| +0x18 | byte | CloseEnabled | FUN_00465300 — Message Dispatch Node Allocator | 5627 |
| +0x00 | byte | DataByte | FUN_00465300 — Message Dispatch Node Allocator | 5656 |
| +0x04 | HANDLE | MutexHandle | FUN_00465300 — Message Dispatch Node Allocator | 5657 |
| +0x08 | DWORD | TimeoutMs | FUN_00465300 — Message Dispatch Node Allocator | 5658 |
| +0x04 | HANDLE | ThreadHandle | FUN_00465300 — Message Dispatch Node Allocator | 5685 |
| +0x04 | byte | SubBuffer | FUN_00465300 — Message Dispatch Node Allocator | 5744 |
| +0x10 | int | Field_0x10 | FUN_00465300 — Message Dispatch Node Allocator | 5745 |
| +0x14 | int | Field_0x14 | FUN_00465300 — Message Dispatch Node Allocator | 5746 |
| +0x18 | byte | Field_0x18 | FUN_00465300 — Message Dispatch Node Allocator | 5747 |
| +0x19 | byte | Field_0x19 | FUN_00465300 — Message Dispatch Node Allocator | 5748 |
| +0x50 | ptr | EncodingObj | FUN_00465300 — Message Dispatch Node Allocator | 5879 |
| +0x00 | ptr | PointerA | FUN_00465300 — Message Dispatch Node Allocator | 5923 |
| +0x08 | ptr | PointerC | FUN_00465300 — Message Dispatch Node Allocator | 5924 |
| +0x4C | int | Value | FUN_00465300 — Message Dispatch Node Allocator | 6073 |
| +0x50 | HANDLE | MutexHandle | FUN_00465300 — Message Dispatch Node Allocator | 6074 |
| +0x54 | DWORD | TimeoutMs | FUN_00465300 — Message Dispatch Node Allocator | 6075 |
| +0x00 | byte | unknown | FUN_00465300 — Message Dispatch Node Allocator | 6274 |
| +0x14 | int32 | unknown | FUN_00465300 — Message Dispatch Node Allocator | 6275 |
| +0x18 | int32 | unknown | FUN_00465300 — Message Dispatch Node Allocator | 6276 |
| +0x1C | int32 | unknown | FUN_00465300 — Message Dispatch Node Allocator | 6277 |
| +0x00 | int | unknown | FUN_00465300 — Message Dispatch Node Allocator | 6303 |
| +0x1100 | int | unknown | FUN_00465300 — Message Dispatch Node Allocator | 6304 |
| +0x1AC | int32 | unknown | FUN_00465300 — Message Dispatch Node Allocator | 6328 |
| +0x14 | ptr | unknown | FUN_00465300 — Message Dispatch Node Allocator | 6414 |
| +0x24 | int | unknown | FUN_00465300 — Message Dispatch Node Allocator | 6415 |
| +0x00 | ptr | unknown | FUN_00465300 — Message Dispatch Node Allocator | 6442 |
| +0x08 | byte | unknown | FUN_00465300 — Message Dispatch Node Allocator | 6443 |
| +0xD4 | HANDLE | unknown | FUN_00465300 — Message Dispatch Node Allocator | 6466 |
| +0x18 | int | unknown | FUN_00465300 — Message Dispatch Node Allocator | 6568 |
| +0x1C | ptr | unknown | FUN_00465300 — Message Dispatch Node Allocator | 6569 |
| +0x1100 | ptr | int* | FUN_00465300 — Message Dispatch Node Allocator | 6743 |
| +0x2058 | int | - | FUN_00465300 — Message Dispatch Node Allocator | 6744 |
| +0x2098 | int | - | FUN_00465300 — Message Dispatch Node Allocator | 6745 |
| +0x20D8 | int | - | FUN_00465300 — Message Dispatch Node Allocator | 6746 |
| +0x10 | int | HANDLE | FUN_00465300 — Message Dispatch Node Allocator | 6819 |
| +0x18 | byte | byte | FUN_00465300 — Message Dispatch Node Allocator | 6820 |
| +0x554 | int | HANDLE | FUN_00465300 — Message Dispatch Node Allocator | 6843 |
| +0x558 | int | DWORD | FUN_00465300 — Message Dispatch Node Allocator | 6844 |
| +0x120 | int | int | FUN_004773a0 — - Bounds Check with Position Query | 7412 |
| +0x124 | int | int | FUN_004773a0 — - Bounds Check with Position Query | 7413 |
| +0x140 | int | int | FUN_004773a0 — - Bounds Check with Position Query | 7414 |
| +0x144 | int | int | FUN_004773a0 — - Bounds Check with Position Query | 7415 |
| +0xEC | int | int | FUN_0047bae0 — - Bounded Counter Update | 7484 |
| +0x44 | int | int* | FUN_00486f30 — - Linked List Insert with Node Allocation | 7541 |
| +0x48 | int | int* | FUN_00486f30 — - Linked List Insert with Node Allocation | 7542 |
| +0x4C | int | int* | FUN_00486f30 — - Linked List Insert with Node Allocation | 7543 |
| +0x50 | int | int | FUN_00486f30 — - Linked List Insert with Node Allocation | 7544 |
| +0x31C | int | int* | FUN_0048cc20 — - Linked List Size Calc with Max Tracking | 7614 |
| +0x324 | int | int* | FUN_0048cc20 — - Linked List Size Calc with Max Tracking | 7615 |
| +0x32C | int | int | FUN_0048cc20 — - Linked List Size Calc with Max Tracking | 7616 |
| +0x330 | int | int | FUN_0048cc20 — - Linked List Size Calc with Max Tracking | 7617 |
| +0x168 | int | int | FUN_0048faf0 — - Decrement Counter with Clamp | 7651 |
| +0x178 | int | int | FUN_0048faf0 — - Decrement Counter with Clamp | 7652 |
| +0x24 | int | unknown | FUN_004a0de0 — - Function Call Wrapper | 15395 |
| +0x00 | ptr | Ptr | FUN_004a0de0 — - Function Call Wrapper | 15422 |
| +0x08 | byte | FreeFlag | FUN_004a0de0 — - Function Call Wrapper | 15423 |
| +0x50 | ptr | int* | FUN_00599232 — - Conditional Delegate Call with Null Guard | 6966 |
| +0x00 | int | ResourceResult | FUN_0059ab83 — - Object Destructor with SEH | 10076 |
| +0x440 | ptr | VTableBasePtr | FUN_0059ab83 — - Object Destructor with SEH | 10077 |
| +0x1A0 | int | ExistingResource | FUN_0059ab83 — - Object Destructor with SEH | 10082 |
| +0x80 | byte | Flags | FUN_0059ab83 — - Object Destructor with SEH | 10083 |
| +0x7C | int | FormatParam | FUN_0059ab83 — - Object Destructor with SEH | 10084 |
| +0x114 | int | OutputTransform | FUN_0059ab83 — - Object Destructor with SEH | 10118 |
| +0x1A0 | int | TransformSrc | FUN_0059ab83 — - Object Destructor with SEH | 10119 |
| +0x204 | int | TransformOffset | FUN_0059ab83 — - Object Destructor with SEH | 10120 |
| +0x1AC | int | BoundingData | FUN_0059ab83 — - Object Destructor with SEH | 10125 |
| +0x14 | int | StateFlags | FUN_0059ab83 — - Object Destructor with SEH | 10130 |
| +0xE8 | int | ContactState | FUN_0059ab83 — - Object Destructor with SEH | 10131 |
| +0x11C | ptr | CollisionData | FUN_0059ab83 — - Object Destructor with SEH | 10132 |
| +0x00 | int | Flags | FUN_0059ab83 — - Object Destructor with SEH | 10166 |
| +0x04 | int | ComputedID | FUN_0059ab83 — - Object Destructor with SEH | 10167 |
| +0x58 | char | NameBuffer | FUN_0059ab83 — - Object Destructor with SEH | 10168 |
| +0x0C | ptr | ResourceA | FUN_0059ab83 — - Object Destructor with SEH | 10192 |
| +0x1C | ptr | ResourceB | FUN_0059ab83 — - Object Destructor with SEH | 10193 |
| +0x20 | ptr | ResourceC | FUN_0059ab83 — - Object Destructor with SEH | 10194 |
| +0x22C | int | CountA | FUN_0059ab83 — - Object Destructor with SEH | 10221 |
| +0x230 | ptr | BufferA | FUN_0059ab83 — - Object Destructor with SEH | 10222 |
| +0x234 | int | CountB | FUN_0059ab83 — - Object Destructor with SEH | 10223 |
| +0x238 | ptr | BufferB | FUN_0059ab83 — - Object Destructor with SEH | 10224 |
| +0x23C | int | CountC | FUN_0059ab83 — - Object Destructor with SEH | 10225 |
| +0x240 | ptr | BufferC | FUN_0059ab83 — - Object Destructor with SEH | 10226 |
| +0xAC8 | ptr | ListHead | FUN_0059ab83 — - Object Destructor with SEH | 10274 |
| +0xACC | int | ListState | FUN_0059ab83 — - Object Destructor with SEH | 10275 |
| +0xAD8 | HANDLE | MutexHandle | FUN_0059ab83 — - Object Destructor with SEH | 10276 |
| +0xADC | DWORD | MutexTimeout | FUN_0059ab83 — - Object Destructor with SEH | 10277 |
| +0x00 | ptr | ObjectPtr | FUN_0059ab83 — - Object Destructor with SEH | 10282 |
| +0x04 | ptr | NextPtr | FUN_0059ab83 — - Object Destructor with SEH | 10283 |
| +0x08 | byte | DestructFlag | FUN_0059ab83 — - Object Destructor with SEH | 10284 |
| +0x00 | ptr | ListHead | FUN_0059ab83 — - Object Destructor with SEH | 10317 |
| +0x04 | int | ListTailOrState | FUN_0059ab83 — - Object Destructor with SEH | 10318 |
| +0x08 | int | ListCount | FUN_0059ab83 — - Object Destructor with SEH | 10319 |
| +0x00 | ptr | ObjectPtr | FUN_0059ab83 — - Object Destructor with SEH | 10324 |
| +0x04 | ptr | NextPtr | FUN_0059ab83 — - Object Destructor with SEH | 10325 |
| +0x08 | byte | DestructFlag | FUN_0059ab83 — - Object Destructor with SEH | 10326 |
| +0x64 | char | NameBuffer | FUN_0059ab83 — - Object Destructor with SEH | 10351 |
| +0x74 | byte | AssociatedFlag | FUN_0059ab83 — - Object Destructor with SEH | 10352 |
| +0x00 | ptr | BufferPtr | FUN_0059ab83 — - Object Destructor with SEH | 10381 |
| +0x04 | int | BufferCapacity | FUN_0059ab83 — - Object Destructor with SEH | 10382 |
| +0x08 | int | BufferSize | FUN_0059ab83 — - Object Destructor with SEH | 10383 |
| +0x00 | int | BufferPtr | FUN_0059ab83 — - Object Destructor with SEH | 10486 |
| +0x04 | int | DataStart | FUN_0059ab83 — - Object Destructor with SEH | 10487 |
| +0x08 | int | BufferSize | FUN_0059ab83 — - Object Destructor with SEH | 10488 |
| +0x00 | int | State | FUN_0059ab83 — - Object Destructor with SEH | 10539 |
| +0x84 | int | ResultID | FUN_0059ab83 — - Object Destructor with SEH | 10540 |
| +0x00 | ptr | DirectResourcePtr | FUN_0059ab83 — - Object Destructor with SEH | 10567 |
| +0x18 | ptr | ArrayResourcePtr | FUN_0059ab83 — - Object Destructor with SEH | 10568 |
| +0x4 | int | uint | FUN_0059ab83 — - Object Destructor with SEH | 10602 |
| +0x8 | int | int | FUN_0059ab83 — - Object Destructor with SEH | 10603 |
| +0x14 | int | int | FUN_0059ab83 — - Object Destructor with SEH | 10604 |
| +0x18 | ptr | uint** | FUN_0059ab83 — - Object Destructor with SEH | 10605 |
| +0x1C | ptr | int* | FUN_0059ab83 — - Object Destructor with SEH | 10606 |
| +0x24 | int | int* | FUN_0059ab83 — - Object Destructor with SEH | 10636 |
| +0xA4 | int | int | FUN_0059ab83 — - Object Destructor with SEH | 10637 |
| +0xA8 | int | int | FUN_0059ab83 — - Object Destructor with SEH | 10638 |
| +0x1000 | int | short | FUN_0059ab83 — - Object Destructor with SEH | 10817 |
| +0x1002 | int | short | FUN_0059ab83 — - Object Destructor with SEH | 10818 |
| +0xB00 | int | int* | FUN_0059ab83 — - Object Destructor with SEH | 10846 |
| +0xB04 | int | int* | FUN_0059ab83 — - Object Destructor with SEH | 10847 |
| +0xB08 | int | int* | FUN_0059ab83 — - Object Destructor with SEH | 10848 |
| +0xB0C | int | int* | FUN_0059ab83 — - Object Destructor with SEH | 10849 |
| +0xB10 | int | HANDLE | FUN_0059ab83 — - Object Destructor with SEH | 10850 |
| +0xB14 | int | DWORD | FUN_0059ab83 — - Object Destructor with SEH | 10851 |
| +0x0 | int | int* | FUN_0059ab83 — - Object Destructor with SEH | 10927 |
| +0x10 | int | HANDLE | FUN_0059ab83 — - Object Destructor with SEH | 10928 |
| +0x18 | byte | byte | FUN_0059ab83 — - Object Destructor with SEH | 10929 |
| +0x28 | int | int | FUN_0059ab83 — - Object Destructor with SEH | 11072 |
| +0x2C | ptr | int* | FUN_0059ab83 — - Object Destructor with SEH | 11073 |
| +0x30 | byte | byte | FUN_0059ab83 — - Object Destructor with SEH | 11074 |
| +0x20 | double | int** | FUN_0059ab83 — - Object Destructor with SEH | 11117 |
| +0x30 | double | int** | FUN_0059ab83 — - Object Destructor with SEH | 11118 |
| +0x04 | int | Flags | FUN_0059ab83 — - Object Destructor with SEH | 11299 |
| +0x10 | int | Counter/State | FUN_0059ab83 — - Object Destructor with SEH | 11300 |
| +0x5C | int | value1 | FUN_0059ab83 — - Object Destructor with SEH | 11325 |
| +0x60 | int | value2 | FUN_0059ab83 — - Object Destructor with SEH | 11326 |
| +0x440 | ptr | vtable/itemArray | FUN_0059ab83 — - Object Destructor with SEH | 11354 |
| +0x4EC | int | count | FUN_0059ab83 — - Object Destructor with SEH | 11355 |
| +0x54 | ptr | controlBlock | FUN_0059ab83 — - Object Destructor with SEH | 11360 |
| +0x1000 | int | readPos | FUN_0059ab83 — - Object Destructor with SEH | 11487 |
| +0x1002 | int | count | FUN_0059ab83 — - Object Destructor with SEH | 11488 |
| +0xB1C | ptr | listHead | FUN_0059ab83 — - Object Destructor with SEH | 11517 |
| +0xB2C | HANDLE | mutexHandle | FUN_0059ab83 — - Object Destructor with SEH | 11518 |
| +0xB30 | DWORD | mutexTimeout | FUN_0059ab83 — - Object Destructor with SEH | 11519 |
| +0x5D | byte | busyFlag | FUN_0059ab83 — - Object Destructor with SEH | 11548 |
| +0x60 | int | threshold | FUN_0059ab83 — - Object Destructor with SEH | 11549 |
| +0x54 | HANDLE | handle | FUN_0059ab83 — - Object Destructor with SEH | 11572 |
| +0x5C | byte | validFlag | FUN_0059ab83 — - Object Destructor with SEH | 11573 |
| +0x0D | byte | flags | FUN_0059ab83 — - Object Destructor with SEH | 11631 |
| +0x10 | int | dataPtr | FUN_0059ab83 — - Object Destructor with SEH | 11632 |
| +0x4 | ptr | unknown | FUN_0059ab83 — - Object Destructor with SEH | 12245 |
| +0x10 | int | unknown | FUN_0059ab83 — - Object Destructor with SEH | 12246 |
| +0x00 | int | uint | FUN_0059ab83 — - Object Destructor with SEH | 12270 |
| +0x14 | ptr | void* | FUN_0059ab83 — - Object Destructor with SEH | 12271 |
| +0x18 | ptr | void* | FUN_0059ab83 — - Object Destructor with SEH | 12272 |
| +0x000 | int | undefined4 | FUN_0059ab83 — - Object Destructor with SEH | 12295 |
| +0x1100 | int | void* | FUN_0059ab83 — - Object Destructor with SEH | 12296 |
| +0x20 | int | uint | FUN_0059ab83 — - Object Destructor with SEH | 12319 |
| +0x38 | int | undefined4 | FUN_0059ab83 — - Object Destructor with SEH | 12344 |
| +0x3C | int | undefined4 | FUN_0059ab83 — - Object Destructor with SEH | 12345 |
| +0x40 | int | undefined4 | FUN_0059ab83 — - Object Destructor with SEH | 12346 |
| +0x3C | byte | byte | FUN_0059ab83 — - Object Destructor with SEH | 12374 |
| +0x40 | ptr | int | FUN_0059ab83 — - Object Destructor with SEH | 12375 |
| +0x44 | ptr | int | FUN_0059ab83 — - Object Destructor with SEH | 12376 |
| +0x4C | ptr | int | FUN_0059ab83 — - Object Destructor with SEH | 12377 |
| +0x00 | int | int | FUN_0059ab83 — - Object Destructor with SEH | 12404 |
| +0x70 | int | int | FUN_0059ab83 — - Object Destructor with SEH | 12405 |
| +0x74 | int | int | FUN_0059ab83 — - Object Destructor with SEH | 12406 |
| +0x04 | int | int | FUN_0059ab83 — - Object Destructor with SEH | 12433 |
| +0x08 | byte | byte | FUN_0059ab83 — - Object Destructor with SEH | 12434 |
| +0x28 | byte | byte | FUN_0059ab83 — - Object Destructor with SEH | 12435 |
| +0x29 | byte | byte | FUN_0059ab83 — - Object Destructor with SEH | 12436 |
| +0x2A | byte | byte | FUN_0059ab83 — - Object Destructor with SEH | 12437 |
| +0x2B | byte | byte | FUN_0059ab83 — - Object Destructor with SEH | 12438 |
| +0x2C | byte | byte | FUN_0059ab83 — - Object Destructor with SEH | 12439 |
| +0x00 | ptr | void* | FUN_0059ab83 — - Object Destructor with SEH | 12460 |
| +0x00 | ptr | void* | FUN_0059ab83 — - Object Destructor with SEH | 12482 |
| +0x1C | int | undefined4 | FUN_0059ab83 — - Object Destructor with SEH | 12483 |
| +0x04 | int | HANDLE | FUN_0059ab83 — - Object Destructor with SEH | 12507 |
| +0x0C | byte | byte | FUN_0059ab83 — - Object Destructor with SEH | 12508 |
| +0x00 | ptr | void* | FUN_0059ab83 — - Object Destructor with SEH | 12534 |
| +0x04 | ptr | int | FUN_0059ab83 — - Object Destructor with SEH | 12535 |
| +0x08 | int | int | FUN_0059ab83 — - Object Destructor with SEH | 12536 |
| +0x0C | int | int | FUN_0059ab83 — - Object Destructor with SEH | 12537 |
| +0x00 | ptr | int* | FUN_0059ab83 — - Object Destructor with SEH | 12568 |
| +0x00 | ptr | void* | FUN_0059ab83 — - Object Destructor with SEH | 12596 |
| +0x04 | int | int | FUN_0059ab83 — - Object Destructor with SEH | 12597 |
| +0x08 | int | int | FUN_0059ab83 — - Object Destructor with SEH | 12598 |
| +0x0C | int | int | FUN_0059ab83 — - Object Destructor with SEH | 12599 |
| +0x04 | int | int | FUN_0059ab83 — - Object Destructor with SEH | 12640 |
| +0x0C | int | int | FUN_0059ab83 — - Object Destructor with SEH | 12677 |
| +0x10 | int | int | FUN_0059ab83 — - Object Destructor with SEH | 12678 |
| +0x1C | ptr | int | FUN_0059ab83 — - Object Destructor with SEH | 12679 |
| +0x20 | int | int | FUN_0059ab83 — - Object Destructor with SEH | 12680 |
| +0x2C | ptr | int | FUN_0059ab83 — - Object Destructor with SEH | 12681 |
| +0x30 | ptr | int | FUN_0059ab83 — - Object Destructor with SEH | 12682 |
| +0x38 | int | int | FUN_0059ab83 — - Object Destructor with SEH | 12683 |
| +0x3C | int | int | FUN_0059ab83 — - Object Destructor with SEH | 12684 |
| +0x40 | int | int | FUN_0059ab83 — - Object Destructor with SEH | 12685 |
| +0x44 | int | int | FUN_0059ab83 — - Object Destructor with SEH | 12686 |
| +0x48 | int | bool | FUN_0059ab83 — - Object Destructor with SEH | 12687 |
| +0x50 | ptr | int | FUN_0059ab83 — - Object Destructor with SEH | 12688 |
| +0x38 | int | int | FUN_0059ab83 — - Object Destructor with SEH | 12738 |
| +0x3C | int | int | FUN_0059ab83 — - Object Destructor with SEH | 12739 |
| +0x40 | int | int | FUN_0059ab83 — - Object Destructor with SEH | 12740 |
| +0x44 | int | int | FUN_0059ab83 — - Object Destructor with SEH | 12741 |
| +0x48 | int | bool | FUN_0059ab83 — - Object Destructor with SEH | 12742 |
| +0x50 | ptr | int | FUN_0059ab83 — - Object Destructor with SEH | 12743 |
| +0x40 | ptr | void* | FUN_0059ab83 — - Object Destructor with SEH | 12789 |
| +0x44 | ptr | void* | FUN_0059ab83 — - Object Destructor with SEH | 12790 |
| +0x48 | ptr | void* | FUN_0059ab83 — - Object Destructor with SEH | 12791 |
| +0x4C | int | int | FUN_0059ab83 — - Object Destructor with SEH | 12792 |
| +0x18 | ptr | void* | FUN_0059ab83 — - Object Destructor with SEH | 12818 |
| +0x20 | int | void* | FUN_0059ab83 — - Object Destructor with SEH | 12819 |
| +0x48 | ptr | void* | FUN_0059ab83 — - Object Destructor with SEH | 12820 |
| +0x4C | int | int | FUN_0059ab83 — - Object Destructor with SEH | 12821 |
| +0x00 | int | void* | FUN_0059ab83 — - Object Destructor with SEH | 12844 |
| +0x0C | int | void* | FUN_0059ab83 — - Object Destructor with SEH | 12845 |
| +0x20 | int | void* | FUN_0059ab83 — - Object Destructor with SEH | 12846 |
| +0x34 | int | void* | FUN_0059ab83 — - Object Destructor with SEH | 12847 |
| +0x48 | int | void* | FUN_0059ab83 — - Object Destructor with SEH | 12848 |
| +0x64 | int | void* | FUN_0059ab83 — - Object Destructor with SEH | 12873 |
| +0x414 | int | int | FUN_0059ab83 — - Object Destructor with SEH | 12874 |
| +0x65 | int | char | FUN_0059ab83 — - Object Destructor with SEH | 12902 |
| +0x66 | byte | byte | FUN_0059ab83 — - Object Destructor with SEH | 12903 |
| +0x04 | int | uint | FUN_0059ab83 — - Object Destructor with SEH | 13051 |
| +0x08 | int | uint | FUN_0059ab83 — - Object Destructor with SEH | 13052 |
| +0x10 | int | float | FUN_0059ab83 — - Object Destructor with SEH | 13053 |
| +0x1C | ptr | int* | FUN_0059ab83 — - Object Destructor with SEH | 13054 |
| +0x08 | int | undefined4 | FUN_0059ab83 — - Object Destructor with SEH | 13083 |
| +0x0C | int | undefined4 | FUN_0059ab83 — - Object Destructor with SEH | 13084 |
| +0x04 | int | undefined4 | FUN_0059ab83 — - Object Destructor with SEH | 13173 |
| +0x50 | int | undefined4 | FUN_0059ab83 — - Object Destructor with SEH | 13174 |
| +0x1EC | ptr | int* | FUN_0059ab83 — - Object Destructor with SEH | 13202 |
| +0x0C | ptr | code* | FUN_0059ab83 — - Object Destructor with SEH | 13228 |
| +0x10 | int | undefined4 | FUN_0059ab83 — - Object Destructor with SEH | 13229 |
| +0x04 | ptr | int* | FUN_0059ab83 — - Object Destructor with SEH | 13255 |
| +0x2C | int | char | FUN_0059ab83 — - Object Destructor with SEH | 13281 |
| +0x2D | byte | byte[] | FUN_0059ab83 — - Object Destructor with SEH | 13282 |
| +0x08 | ptr | int* | FUN_0059ab83 — - Object Destructor with SEH | 13341 |
| +0x04 | int | HANDLE | FUN_0059ab83 — - Object Destructor with SEH | 13380 |
| +0x0C | byte | byte | FUN_0059ab83 — - Object Destructor with SEH | 13381 |
| +0x10 | int | HANDLE | FUN_0059ab83 — - Object Destructor with SEH | 13382 |
| +0x00 | int | Initialized | FUN_0059ab83 — - Object Destructor with SEH | 14376 |
| +0x30 | int | TimerRunning | FUN_0059ab83 — - Object Destructor with SEH | 14377 |
| +0x34 | int | TimerRunning2 | FUN_0059ab83 — - Object Destructor with SEH | 14378 |
| +0x48 | byte | TimerFlags | FUN_0059ab83 — - Object Destructor with SEH | 14379 |
| +0x50 | ptr | ResourceBlk | FUN_0059ab83 — - Object Destructor with SEH | 14407 |
| +0x1C | int | SubResource1 | FUN_0059ab83 — - Object Destructor with SEH | 14408 |
| +0x24 | int | SubResource2 | FUN_0059ab83 — - Object Destructor with SEH | 14409 |
| +0x20 | int | Flags | FUN_0059ab83 — - Object Destructor with SEH | 14410 |
| +0x2C | int | StateCount | FUN_0059ab83 — - Object Destructor with SEH | 14411 |
| +0x34 | ptr | StateArray | FUN_0059ab83 — - Object Destructor with SEH | 14412 |
| +0x30 | int | Counter1 | FUN_0059ab83 — - Object Destructor with SEH | 14413 |
| +0x38 | int | Counter2 | FUN_0059ab83 — - Object Destructor with SEH | 14414 |
| +0x120 | ptr | ListHead | FUN_0059ab83 — - Object Destructor with SEH | 14442 |
| +0x20 | ptr | NextPtr | FUN_0059ab83 — - Object Destructor with SEH | 14443 |
| +0x14 | int | Field1 | FUN_0059ab83 — - Object Destructor with SEH | 14469 |
| +0x24 | int | Field2 | FUN_0059ab83 — - Object Destructor with SEH | 14470 |
| +0x34 | int | Field3 | FUN_0059ab83 — - Object Destructor with SEH | 14471 |
| +0x00 | int | Count | FUN_0059ab83 — - Object Destructor with SEH | 14492 |
| +0x14 | int | SecondaryBuf | FUN_0059ab83 — - Object Destructor with SEH | 14493 |
| +0x2C | byte | DataLength | FUN_0059ab83 — - Object Destructor with SEH | 14546 |
| +0x2D | byte | DataBuffer | FUN_0059ab83 — - Object Destructor with SEH | 14547 |
| +0x00 | ptr | VTablePtr | FUN_0059ab83 — - Object Destructor with SEH | 14588 |
| +0x1C | int | Field7 | FUN_0059ab83 — - Object Destructor with SEH | 14589 |
| +0x00 | ptr | ListHead | FUN_0059ab83 — - Object Destructor with SEH | 14618 |
| +0x04 | ptr | ListTail | FUN_0059ab83 — - Object Destructor with SEH | 14619 |
| +0x08 | ptr | ListCount | FUN_0059ab83 — - Object Destructor with SEH | 14620 |
| +0x0C | ptr | ListFlags | FUN_0059ab83 — - Object Destructor with SEH | 14621 |
| +0x00 | int | BasePtr | FUN_0059ab83 — - Object Destructor with SEH | 14653 |
| +0x04 | HANDLE | ThreadHandle | FUN_0059ab83 — - Object Destructor with SEH | 14687 |
| +0x1C | byte | SuspendFlag | FUN_0059ab83 — - Object Destructor with SEH | 14688 |
| +0x20 | HANDLE | MutexHandle | FUN_0059ab83 — - Object Destructor with SEH | 14689 |
| +0x24 | DWORD | MutexTimeout | FUN_0059ab83 — - Object Destructor with SEH | 14690 |
| +0x414 | ptr | TypeResolver | FUN_0059ab83 — - Object Destructor with SEH | 14745 |
| +0x1C | int | DispatchMode | FUN_0059ab83 — - Object Destructor with SEH | 14905 |
| +0x04 | byte | byte* | FUN_0059ab83 — - Object Destructor with SEH | 15274 |
| +0x08 | int | int | FUN_0059ab83 — - Object Destructor with SEH | 15275 |
| +0xB6C | byte | int | FUN_0059db09 — - Flag/State Setter with 3 Special-Case Values | 7020 |
| +0x00 | int | uint32 | Unwind_0059d524 — - C++ Unwind Helper Thunk | 8452 |
| +0x40 | int | float | Unwind_0059d524 — - C++ Unwind Helper Thunk | 8453 |
| +0x110 | ptr | -> +0x28 | Unwind_0059d524 — - C++ Unwind Helper Thunk | 8481 |
| +0x5C | ptr | (node) | Unwind_0059d524 — - C++ Unwind Helper Thunk | 8482 |
| +0x54 | ptr | (node) | Unwind_0059d524 — - C++ Unwind Helper Thunk | 8483 |
| +0x18 | int32 | (channel) | Unwind_0059d524 — - C++ Unwind Helper Thunk | 8484 |
| +0x38 | float | (channel) | Unwind_0059d524 — - C++ Unwind Helper Thunk | 8485 |
| +0x00 | byte | unknown | Unwind_0059d524 — - C++ Unwind Helper Thunk | 8511 |
| +0x20 | int32 | unknown | Unwind_0059d524 — - C++ Unwind Helper Thunk | 8512 |
| +0x24 | int32 | unknown | Unwind_0059d524 — - C++ Unwind Helper Thunk | 8513 |
| +0x28 | int32 | unknown | Unwind_0059d524 — - C++ Unwind Helper Thunk | 8514 |
| +0x1100 | ptr | int* | Unwind_0059d524 — - C++ Unwind Helper Thunk | 8539 |
| +0x516 | int | char[16] | Unwind_0059d524 — - C++ Unwind Helper Thunk | 8540 |
| +0x526 | int | char[16] | Unwind_0059d524 — - C++ Unwind Helper Thunk | 8541 |
| +0x536 | int | char[16] | Unwind_0059d524 — - C++ Unwind Helper Thunk | 8542 |
| +0x20 | int | HANDLE | Unwind_0059d524 — - C++ Unwind Helper Thunk | 8636 |
| +0x28 | byte | byte | Unwind_0059d524 — - C++ Unwind Helper Thunk | 8637 |
| +0x570 | int | HANDLE | Unwind_0059d524 — - C++ Unwind Helper Thunk | 8662 |
| +0x574 | int | DWORD | Unwind_0059d524 — - C++ Unwind Helper Thunk | 8663 |
| +0x24 | int | unknown | Unwind_0059d524 — - C++ Unwind Helper Thunk | 8847 |
| +0x868 | ptr | unknown | Unwind_0059d524 — - C++ Unwind Helper Thunk | 8848 |
| +0x38 | int | uint | Unwind_0059d524 — - C++ Unwind Helper Thunk | 8908 |
| +0x40 | int | int | Unwind_0059d524 — - C++ Unwind Helper Thunk | 8909 |
| +0x44 | int | int | Unwind_0059d524 — - C++ Unwind Helper Thunk | 8910 |
| +0x4C | ptr | int | Unwind_0059d524 — - C++ Unwind Helper Thunk | 8911 |
| +0x84 | int | uint | Unwind_0059d524 — - C++ Unwind Helper Thunk | 8916 |
| +0x00 | int | float | Unwind_0059d524 — - C++ Unwind Helper Thunk | 8948 |
| +0x04 | int | int | Unwind_0059d524 — - C++ Unwind Helper Thunk | 8949 |
| +0x08 | int | int | Unwind_0059d524 — - C++ Unwind Helper Thunk | 8950 |
| +0x0C | int | int | Unwind_0059d524 — - C++ Unwind Helper Thunk | 8951 |
| +0x10 | int | int | Unwind_0059d524 — - C++ Unwind Helper Thunk | 8952 |
| +0x14 | int | int | Unwind_0059d524 — - C++ Unwind Helper Thunk | 8953 |
| +0x18 | int | int* | Unwind_0059d524 — - C++ Unwind Helper Thunk | 8954 |
| +0x1C | int | int | Unwind_0059d524 — - C++ Unwind Helper Thunk | 8955 |
| +0x20 | int | int | Unwind_0059d524 — - C++ Unwind Helper Thunk | 8956 |
| +0x24 | int | int | Unwind_0059d524 — - C++ Unwind Helper Thunk | 8957 |
| +0x28 | int | int | Unwind_0059d524 — - C++ Unwind Helper Thunk | 8958 |
| +0x28 | int | int | Unwind_0059d524 — - C++ Unwind Helper Thunk | 8959 |
| +0x24 | int | int | Unwind_0059d524 — - C++ Unwind Helper Thunk | 8960 |
| +0x08 | ptr | int* | Unwind_0059d524 — - C++ Unwind Helper Thunk | 9034 |
| +0x0C | ptr | int* | Unwind_0059d524 — - C++ Unwind Helper Thunk | 9035 |
| +0x10 | int | int* | Unwind_0059d524 — - C++ Unwind Helper Thunk | 9036 |
| +0x14 | int | int | Unwind_0059d524 — - C++ Unwind Helper Thunk | 9037 |
| +0x00 | int | int | Unwind_0059d524 — - C++ Unwind Helper Thunk | 9042 |
| +0x04 | ptr | int* | Unwind_0059d524 — - C++ Unwind Helper Thunk | 9043 |
| +0x08 | byte | char | Unwind_0059d524 — - C++ Unwind Helper Thunk | 9044 |
| +0x5A8 | int | HANDLE | Unwind_0059d524 — - C++ Unwind Helper Thunk | 9099 |
| +0x5AC | int | DWORD | Unwind_0059d524 — - C++ Unwind Helper Thunk | 9100 |
| +0x50 | int | HANDLE | Unwind_0059d524 — - C++ Unwind Helper Thunk | 9127 |
| +0x54 | int | DWORD | Unwind_0059d524 — - C++ Unwind Helper Thunk | 9128 |
| +0x0C | int | int | Unwind_0059d524 — - C++ Unwind Helper Thunk | 9472 |
| +0x14 | int | int | Unwind_0059d524 — - C++ Unwind Helper Thunk | 9473 |
| +0x14 | byte | byte* | Unwind_0059d524 — - C++ Unwind Helper Thunk | 9505 |
| +0x1C | ptr | int* | Unwind_0059d524 — - C++ Unwind Helper Thunk | 9506 |
| +0x34 | int | int | Unwind_0059d524 — - C++ Unwind Helper Thunk | 9507 |
| +0xD0 | ptr | code* | Unwind_0059d524 — - C++ Unwind Helper Thunk | 9551 |
| +0x100 | int | undefined4 | Unwind_0059d524 — - C++ Unwind Helper Thunk | 9552 |
| +0x3C | byte | SkipFlags | Unwind_0059d524 — - C++ Unwind Helper Thunk | 9601 |
| +0x204 | ptr | ListHead | Unwind_0059d524 — - C++ Unwind Helper Thunk | 9602 |
| +0x00 | ptr | *param_1 | Unwind_0059d524 — - C++ Unwind Helper Thunk | 9629 |
| +0x08 | ptr | param_1[2] | Unwind_0059d524 — - C++ Unwind Helper Thunk | 9630 |
| +0x20 | int | param_1[8] | Unwind_0059d524 — - C++ Unwind Helper Thunk | 9631 |
| +0xD4 | HANDLE | MutexHandle | Unwind_0059d524 — - C++ Unwind Helper Thunk | 9671 |
| +0xD8 | DWORD | MutexTimeout | Unwind_0059d524 — - C++ Unwind Helper Thunk | 9672 |
| +0x50 | HANDLE | MutexHandle | Unwind_0059d524 — - C++ Unwind Helper Thunk | 9697 |
| +0x00 | ptr | DataPtr | Unwind_0059d524 — - C++ Unwind Helper Thunk | 9720 |
| +0x04 | int | Capacity | Unwind_0059d524 — - C++ Unwind Helper Thunk | 9721 |
| +0x08 | int | Size | Unwind_0059d524 — - C++ Unwind Helper Thunk | 9722 |
| +0xAAC | ptr | ListHead | Unwind_0059d524 — - C++ Unwind Helper Thunk | 9761 |
| +0xABC | HANDLE | MutexHandle | Unwind_0059d524 — - C++ Unwind Helper Thunk | 9762 |
| +0xAC0 | DWORD | MutexTimeout | Unwind_0059d524 — - C++ Unwind Helper Thunk | 9763 |
| +0x00 | ptr | ListHead | Unwind_0059d524 — - C++ Unwind Helper Thunk | 9794 |
| +0x04 | ptr | TailPtr | Unwind_0059d524 — - C++ Unwind Helper Thunk | 9795 |
| +0x08 | ptr | Current | Unwind_0059d524 — - C++ Unwind Helper Thunk | 9796 |
| +0x0C | int | Count | Unwind_0059d524 — - C++ Unwind Helper Thunk | 9797 |
| +0x24 | int | StateFlag | Unwind_0059d524 — - C++ Unwind Helper Thunk | 9816 |
| +0xD4 | ptr | vtable_method | Unwind_0059d524 — - C++ Unwind Helper Thunk | 9842 |
| +0x100 | ptr | DataPtr | Unwind_0059d524 — - C++ Unwind Helper Thunk | 9843 |
| +0x00 | ptr | *param_1 | Unwind_0059d524 — - C++ Unwind Helper Thunk | 9868 |
| +0x210 | int | puVar1[0x84] | Unwind_0059d524 — - C++ Unwind Helper Thunk | 9869 |
| +0x214 | int | puVar1[0x85] | Unwind_0059d524 — - C++ Unwind Helper Thunk | 9870 |

---
Total observations extracted: 523
Confidence: medium. Automated extraction with heuristic grouping. Some type guesses may be inaccurate.

---

## Source: docs/18-physics-dynamics.md

Based on 270 function entries, 435+ offset observations.

---

## RigidBodyState (inferred)

Core rigid body dynamics struct. Position, orientation, velocity, momentum. Used by 20+ functions.

Based on 25+ function observations. Confidence: high.

| Offset | Type | Field | Observed in | Notes |
|--------|------|-------|-------------|-------|
| +0x000 | double | Pad/Mass? | FUN_00448e90 | first 6 ints zeroed |
| +0x004 | double | PosX | FUN_00569a20, FUN_005694e0, FUN_00569860, FUN_0056d1c0, FUN_0043e5d0, FUN_00441d60 | World-space center of mass X |
| +0x00c | double | PosY | FUN_00569a20, FUN_005694e0, FUN_00569860, FUN_0056d1c0, FUN_0043e5d0, FUN_00441d60 | World-space center of mass Y |
| +0x014 | double | PosZ | FUN_00569a20, FUN_005694e0, FUN_00569860, FUN_0056d1c0, FUN_0043e5d0, FUN_00441d60 | World-space center of mass Z |
| +0x018 | byte | ActiveFlag | FUN_00448e90, FUN_00431390 | set to 1 when active |
| +0x019 | byte | BVType/Flags | FUN_00448e90 | bounding volume type |
| +0x01a | short | CollisionGroupID | FUN_00448e90 | 0xffff = no group |
| +0x01c | double | RotMatrix[0][0] | FUN_00569860, FUN_0056d1c0, FUN_00438930, FUN_004359a0 | Orientation matrix col0.x |
| +0x024 | double | RotMatrix[1][0] | FUN_00569860, FUN_0056d1c0 | Orientation matrix col0.y |
| +0x02c | double | RotMatrix[2][0] | FUN_00569860, FUN_0056d1c0, FUN_00438930, FUN_004359a0, FUN_00441ad0 | Orientation matrix col0.z |
| +0x034 | double | RotMatrix[0][1] | FUN_00569860, FUN_0056d1c0, FUN_00438930 | Orientation matrix col1.x |
| +0x03c | double | RotMatrix[1][1] | FUN_00569860, FUN_0056d1c0 | Orientation matrix col1.y |
| +0x044 | double | RotMatrix[2][1] | FUN_00569860, FUN_0056d1c0, FUN_00438930 | Orientation matrix col1.z |
| +0x04c | double | RotMatrix[0][2] | FUN_00569860, FUN_0056d1c0, FUN_00438930 | Orientation matrix col2.x |
| +0x054 | double | RotMatrix[1][2] | FUN_00569860, FUN_0056d1c0 | Orientation matrix col2.y |
| +0x05c | double | RotMatrix[2][2] | FUN_00569860, FUN_0056d1c0, FUN_00438930 | Orientation matrix col2.z |
| +0x060 | double | ForceAccumX0 | FUN_00441d60 | Force buffer 0 X |
| +0x064 | double | ForceAccumY0 | FUN_00441d60 | Force buffer 0 Y |
| +0x06c | double | ForceAccumZ0 / VelocityX? | FUN_00441d60, FUN_00441ad0 | Force buffer 0 Z or velocity X |
| +0x074 | double | VelocityY? | FUN_00441ad0 | Y velocity component |
| +0x07c | double | TransformResultX | FUN_005691d0, FUN_00435e00, FUN_004359a0 | Rotated vector output X |
| +0x084 | double | TransformResultY | FUN_005691d0, FUN_00435e00, FUN_004359a0 | Rotated vector output Y |
| +0x08c | double | TransformResultZ | FUN_005691d0, FUN_00435e00, FUN_004359a0 | Rotated vector output Z |
| +0x094 | double | InputVectorX | FUN_005691d0, FUN_00469410 | Input vector X component |
| +0x09c | double | InputVectorY | FUN_005691d0 | Input vector Y component |
| +0x0a4 | double | InputVectorZ | FUN_005691d0 | Input vector Z component |
| +0x0b4 | double | ScaleFactor | FUN_00569670, FUN_00569410 | Damping/time-step/scale factor |
| +0x0bc | double | DiagonalScale[0] | FUN_00438130, FUN_00569410 | Diagonal scale S0 |
| +0x0c4 | double | DiagonalScale[1] | FUN_00569410 | Diagonal scale S1 |
| +0x0cc | double | DiagonalScale[2] | FUN_00569410 | Diagonal scale S2 |
| +0x0ec | double | InertiaTensor[0][0] | FUN_00569670, FUN_005691d0 | Row 0 col 0 |
| +0x0f4 | double | InertiaTensor[0][1] | FUN_00569670, FUN_005691d0 | Row 0 col 1 |
| +0x0fc | double | InertiaTensor[0][2] | FUN_00569670, FUN_005691d0 | Row 0 col 2 |
| +0x104 | double | InertiaTensor[1][0] | FUN_00569670, FUN_005691d0 | Row 1 col 0 |
| +0x10c | double | InertiaTensor[1][1] | FUN_00569670, FUN_005691d0 | Row 1 col 1 |
| +0x114 | double | InertiaTensor[1][2] | FUN_00569670, FUN_005691d0 | Row 1 col 2 |
| +0x11c | double | InertiaTensor[2][0] | FUN_00569670, FUN_005691d0 | Row 2 col 0 |
| +0x124 | double | InertiaTensor[2][1] | FUN_00569670, FUN_005691d0 | Row 2 col 1 |
| +0x12c | double | InertiaTensor[2][2] | FUN_00569670, FUN_005691d0 | Row 2 col 2 |
| +0x134 | double | LinearMomentumAccumX | FUN_00569a20, FUN_00569ad0, FUN_00441bb0, FUN_00441d60, FUN_00438130 | Linear momentum / angular momentum X |
| +0x13c | double | LinearMomentumAccumY | FUN_00569a20, FUN_00569ad0, FUN_00441bb0, FUN_00441d60 | Linear momentum Y |
| +0x144 | double | LinearMomentumAccumZ | FUN_00569a20, FUN_00569ad0, FUN_00441bb0, FUN_00441d60 | Linear momentum Z |
| +0x14c | double | AngularMomentumAccumX | FUN_00569a20, FUN_00569ad0, FUN_0056ee40, FUN_00438930, FUN_0043ff3d, FUN_0043fffb, FUN_00441d60 | Angular momentum / cross accum X |
| +0x154 | double | AngularMomentumAccumY | FUN_00569a20, FUN_00569ad0, FUN_0056ee40, FUN_00438930, FUN_0043ff3d, FUN_00441d60 | Angular momentum / cross accum Y |
| +0x15c | double | AngularMomentumAccumZ | FUN_00569a20, FUN_00569ad0, FUN_0056ee40, FUN_00438930, FUN_0043ff3d, FUN_00441d60 | Angular momentum / cross accum Z |
| +0x22c | int | RingBufferIndex | FUN_00569860, FUN_0056A390 | Write index/counter |
| +0x230 | double* | RingBufferBase | FUN_00569860, FUN_0056A390 | Ring buffer pointer |
| +0x224 | double* | AccumulatorArray | FUN_0056A390 | Force accumulator array |
| +0x22c | int | EntityCount | FUN_0056A390 | Number of bodies/elements |

---

## VehiclePhysicsState (inferred)

Large vehicle dynamics & suspension struct. Stride 0x464 per wheel substruct. Used by 20+ functions.

Based on 20+ function observations. Confidence: high.

| Offset | Type | Field | Observed in | Notes |
|--------|------|-------|-------------|-------|
| +0x000 | int/byte | ActiveFlag | FUN_00431390 | Set to 1 on init |
| +0x004 | byte | ActiveFlag | FUN_004f8370, FUN_00434450 | Set to 1 on init |
| +0x008 | int | Mode/Magic | FUN_00434450 | Config init |
| +0x00c | int | DataPtr | FUN_0040ef70 | Target data struct pointer |
| +0x010 | float | ResultFloat | FUN_0040ef70 | Stored result |
| +0x014 | float | InitFlag | FUN_00434450 | Config init |
| +0x018 | int | Sentinel/-1 | FUN_00434450, FUN_00434860 | Config init (0xffffffff) |
| +0x01c | int | Mode | FUN_0040ef70, FUN_0040f550, FUN_00434450, FUN_00434860 | Processing mode 0-5 |
| +0x020 | float | MaxForce? | FUN_00434450, FUN_00434860 | Config default 2.0f |
| +0x024 | float | MaxForce2? | FUN_00434450 | Config default 2.0f |
| +0x028 | int | Reserved | FUN_00434450 | Set to 0 |
| +0x02c | int | Reserved2 | FUN_00434450, FUN_00432810 | Config init |
| +0x030 | float | FrictionCoeff | FUN_00434450, FUN_00434860 | Config default 3.25f |
| +0x034 | int | Reserved3 | FUN_00434450, FUN_00434860 | Config init |
| +0x038 | double | SomeValue | FUN_00431850 | Suspension model intermediate |
| +0x060 | double | InputAngle | FUN_00447ab0 | Table lookup input |
| +0x064 | double | MomentumAccumX | FUN_00569670 | Linear momentum accumulator |
| +0x06c | double | MomentumAccumY | FUN_00569670 | Linear momentum accumulator |
| +0x074 | double | MomentumAccumZ | FUN_00569670 | Linear momentum accumulator |
| +0x078 | int | VehicleIndex | FUN_00438130 | Index in vehicle array |
| +0x094 | double | Counter/State | FUN_004f8370 | Reset to 0 on init |
| +0x0a8 | float | StoredValue | FUN_004fefc0 | Clamped value |
| +0x0ac | float | Reciprocal | FUN_004fefc0 | 1/value for fast multiply |
| +0x0b0 | float | Reciprocal2 | FUN_004fefc0 | Second reciprocal |
| +0x0b4 | int | (varies) | FUN_0040ef70 | Mode 0-5 processing |
| +0x0bc | double | DampingCoeff | FUN_00438130 | Velocity-based damping |
| +0x0d4 | float | DirX | FUN_004e3090 | Normalised direction X |
| +0x0e0 | float | DirZ | FUN_004e3090 | Normalised direction Z |
| +0x124 | float | PosY | FUN_004e3090 | World position Y |
| +0x134 | double | — | FUN_00441360 | Position/velocity component |
| +0x13c | double | — | FUN_00441360 | Position/velocity component |
| +0x144 | double | — | FUN_00441360 | Position/velocity component |
| +0x14c | double | SpringCoeff | FUN_00438130, FUN_00441360 | Spring/damper coefficient |
| +0x154 | double | — | FUN_00441360 | Position/velocity component |
| +0x15c | double | SubstructPtr | FUN_00438130, FUN_00441360 | Pointer to substruct (or double) |
| +0x19c | double | IntegrationFlag | FUN_00447b10, FUN_0041d60, FUN_00438130 | 0 = step pending |
| +0x1c59 | byte | DisableFlag | FUN_00447b10, FUN_00447270 | 0 = disabled |
| +0x234 | double | — | FUN_00438130 | Unnamed double |
| +0x268 | double | SpringForce2 | FUN_00438130 | Spring force |
| +0x270 | double | — | FUN_00438130 | Unnamed double |
| +0x278 | double | — | FUN_00438130 | Unnamed double |
| +0x288 | double | — | FUN_00438130 | Unnamed double |
| +0x314 | double | — | FUN_00438130 | Unnamed double |
| +0x31c | double | SpringForce1 | FUN_00438130 | Spring force |
| +0x324 | double | DampingCoeff2 | FUN_00438130 | Velocity-based damping |
| +0x334 | double | ForceRatio1 | FUN_00438130 | Convergence computation |
| +0x33c | double | — | FUN_00438130 | Unnamed double |
| +0x344 | double | — | FUN_00438130 | Unnamed double |
| +0x34c-0x36c | double[6] | ForceAccumulator | FUN_00438130 | 6-slot force accumulator |
| +0x354 | double | — | FUN_00438130 | Unnamed double |
| +0x35c | double | — | FUN_00438130 | Unnamed double |
| +0x364 | double | FactorA | FUN_00438100 | Multiplication factor A |
| +0x368 | double | SpringDisplacement | FUN_0043fffb | Per wheel |
| +0x36c | double | FactorB | FUN_00438100 | Multiplication factor B |
| +0x374 | double | Product | FUN_00438100, FUN_00438130 | Force product result |
| +0x37c | double | — | FUN_00438130 | Unnamed double |
| +0x38c | double | Multiplier | FUN_00438100 | Force multiplier |
| +0x394 | double | EnergyThreshold | FUN_00438130 | Energy/clamp check |
| +0x398 | double | — | FUN_00438130 | Unnamed double |
| +0x39c | double | DampingTorqueOut | FUN_00438130 | Final damping torque |
| +0x3a4 | double | DampingCoeff3 | FUN_00438130 | Velocity-based damping |
| +0x3ac | double | — | FUN_00438130 | Unnamed double |
| +0x3b4 | double | — | FUN_00438130 | Unnamed double |
| +0x3bc | double | — | FUN_00438130 | Unnamed double |
| +0x3c4 | double | — | FUN_00438130 | Unnamed double |
| +0x3cc | double | — | FUN_00438130 | Unnamed double |
| +0x44c | double | — | FUN_00438130 | Unnamed double |
| +0x454 | double | — | FUN_00438130 | Unnamed double |
| +0x660 | double | MaxTravel | FUN_0043fffb, FUN_0043ff3d | Per wheel max travel |
| +0x6c4 | int | ListHead | FUN_00465460 | Master entity list head |
| +0x72 | byte | BrakeFlags[11] | FUN_00438cc0 | Brake/diff settings |
| +0x80 | int | ModeFlags | FUN_00438cc0 | From DAT_007ce874/88c |
| +0x84c | int* | WheelHubPtr | FUN_0043fffb | Wheel hub struct ptr (4 wheels) |
| +0x900 | double | — | FUN_00438130 | Unnamed high offset |
| +0xcb0 | int* | WheelHubPtrAlt | FUN_0043fffb, FUN_00430750 | Wheel hub struct ptr alt |
| +0x1114 | int* | WheelHubPtrAlt2 | FUN_0043fffb | Wheel hub struct ptr alt2 |
| +0x141c | int* | WheelHubContact | FUN_0043fffb, FUN_0043ba20, FUN_0043ec80 | Wheel hub contact struct |
| +0x1420 | double | BiasTerm | FUN_0043ba20, FUN_0043bb00 | Time bias for constraint |
| +0x1428 | double | StateValue | FUN_0043ba20, FUN_0043bb00 | Current state value |
| +0x1430 | double | DeltaGain | FUN_0043bb00 | Delta gain factor |
| +0x15ac | int | BodyCount | FUN_00441d60 | Number of bodies |
| +0x15b0 | double* | BodyArray | FUN_00441d60 | Body array pointer, stride 0x244 |
| +0x15c4 | int | ConstraintCount | FUN_0043ba20 | Constraint count |
| +0x15c8 | int* | ConstraintArray | FUN_0043ba20 | Constraint array, stride 0x48 |
| +0x15f0 | int* | BodyPtr | FUN_0043fffb, FUN_0043ba20, FUN_0043e5d0, FUN_00447100, FUN_0043e6a0, FUN_0041d60, FUN_0041bb0, FUN_0046fd0, FUN_0043e4b0 | Main rigid body pointer |
| +0x15fc | double | WorldOriginX | FUN_00446fd0, FUN_0043e4b0 | Rotation matrix column 0 / world origin X |
| +0x1604 | double | WorldOriginY | FUN_00446fd0, FUN_0043e4b0 | Rotation matrix column 1 / world origin Y |
| +0x160c | double | WorldOriginZ | FUN_00446fd0, FUN_0043e4b0 | Rotation matrix column 2 / world origin Z |
| +0x17d8 | double | DamperState1 | FUN_0043eae0 | Accumulated damper displacement |
| +0x17f0 | double | DamperState2 | FUN_0043eae0 | Accumulated damper velocity |
| +0x1808 | double | SpringState1 | FUN_0043e980 | Updated and clamped |
| +0x1818 | double | SpringState2 | FUN_0043e980 | Updated and clamped |
| +0x19a4 | byte | ResetCounter | FUN_00431390 | Set to 0 on init |
| +0x1bc0 | double | Accumulator | FUN_0043ea70 | Scalar accumulator |
| +0x1c00 | double | SpringOutput | FUN_0043e890, FUN_0043bb30 | Result passed to callback |
| +0x1c08 | double | DamperMin1 | FUN_0043e890 | Lower bound for damper 1 |
| +0x1c10 | double | DamperMin2 | FUN_0043e890, FUN_0043ff3d | Lower bound for damper 2 / Compliance |
| +0x1c18 | double | PtrToFunc/Input | FUN_0043e980, FUN_0043bbd0 | Input value / callback arg |
| +0x1c20 | double | SpringLower1 | FUN_0043e980 | Lower bound for state1 |
| +0x1c28 | double | SpringLower2 | FUN_0043e980 | Lower bound for state2 |
| +0x1c30 | double | LowerBound | FUN_0043ea70 | Lower bound for clamp |
| +0x1c38 | double | Input | FUN_0043bb80 | Input value stored |
| +0x1c3c | double | Input2 | FUN_0043bb80 | Input value 2 |
| +0x1c40 | double | ClampLower | FUN_0043eae0 | Clamp lower bound |
| +0x1c48 | double | ClampLower2 | FUN_0043eae0 | Clamp lower bound 2 |
| +0x1c5c | double | AccumulatedFriction | FUN_0043ff3d, FUN_00412f0, FUN_0043fffb | Suspension travel / friction accum |
| +0x1c64 | float | CurSuspDisp | FUN_00412f0 | Current suspension displacement |
| +0x1c74 | double | SecondaryStiffness | FUN_0043fffb | Secondary stiffness |
| +0x1ca8 | int[] | JointTargetArray | FUN_004317f0, FUN_00431390 | Joint target positions / indexed params |
| +0x1cb4 | double | Threshold | FUN_004313c0 | Threshold value |
| +0x1cb8 | byte | DirtyFlag | FUN_00431a50 | Set to 1 when modified |
| +0x1cbc | double | StoredValue | FUN_00431a50 | Stored value |
| +0x1cc0 | byte[] | ConstraintActive | FUN_00431930 | Per-index active flag |
| +0x1cc4 | uint[] | ConstraintValue | FUN_00431930 | Per-index coefficient |
| +0x1cd4 | byte[] | ParamFlags | FUN_004319c0 | Per-parameter dirty flags |
| +0x1cd8 | int[] | ParamValues | FUN_004319c0 | Per-parameter values |
| +0x1ce8 | byte[] | RowActiveFlag | FUN_00431a70 | Per-row active flags |
| +0x1d4c | double | (OilTemp?) | FUN_00438130 | From wear/damage domain |
| +0x1db4 | double | EffectiveLifetime | FUN_00447280 | Driver effectiveness at spawn |
| +0x1e14 | int | SuspensionConfig | FUN_0043fffb, FUN_0043ff3d, FUN_0043af0 | Mode 0/1/2 |
| +0x1e18 | double | Compliance | FUN_0043fffb | Suspension compliance |
| +0x1e20 | double | ReboundDamping | FUN_0043fffb | Rebound damping factor |
| +0x1e28 | double | BumpDamping | FUN_0043fffb | Bump damping factor |
| +0x1e30 | double | FrictionOffset | FUN_0043fffb | Friction offset |
| +0x1e38 | double | SuspensionTravel | FUN_0043fffb, FUN_0043ff3d, FUN_00412f0 | Accumulated suspension travel / lambda |
| +0x1e3c | float | PrevWheelVel | FUN_00412f0 | Previous wheel velocity |
| +0x1e40 | float | CurWheelVel | FUN_00412f0 | Current wheel velocity |
| +0x1e50 | double | AntiRollBarStiffness | FUN_0043fffb, FUN_0043ff3d | Anti-roll bar stiffness / EffectiveMass |
| +0x1ea4 | double | MotionRatioComp | FUN_0043fffb, FUN_0043ff3d | Motion ratio compensator / ERP coeff |
| +0x1f00 | int* | VehicleDataPtr | FUN_0041ad0 | Points to vehicle data (indirection) |
| +0x1f04 | double | ForceAccumX1 | FUN_0043e5d0, FUN_00441d60 | Force buffer 1 X |
| +0x1f0c | double | ForceAccumY1 | FUN_0043e5d0, FUN_00441d60 | Force buffer 1 Y |
| +0x1f14 | double | ForceAccumZ1 | FUN_0043e5d0, FUN_00441d60 | Force buffer 1 Z |
| +0x1f1c | double | ImpulseAccumX1 | FUN_0043e5d0, FUN_00441d60 | Impulse buffer 1 X |
| +0x1f24 | double | ImpulseAccumY1 | FUN_0043e5d0, FUN_00441d60 | Impulse buffer 1 Y |
| +0x1f2c | double | ImpulseAccumZ1 | FUN_0043e5d0, FUN_00441d60 | Impulse buffer 1 Z |
| +0x3b40 | int | SetupIndex | FUN_004af3a0 | Setup index 0-3 |
| +0x3b80..+0x3ff0 | float[] | SetupParams | FUN_004af3a0 | Tire/suspension/brake params |
| +0x3a8 | int[] | ConstraintFlags | FUN_0043e4b0 | Per-constraint flags (stride 0x119) |
| +0x402c | float[] | WheelParams | FUN_004af3a0 | Per-wheel array, 9 ints each |

---

## WheelCornerStruct (per-wheel, stride 0x464)

Per-wheel vehicle substruct. Used by suspension, brake, tire force computation.

Based on 10+ function observations. Confidence: high.

| Offset | Type | Field | Observed in | Notes |
|--------|------|-------|-------------|-------|
| +0x000 | float[3] | Position | FUN_004e3aa0 | Wheel position |
| +0x006 | float[3] | Velocity | FUN_004e3aa0 | Wheel velocity |
| +0x00c | float[3] | ForceDir | FUN_004e3aa0 | Force direction in contact frame |
| +0x011 | float | SlipForce | FUN_004e3aa0 | Computed slip force |
| +0x01d | float | ContactLoad | FUN_004e3aa0 | Normal load |
| +0x01e | float[2] | FrictionParams | FUN_004e3aa0 | Friction coefficients |
| +0x024 | float | SuspensionDefl | FUN_004e3aa0 | Suspension deflection |
| +0x033 | float[3] | ContactForce | FUN_004e3aa0 | Output contact force |
| +0x039 | float[4] | SuspensionParams | FUN_004e3aa0 | Suspension parameters |
| +0x0c4 | int | TireInstanceId | FUN_00430750 | Index for tire data lookup |
| +0xc30 | double | LongSlipBias | FUN_00430750 | Longitudinal slip bias |
| +0xc38 | double | LongSlipScale | FUN_00430750 | Longitudinal slip scaling |
| +0xc44 | int | LongSlipFactor | FUN_00430750 | Additional slip factor |
| +0xcb0/cb8/cc4 | double[3] | Load | FUN_00430750 | Tire load (bias/scale/factor) |
| +0x348 | double | DamperForce | FUN_0043fffb, FUN_0043ff3d | Per wheel (stride 0x464) |
| +0x360 | double | SpringForce | FUN_0043fffb, FUN_0043ff3d | Per wheel (stride 0x464) |
| +0x7ac | double | HubForceContrib | FUN_0043fffb | Per wheel hub force |
| +0xc10 | double | ExtraSpringForce | FUN_0043fffb | Additional spring force |
| +0xc28 | double | GeomLeverageRatio | FUN_0043fffb, FUN_0043ff3d | Geometry leverage |
| +0xc30 | double | GeomLeverageAlt | FUN_0043fffb | Alternate geometry leverage |
| +0x1074 | double | ExtraDamperForce | FUN_0043fffb | Additional damper force |
| +0x108c | double | GeomLeverageRatio2 | FUN_0043fffb | Geometry leverage ratio 2 |
| +0x119 | int | WheelSubID | FUN_0043e230 | Wheel substructure ID |

---

## BodyStateArray (stride 0x244)

Array of body states for multi-body physics.

Based on 3+ function observations. Confidence: medium.

| Offset | Type | Field | Observed in | Notes |
|--------|------|-------|-------------|-------|
| +0x04 | double | PosX | FUN_0056d1c0 | Body position |
| +0x0c | double | PosY | FUN_0056d1c0 | Body position |
| +0x14 | double | PosZ | FUN_0056d1c0 | Body position |
| +0x1c | double | Rot00 | FUN_0056d1c0 | Rotation matrix element |
| +0x24 | double | Rot01 | FUN_0056d1c0 | Rotation matrix element |
| +0x2c | double | Rot02 | FUN_0056d1c0 | Rotation matrix element |
| +0x34 | double | Rot10 | FUN_0056d1c0 | Rotation matrix element |
| +0x3c | double | Rot11 | FUN_0056d1c0 | Rotation matrix element |
| +0x44 | double | Rot12 | FUN_0056d1c0 | Rotation matrix element |
| +0x4c | double | Rot20 | FUN_0056d1c0 | Rotation matrix element |
| +0x54 | double | Rot21 | FUN_0056d1c0 | Rotation matrix element |
| +0x5c | double | Rot22 | FUN_0056d1c0 | Rotation matrix element |
| +0x60 | double | PosDeltaX | FUN_0041ad0, FUN_0041d60 | Position offset |
| +0x64 | double | PosDeltaY | FUN_0041ad0, FUN_0041d60 | Position offset |
| +0x6c | double | PosDeltaZ | FUN_0041ad0, FUN_0041d60 | Position offset / angular vel X |
| +0x74 | double | AngularVelY | FUN_0041ad0 | Angular velocity Y |
| +0x7c | double | AngularVelZ | FUN_0041ad0 | Angular velocity Z |
| +0x134 | double | AngMomX | FUN_0041d60 | Angular momentum X |
| +0x13c | double | AngMomY | FUN_0041d60 | Angular momentum Y |
| +0x144 | double | AngMomZ | FUN_0041d60 | Angular momentum Z |
| +0x14c | double | ForceX | FUN_0041d60 | Force accumulation X |
| +0x154 | double | ForceY | FUN_0041d60 | Force accumulation Y |
| +0x15c | double | ForceZ | FUN_0041d60 | Force accumulation Z |
| Stride: 0x244 (580 bytes) | | | FUN_0041d60 | Per-body state |

---

## ConstraintGroupStruct (param_1 for FUN_0056ee40)

Constraint solver group descriptor.

Based on 1 function observation (FUN_0056ee40). Confidence: medium.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x08 | int | Group1Count | Body count for group 1 |
| +0x0c | int* | Group1Array | Body index array |
| +0x10 | int | Group2Count | Pair count for group 2 |
| +0x14 | int* | Group2Array | Pair array |
| +0x18 | int | Group3Count | Body count for group 3 |
| +0x1c | int* | Group3Array | Body array |
| +0x2c | double* | GlobalPosArray | Double-precision position array |

---

## ConstraintEntryStruct (stride 0x48)

Per-constraint entry in constraint array.

Based on 1 function observation (FUN_0043ba20). Confidence: medium.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x04 | int | BodyA_ID | First body identifier |
| +0x08 | int* | ForcePtrA | Force pointer for body A |
| +0x0c | int | BodyB_ID | Second body identifier |
| +0x10 | int* | ForcePtrB | Force pointer for body B |
| Stride: 0x48 | | | |

---

## ConstraintSolverParamStruct (from FUN_00434860)

Constraint solver parameter struct.

Based on 2 function observations. Confidence: medium.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x00 | byte | Flag0 | 0 |
| +0x01 | byte | Enabled | 1 = enabled |
| +0x02 | byte | Flag2 | 0 |
| +0x04 | int | ParamI0 | 0 |
| +0x08 | int | ParamI1 | 0 |
| +0x0c | int | ParamI2 | 0 |
| +0x10 | float | AngleLimit1 | 90.0f |
| +0x14 | float | AngleLimit2 | 75.0f |
| +0x18 | int | Sentinel | 0xffffffff (-1) |
| +0x1c | int | ParamI3 | 0 |
| +0x20 | int | ParamI4 | 0 |
| +0x24 | float | MaxForce | 2.0f |
| +0x28 | int | ParamI5 | 0 |
| +0x2c | int | ParamI6 | 0 |
| +0x30 | float | FrictionCoeff | 3.25f |
| +0x34 | int | ParamI7 | 0 |

---

## BVH/TreeNode (0x60 bytes)

Spatial partitioning tree node for broadphase collision.

Based on 6+ function observations. Confidence: high.

| Offset | Type | Field | Observed in | Notes |
|--------|------|-------|-------------|-------|
| +0x00 | float | SplitX | FUN_004485d0 | X partition boundary |
| +0x04 | byte[8] | Pad1 | FUN_004485d0 | 8 bytes padding |
| +0x0c | float | SplitY | FUN_004485d0 | Y partition boundary |
| +0x10 | double | DoubleKey | FUN_004485d0, FUN_00448de0 | Unique key for exact match / accumulator |
| +0x04 | double | LocalValue | FUN_00448de0 | Node's local contribution |
| +0x48 | int | LinearIndex | FUN_004486e0 | Assigned DFS index |
| +0x4c | int* | Child[0] | FUN_004486e0, FUN_004485d0, FUN_00448da0, FUN_00448e50, FUN_004486a0, FUN_00448de0 | Child node pointer 0 |
| +0x50 | int* | Child[1] | Same set | Child node pointer 1 |
| +0x54 | int* | Child[2] | Same set | Child node pointer 2 |
| +0x58 | int* | Child[3] | Same set | Child node pointer 3 |
| +0x5c | int* | NextSibling | Same set | Overflow/sibling pointer |

---

## ContactPairStruct (stride 0x20)

Contact pair entry.

Based on 2+ function observations. Confidence: medium.

| Offset | Type | Field | Observed in | Notes |
|--------|------|-------|-------------|-------|
| +0x00 | int | ContactType | FUN_00449700 | Contact type/flag |
| +0x04 | int | BodyA | FUN_00449700 | First body ID |
| +0x08 | int | BodyB | FUN_00449700 | Second body ID |
| +0x0c | int | BodyC | FUN_00449700 | Third body ID |
| +0x10 | int | BodyVelocity | FUN_00449700 | Body velocity field |
| +0x14 | int | BodyVelocityB | FUN_00449700 | Body velocity field |
| +0x18 | int | Reserved | FUN_00449700 | |
| +0x1c | int | NextPtr | FUN_004496d0 | Linked list next |
| Stride: 0x20 (32 bytes) | | | FUN_00449700, FUN_004496d0 | |

---

## CollisionContactBufferStruct

Contact buffer management.

Based on 2 function observations. Confidence: medium.

| Offset | Type | Field | Observed in | Notes |
|--------|------|-------|-------------|-------|
| +0x00 | int | ElementCount | FUN_004492d0 | Count of elements |
| +0x04 | int | AllocatedCount | FUN_004492d0 | Allocated capacity |
| +0x08 | void* | BufferPtr | FUN_004492d0 | Pointer to first element |

---

## QuadFunctionCoeffs (spring/damper quadratic)

Coefficient set for quadratic spring/damper force computation.

Based on 5+ function observations (FUN_0043bb30, FUN_0043bb80, FUN_0043bbd0, FUN_0043e890, FUN_0043e980). Confidence: high.

| Offset | Type | Field | Observed in | Notes |
|--------|------|-------|-------------|-------|
| +0x17a8 | double | CoeffSetA[0] | FUN_0043bb30, FUN_0043e890 | Damper coeff set A (x0) |
| +0x17b0 | double | CoeffSetA[1] | FUN_0043bb30, FUN_0043e890 | Damper coeff set A (x1) |
| +0x17b8 | double | CoeffSetA[2] | FUN_0043bb30, FUN_0043e890 | Damper coeff set A (x2) |
| +0x17c0 | double | CoeffSetB[0] | FUN_0043bb30, FUN_0043e890 | Damper coeff set B (x0) |
| +0x17c8 | double | CoeffSetB[1] | FUN_0043bb30, FUN_0043e890 | Damper coeff set B (x1) |
| +0x17d0 | double | CoeffSetB[2] | FUN_0043bb30, FUN_0043e890 | Damper coeff set B (x2) |
| +0x17d8 | double | ConstTerm0 | FUN_0043bb80 | Quadratic constant A |
| +0x17e0 | double | LinearTerm0 | FUN_0043bb80 | Quadratic coefficient A |
| +0x17e8 | double | QuadTerm0 | FUN_0043bb80 | Quadratic coefficient A |
| +0x17f0 | double | ConstTerm1 | FUN_0043bb80 | Quadratic constant B |
| +0x17f8 | double | LinearTerm1 | FUN_0043bb80 | Quadratic coefficient B |
| +0x1800 | double | QuadTerm1 | FUN_0043bb80 | Quadratic coefficient B |
| +0x1808 | double | RestForceX | FUN_0043bbd0 | Spring rest force X |
| +0x1810 | double | StiffnessX | FUN_0043bbd0 | Spring stiffness X |
| +0x1818 | double | RestForceY | FUN_0043bbd0, FUN_0043e980 | Spring rest force Y |
| +0x1820 | double | StiffnessY | FUN_0043bbd0 | Spring stiffness Y |
| +0x1828 | double | RestForceZ | FUN_0043bbd0 | Spring rest force Z |
| +0x1830 | double | StiffnessZ | FUN_0043bbd0 | Spring stiffness Z |
| +0x1930 | double | ResultA | FUN_0043bb30 | Computed output A |
| +0x19e8 | double | ResultB | FUN_0043bb30 | Computed output B |
| +0x1a0c | double | Result0 | FUN_0043bb80 | Computed output 0 |
| +0x1abc | double | Result1 | FUN_0043bb80 | Computed output 1 |
| +0x1adc | double | ForceY | FUN_0043bbd0 | Output Y force |
| +0x1b94 | double | ForceX | FUN_0043bbd0 | Output X force |
| +0x1d9c | double | ForceZ | FUN_0043bbd0 | Output Z force |

---

## WheelStateArray (stride 0x464, 4 wheels)

Per-wheel state array for suspension/velocity history.

Based on 3+ function observations (FUN_00412f0, FUN_00413e230, FUN_0041ad0). Confidence: medium.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x338 | float[0x119] | WheelStates | Per-wheel state array |
| +0x1c5c-0x1c68 | float | SuspHistory | Suspension displacement history (prev/cur pairs) |
| +0x1e38-0x1e44 | float | VelHistory | Wheel velocity history (prev/cur pairs) |
| Stride: 0x464 (4 wheels × 0x119 × 4 = per wheel stride) | | | |

---

## VehicleWheelDataStruct (stride 0x3e/0x4a)

From FUN_004EE2D0 vehicle dynamics update.

Based on 1 function observation. Confidence: low.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x32bc | int | PhysicsMode | 0=suspension, 1=brake, 2=tire, 3=replay |
| +0x34ac | float | RotationAngle | Vehicle rotation |
| +0x34b0-0x34e0 | float[9] | RotationMatrix | 3x3 rotation matrix |
| +0x34d4-0x34dc | float[3] | PositionOffset | Translation vector |
| +0x34ec-0x34f4 | float[3] | LocalPosition | Local space position |
| +0x34f8-0x3500 | float[3] | LocalOffset | Additional offset |
| +0x3590 | float[] | WheelData[4] | Per-wheel data stride 0x3e |
| +0x3668 | int | ContactCount | Number of contacts |
| +0x36c4 | float | ContactActive | Contact active flag |
| +0x3760 | int | WheelCount | Number of wheels |
| +0x3be8-0x3bf0 | float[3] | SurfaceNormal | Track surface normal |
| +0x3d54-0x3d5c | float[3] | ContactPos | Track contact point |
| +0x6e4 | ? | SuspensionData | Suspension state |
| +0x77c | ? | TireDataStart | Tire slip data |
| +0x7d4 | float[] | BrakeData[4] | Per-wheel brake stride 0x4a |
| +0x8cc-0xc44 | float[4] | TireWearChannels | 4 tire wear values stride 0x128 |
| +0x1070 | byte | ActiveFlag | Active flag |

---

## VehicleControllerStruct (AI/player controller state)

From FUN_00425670, FUN_004e3090. Confidence: high.

| Offset | Type | Field | Observed in | Notes |
|--------|------|-------|-------------|-------|
| +0x70 | int | ActiveFlag | FUN_004e3090 | Must be non-zero |
| +0x74 | float | PosX | FUN_004e3090 | World position X |
| +0x78 | float | PosZ | FUN_004e3090 | World position Z |
| +0xb0 | byte | Enabled | FUN_004e3090 | Enable byte |
| +0xd4 | float | DirX | FUN_004e3090 | Normalised direction X |
| +0xe0 | float | DirZ | FUN_004e3090 | Normalised direction Z |
| +0x11c | int | PointCount | FUN_004e3090 | Number of interpolation points |
| +0x120 | int* | PointArray | FUN_004e3090 | Point array stride 0x20 |
| +0x124 | float | PosY | FUN_004e3090 | World position Y |
| +0x34e0 | float | posX | FUN_00425670 | Current world X |
| +0x34e4 | float | posY | FUN_00425670 | Current world Y |
| +0x34e8 | float | posZ | FUN_00425670 | Current world Z |
| +0x34f0 | float | heading | FUN_00425670 | Current heading angle |
| +0x34f8 | float | velX | FUN_00425670 | Velocity X |
| +0x3500 | float | velZ | FUN_00425670 | Velocity Z |
| +0x39fc | int | aiSubState | FUN_00425670 | AI sub-state counter |
| +0x4354 | int* | targetPtr | FUN_00425670 | Target waypoint pointer |
| +0x4440 | float | speedThreshold2 | FUN_00425670 | Secondary speed check |
| +0x446c | int | headingTimer | FUN_00425670 | Heading deviation timer |
| +0x4470 | float[3] | lastTargetPos | FUN_00425670 | Cached target position |
| +0x447c | float | currentSpeed | FUN_00425670 | Current speed |
| +0x4510 | int | steerState | FUN_00425670, FUN_00426330 | 1=search, 6=track, 7=arrived / current gear |
| +0x4558 | float | headingTimeout | FUN_00425670 | Max heading deviation time |

---

## VehicleGearShiftStruct

From FUN_00426330. Confidence: medium.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x37cc | float | LeftWheelSpeed | Left wheel speed |
| +0x38c4 | float | RightWheelSpeed | Right wheel speed |
| +0x39a0 | float | EngineRPM | Engine RPM |
| +0x39fc | int | ShiftTimer | Gear shift state / timer |
| +0x3a04 | int | NextGearThreshold | Next gear shift threshold |
| +0x3a10 | float | EngineSpeed | Engine speed (vs zero threshold) |
| +0x3a18 | float | RPMShiftThreshold | RPM shift threshold |
| +0x3d6c | int | DrivingMode | Driving mode (2=specifiic) |
| +0x4510 | int | CurrentGear | Current gear (6=highest) |

---

## PhysicsInteractionState (steering/force feedback)

From FUN_004e2760. Confidence: low.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x108 | int[4] | WheelIndices | Stride 0x4a (74 bytes) |
| +0x938 | int | PackedWheelData | Base-256 packed |
| +0x93c | short | PackedShort | Base-16 packed |
| +0x93e | byte | PackedByte | Base-8/base-4 packed |
| +0x93f | byte | ChannelMask | Active channel bitmask |
| +0x940 | int | ChannelBitfield | Active channels |
| +0x944 | short | ChannelOut0 | 16-bit output channel 0 |
| +0x946 | short | ChannelOut1 | 16-bit output channel 1 |
| +0x948 | short | ChannelOut2 | 16-bit output channel 2 |
| +0x98c | int | ActiveFlag | Zero = clear all outputs |
| +0x9a8 | float[] | AnalogChannels | Up to 17 channels, stride 7 floats |

---

## EntityGridManagerStruct

From FUN_00465460. Confidence: medium.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x6c | int* | ListHead | Master entity list head |
| +0x74 | int* | ListCurrent | Traversal cursor |
| +0x7c | int* | AltListHead | Secondary list head |
| +0x84 | int* | AltListCur | Secondary cursor |
| +0x2b4 | short | BudgetRemaining | Per-vehicle budget carry-over (stride 0x230) |
| +0x2b6 | byte | EntityTypeFilter | Per-vehicle type check |
| +0x2b8 | int* | EntityPtrs | Per-slot entity pointers |
| +0xe410 | int[32] | EntityTypeMap | Per-slot entity type filter |
| +0xe5b0 | int* | ActiveListHead | Active processing list |
| +0xe5b4 | int* | ActiveListTail | Tail |
| +0xe5b8 | int* | ActiveListIter | Iterator |
| +0xe5bc | int | ActiveListCount | Count |
| +0xe5c0 | int* | WorkListHead | Pending-entity work list |
| +0xe5c4 | int* | WorkListTail | Tail for append |
| +0xe5c8 | int* | WorkListIter | Iterator |
| +0xe5cc | int | WorkListCount | Entity count |

---

## SuspensionDamperCoeffs (coeff array used by multiple functions)

From FUN_00436470 (quadratic spring). Confidence: medium.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x04 | double | BiasA | Bias for channel A |
| +0x0c | double | LinearA | Linear coefficient A |
| +0x14 | double | QuadA | Quadratic coefficient A |
| +0x1c | double | BiasB | Bias for channel B |
| +0x24 | double | LinearB | Linear coefficient B |
| +0x2c | double | QuadB | Quadratic coefficient B |
| +0x34 | double | ResultA | Output result A |
| +0x3c | double | ResultB | Output result B |

---

## PhysicsConfigStruct (from FUN_00434450)

Default physics config values.

Based on 2 function observations. Confidence: medium.

| Offset | Type | Default | Field |
|--------|------|---------|-------|
| +0x00 | byte | 0 | Flag0 |
| +0x01 | byte | 1 | Enabled |
| +0x02 | byte | 0 | Flag2 |
| +0x04 | int | 0 | ParamI0 |
| +0x08 | int | 0 | ParamI1 |
| +0x0c | int | 0 | ParamI2 |
| +0x10 | float | 90.0 | AngleLimit1 |
| +0x14 | float | 75.0 | AngleLimit2 |
| +0x18 | int | -1 | Sentinel |
| +0x1c | int | 0 | ParamI3 |
| +0x20 | int | 0 | ParamI4 |
| +0x24 | float | 2.0 | MaxForce |
| +0x28 | int | 0 | ParamI5 |
| +0x2c | int | 0 | ParamI6 |
| +0x30 | float | 3.25 | FrictionCoeff |
| +0x34 | int | 0 | ParamI7 |

---

## DeltaUpdateTrackerStruct

From FUN_0043bb00. Confidence: medium.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0xd4c | double | CumulativeDelta | Accumulated delta |
| +0x1428 | double | CurrentValue | Current state value |
| +0x1430 | double | DeltaGain | Gain factor for delta tracking |

---

## PhysicsQueryStruct

From FUN_00583790. Confidence: medium.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x0c | byte | ReadyFlag | 0 = no data ready |
| +0x10 | double | ReferenceValue | Base reference |
| +0x18 | double | DeltaValue | Delta/adjustment |
| +0x20 | byte[] | DataBuffer | Variable-length data |
| +0x120 | int | DataCount | Number of entries |

---

## SparseParamArray

From FUN_004319c0, FUN_00431a70. Confidence: medium.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x1cd4 | byte[] | ParamFlags | Per-parameter dirty flags |
| +0x1cd8 | int[] | ParamValues | Per-parameter values |
| +0x1ce8 | byte[] | RowActiveFlags | Per-row active flags |
| +0x000 | int[3] | GridBase | 3-wide grid (4-byte elements) |

---

## WheelForceArrayStruct

From FUN_004e3aa0. Confidence: low.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x00..2 | float[3] | Position | Wheel position |
| +0x06..8 | float[3] | Velocity | Wheel velocity |
| +0x0e..10 | float[3] | ForceDir | Force direction in contact frame |
| +0x11 | float | SlipForce | Computed slip force |
| +0x1d | float | ContactLoad | Normal load |
| +0x1e..1f | float[2] | FrictionParams | Friction coefficients |
| +0x24 | float | SuspensionDefl | Suspension deflection |
| +0x33..35 | float[3] | ContactForce | Output contact force |
| +0x39..3c | float[4] | SuspensionParams | Suspension parameters |

---

## PerElementForceScalingStruct

From FUN_0059d9d7. Confidence: low.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x39d4 | float* | ForceArrayBase | Base of per-element force array |
| +0x39f8 | int | ElementCount | Number of elements to process |
| +0x3a0c | float | LocalForceMultiplier | Per-instance scaling factor |

---

## AudioSceneUpdateStruct

From FUN_004532d0. Confidence: low.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0xd80 | int | SceneEntryCount | Number of scene entries |

---

## ForceIntegratorStruct (FUN_00438130 + FUN_00438100 overlap)

From FUN_00438100, FUN_00438130. Confidence: medium.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x364 | double | FactorA | Multiplication factor A |
| +0x36c | double | FactorB | Multiplication factor B |
| +0x374 | double | Product | Computed product |
| +0x38c | double | Multiplier | Force multiplier |
| +0x384 (900) | double | BiasTerm | Addition bias |

---

## ConstraintEnforceStruct

From FUN_004380b0. Confidence: medium.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x1e8 | double | DispX | Displacement X |
| +0x1f0 | double | DispY | Displacement Y |
| +0x1f8 | double | RestPosX | Rest position X |
| +0x204 | double | Distance | Computed distance |

---

## EnergyAccumulationStruct

From FUN_004390a0. Confidence: medium.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x138 | double[4] | WheelEnergy | Per wheel, stride 0x58 |
| +0xdf0 | double[3] | FrontEnergyParams | Front energy parameters |
| +0xe30 | double[3] | RearEnergyParams | Rear energy parameters |
| +0x1270 | double[3] | ChassisEnergyParams | Chassis energy parameters |
| +0x12b0 | double[3] | SecondaryEnergyParams | Secondary component |
| +0x12f0 | double[3] | FrontCombinedParams | Combined front params |
| +0x1330 | double[3] | RearCombinedParams | Combined rear params |

---

## SuspensionCopyStruct (FUN_0043bc20 setup copy)

From FUN_0043bc20. Confidence: low.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x1900 | double | FlagType | Copy from template +0x1ec |
| +0x1910 | float | SetupValue1 | Copy from template +0x1f0 |
| +0x1914 | float | SetupValue2 | Copy from template +500 |
| +0x1938 | float | SetupValue3 | Copy from template +0x228 |
| +0x193c | float | SetupValue4 | Copy from template +0x22c |
| +0x1940 | float | SetupValue5 | Copy from template +0x230 |
| +0x1944 | float | SetupValue6 | Copy from template +0x234 |
| +0x1960 | float[36] | SpringDamperMatrix | 6x6 symmetric matrix |
| +0x19f0 | float[6] | BiasVector | 6-element bias |
| +0x17a8 | float[6*4] | HubPositions | 6 hub XYZ positions + extra |
| +0x17c0 | float[6*4] | PatchPositions | 6 contact patch positions |
| +0x1c08-0x1c14 | float[6*4] | MirroredPositions | Mirrored hub/patch data |
| +0x1a08 | flag | DampingFlag | Flag for damping curves |
| +0x1a14/0x1a18 | float | BumpRebound | Bump/rebound rates |
| +0x1a34 | float[36] | DampingMatrix | 6x6 damping matrix |
| +0x1ac4 | float[6] | DampingBias | Damping bias vector |
| +0x17d8-0x1804 | float[12] | TravelLimits | 6x2 values per wheel |
| +0x1828-0x1834 | float[6] | WheelMassInertia | Wheel mass/inertia |
| +0x1ae4-0x1af8 | float[6] | InertiaMatrix | 6x6 inertia matrix |
| +0x1b14-0x1ba4 | float[36] | ComplianceMatrix | 6x6 compliance matrix |
| +0x1808 | float | SpringPreloadToe | Scaled spring preload + toe offset |
| +0x1810/0x1814 | float | CamberToe | Camber/toe angles |
| +0x1818 | float | ScaledCaster | Scaled caster angle |
| +0x1820/0x1824 | float | CasterAngles | Additional caster values |
| +0x1bbc-0x1be4 | float[8] | AntiRollBarParams | Anti-roll bar stiffness and travel |

---

## CollisionShapeStruct (0x20 bytes)

From FUN_00448e90, FUN_00492b0. Confidence: medium.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x00 | int | Field0 | Zeroed init |
| +0x04 | int | Field1 | Zeroed init |
| +0x08 | int | Field2 | Zeroed init (FUN_00492b0) |
| +0x0c | int | Field3 | Zeroed init (FUN_00492b0) |
| +0x10 | int | Field4 | Zeroed init (FUN_00492b0) |
| +0x14 | int | Field5 | Clear in FUN_00433090 |
| +0x18 | byte | ActiveFlag | Set to 1 |
| +0x19 | byte | BVType | Bounding volume type |
| +0x1a | short | CollisionGroup | 0xffff = none |

---

## VectorPositionStruct (0x20 stride, interpolation points)

From FUN_004e3090. Confidence: medium.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x00 | float | SrcX | Source coordinate X |
| +0x04 | float | SrcY | Source coordinate Y |
| +0x08 | float | SrcZ | Source coordinate Z |
| +0x0c | float | TgtX | Target coordinate X |
| +0x10 | float | TgtY | Target coordinate Y |
| +0x14 | float | TgtZ | Target coordinate Z |
| +0x18 | float | Factor | Interpolation factor |
| +0x1c | float* | OutputPtr | Output pointer |
| Stride: 0x20 (32 bytes) | | | |

---

## TraversalBoundStruct

From FUN_00443af0. Confidence: low.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x1e14 | int | TraversalMode | 1 or 2 |
| +0x3d0 | double | BoundA | First bound |
| +0x834 | double | BoundB | Second bound |
| +0xc98 | double | BoundC | Third bound |
| +0x10fc | double | BoundD | Fourth bound |

---

## Source: docs/10-vehicle-physics.md

# Struct Offset Synthesis — Worker E

Source: `docs/10-vehicle-physics.md` (80 entries, 257 offset observations)

---

## VehiclePhysicsHeader (inferred)

Based on 8 function observations. Confidence: high.

Main vehicle physics instance struct (param_1). Contains pointers to sub-structs,
physics body references, wheel arrays, suspension/steering linkage systems,
aero data, and center-of-mass parameters.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | unknown | (header start) | FUN_00439210, FUN_00430f00, FUN_0042f470, FUN_0042fd00 | Base of vehicle physics struct |
| +0x04 | unknown | (unknown) | FUN_0042f470 | Near UnitName string ptr |
| +0x08 | (ptr) | GearEnableFlag | FUN_0042f470, FUN_0042fd00 | Per-gear enable flag at +0x08 within gear slot (stride 0x40) |
| +0x18 | char* | SpeedUnit | FUN_0042f470 | Unit string (e.g. "kph") |
| +0x28 | char* | UnitName | FUN_0042f470 | Unit string (e.g. "mm", "deg") |
| +0x58 | char* | CarName/SetupName | FUN_0042f470 | Display name string |
| +0x68 | char* | Notes | FUN_0042fd00 | Driver notes string |
| +0x84 | double | SteeringRatioReduction | FUN_0043b590 | |
| +0x8c | double | SteeringRatio | FUN_0043b590 | 1.0/travel if travel>0 |
| +0x94 | double | MaxSteeringAngle | FUN_0043b590 | Radians |
| +0xa4 | int | SteeringFlags1 | FUN_0043b590 | |
| +0xa8 | int | SteeringFlags2 | FUN_0043b590 | |
| +0xbb0 | struct[] | SetupParamArray | FUN_0042f470 | Array of 64-byte setup parameter entries |
| +0xbc4 | int | TireCompoundSetting | FUN_0042fd00 | |
| +0xc04 | int | CGRightSetting | FUN_0042fd00 | |
| +0xc44 | int | CGRearSetting | FUN_0042fd00 | |
| +0xc84 | int | WedgeSetting | FUN_0042fd00 | |
| +0xcc4 | int | FuelSetting | FUN_0042fd00 | Also brake bias split from FUN_004e5f60 |
| +0xd04 | int | AntiSwaySetting | FUN_0042fd00 | Front anti-sway bar |
| +0xd44 | int | ToeInLeftSetting | FUN_0042fd00 | |
| +0xd84 | int | ToeInRightSetting | FUN_0042fd00 | |
| +0xdc4 | int | (Suspension param) | FUN_0042fd00 | |
| +0xe04 | int | LeftFenderFlareSetting | FUN_0042fd00 | |
| +0xe44 | int | RightFenderFlareSetting | FUN_0042fd00 | |
| +0xe84 | int | CasterLeftSetting | FUN_0042fd00 | |
| +0xec4 | int | CasterRightSetting | FUN_0042fd00 | |
| +0xf04 | int | TrackBarLeftSetting | FUN_0042fd00 | |
| +0xf44 | int | TrackBarRightSetting | FUN_0042fd00 | |
| +0xf84 | int | Front3rdSpringSetting | FUN_0042fd00 | |
| +0xfc4 | int | FrontPackerSetting | FUN_0042fd00 | |
| +0x1004 | int | FrontBumpSetting | FUN_0042fd00 | |
| +0x1044 | int | FrontReboundSetting | FUN_0042fd00 | |
| +0x1084 | int | Rear3rdSpringSetting | FUN_0042fd00 | |
| +0x10c4 | int | RearPackerSetting | FUN_0042fd00 | |
| +0x1104 | int | RearBumpSetting | FUN_0042fd00 | |
| +0x1144 | int | RearReboundSetting | FUN_0042fd00 | |
| +0x1184 | int | (Susp param) | FUN_0042fd00 | |
| +0x11c4 | int | (Susp param) | FUN_0042fd00 | |
| +0x1204 | int | (Susp param) | FUN_0042fd00 | |
| +0x1244 | int | (Susp param) | FUN_0042fd00 | |
| +0x1284 | int | FWSetting | FUN_0042fd00 | Front wing setting |
| +0x12c4 | int | RWSetting | FUN_0042fd00 | Rear wing setting |
| +0x1304 | int | RadiatorSetting | FUN_0042fd00 | |
| +0x1344 | int | BrakeDuctSetting | FUN_0042fd00 | |
| +0x1384 | int | RearBrakeSetting | FUN_0042fd00 | |
| +0x13c4 | int | BrakePressureSetting | FUN_0042fd00 | |
| +0x1404 | int | HandbrakePressSetting | FUN_0042fd00 | |
| +0x141c | (ptr) | AttachedBodyPtr / RearAxlePtr | FUN_00439210, FUN_00438da0, FUN_0043f7f0, FUN_00442060 | Attached aero body / rear axle / alternate force target |
| +0x1428 | unknown | AeroDataStart | FUN_00439210 | Aero data region |
| +0x1430 | unknown | AeroDataEnd | FUN_00439210 | |
| +0x1444 | int | SteerLockSetting | FUN_0042fd00 | |
| +0x1448 | double | FrontAeroDownforce | FUN_00439210 | |
| +0x1450 | double | RearAeroDownforce | FUN_00439210 | |
| +0x1484 | int | DiffPumpSetting | FUN_0042fd00 | |
| +0x14c4 | int | DiffPowerSetting | FUN_0042fd00 | |
| +0x1504 | int | DiffCoastSetting | FUN_0042fd00 | |
| +0x1544 | int | DiffPreloadSetting | FUN_0042fd00 | |
| +0x1564 | double | ComputedBrakeBias | FUN_00447d00 | bias = index * slope + intercept |
| +0x156c | double | BrakeBiasIntercept | FUN_00447d00 | |
| +0x1574 | double | BrakeBiasSlope | FUN_00447d00 | |
| +0x157c | int | BrakeBiasMaxIndex | FUN_00447d00 | |
| +0x1580 | int | BrakeBiasCurrentIndex | FUN_00447d00 | |
| +0x1584 | int | RevLimitSetting | FUN_0042fd00 | |
| +0x15ac | int | SuspBodyCount | FUN_00439210, FUN_00438da0 | Number of suspension bodies |
| +0x15b0 | (ptr) | SuspBodyArray | FUN_00439210 | Array of suspension body structs |
| +0x15b4 | int | SuspLinkCount | FUN_00439210 | Suspension link count (stride 0x30) |
| +0x15b8 | (ptr) | SuspLinkArray | FUN_00439210 | |
| +0x15bc | int | SteeringLinkCount | FUN_00439210, FUN_00442060 | Steering link count (stride 0x48) |
| +0x15c0 | (ptr) | SteeringLinkArray | FUN_00439210, FUN_00442060 | Points to suspension component array |
| +0x15c4 | int | SteeringBarCount | FUN_00439210 | Steering bar count (stride 0x48) |
| +0x15c8 | (ptr) | SteeringBarArray | FUN_00439210, FUN_0043b590 | |
| +0x15c4 | int | RevLimitSetting | FUN_0042fd00 | **duplicate offset?** +0x1584 confirmed, 0x15c4 unconfirmed |
| +0x15c4 | int | EngineMapSetting | FUN_0042fd00 | Conflicts: also used as EngineMapSetting in setup write |
| +0x15f0 | (ptr) | MainBodyPtr | FUN_00439210, FUN_00438da0 | Also WheelForceTarget in FUN_0043f7f0 — consistent as physics body accumulator |
| +0x15f4 | double | TotalMass | FUN_00439210 | |
| +0x15fc | double[3] | CenterOfMass | FUN_00439210 | 3 doubles |
| +0x1604 | int | EngineBrakeMapSetting | FUN_0042fd00 | |
| +0x1614 | double[3] | CoGOffset | FUN_00439210 | 3 doubles |
| +0x162c | (ptr) | SuspBodyAllocPtr | FUN_00438da0 | Allocated suspension body array |
| +0x1630 | (ptr) | LeftRackPosPtr | FUN_00438da0, FUN_0043b590 | fl_steering body ptr |
| +0x1634 | double | LeftSteeringAxis_X | FUN_0043b590 | Double pair |
| +0x1638 | double | LeftSteeringAxis_Y | FUN_0043b590 | |
| +0x163c | double | LeftScrubRadius | FUN_0043b590 | Camber gain / scrub radius |
| +0x1644 | (ptr) | RightRackPosPtr | FUN_00438da0, FUN_0043b590 | fr_steering body ptr |
| +0x1648 | double | RightSteeringAxis_X | FUN_0043b590 | Double pair |
| +0x164c | double | RightSteeringAxis_Y | FUN_0043b590 | |
| +0x1650 | double | RightScrubRadius | FUN_0043b590 | |
| +0x16c4 | struct[8] | GearSettings | FUN_0042fd00 | 8 entries × 0x40 = 0x200 bytes, each: +0x08=enable flag |
| +0x1884 | int | GearCount / NumPitstops | FUN_0042f470, FUN_0042fd00 | GearCount in formatter, NumPitstopsSetting in writer — potential field reuse |
| +0x18c4 | int | Pitstop1Setting | FUN_0042fd00 | |
| +0x1904 | int | Pitstop2Setting | FUN_0042fd00 | |
| +0x1944 | int | Pitstop3Setting | FUN_0042fd00 | |
| +0x1980 | int | GearCounter2 | FUN_0042f470 | Bevel ratio compute |
| +0x1984 | int | GearCounter1 | FUN_0042f470 | Bevel ratio compute |
| +0x1989 | byte | AutoSetupFlag | FUN_0042f470 | Controls case 5-6 display |
| +0x198c | int | SetupFlagsBitmask | FUN_0042f470 | bit0=auto, bit1=gear mode, bit2=bevel ratio |
| +0x19a4 | byte | CustomFlag | FUN_0042fd00 | Custom setup flag |
| +0x19a5 | byte | SymmetricFlag | FUN_0042fd00 | |
| +0x19a6 | char[] | FormatBufferLower | FUN_00430f00 | Display buffer region |
| +0x1b26 | char[] | FormatBufferMain | FUN_00430f00 | Display buffer region |
| +0x1c26 | char[] | FormatBufferEnd | FUN_00430f00 | End of display buffer region |
| +0x1c5c | float | WheelVelocity | FUN_0043f7f0 | Suspension velocity state |
| +0x1c84 | float | SuspensionRef | FUN_004471f0 | Reference suspension compression |
| +0x1ca8 | float | DownforceRating | FUN_0042fd00 | BASIC section |
| +0x1cac | float | BalanceRating | FUN_0042fd00 | BASIC section |
| +0x1cb0 | float | RideRating | FUN_0042fd00 | BASIC section |
| +0x1cb4 | float | GearingRating | FUN_0042fd00 | BASIC section |
| +0x1cd8 | float[] | SetupFloatValues | FUN_004319e0 | Indexed by param_2 × 4 |
| +0x1cfc | (ptr) | SpringCurveTable | FUN_0043f7f0 | Pointer to (x,y) float table for non-linear springs |
| +0x1d00 | float | SpringForce | FUN_0043f7f0 | Interpolated spring force |
| +0x1d04 | float | DamperForce | FUN_0043f7f0 | Interpolated damper force |
| +0x1d10 | float | VibrationOutput | FUN_004471f0 | Random vibration force result |
| +0x1d4 | (ptr) | FuelTankBodyPtr | FUN_00439210, FUN_00438da0 | Physics body for fuel tank — **low offset, possibly early struct field** |
| +0x1db4 | double | EffectiveLifetimeAtSpawn | FUN_004ee150, docs/13 | Engine wear parameter |
| +0x1dbc | double | LifetimeEngineRPM_min | docs/13 | |
| +0x1dc4 | double | 1/LifetimeEngineRPM_max | docs/13 | Reciprocal stored |
| +0x1dcc | double | LifetimeOilTemp_min | docs/13 | |
| +0x1dd4 | double | 1/LifetimeOilTemp_max | docs/13 | Reciprocal stored |
| +0x1dfc | double[3] | ReferencePosition | FUN_00439210 | 3 doubles, world space |
| +0x1e0 | double | AccumulatedSteeringAngle | FUN_00442060 | Cumulative steering angle for damage detection |
| +0x1e14 | int | SolverMode | FUN_0043f7f0 | 0=2wheel, 1=4wheel, 2=2wheel_alt |
| +0x1e18 | float | SpringStiffness | FUN_0043f7f0 | Spring rate |
| +0x1e20 | float | DampingRebound | FUN_0043f7f0 | Rebound damping coefficient |
| +0x1e28 | float | DampingBump | FUN_0043f7f0 | Bump/compression damping coefficient |
| +0x1e30 | float | BiasForce | FUN_0043f7f0 | Preload/bias force |
| +0x1e38 | float | WheelDeflection | FUN_0043f7f0 | Current suspension position |
| +0x1e50 | float | BiasState | FUN_0043f7f0 | Accumulated bias/integral term |
| +0x1e58 | float | ForceScale | FUN_0043f7f0 | Overall force scaling factor |
| +0x1ef0 | int | SolverErrorFlag | FUN_0043f7f0 | Constraint failure flag |
| +0x1e8 | (ptr) | DriverHeadPtr | FUN_00438da0 | Driver head physics body |
| +0x1f00 | (ptr) | VehicleDataPtr | FUN_00439210, FUN_00447c70 | Pointer to extended vehicle data |
| +0x25b | byte | RespawnFlag | FUN_004e0800 | |
| +0x25d | byte | ClearFlag | FUN_004e0800 | |
| +0x263 | byte | DamageAnimFlag | FUN_004e0800 | |
| +0x32bc | int | CollisionEnabled | FUN_004efa40, FUN_004efae0 | 0=no collision |
| +0x3448 | float | FuelConsumptionRate | FUN_004ad2d0 | |
| +0x3450 | int | CurrentGear | FUN_0049ba30 | |
| +0x34f8 | float | RefCoeffX | FUN_00423ca0 | Reference vector X for force projection |
| +0x3500 | float | RefCoeffY | FUN_00423ca0 | Reference vector Y for force projection |
| +0x358c | float[] | WheelCorrectedValues | FUN_004e5f60 | Stride 0xf8, per-corner corrected state |
| +0x35ac | float[] | PerCornerForce | FUN_004e5f60 | Stride 0x3e, per-corner tire force output |
| +0x3674 | float[4] | ChassisLoadMatrix | FUN_004e5f60 | 4-corner weight distribution |
| +0x3784 | float | BrakeForce_FL | FUN_004e5f60 | Per-corner brake force |
| +0x3960 | float | PrimaryInertia | FUN_004e5f60 | Engine/transmission primary inertia |
| +0x3970 | int | TireNameIndex | FUN_004f1630 | Index for tire name lookup |
| +0x3974 | float | HeaveStiffness | FUN_004e5f60 | Heave/roll stiffness |
| +0x3984 | float | RemainingFuelWeight | FUN_004ad2d0, FUN_004f15da | |
| +0x398c | float | FuelMass | FUN_0049ba50 | |
| +0x3994 | float | CurrentHeight | FUN_004efa40 | Current ride height |
| +0x399c | float | TargetHeight | FUN_004efa40 | Target ride height |
| +0x39a0 | float | Speed | FUN_0049b8d0, FUN_0049d070 | Vehicle speed |
| +0x39b8 | float | RandomBump | FUN_004efa40 | Random bump offset |
| +0x39f8 | float | LapThreshold | FUN_004f15da | Lap completion threshold |
| +0x3a30 | float | FrontWingDownforce | FUN_004e5f60 | Front wing downforce |
| +0x3a44 | float | RearWingDownforce | FUN_004e5f60 | Rear wing downforce |
| +0x3ab8 | float[3] | SuspPosition[0] | FUN_004e5f60 | Final suspension position 1 (stride 0xc) |
| +0x3ac0 | float[3] | SuspPosition[1] | FUN_004e5f60 | Final suspension position 2 (stride 0xc) |
| +0x3bf4 | int | (unknown) | FUN_004f15da | Set after lap threshold |
| +0x3d64 | float[4] | EngineFailureTime | FUN_004ee150 | 4 cylinders, failure time per cylinder |
| +0x3d64 | float | TireWearAccumulator | FUN_004efae0 | **same offset?** — may be union/overlap or different struct |
| +0x3ec | (ptr) | FLWheelPtr | FUN_00439210, FUN_00438da0, FUN_0043b590 | Left front wheel suspension data |
| +0x4020 | int | RandomSeed | FUN_004e5f60 | rand() output |
| +0x4024 | float | RollPitchTorque | FUN_004e5f60 | |
| +0x403c | int | SeasonPoints | FUN_004ad2d0 | Current race points |
| +0x4040 | int | FuelUsed | FUN_004ad2d0 | Fuel consumed so far |
| +0x4058 | int | QualifyingPosition | FUN_004ad2d0 | |
| +0x4060 | int | FinishPosition | FUN_004ad2d0 | |
| +0x4064 | int | FinishState | FUN_0049bab0, FUN_004a6db0 | 0=running, 1=finished, 2=DNF, 3=DSQ |
| +0x4068 | int | ReasonCode | FUN_00442060 | Damage reason code (4=steering) |
| +0x4070 | int | PitStateFlag | FUN_0049ba90 | >0 = in pit |
| +0x4108 | int | VehicleFlag | FUN_0049bb20 | |
| +0x4354 | int | AIStateFlags | FUN_004e5f60 | Overtaking zone flags |
| +0x4438 | (ptr) | AIFollowTarget | FUN_004e5f60 | |
| +0x445c | float | AIGapToAhead | FUN_004e5f60 | |
| +0x454c | float | AISpeedDelta | FUN_004e5f60 | |
| +0x4620 | char[] | DriverName | FUN_004e5f60 | |
| +0x4678 | char[] | VehicleDescription | FUN_004e5f60 | |
| +0x4894 | int | TeamID | FUN_004e5f60 | |
| +0x489c | int | DriverNumber | FUN_004e5f60 | |
| +0x48c0 | - | StructSize | FUN_004b5c50 | Total stride, 104 entries |

---

## PhysicsBody (inferred)

Based on 1 function observation (FUN_00439210). Confidence: medium.

Rigid body struct referenced by pointers in VehiclePhysicsHeader (at +0x1d4, +0x15f0, +0x141c).

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | unknown | (vtable/type) | FUN_00439210 | |
| +0x04 | double[3] | Position | FUN_00439210 | x, y, z world position |
| +0x1c | double[3×3] | OrientationMatrix | FUN_00439210 | 3×3 rotation matrix (9 doubles, 0x1c-0x5c) |
| +0xac | double | Mass | FUN_00439210 | Body mass |
| +0xb4 | double | InvMass | FUN_00439210 | 1.0 / mass |
| +0xbc | double[3] | InertiaDiagonal | FUN_00439210 | Principal inertia terms |

---

## PhysicsSystemHeader (inferred)

Based on 1 function observation (FUN_0056d930). Confidence: high.

Top-level physics system/joint struct managed by solver. Contains counts and arrays for bodies, joints, hinges, bars.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | int | BodyCount | FUN_0056d930 | |
| +0x04 | (ptr) | BodyArray | FUN_0056d930 | Stride 0x244 |
| +0x08 | int | JointCount | FUN_0056d930 | |
| +0x0c | (ptr) | JointArray | FUN_0056d930 | Stride 0x30 |
| +0x10 | int | HingeCount | FUN_0056d930 | |
| +0x14 | (ptr) | HingeArray | FUN_0056d930 | Stride 0x30 |
| +0x18 | int | BarCount | FUN_0056d930 | |
| +0x1c | (ptr) | BarArray | FUN_0056d930 | Stride 0x48 |
| +0x20 | int | ConstraintCount | FUN_0056d930 | |
| +0x24 | (ptr) | ConstraintMatrix | FUN_0056d930 | |
| +0x28 | (ptr) | ConstraintRowStride | FUN_0056d930 | |
| +0x2c | (ptr) | SolverObject | FUN_0056d930 | |

---

## PhysicsBody (solver system) (inferred)

Inside BodyArray (stride 0x244) from FUN_0056d930.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | char* | NameString | FUN_0056d930 | |
| +0x04 | double[4] | PositionQuaternion | FUN_0056d930 | 4 doubles (pos + quaternion) |
| +0x1c | double[4] | OrientationQuat | FUN_0056d930 | Continuation? |
| +0x20 | double[3] | InertiaDiagonal | FUN_0056d930 | Principal inertia |
| +0x34 | double[3] | InertiaOffDiagonal | FUN_0056d930 | Products of inertia |
| +0x38 | double[3] | InertiaOffDiag2 | FUN_0056d930 | |
| +0x48 | double[3] | TransformMatrixRaw | FUN_0056d930 | |
| +0x4c | double[4×4] | TransformMatrix | FUN_0056d930 | 4×4 transform |
| +0x224 | (ptr) | AuxDataPtr | FUN_0056d930 | Per-body auxiliary pointer |
| +0x228 | (ptr) | BodyDataPtr | FUN_0056d930 | Per-body data pointer |
| +0x22c | int | JointRefCount | FUN_0056d930 | Number of joints referencing this body |
| +0x234 | int | HingeRefCount | FUN_0056d930 | Number of hinges referencing this body |
| +0x23c | int | BarRefCount | FUN_0056d930 | Number of bars referencing this body |

---

## JointHingeBarStruct (inferred)

Inside JointArray/HingeArray (stride 0x30) from FUN_0056d930.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | char* | NameString | FUN_0056d930 | |
| +0x04 | (ptr) | NegBodyPtr | FUN_0056d930 | Negative body reference |
| +0x08 | double | DerivedSpring1 | FUN_0056d930 | Computed spring/tension value |
| +0x0c | (ptr) | PosBodyPtr | FUN_0056d930 | Positive body reference |
| +0x10 | double | DerivedSpring2 | FUN_0056d930 | Computed spring/tension value |
| +0x14 | double[6] | PositionOrientation | FUN_0056d930 | 6 doubles |
| +0x2c | int | LinkCounter | FUN_0056d930 | Joint index |
| +0x30 | - | StructStride | FUN_0056d930 | 0x30 |

---

## BarStruct (inferred)

Inside BarArray (stride 0x48) from FUN_0056d930. Extends JointHingeBarStruct with spring/damper params.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | char* | NameString | FUN_0056d930 | Same header as joint/hinge |
| +0x04 | (ptr) | NegBodyPtr | FUN_0056d930 | |
| +0x08 | double | DerivedSpring1 | FUN_0056d930 | |
| +0x0c | (ptr) | PosBodyPtr | FUN_0056d930 | |
| +0x10 | double | DerivedSpring2 | FUN_0056d930 | |
| +0x14 | double[6] | PositionOrientation | FUN_0056d930 | |
| +0x2c | int | LinkCounter | FUN_0056d930 | |
| +0x30 | (extra) | SpringDamperParams | FUN_0056d930 | Additional 0x18 bytes of spring/damper data |
| +0x48 | - | StructStride | FUN_0056d930 | 0x48 |

---

## PerWheelPhysics (inferred)

Based on 2 function observations (FUN_0043da10, FUN_0043f7f0). Confidence: high.

Per-wheel physics sub-struct accessed as wheel_index × 0x464 from base pointer.
Tire compound data is at wheel_base + 0x28c within this struct.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x28c | struct | TireCompoundData | FUN_0043da10 | Tire physics params offset within wheel |
| +0x348 | double | Position | FUN_0043f7f0 | Wheel position |
| +0x360 | float | Force | FUN_0043f7f0 | |
| +0x368 | int | ConstraintState | FUN_0043f7f0 | |
| +0x7ac | float | Force2 | FUN_0043f7f0 | |
| +0x7c4 | float | Inertia | FUN_0043f7f0 | |
| +0xc10 | float | Velocity | FUN_0043f7f0 | |
| +0xc28 | float | Mass | FUN_0043f7f0 | |
| +0xc30 | float | Inertia2 | FUN_0043f7f0 | |
| +0x1074 | float | Bias | FUN_0043f7f0 | |
| +0x108c | float | Bias2 | FUN_0043f7f0 | |
| +0x464 | - | WheelStructStride | - | Full wheel struct size |

---

## PerWheelTireCompound (inferred)

Based on 1 function observation (FUN_0043da10). Confidence: high.

Located at wheel_base + 0x28c within per-wheel physics struct.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | unknown | compound[0] | FUN_0043da10 | Tire width source |
| +0x08 | unknown | compound[1] | FUN_0043da10 | Tire width 2 source |
| +0x08 | float | TireRadiusMax | FUN_0043da10 | From compound +0x08 |
| +0x20c | float | GripParam1 | FUN_0043da10 | From compound +0x24 |
| +0x210 | float | GripParam2 | FUN_0043da10 | From compound +0x24 (same source) |
| +0x214 | float | GripParam3 | FUN_0043da10 | From compound +0x28 |
| +0x218 | float | GripParam4 | FUN_0043da10 | From compound +0x2c |
| +0x21c | float | CamberFactor1 | FUN_0043da10 | compound[6] × _DAT_0059ec68 |
| +0x224 | float | CamberFactor2 | FUN_0043da10 | compound[6] × _DAT_0059ec60 |
| +0x22c | float | LoadSensitivity | FUN_0043da10 | Computed via FUN_004d6ae0 |
| +0x234 | float | GripMultiplier | FUN_0043da10 | From compound +0x48 |
| +0x238 | float | GripMultiplier2 | FUN_0043da10 | From compound +0x4c |
| +0x278 | float | TireRadiusMin | FUN_0043da10 | From compound +0x00 |
| +0x280 | float | TireWidth | FUN_0043da10 | compound[0] - compound[2] |
| +0x288 | float | TireRadiusMax | FUN_0043da10 | From compound +0x08 |
| +0x290 | float | TireWidth2 | FUN_0043da10 | compound[1] - compound[3] |
| +0x2d8 | (ptr) | SlipCurve1 | FUN_0043da10 | Via FUN_004d75d0 lookup |
| +0x2dc | (ptr) | SlipCurve2 | FUN_0043da10 | Via FUN_004d75d0 lookup |
| +0x2e0 | (ptr) | SlipCurve3 | FUN_0043da10 | Via FUN_004d75d0 lookup |
| +0x2e4 | float | LoadNormalization | FUN_0043da10 | 1.0 / (load_norm × _DAT_0059ec58) |
| +0x2f4 | float | OptimumCamber | FUN_0043da10 | compound[0x13] |
| +0x2fc | float | CamberSensitivity | FUN_0043da10 | compound[0x15] × _DAT_0059ec50 |
| +0x304 | float | CamberFactorMain | FUN_0043da10 | Computed: _DAT_0059e898 / camber |
| +0x30c | float | CamberSlope | FUN_0043da10 | Computed: _DAT_0059e890 / (max_camber - opt_camber) |
| +0x334 | float | OptimumTemp | FUN_0043da10 | compound[0x23] + 273.15 K |
| +0x34c | float[11] | CamberSensitivityTable | FUN_0043da10 | 0x34c-0x378, hardcoded values |
| +0x384 | float | BaseGrip | FUN_0043da10 | From compound +0x38 |
| +0x388 | float | GripFactor | FUN_0043da10 | From compound +0x3c |
| +0x38c | float | SensFactor | FUN_0043da10 | From compound +0x40 |
| +0x390 | float | SensFactor2 | FUN_0043da10 | From compound +0x44 |
| +0x394 | float | WearInit0 | FUN_0043da10 | Hardcoded 0 |
| +0x398 | float | WearInit1 | FUN_0043da10 | Hardcoded 1.0 |
| +0x3cc | float | WearRate | FUN_0043da10 | compound[0x1c] × DAT_007d0c60 × load_norm |

---

## WheelSuspensionData (inferred)

Based on 1 function observation (FUN_0042fd00). Confidence: medium.

Per-wheel setup data, stride 0x2c0. Used in [FRONTLEFT]/[FRONTRIGHT]/[REARLEFT]/[REARRIGHT] sections.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x104 | int | CamberSetting | FUN_0042fd00 | |
| +0x144 | int | RideHeightSetting | FUN_0042fd00 | |
| +0x184 | int | PackerSetting | FUN_0042fd00 | |
| +0x1c4 | int | SpringSetting | FUN_0042fd00 | |
| +0x204 | int | SlowBumpSetting | FUN_0042fd00 | |
| +0x244 | int | FastBumpSetting | FUN_0042fd00 | |
| +0x284 | int | SlowReboundSetting | FUN_0042fd00 | |
| +0x2c4 | int | FastReboundSetting | FUN_0042fd00 | |
| +0x304 | int | BrakeDiscSetting | FUN_0042fd00 | |
| +0x344 | int | BrakePadSetting | FUN_0042fd00 | |
| +0x2c0 | - | WheelSetupStride | - | Per-wheel stride |

---

## FenderStruct (inferred)

Based on 1 function observation (FUN_004f3090). Confidence: high.

Fender flare aero setup per wheel.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | int | ActiveFlag | FUN_004f3090 | Set to 1 if FenderCenter present |
| +0x04 | double[3] | DragParams | FUN_004f3090 | Drag coefficient params |
| +0x1c | double[3] | LiftParams | FUN_004f3090 | Lift coefficient params |
| +0x34 | double | SidewaysCoeff | FUN_004f3090 | Sideways force coefficient |
| +0x3c | double[3] | CenterPosition | FUN_004f3090 | Fender center x, y, z |
| +0x54 | double | FlareSetting | FUN_004f3090 | |

---

## SuspensionForceValidator (inferred)

Based on 1 function observation (FUN_004f3240). Confidence: low.

Per-axis force validation data. Reads 3 doubles at stride 0x18 (3 axes × 2 directions).

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | double | ForceX | FUN_004f3240 | Per-axis force coefficient |
| +0x18 | double | ForceY | FUN_004f3240 | Stride 0x18 between axes |
| +0x30 | double | ForceZ | FUN_004f3240 | |

---

## WheelFloatArray (per-wheel state as float[]) (inferred)

Based on 1 function observation (FUN_004e3d00). Confidence: medium.

Wheel state represented as float array (int-indexed at param_1[N]).

| Float Index | Real Offset | Type | Field Name | Observed in | Notes |
|-------------|-------------|------|------------|-------------|-------|
| 0x0e | +0x38 | float[3] | SuspAxisVectors | FUN_004e3d00 | Suspension axis (3 floats) |
| 0x0f | +0x3c | float | SuspType | FUN_004e3d00 | 0=double-wishbone, 1=rigid axle |
| 0x10 | +0x40 | float | WheelNormal | FUN_004e3d00 | |
| 0x11 | +0x44 | float | RideHeight | FUN_004e3d00 | Current travel |
| 0x12 | +0x48 | float | SpringK | FUN_004e3d00 | Hardcoded 5.0 |
| 0x13 | +0x4c | float | SpringForce | FUN_004e3d00 | Computed |
| 0x14 | +0x50 | float | DampingEnabled | FUN_004e3d00 | 1.0 = enabled |
| 0x15 | +0x54 | float | DamperForce | FUN_004e3d00 | Accumulator |
| 0x16 | +0x58 | float | BumpForce | FUN_004e3d00 | |
| 0x24 | +0x90 | float | WheelRadius | FUN_004e3d00 | |
| 0x25 | +0x94 | float | DampingFactor | FUN_004e3d00 | |
| 0x27 | +0x9c | float | SpringRateMult | FUN_004e3d00 | |
| 0x2a | +0xa8 | float | ProgressiveRate | FUN_004e3d00 | |
| 0x2b | +0xac | float | BumpStopTravel | FUN_004e3d00 | |
| 0x2c | +0xb0 | float | AlignmentCamber | FUN_004e3d00 | |
| 0x2d | +0xb4 | float | AlignmentCaster | FUN_004e3d00 | |
| 0x2e | +0xb8 | float | (alignment) | FUN_004e3d00 | |
| 0x2f | +0xbc | float | SteerCasterCos | FUN_004e3d00 | Caster angle cosine |
| 0x30 | +0xc0 | float | SteerKingpin | FUN_004e3d00 | Kingpin angle |
| 0x31 | +0xc4 | float | LastContactX | FUN_004e3d00 | |
| 0x32 | +0xc8 | float | LastContactZ | FUN_004e3d00 | |
| 0x36 | +0xd8 | float[3] | WheelVelocity | FUN_004e3d00 | 3-component output velocity |

---

## WheelSuspensionForceStruct (stride 0x13c) (inferred)

Based on 1 function observation (FUN_00401340). Confidence: low.

Per-wheel suspension force calculations. Array of stride 0x13c from param_1+0x134.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x70 | float | LateralForce | FUN_00401340 | Output: lateral suspension force |
| +0x74 | float | LongitudinalForce | FUN_00401340 | Output: longitudinal suspension force |
| +0x78 | float | SpringForce0 | FUN_00401340 | Spring/damper force |
| +0x7c | float | SpringForce1 | FUN_00401340 | |
| +0x80 | float | SpringForce2 | FUN_00401340 | |
| +0x94 | float | BodyAttachX | FUN_00401340 | Body attachment point |
| +0x98 | float | BodyAttachY | FUN_00401340 | |
| +0x9c | float | BodyAttachZ | FUN_00401340 | |
| +0x10c | (ptr) | SuspGeomPtr | FUN_00401340 | Suspension geometry index/ptr |
| +0x110 | (ptr) | ContactPtr | FUN_00401340 | Collision contact surface pointer |
| +0x130 | int | NumWheels | FUN_00401340 | Wheel count for this vehicle |
| +0x134 | (ptr) | WheelArrayPtr | FUN_00401340 | Pointer to wheel struct array |
| +0x13c | - | StructStride | FUN_00401340 | Per-wheel stride |

---

## SetupParamArrayEntry (inferred)

Based on 1 function observation (FUN_0042f470). Confidence: high.

Entry in SetupParamArray at param_1 + 0xbb0, stride 0x40 per entry.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | double | BaseValue | FUN_0042f470 | Base setup value |
| +0x08 | double | Multiplier | FUN_0042f470 | Scale factor |
| +0x10 | int | ParamCount | FUN_0042f470 | |
| +0x14 | int | CurrentValue | FUN_0042f470 | |
| +0x18 | char* | FormatName | FUN_0042f470 | String name |
| +0x1c | int | Flags | FUN_0042f470 | Attribute flags |
| +0x20 | (extra) | (padding) | FUN_0042f470 | Remaining bytes to 0x40 stride |
| +0x40 | - | EntryStride | - | 0x40 |

---

## VehicleSceneNodeMap (inferred)

Based on 1 function observation (FUN_004dfce0). Confidence: high.

Maps mesh names to scene node indices. Int-indexed array (param_1[int_index]).

| Int Index | Real Offset | Type | Field Name | Observed in | Notes |
|-----------|-------------|------|------------|-------------|-------|
| 0x51 | +0x144 | int | LFTIRE_idx | FUN_004dfce0 | Left front tire mesh |
| 0x62 | +0x188 | int | LFSPINDLE_idx | FUN_004dfce0 | |
| 0x9b | +0x26c | int | RFTIRE_idx | FUN_004dfce0 | |
| 0xac | +0x2b0 | int | RFSPINDLE_idx | FUN_004dfce0 | |
| 0xe5 | +0x394 | int | LRTIRE_idx | FUN_004dfce0 | |
| 0xf6 | +0x3d8 | int | LRSPINDLE_idx | FUN_004dfce0 | |
| 0x12f | +0x4bc | int | RRTIRE_idx | FUN_004dfce0 | |
| 0x140 | +0x500 | int | RRSPINDLE_idx | FUN_004dfce0 | |
| 0x179 | +0x5e4 | int | FWING_idx | FUN_004dfce0 | Front wing |
| 0x18a | +0x628 | int | RWING_idx | FUN_004dfce0 | Rear wing |
| 0x19b–0x247 | +0x66c–+0x91c | int[?] | DEBRIS0–7_idx | FUN_004dfce0 | 8 debris meshes, stride 0x11 |
| 0x223 | +0x88c | int | COCKPIT_idx | FUN_004dfce0 | |
| 0x224 | +0x890 | int | SUSPENSION_idx | FUN_004dfce0 | |
| 0x225 | +0x894 | int | HELMET_idx | FUN_004dfce0 | |
| 0x226 | +0x898 | int | (unnamed) | FUN_004dfce0 | DAT_005c674c related |
| 0x227 | +0x89c | int | (unnamed) | FUN_004dfce0 | DAT_005d4d64 related |
| 0x228 | +0x8a0 | int | WHEEL_idx | FUN_004dfce0 | |
| 0x229 | +0x8a4 | int | RAINLIGHT_idx | FUN_004dfce0 | |
| 0x22a | +0x8a8 | int | BRAKELIGHT_idx | FUN_004dfce0 | |
| 0x22b | +0x8ac | int | HEADLIGHT_idx | FUN_004dfce0 | |
| 0x22c | +0x8b0 | int | BACKFIRE_idx | FUN_004dfce0 | |

---

## CameraStruct (inferred)

Based on 1 function observation (FUN_0040b850). Confidence: medium.

Camera definition struct for MAINVIEW and TRACKINGCAM. Stride 0xd0.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | unknown | (start) | FUN_0040b850 | |
| +0x04 | int | CameraCount | FUN_0040b850 | From FUN_00544f50 |
| +0x0c | (ptr) | CameraArrayPtr | FUN_0040b850 | Array of camera structs |
| +0x10 | int | CameraCount2 | FUN_0040b850 | Second count |
| +0x14 | int | CurrentIndex | FUN_0040b850 | Initialized to 0 |
| +0xd0 | - | CameraStructSize | - | Stride |

---

## PositionDeltaStruct (inferred)

Based on 1 function observation (FUN_004faec0). Confidence: high.

3D position tracking with target/reference pointers.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | float[3] | CurrentPosition | FUN_004faec0 | x, y, z |
| +0x0c | float[3] | ComputedDelta | FUN_004faec0 | Output delta vector |
| +0x10c (0x43×4) | (ptr) | RefPtr | FUN_004faec0 | Reference position pointer |
| +0x110 (0x44×4) | (ptr) | TargetPtr | FUN_004faec0 | Target position pointer |

---

## InitFloatConstantsStruct (inferred)

Based on 1 function observation (FUN_004594d0). Confidence: medium.

Struct initialized with physics-related float constants (likely tire/vehicle params).

| Offset | Type | Value | Field Name | Observed in | Notes |
|--------|------|-------|------------|-------------|-------|
| +0x04 | float | 0.0 | Zero | FUN_004594d0 | Cleared |
| +0x1c | float | FLT_MAX | MaxBound1 | FUN_004594d0 | 0x7f7fffff |
| +0x20 | float | FLT_MAX | MaxBound2 | FUN_004594d0 | |
| +0x24 | float | 0.0 | Cleared1 | FUN_004594d0 | |
| +0x28 | float | 0.0 | Cleared2 | FUN_004594d0 | |
| +0x2c | float | 3.75f | PhysicsParam1 | FUN_004594d0 | |
| +0x30 | float | 0.0 | Cleared3 | FUN_004594d0 | |
| +0x34 | float | 3.25f | PhysicsParam2 | FUN_004594d0 | |
| +0x38 | float | 0.0 | Cleared4 | FUN_004594d0 | |
| +0x3c | float | 1.75f | PhysicsParam3 | FUN_004594d0 | |
| +0x40 | float | -4.19e8f | LargeNeg1 | FUN_004594d0 | |
| +0x44 | float | 0.813f | Coeff1 | FUN_004594d0 | |
| +0x48 | float | -4.19e8f | LargeNeg2 | FUN_004594d0 | |
| +0x4c | float | 0.752f | Coeff2 | FUN_004594d0 | |
| +0x50 | float | 0.0 | Cleared5 | FUN_004594d0 | |
| +0xc0 | float | 0.0 | Cleared6 | FUN_004594d0 | |
| +0xc4 | float | 0.0 | Cleared7 | FUN_004594d0 | |
| +0xc8 | float | 0.0 | Cleared8 | FUN_004594d0 | |
| +0xcc | float | 0.0 | Cleared9 | FUN_004594d0 | |
| +0xd0 | float | 0.0 | Cleared10 | FUN_004594d0 | |

---

## SteeringTorqueOutputStruct (inferred)

Based on 1 function observation (FUN_00423ca0). Confidence: medium.

Output struct for steering torque/force computation.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x10 (param_1[4]) | float | OrthogonalResult | FUN_00423ca0 | Perpendicular force component |
| +0x18 (param_1[6]) | float | PrimaryResult | FUN_00423ca0 | Signed torque/force output |

---

## WheelSuspensionInitStruct (inferred)

Based on 1 function observation (FUN_004e2540). Confidence: medium.

Per-wheel suspension/tire initialization state.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x48 | float | PosX | FUN_004e2540 | |
| +0x4c | float | PosY | FUN_004e2540 | |
| +0x50 | float | PosZ | FUN_004e2540 | |
| +0x74 | float | VelocityStore1 | FUN_004e2540 | velocity = param_3 - position |
| +0x8c | int[9] | CoeffCopySource | FUN_004e2540 | 9 ints copied from +0xd0 |
| +0xb8 | float | VelocityStore2 | FUN_004e2540 | |
| +0xc4 | float | ParamStore1 | FUN_004e2540 | |
| +0xcc | float | ParamStore2 | FUN_004e2540 | |
| +0xd0 | int[9] | CoeffCopyTarget | FUN_004e2540 | Source for 9-int copy |
| +0xf8 | float | ParamStore3 | FUN_004e2540 | |
| +0xfc | float | ParamStore4 | FUN_004e2540 | |

---

## VehicleSetupFileWriterLayout (setup file struct region)

Based on 1 function observation (FUN_0042fd00). Confidence: high.

The setup file writer accesses a large region of the vehicle struct devoted to setup
parameter values. These offsets overlap with the main VehiclePhysicsHeader struct
at the +0xbb0–+0x1ccx range.

Most setup fields are `int` type (4 bytes). See VehiclePhysicsHeader table above for
complete listing. This section cross-references which entries are setup-file moddable.

**Moddable setup fields (confirmed by FUN_0042fd00):**
All int-type fields from +0xbc4 (TireCompoundSetting) through +0x1ccx (GearSettings)
are written to setup files. Full list in VehiclePhysicsHeader table above.

---

## Conflicting Offset Observations

| Offset | Conflict | Functions | Resolution |
|--------|----------|-----------|------------|
| +0x1d4 | (ptr) FuelTankBodyPtr vs low offset | FUN_00439210 (+0x1d4 as ptr), FUN_00439210 also +0x1d4 listed | Same struct — low absolute offset relative to vehicle base, consistent as pointer field |
| +0x15c4 | SteeringBarCount vs EngineMapSetting | FUN_00439210 (bar count), FUN_0042fd00 (engine map) | Likely different struct regions or same field repurposed. Majority: FUN_00439210 more authoritative for physics layout |
| +0x1884 | GearCount vs NumPitstopsSetting | FUN_0042f470 (gear count), FUN_0042fd00 (pitstops) | Same offset, different usage context. May be union or function-specific interpretation |
| +0x3d64 | EngineFailureTime[4] vs TireWearAccumulator | FUN_004ee150 (4 floats for engine failure), FUN_004efae0 (single float tire wear) | Different structs or union. Engine failure uses param_2, tire wear uses param_1 directly |
| +0x1db4 | double vs docs/13 EffectiveLifetime | docs/13 (double) | Consistent |

---

## Source: docs/08-file-formats.md

Source: docs/08-file-formats.md (279 entries, ~204 offset observations)

---

## Vehicle Struct (int-indexed from .veh file parser)

Based on 1 function observation (FUN_004c3200). Confidence: medium — int-indexed, stride unclear.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | char* | filename | FUN_004c3200 | string pointer (int-indexed [0]) |
| +0x02 | char* | HDVehicle file path | FUN_004c3200 | [2] |
| +0x04 | char* | HeadPhysics file path | FUN_004c3200 | [4] |
| +0x06 | char* | Sounds file path | FUN_004c3200 | [6] |
| +0x08 | char* | Graphics file path | FUN_004c3200 | [8] |
| +0x0a | char* | GenString | FUN_004c3200 | [0xa] |
| +0x0e–+0x10 | float×3 | Eyepoint | FUN_004c3200 | 3 floats at [0xe], [0xf], [0x10] |
| +0x11–+0x13 | float×3 | CameraTarget | FUN_004c3200 | 3 floats at [0x11], [0x12], [0x13] |
| +0x14–+0x16 | float×3 | MirrorPos | FUN_004c3200 | 3 floats at [0x14], [0x15], [0x16] |
| +0x17–+0x19 | float×3 | MirrorNorm | FUN_004c3200 | 3 floats at [0x17], [0x18], [0x19] |
| +0x1a–+0x1c | float×3 | SteeringWheelAxis | FUN_004c3200 | 3 floats at [0x1a], [0x1b], [0x1c] |
| +0x1d | char* | Number | FUN_004c3200 | [0x1d] |
| +0x1f | char* | (unknown) | FUN_004c3200 | [0x1f] |
| +0x2f | char* | Driver name | FUN_004c3200 | [0x2f] |
| +0x3f | char* | Description | FUN_004c3200 | [0x3f] |
| +0x4f | char* | Engine file | FUN_004c3200 | [0x4f] |
| +0x5f | char* | Manufacturer | FUN_004c3200 | [0x5f] |
| +0x6f | char* | Classes | FUN_004c3200 | [0x6f] |
| +0xaf | char* | FullTeamName | FUN_004c3200 | [0xaf] |
| +0xcf | char* | TeamFounded | FUN_004c3200 | [0xcf] |
| +0xd3 | char* | TeamHeadquarters | FUN_004c3200 | [0xd3] |
| +0xe3 | char* | TeamStarts | FUN_004c3200 | [0xe3] |
| +0xe7 | char* | TeamPoles | FUN_004c3200 | [0xe7] |
| +0xeb | char* | TeamWins | FUN_004c3200 | [0xeb] |
| +0xef | char* | TeamWorldChampionships | FUN_004c3200 | [0xef] |
| +0xf5 | void* | TrackLivery linked list | FUN_004c3200 | [0xf5] |

Note: This is clearly a string-table struct (int-indexed, each slot = 4 bytes pointer). Total ~0xf9 slots ≈ 996 bytes. Not the physics vehicle struct.

---

## Vehicle Array Entry (stride 0x424)

Based on 4 function observations (FUN_004c78f0, FUN_004c3d80, FUN_004c2a80, FUN_004c7b50). Confidence: high — consistent stride 0x424, documented in setup.cpp loader.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | char* | filename | FUN_004c3200, FUN_004c78f0 | from .veh file |
| +0x02 | char* | HDVehicle file path | FUN_004c3200 | |
| +0x04 | char* | HeadPhysics file path | FUN_004c3200 | |
| +0x06 | char* | Sounds file path | FUN_004c3200 | |
| +0x08 | char* | Graphics file path | FUN_004c3200 | |
| +0x0a | char* | GenString | FUN_004c3200 | |
| +0x0e–+0x10 | float×3 | Eyepoint | FUN_004c3200 | |
| +0x11–+0x13 | float×3 | CameraTarget | FUN_004c3200 | |
| +0x14–+0x16 | float×3 | MirrorPos | FUN_004c3200 | |
| +0x17–+0x19 | float×3 | MirrorNorm | FUN_004c3200 | |
| +0x1a–+0x1c | float×3 | SteeringWheelAxis | FUN_004c3200 | |
| +0x1d | char* | Number | FUN_004c3200, FUN_004c78f0 | also written as char string |
| +0x1f | char* | (unknown) | FUN_004c3200, FUN_004c78f0 | |
| +0x2f | char* | Driver name | FUN_004c3200, FUN_004c78f0 | |
| +0x3f | char* | Description | FUN_004c3200, FUN_004c78f0 | |
| +0x4f | char* | Engine file | FUN_004c3200 | |
| +0x5f | char* | Manufacturer | FUN_004c3200 | |
| +0x6f | char* | Classes | FUN_004c3200 | |
| +0x7c | char* | name field (at +0x7c) | FUN_004c3fe0, FUN_004c3f80 | used by name lookup |
| +0xaf | char* | FullTeamName | FUN_004c3200 | |
| +0xbc | char* | vehicle name | FUN_004c3f80, FUN_004c3fe0 | consistent across lookups |
| +0xcf | char* | TeamFounded | FUN_004c3200 | |
| +0xd3 | char* | TeamHeadquarters | FUN_004c3200 | |
| +0xe3 | char* | TeamStarts | FUN_004c3200 | |
| +0xe7 | char* | TeamPoles | FUN_004c3200 | |
| +0xeb | char* | TeamWins | FUN_004c3200 | |
| +0xef | char* | TeamWorldChampionships | FUN_004c3200 | |
| +0xf5 | void* | TrackLivery linked list | FUN_004c3200 | |
| +0x403c | int | SeasonPoints | FUN_004c2a80 | score accumulation |
| +0x4060 | int | FinishPosition | FUN_004c2a80 | qualifying/race position |
| +0x4064 | int | FinishState | FUN_004c2a80 | 0=running, 1=finished, 2=DNF, 3=DSQ |
| +0x409c | float | BestLapTime | FUN_004c2a80 | |
| +0x4620 | char* | DriverName | FUN_004c6a10, FUN_004c7b50 | full name string |
| +0x4660 | char[] | Nationality | FUN_004c6c40 | max 0x17 chars |
| +0x4677 | char | null terminator | FUN_004c6c40 | |
| +0x4678 | char* | Description | FUN_004c78f0 | from .veh +0x3f |
| +0x46b8 | char* | Number | FUN_004c78f0 | from .veh +0x1f |
| +0x46f8 | char[] | Abbreviation | FUN_004c6a10 | max 15 chars |
| +0x4707 | char | null terminator | FUN_004c6a10 | |
| +0x4714 | char* | VehicleDescription | FUN_004c7b50 | vehicle description path |
| +0x4894 | int | vehicle index | FUN_004c6c40, FUN_004c78f0 | index in vehicle array |
| +0x4898 | int | VehicleIndex | FUN_004c7b50 | duplicate of +0x4894? |
| +0x489c | int | DriverNumber | FUN_004c7b50 | driver number |
| +0x48a0 | int | (unknown) | FUN_004c7b50 | |
| +0x48a4 | int | flag (-1 after load) | FUN_004c6c40 | |
| +0x48a8 | int | flag (-1 after load) | FUN_004c6c40 | |
| +13000 | int | first-load flag | FUN_004c6c40 | 0 = first time (offscreen offset?) |

**Note on +0xbc vs +0x7c:** Both appear as name fields in lookup functions. May be different field names or aliases. +0xbc used by FUN_004c3f80 (vehicle name lookup), +0x7c by FUN_004c3fe0 (name comparison).

**Note on offset +13000:** This is suspiciously large. May be byte-indexed relative to a different base, not from same struct.

---

## Player Career Stats / Game Options Struct

Based on 2 function observations (FUN_004c18b0 reader, FUN_004c1e80 writer). Confidence: high — identical struct used by reader and writer. Byte-indexed.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x08 | int | ABORTEDSEASONS | FUN_004c18b0 | |
| +0x09 | int | TOTALLAPS | FUN_004c18b0 | |
| +0x0a | int | TOTALRACES | FUN_004c18b0 | |
| +0x0b | int | TOTALRACESWITHAI | FUN_004c18b0 | |
| +0x0c | int | TOTALPOINTSSCORED | FUN_004c18b0 | |
| +0x0d | int | TOTALCHAMPIONSHIPS | FUN_004c18b0 | |
| +0x0e | int | TOTALWINS | FUN_004c18b0 | |
| +0x0f | int | TOTALPOLES | FUN_004c18b0 | |
| +0x10 | int | TOTALLAPRECORDS | FUN_004c18b0 | |
| +0x11 | float→int | AVGSTARTPOSITION | FUN_004c18b0 | stored as float, cast to int |
| +0x12 | int | AVGFINISHPOSITION | FUN_004c18b0 | |
| +0x13 | int | AVGRACEDISTANCE | FUN_004c18b0 | |
| +0x14 | int | AVGOPPONENTSTRENGTH | FUN_004c18b0 | |
| +0x15 | int | MECHFAIL_rate | FUN_004c18b0 | |
| +0x16 | int | RACECOND_reconnaissance | FUN_004c18b0 | |
| +0x17 | int | RACECOND_walkthrough | FUN_004c18b0 | |
| +0x18 | int | RACECOND_formation | FUN_004c18b0 | |
| +0x19 | int | RACECOND_flag_rules | FUN_004c18b0 | |
| +0x1a | int | RACECOND_weather | FUN_004c18b0 | |
| +0x1b | bool | RACECOND_timescaled_weather | FUN_004c18b0 | |
| +0x1c | int | GAMEOPT_qualify_laps | FUN_004c18b0 | |
| +0x1d | int | GAMEOPT_race_laps | FUN_004c18b0 | |
| +0x1e | int | GAMEOPT_race_time | FUN_004c18b0 | |
| +0x1f | int | GAMEOPT_race_length | FUN_004c18b0 | |
| +0x20 | int | GAMEOPT_opponents | FUN_004c18b0 | |
| +0x21 | int | GAMEOPT_fuel_mult | FUN_004c18b0 | |
| +0x22 | int | GAMEOPT_tire_mult | FUN_004c18b0 | |
| +0x23 | int | GAMEOPT_speed_comp | FUN_004c18b0 | |

Note: Offsets are packed (consecutive bytes). This is a dense byte-indexed struct, not int-indexed. Total size: at least 0x24 bytes.

---

## PLAYERTRACKSTAT Node Struct (int-indexed)

Based on 1 function observation (FUN_004c2420). Confidence: low — single source. Int-indexed.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | char* | TrackName string | FUN_004c2420 | [0] |
| +0x01 | char* | TrackName string 2 | FUN_004c2420 | [1] |
| +0x02 | char* | TrackFile string 1 | FUN_004c2420 | [2] |
| +0x03 | char* | TrackFile string 2 | FUN_004c2420 | [3] |
| +0x04 | int | TotalNumLaps | FUN_004c2420 | [4] |
| +0x05 | float | BestLapTime | FUN_004c2420 | [5] |

---

## Standings / Scoring Struct (int-indexed)

Based on 2 function observations (FUN_004c0910, FUN_004c03f0). Confidence: medium — pattern consistent but only 2 functions.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x18 + i*4 | int | FINISHPOSITION[0..47] | FUN_004c0910 | array of finish positions |
| +0xd8 + i*4 | int | FINISHPOINTS[0..47] | FUN_004c0910 | array of points per race |
| +0x198 | int | SEASONPOINTS | FUN_004c0910 | accumulated total |
| +0x1a0 | int | POLESTAKEN | FUN_004c0910 | pole position count |
| +0x1a4 | int | ORIGINALGRIDPOSITION | FUN_004c0910 | |
| +0x1a8 | int | CURRENTGRIDPOSITION | FUN_004c0910 | |

Note: +0x18 to +0xd8 = 0xc0 bytes = 48 entries × 4 bytes. +0xd8 to +0x198 = 0xc0 bytes = same 48 entries × 4 bytes. Stride 0x18? No — the arrays have 48 elements each (0xc0 bytes each).

---

## Player File Struct

Based on 2 function observations (plrfile.cpp section, FUN_004b0540). Confidence: medium — offsets from different sections consistent.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x14 | char* | FilePath | FUN_004b0540 | player data path |
| +0x114 | int | FileExistsFlag | FUN_004b0540 | |
| +0x1f78 | int | GameMode | FUN_004b0540 | also called "state (4=?)" in plrfile |
| +0x24f8 | int | VehicleCountTable | FUN_004b0540 | clamped 1-104 |
| +0x2f8c | int | AIDifficulty | FUN_004b0540 | |
| +0x49b0 | char* | player data path ptr | plrfile.cpp section | duplicate of +0x14? |

**Conflict:** +0x14 is FilePath (char*) and +0x49b0 is also player data path pointer. These may be different fields (primary path vs backup), or the plrfile.cpp section refers to a different struct. Uncertain.

---

## Game Data File State Struct

Based on 1 function observation (FUN_004b7300). Confidence: low — single source, no cross-validation.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x6c0 | void* | DataListHead | FUN_004b7300 | linked list of data blocks |
| +0x6e4 | int | SuccessFlag | FUN_004b7300 | |
| +0x700 | int | OpState | FUN_004b7300 | operation state |
| +0xf1c | int | PlayerTeamID | FUN_004b7300 | |
| +0xf20 | int | SessionType | FUN_004b7300 | |

---

## AutoLoadEntry Struct (int-indexed)

Based on 2 function observations (FUN_00432bf0 writer, FUN_00432a70 reader). Confidence: high — reader and writer agree on field names.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | char* | Track path | FUN_00432bf0, FUN_00432a70 | [0] |
| +0x02 | char* | Classes | FUN_00432bf0, FUN_00432a70 | [2] |
| +0x04 | int | Session | FUN_00432bf0, FUN_00432a70 | [4] |
| +0x05 | char* | (unnamed string) | FUN_00432bf0, FUN_00432a70 | [5] |

**Conflict:** FUN_00432a70 stores offsets as byte addresses: +0x00 Track, +0x08 Classes, +0x10 Session, +0x14 (unnamed). These are actual byte offsets (8 bytes apart = 2 int-indexed slots apart). Compatible because int-indexed: [0] = +0x00, [2] = +0x08, [4] = +0x10, [5] = +0x14. ✅ Consistent.

---

## AutoLoadEntry Linked List Node Struct (stride 0x1c)

Based on 1 function observation (FUN_00432e70). Confidence: low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | char* | Track path (alloc) | FUN_00432e70 | string allocation |
| +0x04 | int | next pointer | FUN_00432e70 | -1 = end |
| +0x08 | char* | Classes (alloc) | FUN_00432e70 | string allocation |
| +0x0c | int | next pointer | FUN_00432e70 | -1 = end |
| +0x14 | char* | (unnamed, alloc) | FUN_00432e70 | string allocation |
| +0x18 | int | next pointer | FUN_00432e70 | -1 = end |

Note: This appears to be a string-pair list node where each string pointer is followed by a "next" link. Stride 0x1c.

---

## AutoLoadEntry List Head Struct

Based on 1 function observation (FUN_00432e70). Confidence: low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x1c | void* | head | FUN_00432e70 | list head pointer |
| +0x20 | void* | tail | FUN_00432e70 | list tail pointer |
| +0x24 | void* | iterator | FUN_00432e70 | current traversal position |
| +0x28 | int | count | FUN_00432e70 | entry count |
| +0x18 | int | loaded flag | FUN_00432e70 | set to 1 at end of load |

**Conflict:** +0x18 is both "loaded flag" and overlaps with AutoLoadEntry node struct +0x18 (next pointer for unnamed alloc). These are different structs — the list head struct is a separate container. ✅ Consistent.

---

## Game State / Session Config Struct

Based on 3 function observations (FUN_004c11e0, FUN_004c0b70, FUN_004c0db0). Confidence: medium — offsets overlap suggest large struct with multiple sections.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0xb110 | int | filter base start | FUN_004c0db0 | |
| +0xb114 | int | filter base repeat | FUN_004c0db0 | |
| +0xb118 | int | filter count | FUN_004c0db0 | |
| +0xb11c | bool | filter active flag | FUN_004c0db0 | |
| +0xb130 | int | QualifyLaps | FUN_004c11e0 | |
| +0xb134 | int | QualifyTime | FUN_004c11e0 | |
| +0xb138 | int | RaceLaps | FUN_004c11e0 | |
| +0xb13c | int | RaceTime | FUN_004c11e0 | |
| +0xb140 | void* | Current track data ptr | FUN_004c11e0 | |
| +0xb144 | int | session filter type (=2) | FUN_004c0db0, FUN_004c0b70 | also SEASONSTATUS |
| +0xb148 | int | CURRENTRACE | FUN_004c0b70, FUN_004c0db0 | current race index |
| +0xb14c | int | RACESESSION | FUN_004c0b70 | |
| +0xb150 | bool | RACEOVER | FUN_004c0b70 | |

**Conflict:** +0xb144 is called "session filter type" in FUN_004c0db0 and "SEASONSTATUS" in FUN_004c0b70. Both may be aliases for same field (season status determines filter type). Uncertain.

---

## Vehicle Setup Struct

Based on 1 function observation (FUN_004f6300). Confidence: low — single source, offsets sparse within large struct.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0xbc0 | void* | Tire brand data ptr | FUN_004f6300 | |
| +0x13c0 | int | SetupType | FUN_004f6300 | 0=Custom, 1=Gearing, 2=Balance, 3=Downforce |
| +0x1988 | bool | Auto-setup enabled | FUN_004f6300 | from file +0x548 |
| +0x1989 | bool | Auto-setup sub-flag | FUN_004f6300 | from file +0x56c |
| +0x1990 | bool | Auto-setup flag | FUN_004f6300 | default 1 |
| +0x1994 | float | FuelConsumptionRecip | FUN_004f6300 | 1 / computed fuel |
| +0x19a4 | bool | Setup bool flag | FUN_004f6300 | |
| +0x19a5 | bool | Setup bool flag 2 | FUN_004f6300 | |

---

## Per-Vehicle Filter State Struct (stride 0x1b4)

Based on 1 function observation (FUN_004c0db0). Confidence: low — stride 0x1b4 per vehicle.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x194 | int | filter index start | FUN_004c0db0 | |
| +0x198 | int | filter index end | FUN_004c0db0 | |
| +0x19c | int | filter flags | FUN_004c0db0 | |
| +0x1a0 | bool | filter active flag | FUN_004c0db0 | |

---

## Track Database Struct (int-indexed)

Based on 1 function observation (FUN_00460a10). Confidence: low — single source, int-indexed.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x08 | int | expected terrain type | FUN_00460a10 | [2] |
| +0x0c | int | expected surface type hash | FUN_00460a10 | [3] |
| +0x10 | int | expected terrain.ini CRC | FUN_00460a10 | [4] |
| +0x14 | int | expected track name hash | FUN_00460a10 | [5] |
| +0x18 | int | expected full path hash | FUN_00460a10 | [6] |

---

## Terrain Validation Flags Struct

Based on 1 function observation (FUN_00460a10). Confidence: low. Offsets in a very large struct (>0x1b76e bytes).

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x1b754 | byte | terrain type byte 1 | FUN_00460a10 | |
| +0x1b755 | byte | terrain type byte 2 | FUN_00460a10 | |
| +0x1b76a | byte | check 1 pass (terrain) | FUN_00460a10 | |
| +0x1b76b | byte | check 2 pass (surface) | FUN_00460a10 | |
| +0x1b76c | byte | check 3 pass (CRC) | FUN_00460a10 | |
| +0x1b76d | byte | check 4 pass (track name) | FUN_00460a10 | |
| +0x1b76e | byte | check 5 pass (full path) | FUN_00460a10 | |

Note: At >112KB this may be a different struct or an offset relative to a different base pointer (e.g., a large track/track-database object).

---

## Scene Array Entry (stride 0x18c)

Based on 4 function observations (FUN_004c54f0, FUN_004c5cb0, FUN_004c6330, FUN_004c5940). Confidence: high — stride 0x18c consistently used across scene enumeration functions.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x104 | char* | scene name/identifier | FUN_004c54f0, FUN_004c5cb0, FUN_004c6330 | string identifier for scene |

---

## Filter Node Linked List (stride 0xc)

Based on 1 function observation (FUN_004c5e50). Confidence: low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | int | scene index | FUN_004c5e50 | |
| +0x04 | void* | next pointer | FUN_004c5e50 | |
| +0x08 | bool | active flag | FUN_004c5e50 | set to 1 |

---

## Filter List State

Based on 1 function observation (FUN_004c5e50). Confidence: low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x08 | void* | list head | FUN_004c5e50 | |
| +0x0c | void* | list tail | FUN_004c5e50 | |
| +0x10 | void* | current iterator | FUN_004c5e50 | |
| +0x14 | int | node count | FUN_004c5e50 | |

---

## File Buffer State Struct

Based on 2 function observations (FUN_00587ca0, FUN_00589898). Confidence: high — identical offsets in both functions.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | byte* | buffer_ptr | FUN_00587ca0, FUN_00589898 | current read/write position |
| +0x04 | int | remaining | FUN_00587ca0, FUN_00589898 | remaining bytes in buffer |

---

## File State / Mode Flags Struct

Based on 2 function observations (FUN_00587f90, FUN_0059c156). Confidence: high — consistent offsets.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x0c | uint | ModeFlags | FUN_00587f90, FUN_0059c156 | bitmask: 0x1=read, 0x2=write, 0x80=EOF |
| +0x10 | int/void* | FileHandle/Buffer | FUN_00587f90, FUN_0059c156 | file handle or buffer pointer |
| +0x18 | uint | BufferSize | FUN_00587f90, FUN_0059c156 | I/O buffer size (0x200) |

---

## Stream Object Struct

Based on 1 function observation (FUN_0059a3a9). Confidence: low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x04 | uint | status/flags | FUN_0059a3a9 | |
| +0x28 | void* | stored reference | FUN_0059a3a9 | param_2 |
| +0x2c | void* | zeroed | FUN_0059a3a9 | |
| +0x30 | ushort | buffer/chunk size | FUN_0059a3a9 | |

---

## Buffered I/O Stream Struct

Based on 1 function observation (FUN_00599081). Confidence: low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | void* | vtablePtr | FUN_00599081 | virtual method table |
| +0x1c | byte* | BufferPtr | FUN_00599081 | read buffer base |
| +0x2c | int* | BufferEnd | FUN_00599081 | buffer limit pointer |

---

## Buffered I/O Init Struct

Based on 1 function observation (FUN_005876f0). Confidence: low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x410 | int | sentinel | FUN_005876f0 | set to -1 (end marker) |
| +0x414 | int | cursor | FUN_005876f0 | zeroed (counter) |

---

## String Property Struct

Based on 1 function observation (FUN_00467430). Confidence: low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x2f0 | char* | stored string | FUN_00467430 | param_1[0xbc] |
| +0x2f4 | char* | cursor pointer | FUN_00467430 | param_1[0xbd] |
| +0x2f8 | int | buffer size | FUN_00467430 | param_1[0xbe] |

---

## UI State Struct

Based on 1 function observation (FUN_004662c0). Confidence: low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0xf4 | byte | flag | FUN_004662c0 | zeroed on reset |
| +0xf5 | byte | flag | FUN_004662c0 | zeroed on reset |

---

## UI Dialog/Property Page Struct

Based on 1 function observation (FUN_00469880). Confidence: low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | void* | vtablePtr | FUN_00469880 | PTR_FUN_0059f7c8 |
| +0x174 | int | zeroed | FUN_00469880 | param_1[0x5d] |
| +0x178 | int | zeroed | FUN_00469880 | param_1[0x5e] |
| +0x17c | byte | activeFlag | FUN_00469880 | set to 1 |
| +0x180 | int | zeroed | FUN_00469880 | param_1[0x60] |
| +0x184 | int | sentinel | FUN_00469880 | param_1[0x61] = -1 |

---

## UI Options / Display Settings Struct

Based on 1 function observation (FUN_004726c0). Confidence: low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x31c | void** | screenModePtr | FUN_004726c0 | param_1[199] → &DAT_007cff84 |
| +0x324 | void* | optionCount | FUN_004726c0 | param_1[0xc9] = 3 |
| +0x328 | int | flag1 | FUN_004726c0 | param_1[0xca] = 1 |
| +0x32c | int | flag2 | FUN_004726c0 | param_1[0xcb] = 1 |
| +0x330 | int | flag3 | FUN_004726c0 | param_1[0xcc] = 1 |
| +0x334 | int | defaultID | FUN_004726c0 | param_1[0xcd] = 0x103 |
| +0x338 | int | sentinel | FUN_004726c0 | param_1[0xce] = -1 |

---

## File Read Loop Struct

Based on 1 function observation (FUN_005352d0). Confidence: low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x04 | int | zeroed on start | FUN_005352d0 | |
| +0x10 | int | bufferAvail | FUN_005352d0 | available bytes count |
| +0x40 | void* | buffer | FUN_005352d0 | data buffer |
| +0x48 | void* | readBufPtr | FUN_005352d0 | read position |
| +0x5c | char | modeFlag | FUN_005352d0 | 'w' = write mode |

---

## File Handle Close Struct

Based on 1 function observation (FUN_00566b90). Confidence: low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | int | FileHandle | FUN_00566b90 | handle to close |
| +0x10 | int | CloseFlags | FUN_00566b90 | 0 → method A, else → method B |

---

## Season Database Struct (FUN_0047f440)

Based on 1 function observation (FUN_0047f440). Confidence: low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x191c | void** | entryArray[508] | FUN_0047f440 | array of 508 object pointers |
| +0x1fe8 | void* | specialPtr | FUN_0047f440 | for index 0x1b4 case |

---

## Buffer Flush/Write I/O Struct (FUN_0058a05a)

Based on 1 function observation (FUN_0058a05a). Confidence: low — offset names from doc comment.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | void* | WritePos | FUN_0058a05a | current write position |
| +0x04 | void* | StartPos | FUN_0058a05a | start of buffer |
| +0x08 | void* | BufferStart | FUN_0058a05a | buffer base |
| +0x0c | uint | Flags | FUN_0058a05a | mode bits |
| +0x10 | int | IOHandle | FUN_0058a05a | underlying I/O handle |

---

## File Close Wrapper Struct (FUN_00599495)

Based on 1 function observation (FUN_00599495). Confidence: low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x50 | int | FileHandle | FUN_00599495 | |

---

## Scoring Database Struct (at DAT_007d2e48 + season_index * 0x48c0)

Based on 1 function observation (FUN_004c0910). Confidence: medium — aligns with vehicle struct offsets.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x403c | int | season points total | FUN_004c0910 | |
| +0x4060 | int | finish position | FUN_004c0910 | |
| +0x4064 | int | finish state | FUN_004c0910 | 3 = DNF/excluded |
| +0x409c | float | best lap time | FUN_004c0910 | |

Note: These offsets (+0x403c through +0x409c) match the vehicle struct offsets from FUN_004c2a80. Suggests scoring DB entries may be vehicle structs or a compatible layout. ✅ Consistent with Vehicle Array Entry (stride 0x424 → vehicle struct ≈0x48c0).

---

## Credited Functions Index

All functions in docs/08-file-formats.md that contributed offset observations:

| Function | Section | Observations |
|----------|---------|-------------|
| FUN_004c3200 | .veh File Parser | 26 offsets (vehicle file slots) |
| FUN_004c18b0 | Player Career Stats | 24 offsets (career struct) |
| FUN_004c78f0 | Nationality/Driver Info | 5 offsets (vehicle array access) |
| FUN_004c2a80 | Season Scoring Updater | 4 offsets (vehicle struct) |
| FUN_004c0910 | Season Scoring | 6 offsets (standings struct) + 4 offsets (scoring DB) |
| FUN_004c2420 | Career Stats Writer | 6 offsets (PLAYERTRACKSTAT node) |
| FUN_004c1e80 | Game Options Writer | 24 offsets (same as reader) |
| FUN_004c0db0 | Game Filter Data Loader | 8 offsets (filter state) + 4 offsets (per-vehicle) |
| FUN_004c6c40 | vehgen.scn Loader | 6 offsets (vehicle struct) |
| FUN_004c7b50 | Vehicle Setup Driver Number | 4 offsets (vehicle struct) |
| FUN_004c6a10 | Driver Abbreviation Formatter | 3 offsets (vehicle struct) |
| FUN_004c11e0 | Session Config Reader | 5 offsets (game state) |
| FUN_004c0b70 | Career/Season State Reader | 4 offsets (game state) |
| FUN_004c6320 | Scene File Filter Builder | 2 offsets (scene array + filter list) |
| FUN_004c5e50 | Filter Properties Builder | 5 offsets (filter list state) |
| FUN_004c5cb0 | SceneOrder Slot Finder | 2 offsets (scene struct) |
| FUN_004b0540 | PlayerFileInit | 5 offsets (player file struct) |
| FUN_004b7300 | GameDataFileIO | 5 offsets (game data state) |
| FUN_00432bf0 | AutoLoadEntry Writer | 4 offsets (autoload entry) |
| FUN_00432a70 | Track/Session/Classes Reader | 4 offsets (autoload entry, byte offsets) |
| FUN_00432e70 | AutoLoadEntry List Loader | 9 offsets (list node + head/tail) |
| FUN_004f6300 | Vehicle Setup File Parser | 8 offsets (setup struct) |
| FUN_00460a10 | terrain.ini Parser | 12 offsets (terrain validation + track DB) |
| FUN_004c54f0 | .AIW/.SCN Filename Builder | 1 offset (scene name) |
| FUN_004c5940 | SeasonRaces Scene Sorter | 1 offset (scene array) |
| FUN_004c3d80 | Vehicle File Loader | 2 offsets (vehicle array globals) |
| FUN_0047f440 | Season Database Factory | 2 offsets (season DB struct) |
| FUN_00587ca0 | File Read Until Newline | 2 offsets (file buffer state) |
| FUN_00589898 | Buffered Char Write | 2 offsets (file buffer state) |
| FUN_00587f90 | File Tell/Seek | 3 offsets (file state) |
| FUN_0059c156 | File Seek with Validation | 3 offsets (file state) |
| FUN_0059a3a9 | Stream Creation | 4 offsets (stream struct) |
| FUN_00599081 | Buffered Stream Read | 3 offsets (stream buffer) |
| FUN_005876f0 | Buffered I/O Init | 2 offsets (buffered IO struct) |
| FUN_0058a05a | Buffer Flush/Write | 5 offsets (buffer I/O struct) |
| FUN_00599495 | File Close Wrapper | 1 offset (file handle struct) |
| FUN_005352d0 | File Read Loop | 5 offsets (read state struct) |
| FUN_00566b90 | Conditional File Close | 2 offsets (file handle struct) |
| FUN_00598d6d | OutputStream Write | 2 offsets (stream buffer) |
| FUN_00467430 | String Compare Replace | 3 offsets (string property) |
| FUN_004662c0 | UI State Reset | 2 offsets (UI state struct) |
| FUN_00469880 | UI Dialog Constructor | 5 offsets (UI dialog struct) |
| FUN_004726c0 | UI Options Constructor | 7 offsets (UI options struct) |
| FUN_00473fd0 | UI Options Constructor | 1 offset (UI options global ref) |

---

## Source: docs/19-renderer.md

# Struct Offset Synthesis — Worker G (docs/19-renderer.md)

429 entries scanned. 161 offset observations extracted.

## RenderContext (inferred)

Large render device/context struct used by multiple functions including
FUN_005550e0, FUN_0053eb70, FUN_004c71c0, FUN_00554700, FUN_00586700,
FUN_00540f00. Int-indexed access (param_1[N]) common. Controls D3D device,
render states, buffers.

Based on 18+ function observations. Confidence: high.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x0000 | int* | vtablePtr | FUN_004c71c0, FUN_005550e0, FUN_0053eb70, FUN_0054ca00 | Virtual method table |
| +0x1100 (0x440) | ptr | deviceVtableObj | FUN_005550e0, FUN_0053eb70, FUN_0053ead0, FUN_00554700, FUN_00586700 | Interface ptr with vtable at *(*this+0x440); used for D3D state calls |
| +0x1398 (0x4e6) | int | valueSlot1 | FUN_00554700 | Property value slot |
| +0x139c (0x4e7) | int | valueSlotIndex | FUN_00554700 | Property index/value slot 2 |
| +0x13e0 (0x4f8) | int | bufferType | FUN_00540f00 | Format/type flag for buffer alloc |
| +0x12a8 (0x4ea) | int | renderStateFlags | FUN_005550e0, FUN_0053eb70 | Bitmask: bit 28 = initialized, bit 8 = fog, bit 9 = debug |
| +0x12b0 (0x4ec) | int | renderLimit | FUN_005550e0 | Max iterations per bucket |
| +0x12c4 (0x4f1) | int | initializedFlag | FUN_005550e0 | 1 = already initialized |
| +0x12c8 (0x4f2) | int | colorValue | FUN_005550e0 | Cached color/int value |
| +0x12cc (0x4f3) | int | currentMaterialID | FUN_005550e0 | Tracks active material/texture |
| +0x12d0 (0x4f4) | int | renderDebugMode | FUN_005550e0 | 0=normal, non-0=debug overlay |
| +0x12d8 (0x4f6) | int | textOverlayMode | FUN_005550e0 | Non-0 enables debug text |
| +0x14f0 (0x53c) | int | extraFlag | FUN_005550e0 | Guard/state flag checked at end of render |
| +0x152c (0x54b) | ptr | textureResource | FUN_0053ead0 | Texture resource ptr |
| +0x1524 (0x549) | ptr | resourceA | FUN_0053ead0 | Freed on cleanup |
| +0x1528 (0x54a) | ptr | resourceB | FUN_0053ead0 | Freed on cleanup |
| +0x152c | ptr | extraTexture | FUN_0053f270, FUN_0053ead0 | Released via FUN_0053f6e0 |
| +0x13a0 | int | renderState | FUN_0053f270 | Set to 1 during cleanup |
| +0x13a8 | int | cleanupFlags | FUN_0053f270 | Bit 28 = needs cleanup |
| +0x1140 | ptr | frontBuffer | FUN_0053f270 | D3D front buffer |
| +0x113c | ptr | backBuffer | FUN_0053f270 | D3D back buffer |
| +0x1144 | ptr | depthStencil | FUN_0053f270 | D3D depth/stencil |
| +0x14f0..0x1504 | int[5] | viewportDims | FUN_0053f270 | Zeroed during cleanup |
| +0x1518 | ptr | textureList | FUN_0053f270 | Linked list of loaded textures |
| +0x1580 | ptr | targetList | FUN_0053f270 | Linked list of render targets |
| +0x704 | float[16] | viewMatrix | FUN_004c71c0 | View transformation 4x4 |
| +0x744 | float[16] | worldMatrix | FUN_004c71c0 | World transformation 4x4 |
| +0x83c | float[3]×4 | wheelPositions | FUN_004c71c0 | 4 wheel positions, stride 0x128 |
| +0x34f8 | float[4] | diffuseColor | FUN_004c71c0 | Diffuse lighting RGBA |
| +0x3510 | float[4] | specularColor | FUN_004c71c0 | Specular lighting RGBA |
| +0x3540 | int | envMapHandle | FUN_004c71c0 | Environment map texture handle |

## Camera/Projection Struct (inferred)

Used by FUN_004c7f30, FUN_00542050, possibly FUN_00542200.
Stores viewport/projection parameters and FOV settings.

Based on 2+ function observations. Confidence: high.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x04 | float | nearClipZ | FUN_00542050 | Near clipping plane Z |
| +0x08 | float | farClipZ | FUN_00542050 | Far clipping plane Z |
| +0x0c | float | projScaleX | FUN_00542050 | Projection X scale |
| +0x10 | float | projScaleY | FUN_00542050 | Projection Y scale |
| +0x14 | float | widthFloat | FUN_00542200 | Viewport width as float |
| +0x18 | float | heightFloat | FUN_00542200 | Viewport height as float |
| +0x1c | float | tanHalfFovX | FUN_00542050 | tan(FOV_X/2) |
| +0x20 | float | tanHalfFovY | FUN_00542050 | tan(FOV_Y/2) |
| +0x54 | int | screenWidth | FUN_00542050, FUN_00542200 | Screen width in pixels |
| +0x58 | int | screenHeight | FUN_00542050, FUN_00542200 | Screen height in pixels |
| +0x5c | int | centerX | FUN_00542200 | Viewport center X |
| +0x60 | int | centerY | FUN_00542200 | Viewport center Y |
| +0x6c | float | fov | FUN_00542050, FUN_004c7f30 | Field of view |
| +0x70 | float | pitch | FUN_00542050 | Vertical angle |
| +0x74 | float | aspectRatio | FUN_00542200 | width/height |
| +0x78 | float | farDiagonal | FUN_00542050 | Far plane diagonal distance |
| +0x80 | int | flags | FUN_00542050, FUN_00542200 | Bit 4 = negate projection X |
| +0x9c..0xd8 | float[15] | viewMatrix | FUN_00542050 | 3×3 orientation matrix |
| +0xec..0xf8 | float[3] | translation | FUN_00542050 | Zeroed translation |
| +0xdc..0xe8 | float[3] | forwardZ | FUN_00542050 | Forward vector Z component |
| +0x19c | ptr | chainTexture | FUN_00495dc0 | Dereference chain to source texture |

## Transform/4x4 Matrix Struct (inferred)

Used by FUN_0054b570, FUN_00541db0. Holds Euler-angle orientation and
4x4 transformation matrix with backup copy.

Based on 2 function observations. Confidence: high.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x20 | float | positionX | FUN_0054b570 | Translation X |
| +0x24..0x2c | float[3] | inputVec | FUN_00541db0 | Input direction vector (x,y,z) |
| +0x2c | float | yaw | FUN_0054b570, FUN_00541db0 | Heading/rotation about Y |
| +0x30 | float | pitch | FUN_0054b570, FUN_00541db0 | Rotation about X |
| +0x34 | float | roll | FUN_0054b570, FUN_00541db0 | Rotation about Z |
| +0x38 | float | rollAlt | FUN_00541db0 | Roll angle (random) |
| +0x40 | int | matrixSlot | FUN_0054b570 | Non-0 = use alt slot (+0xd4) |
| +0xd4/0xe4/0xf4 | float[12] | matrixAlt | FUN_0054b570 | Alternate transform slot |
| +0x114/124/134 | float[12] | matrixRows | FUN_0054b570 | Primary 4×4 rows 0/1/2 |
| +0x144/0x104 | float[4] | positionRow3 | FUN_0054b570 | Translation row + W=1 |
| +0x154 | float[16] | matrixBackup | FUN_0054b570 | Cached copy of 4×4 |
| +0x15c..0x198 | float[16] | rotMatrix | FUN_00541db0 | 4×4 rotation matrix |
| +0x18c | float | resultX | FUN_00541db0 | Rotated vector X |
| +0x190 | float | resultY | FUN_00541db0 | Rotated vector Y |
| +0x194 | float | resultZ | FUN_00541db0 | Rotated vector Z |
| +0x198 | float | one | FUN_00541db0 | Constant 1.0 |

## Texture/Surface Format Struct (inferred)

Used by FUN_0050ab51, FUN_00518248, FUN_00586d70, FUN_00558d80,
FUN_00558d10, FUN_00558dc0. Holds surface dimensions, pitch, pixel format,
and buffer pointers.

Based on 6+ function observations. Confidence: medium.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | int | width | FUN_00518248, FUN_00552f20 | Surface width (updated on stretch) |
| +0x04 | int | height | FUN_00552f20 | Surface height |
| +0x0b | byte | bpp | FUN_00518248 | Bits per pixel (1/2/4/8+) |
| +0x14 | ptr | bitmapData | FUN_00586d70 | Raw bitmap data ptr |
| +0x1c | ptr | bitmapHeader | FUN_00586d70 | Bitmap header struct |
| +0x20 | int | flags | FUN_00558d80, FUN_00558dc0 | Bit 0x100 = locked, sign bit for render mode |
| +0x34 | ptr | rowLookup | FUN_00558dc0 | Row lookup table |
| +0x38 | int | regionStride | FUN_00586d70 | Scan offset into bitmap |
| +0x4c | int | renderMode | FUN_00558dc0 | Render mode flag (gated: ==1) |
| +0x50 | ptr | surfaceArray | FUN_00558d80, FUN_00558dc0 | Surface slot array base, pixel buffer |
| +0x1050 | int | yPitch | FUN_0050ab51, FUN_00503920 | Y plane pitch in bytes |
| +0x1054 | int | uvPitch | FUN_0050ab51 | UV plane pitch |
| +0x106c | ptr | outputBuffer | FUN_0050ab51 | Output float RGBA buffer |
| +0x1070 | int | outputStride | FUN_0050ab51 | Output stride in pixels |
| +0x1074 | int | dirtyLeft | FUN_0050ab51 | Dirty rect left |
| +0x1078 | int | dirtyRight | FUN_0050ab51 | Dirty rect right |
| +0x107c | int | dirtyTop | FUN_0050ab51 | Dirty rect top |
| +0x1080 | int | dirtyBottom | FUN_0050ab51 | Dirty rect bottom |
| +0x1084 | int | width | FUN_0050ab51 | Surface width |
| +0x1090 | int | bufferReady | FUN_0050ab51 | Flag (non-zero = ready) |
| +0x1094 | int | bitDepth | FUN_0050ab51 | Bits per channel |
| +0x1098 | int | bitShift | FUN_0050ab51 | Bit shift amount |

## D3D Render State Cache (inferred)

Used by FUN_00586700. Stores per-D3DRS cached values for incremental
state updates.

Based on 1 function observation. Confidence: high.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x34 | int | D3DRS_1_Value | FUN_00586700 | Render state value for D3DRS 1 |
| +0x38 | int | D3DRS_8_Value | FUN_00586700 | Render state value for D3DRS 8 |
| +0x3c | int | D3DRS_1b_Value | FUN_00586700 | Render state D3DRS 0x1b |
| +0x40 | int | D3DRS_2_Value | FUN_00586700 | Render state value for D3DRS 2 |
| +0x44 | int | D3DRS_10_Value | FUN_00586700 | Render state D3DRS 0x10 |

## Animation State Struct (inferred)

Used by FUN_00486730, FUN_00403cd0. Timed animation trigger with
frame index, accumulator, and loop settings.

Based on 2 function observations. Confidence: medium.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x10 | int | maxFrames | FUN_00486730 | Frame count limit |
| +0x18 | int | duration | FUN_00486730 | Per-frame duration |
| +0x1c | int | loopMode | FUN_00486730 | 0=wrap, non-0=modulo |
| +0x28 | int | active | FUN_00486730 | 0=disabled |
| +0x80 | float | accumulator | FUN_00486730 | Elapsed time accumulator |
| +0x84 | int | stateID | FUN_00486730 | Animation state identifier |
| +0x88 | int | frameIndex | FUN_00486730 | Current animation frame |
| +0xdc | int | repeatCount | FUN_00486730 | Remaining repeats |
| +0x150 | float[7] | keyframeArray | FUN_00403cd0 | Frames: pos xyz + quaternion xyzw |

## Buffer/Mesh Allocation Struct (inferred)

Used by FUN_00403350. Manages multi-dimensional buffer allocation
with 3 buffer pointers (A/B/C) and 4 dimension fields.

Based on 1 function observation. Confidence: high.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x08 | int | initializedFlag | FUN_00403350 | Set to 1 after alloc |
| +0x0c | int | countA | FUN_00403350 | dimA + 1 |
| +0x10 | int | countB | FUN_00403350 | dimB + countA |
| +0x14 | int | totalCount | FUN_00403350 | countB + dimC |
| +0x150 | ptr | bufferBPtr | FUN_00403350 | dimB × 0x1C array |
| +0x154 | ptr | bufferAPtr | FUN_00403350 | dimC × 0x1C array |
| +0x158 | ptr | bufferCPtr | FUN_00403350 | dimD × dimC × 0x1C 2D array |
| +0x15c | int | dimA | FUN_00403350 | First dimension |
| +0x160 | int | dimB | FUN_00403350 | Second dimension |
| +0x164 | int | dimC | FUN_00403350 | Third dimension |
| +0x168 | int | dimD | FUN_00403350 | Fourth dimension |

## Spatial/BSP Node (stride 0x20) (inferred)

Used by FUN_0051d57f. Recursive spatial subdivision node with
bounding box and span data.

Based on 1 function observation. Confidence: high.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | int | minX | FUN_0051d57f | Bounding box min X |
| +0x04 | int | maxX | FUN_0051d57f | Bounding box max X |
| +0x08 | int | minY | FUN_0051d57f | Bounding box min Y |
| +0x0c | int | maxY | FUN_0051d57f | Bounding box max Y |
| +0x10 | int | minZ | FUN_0051d57f | Bounding box min Z |
| +0x14 | int | maxZ | FUN_0051d57f | Bounding box max Z |
| +0x18 | int | spanX | FUN_0051d57f | X span (maxX-minX) |
| +0x1c | int | spanY | FUN_0051d57f | Y span (maxY-minY) |
| +0x20 | int | spanZ | FUN_0051d57f | Z span (maxZ-minZ) |

## Mesh Bounding Box Struct (inferred)

Used by FUN_0054d9f0, FUN_0054b6190? Stores mesh bounds, flags,
and subset information.

Based on 1 function observation. Confidence: medium.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x14 | int | flags | FUN_0054d9f0 | 0x800000 = LOD mode, 0x80010000 = interpolation |
| +0x18 | float | boundingSphereRadius | FUN_0054d9f0 | sqrt of squared extent |
| +0x1c..0x78 | float[24] | aabbCorners | FUN_0054d9f0 | 8×3 floats (OBB corners) |
| +0xdc | float | centerX | FUN_0054d9f0 | (maxX+minX)×0.5 |
| +0x118 | int | subsetCount | FUN_0054d9f0 | Number of vertex subsets |
| +0x11c | ptr | subsetArray | FUN_0054d9f0 | Vertex array descriptors |

## D3D Vertex Buffer Object (inferred)

Used by FUN_0054ca00. Per-buffer state with block descriptors,
render flags, and device handle.

Based on 1 function observation. Confidence: medium.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x14 | int | flags | FUN_0054ca00 | 0x8000000=clip, 0x800000=alpha |
| +0x118 | int | numBlocks | FUN_0054ca00 | Sub-mesh block count |
| +0x11c | ptr | blockArray | FUN_0054ca00 | Block descriptor array |
| +0x138 | ptr | devicePtr | FUN_0054ca00 | D3D device pointer |

## Screen-Space Tile Renderer (inferred)

Used by FUN_00495dc0. Controls full vs tiled blit rendering.

Based on 1 function observation. Confidence: medium.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x1578 | int | renderMode | FUN_00495dc0 | 0=full blit, 1=tiled (80 steps) |
| +0x157c | ptr | chainPtr | FUN_00495dc0 | Dereference chain to source texture |
| +0x1580 | int | screenOffsetX | FUN_00495dc0 | Accumulated X scroll/offset |
| +0x1584 | int | screenOffsetY | FUN_00495dc0 | Accumulated Y scroll/offset |

## Resource Manager (texture loading) (inferred)

Used by FUN_0053d970. Per-resource state tracking with 6 resource slots.

Based on 1 function observation. Confidence: medium.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| param_1[0x43f] | ptr | resourceManager | FUN_0053d970 | Interface pointer with vtable |
| param_1[3..] | int[] | perResourceState | FUN_0053d970 | Stride 0x10f ints per resource |

## Texture Allocation Format Struct (inferred)

Used by FUN_00558d10. Dual-format texture allocation with state flag.

Based on 1 function observation. Confidence: medium.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x20 | uint | flags | FUN_00558d10 | Bit 0x100 = allocated |
| +0x2c | int | multiplier | FUN_00558d10 | Size multiplier for format path 2 |
| +0x50 | ptr | subStruct | FUN_00558d10 | Resource array ptr (stride 0x40) |

## Display Mode Init Struct (inferred)

Used by FUN_00563e00. Guards against re-init, stores mode/buffer handles.

Based on 1 function observation. Confidence: high.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | int | initialized | FUN_00563e00 | Non-zero = already done |
| +0x04 | int | modeHandle | FUN_00563e00 | Display mode init result |
| +0x94 | int | bufferHandle | FUN_00563e00 | Buffer creation result |
| +0x98 | int | bufferCount | FUN_00563e00 | Set to 0 |

## UI Control Struct (common) (inferred)

Used across many UI functions: FUN_004a70e0, FUN_00487400, FUN_00488180,
FUN_00489530, FUN_0048bbe0, FUN_0048e860, FUN_0048fdb0, etc. Large struct
with vtable, state fields, and function table slots.

Based on 15+ function observations. Confidence: medium.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | ptr | vtable | FUN_0048f640, FUN_00487400, FUN_00488180 | Virtual method table |
| +0x08 | ushort | renderMode | FUN_0040eb30 | Render mode flag |
| +0x0c | int | width | FUN_0048fdb0 | Width/dimension A |
| +0x10 | int | height | FUN_0048fdb0, FUN_0048f640 | Height/dimension B |
| +0x18 | ptr | nextNode | FUN_00486540 | Linked list next |
| +0x1c | int | typeID | FUN_0040eb30 | Type/ID (3 for camera/projection) |
| +0x20 | ptr/uint | reference/resource | FUN_0040eb30, FUN_0048f640, FUN_004c9310 | Reference parameter / flags |
| +0x24-0x28 | ptr[3] | resourcePtrs | FUN_004c9310 | 3 vtable+8 resource slots |
| +0x38 | char | visibility | FUN_0048bbe0 | Active/visibility flag |
| +0x3c | ptr | elementList | FUN_0048f640 | Linked list of layout elements |
| +0x3e | ptr | currentElement | FUN_0048f640 | Iterator during traversal |
| +0x40 | int | layoutMode | FUN_0048f640 | 0=horizontal, 1=vertical-first |
| +0x45 | byte | activeFlag | FUN_00488180 | Active/visible flag (1) |
| +0x48 | int | headerWidth | FUN_0048f640 | Fixed header width |
| +0x49 | int | contentWidth | FUN_0048f640 | Content/total width |
| +0x50 | int | headerHeight | FUN_0048f640 | Fixed header height |
| +0x51 | int | contentHeight | FUN_0048f640 | Content/total height |
| +0x54 | int | maxElementWidth | FUN_0048f640 | Maximum element width |
| +0x55 | int | maxElementHeight | FUN_0048f640 | Maximum element height |
| +0x56 | int | columnCount | FUN_0048f640 | Computed columns |
| +0x57 | int | rowCount | FUN_0048f640 | Computed rows |
| +0x58 | int | viewWidth | FUN_0048f640 | Visible viewport width |
| +0x59 | int | viewHeight | FUN_0048f640 | Visible viewport height |
| +0x5b | int | scrollRange | FUN_0048f640 | Computed scroll range |
| +0xe1 | char | secondaryFlag | FUN_0048bbe0 | Secondary active flag |
| +0xe8 | int | guardFlag | FUN_0048e860 | Conditional dispatch guard |
| +0x118 | ptr | ptrSlot1 | FUN_004a70e0 | First function ptr table entry |
| +0x130 | ptr | ptrSlot2 | FUN_004a70e0 | Second function ptr table entry |
| +0x14c | int | navigationPos | FUN_00489530 | Counter/navigation position |

## List Container (doubly-linked) (inferred)

Used by FUN_004967d0, FUN_004b9000, FUN_00486540. Generic
doubly-linked list with head/tail/element tracking.

Based on 3 function observations. Confidence: high.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x18cc | ptr | head | FUN_004967d0 | List head pointer |
| +0x18d0 | ptr | tailWrite | FUN_004967d0 | Tail write pointer |
| +0x18d4 | ptr | tailAlt | FUN_004967d0 | Alternative tail |
| +0x18d8 | int | elementCount | FUN_004967d0 | Element count |

## Linked List Node (inferred)

Used by FUN_00486540. Generic node for render/display lists.

Based on 1 function observation. Confidence: high.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | ptr | data | FUN_00486540 | Node data |
| +0x04 | ptr | next | FUN_00486540 | Next node pointer |
| +0x08 | ptr | prev | FUN_00486540 | Previous node pointer |

## Circular Buffer Slot Allocator (inferred)

Used by FUN_004cb540. Tracks max count, slot array, current index,
allocation count, and mapping.

Based on 1 function observation. Confidence: medium.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x58 | int | maxCount | FUN_004cb540 | Maximum slot count |
| +0x5c | ptr | slotArray | FUN_004cb540 | Slot array base ptr |
| +0x60 | int | currentIndex | FUN_004cb540 | Current allocation index |
| +0x64 | int | allocCount | FUN_004cb540 | Number of allocated slots |
| +0x68 | ptr | mappingArray | FUN_004cb540 | Index-to-slot mapping array |

## Render Args Struct (inferred)

Used by FUN_0058a40a, FUN_0058a4e5. Small struct for forwarding
render arguments.

Based on 2 function observations. Confidence: high.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x08 | int | arg1 | FUN_0058a40a, FUN_0058a4e5 | First extracted arg |
| +0x0c | int | arg2 | FUN_0058a40a, FUN_0058a4e5 | Second extracted arg |
| +0x10 | int | arg3 | FUN_0058a40a | Third extracted arg |
| +0x14 | int | arg4 | FUN_0058a4e5 | Fourth arg |
| +0x18 | ptr | dispatchFn | FUN_0058a4e5 | Jump-table dispatch function |
| +0x24 | int | stateFlag | FUN_0058a4e5 | Flag checked for early-out |

## Render Object / VTable Wrapper (inferred)

Used by FUN_0052e170. Constructor sets vtable and initializes
observer list and property fields.

Based on 1 function observation. Confidence: low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | ptr | vtable | FUN_0052e170 | Virtual method table |
| +0x90 | ptr | observerList | FUN_0052e170 | param_1[0x24] — observer list head |

## Pixel Compositing Struct (inferred)

Used by FUN_00503e36. Holds source and destination image
pointers for compositing/blitting.

Based on 1 function observation. Confidence: low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | ptr | srcPtr | FUN_00503e36 | Source image struct |
| +0x04 | ptr | dstPtr | FUN_00503e36 | Dest image struct (offset via +0x18) |

## Lazy Init Struct (inferred)

Used by FUN_004184f0. Guards subsystem initialization with
flag and resource handle.

Based on 1 function observation. Confidence: high.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0xaf0 | byte | initFlag | FUN_004184f0 | Non-zero if initialized |
| +0xaf4 | int | resourceHandle | FUN_004184f0 | Initialized resource handle |

## Render Property Slots (inferred)

Used by FUN_00554700. Stores value and index property slots
with vtable object for dispatch.

Based on 1 function observation. Confidence: medium.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x1398 | int | valueSlot1 | FUN_00554700 | Property value (param_1[0x4e6]) |
| +0x139c | int | valueSlot2 | FUN_00554700 | Property index (param_1[0x4e7]) |
| +0x1100 | ptr | vtableObj | FUN_00554700 | Object with vtable (param_1[0x440]) |

## Texture/Blit Render Struct (inferred)

Used by FUN_0048E4B0. Stores path strings, render enable flag,
dirty flag, and rect dimensions.

Based on 1 function observation. Confidence: low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0xb0 | ptr | pathStringA | FUN_0048E4B0 | Path string or null |
| +0xfc | ptr | pathStringB | FUN_0048E4B0 | Path string or null |
| +0xe4 | int | renderEnable | FUN_0048E4B0 | Non-zero enables render |
| +0xf8 | byte | dirtyFlag | FUN_0048E4B0 | Cleared after render |
| +0xe8 | int | rectX | FUN_0048E4B0 | Clear/render X |
| +0xec | int | rectY | FUN_0048E4B0 | Clear/render Y |
| +0xf0 | int | rectW | FUN_0048E4B0 | Clear/render W |
| +0xf4 | int | rectH | FUN_0048E4B0 | Clear/render H |

---

## Inline offset references (not in tables)

These offsets appear in function descriptions but not in structured tables.

### FUN_004c71c0 — SetupCarLightingAndRender
| +0x83c | float[3]×4 | WheelPositions | stride 0x128 between wheels |
| +0x704 | float[16] | ViewMatrix | |
| +0x744 | float[16] | WorldMatrix | |
| +0x34f8 | float[4] | DiffuseColor | |
| +0x3510 | float[4] | SpecularColor | |
| +0x3540 | int | EnvMapHandle | |

### FUN_0053f270 — RenderTargetCleanup
| +0x1140 | ptr | FrontBuffer | |
| +0x113c | ptr | BackBuffer | |
| +0x1144 | ptr | DepthStencil | |
| +0x14f0..0x1504 | int[5] | ViewportDims | |
| +0x1518 | ptr | TextureList | Linked list |
| +0x1580 | ptr | RenderTargetList | |
| +0x13a8 | int | CleanupFlag | Bit 28 |
| +0x13a0 | int | RenderState | Set to 1 |

### FUN_003f270 / FUN_003ead0 shared
| +0x152c | ptr | ExtraTexture | |

### Inline from many functions
| +0x14 | int | flags | 0x800000(clip), 0x8000000(alpha), 0x4000(visible), etc. |

## Offset conflicts

| Offset | Conflict | Functions | Resolution |
|--------|----------|-----------|------------|
| +0x14 | int flags | FUN_0054ca00 (0x8000000 clip), FUN_0054d9f0 (0x800000 LOD), FUN_004e2d00 (bit 26 transformed) | Same struct? Unlikely — different struct types, likely int flags in each |
| +0x20 | different usage | FUN_0040eb30 (ref param), FUN_00558d80 (flags), FUN_00558dc0 (byte flag), FUN_00586d70 (bitmap data) | Different struct types — not same struct |
| +0x50 | different usage | FUN_00558d80 (surface array ptr), FUN_00558dc0 (pixel buffer ptr), FUN_00558d10 (sub-struct ptr) | Same texture manager struct across these functions — consistent |

## Notes

- Many FUN_ entries do NOT have formal struct offset tables — they describe
  offsets inline in prose. All inline offsets in 19-renderer.md have been
  captured in this synthesis.
- The large RenderContext struct spans many functions and likely represents
  the main `RenderDevice` or `Renderer` C++ class with D3D device interface,
  render states, buffers, and per-frame state.
- UI functions (FUN_0048*) share a common UI control struct pattern with
  vtable at +0x00 and various state fields in the +0x00-0x200 range. The
  exact field layout varies by control type but follows a consistent pattern.
- offset 0x14 appears as "flags" in many contexts — this is polymorphic and
  depends on the struct type.

---

## Source: docs/17-physics-collision.md

Source file: `docs/17-physics-collision.md` (5,822 lines, ~343 function entries)
Extracted: **41 struct offset tables**, 100+ offset observations

---

## CollisionBody (inferred — rigid body physics state)

Based on 6 function observations (FUN_00436870, FUN_004542d0, FUN_00457a00, FUN_004584c0, FUN_004987b0, FUN_0044fee0). Confidence: **high**.

This is the primary rigid body collision structure — contains contact geometry, friction model, impulse accumulation, and body state flags. Large struct likely spanning 0x0000–0x1184+.

| Offset | Type | Field | Observed in | Notes |
|--------|------|-------|-------------|-------|
| +0x040 | float[3] | AxisCoeff | FUN_004542d0 | Per-axis scaling coefficient |
| +0x060 | float[3] | AxisMin | FUN_004542d0 | AABB min bounds |
| +0x068-0x070 | int32[3] | BodyStateFlags | FUN_004987b0 | Collision body type flags |
| +0x084-0x08C | int32[3] | ContactStateFlags | FUN_004987b0 | Per-contact state flags |
| +0x090 | float | ContactPosX | FUN_00457a00 | Contact point world X |
| +0x094 | float | ContactPosY | FUN_00457a00, FUN_004039c0, FUN_004038e0 | Contact/position Y |
| +0x098 | float | ContactPosZ | FUN_00457a00, FUN_004039c0, FUN_004038e0 | Contact/position Z |
| +0x0A4 | float | RestitutionFactor | FUN_004584c0, FUN_00403aa0 | Restitution coefficient / normal X |
| +0x0AC | float | NormalZ | FUN_00403aa0, FUN_004038e0, FUN_00456f70 | Collision normal Z / body collision base |
| +0x0D8 | double | PositionX | FUN_004599c0 | Body position X (double) |
| +0x0E0 | double | PositionY | FUN_004599c0 | Body position Y |
| +0x0E4 | float | FrictionAccum1 | FUN_00436870 | Accumulated friction displacement |
| +0x0E8 | double | PositionZ | FUN_004599c0 | Body position Z |
| +0x0EC | float | FrictionAccum2 | FUN_00436870 | Accumulated friction displacement |
| +0x0F4 | float | FrictionAccum3 | FUN_00436870 | Accumulated friction displacement |
| +0x0FC | float | ContactPointWorldX | FUN_00436870 | X of contact point |
| +0x100 | float | ContactPointWorldY | FUN_00436870 | Y of contact point |
| +0x100 | int | FlagA | FUN_004987b0 | First-level branch flag (int32) — note: overlaps ContactY, may be union |
| +0x10C | int* | NextPrimary | FUN_00403aa0, FUN_004039c0 | Primary child / linked list next |
| +0x110 | int* | NextSecondary | FUN_00403aa0, FUN_004039c0 | Sibling/alternative / return value |
| +0x12C | int | TypeFilterField | FUN_004038e0 | Entity/type filter |
| +0x134 | float | FrictionMagnitude | FUN_00436870 | |
| +0x144 | float | StiffnessTerm | FUN_00436870 | Spring-like term |
| +0x15C | int* | TriangleDataPtr | FUN_00436870 | Pointer to triangle vertices |
| +0x180 | uint32 | MassLow | FUN_00459950 | Low part of mass double |
| +0x184 | uint32 | MassHigh | FUN_00459950 | High part of mass double |
| +0x188 | double | InvMass | FUN_00459950 | 1.0/mass |
| +0x200 | float | TimeAccum | FUN_004987b0 | Accumulated timestep |
| +0x20C | float | Damping | FUN_00436870 | Velocity damping |
| +0x214 | float | Restitution | FUN_00436870 | Bounce coefficient |
| +0x21C | float | HalfExtent | FUN_00436870 | Bounding radius |
| +0x224 | float[3] | RotationMatrix | FUN_00436870 | Body orientation row |
| +0x264 | int | BestTriIndex | FUN_00436870 | Which triangle face hit |
| +0x278 | int | CullFlag | FUN_0044efe0 | Collision culling enable flag |
| +0x27C–0x290 | float | FrictionCurveParams | FUN_00436870 | Falloff coefficients |
| +0x27C | byte[] | PropertyBlock | FUN_0044f050 | Per-node byte properties |
| +0x298–0x2D0 | float | FrictionFalloff | FUN_00436870 | cos/sin friction curve |
| +0x2E4 | float | FrictionScale | FUN_00436870 | Overall friction scalar |
| +0x2EC | float | RollingResistance | FUN_00436870 | Rolling resistance factor |
| +0x2F4 | int | StoredParam | FUN_0044fbb0, FUN_0044fbe0 | Reference/state flag |
| +0x304 | float | StiffnessAngle | FUN_00436870 | Angle for stiffness response |
| +0x314 | float | RandomSeed | FUN_00436870 | Stochastic element |
| +0x31C | float | ContactForce | FUN_00436870 | Normal impulse magnitude |
| +0x31C | int | ContactCount | FUN_0045b840 | Number of active contacts |
| +0x320 | float | ContactEnergy | FUN_0045b840 | Per-contact energy (stride 0x90) |
| +0x324 | float | PenetrationDepth | FUN_00436870 | Signed distance |
| +0x32C | float | ContactArea | FUN_00436870 | Contact patch size |
| +0x344 | float | FlagA_first | FUN_004a6b80 | collision active flag |
| +0x37C | byte[256] | NodeActiveFlags | FUN_0044f0a0, FUN_0044f0e0 | Per-node active flag |
| +0x398 | float[3] | AxisMax | FUN_004542d0 | AABB max bounds |
| +0x39C | float | SurfaceFrictionScale | FUN_00436870 | Per-triangle friction |
| +0x560 | double | LinearImpulseX | FUN_0044fee0 | Accumulated linear impulse |
| +0x568 | double | LinearImpulseY | FUN_0044fee0 | |
| +0x570 | double | LinearImpulseZ | FUN_0044fee0 | |
| +0x578 | double | AngularImpulseX | FUN_0044fee0 | Accumulated angular impulse |
| +0x580 | double | AngularImpulseY | FUN_0044fee0 | |
| +0x588 | double | AngularImpulseZ | FUN_0044fee0 | |
| +0x828 | int[4] | WheelActiveFlags | FUN_004e96c0 | Per-wheel active, stride 0x4a |
| +0x87C | int[256] | ChildIndices | FUN_0044f0a0, FUN_0044f0e0 | Child node indices |
| +0xC84 | int | LeafCount | FUN_0044f0a0 | Number of leaf nodes |
| +0xC88 | int[12] | LeafNodes | FUN_0044f0a0 | Leaf node indices |
| +0xD88 | float[] | BodyAGeom1 | FUN_004542d0 | Primary collision set A data |
| +0x1184 | float[] | BodyAGeom2 | FUN_004542d0 | Secondary collision set A data |

**Conflicts:**
- +0x100: FUN_00436870 says float (ContactPointWorldY), FUN_004987b0 says int32 (FlagA) — likely same field used as union or type-dependent
- +0x31C: FUN_00436870 says float (ContactForce), FUN_0045b840 says int (ContactCount) — could be same lane read as different types

---

## BVH/SpatialTreeNode (inferred)

Based on 4 function observations (FUN_00403aa0, FUN_004039c0, FUN_0044aa30, FUN_004038e0). Confidence: **high**.

| Offset | Type | Field | Observed in | Notes |
|--------|------|-------|-------------|-------|
| +0x08 | short | NodeIdx | FUN_0044aa30 | Negative=leaf, 0=axis test |
| +0x0A | short | AxisIdx | FUN_0044aa30 | Comparison axis selector |
| +0x0C | int* | ChildPtr | FUN_0044aa30 | Child/sibling node pointer |
| +0x3C | float | Stride | FUN_004039c0 | Element stride |
| +0x94 | float | PosX | FUN_00403aa0, FUN_004039c0, FUN_004038e0 | Node center X |
| +0x98 | float | PosY | FUN_00403aa0, FUN_004039c0, FUN_004038e0 | Node center Y |
| +0x9C | float | PosZ | FUN_00403aa0, FUN_004039c0, FUN_004038e0 | Node center Z |
| +0xA4 | float | NormalX | FUN_00403aa0, FUN_004038e0 | Split plane normal X |
| +0xAC | float | NormalZ | FUN_00403aa0, FUN_004038e0 | Split plane normal Z |
| +0x10C | int* | NextPrimary | FUN_00403aa0 | Primary child / linked list |
| +0x110 | int* | NextSecondary | FUN_00403aa0, FUN_004039c0, FUN_004038e0 | Sibling/alternate / return value |
| +0x12C | int | CategoryTag | FUN_004038e0, FUN_00403aa0 | Match filter/type field (+300) |

---

## CollisionLinkedNode (inferred — generic collision/proxy linked list node)

Based on 4 function observations (FUN_00494e60, FUN_004bac20, FUN_004ba140, FUN_004bad70). Confidence: **high**.

| Offset | Type | Field | Observed in | Notes |
|--------|------|-------|-------------|-------|
| +0x00 | int* | Data | FUN_004bac20, FUN_00494e60 | Proxy data pointer / resource handle |
| +0x04 | int* | Next | FUN_004bac20, FUN_00494e60 | Next node pointer |
| +0x08 | byte | Flag | FUN_004bac20, FUN_00494e60 | Byte flag/type, non-zero=active |

---

## DualLinkedListHeader (inferred)

Based on 2 function observations (FUN_004bad70, FUN_00490d00). Confidence: **high**.

| Offset | Type | Field | Observed in | Notes |
|--------|------|-------|-------------|-------|
| +0x00 | int* | ListA_Head | FUN_004bad70 | Primary list head |
| +0x04 | int* | ListA_Tail | FUN_004bad70 | Primary list tail |
| +0x08 | int* | ListA_Last | FUN_004bad70 | Primary list iterator/last |
| +0x0C | int | ListA_Count | FUN_004bad70 | Primary list element count |
| +0x10 | int* | ListB_Head | FUN_004bad70 | Secondary list head |
| +0x14 | int* | ListB_Tail | FUN_004bad70 | Secondary list tail |
| +0x18 | int* | ListB_Last | FUN_004bad70 | Secondary list iterator/last |
| +0x1C | int | ListB_Count | FUN_004bad70 | Secondary list element count |

---

## CollisionGridParams (inferred — broadphase grid state)

Based on 8 function observations (FUN_0044d520/FUN_0044dca0/etc — grid init functions, FUN_0044ba40). Confidence: **medium**.

Many init functions across 0x007cxxxx globals appear to follow this pattern per grid cell:
| Offset | Type | Field | Observed in | Notes |
|--------|------|-------|-------------|-------|
| +0x00 | int | CellCount | Multiple init functions | Grid cell count (varies: 4, 16, 37, 49, 77, 97) |
| +0x04 | int | Flags/Counter | init patterns | Zeroed field |
| +0x08 | int | Sentinel/Scale | init patterns | Often -1.0f (0xBF800000) as sentinel or 1.0f |
| +0x0C | int | MaxDistance | init patterns | 9000 or 27000 for search radius |

Per-grid-cell stride = 0x10 (16 bytes) based on the 4-field pattern.

---

## CollisionMaterialGroup (inferred)

Based on 8 function observations (FUN_0044da60, FUN_0044d5e0, various material init functions). Confidence: **high**.

| Offset | Type | Field | Observed in | Notes |
|--------|------|-------|-------------|-------|
| +0x00 | int | MaterialID | Multiple material init functions | Type/subtype ID (varies: 7, 19, 40, 52, 80, 100) |
| +0x04 | int | ParamA | init patterns | Zeroed |
| +0x08 | int | ParamB | init patterns | Zeroed |
| +0x0C | float | Coefficient | init patterns | 1.0f (restitution default) or 18000 (range) |

Stride 0x10–0x14 per material entry based on pattern.

---

## WheelContactState (inferred — per-wheel collision from vehicle struct)

Based on FUN_004e96c0. Confidence: **high**. Offsets relative to vehicle struct base.

| Offset | Type | Field | Observed in | Notes |
|--------|------|-------|-------------|-------|
| +0x828 | int[4] | WheelActiveFlags | FUN_004e96c0 | Per-wheel active flags, stride 0x4a |
| +0x34D4 | float[3] | VehiclePos | FUN_004e96c0 | Vehicle position (x, y, z) |
| +0x3AAC | float[3] | TargetPos | FUN_004e96c0 | Contact point / target |
| +0x3B6C | float | SuspensionTravel | FUN_004e96c0 | Suspension travel bounds |

---

## CollisionDeformationMesh (inferred — param_1 in FUN_004DF110)

Based on FUN_004DF110. Confidence: **medium**.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x00 | float | MaxValue | Current max, updated to param_2 |
| +0x08 | int | GroupCount | Number of vertex groups |
| +0x0C | int* | GroupArray | Pointer to group data (stride 0xC) |
| +0x10 | int | EntityCount | Number of entities |
| +0x14 | int* | EntityArray | Pointer to entity array |
| +0x18 | int | EntryCount | Number of entries |
| +0x1C | float* | EntryArray | Entries start (stride 9 floats = 0x24 bytes) |

---

## CollisionResponseState (inferred — param_1 in FUN_004a6b80, FUN_00453100, FUN_00462ce0)

Based on 3 function observations. Confidence: **medium**.

| Offset | Type | Field | Observed in | Notes |
|--------|------|-------|-------------|-------|
| +0x10 | int | CollisionThreshold | FUN_00462ce0 | Threshold value from _DAT_0059f0a0 |
| +0x29 | byte | ActiveFlag | FUN_00462ce0 | Collision response active |
| +0x374 | int | ResponseFlag | FUN_00463cd0 | Collision response flag |
| +0x388 | float | SpeedParam | FUN_004636a0 | Vehicle speed/parameter |
| +0x3FC4 | int | CollisionType | FUN_00462ce0, FUN_00462940, FUN_0045f390 | Collision type code |

---

## BSPTreeNode (inferred — param_1/param_2 in FUN_0044a4b0)

Based on FUN_0044a4b0. Confidence: **medium**.

**Node output (param_1):**
| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x08 | short | SplitDir | 0=left child, 1=right child, 0xffff=leaf, 0xfffe=2-node |
| +0x0A | short | SplitIndex | Index of split plane (0..14) |
| +0x0C | int* | VertexPtr | Output vertex buffer pointer |

**Allocator context (param_2):**
| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x1C | int | NodeCount | Total nodes allocated |
| +0x1C | int* | NextPtr | Linked list next (same offset as NodeCount — union/overlap?) |
| +0x24 | int* | DataBase | Base of data buffer |
| +0x28 | int | VertexCount | Vertex count |
| +0x30 | int* | VertexBase | Base of vertex buffer |
| +0x34 | int | SomeParam | Parameter passed to children |

**Conflict:** +0x1C used as both int (nodeCount) and int* (nextPtr) — likely same field reused depending on node type.

---

## CollisionDamageContactStore (inferred — FUN_0045b840)

Based on FUN_0045b840. Confidence: **medium**.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x31C | int | ContactCount | Number of active contacts |
| +0x320 | float | ContactEnergy | Per-contact at stride 0x90 |
| +0x3C (per contact) | float[3] | ContactPosition | Contact world position |
| +800 (0x320) | byte | DecayDoneFlag | Flag for decay completion |

**Note:** +0x320 appears to be both ContactEnergy base and DecayDoneFlag (at offset 0x320 which = 800 decimal). Likely different fields in different struct contexts — ContactEnergy is per-contact within the stride, DecayDoneFlag is a single byte at absolute offset 0x320.

---

## ViewportRect (inferred — param_1 in FUN_0044f680)

Based on FUN_0044f680. Confidence: **medium**.

| Index | Type | Field | Notes |
|-------|------|-------|-------|
| [0] | int | left | Viewport left |
| [1] | int | top | Viewport top |
| [2] | int | right | Viewport right |
| [3] | int | bottom | Viewport bottom |
| [4] | int | center_x | Computed center X |
| [5] | int | center_y | Computed center Y |
| [6] | int | scale_x | Fixed-point X scale |
| [7] | int | scale_y | Fixed-point Y scale |

---

## CollisionRaycastPlane (inferred — param_1 in FUN_0044ba40)

Based on FUN_0044ba40. Confidence: **medium**.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x004 | int | PlaneActive | Guard flag |
| +0x008 | double | OriginX | Plane origin X |
| +0x010 | double | PlaneWidth | Plane width |
| +0x018 | double | OriginY | Plane origin Y |
| +0x020 | double | PlaneHeight | Plane height |
| +0x028 | float[1024] | ResultBuffer | 32×32 raycast results |

---

## ProximitySphere (inferred — entry in FUN_004bda20)

Based on FUN_004bda20. Confidence: **high**.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x04 | int | Tag | Owner/type tag |
| +0x0C | float | CenterX | Sphere center X |
| +0x10 | float | CenterY | Sphere center Y |
| +0x14 | float | CenterZ | Sphere center Z |
| +0x18 | float | Radius | Sphere radius |
| +0x20 | int | ExcludeTag | Exclude from matching |

---

## SpringDamperState (inferred — param_1 as int[] in FUN_0044f6f0)

Based on FUN_0044f6f0. Confidence: **medium**.

| Index | Field | Notes |
|-------|-------|-------|
| [0x00] | MinVelocity | Velocity lower bound |
| [0x01] | MaxVelocity | Velocity upper bound |
| [0x02] | MinPosition | Position lower bound |
| [0x03] | MaxPosition | Position upper bound |
| [0x04] | PrevPosition | Previous frame position |
| [0x05] | PrevParam3 | Previous param_3 value |
| [0x06] | SpringK1 | Spring coefficient (float bit pattern) |
| [0x07] | SpringK2 | Secondary spring coefficient |
| [0x08] | DeltaPosition | Computed position delta |
| [0x09] | DeltaVelocity | Computed velocity delta |
| [0x0A] | OutputPosition | Clamped position × K1 |
| [0x0B] | OutputVelocity | Clamped velocity × K2 |
| [0x2C-0x2F] | Coeffs | Coefficient registers |

---

## SensorState (inferred — param_1 in FUN_00464a40)

Based on FUN_00464a40. Confidence: **low** (single function).

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x068 | int | SensorTimeout | Sensor timeout value |
| +0x06C | byte | SensorState | Sensor state flag |
| +0x071 | undefined4 | SensorValue | Sensor reading (float?) |

---

## CollisionPositionStepper (inferred — param_1 in FUN_0048cb00)

Based on FUN_0048cb00. Confidence: **low** (single function).

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0xCA*4 | int | ArrayDimA | Array dimension A |
| +0xCB*4 | int | ArrayDimB | Array dimension B |
| +0xCD*4 | int | CurrentPosition | Cyclic position index |
| +0xCE*4 | int | PositionScale | Position scaling factor |
| +0xCF*4 | char | DirectionFlag | Direction sign (0 = negate) |
| +0xD0*4 | int | Accumulator | Fixed-point time accumulator |

Note: Offsets are int-indexed (multiply by 4 for byte offset).

---

## OscillatoryCollisionState (inferred — FUN_0045c7e0 / FUN_0045c8f0)

Based on 2 function observations. Confidence: **low**.

| Offset | Type | Field | Observed in | Notes |
|--------|------|-------|-------------|-------|
| +0x00 | float | Accum0 | FUN_0045c7e0 | Primary accumulator |
| +0x04 | float | Accum1 | FUN_0045c7e0 | Secondary accumulator |
| +0x08 | float | Accum2 | FUN_0045c7e0 | Tertiary accumulator |
| +0x0C | int | OverflowScaled | FUN_0045c7e0 | Overflow scaled result |
| +0x10 | float | Accum3 | FUN_0045c7e0 | |
| +0x14 | float | Accum4 | FUN_0045c7e0 | |
| +0x68 (stride) | float | ContactTimer[i] | FUN_0045c8f0 | Per-contact timers |
| +0x1B4+id*4 | float | ContactThreshold[i] | FUN_0045c8f0 | Per-contact threshold |
| +0x354+id | byte | ContactActive[i] | FUN_0045c8f0 | Per-contact active flag |
| +0x3BC+id | byte | ContactPosIdx[i] | FUN_0045c8f0 | Per-contact position index |
| +0x1124+id*4 | float | ContactOutput[i] | FUN_0045c8f0 | Per-contact output (-1.0f) |

---

## CollisionProxyRegistration (inferred — param_1 in FUN_0044f0e0)

Based on FUN_0044f0e0 + FUN_0044f0a0. Confidence: **medium**.

| Offset | Type | Field | Observed in | Notes |
|--------|------|-------|-------------|-------|
| +0x37C | byte[256] | ProxyActiveFlags | FUN_0044f0e0, FUN_0044f0a0 | Per-proxy active flag |
| +0x87C | int[256] | ProxyChildIndices | FUN_0044f0e0, FUN_0044f0a0 | Per-proxy child indices |
| +0xC88 | int[12] | ProxyLeafNodes | FUN_0044f0e0, FUN_0044f0a0 | Leaf node indices |

---

## CollisionElementArray (inferred — param_1 in FUN_004046b0)

Based on FUN_004046b0. Confidence: **low** (single function).

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x10 | int | Threshold | Comparison threshold |
| +0x130 | int | ElementCount | Array length |
| +0x134 | int* | ElementArray | Array base (stride 0x13C) |

Elements have stride 0x13C with known sub-fields:
| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x04C | float | AccumValue | Accumulated value within element |
| +0x10C | int* | NextLink | Linked list link |
| +0x110 | int* | NextSibling | Linked list sibling |
| +300 (0x12C) | int | TypeFilter | Type/classification field |

---

## CollisionShapeClassifier (inferred — param_1 in FUN_004139c0 / FUN_00412c30)

Based on 2 function observations. Confidence: **medium**.

| Offset | Type | Field | Observed in | Notes |
|--------|------|-------|-------------|-------|
| +0x08 | int | ShapeClass | FUN_004139c0, FUN_00412c30 | Size class (0x20-0x2f) or bone index (0x99-0xBD) |
| +0x0C | int | SecondaryClass | FUN_004139c0, FUN_00412c30 | Secondary class / bone-related value |

**Conflict:** +0x08 used as both SizeClass and BoneIndex — these are different structs; same offset pattern reused.

---

## ImpulseAccumulator (inferred — param_1 in FUN_0044fee0)

Based on FUN_0044fee0. Confidence: **medium**.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x560 | double | LinearImpulseX | Accumulated linear impulse |
| +0x568 | double | LinearImpulseY | |
| +0x570 | double | LinearImpulseZ | |
| +0x578 | double | AngularImpulseX | Accumulated angular impulse |
| +0x580 | double | AngularImpulseY | |
| +0x588 | double | AngularImpulseZ | |

---

## CollisionDataBlock (inferred — param_1 in FUN_0044fbb0)

Based on FUN_0044fbb0, FUN_0044fbe0, FUN_0044efc0. Confidence: **medium**.

| Offset | Type | Field | Observed in | Notes |
|--------|------|-------|-------------|-------|
| +0x080 | int* | VTablePtr | FUN_0044fbe0, FUN_0044f7f0 | Vtable/collision object pointer |
| +0x084 | int[0x91] | DataBlock | FUN_0044fbb0, FUN_0044efc0 | Collision data payload (364–580 bytes) |
| +0x278 | int | Handle | FUN_0044efc0 | Handle/ID |
| +0x2F4 | int | StoredParam | FUN_0044fbb0, FUN_0044fbe0 | Reference/state flag |

---

## CollisionNoiseRange (inferred — param_1 in FUN_004962c0)

Based on FUN_004962c0. Confidence: **low** (single function).

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x162C | float[16] | NoiseRangeTable | Base range for noise, indexed by param_3 |

---

## Small structs (single observation)

### InvDistance (FUN_0045f2a0)
| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x04 | float | InvDistance | 1.0/distance |

### FloatFraction (FUN_00464ef0)
| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x68 | float | ComputedFraction | Iterative float conversion result |

### CollisionFillBlock (FUN_0044f070)
| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x27C | byte[0x100] | FillBlock | 0x40 dword fill block |

### ConstraintSolverState (FUN_00454250)
| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x040 | float | Stiffness | Constraint stiffness |
| +0x060 | float | RestValue | Constraint rest value |
| +0x398 | float | CurrentValue | Constraint current value |
| +0xD88 | float[] | ConstraintSet1 | Primary constraint set |
| +0x1184 | float[] | ConstraintSet2 | Secondary constraint set |

---

## CollisionContactSolver (inferred — param_1 in FUN_0045c8f0)

Based on FUN_0045c8f0. Confidence: **medium**.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x04 | byte | ContactCountAccum | Accumulated byte count |
| +0x08 | int | ContactCount | Contact count accumulator |
| +0x14+id*4 | int | ContactActiveFlag[i] | Per-contact active flag |
| +0x1B4+id*4 | float | ContactTimer[i] | Per-contact timer |
| +0x354+id | byte | ContactPosition[i] | Per-contact position index (capped 0x10) |
| +0x3BC+id | byte | ContactWrapIndex[i] | Per-contact wrap index (masked to 0xF) |
| +0x1124+id*4 | float | ContactOutput[i] | Per-contact output value |

---

## AnimationFrameTimer (inferred — param_1 in FUN_00469dd0)

Based on FUN_00469dd0. Confidence: **low**.

| Index | Type | Field | Notes |
|-------|------|-------|-------|
| [0x5D] | float | FrameTimer | Accumulated frame time |
| [0x5E] | int | FrameIndex | Animation frame index (wraps at DAT_007d2dcc) |

---

## Tire/vehicle struct (partial from FUN_004a6b80 comments)

Based on FUN_004a6b80 description. Confidence: **low** — listed in comments but not explicitly tabulated.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x344C | int | ActiveFlag | Vehicle collision active |
| +0x34E0 | float[3] | Position | Vehicle position |
| +0x34F8 | float[3] | Direction | Vehicle direction normal |

---

## ConstraintForceState (inferred — param_1 in FUN_00454250)

Based on FUN_00454250. Confidence: **low**.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x040 | float | Stiffness | Constraint stiffness coefficient |
| +0x060 | float | RestValue | Rest/equilibrium value |
| +0x398 | float | CurrentValue | Current constraint value |
| +0xD88 | float[] | ConstraintSetPrimary | Primary constraint array |
| +0x1184 | float[] | ConstraintSetSecondary | Secondary constraint array |

---

## VehicleLapTime (inferred — from FUN_0049b6d0)

Based on FUN_0049b6d0. Confidence: **high** (matches known vehicle struct in docs/01-10).

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x403C | int | CurrentLap | Current lap number |

---

## CollisionMutexState (inferred — from FUN_0045bf90)

Based on FUN_0045bf90. Confidence: **low**.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| DAT_007cd264 | HANDLE | MutexHandle | Win32 mutex handle |
| DAT_007cd268 | int | LockState | -1 = unlocked |
| DAT_007cd26C | int | InitFlag | 1 = initialized |

---

## GridCellIndex (inferred — entry in FUN_0051d247)

Based on FUN_0051d247. Confidence: **low** (stack-based array, not a persistent struct).

| Index | Type | Field | Notes |
|-------|------|-------|-------|
| [0] | int | minX | Left bound |
| [1] | int | maxX | Right bound |
| [2] | int | minZ | Bottom bound |
| [3] | int | maxZ | Top bound |
| [4] | int | minY | Near bound |
| [5] | int | maxY | Far bound |
| [6] | int | contactDistanceSq | Weighted squared distance |
| [7] | int | nonZeroCellCount | Count of occupied cells |

---

## CollisionTerrainSurface (inferred — from FUN_0045ca20)

Based on FUN_0045ca20. Confidence: **low**.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x424 | float[8] | SurfaceDataBlock | 8-dword block per surface entry |
| +0x1124[surfaceIdx] | float | SurfaceCache | Cached surface value |

---

## CollisionProxyFlagSetter (inferred — from FUN_004ba140)

Based on FUN_004ba140. Confidence: **low**.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| param_1+0x08 | int* | EntityPtr | Base pointer to entity/proxy |
| EntityPtr+0xF78 | byte | FlagField | Byte field being set |

---

## Summary

| Struct name | # observations | Confidence | Key functions |
|-------------|---------------|------------|---------------|
| CollisionBody | 6 | high | 0x436870, 0x4542d0, 0x457a00, 0x4584c0, 0x4987b0, 0x44fee0 |
| BVH/SpatialTreeNode | 4 | high | 0x403aa0, 0x4039c0, 0x44aa30, 0x4038e0 |
| CollisionLinkedNode | 4 | high | 0x494e60, 0x4bac20, 0x4ba140, 0x4bad70 |
| DualLinkedListHeader | 2 | high | 0x4bad70, 0x490d00 |
| CollisionGridParams | 8 | medium | Dozens of grid init functions |
| CollisionMaterialGroup | 8 | high | Dozens of material init functions |
| WheelContactState | 1 | high | 0x4e96c0 |
| CollisionDamageContactStore | 2 | medium | 0x45b840 |
| BSPTreeNode | 1 | medium | 0x44a4b0 |
| CollisionRaycastPlane | 1 | medium | 0x44ba40 |
| ProximitySphere | 1 | high | 0x4bda20 |
| CollisionContactSolver | 1 | medium | 0x45c8f0 |
| SpringDamperState | 1 | medium | 0x44f6f0 |
| SensorState | 1 | low | 0x464a40 |
| CollisionPositionStepper | 1 | low | 0x48cb00 |
| CollisionProxyRegistration | 2 | medium | 0x44f0e0, 0x44f0a0 |
| CollisionElementArray | 1 | low | 0x4046b0 |
| CollisionShapeClassifier | 2 | medium | 0x4139c0, 0x412c30 |
| ImpulseAccumulator | 1 | medium | 0x44fee0 |
| CollisionDataBlock | 3 | medium | 0x44fbb0, 0x44fbe0, 0x44efc0 |
| ConstraintSolverState | 2 | low | 0x454250, 0x4542d0 |
| AnimationFrameTimer | 1 | low | 0x469dd0 |
| VehicleLapTime | 1 | high | 0x49b6d0 |
| ViewportRect | 1 | medium | 0x44f680 |
| OscillatoryCollisionState | 2 | low | 0x45c7e0, 0x45c8f0 |
| CollisionNoiseRange | 1 | low | 0x4962c0 |
| Tire/vehicle struct (partial) | 1 | low | 0x4a6b80 |
| ConstraintForceState | 1 | low | 0x454250 |
| GridCellIndex | 1 | low | 0x51d247 |
| CollisionTerrainSurface | 1 | low | 0x45ca20 |
| CollisionProxyFlagSetter | 1 | low | 0x4ba140 |
| CollisionDeformationMesh | 1 | medium | 0x4df110 |
| CollisionMutexState | 1 | low | 0x45bf90 |
| CollisionResponseState | 3 | medium | 0x462ce0, 0x463cd0, 0x453100 |

Total distinct structs: **34** identified from 41 offset table observations in docs/17-physics-collision.md.

**Key insights:**
- The **CollisionBody** struct is dominant — ~58 field observations across 6 functions, spanning 0x040 to 0x1184
- Per-contact sub-struct within CollisionBody has stride 0x90 (144 bytes) for contact data
- Grid and material init functions follow a repetitive 4-field pattern with count/zero/zero/(1.0f or -1.0f or range)
- Multiple structures share offset +0x94/0x98/0x9C for position (consistent across BVH, spatial trees, collision bodies)
- Linked list node pattern (data + next + flags) is consistent at 0xC bytes across multiple collision subsystems

---

## Source: docs/03-engine-wear-damage.md

Source: `docs/03-engine-wear-damage.md` (7 entries, 93+ offset observations)

---

## VehiclePhysicsInstance (primary vehicle struct)

Based on 7 function observations. Confidence: **high**.

This is the main per-vehicle physics instance struct (~0x48C0 bytes). Observed as `param_1` in engine parser (FUN_004f3c80), session init (FUN_0043c250), engine stress sim (FUN_0043ef20), fuel/wear (FUN_004ed960), tire compound broadcast (FUN_004537b0/54350), and engine physics updater (FUN_004e6d93).

### Engine/Drivetrain Params (loaded from .svm ENGINE section)

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x674 | double | FuelConsumption | FUN_004f3c80 | raw from .svm |
| +0x67c | double | FuelEstimate | FUN_004f3c80 | raw from .svm |
| +0x684 | double | EngineInertia | FUN_004f3c80 | raw from .svm |
| +0x68c | double | IdleRPMLogic_min | FUN_004f3c80 | × RPM_TO_RAD (DAT_005ad258) |
| +0x694 | double | IdleRPMLogic_max | FUN_004f3c80 | × RPM_TO_RAD |
| +0x69c | double | IdleThrottle | FUN_004f3c80 | range-checked → flag at +0x6a0 |
| +0x6a0 | double | IdleThrottle_flag | FUN_004f3c80 | computed (0 or 1.0) |
| +0x6ac | double | LaunchRPMLogic_min | FUN_004f3c80 | × RPM_TO_RAD |
| +0x6b4 | double | LaunchRPMLogic_max | FUN_004f3c80 | × RPM_TO_RAD |
| +0x6bc | double | RevLimitLogic | FUN_004f3c80 | × RPM_TO_RAD |
| +0x6c4 | int | RPMTorque_point_count | FUN_004f3c80 | max 126 |
| +0x6c8 | double[3] | RPMTorque_array | FUN_004f3c80 | each 3 doubles: rpm, torque_throttle, torque_brake; rpm × RPM_TO_RAD |

### Tire/Compound Data

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x1140–+0x115c | double×8 | FrontTireTelemetry | FUN_004537b0, FUN_00454350 | contiguous 8 doubles |
| +0x1160 | byte[16] | FrontCompoundFlags | FUN_004537b0, FUN_00454350 | compound/state flag array |
| +0x1170 | int | CurrentFrontCompound | FUN_004537b0 | index compared to 4 constants |
| +0x1174 | int | CompoundSelect_Stop2 | FUN_004537b0 | compound selection for pitstop 2 |
| +0x1178 | int | CompoundSelect_Stop3 | FUN_004537b0 | |
| +0x117c | int | CompoundSelect_Stop4 | FUN_004537b0 | |
| +0x1180 | uint | PitStopFlag | FUN_004537b0 | bitmask: bit0=stop1 valid, 0x100=stop2, 0x200=stop3, 0x400=stop4 |
| +0x153c–+0x1558 | double×8 | RearTireTelemetry | FUN_004537b0, FUN_00454350 | contiguous 8 doubles |
| +0x155c | byte[16] | RearCompoundFlags | FUN_004537b0 | compound/state flag array |

### Thermal/Engine Model Params (loaded from .svm ENGINE section)

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x12c8 | double | OptimumOilTemp | FUN_004f3c80 | + 273.15 K offset (DAT_0059eac8) |
| +0x12d0 | double | CombustionHeat | FUN_004f3c80 | raw |
| +0x12d8 | double | EngineSpeedHeat | FUN_004f3c80 | raw |
| +0x12e0 | double | OilMinimumCooling | FUN_004f3c80 | raw |
| +0x12e8 | double | OilWaterHeatTransfer_p1 | FUN_004f3c80 | raw |
| +0x12f0 | double | OilWaterHeatTransfer_p2 | FUN_004f3c80 | raw |
| +0x12f8 | double | WaterMinimumCooling | FUN_004f3c80 | raw |
| +0x1300 | double | RadiatorCooling_min | FUN_004f3c80 | raw |
| +0x1308 | double | RadiatorCooling_max | FUN_004f3c80 | raw |
| +0x1310 | double | LifetimeEngineRPM_min | FUN_004f3c80, FUN_0043c250 | × RPM_TO_RAD at load; stored raw at +0x1dbc in runtime |
| +0x1318 | double | LifetimeEngineRPM_max | FUN_004f3c80, FUN_0043c250 | × RPM_TO_RAD at load; 1/max stored at +0x1dc4 in runtime |
| +0x1320 | double | LifetimeOilTemp_min | FUN_004f3c80, FUN_0043c250 | + 273.15 K at load; stored at +0x1dcc in runtime |
| +0x1328 | double | LifetimeOilTemp_max | FUN_004f3c80, FUN_0043c250 | **type conflict**: FUN_004f3c80 says raw (no offset), FUN_0043c250 stores 1/max at +0x1dd4 |
| +0x1330 | double | LifetimeAvg | FUN_004f3c80, FUN_004e6d93, FUN_0043c250, FUN_0043bc20 | raw from .svm; used in lifetime formula |
| +0x1338 | double | LifetimeVar | FUN_004f3c80, FUN_004e6d93, FUN_0043c250, FUN_0043bc20 | raw from .svm; used in lifetime formula |
| +0x1340 | double | EngineEmission_0 | FUN_004f3c80 | raw |
| +0x1348 | double | EngineEmission_1 | FUN_004f3c80 | raw |
| +0x1350 | double | EngineEmission_2 | FUN_004f3c80 | raw |
| +0x1344 | int | LifetimeRandomCoeff | FUN_004e6d93 | **conflict**: embedded in double region at +0x1340–+0x1350. FUN_004f3c80 reads doubles at +0x1340/0x1348/0x1350; FUN_004e6d93 reads int at +0x1344. This is a 4-byte int tucked between doubles — likely a separate per-vehicle random seed set at spawn |
| +0x1358 | double | OnboardStarter | FUN_004f3c80 | raw |
| +0x135c | double | StarterTiming_0 | FUN_004f3c80 | raw |
| +0x1364 | double | StarterTiming_1 | FUN_004f3c80 | raw |
| +0x136c | double | StarterTiming_2 | FUN_004f3c80 | raw |

### Runtime Lifetime Storage (populated at session init, consumed by physics)

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x1db4 | double | EffectiveLifetime | FUN_0043c250, FUN_0043ef20 | post-formula, post-scaling; per-lap fraction in race; ≤0 = worn out |
| +0x1dbc | double | LifetimeEngineRPM_min_copy | FUN_0043c250 | raw copy from +0x1310 |
| +0x1dc4 | double | LifetimeEngineRPM_max_recip | FUN_0043c250 | 1 / value from +0x1318 (reciprocal for fast multiply) |
| +0x1dcc | double | LifetimeOilTemp_min_copy | FUN_0043c250 | raw copy from +0x1320 (Kelvin) |
| +0x1dd4 | double | LifetimeOilTemp_max_recip | FUN_0043c250 | 1 / value from +0x1328 (reciprocal for fast multiply) |

### Runtime Engine Stress Simulation

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x19c | double? | RPM_current | FUN_0043ef20 | compared to threshold for stress reduction |
| +0x1c5c | double? | CrankDelta | FUN_0043ef20 | crankshaft rotation delta (ABS), drives stress computation |
| +0x1d4 | ptr? | GaugePtr | FUN_0043ef20 | pointer to gauge display sub-struct (→+0xac display, +0xb4 reciprocal) |
| +0x1d4c | double | OilTemp_current | FUN_0043ef20 | complex heat equation, sine-based ripple |
| +0x1d8c | double | CylinderHeadTemp | FUN_0043ef20 | similar thermal model to oil temp |
| +0x1dac | double? | VibrationAccum | FUN_0043ef20 | vibration accumulator, reset each tick |
| +0x1de4 | double | WearAxis_0 | FUN_0043ef20 | failure distribution axis 0 |
| +0x1dec | double | WearAxis_1 | FUN_0043ef20 | failure distribution axis 1 |
| +0x1df4 | double | WearAxis_2 | FUN_0043ef20 | failure distribution axis 2 |
| +0x1f00 | ptr | VehicleSelfPtr | FUN_0043ef20 | pointer to own vehicle struct (dereferences to +0x4068 ReasonCode) |

### Fuel/Wear/Damage Runtime

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x3978 | float? | FuelLevel | FUN_004ed960 | param_1[0xe5e] × 4 = 0x3978; decremented by flow×rate×delta |
| +0x4068 | int | ReasonCode | FUN_004ed960, FUN_0043ef20 | 0=none, 1=engine, 2=suspension, 4=brake, 5=gearbox, 6=puncture/flat, 8=electronics, 9=fuel. [CORRECTED 2026-07-21: was "2=DNF,3=DSQ" — those are FinishState values, not ReasonCode] |
| +0x39ee? | byte? | SuspensionFailureFlag | FUN_004ed960 | set on gearbox failure (param_1 + 0x39ee) |

---

## DamageModelSubStruct (PHYSICAL section)

Based on 1 function observation (FUN_004f24f0). Confidence: **medium**.

Loaded by `vehload.cpp` from `.svm`/`.hdv` PHYSICAL section. Could be a sub-struct within the vehicle struct at some base offset, or a separate allocation passed as param_1. The doc treats it as param_1 base.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | float | RadiusAdd | FUN_004f24f0 | body collision radius addition |
| +0x04 | float | RadiusMult | FUN_004f24f0 | body collision radius multiplier |
| +0x08 | float | RadiusMax | FUN_004f24f0 | maximum collision radius |
| +0x0c | float | EngineCollision | FUN_004f24f0 | engine collision parameter |
| +0x10 | float | AeroDiv | FUN_004f24f0 | aero division factor |
| +0x14 | float | AeroMin | FUN_004f24f0 | aero minimum |
| +0x18 | float | VertMult | FUN_004f24f0 | vertical multiplier |
| +0x1c | float | FrontWingDetach | FUN_004f24f0 | front wing detach threshold |
| +0x20 | float | FrontWingRandom | FUN_004f24f0 | front wing random failure chance |
| +0x24–+0x2c | float×3 | FrontWingPos | FUN_004f24f0 | xyz position (3 floats) |
| +0x30–+0x3c | 4 vals | FrontWingMassInertia | FUN_004f24f0 | mass + 3 inertia; exact type uncertain |
| +0x40–+0x48 | 3 vals | FrontWingCollParams | FUN_004f24f0 | 3 collision params; exact type uncertain |
| +0x4c | float | RearWingDetach | FUN_004f24f0 | rear wing detach threshold |
| +0x50 | float | RearWingRandom | FUN_004f24f0 | rear wing random failure chance |
| +0x54–+0x5c | float×3 | RearWingPos | FUN_004f24f0 | xyz position (3 floats) |
| +0x60–+0x6c | 4 vals | RearWingMassInertia | FUN_004f24f0 | mass + 3 inertia |
| +0x70–+0x78 | 3 vals | RearWingCollParams | FUN_004f24f0 | 3 collision params |
| +0x7c | float | WheelBendThreshold | FUN_004f24f0 | wheel bending threshold |
| +0x80 | float | WheelDetachThreshold | FUN_004f24f0 | wheel detach threshold |
| +0x84 | float | WheelRandomFail | FUN_004f24f0 | wheel random failure chance |
| +0x88–+0xfc | stride 0x1c ×4 | Wheel_MassInertia[4] | FUN_004f24f0 | 4 wheels × 4 values each (mass + 3 inertia) |
| +0x118–+0x158 | float×8 | PartDetach[0..7] | FUN_004f24f0 | 8 part detach thresholds (4 bytes each) |
| +0x13c–+0x178 | stride 0xc ×8 | PartPos[0..7] | FUN_004f24f0 | 8 parts × 3 floats each (xyz position) |
| +0x1a0–+0x250 | stride 0x1c ×8 | PartMassInertia[0..7] | FUN_004f24f0 | 8 parts × (mass + 3 inertia + 3 collision params) |

**Type uncertainty:** The doc does not explicitly state types for damage struct fields. Types above are inferred from offset spacing (0x04 = float, ranges covering 3 values over 12 bytes = float×3). The `MassInertia` and `CollParams` ranges use stride 0x1c = 28 bytes, which may contain doubles or structs — verify against Ghidra pseudocode.

---

## RPMPerGearSubStruct (stride 0x0c, 5 gears)

Based on 1 function observation (FUN_004f6bf0). Confidence: **high**.

Per-gear RPM limits loaded from .svm. Stride = 0x0c (12 bytes) for 5 gears (0–4). The gear index is param_3, offset computed as `gear × 0x0c`.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x04 + gear×0xc | float | MinimumRPM | FUN_004f6bf0 | × RPM_TO_RAD conversion |
| +0x08 + gear×0xc | float | MaximumRPM | FUN_004f6bf0 | × RPM_TO_RAD conversion |
| +0x0c + gear×0xc | float | NaturalRPM_recip | FUN_004f6bf0 | 1.0 / (NaturalRPM × RPM_TO_RAD); stored as reciprocal |

**Note:** 3 fields × 4 bytes = 12 bytes = 0x0c stride, confirming float (not double) per field.

---

## GaugeDisplaySubStruct (referenced via pointer at +0x1d4)

Based on 1 function observation (FUN_0043ef20). Confidence: **low**.

This is pointed to by the vehicle struct at offset +0x1d4. Only 2 offsets observed:

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0xac | double? | GaugeDisplay | FUN_0043ef20 | display value updated from RPM |
| +0xb4 | double? | GaugeRecip | FUN_0043ef20 | reciprocal for gauge computation |

---

## Consolidated Notes

### Conflicts

1. **+0x1328** — FUN_004f3c80 stores `LifetimeOilTemp_max` as raw double (no offset). FUN_0043c250 stores `1/LifetimeOilTemp_max` at +0x1dd4 (runtime reciprocal copy). No actual conflict — the parser and runtime use different offsets for different representations.

2. **+0x1344** — FUN_004f3c80 treats this as part of the EngineEmission double array (double at +0x1340, +0x1348, +0x1350). FUN_004e6d93 reads a 4-byte int at +0x1344 (`LifetimeRandomCoeff`). **Resolution:** The struct layout has 3 doubles at +0x1340, +0x1348, +0x1350 occupying +0x1340–+0x1357 (24 bytes). The 4-byte int at +0x1344 falls inside the first double's storage — this suggests either: (a) the double at +0x1340 is actually a union/packing with the int, or (b) the random coefficient is a separate 4-byte field at +0x1344 that overlays the double's lower/higher 4 bytes. Most likely: the double at +0x1340 is `EngineEmission[0]` (8 bytes +0x1340–+0x1347), and +0x1344 is a separate int field that shares space with the upper 4 bytes of that double — a classic MSVC union or bitfield overlay.

### Overlaps with docs/13-struct-offsets.md

Existing docs/13 entries are confirmed and expanded:
- +0x1db4, +0x1dbc, +0x1dc4, +0x1dcc, +0x1dd4: confirmed from 2 functions
- +0x1140–+0x115c, +0x1160, +0x1170, +0x1174–+0x117c, +0x1180: confirmed from 2 functions
- +0x153c–+0x1558, +0x155c: confirmed from 2 functions

### New offsets not in docs/13

The following offsets from FUN_004f3c80 (engine section parser) are **new** and should be added to docs/13:
- +0x674 (FuelConsumption) through +0x6c8 (RPMTorque array)
- +0x12c8 (OptimumOilTemp) through +0x136c (StarterTiming)
- +0x1340–+0x1350 (EngineEmission)
- +0x19c (RPM_current), +0x1c5c (CrankDelta), +0x1d4 (GaugePtr)
- +0x1d4c (OilTemp), +0x1d8c (HeadTemp), +0x1dac (Vibration)
- +0x1de4, +0x1dec, +0x1df4 (WearAxes), +0x1f00 (VehicleSelfPtr)
- +0x3978 (FuelLevel), +0x4068 (ReasonCode)

The entire DamageModelSubStruct (+0x00–+0x250, 37+ offsets) is new.
The entire RPMPerGearSubStruct (stride 0x0c × 5 gears) is new.

---

## Source: docs/09-track-system.md

# Struct Offset Synthesis — Worker J

Source: docs/09-track-system.md

## 1. Track Material Struct (inferred)

Based on 1 function observation (FUN_004cdd80). Confidence: medium.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x08 | float? | GripLevel | FUN_004cdd80 | Read from MATERIALS file section |
| +0x0c | float? | GripLevel2 | FUN_004cdd80 | Computed (grip - offset) |
| +0x10 | float? | Resistance | FUN_004cdd80 | Collision resistance |
| +0x14 | float? | BumpAmp | FUN_004cdd80 | × _DAT_0059e7f8 at load |
| +0x18 | float? | BumpFreq | FUN_004cdd80 | _DAT_0059ed28 / wavelen (min 3.0) |
| +0x1c | float? | Spring | FUN_004cdd80 | Spring rate |
| +0x20 | float? | Damper | FUN_004cdd80 | Damper rate |
| +0x24 | float? | CollFrict | FUN_004cdd80 | Collision friction |
| +0x28 | int? | Sparks | FUN_004cdd80 | Sparks texture/effect |
| +0x2c | bool? | Scraping | FUN_004cdd80 | Bool — scraping sound on collision |
| +0x30–0x38 | int[3]? | SoundIDs | FUN_004cdd80 | 3 sound indices |
| +0x60 | bool? | LegalFlag | FUN_004cdd80 | Bool — is material legal track surface |

Note: Types are inferred from field semantics (float for physics values, int/bool for flags). No explicit type casts documented in source. Struct size ~0x60+.

---

## 2. Commentary/Director Event Struct (inferred)

Based on 1 function observation (FUN_0040d4c0). Confidence: low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x04 | int | EventID | FUN_0040d4c0 | Event identifier |
| +0x0c | float | Probability | FUN_0040d4c0 | Default 1.0 |
| +0x10 | unknown | Param | FUN_0040d4c0 | Additional parameter |
| +0x24 | int | EventTypeCode | FUN_0040d4c0 | 0–0xc (CAMERA_ACQUIRE_CONTROL, COMMENTARY_START, SCRIPT_END, etc.) |
| +0x28 | unknown | Unknown | FUN_0040d4c0 | Not documented |

---

## 3. Cockpit Dashboard Struct (inferred)

Based on 1 function observation (FUN_0049ca00). Confidence: medium.

**Gauge textures (array, stride 0x4c):**

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x60 | char*? | TAC_01_texture | FUN_0049ca00 | Tachometer texture |
| +0xac | char*? | WATERTEMP_texture | FUN_0049ca00 | Water temp gauge |
| +0xf8 | char*? | OILTEMP_texture | FUN_0049ca00 | Oil temp gauge |
| +0x144 | char*? | OILPRESS_texture | FUN_0049ca00 | Oil pressure gauge |
| +0x190 | char*? | FUEL_texture | FUN_0049ca00 | Fuel gauge |

**LED indicators (at param_1 + 0x20–0x48):**

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x20 | char*? | LED165 | FUN_0049ca00 | 165°C temp LED |
| +0x24 | char*? | LED170 | FUN_0049ca00 | 170°C temp LED |
| +0x28 | char*? | LED175 | FUN_0049ca00 | 175°C temp LED |
| +0x2c | char*? | LED182 | FUN_0049ca00 | 182°C temp LED |
| +0x30 | char*? | LEDSL | FUN_0049ca00 | Shift light LED |
| +0x34 | char*? | LEDPSY | FUN_0049ca00 | Pit speed yellow LED |
| +0x38 | char*? | LEDPSR | FUN_0049ca00 | Pit speed red LED |
| +0x3c | char*? | LEDLF | FUN_0049ca00 | Low fuel LED |
| +0x40 | char*? | LEDFR | FUN_0049ca00 | Fuel red LED |
| +0x44 | char*? | LEDFY | FUN_0049ca00 | Fuel yellow LED |
| +0x48 | char*? | LEDFB | FUN_0049ca00 | Fuel blue LED |

---

## 4. Vehicle Struct (shared — FinishPosition, TeamID, etc.)

Based on observations from FUN_0041d630, FUN_00419c50, FUN_0040c540, FUN_0040adb0, FUN_0045d890, FUN_0042e530. Confidence: high.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x58..0x60 | float[3]? | Velocity | FUN_0040adb0 | Velocity vector (also +0x58/0x5c/0x60 in FUN_0040b710) |
| +0x130 | int? | GearData1 | FUN_0042e530 | Gear ratio data |
| +0x138 | int? | GearData2 | FUN_0042e530 | Gear ratio data |
| +0x144 | int? | GearData3 | FUN_0042e530 | Gear ratio data |
| +0x1f0 | unknown[0x2c0]×4 | WingPosArray | FUN_0042e530 | Wing position arrays, stride 0x2c0 × 4 entries |
| +0x3f0 | int? | GearData4 | FUN_0042e530 | Gear ratio data |
| +0x3f8 | int? | GearData5 | FUN_0042e530 | Gear ratio data |
| +0x400 | int? | GearData6 | FUN_0042e530 | Gear ratio data |
| +0x404 | int? | GearData7 | FUN_0042e530 | Gear ratio data |
| +0x4060 | int | FinishPosition | FUN_0041d630, FUN_0040c540 | Finish position |
| +0x4064 | int | FinishState | FUN_0041d630, FUN_00419c50 | 0=running, 1=finished, 2=DNF, 3=DSQ |
| +0x4070 | int | MessageFlag | FUN_00419c50 | Previous commentary message flag |
| +0x409c | float | BestLapTime | FUN_0041d630, FUN_0045d890 | Best overall lap time |
| +0x4894 | int | TeamID | FUN_00419c50, FUN_0040c540, FUN_0045d890 | Team identifier |
| +0x489c | int | DriverNumber | FUN_0041d630 | Driver number |
| +0x6b0 | unknown | AeroData1 | FUN_0042e530 | Aero data |
| +0x704..0x70c | float[3]? | Orientation | FUN_0040adb0 | Orientation vector |
| +0x744..0x74c | float[3]? | WorldPos | FUN_0040adb0 | World position |
| +0x970 | unknown | AeroData2 | FUN_0042e530 | Aero data |
| +0xff0 | unknown | WingArray1 | FUN_0042e530 | Wing position array entry |
| +0x1030 | unknown | WingArray2 | FUN_0042e530 | Wing position array entry |
| +0x1070 | unknown | WingArray3 | FUN_0042e530 | Wing position array entry |
| +0x10b0 | unknown | WingArray4 | FUN_0042e530 | Wing position array entry |
| +0x1170 | unknown | WingArray5 | FUN_0042e530 | Wing position array entry |
| +0x11b0 | unknown | WingArray6 | FUN_0042e530 | Wing position array entry |
| +0x11f0 | unknown | WingArray7 | FUN_0042e530 | Wing position array entry |
| +0x1230 | unknown | WingArray8 | FUN_0042e530 | Wing position array entry |
| +0x12b0 | unknown | AeroData3 | FUN_0042e530 | Aero data |
| +0x12c0 | unknown | AeroData4 | FUN_0042e530 | Aero data |
| +0x12c4 | unknown | AeroData5 | FUN_0042e530 | Aero data |

Consistency check: +0x4060 (FinishPosition) and +0x4894 (TeamID) confirmed by 2+ functions each. +0x4064 (FinishState) confirmed by 2 functions with same value 2=DNF.

---

## 5. SpecialFX Struct (inferred)

Based on observations from specialfx.cpp entries (FUN_004cee90–FUN_004cfff0). Confidence: low.

**WARNING:** Offsets listed in doc as +0x00, +0x01, +0x02, +0x03, +0x04, +0x05, +0x06–0x0a, +0x0b, +0x0c, +0x0d — these appear to be sequential byte offsets in a packed struct or may have been mis-extracted. They do not follow the typical DWORD-aligned pattern seen in other game structs. Likely these are fields within a small header or the doc extraction is incomplete.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | int | LPTreeCount | specialfx.cpp Init | LPTREE scene node count |
| +0x01 | ptr? | LPTreeArray | specialfx.cpp Init | Stride 0x3c |
| +0x02 | int | FeedbackCount | specialfx.cpp Init | Feedback material count |
| +0x03 | ptr? | FeedbackArray | specialfx.cpp Init | Stride 0x6c |
| +0x04 | int | LooseMatCount | specialfx.cpp Init | Loose material count |
| +0x05 | ptr? | LooseMatArray | specialfx.cpp Init | Stride 0x6c |
| +0x06–0x0a | ptr[5]? | SpecialMaterials | specialfx.cpp Init | Pointers for material types 0xc, 0xd, 1, 3, 4 |
| +0x0b | unknown | SceneExtents | specialfx.cpp Init | Scene extent data |
| +0x0c | float | AIDryGrip | specialfx.cpp Init | AI dry grip multiplier |
| +0x0d | float | AIWetGrip | specialfx.cpp Init | AI wet grip multiplier |

**CONFLICT:** Offsets +0x00 through +0x0d are suspiciously small (not DWORD-aligned). Compare with other structs in this game which use DWORD offsets (multiples of 4). Possible extraction error in doc or unusual packed struct. If offsets are actually DWORD-based: +0x00, +0x04, +0x08, +0x0c, +0x10, +0x14, +0x18, +0x28, +0x30, +0x34 would be the real DWORD-aligned offsets.

---

## 6. Camera Manager Struct (inferred)

Based on observations from FUN_00408e20, FUN_00408870. Confidence: medium.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x10 | Camera* | NoseCam | FUN_00408e20 | NOSECAM camera object |
| +0x14 | Camera* | CockpitCam | FUN_00408e20 | COCKPIT camera object |
| +0x18 | Camera* | TVCockpitCam | FUN_00408e20 | TVCOCKPIT camera object |
| +0x1c | Camera* | SwingmanCam | FUN_00408e20 | SWINGMAN camera (TV broadcast) |
| +0x20 | Camera* | ExtraCamArray | FUN_00408e20 | Array of additional cameras (200 bytes each) |
| +0x24 | Camera* | PitCam | FUN_00408e20 | Set by FUN_00408870 (2SEATER/3SEATER/pits) |
| +0x28 | Camera* | Unused1 | FUN_00408e20 | UNUSED allocated camera |
| +0x2c | Camera* | Unused2 | FUN_00408e20 | UNUSED allocated camera |
| +0x30 | Camera* | Unused3 | FUN_00408e20 | UNUSED allocated camera |
| +0x40 | int/str? | CameraName | FUN_00408e20 | Camera name identifier |
| +0x44 | int | CameraCount | FUN_00408e20 | Camera slot count |

**Note:** There is a potential struct size issue. Offsets +0x28 to +0x30 are 4 bytes each (3 Camera* pointers). But +0x40 appears right after +0x30 with +0x10 gap — suggests additional fields between +0x30 and +0x40 not documented, or +0x40 is relative to a different struct.

---

## 7. Camera Struct (200 bytes, stride 200)

Based on observations from FUN_00408e20, FUN_00408870, FUN_0040db00. Confidence: medium.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x14 | char*? | NodeName | FUN_004fc2f0 | Scene node name |
| +0x18 | int*? | Interface1 | FUN_0040c890 | First vtable interface pointer |
| +0x1c | int*? | Interface2 | FUN_0040c890 | Second vtable interface pointer |
| +0x20 | int*? | Interface3 | FUN_0040c890 | Third vtable interface pointer |
| +0x30 | float | Param1 | FUN_00408e20, FUN_00408870 | FOV/settings (60.0 for fixed cams) |
| +0x34 | float | Param2 | FUN_00408e20, FUN_00408870 | FOV/settings (45.0 for fixed cams) |
| +0x38 | float | NearClip | FUN_00408e20, FUN_00408870 | Near clip plane (60.0 for fixed cams) |
| +0x3c | float | FarClip | FUN_00408e20, FUN_00408870 | Far clip plane (45.0 for fixed cams) |
| +0x40 | int | NameID | FUN_00408e20, FUN_00408870 | Camera name ID / FOV-Zoom param |
| +0x44 | int | SlotCount | FUN_00408e20 | Camera slot count / Range (500.0) |
| +0x48 | float | ScaleX | FUN_00408870 | Scale X (1.0) |
| +0x4c | float | ScaleY | FUN_00408870 | Scale Y (1.0) |
| +0x50 | float | ScaleZ | FUN_00408870 | Scale Z (1.0) |
| +0x54 | float | AspectClipX | FUN_00408870 | Aspect/clip X (0.5) |
| +0x58 | float | AspectClipY | FUN_00408870 | Aspect/clip Y (0.5) |
| +0x60 | int | ActiveFlag | FUN_00408870 | Active flag (1) |
| +0x64–0x78 | byte[0x14]? | Padding | FUN_00408870 | Zero padding |
| +0x80 | float | BaseOffsetX | FUN_00408870 | Base offset X |
| +0x84 | float | BaseOffsetY | FUN_00408870 | Base offset Y |
| +0x88–0x90 | float[3]? | PositionRot | FUN_00408870 | Position/rotation vector |
| +0x8c | Camera* | OriginalTarget | FUN_0040db00 | Original camera target |
| +0x90 | Camera* | LastTarget | FUN_0040db00 | Last camera target |
| +0x94–0xa8 | float[4]? | LookAtQuat | FUN_00408870 | Look-at/direction quaternion |
| +0xa0 | float | ExtraOffsetX | FUN_00408870 | Extra offset X |
| +0xa4 | float | ExtraOffsetY | FUN_00408870 | Extra offset Y |
| +0xa8 | float | ExtraOffsetZ | FUN_00408870 | Extra offset Z |

**CONFLICT:** +0x40 documented as "Camera Name ID" in FUN_00408e20 but as "FOV/Zoom parameter" in FUN_00408870. These may be different structs (camera view definition vs camera instance), or the field is multi-purpose.
**CONFLICT:** +0x44 documented as "Camera slot count" in FUN_00408e20 but as "Range (500.0)" in FUN_00408870. Same struct reinterpretation issue.
**NOTE:** +0x8c and +0x90 overlap with the PositionRot/LookAtQuat range from FUN_00408870. The camera manager struct (+0x08e20) has +0x8c as OriginalTarget, while the camera camera definition struct (+0x08870) has +0x88–0x90 as position/rotation. These are likely different structs at different scopes.

---

## 8. Scene File Struct (param_1, fog parameters)

Based on 1 function observation (FUN_0055b200). Confidence: medium.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x188 | short | FogColorR | FUN_0055b200 | FOGCOLOR red component (short) |
| +0x18a | short | FogColorG | FUN_0055b200 | FOGCOLOR green component (short) |
| +0x18c | short | FogColorB | FUN_0055b200 | FOGCOLOR blue component (short) |
| +0x194 | float | FogInDist | FUN_0055b200 | FOGIN distance (float) |
| +0x198 | float | FogOutDist | FUN_0055b200 | FOGOUT distance (float) |
| +0x190 | float | FogDensity | FUN_0055b200 | FOGDENSITY (float) |
| +0x19c | int | FogModeMask | FUN_0055b200 | Fog mode (LINEAR=0x20000, FOG=0x40000/0x80000) |

**NOTE:** +0x190 is documented as "400" (decimal) in the source doc — likely 0x190 hex = 400 decimal. It sits between the color shorts and the distance floats. Alignment: shorts at +0x188–0x18c (6 bytes), then FogDensity at +0x190 (4-byte aligned), FogInDist at +0x194, FogOutDist at +0x198.

---

## 9. Scene Instance/Node Struct (inferred)

Based on observations from FUN_0055a910, FUN_004fc2f0. Confidence: low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x3c | int | InstanceFlags | FUN_0055a910 | Bitmask: MOVEABLE(0x1), RENDERdis(0x4), CHANGEdis(0x8), BILLBOARD(0x9), STAMP(0x10) |
| +0x50 | unknown | ClipPlaneData | FUN_0055a910 | Clipping plane data |
| +0x118 | int | NodeCount | FUN_004fc2f0 | Scene node count |
| +0x128 | ptr | NodeList | FUN_004fc2f0 | List of nodes, stride 0x100 |
| +0x13c | int | ShadowRecvCount | FUN_0055a910 | Shadow receiver count |
| +0x174 | int | ReflectorCount | FUN_0055a910 | Reflector count |

**Node flags (+0x14 bitmask):**

| Bit | Field | Observed in |
|-----|-------|-------------|
| 0x6 | COLLTARGET | FUN_0055a910 |
| 0x7 | SPHERETARGET | FUN_0055a910 |
| 0x8 | HATTARGET | FUN_0055a910 |
| 0xd | ZBUFFER_DISABLE | FUN_0055a910 |
| 0xe | SHADOW_RECEIVER | FUN_0055a910 |
| 0x11 | REFLECTOR | FUN_0055a910 |
| 0x15 | MORPH_TARGET | FUN_0055a910 |
| 0x19 | SHADOW_CASTER | FUN_0055a910 |

---

## 10. NetComm Session Struct (inferred) — large, multi-field

Based on 14+ function observations from NetComm.cpp entries. Confidence: high (for frequently-accessed offsets).

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x0c | float | RefillTimeout | FUN_0045f950 | Client timeout refill value |
| +0x10 | float | ClientTimeout | FUN_0045f950, FUN_00464290 | Client timeout counter |
| +0x14 | int | ClientFlag | FUN_00464290, FUN_0045f950 | Client flag |
| +0x1c | float | GridTimer | FUN_00460380 | Client grid display timer |
| +0x1c | ptr? | NodeIDArray | FUN_00460cb0, FUN_0045eb50 | Node ID array (104 entries, at +0x1d4 from some refs) |
| +0x20 | int | SceneLoadedFlag | FUN_00460380 | Scene load wait flag |
| +0x28 | int | InitFlag | FUN_00464290 | First call flag |
| +0x29 | byte | OpeningFlag | FUN_00460e90, FUN_00461020, FUN_004612e0 | Track opened/closed (1=open, 0=closed) |
| +0x2c | float | OpenTimer | FUN_00461190, FUN_004612e0 | Track opening timer/-1.0f |
| +0x30 | int | BootedFlag | FUN_00461d20 | Boot notification displayed flag |
| +0x380 | float | ResetTimer | FUN_00464290, FUN_00461d20 | Reset accumulator/frame timer |
| +0x388 | int | ResetFlag | FUN_00464290 | Reset flag |
| +0x38c | float | KeepAliveAccum | FUN_0045f950 | Keep-alive accumulator |
| +0x390 | float | SyncTimeout | FUN_00464290, FUN_0045d890 | Sync/timeout accumulator |
| +0x398 | char[0x8c]×104 | PlayerNames | FUN_0045eb50 | Player name strings, stride 0x8c |
| +0x3c74 | int[104] | SlotNodeIDs | FUN_00460cb0, FUN_0045eb50 | Slot-to-node-ID mapping |
| +0x3e14 | int | SlotCount | FUN_00460cb0, FUN_0045eb50, FUN_0045fc50 | Number of active player slots |
| +0x3fc4 | int | Connected | FUN_00464290 | Connection flag |
| +0x1b770 | ptr | MsgListHead | FUN_00460e90 | Message linked list head |
| +0x1b774 | ptr | MsgListTail | FUN_00460e90 | Message linked list tail |
| +0x1b77c | int | MsgListCount | FUN_00460e90 | Message linked list count |
| +0x1b79c | int | NetworkActive | FUN_00461de0 | Network active flag |
| +0x1d4 | int[104] | NodeIDList | FUN_00460cb0 | Node ID array (also referenced from param_1 + 0x1d4) |

**CONFLICT:** +0x1c is "GridTimer" (float) in FUN_00460380 but likely same field offset reused for different purposes in different contexts. +0x1d4 is referenced as a node ID array in FUN_00460cb0 and also as part of slot struct in FUN_0045eb50 — these may reference different offsets relative to different pointer bases.

**NOTE:** The struct is very large (0x1b79c+ bytes = ~112,540 bytes). Many fields between +0x30 and +0x380 are undocumented. The stride 0x8c for player slots is consistent across FUN_0045eb50 and FUN_0045fc50.

---

## 11. Player Slot Struct (stride 0x8c)

Based on observations from FUN_0045eb50, FUN_0045fc50. Confidence: medium.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | int | NodeID | FUN_0045eb50 | Network node ID |
| +0x04–0x8b | char[0x87] | PlayerName | FUN_0045eb50 | Player name string |

Note: This is a sub-struct within the NetComm session struct, stride 0x8c per slot, starting at various base offsets (+0x398 for names, +0x3c74 for IDs, +0x3d0 for slot data).

---

## 12. Environment/Track Struct (inferred)

Based on 1 function observation (FUN_004ade20). Confidence: low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x1aec | int | EnvMode | FUN_004ade20 | Environment mode (1=dry, 2=wet, 3=mixed) |
| +0x1b10 | int | CameraCount | FUN_004ade20 | Number of track cameras |
| +0x1b18 | int | CameraMin | FUN_004ade20 | Minimum camera count bound |
| +0x1b1c | int | CameraMax | FUN_004ade20 | Maximum camera count bound |

---

## 13. Commentary Path List Struct (inferred)

Based on 1 function observation (FUN_00414e60). Confidence: very low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | char*? | CircuitNamePtr | FUN_00414e60 | Circuit/season name pointer |
| +0x02 | unknown | PathData | FUN_00414e60 | Path data |
| +0x05 | char*? | CountryE | FUN_00414e60 | English country name (entry 2) |
| +0x0a | char*? | CountryB | FUN_00414e60 | Broadcast language country name (entry 3) |
| +0x12 | char*? | CircuitE | FUN_00414e60 | English circuit name (entry 4) |
| +0x17 | char*? | CircuitB | FUN_00414e60 | Broadcast language circuit name (entry 5) |

**CONFLICT:** Offsets (+0x00, +0x02, +0x05, +0x0a, +0x12, +0x17) are not DWORD-aligned in a typical 32-bit PE struct. Likely multiple struct sizes being accessed, or the doc offsets are relative to different base pointers. Not reliable for struct synthesis.

---

## 14. UI Dialog Struct (inferred)

Based on observations from FUN_0046b0c0, FUN_00470300. Confidence: low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x1fc | int | State | FUN_0046b0c0 | State machine (0=idle, 1=init, 2=await input, 3=confirm) |
| +0x200 | int | RawInputData | FUN_0046b0c0 | Raw input key/button data |
| +0x204 | int | InputType | FUN_0046b0c0 | Input device type |
| +0x2e8 | int | ResetField | FUN_00470300 | Reset counter/state |
| +0x304 | int | ControlID | FUN_00470300 | Dialog control ID |

Note: +0x1fc (500 in decimal) is documented as "500" in FUN_0046b0c0 for DeviceIndex — likely not a struct offset but an array index relative to param_1.

---

## 15. Net Session State Struct (inferred, small)

Based on observations from FUN_00462160. Confidence: low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0xc4 | int | FilterActiveFlag | FUN_00462160 | Sort/filter active flag, toggle by param_3 |

---

## Summary

| # | Struct Name | Observed Offsets Span | Functions | Confidence |
|---|-------------|----------------------|-----------|------------|
| 1 | TrackMaterial | +0x08 to +0x60 | 1 | medium |
| 2 | CommentaryEvent | +0x04 to +0x28 | 1 | low |
| 3 | CockpitDashboard | +0x20 to +0x190 | 1 | medium |
| 4 | Vehicle | +0x58 to +0x489c | 7 | high |
| 5 | SpecialFX | +0x00 to +0x0d | 1 | low |
| 6 | CameraManager | +0x10 to +0x44 | 1 | medium |
| 7 | Camera (200B) | +0x14 to +0xa8 | 4 | medium |
| 8 | SceneFile | +0x188 to +0x19c | 1 | medium |
| 9 | SceneNode/Instance | +0x3c to +0x174 | 2 | low |
| 10 | NetCommSession | +0x0c to +0x1b79c | 14 | high |
| 11 | PlayerSlot (0x8c) | +0x00 to +0x8b | 2 | medium |
| 12 | Environment/Track | +0x1aec to +0x1b1c | 1 | low |
| 13 | CommentaryPathList | +0x00 to +0x17 | 1 | very low |
| 14 | UIDialog | +0x1fc to +0x304 | 2 | low |
| 15 | NetSessionFilter | +0xc4 | 1 | low |

Total offset observations extracted: ~100+
Total distinct structs identified: 15

---

## Source: docs/21-audio-network-internals.md

Source: docs/21-audio-network-internals.md (181 entries, 77+ offset observations)

---

## NetworkManagerStruct (inferred, size ~0xbf8)

Based on 10+ function observations. Confidence: high.

The 0xbf8-byte network manager struct allocated by FUN_0057a420. Contains socket state, mutexes, connection lists, and send/receive queues.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x000 | int | ConnectionState | FUN_00563260 | 0=initial, 1+=connected |
| +0x004 | byte | ActiveFlag | FUN_0057afa0 | Packet queue activity flag |
| +0x008 | void* | ClientArray | FUN_00563260 | Client data array ptr (stride 0x1c) |
| +0x008 | int* | HeadPtr | FUN_0057afa0 | Packet queue linked list head |
| +0x00c | int* | CurrentPtr | FUN_0057afa0 | Packet queue insertion point |
| +0x010 | int* | TailPtr | FUN_0057afa0 | Packet queue tail |
| +0x014 | uint | PacketCounter | FUN_0057afa0 | Total packet count |
| +0x01c | int32* | MessageList | FUN_0057b840 | Pointer to message comparison slots |
| +0x070 | int | MaxClientCount | FUN_00563260 | param_1[0x1c] |
| +0x074 | int | ConnAttemptCounter | FUN_00563260 | param_1[0x1d] |
| +0x088 | SOCKET | SocketHandle | FUN_00563080 | UDP broadcast socket |
| +0x098 | int | ReconnRetryCounter | FUN_00563260 | param_1[0x26] |
| +0x244 | short | Port | FUN_005804a0 | Network port |
| +0x24e | int | AltPort | FUN_005804a0 | Alternate port |
| +0x24f | int | SocketFD | FUN_005804a0 | Socket descriptor |
| +0x252 | char[31] | Name | FUN_005804a0 | Connection name |
| +0x25a | byte | Flag1 | FUN_005804a0 | Set to 1 on success |
| +0x29d | byte | CleanupFlag | FUN_0057fbe0 | If set, calls WSACleanup |
| +0x2b6 | HANDLE | MutexH | FUN_00580de0, FUN_0057fbe0 | Win32 mutex |
| +0x2b7 | DWORD | MutexTimeoutH | FUN_00580de0 | Wait timeout in ms |
| +0x2bd | HANDLE | MutexI | FUN_0057fbe0 | Win32 mutex |
| +0x2c4 | HANDLE | MutexJ | FUN_0057bce0 | Win32 mutex |
| +0x2cb | HANDLE | MutexK | FUN_0057bce0 | Win32 mutex |
| +0x2cf | HANDLE | MutexL | FUN_0057bce0 | Win32 mutex |
| +0x2da | HANDLE | MutexM | FUN_0057bce0 | Win32 mutex |
| +0x2e5 | HANDLE | MutexN | FUN_0057bce0 | Win32 mutex |
| +0x2f0 | HANDLE | MutexO | FUN_0057bce0 | Win32 mutex |
| +0x640 | HANDLE | MutexC | FUN_00580c10 | Win32 mutex |
| +0x6c | int | SocketCount | FUN_00563dc0 | Number of open sockets |
| +0x778 | WSADATA | WsaData | FUN_0057fb90 | Winsock startup data |
| +0x88 | SOCKET | UdpSocket | FUN_00563080 | UDP broadcast socket handle |
| +0x938 | SOCKET | ListenSocket | FUN_00580190 | Listening socket |
| +0x93c | SOCKET | CheckSocket | FUN_00580190 | Secondary socket for cancellation |
| +0x967 | byte | NameTerminator | FUN_005804a0 | Null terminator for Name |
| +0x96a | byte | Flag2 | FUN_005804a0 | Set to 1 on success |
| +0x96b | byte | Param3 | FUN_005804a0 | Stored from input |
| +0xa74 | byte | WinsockInitFlag | FUN_0057fb90 | 1 = WSAStartup done |
| +0xaac | int* | SendQueuePtr | FUN_0057d8d0 | Head of send queue linked list |
| +0xabc | HANDLE | SendMutex | FUN_0057d8d0 | Send queue sync |
| +0xac0 | DWORD | SendMutexTimeout | FUN_0057d8d0 | Send mutex wait timeout |
| +0xac8 | int* | ConnectionList | FUN_005813e0, FUN_0057e3a0 | Linked list of connections |
| +0xacc | int* | ConnectionPrev | FUN_005813e0 | Previous pointer |
| +0xad0 | int* | ConnectionCurrent | FUN_005813e0 | Current iterator |
| +0xad4 | int | ConnectionCount | FUN_005813e0 | Total connections |
| +0xad8 | HANDLE | ConnMutex | FUN_005813e0, FUN_0057e3a0, FUN_00580c10 | Win32 mutex |
| +0xadc | DWORD | ConnMutexTimeout | FUN_005813e0, FUN_0057e3a0 | Wait timeout in ms |
| +0xb00 | int* | ConnListHead | FUN_0057edd0 | Head of network thread connection list |
| +0xb10 | HANDLE | ListMutex | FUN_0057edd0 | Mutex for connection list |
| +0xb14 | DWORD | ListMutexTimeout | FUN_0057edd0 | Wait timeout |
| +0xb38 | int | PacketIDCounter | FUN_00580c10 | Shared packet ID counter |
| +0xb3c | HANDLE | PacketMutex | FUN_00580c10 | Mutex for packet ID |
| +0xbec | HANDLE | AcceptMutex | FUN_00580190 | Mutex for accept handling |

**Notes:**
- Offsets span 0x000–0xbf8 in a single allocation (3064 bytes from FUN_0057a420)
- The struct contains ~6+ mutex handles for different subsystems
- Connection list management uses queue pattern at +0xac8 (head, prev, current, count)
- Socket array at +0x08 has stride 0x1c per socket entry (FUN_00563dc0)
- +0x6c (SocketCount) and +0x08 (SocketArray) may overlap with ClientArray — needs verification

---

## AudioHandleStruct / MilesSampleStruct (inferred)

Based on 4+ function observations. Confidence: high.

Used by Miles Sound System wrapper functions. Contains audio handle, filter state, and control fields.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x0c | void* | SubResource | FUN_00552760, FUN_00406750 | Sub-resource pointer, freed conditionally |
| +0x10 | void* | MilesSampleHandle | FUN_00405b50, FUN_004059f0, FUN_004060c0 | (dereferenced from +0x58) Miles sample handle |
| +0x14 | int | PlayState | FUN_00405b50 | Play state/flag |
| +0x24 | uint32 | FlagBitmask | FUN_00552760 | Bit 0x20000 gates sub-resource cleanup |
| +0x58 | void* | AudioHandle | FUN_00405b50, FUN_004060c0, FUN_004059f0 | Audio handle/sample struct pointer |
| +0x5c | int | StreamHandle | FUN_00406750 | -1 = closed |
| +0x60 | int | FilterType | FUN_004060c0 | -1 = no filter |
| +0x64 | int | FilterParam | FUN_004060c0 | Parameter for filter |
| +0x68 | byte[] | FilterState | FUN_004060c0 | Filter state struct |
| +0x868 | void* | SecondaryResource | FUN_00552760 | Secondary sub-resource, conditionally freed |

**Notes:**
- +0x24 bit 0x20000 (131072) is a cleanup gate flag
- +0x58 is a common audio handle pattern across multiple MSS wrapper functions
- +0x64 (100) used as resource handle offset in FUN_00552760

---

## AudioStreamStruct (inferred)

Based on 2+ function observations. Confidence: medium.

Large audio codec/stream struct used by resampler and codec functions.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x24a4 | void* | InputBufferPtr | FUN_0052e6f0 | Input buffer pointer, null-checked |
| +0x24a8 | int | BitPosition | FUN_0052e6f0 | Bitstream read position |
| +0x24bc | int | RingBufIndex | FUN_00532aa0 | 16-entry ring buffer, decremented & masked |
| +0x24cc | int | EntryCount | FUN_00532aa0, FUN_0052e6f0 | 2=stereo, 1=mono |
| +0x24d0 | int | OutputStride | FUN_0052e6f0 | Output byte stride per channel |

---

## AudioChannelInitStruct (inferred)

Based on 2+ function observations. Confidence: medium.

Audio channel/voice initialization struct used by audio system init.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x130 | int | PitchScale1 | FUN_0044ff50 | Division rate for pitch scaling |
| +0x131 | int | PitchScale2 | FUN_0044ff50 | Division rate for pitch scaling |
| +0x132 | int | PitchScale3 | FUN_0044ff50 | Division rate for pitch scaling |
| +0x133 | int | PitchScale4 | FUN_0044ff50 | Division rate for pitch scaling |
| +0x13a | int | SourceHandle1 | FUN_0044ff50 | Audio source handle |
| +0x13c | int | SourceHandle2 | FUN_0044ff50 | Audio source handle |
| +0x13d | int | SourceHandle3 | FUN_0044ff50 | Audio source handle |
| +0x13e | int | Direction1 | FUN_0044ff50 | Direction flag |
| +0x140 | int | Direction2 | FUN_0044ff50 | Direction flag |
| +0x141 | int | Direction3 | FUN_0044ff50 | Direction flag |
| +0x142 | int | ChannelOffset1 | FUN_0044ff50 | Channel offset |
| +0x144 | int | ChannelOffset2 | FUN_0044ff50 | Channel offset |
| +0x145 | int | ChannelOffset3 | FUN_0044ff50 | Channel offset |
| +0x146 | int | SampleCount1 | FUN_0044ff50 | 8 samples per source |
| +0x147 | int | SampleCount2 | FUN_0044ff50 | 8 samples per source |
| +0xfef | void* | FnPtrTable | FUN_0045d530 | Function pointer table |
| +0xff6 | int | ChannelType | FUN_0045d530 | Set to 8 |

**Notes:**
- Three audio sources per surface: left engine, right engine, exhaust
- 10 control surface slots (cases 0–8) with sample IDs, volume, pan, gain curves
- +0x6ddb–0x6de3 are 8 slots (unclear stride)

---

## NetworkSessionState (inferred)

Based on 1 function (FUN_00563260). Confidence: medium.

Separate from the 0xbf8 manager struct. Contains connection state and client tracking.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | int | ConnectionState | FUN_00563260 | 0=initial, 1+=connected |
| +0x04 | int | ClientArrayPtr | FUN_00563260 | param_1[1]? needs cross-ref |
| +0x70 | int | MaxClientCount | FUN_00563260 | param_1[0x1c] |
| +0x74 | int | ConnAttemptCounter | FUN_00563260 | param_1[0x1d] |
| +0x98 | int | ReconnRetryCounter | FUN_00563260 | param_1[0x26] |

---

## PacketQueueStruct (inferred)

Based on 1 function (FUN_0057afa0). Confidence: medium.

Linked-list packet queue with head/current/tail pointers.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x04 | byte | ActiveFlag | FUN_0057afa0 | Activity flag, reset to 0 |
| +0x08 | int* | HeadPtr | FUN_0057afa0 | List head |
| +0x0c | int* | CurrentPtr | FUN_0057afa0 | Current insertion point |
| +0x10 | int* | TailPtr | FUN_0057afa0 | List tail |
| +0x14 | uint | Counter | FUN_0057afa0 | Total packet count |

---

## AudioSampleRingBuffer (inferred)

Based on 1 function (FUN_004ef2e0). Confidence: medium.

Ring buffer for audio sample streaming with deduplication.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x1018 | double | LastSampleTime | FUN_004ef2e0 | Timestamp of last frame push |
| +0x101c | short[5] | LastFrameData | FUN_004ef2e0 | Previous frame for dedup (10 bytes) |

---

## DynamicStackStruct (inferred)

Based on 1 function (FUN_005648d0). Confidence: high.

Dynamic stack/buffer with automatic growth on overflow. Used in audio mixer buffer management.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | int32 | Top | FUN_005648d0 | Stack pointer / write index |
| +0x04 | int32 | Capacity | FUN_005648d0 | Allocated element count |
| +0x08 | int32 | ElementSize | FUN_005648d0 | Size of each element for growth calc |

---

## AudioMixerValueStruct (inferred)

Based on 1 function (FUN_00562fe0). Confidence: medium.

Simple value store with vtable-based audio dispatch callback.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | int | Value | FUN_00562fe0 | Written from param_2 |
| +0x78 | code* | vtable_fn | FUN_00562fe0 | Audio callback at vtable+0x78 |
| +0x7c | int | ChannelId | FUN_00562fe0 | Passed as third arg to callback |

---

## AudioResourceStruct (inferred)

Based on 1 function (FUN_00552760). Confidence: medium.

Resource management struct with flag-gated sub-resource cleanup.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x0c | uint32 | SubResourcePtr | FUN_00552760 | Freed and zeroed; gated by +0x24 bit 0x20000 |
| +0x24 | uint32 | FlagBitmask | FUN_00552760 | Bit 0x20000 gates cleanup |
| +0x64 | uint32 | ResourceHandle | FUN_00552760 | Primary resource at offset 100, released via FUN_0053cb90 |
| +0x868 | uint32 | SecondaryResource | FUN_00552760 | Conditionally freed |

---

## AudioArrayContainer (inferred)

Based on 1 function (FUN_00564740). Confidence: high.

Simple array container with data buffer and element count.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | void* | DataBuffer | FUN_00564740 | Element data buffer, freed via FUN_0058aa6f |
| +0x04 | int | ElementCount | FUN_00564740 | Loop bound for element cleanup |

---

## AllocStruct18 (inferred, 0x18 bytes)

Based on 1 function (FUN_00564810). Confidence: high.

0x18-byte control struct with separate inner data buffer allocation. Used for audio buffer allocation.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | int | Zeroed | FUN_00564810 | Always zeroed |
| +0x04 | int | ElementSize | FUN_00564810 | Size per element (default 8) |
| +0x08 | int | Capacity | FUN_00564810 | param_1 = capacity |
| +0x0c | int | Count | FUN_00564810 | Count/capacity |
| +0x10 | int | UserData | FUN_00564810 | param_3 (user data) |
| +0x14 | void* | DataBuffer | FUN_00564810 | Inner data buffer (param_1 * param_2 bytes) |

---

## StreamEventDecompressor (inferred)

Based on 1 function (FUN_00510975). Confidence: medium.

Byte-stream event decompressor with nibble storage and dispatch callbacks.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | void* | StreamStruct | FUN_00510975 | Base pointer |
| +0x04 | code* | DispatchFn0 | FUN_00510975 | Secondary dispatch (program-change) |
| +0x14 | byte | EventStatus | FUN_00510975 | Status byte (0x4e=note, 0x1a/0x1b=control) |
| +0x18 | int | EventParam1 | FUN_00510975 | First parameter |
| +0x1c | int | EventParam2 | FUN_00510975 | Second parameter |
| +0xca | byte[16] | NibbleLo | FUN_00510975 | Low-nibble storage (uVar4 < 0x10) |
| +0xda | byte[16] | NibbleHi | FUN_00510975 | High-nibble or full byte storage |

---

## AudioConfigFlagsStruct (inferred)

Based on 1 function (FUN_00551480). Confidence: low.

Simple config flags struct.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x04 | uint | AudioConfigFlags | FUN_00551480 | Bit 12 set, bits 13-14 cleared |

---

## StreamBufferReadStruct (inferred)

Based on 1 function (FUN_0050fab7). Confidence: low.

Stream/buffer read state machine with vtable dispatch.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | uint | vtable | FUN_0050fab7 | Virtual method table |
| +0x08 | uint | IOCallback | FUN_0050fab7 | I/O callback function pointer |
| +0x10 | int | MagicCheck | FUN_0050fab7 | param_1[4]; must be 0xcd |
| +0x60 | uint | CompletionCallback | FUN_0050fab7 | Completion handler (conflict: also listed as total size) |
| +0x78 | uint | ReadCursor | FUN_0050fab7 | Current read position |

**Conflict:** +0x60 appears as both CompletionCallback and TotalSize in the same source. Needs verification.

---

## MessageSlotStruct (inferred, 0x18 bytes per slot)

Based on 1 function (FUN_0057b840). Confidence: medium.

Network message comparison slot layout (inner struct, pointed to by +0x1c of parent).

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x02 | int16 | MessageID | FUN_0057b840 | Short-masked event type |
| +0x04 | int32 | MessageValue | FUN_0057b840 | Subtype or parameter value |
| +0x12 | int16 | MessageID_alt | FUN_0057b840 | Alternative slot ID |
| +0x14 | int32 | MessageValue_alt | FUN_0057b840 | Alternative slot value |

---

## Minor Structs (1 observation each)

### AudioStreamInitStruct (FUN_0057a3f0)
| Offset | Type | Field Name | Notes |
|--------|------|------------|-------|
| +0x00 | int | Active | =1 |
| +0x04 | int | Field1 | =0 |
| +0x08 | uint16 | SampleRate | =0xd45 (3397 — sample rate/format ID) |
| +0x0a | uint16 | BufferSize | =0x1d8 (472) |
| +0x0c | int | Field3 | =0 |
| +0x10–0x2c | int[8] | Reserved | Zeroed |

### VehicleSoundStruct (FUN_004f12e0)
| Offset | Type | Field Name | Notes |
|--------|------|------------|-------|
| +0x7a4 | float | SlipAngle | >0 triggers skid sounds |
| +0x32bc | int | SuspensionType | Engine/road noise selector |
| +0x34ec | float | WheelVelX | Wheel velocity component |
| +0x34f0 | float | WheelVelY | Wheel velocity component |
| +0x34f4 | float | WheelVelZ | Wheel velocity component |
| +0x3668 | void*[4] | WheelPtrs | 4 wheel pointers, stride 0x3e |

### VehicleEngineSoundStruct (FUN_004f88a0)
| Offset | Type | Field Name | Notes |
|--------|------|------------|-------|
| +0x39a0 | float | RPMNumerator | RPM ratio numerator |
| +0x39a4 | float | RPMDenominator | RPM ratio denominator |

### AudioBufferFormatStruct (FUN_0051868c)
| Offset | Type | Field Name | Notes |
|--------|------|------------|-------|
| +0x60 | uint16 | FormatFlags | Audio format flags |
| +0xb8 | int | SampleRate | Sample rate in Hz |
| +0xbc | int | Channels | Channel count |
| +0x10a | short | Interleave | Interleave size, doubles buffer size |
| +0x116 | byte | FormatType | Format-specific override (0/2/3) |
| +0x119 | byte | BitsPerPixel | Bit depth |

### AudioWaveTableStruct (FUN_0051e3e7)
| Offset | Type | Field Name | Notes |
|--------|------|------------|-------|
| +0x64 | int | ChannelCount | param_1+100, per-channel divisor |

---

## Summary

| # | Struct Name | Estimated Size | Functions | Observations |
|---|-------------|---------------|-----------|-------------|
| 1 | NetworkManagerStruct | ~0xbf8 (3064) | 10+ | 50+ |
| 2 | AudioHandleStruct | ~0x870 | 5 | 10 |
| 3 | AudioStreamStruct | ~0x24d4+ | 2 | 5 |
| 4 | AudioChannelInitStruct | ~0xff6+ | 2 | 16 |
| 5 | NetworkSessionState | ~0x98 | 1 | 5 |
| 6 | PacketQueueStruct | ~0x18 | 1 | 5 |
| 7 | AudioSampleRingBuffer | ~0x102c | 1 | 2 |
| 8 | DynamicStackStruct | ~0x0c | 1 | 3 |
| 9 | AudioMixerValueStruct | ~0x80 | 1 | 3 |
| 10 | AudioResourceStruct | ~0x868 | 1 | 4 |
| 11 | AudioArrayContainer | ~0x08 | 1 | 2 |
| 12 | AllocStruct18 | 0x18 | 1 | 6 |
| 13 | StreamEventDecompressor | ~0xea | 1 | 7 |
| 14 | AudioConfigFlagsStruct | ~0x08 | 1 | 1 |
| 15 | StreamBufferReadStruct | ~0x78+ | 1 | 4+1 conflict |
| 16 | MessageSlotStruct | ~0x18 | 1 | 4 |
| 17 | AudioStreamInitStruct | ~0x2c | 1 | 5 |
| 18 | VehicleSoundStruct | ~0x3668+ | 1 | 6 |
| 19 | VehicleEngineSoundStruct | ~0x39a4+ | 1 | 2 |
| 20 | AudioBufferFormatStruct | ~0x11a | 1 | 6 |
| 21 | AudioWaveTableStruct | ~0x68 | 1 | 1 |

**Flags for docs/13 integration:**
- NetworkManagerStruct is the most cross-referenced — strong candidate for a canonical definition
- VehicleSoundStruct offsets (0x7a4, 0x32bc, 0x34ec, 0x3668) may overlap with vehicle physics struct — verify against docs/10-vehicle-physics.md
- AudioHandleStruct +0x58 pattern matches Miles Sound System wrapper idiom
- AudioStreamStruct offsets (0x24xx range) are in a different region vs other audio structs — likely a separate large codec struct

---

## Source: docs/02-ai-system.md

## Summary

**File analyzed:** docs/02-ai-system.md (1536 lines, ~65 `## FUN_` entries)

**Result:** Extracted ~120 offset observations across 9 distinct structs. 2 conflicts identified (see below).

---

## Struct 1: Vehicle / AI Driver Struct (param_1)

Based on 50+ function observations across AI ability processing, pit logic, overtaking, and steering. Confidence: **high**.

This is the main per-vehicle struct (stride ~0x48C0). AI-specific fields occupy the range +0x112e–+0x117f (AI abilities and behavior state) and +0x32c8–+0x48a8 (session, identity, path tracking).

### AI Ability & Behavior Region (+0x112e–+0x117f)

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x112e | float | TireStartTempMult | FUN_00424080 (AI profile loader) | clamp(blend × 0.1 + 1.0, 0.60, 1.40). StartsDry/StartsWet blend + ±1.0 random |
| +0x1130 | int/float | QualifyingAbility (stored) | FUN_00424080, FUN_004bf790 | Stored as `(int)((1.0 - QA) × scale)`. Inverted from .rcd. Larger QA → smaller stored → faster synthetic laps |
| +0x1131 | float | RaceAbility scaled (slowness) | FUN_00424080, FUN_0042af70 | `raw_delta = (22 - RA) / 22`. 0 = ideal, 1 = worst. Quadratic slider scaling applied |
| +0x1132 | float | RainSensitivity | FUN_00424080, FUN_0042a180 | `RainAbility × 0.01 × global_rain_scale`. Used in wet speed mult |
| +0x1133 | float | Passing (overtake effort) | FUN_00424080 | `Passing × 0.001 + 0.9`, capped 1.0. Maps [0,100] → [0.90, 1.0] |
| +0x1135 | float | PushLapProbRef | FUN_00424080, FUN_00429470 | `(22 - RA × 0.67) × (1/22)`. Push lap probability threshold |
| +0x1136 | float | SpeedVarWindow | FUN_00424080, FUN_00429470 | `(1 - 0x113d) × 0.67`. Variation window above base speed target |
| +0x113d | float | BaseSpeedTarget | FUN_00424080, FUN_00429470 | `(1 - RA × 0.01) × DAT_005ea3d8`. Session-scaled base speed ratio |
| +0x113e | float | TrackAggression scaled | FUN_00424080 | `TrackAggression × DAT_007d017c`. Minimum clamp 0.01 |
| +0x1140 | float | CorneringAdd | FUN_00424080 | From .rcd. Default 1.5. Modulates AI cornering speed |
| +0x1141 | float | CorneringMult | FUN_00424080 | From .rcd. Default ≈ 0.967. Modulates AI cornering speed |
| +0x1142 | byte | LapTypeFlag | FUN_00429470, FUN_0042a180 | 0 = conservative lap, nonzero = push lap |
| +0x1143 | byte | PushLapCounter | FUN_00429470, FUN_0042af70 | Consecutive push laps. Subtracts 0.5 from push prob each lap |
| +0x1144 | int | AIBehaviorState | FUN_00424e70 | 4/5 = pit window, 0/6 = follow, 1 = pursuit, 3 = pit entry, 2 = pit in, 7 = overtake |
| +0x114f | float | LiveLapRatio | FUN_00424080, FUN_00429470, FUN_0042a180 | Live lap target ratio. Init 1.0. ±0.01 per lap adjustment. Caps at BaseSpeedTarget or (BaseSpeedTarget + SpeedVarWindow) |
| +0x1152 | byte/flag | SteeringOverwriteFlag | FUN_004270a0 | When set, uses raw 0x1108 steering (no correction) |
| +0x1153 | byte/flag | PushActiveFlag | FUN_0042a180 | Push lap active flag |
| +0x1157 | float? | BrakeAccumulator | FUN_004270a0 | Incremented each frame brakes active |
| +0x115b | byte | FlagByte | FUN_004270a0 | Input gate flag |
| +0x115c | float? | BrakeTimerLeft | FUN_004270a0 | Per-side brake timer |
| +0x115d | float? | BrakeTimerRight | FUN_004270a0 | Per-side brake timer |
| +0x1160 | float | WetSpeedMult | FUN_00424080 (calc), FUN_0042a180 | `1.0 - wetness × 0x1132`. Clamped minimum 0.5 |
| +0x1167 | byte | PitBlockingFlags | FUN_0042aee0, FUN_0042a3d0 | Bit 3 = pit block flag (non-race). Bitmask of pit-related flags |
| +0x1178 | uint/bitmask | PlannedStopsBitmask | FUN_0042a3d0 | Bitmask of planned pit stops |
| +0x117f | byte | OvertakeTargetDirection | FUN_0042af70 | Steering direction: 2 = right, else = left |

### Steering & Racing Line Region (+0x105d–+0x1110)

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x1102 | float | FilteredSteering | FUN_004270a0 | Filtered/clamped copy of steering |
| +0x1103 | float | SteeringOutput | FUN_004270a0 | Final steering angle output |
| +0x1105 | float | SteeringLimitLeft | FUN_004270a0 | Left steering limit from track-speed |
| +0x1106 | float | SteeringLimitRight | FUN_004270a0 | Right steering limit from track-speed |
| +0x1108 | float | RawSteering | FUN_004270a0 | Raw steering value (used when overwrite flag set) |
| +0x1110 | float | SpeedRefValue | FUN_004270a0 | Speed-related reference for overtake threshold |

### Candidate Rival Struct (stride 0x11, at param_1 + 0x105d + i×0x11, i=0..4)

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | ptr | VehiclePtr | FUN_004270a0 | Pointer to rival vehicle |
| +0x03 | float? | LateralDistanceAhead | FUN_004270a0 | Lateral distance to rival ahead |
| +0x0c | float? | LongitudinalGap | FUN_004270a0 | Longitudinal gap to rival |
| +0x0d | float? | ThresholdCheck | FUN_004270a0 | Compared against DAT_0059e95c |
| +0x0e | int | PathSegmentIndex | FUN_004270a0 | From FUN_00403aa0/FUN_004039c0 |
| +0x10 | int | IndexOffset | FUN_004270a0 | For state machine indexing |

### Rival State Machine Array (at param_1[(rivalIdx + 0x263) × 7])

States per rival: 0=normal, 1=passing right, 2=passing left, 3=side-by-side right, 4=side-by-side left, 5=fall back, 7/8=defend, 0x10=alongside.

### Command Queue Region (+0x112a–+0x112c)

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x112a | array | CommandQueue | FUN_00424cd0 | Command queue array |
| +0x112b | int | QueueCapacity | FUN_00424cd0 | Command queue capacity |
| +0x112c | int | QueueCount | FUN_00424cd0 | Command queue entry count |

### Active & State Region (+0x1b0, +0x834, +0xcb2)

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x1b0 | int[] | DriverStateArray | FUN_00419120, FUN_00419690 | State array. Indexed: param_1+0x1b0+param_3×4 = 1 |
| +0x834 | int[4] | SlotActiveFlags | FUN_004bef60 | 4 slot active flags |
| +0xa44 | int[] | PhaseSlotFlags | FUN_0041aa10 | Phase slot flags: param_1+0xa44+param_2×4 = 1 |
| +0xcb2 | int | AIActiveFlag | FUN_00424e70 | 0 or 1 = AI active gate |

### Path Tracking Region (+0x32bc–+0x3a9c)

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x32bc | int | PathValidFlag | FUN_004ef7c0 | Path validity flag |
| +0x32c8 | int | VehicleActiveFlag | FUN_004333e0, FUN_004336f0 | Active flag (AI=0, human=nonzero) |
| +0x34b0–+0x34d0 | float[12] | OrientMatrix | FUN_004ef7c0 | Orientation matrix (3×4 floats) |
| +0x34d4 | float | PathOffsetX | FUN_004ef7c0 | Accumulated path offset X |
| +0x34d8 | float | PathOffsetY | FUN_004ef7c0 | Accumulated path offset Y |
| +0x34dc | float | PathOffsetZ | FUN_004ef7c0 | Accumulated path offset Z |
| +0x34e0 | float | TargetPosX | FUN_004ef7c0 | Target position X |
| +0x34e4 | float | TargetPosY | FUN_004ef7c0 | Target position Y |
| +0x34e8 | float | TargetPosZ | FUN_004ef7c0 | Target position Z |
| +0x3450 | int | PitState | FUN_0041a200 | 1 = in pit |
| +0x3a64 | float | LateralForceX | FUN_0042caa0 | Lateral repulsion/attraction force X |
| +0x3a6c | float | LateralForceZ | FUN_0042caa0 | Lateral repulsion/attraction force Z |
| +0x3a9c | int | TrackingFlag | FUN_004ef7c0 | Path tracking flag (reset to 0) |

### Session & Identity Region (+0x403c–+0x48a8)

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x403c | int | SeasonPoints | FUN_004bf390, FUN_0042af70, FUN_0042a110 | Race rank/points |
| +0x4040 | int | SetupStrategy | FUN_0041a200 | Pit strategy: 2 or -1 |
| +0x404c | float | PlayerSpeed | FUN_00419500 | Player speed reference |
| +0x4058 | int | QualifyingPosition | FUN_004198b0 | Stored qualifying position |
| +0x4060 | int | FinishPosition | FUN_004198b0 | Race finish position. Compared for position change detection |
| +0x4098 | float | RankTime | FUN_004bf390 | Time used for rank comparison |
| +0x409c | float | Gap/BestLapTime | FUN_004bf390 | Gap for non-race sorting |
| +0x40d0 | ptr? | RetirementLink1 | FUN_004199e0 | Retirement linked list |
| +0x40d4 | ptr? | RetirementLink2 | FUN_004199e0 | Retirement linked list |
| +0x4438 | ptr | AIFollowTarget | FUN_00425920 | Follow target vehicle pointer |
| +0x4448 | float | RingBufferField | FUN_00424c80 | Computed from ring buffer + difficulty offset |
| +0x447c | float | PitExitTimestamp | FUN_0042a6f0 | Set to current time + 0.5s |
| +0x4534 | float | PitCrewTimer | FUN_0042a6f0 | Cleared post-pit |
| +0x4550 | int | ProximityFlag | FUN_00429eb0 | Proximity check flag |
| +0x4579 | byte | BrakeActiveFlag | FUN_004270a0 | Brake active flag. Cleared at top of frame, set when braking |
| +0x4584 | int | PitClearedFlag | FUN_0042a6f0 | Pit exit cleanup flag |
| +0x45e0 | int | StintCounter | FUN_0042a6f0 | Incremented each post-pit stint |
| +0x4620 | char[] | DriverName | FUN_004b51e0 | Driver name string buffer |
| +0x4714 | char[] | VehicleDescription | FUN_004333e0, FUN_004b51e0 | Team/livery path or description |
| +0x4794 | char[0xff] | AISettingsFile | FUN_004333e0, FUN_004336f0 | AI settings file path (max 255 bytes) |
| +0x4893 | byte | NullTerminator | FUN_004333e0 | String terminator |
| +0x4894 | int | TeamID/PitIndex | FUN_004333e0 | Team or pit index |

### Other Region

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x27 | int | BehaviorTimer | FUN_0040de60 | Decrements each tick |
| +0x61 | int | ModeSelector | FUN_004a5d10 | AI state machine mode |
| +0x62 | int | SubMode | FUN_004a5d10 | From param_2+4 |
| +0x198 | float | Score/Laptime | FUN_0041e890 | Return value of entrant lookup |
| +0x2c | int | TargetWaypointIdx | FUN_00434d60 | Target waypoint index for steering |
| +0x864 | int[20][8] | DriverDataArray | FUN_00418560, FUN_00418a60 | 20 entries × 8 ints (stride 0x20) |
| +0xaec | int | DriverEntryCount | FUN_00418a60 | Range check bound (0x123) |
| +0xaf4 | ptr* | VtablePtr | FUN_00418a60 | Virtual method table pointer |
| +0xd4 | float? | Accum1 | FUN_004beb10 | Accumulated value |
| +0xd5 | float? | Accum2 | FUN_004beb10 | Accumulated value, += param_1[0xd4] |
| +0xd98 | int | RaceModeParam | FUN_004af220 | Mode-dependent value: 12/14/16 |
| +0xda0 | int | MinBound | FUN_004af220 | Clamp minimum |
| +0xda4 | int | MaxBound | FUN_004af220 | Clamp maximum |
| +0x1170 | int | CompoundFlag | FUN_004af220 | Compound selection 0-3 |
| +0x1178 | int | CompoundMin | FUN_004af220 | Secondary clamp min |
| +0x117c | int | CompoundMax | FUN_004af220 | Secondary clamp max |
| +0x1b10 | int | RaceModeSelector | FUN_004ae9f0 | Mode selector 1-4 |
| +0x1b34 | int | RaceModeParam2 | FUN_004af220 | Mode selector 1-4 |

---

## Struct 2: AI Database Struct (aiDB, param_1 in FUN_004040a0 / FUN_00402690)

Based on 2 function observations. These two functions index the struct differently — FUN_004040a0 uses `param_1[idx]` (4-byte stride), FUN_00402690 uses byte offsets. Both are consistent when converting: byte_offset = idx × 4.

Offset range: +0x00–+0x168 (360 bytes). Confidence: **high**.

| Byte Offset | Index (×4) | Type | Field Name | Observed in | Notes |
|-------------|-----------|------|------------|-------------|-------|
| +0x00 | [0x00] | float | GrooveWidth | FUN_004040a0, FUN_00402690 | Default 4.5f |
| +0x04 | [0x01] | float | GrooveWidthWet | FUN_004040a0, FUN_00402690 | Default 4.3125f |
| +0x11c | [0x47] | float | AiSpeedMultMin | FUN_004040a0, FUN_00402690 | Default 0.5f. Global speed mult lower bound |
| +0x118 | [0x46] | float | AiGlobalSpeedMult | FUN_004040a0 | Computed from slider interpolation |
| +0x120 | [0x48] | float | AiSpeedMultMid | FUN_004040a0, FUN_00402690 | Default 1.0f. Mid bound |
| +0x124 | [0x49] | float | AiSpeedMultMax | FUN_004040a0, FUN_00402690 | Default 1.3f. Upper bound |
| +0x13c | — | float | LapLength | FUN_00402690 | Track lap length |
| +0x140 | — | float | Sector1Length | FUN_00402690 | Sector 1 length |
| +0x144 | — | float | Sector2Length | FUN_00402690 | Sector 2 length |
| +0x14c | — | float | FuelUse | FUN_00402690 | Fuel consumption rate |
| +0x150 | — | struct[] | GridArray | FUN_00402690 | Stride 0x1c, max 104 entries |
| +0x154 | — | struct[] | PitArray | FUN_00402690 | Stride 0x1c, max 52 entries |
| +0x158 | — | struct[] | GarageArray | FUN_00402690 | Stride 0x1c |
| +0x15c | [0x57] | int | PitlaneCount | FUN_004040a0, FUN_00402690 | Default 3 (per FUN_004040a0 [0x5a] — **see conflict below**) |
| +0x160 | [0x58] | int | StartingGridSlots | FUN_004040a0, FUN_00402690 | Default 104. Minimum 104 |
| +0x164 | [0x59] | int | PitSpots | FUN_004040a0, FUN_00402690 | Default 52. Minimum 52 |
| +0x168 | [0x5a] | int | GarageSpots | FUN_004040a0, FUN_00402690 | Default 3. Minimum 3 |
| +0x130 | — | int | WaypointCount | FUN_00402690 | Waypoint array count |
| +0x134 | — | ptr | WaypointArray | FUN_00402690 | Array of waypoints, stride 0x13c |
| +0x12c | — | bool | LeftHandedPits | FUN_00402690 | Boolean flag |

### FUN_004040a0 aiDB[] mappings (4-byte stride indexing)

| Index | Byte Offset | Field Name | Default | Notes |
|-------|-------------|------------|---------|-------|
| [0x00] | +0x00 | GrooveWidth | 4.5 | Confirmed |
| [0x01] | +0x04 | GrooveWidthWet | 4.3125 | Confirmed |
| [0x46] | +0x118 | AiGlobalSpeedMult | computed | Slider interpolation result |
| [0x47] | +0x11c | WorstAdjust / AiSpeedMultMin | 0.5 | Confirmed by FUN_00402690 |
| [0x48] | +0x120 | MidAdjust / AiSpeedMultMid | 1.0 | Confirmed by FUN_00402690 |
| [0x49] | +0x124 | BestAdjust / AiSpeedMultMax | 1.3 | Confirmed by FUN_00402690 |
| [0x4f–0x51] | +0x13c–+0x144 | (default triple) | _DAT_0059e478 | Unknown purpose |
| [0x57] | +0x15c | PitlaneCount | 1 | FUN_004040a0 sets [0x57]=1 |
| [0x58] | +0x160 | StartingGridSlots | 104 | FUN_004040a0 says 104 |
| [0x59] | +0x164 | PitSpots | 52 | FUN_004040a0 says 52 |
| [0x5a] | +0x168 | GarageSpots | 3 | FUN_004040a0 says 3 |

### CONFLICT: aiDB[0x57] vs +0x15c

| Source | Offset | Value | Interpretation |
|--------|--------|-------|---------------|
| FUN_004040a0 | aiDB[0x57] = +0x15c | 1 | Unknown flag / PitlaneCount? |
| FUN_00402690 | +0x15c | pitlanes count | Track-dependent (reads from .gdb) |

**Assessment:** The default value 1 at aiDB[0x57] likely represents a flag (not pitlane count) that gets overwritten when the .gdb file is loaded. At init, aiDB[0x57]=1 is a placeholder. When FUN_00402690 loads the track database, +0x15c is set to the actual pitlane count. No real conflict — same field dual-purposed as flag-at-init and count-at-load.

---

## Struct 3: Waypoint Struct (stride 0x13c = 316 bytes)

Based on FUN_00402690 observations. Confidence: **medium** — offset calculations may use mixed indexing (some byte, some word).

**NOTE:** Offsets below are as documented in FUN_00402690. The +0x0b and +0x25 field positions suggest these may not be simple byte offsets but a mix of byte and sub-byte offsets in a compressed struct.

| Offset | Size | Type | Field Name | Notes |
|--------|------|------|------------|-------|
| +0x00 | 12 | float[3] | Position (x, y, z) | World position |
| +0x08 | 12 | float[3] | PerpVector | Perpendicular direction to track |
| +0x0b | 16 | float[4] | Width | Track width at waypoint |
| +0x16 | 16 | float[4] | DWidth | Width delta |
| +0x12 | 4 | float? | Score | Waypoint score |
| +0x21 | 2 | byte[2] | Event | Event trigger values |
| +0x25 | 12 | float[3] | PosBackup | Backup copy of position |
| +0x46 | 1 | byte | GAlpha | Groove alpha |
| +0x47 | 1 | byte | GrooveLat | Groove lateral offset |
| +0x48 | 12 | ptr[3] | NextPtrs | 3 next-waypoint pointers |
| +0x4b | 1 | byte | BranchID | Branch identifier |
| +0x4c | 1 | byte | Bitfields | Waypoint flags |
| +0x4d | 2 | byte[2] | Wpse | Waypoint sequence data |
| +0x110 | 4 | ptr | NextWpPtr | Linked list next pointer |

**Offset overlap concerns:**
- +0x0b (Width, 4 floats = 16 bytes) overlaps with +0x12 (Score, 4 bytes) and +0x21 (Event, 2 bytes) and +0x25 (PosBackup, 12 bytes)
- +0x46 (GAlpha) overlaps with +0x47 (GrooveLat) → these are single bytes, adjacent
- The true byte layout likely differs from the documented offsets. These may be word indices or from an alternate decompile view.

**Recommendation:** Re-examine the .c source for FUN_00402690 to resolve the byte addressing scheme for this struct.

---

## Struct 4: Driver Data Entry (stride 0x20 = 32 bytes = 8 ints)

Based on FUN_00418560 and FUN_00418a60. Array at param_1+0x864, 20 entries max.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | int | Time/RankKey | FUN_00418560 | Sorted entry; compared against reference |
| +0x14 | int | SortKey | FUN_00418560 | Max entry index by this key |
| +0x00–+0x1c | int[8] | EntryData | FUN_00418a60 | Full 8-field entry |

---

## Struct 5: AI Path / Entrant Struct (stride 0x48c0, from FUN_00418ee0)

Based on FUN_00418ee0 (target driver selection). Confidence: **low** — only 1 observation.

| Offset | Type | Field Name | Notes |
|--------|------|------------|-------|
| +0x00–+0x48bf | byte[0x48c0] | EntrantEntry | Full entrant data block, stride 0x48c0 |
| (entry base) | — | DriverIndex | Iterated from DAT_005f0cf8 |

---

## Struct 6: Shift Struct (param_1 in FUN_0042b8d0)

Based on 1 observation. Confidence: **medium**.

| Offset | Type | Field Name | Notes |
|--------|------|------------|-------|
| +0x00 | float | UpshiftRPM | AI upshift RPM target |
| +0x04 | float | DownshiftRPM | AI downshift RPM target |
| +0x08 | int | DisallowedFlags | Bitmask of disallowed ranges |

---

## Struct 7: Linked List Node (FUN_004bf790)

Based on 1 observation. Confidence: **medium**.

| Offset | Size | Type | Field Name | Notes |
|--------|------|------|------------|-------|
| +0x00 | 8 | struct | EntrySubNode | 8 bytes: ID (4) + QA score float (4) |
| +0x04 | 4 | ptr | NextNode | Next linked list node pointer |
| +0x08 | 1 | byte | Flag | Set to 1 |

**Note:** +0x00 and +0x04 overlap by 4 bytes. The node is 0xc (12) bytes total, with sub-node contained inline. Layout appears to be: [subnode 8 bytes][next ptr 4 bytes][flag byte 1 byte] with alignment padding.

---

## Struct 8: Config Entry Node (FUN_00433b60)

Based on 1 observation. Confidence: **low** — only total size known.

| Offset | Type | Field Name | Notes |
|--------|------|------------|-------|
| +0x00–+0x1b | byte[0x1c] | ConfigNode | Allocated and linked. Total size 0x1c bytes |

---

## Struct 9: Race Mode State Struct (FUN_004ae9f0 / FUN_004af220)

Based on 2 observations. Confidence: **low** — sparse data. These may overlap with the Vehicle struct (param_1) at different offsets.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x1b10 | int | DifficultyMode | FUN_004ae9f0 | 1-4 selector |
| +0x1b34 | int | ModeSelector | FUN_004af220 | 1-4 selector |

These are at high offsets (+0x1b10, +0x1b34) — likely still within the Vehicle struct (stride ~0x48C0), not a separate struct.

---

## Summary of New Offset Regions Not in docs/13-struct-offsets.md

The following regions have offset observations from 02-ai-system.md that are **not yet present** in `docs/13-struct-offsets.md`:

1. **AI Ability region** (+0x112e–+0x1144): 15 fields (TireStartTempMult, QualifyingAbility stored, RaceAbility scaled, RainSensitivity, Passing, PushLapProbRef, SpeedVarWindow, BaseSpeedTarget, TrackAggression scaled, CorneringAdd, CorneringMult, LapTypeFlag, PushLapCounter, AIBehaviorState, LiveLapRatio)

2. **Steering output region** (+0x1102–+0x1110): 5 fields (filtered steering, steering output, left/right limits, raw steering, speed ref)

3. **Command queue** (+0x112a–+0x112c): 3 fields (queue array, capacity, count)

4. **Brake/steering control** (+0x1152–+0x115d): 5 fields (steering overwrite, push active, brake acc, brake timers)

5. **AI adjustment region** (+0x1135–+0x1141): 6 additional fields from .rcd processing

6. **Path tracking** (+0x32bc–+0x3a9c): 10 fields (path valid, orientation matrix, offset x/y/z, target pos x/y/z, lateral forces, tracking flag)

7. **AI session fields** in the +0x834–+0xcb2 range: 3 fields (slot active flags, phase slot flags, AI active flag)

8. **Pit/retirement related** (+0x40d0–+0x45e0): 8 fields (retirement links, pit exit timestamp, pit crew timer, proximity flag, brake active, pit cleared, stint counter, AI follow target, ring buffer, AIBehaviorState)

9. **Composite fields**: +0x0d5, +0x0d98, +0x0da0, +0xda4, +0x1170, +0x1178, +0x117c, +0x1b10, +0x1b34

All of these should be added to `docs/13-struct-offsets.md` for completeness.

---

## Cross-reference: fields already in docs/13-struct-offsets.md

| Field | 13-struct-offsets.md | 02-ai-system.md | Match? |
|-------|---------------------|------------------|--------|
| EffectiveLifetimeAtSpawn | +0x1db4 | Not used in AI doc | N/A |
| LifetimeEngineRPM min/max | +0x1dbc/+0x1dc4 | Not used in AI doc | N/A |
| LifetimeOilTemp min/max | +0x1dcc/+0x1dd4 | Not used in AI doc | N/A |
| PitStopFlag bitmask | +0x1180 | +0x1178 | **MISMATCH** — AI doc says +0x1178 for PlannedStopsBitmask, 13-struct-offsets says +0x1180. Need resolution. |

### CONFLICT: PitStopFlag offset

| Source | Offset | Notes |
|--------|--------|-------|
| docs/13-struct-offsets.md | +0x1180 | PitStopFlag bitmask |
| docs/02-ai-system.md (FUN_0042a3d0) | +0x1178 | PlannedStopsBitmask |

These may be **different fields** at adjacent offsets: +0x1178 = planned stops bitmask (from .rcd, written by FUN_0042a3d0), +0x1180 = runtime pit stop flag (set during pit operations). No conflict — adjacent fields in the same struct.

**Recommendation:** Retain both offsets as separate fields in the consolidated struct definition.

---

## Source: docs/07-pit-system.md

Source: docs/07-pit-system.md (23 entries, 25+ offset observations)

---

## Pooled Struct Groupings

### Struct 1: Pit Crew Actor (inferred)

Based on 1 function observation (FUN_004a2a90). Confidence: **high**.

Stride 0x78, allocated as array.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | uint16 | DetailLevel | FUN_004a2a90 | detail level |
| +0x03 | byte | LollipopFlag | FUN_004a2a90 | 1 if actor name == "LOLLIPOP" |
| +0x26 | float | PosX | FUN_004a2a90 | POSITION directive x |
| +0x2a | float | PosY | FUN_004a2a90 | POSITION directive y |
| +0x2e | float | PosZ | FUN_004a2a90 | POSITION directive z |
| +0x2c | float[?] | Rotate | FUN_004a2a90 | ROTATE directive, quaternion or euler × _DAT_0059e65c |

**Notes:** Parsed from .mts pit crew model files. Wheel meshes mapped by name (LFWHEELOFF/ON, RFWHEELOFF/ON, LRWHEELOFF/ON, RRWHEELOFF/ON) to indices 0–3.

---

### Struct 2: Pit Order Config (inferred)

Based on 1 function observation (FUN_004d12c0). Confidence: **medium**.

Reads PITORDER section from file. Small config struct for pit crew ordering.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x1a8 | int | PitOrderCount | FUN_004d12c0 | number of pit order entries |
| +0x1ac | char** | PitOrderArray | FUN_004d12c0 | array of string pointers, stride 8 per entry |

**Notes:** `ReversePitOrder` config (True/False) reverses the array. Each entry is a pit crew role name string pointer.

---

### Struct 3: Vehicle Struct — Livery/Pit Section (low offsets)

Based on 3 function observations. Confidence: **medium**.

These offsets are in the vehicle struct (0x0000–0x48C0 range) at low addresses.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x60 | byte | PitFlag | FUN_004a6e50 | pit state flag |
| +0x61 | byte | PitState | FUN_004a6e50 | 1=entering, 2=in pits, 3=exiting, 4=collision avoid |
| +0x62 | byte | PitEntryTimer | FUN_004a6e50 | pit entry countdown |
| +0xf3 | char* | LiveryName | FUN_004ddad0 | livery name string |
| +0xf5-0xf9 | ptr | TrackLiveryList | FUN_004ddad0 | TrackLivery linked list pointer |
| +0xf6 | ptr | PitCrewLivery | FUN_004ddad0 | pit crew livery pointer |

**Notes:** FUN_004a6e50 pit state offsets at +0x60–+0x62 are distinct from session timer offsets at +0xb0–+0x104. Confidence that +0x60–+0x62, +0xf3–+0xf6 are all in the main vehicle struct.

---

### Struct 4: Vehicle Struct — Session/Pit Timer Section

Based on 2 function observations (FUN_004d2e50, FUN_004d23d0). Confidence: **high**.

Per-vehicle session timing data. Multiple functions access the same offsets consistently.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0xb0 | int | LapTimeRemaining | FUN_004d2e50, FUN_004d23d0 | consistent across both |
| +0xb4 | int | RaceTimeRemaining | FUN_004d2e50, FUN_004d23d0 | consistent across both |
| +0xb8 | int | PitTimeOffset | FUN_004d2e50, FUN_004d23d0 | pit closure offset |
| +0xc1 | byte | PenaltyFlag | FUN_004d2e50, FUN_004d23d0 | penalty state flag |
| +0xc2 | byte | FormationLapFlag | FUN_004d2e50, FUN_004d23d0 | consistent across both |
| +0xd8 | int | PitWindowOpenTime | FUN_004d2e50, FUN_004d23d0 | consistent across both |
| +0xf4 | byte | FinishState | FUN_004d2e50 | 2=finished (0=running, 1=finished, 2=DNF, 3=DSQ) |
| +0x104 | byte | ProcessedFlag | FUN_004d2e50 | flag: already processed |

**Conflicts:** None — all offsets are consistent across both functions.

**Relationship to existing docs/13:** The existing docs/13 has physics vehicle offsets in range +0x1140–+0x1dc4. These session timer offsets (+0xb0–+0x104) are at a lower address range in what appears to be the same vehicle struct.

**New offsets not in docs/13:** +0xb0, +0xb4, +0xb8, +0xc1, +0xc2, +0xd8, +0xf4, +0x104

---

### Struct 5: Part Repair/Status (maybe sub-struct of vehicle or separate)

Based on 1 function observation (FUN_004a58b0). Confidence: **low** (struct identity uncertain).

Could be a per-part struct or a section of the vehicle struct. Offsets span +0x28 to +0x17c.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x28 | int | ManualEntryFlag | FUN_004a58b0 | 1=automatic entry, !=1=manual |
| +0x36 | char[?] | PartCostDisplayBuf | FUN_004a58b0 | part cost display string buffer |
| +0x58 | double | WearScaleA | FUN_004a58b0 | wear coefficient A |
| +0x60 | double | WearScaleB | FUN_004a58b0 | wear coefficient B |
| +0x6c | int | PartWearIndex | FUN_004a58b0 | part wear index (int-indexed 0x1b) |
| +0x76 | char[?] | WearPctDisplayBuf | FUN_004a58b0 | wear percentage display buffer |
| +0xb6 | char[?] | PartStatusDisplayBuf | FUN_004a58b0 | part name + status display buffer |
| +0xec | double | CurrentWear | FUN_004a58b0 | current wear value (int-indexed 0x3b) |
| +0xf0 | double | TargetWear | FUN_004a58b0 | target wear after repair (int-indexed 0x3c) |
| +0xf6 | char[?] | RepairDeltaDisplayBuf | FUN_004a58b0 | repair delta display buffer |
| +0x128 | int | AutoRepairFlag | FUN_004a58b0 | 1=automatic repair (int-indexed 0x4a) |
| +0x12c | int | DoNotRepairFlag | FUN_004a58b0 | 0=don't repair (int-indexed 0x4b) |
| +0x136 | char[?] | RepairDecisionBuf | FUN_004a58b0 | repair decision display buffer |
| +0x17c | float | CurrentLapWearFlag | FUN_004a58b0 | if 0 → clear wear display (int-indexed 0x5f) |

**Notes:** Offsets use mixed indexing: some given as int-index (param_1[N] where byte offset = N*4) and some as raw byte offsets. All converted to byte offsets here. This may be a per-part sub-struct within the vehicle struct rather than a standalone struct.

---

### Struct 6: Vehicle Struct — Team/Part Fields (high offsets)

Based on 2 function observations. Confidence: **medium**.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x3450 | int | TeammatePartValue | FUN_004a5c40 | part value from teammate vehicle |
| +0x4894 | int | TeamID | FUN_004a4900 | team/pit index for pit crew instance |
| +0x48a4 | int | TeamID2 | FUN_004a5c40 | Secondary TeamID comparison field |

**Conflicts/Notes:**
- +0x4894 (TeamID) matches existing docs/13 and system prompt struct table. Confirmed.
- +0x48a4 (TeamID2) is 0x10 bytes after +0x4894. Could be a second TeamID field or a different field. The system prompt shows +0x4894 for TeamID and +0x489c for DriverNumber. So +0x48a4 is 8 bytes after DriverNumber. Not in existing docs/13.

**New offsets not in docs/13:** +0x3450, +0x48a4

---

### Struct 7: Pit Tire/Waiting State (vehicle struct, high offset)

Based on 1 function observation (FUN_004d2210). Confidence: **low**.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x32C8 | byte | PitTireState | FUN_004d2210 | 0=old tires, 1=waiting for new tires |

**Notes:** Value 13000 decimal = 0x32C8. Used in pit close logic to check which vehicles still need tire changes.

---

## Summary of new offsets for docs/13

New offsets discovered (not in existing docs/13 as of 2026-07-15):

| Range | Struct | New Offsets |
|-------|--------|-------------|
| Vehicle struct — session timer | Vehicle | +0xb0, +0xb4, +0xb8, +0xc1, +0xc2, +0xd8, +0xf4, +0x104 |
| Vehicle struct — pit state | Vehicle | +0x60, +0x61, +0x62 |
| Vehicle struct — livery | Vehicle | +0xf3, +0xf5, +0xf6 |
| Vehicle struct — high | Vehicle | +0x3450, +0x48a4, +0x32C8 |
| Pit crew actor | Separate (stride 0x78) | +0x00, +0x03, +0x26, +0x2a, +0x2e, +0x2c |
| Pit order config | Separate | +0x1a8, +0x1ac |
| Part repair (maybe vehicle sub-struct) | TBD | +0x28, +0x36, +0x58, +0x60, +0x6c, +0x76, +0xb6, +0xec, +0xf0, +0xf6, +0x128, +0x12c, +0x136, +0x17c |

---

## Source: docs/04-tire-system.md

Source: `docs/04-tire-system.md` — 6 functions with struct offset observations,
~35 offset observations across 5 inferred structs.

---

## Struct 1: VehiclePhysicsInstance (tire region)

Based on 3 function observations (FUN_0043e050, FUN_004537b0, FUN_00454350).
Confidence: **high** — offsets confirmed by multiple functions and match existing
13-struct-offsets.md reference.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x0060 | int | wheelState0 | FUN_0043e050 | zero-initialized; per-wheel state |
| +0x0064 | int | wheelState1 | FUN_0043e050 | zero-initialized; per-wheel state |
| +0x0068 | double | tireModelStep | FUN_0043e050 | computed: `400 >> TireModelMode` × multiplier |
| +0x1140 | double[8] | frontTireTelemetry | FUN_004537b0, FUN_00454350 | 8 double telemetry values per front axle; consistent with 13-struct-offsets.md |
| +0x1160 | byte[16] | frontCompoundFlags | FUN_004537b0, FUN_00454350 | compound/state flag array; consistent with ref |
| +0x1170 | int | currentFrontCompound | FUN_004537b0, FUN_00454350 | index into compound array; compared to 4 constants → HUD display |
| +0x1174 | int | pitstopCompound2 | FUN_004537b0, FUN_00454350 | compound selection for pitstop 2 |
| +0x1178 | int | pitstopCompound3 | FUN_004537b0, FUN_00454350 | compound selection for pitstop 3 |
| +0x117c | int | pitstopCompound4 | FUN_004537b0, FUN_00454350 | compound selection for pitstop 4 |
| +0x1180 | uint | pitStopFlag | FUN_004537b0, FUN_00454350 | bitmask: bit0=stop1, bit0x100=stop2, bit0x200=stop3, bit0x400=stop4 |
| +0x153c | double[8] | rearTireTelemetry | FUN_004537b0, FUN_00454350 | 8 double telemetry values per rear axle; consistent with ref |
| +0x155c | byte[16] | rearCompoundFlags | FUN_004537b0, FUN_00454350 | compound/state flag array; consistent with ref |
| +0x1f00 | int/ptr | contextData | FUN_0043e050 | set from stack parameter (opaque context ptr) |

**Pre-existing reference offsets (from 13-struct-offsets.md, same struct):**
| +0x1db4 | double | effectiveLifetime | existing ref | engine lifetime at spawn |
| +0x1dbc | double | lifetimeRPMMin | existing ref | |
| +0x1dc4 | double | invLifetimeRPMMax | existing ref | 1 / max (stored as reciprocal) |
| +0x1dcc | double | lifetimeOilTempMin | existing ref | |
| +0x1dd4 | double | invLifetimeOilTempMax | existing ref | 1 / max (stored as reciprocal) |

**Coverage gap:** Offsets +0x006c to +0x113f (~4,308 bytes) between wheel states
and tire telemetry region are undocumented.

---

## Struct 2: TireBrandManager

Based on 1 function observation (FUN_004d7660).
Confidence: **medium** — only one function accesses this struct.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | int | brandCount | FUN_004d7660 | number of tire brands loaded |
| +0x04 | ptr | brandArray | FUN_004d7660 | array of TireBrandEntry (stride 0x24) |

---

## Struct 3: TireBrandEntry (stride 0x24)

Based on 2 function observations (FUN_004d7150, FUN_004d7880).
Confidence: **medium** — two functions access this struct; stride confirmed.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | char* | brandName | FUN_004d7880 (inferred) | name pointer, searched by linear comparison |
| +0x04 | unknown | pad_or_ptr | — | 4 bytes gap, no documented access |
| +0x08 | int | slipcurveCount | FUN_004d7150 | number of slip curves for this brand |
| +0x0c | ptr | slipcurveArray | FUN_004d7150 | array of SlipCurveEntry (stride 0x18) |
| +0x10 | int | compoundCount | FUN_004d7150 | number of tire compounds for this brand |
| +0x14 | ptr | compoundArray | FUN_004d7150 | array of TireCompoundEntry (stride 0x2a8) |
| +0x18–+0x23 | unknown | unknown | — | 12 bytes undocumented (rest of 0x24 stride) |

---

## Struct 4: TireCompoundEntry (stride 0x2a8 = 680 bytes)

Based on 2 function observations (FUN_004d6b00, FUN_004d7570).
Confidence: **medium** — compound stride (0x2a8) confirmed by VALIDATE pattern
in FUN_004d7570 (index × 0x2a8).

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00–+0xdf | — | (header/gap) | — | 224 bytes undocumented |
| +0x0e0 | unknown (likely double) | wearRate | FUN_004d6b00 | player tire wear rate |
| +0x0f0 | unknown (likely double) | aiSensitivityMin | FUN_004d6b00 | AI tire sensitivity minimum |
| +0x0f8 | unknown (likely double) | aiSensitivityMax | FUN_004d6b00 | AI tire sensitivity maximum |
| +0x100 | unknown (likely double) | aiGripMult | FUN_004d6b00 | AI grip multiplier |
| +0x110 | unknown (likely double) | aiWearMult | FUN_004d6b00 | AI-specific wear multiplier (independent from wearRate) |
| +0x114–+0x2a7 | — | (rest) | — | 404 bytes undocumented |

**Type ambiguity:** The doc does not specify types for these fields. They are
loaded by .tbc parser and used in physics sim — doubles are typical for this
game's physics parameters, but could be floats.

**Moddability:** All 5 fields in this struct are `.tbc` file parameters and
thus `configurable`.

**Note on +0x0f0/+0x0f8:** doc describes as "AI tire sensitivity, min/max" at
+0x0f0 with max at +0x0f8. These likely form a min/max range pair.

---

## Struct 5: SlipCurveEntry (stride 0x18 = 24 bytes)

Based on 2 function observations (FUN_004d5f70, FUN_004d75d0).
Confidence: **medium** — stride (0x18) confirmed by linear search in
FUN_004d75d0.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | char* | name | FUN_004d75d0 | searched by name string (linear comparison) |
| +0x04 | unknown | pad_or_id | — | 4 bytes gap, no documented access |
| +0x08 | float | peakSlip | FUN_004d5f70 | computed: max point of cubic spline evaluation |
| +0x0c | float | peakGrip | FUN_004d5f70 | computed: max grip from spline; all coeffs normalized by this |
| +0x10 | int | pointCount | FUN_004d5f70 | number of data points (≥3, first must be 0.0) |
| +0x14 | ptr | splineData | FUN_004d5f70 | array of cubic spline coefficients (stride 0x20 = 4 doubles per segment) |

**Type inference:** peakSlip/peakGrip sized as float (4 bytes each). If both
were double (8 bytes each), they would overflow the 0x18 stride. The doc does
not specify types; this is a best-fit inference.

**Spline data format:** Each segment at +0x14[i] = 4 doubles (a, b, c, d) for
cubic polynomial: ax³ + bx² + cx + d. Total spline = (pointCount - 1) × 4
doubles.

---

## Cross-Function Conflict Summary

| Offset | Conflicting Observations | Resolution |
|--------|------------------------|------------|
| (none) | — | No conflicts found across functions in this doc |

All observations are consistent across functions that access the same struct.
No type conflicts detected.

## New Offsets vs Existing Reference

Offsets in this analysis **not present** in `13-struct-offsets.md`:

- VehiclePhysicsInstance: +0x0060, +0x0064, +0x0068, +0x1f00
- TireBrandManager: +0x00, +0x04
- TireBrandEntry: +0x00, +0x04, +0x08, +0x0c, +0x10, +0x14
- TireCompoundEntry: +0x0e0, +0x0f0, +0x0f8, +0x100, +0x110
- SlipCurveEntry: +0x00, +0x04, +0x08, +0x0c, +0x10, +0x14

Offsets already in `13-struct-offsets.md` (confirmed):
- VehiclePhysicsInstance: +0x1140–+0x115c, +0x1160, +0x1170, +0x1174–+0x117c, +0x1180, +0x153c–+0x1558, +0x155c

---

## Source: docs/05-weather-system.md

Source: docs/05-weather-system.md (3 function entries, 13+ offset observations)

---

## WeatherState (inferred)

Weather state struct passed as `param_1` to weather system functions. Used by weather loader, file reader, file writer, and initializer. Contains wetness values, temperatures, fog/sun params, and a linked list of per-minute weather changes.

Based on 3 function observations. Confidence: **high** (consistent across all 3 functions).

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x0c | float | unknown_flag | FUN_004fcaa0 | init to 1.0 |
| +0x10 | int | unknown_id | FUN_004fcaa0 | init to -1 (0xFFFFFFFF) |
| +0x18 | float | unknown_val | FUN_004fcaa0 | init to -1.0 |
| +0x20 | float | unknown_zero | FUN_004fe350 | init to 0; only in FUN_004fe350 |
| +0x24 | float | unknown_zero2 | FUN_004fe350 | init to 0; only in FUN_004fe350 |
| +0x28 | float | OnPathWetness | FUN_004fe350, FUN_004fe820 | track grip on racing line; range ~[0,1]; default 0.0 |
| +0x2c | float | OffPathWetness | FUN_004fe350, FUN_004fe820 | track grip off racing line; clamped >= OnPathWetness; default 0.0 |
| +0x30 | float | AmbientTemp | FUN_004fe350, FUN_004fe820 | ambient temp in °C; default 20.0 |
| +0x34 | float | TrackTemp | FUN_004fe350, FUN_004fe820 | track temp in °C; default 22.0 (ambient + 2°C) |
| +0x38 | pointer | WeatherChangeTail | FUN_004fe350, FUN_004fe820 | linked list tail/current node of per-minute weather changes |
| +0x3c | pointer | WeatherChangeHead | FUN_004fe350, FUN_004fe820 | linked list head of per-minute weather changes |
| +0xa4 | float | unknown_neg1 | FUN_004fcaa0 | init to -1.0 |
| +0xa8 | float | sun_elevation | FUN_004fcaa0 | read for fog computation |
| +0xb4 | float | sun_pos_x | FUN_004fcaa0 | sun/light position X (trackPos.x * _DAT_0059e460) |
| +0xb8 | float | sun_pos_y | FUN_004fcaa0 | sun/light position Y |
| +0xbc | float | sun_pos_z | FUN_004fcaa0 | sun/light position Z |
| +0xc0 | float | fog_color_r | FUN_004fcaa0 | init to 0.75 |
| +0xc4 | float | fog_color_g | FUN_004fcaa0 | init to 0.75 |
| +0xc8 | float | fog_color_b | FUN_004fcaa0 | init to 0.75 |
| +0xcc | float | fog_param1 | FUN_004fcaa0 | init to 0.5; probably fog density/start |
| +0xd0 | float | fog_param2 | FUN_004fcaa0 | init to 0.5 |
| +0xd4 | float | fog_param3 | FUN_004fcaa0 | init to 0.5 |
| +0xd8 | float | sun_angle_cos | FUN_004fcaa0 | out param from FUN_00543a30 (sun angle computation) |
| +0xdc | float | sun_angle_sin | FUN_004fcaa0 | out param from FUN_00543a30 |
| +0xe0 | float | sun_angle_result | FUN_004fcaa0 | in/out param from FUN_00543a60 (sun vector magnitude?) |
| +0xe4 | float | unknown_175 | FUN_004fcaa0 | init to 175.0 |
| +0xe8 | float | unknown_700 | FUN_004fcaa0 | init to 700.0 |
| +0xec | float | fog_derived | FUN_004fcaa0 | derived from sun elevation and angle result |
| +0xf0 | int | unknown_zero3 | FUN_004fcaa0 | init to 0 |
| +0xf4 | float | unknown_150 | FUN_004fcaa0 | init to 150.0 |
| +0xf8 | float | unknown_001 | FUN_004fcaa0 | init to 0.01 |
| +0x1c4 | byte | unknown_flag | FUN_004fcaa0 | init to 0 |

**WeatherChangeNode** (linked list node, stride 0x10):
| Offset | Type | Field | Observed in | Notes |
|--------|------|-------|-------------|-------|
| +0x00 | float | time_minutes | FUN_004fe350, FUN_004fe820 | minutes since session start for this weather change |
| +0x04 | float | ambient_temp | FUN_004fe350, FUN_004fe820 | temperature at this time point |
| +0x08 | float | conditions | FUN_004fe350, FUN_004fe820 | wetness/grip multiplier at this time point |
| +0x0c | pointer | next | FUN_004fe350, FUN_004fe820 | next node in linked list (null = end) |

---

## UIComboBox (inferred)

UI widget struct passed as `param_1` to FUN_00470da0. Used for weather mode selection dropdown. `param_1` is `undefined4*` (int-indexed). Vtable pointer at +0x00, widget-specific fields start at int-index +0xc9 (byte offset +0x324).

Based on 1 function observation. Confidence: **medium** (only one function touches this struct).

| Byte Offset | Int Index | Type | Field Name | Observed in | Notes |
|-------------|-----------|------|------------|-------------|-------|
| +0x000 | +0x00 | pointer | vtable | FUN_00470da0 | set to PTR_FUN_005a09c0 |
| +0x324 | +0xc9 | int | option_count | FUN_00470da0 | set to 5 (5 weather mode options) |
| +0x328 | +0xca | int | default_index | FUN_00470da0 | set to 0 |
| +0x32c | +0xcb | int | active_flag | FUN_00470da0 | set to 1 |
| +0x330 | +0xcc | int | unknown_flag | FUN_00470da0 | set to 1 |
| +0x334 | +0xcd | int | scroll_offset | FUN_00470da0 | set to 0x19b (411) |
| +0x338 | +0xce | pointer | weather_mode_ptr | FUN_00470da0 | set to `&DAT_007cf080 + DAT_007d0410 * 9` (per-season weather offset) |

---

## Summary

- **WeatherState**: 30 fields documented across 0x0c–0x1c4 range. Struct size >= 0x1c8 (452+ bytes). High confidence.
- **WeatherChangeNode**: 4 fields, stride 0x10. High confidence (traversal pattern confirmed in 2 functions).
- **UIComboBox**: 7 fields documented. Medium confidence (single function observation). Likely shared widget type used by multiple UI screens.

No conflicts detected across all observations — all offset types and uses are consistent.