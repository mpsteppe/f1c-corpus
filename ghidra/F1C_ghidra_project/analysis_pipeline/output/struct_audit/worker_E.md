=== AUDIT RESULTS ===

## Section 61: ScoringDB / StandingsEntry

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | int | CategoryID | HIGH | FUN_00435390, FUN_004c03f0 | none |
| +0x04 | int | Reserved0 | HIGH | FUN_00435390, FUN_004c07f0 | none |
| +0x08 | int | (undocumented) | HIGH | FUN_00435390 (set to 0) | MISSING from docs |
| +0x0c | int | (undocumented) | HIGH | FUN_00435390 (set to 0) | MISSING from docs |
| +0x10 | float | Weight | HIGH | FUN_00435390 (0x3ff00000 = 1.875f) | none |
| +0x18 | int[48] | FINISHPOSITION | HIGH | FUN_004c03f0, FUN_004c07f0 (loop 0x30) | none |
| +0xd8 | int[48] | FINISHPOINTS | HIGH | FUN_004c03f0, FUN_004c07f0 (loop 0x30) | none |
| +0x198 | int | SEASONPOINTS | HIGH | FUN_004c03f0, FUN_004c07f0, FUN_004c0f60 | none |
| +0x19c | int | POINTSPOSITION | HIGH | FUN_004c03f0, FUN_004c07f0 | none |
| +0x1a0 | int | POLESTAKEN | HIGH | FUN_004c03f0, FUN_004c07f0 | none |
| +0x1a4 | int | ORIGINALGRIDPOSITION | HIGH | FUN_004c03f0 (string parse) | FUN_004c07f0 does NOT clear this (only +0x1a8) |
| +0x1a8 | int | CURRENTGRIDPOSITION | HIGH | FUN_004c03f0, FUN_004c07f0 (-1 sentinel) | none |
| +0x1ac | int | CONTROLTYPE | HIGH | FUN_004c03f0, FUN_004c07f0 (-1 sentinel) | none |
| +0x1b0 | byte | ACTIVE | HIGH | FUN_004c03f0, FUN_004c07f0, FUN_004c0f60, FUN_004c1370 | none |
| +0xb108 | int | RankEntry0 | HIGH | FUN_004c0f60 | none |
| +0xb120 | ptr | PitAllocA | HIGH | FUN_004c0b10 (freed) | none |
| +0xb128 | ptr | PitAllocB | HIGH | FUN_004c0b10 (freed) | none |
| +0xb144 | int | SeasonStatus | MEDIUM | FUN_004c03f0 | linked string "SEASONPOINTS" in same function |
| +0xb148 | int | CurrentRace / UnknownFlags | HIGH | FUN_004c03f0, FUN_004c11d0 | none |
| +0xb14c | int | RaceSession / SessionType | HIGH | FUN_004c03f0, FUN_004c0f60 (==7), FUN_004c11c0, FUN_004c15a0 (switch 1-7) | none |
| +0xb150 | byte | RaceOver / RankingsDirtyFlag | HIGH | FUN_004c03f0, FUN_004c0f60 (0=needs compute), FUN_004c15a0 | none |

**Summary:** HIGH confidence. All 19 offsets confirmed. Types match. Stride 0x1b4 confirmed across 4 functions.
- CONFLICT: +0x00 and +0x04 exist as additional zeroed fields in FUN_00435390 (undocumented)
- Note: +0x00 through +0x1b0 are per-entry offsets (stride 0x1b4), +0xb108 through +0xb150 are container-level offsets — table would benefit from clearer separation
- FUN_004c07f0 does NOT zero ORIGINALGRIDPOSITION (+0x1a4) — only FUN_004c03f0 writes it via string parse. Different init pathways.

---

## Section 62: AIStateBuffer

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x000 | byte | InitializedFlag | HIGH | FUN_0042ec60 (*param_1 = 1) | none |
| +0x0c4 | dword[4][11] | HistoryBuffer1 | MEDIUM | FUN_0042ec60 | DIMENSION WRONG: code shows 4 rows × 44 slots (0x2c0 bytes), not 4×11 (176 bytes). Stride 0x40 correctly noted but count off. |
| +0xbc4 | dword[55] | HistoryBuffer2 | MEDIUM | FUN_0042ec60 | DIMENSION WRONG: code shows 55 slots × 4 dwords each (0x370 bytes), not 55 dwords. |
| +0x1ca8 | float[4] | SmoothCoeff | HIGH | FUN_0042ec60, FUN_0042e320 (0x3f000000 = 0.5f) | none |

**Summary:** MEDIUM confidence. 4 offsets confirmed but dimensions understated.
- CONFLICT: FUN_0042ebc0 uses +0xC8 not +0xC4 for HistoryBuffer1 base, and +0xbc8 not +0xbc4 for HistoryBuffer2 — shift-direction offset (4 bytes = 1 element). Not a true type conflict.
- Recommend: change dword[4][11] to dword[4][44] (or describe as 4 rows × 44 dword slots). Change dword[55] to dword[55][4] (each slot = 4 dwords).

---

## Section 63: CamMan

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | ptr | MAINVIEWSceneNode | HIGH | FUN_0040c920 (*param_1 = FUN_00544f50("MAINVIEW")) | Docs say observed in FUN_0040cce0 — WRONG. Actually set in FUN_0040c920 (Init). |
| +0x08 | ptr | CurrentCamera | HIGH | FUN_0040cce0 (set to 0), FUN_0040c920 (set from +0x18) | none |
| +0x18 | ptr | CameraObject1 | HIGH | FUN_0040cce0 (released + nulled) | none |
| +0x1c | ptr | CameraObject2 | HIGH | FUN_0040cce0 (released + nulled) | none |
| +0x20 | ptr | CameraObject3 | HIGH | FUN_0040cce0 (released + nulled) | none |
| +0x2e | byte | Flag | HIGH | FUN_0040c9e0 (=0), FUN_0040cce0 (=0) | none |
| +0x38 | int | CameraIndex | HIGH | FUN_0040c9e0 (= -1) | none |

**Summary:** HIGH confidence. All 7 offsets confirmed.
- MINOR: docs list MAINVIEWSceneNode at FUN_0040cce0 but it's actually set in FUN_0040c920. Observed-at column slightly wrong.
- NEW OFFSET: +0x2d (byte) — initialized to 0 in FUN_0040c920. Possibly another flag field.

---

## Section 64: BodyStateArray

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x04 | double | PosX | HIGH | FUN_0056d1c0 (matrix transform read) | none |
| +0x0c | double | PosY | HIGH | FUN_0056d1c0 | none |
| +0x14 | double | PosZ | HIGH | FUN_0056d1c0 | none |
| +0x1c | double | Rot00 | HIGH | FUN_0056d1c0 | none |
| +0x24 | double | Rot01 | HIGH | FUN_0056d1c0 | none |
| +0x2c | double | Rot02 | HIGH | FUN_0056d1c0 | none |
| +0x34 | double | Rot10 | HIGH | FUN_0056d1c0 | none |
| +0x3c | double | Rot11 | HIGH | FUN_0056d1c0 | none |
| +0x44 | double | Rot12 | HIGH | FUN_0056d1c0 | none |
| +0x4c | double | Rot20 | HIGH | FUN_0056d1c0 | none |
| +0x54 | double | Rot21 | HIGH | FUN_0056d1c0 | none |
| +0x5c | double | Rot22 | HIGH | FUN_0056d1c0 | none |
| +0x60 | double | PosDeltaX | MEDIUM | FUN_00441d60 (stride 0x244 loop) | FUN_00441ad0 uses +0x64 as angular vel component |
| +0x64 | double | PosDeltaY | LOW | FUN_00441d60 | DUAL-USE in FUN_00441ad0: used as angular vel (SQRT sqrt component) |
| +0x68 | double | (undocumented) | LOW | Gap between +0x64 and +0x6c | MISSING from docs |
| +0x6c | double | PosDeltaZ / AngularVelX | MEDIUM | FUN_00441ad0 (SQRT component) | none |
| +0x74 | double | AngularVelY | MEDIUM | FUN_00441ad0 (SQRT component) | none |
| +0x7c | double | AngularVelZ | LOW | Not directly referenced in read functions | none |
| +0x134 | double | AngMomX | HIGH | FUN_00441d60, FUN_00441ad0 | none |
| +0x13c | double | AngMomY | HIGH | FUN_00441d60, FUN_00441ad0 | none |
| +0x144 | double | AngMomZ | HIGH | FUN_00441d60, FUN_00441ad0 | none |
| +0x14c | double | ForceX | HIGH | FUN_00441d60 | none |
| +0x154 | double | ForceY | HIGH | FUN_00441d60 | none |
| +0x15c | double | ForceZ | HIGH | FUN_00441d60 | none |

**Summary:** MEDIUM confidence. 12 position/rotation double fields confirmed at HIGH. Dynamics fields partially confirmed.
- CONFLICT: Docs reference FUN_0041ad0 and FUN_0041d60 — these DO NOT EXIST. Correct function names are FUN_00441ad0 and FUN_00441d60 (addresses 0x00441ad0, 0x00441d60). Missing leading hex digit '4'.
- CONFLICT: +0x64 is used as angular velocity component in FUN_00441ad0, not just PosDeltaY. Dual-purpose field.
- NEW OFFSET: +0x68 (double) — undocumented field between PosDeltaY (+0x64) and PosDeltaZ (+0x6c)

---

## Section 65: PerElementForceScalingStruct

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x39d4 | float* | ForceArrayBase | MEDIUM | FUN_0059d9d7 (pfVar3 = unaff_EBX + 0x39d4) | none |
| +0x39f8 | int | ElementCount | MEDIUM | FUN_0059d9d7 (iVar1 = *(unaff_EBX + 0x39f8)) | none |
| +0x3a0c | float | LocalForceMultiplier | MEDIUM | FUN_0059d9d7 (*(unaff_EBX + 0x3a0c)) | none |

**Summary:** LOW confidence as stated. All 3 offsets confirmed but only via register variable (unaff_EBX as base), not struct parameter. Types match docs.

---

## Section 66: SuspensionForceValidator

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | double | ForceX | LOW | FUN_004f3240 (base axis group 0) | INCOMPLETE: 2 more doubles at +0x08, +0x10 per axis |
| +0x18 | double | ForceY | LOW | FUN_004f3240 (axis group 1) | INCOMPLETE: 2 more doubles at +0x18+8, +0x18+0x10 |
| +0x30 | double | ForceZ | LOW | FUN_004f3240 (axis group 2) | INCOMPLETE: 2 more doubles at +0x30+8, +0x30+0x10 |

**Summary:** LOW confidence. Structure has 3 axis groups at stride 0x18, each with 3 doubles (pdVar3[0], pdVar3[1], pdVar3[2] at +0x00, +0x08, +0x10 relative to axis base). Docs only list 1 of 3 doubles per axis (the first). 6 doubles are undocumented.

---

## Section 67: AutoLoadEntry Struct

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| [0] / +0x00 | char* | Track path | HIGH | FUN_00432bf0 (*param_1 cast to byte ptr) | none |
| [2] / +0x08 | char* | Classes | HIGH | FUN_00432bf0 (param_1[2] cast to byte ptr) | none |
| [4] / +0x10 | int | Session | HIGH | FUN_00432bf0 (param_1[4] passed as int arg) | none |
| [5] / +0x14 | char* | (unnamed string) | HIGH | FUN_00432bf0 (param_1[5] cast to byte ptr) | none |

**Summary:** HIGH confidence. All offsets confirmed in FUN_00432bf0. The int-indexed vs byte-offset conflict noted in docs is correctly resolved (compatible). Int-index view: [0]=Track, [2]=Classes, [4]=Session, [5]=unnamed. Byte-offset view: +0x00, +0x08, +0x10, +0x14. ✅ Fully consistent.

---

## Section 68: File Read Loop Struct

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x04 | int | zeroed on start | MEDIUM | FUN_005352d0 (*(param_1+4) = 0) | none |
| +0x10 | int | bufferAvail | MEDIUM | FUN_005352d0 (*(param_1+0x10) compared to 0x4000) | none |
| +0x40 | void* | buffer | MEDIUM | FUN_005352d0 (read arg to *(param_1+0x40)) | none |
| +0x48 | void* | readBufPtr | MEDIUM | FUN_005352d0 (read arg to *(param_1+0x48)) | none |
| +0x5c | char | modeFlag | MEDIUM | FUN_005352d0 (compared to 'w') | none |

**Summary:** LOW confidence as stated. All 5 offsets confirmed.
- NEW OFFSET: +0x38 (int) — read status/result, set to -1 on error or 1 on data available. Undocumented.
- NEW OFFSET: +0x0c (int) — set from +0x48 value, likely a copy of readBufPtr. Undocumented.

---

## Section 69: Texture Allocation Format Struct

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x20 | uint | flags | MEDIUM | FUN_00558d10 (bit 0x100 = allocated) | none |
| +0x2c | int | multiplier | MEDIUM | FUN_00558d10 (multiplies texture size) | none |
| +0x50 | ptr | subStruct | MEDIUM | FUN_00558d10 (resource array ptr) | none |

**Summary:** MEDIUM confidence as stated. All 3 offsets confirmed. Types match.

---

## Section 70: CollisionGridParams

| Offset | Current Type | Field | Confidence | .c Evidence | Conflicts |
|--------|-------------|-------|------------|-------------|-----------|
| +0x00 | int | CellCount | MEDIUM | FUN_0044d520 (0x11=17), FUN_0044dca0 (0x32=50) | Values 17,50 not in docs' list (4,16,37,49,77,97) |
| +0x04 | int | Flags/Counter | MEDIUM | Both init functions (0) | none |
| +0x08 | int | Sentinel/Scale | MEDIUM | Both init functions (0) | none |
| +0x0C | int | MaxDistance | MEDIUM | Both init functions (0) | none |

**Summary:** MEDIUM confidence. Pattern confirms 4 fields at stride 0x10.
- Additional +0x10/+0x14 in init functions (set to 0) are likely the next cell's first two fields (CellCount, Flags). Not separate fields in this struct.
- CellCount documented range should include at least 17 and 50.

---

## Section 71: Small structs

### InvDistance (FUN_0045f2a0)
| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x04 | float | InvDistance | MEDIUM | *(param_1+4) = _DAT_0059e43c / param_2 | none |

### FloatFraction (FUN_00464ef0)
| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x68 | float | ComputedFraction | MEDIUM | *(param_1+0x68) = result | none |

### CollisionFillBlock (FUN_0044f070)
| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x27C | byte[0x100] | FillBlock | MEDIUM | Loop: 0x40 writes × 4 bytes = 0x100 | none |

### ConstraintSolverState (FUN_00454250)
| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x040 | float | Stiffness | LOW | OFFSET WRONG: +0x040 is RELATIVE to constraint set base (iVar5), not param_1. Actual param_1 offset = +0xdc8 (set1) or +0x11c4 (set2) |
| +0x060 | float | RestValue | LOW | Same as above — offset is iVar5-relative. Actual param_1 offset = +0xde8 (set1) or +0x11e4 (set2) |
| +0x398 | float | CurrentValue | LOW | Same as above — offset is iVar5-relative. Actual param_1 offset = +0x1120 (set1) or +0x151c (set2) |
| +0xD88 | float[] | ConstraintSet1 | HIGH | iVar5 = param_1 + 0xd88 when param_3==0 | none |
| +0x1184 | float[] | ConstraintSet2 | HIGH | iVar5 = param_1 + 0x1184 when param_3!=0 | none |

**Summary:** First 3 structs confirmed. ConstraintSolverState has a MAJOR CONFLICT: +0x040/0x060/0x398 are offsets relative to constraint set base (iVar5), not param_1. These fields are also arrays indexed by param_2 (per-constraint), not singletons as documented.

---

## Section 72: Cockpit Dashboard Struct

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x60 | char*? | TAC_01_texture | HIGH | FUN_0049ca00 (param_1+0x60) | Not char* — passed to FUN_0049cd80 as render params |
| +0xac | char*? | WATERTEMP_texture | HIGH | FUN_0049ca00 (param_1+0xac) | Same type concern |
| +0xf8 | char*? | OILTEMP_texture | HIGH | FUN_0049ca00 (param_1+0xf8) | Same type concern |
| +0x144 | char*? | OILPRESS_texture | HIGH | FUN_0049ca00 (param_1+0x144) | Same type concern |
| +0x190 | char*? | FUEL_texture | HIGH | FUN_0049ca00 (param_1+400) | Same type concern |
| +0x20 | char*? | LED165 | HIGH | *(param_1+0x20)=FUN_00548890("LED165") | none |
| +0x24 | char*? | LED170 | HIGH | *(param_1+0x24)=FUN_00548890("LED170") | none |
| +0x28 | char*? | LED175 | HIGH | *(param_1+0x28)=FUN_00548890("LED175") | none |
| +0x2c | char*? | LED182 | HIGH | *(param_1+0x2c)=FUN_00548890("LED182") | none |
| +0x30 | char*? | LEDSL | HIGH | *(param_1+0x30)=FUN_00548890("LEDSL") | none |
| +0x34 | char*? | LEDPSY | HIGH | *(param_1+0x34)=FUN_00548890("LEDPSY") | none |
| +0x38 | char*? | LEDPSR | HIGH | *(param_1+0x38)=FUN_00548890("LEDPSR") | none |
| +0x3c | char*? | LEDLF | HIGH | *(param_1+0x3c)=FUN_00548890("LEDLF") | none |
| +0x40 | char*? | LEDFR | HIGH | *(param_1+0x40)=FUN_00548890("LEDFR") | none |
| +0x44 | char*? | LEDFY | HIGH | *(param_1+0x44)=FUN_00548890("LEDFY") | none |
| +0x48 | char*? | LEDFB | HIGH | *(param_1+0x48)=FUN_00548890("LEDFB") | none |
| +0x04 | undefined | FontResource1 | MEDIUM | *(param_1+4)=FUN_0053cfe0("FONTREAD") | MISSING from docs |
| +0x08 | undefined | FontResource2 | MEDIUM | *(param_1+8)=FUN_0053cfe0("FONTLCD") | MISSING from docs |
| +0x0c | undefined | FontResource3 | MEDIUM | *(param_1+0xc)=FUN_0053cfe0("FONTAIDS") | MISSING from docs |
| +0x10 | ptr | ReadoutBMP | MEDIUM | *(param_1+0x10)=FUN_00547920("READOUT_BMP") | MISSING from docs |
| +0x14 | ptr | LCD00BMP | MEDIUM | *(param_1+0x14)=FUN_00547920("LCD00_BMP") | MISSING from docs |
| +0x18 | ptr | LCD00Extra | MEDIUM | *(param_1+0x18)=FUN_0053cb20("LCD00_BMP") | MISSING from docs |
| +0x1c | ptr | LCD01Extra | MEDIUM | *(param_1+0x1c)=FUN_0053cb20("LCD01_BMP") | MISSING from docs |

**Summary:** MEDIUM confidence. All 16 documented offsets confirmed. 7 new undocumented offsets discovered (font resources, BMP render objects). The gauge texture fields (+0x60 etc.) are render-struct pointers, not char* string pointers. LED fields are handles from FUN_00548890, not char*.

---

## Section 73: PacketQueueStruct

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x04 | byte | ActiveFlag | HIGH | *(param_1+4)=0 | none |
| +0x08 | int* | HeadPtr | HIGH | *(param_1+8)=puVar4, checked ==0 | none |
| +0x0c | int* | CurrentPtr | HIGH | *(param_1+0xc)=puVar4 | none |
| +0x10 | int* | TailPtr | HIGH | *(param_1+0x10)=puVar4 | none |
| +0x14 | uint | Counter | HIGH | *(param_1+0x14)++ | none |

**Summary:** MEDIUM confidence as stated. All 5 offsets confirmed. Types match. Linked list operations correct.

---

## Section 74: Shift Struct

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | float | UpshiftRPM | INVALID | FUN_0042b8d0 param_1 is int (selector 0-3) | NOT a struct pointer — param_1 is an enum |
| +0x04 | float | DownshiftRPM | INVALID | Same as above | Same issue |
| +0x08 | int | DisallowedFlags | INVALID | Same as above | Same issue |

**Summary:** MAJOR CONFLICT — param_1 in FUN_0042b8d0 is used as an integer selector (compared to 3 in if statement, used as an index), NOT a struct pointer. The data for Upshifts/Downshifts/Disallowed comes from string lookups in global arrays (DAT_005c32b0, DAT_005c32bc, DAT_005c32cc). Confidence should be INVALID for this specific function reference. The struct offsets might be valid for a different function but NOT FUN_0042b8d0's param_1.

---

## Section 75: Summary

No offsets to audit. The Summary section correctly consolidates WeatherState, WeatherChangeNode, and UIComboBox findings across multiple worker sessions. No conflicts detected in this section.

=== NEW OFFSETS DISCOVERED ===

| Struct | Offset | Type | Found In | Notes |
|--------|--------|------|----------|-------|
| ScoringDB/StandingsEntry | +0x08 | int | FUN_00435390 | Zeroed in init, purpose unknown |
| ScoringDB/StandingsEntry | +0x0c | int | FUN_00435390 | Zeroed in init, purpose unknown |
| CamMan | +0x2d | byte | FUN_0040c920 | Zeroed in Init, possibly another flag |
| BodyStateArray | +0x68 | double | FUN_00441ad0 | Gap between PosDeltaY (+0x64) and PosDeltaZ/AngVelX (+0x6c) |
| SuspensionForceValidator | +0x08 | double | FUN_004f3240 | pdVar3[1] per axis — second value per axis group |
| SuspensionForceValidator | +0x10 | double | FUN_004f3240 | pdVar3[2] per axis — third value per axis group |
| SuspensionForceValidator | +0x20 | double | FUN_004f3240 | Axis group 1, second value |
| SuspensionForceValidator | +0x28 | double | FUN_004f3240 | Axis group 1, third value |
| SuspensionForceValidator | +0x38 | double | FUN_004f3240 | Axis group 2, second value |
| SuspensionForceValidator | +0x40 | double | FUN_004f3240 | Axis group 2, third value |
| FileReadLoopStruct | +0x38 | int | FUN_005352d0 | Read status/result (-1=error, 0/1=status) |
| FileReadLoopStruct | +0x0c | int | FUN_005352d0 | Set from +0x48, possibly copy of readBufPtr |
| CockpitDashboard | +0x04 | ptr | FUN_0049ca00 | Font resource (FONTREAD) |
| CockpitDashboard | +0x08 | ptr | FUN_0049ca00 | Font resource (FONTLCD) |
| CockpitDashboard | +0x0c | ptr | FUN_0049ca00 | Font resource (FONTAIDS) |
| CockpitDashboard | +0x10 | ptr | FUN_0049ca00 | READOUT_BMP render object |
| CockpitDashboard | +0x14 | ptr | FUN_0049ca00 | LCD00_BMP render object |
| CockpitDashboard | +0x18 | ptr | FUN_0049ca00 | LCD00_BMP second instance |
| CockpitDashboard | +0x1c | ptr | FUN_0049ca00 | LCD01_BMP render object |

=== FUNCTION REFERENCE ERRORS ===

| Struct | Wrong Ref | Correct Ref | Severity |
|--------|-----------|-------------|----------|
| BodyStateArray | FUN_0041ad0 | FUN_00441ad0 (0x00441ad0) | HIGH — function doesn't exist |
| BodyStateArray | FUN_0041d60 | FUN_00441d60 (0x00441d60) | HIGH — function doesn't exist |
| CamMan MAINVIEWSceneNode | FUN_0040cce0 | FUN_0040c920 | LOW — wrong observer listed |
| Shift Struct | FUN_0042b8d0 param_1 | Not a struct | MAJOR — param_1 is int enum, not pointer |

=== CONFIDENCE REVISIONS ===

| Struct | Current Confidence | Recommended | Reason |
|--------|-------------------|-------------|--------|
| ScoringDB/StandingsEntry | HIGH | HIGH | Confirmed |
| AIStateBuffer | MEDIUM | MEDIUM | Dimensions wrong but offsets correct |
| CamMan | (implicit) | HIGH | All offsets confirmed |
| BodyStateArray | MEDIUM | MEDIUM | Some refs wrong, +0x64 dual-use |
| PerElementForceScalingStruct | LOW | LOW | Register-allocated base |
| SuspensionForceValidator | LOW | LOW | Incomplete offset documentation |
| AutoLoadEntry | HIGH | HIGH | Fully confirmed |
| FileReadLoopStruct | LOW | LOW | Only 1 function |
| TextureAllocationFormat | MEDIUM | MEDIUM | All confirmed |
| CollisionGridParams | MEDIUM | MEDIUM | Pattern confirmed, values incomplete |
| Small structs | varied | MEDIUM | All confirmed except ConstraintSolverState offsets |
| CockpitDashboard | MEDIUM | MEDIUM | 7 new offsets, types uncertain |
| PacketQueueStruct | MEDIUM | MEDIUM | All confirmed |
| Shift Struct | MEDIUM | INVALID | Wrong function reference |
