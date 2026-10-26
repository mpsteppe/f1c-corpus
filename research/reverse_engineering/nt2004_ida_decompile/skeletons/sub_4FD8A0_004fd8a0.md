## sub_4FD8A0_004fd8a0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_42F350 (0042f350), sub_4B9210 (004b9210)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |
| this | 0x4 | RW | 8 | [LLM] |
| this | 0xC | RW | — | [LLM] |
| this | 0x10 | RW | — | [LLM] |
| this | 0x14 | RW | — | [LLM] |
| this | 0x18 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x10: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x14: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x18: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d5b14 | flt_5D5B14 | R | [LLM] |
| 005fca60 | aWb | R | [LLM] |
| 005fd340 | NumOfElements | R | [LLM] |
| 005ff810 | aClutch | R | [LLM] |
| 005ff8a0 | aBrake | R | [LLM] |
| 005ffc74 | dword_5FFC74 | R | [LLM] |
| 005ffc78 | byte_5FFC78 | R | [LLM] |
| 00601cd4 | aSteering | R | [LLM] |
| 00601d10 | aThrottle | R | [LLM] |
| 00612338 | aOilTemperature | R | [LLM] |
| 00612348 | aWaterTemperatu | R | [LLM] |
| 0061235c | aGear | R | [LLM] |
| 00612364 | aCornerWeight | R | [LLM] |
| 00612374 | aTyreWear | R | [LLM] |
| 00612380 | aTyrePressureKp | R | [LLM] |
| 00612394 | aTyreRightTempK | R | [LLM] |
| 006123a8 | aTyreCenterTemp | R | [LLM] |
| 006123c0 | aTyreLeftTempK | R | [LLM] |
| 006123d4 | aUndertrayRideH | R | [LLM] |
| 006123f0 | aSuspensionDefl | R | [LLM] |
| 0061240c | aWheelspinRadsS | R | [LLM] |
| 00612420 | aRr | R | [LLM] |
| 00612424 | aRl | R | [LLM] |
| 00612428 | aFr | R | [LLM] |
| 0061242c | aFl | R | [LLM] |
| 00612430 | aUnfilteredClut | R | [LLM] |
| 00612444 | aUnfilteredStee | R | [LLM] |
| 00612458 | aUnfilteredBrak | R | [LLM] |
| 0061246c | aUnfilteredThro | R | [LLM] |
| 00612480 | aClutchRpm | R | [LLM] |
| 0061248c | aEngineRpm | R | [LLM] |
| 00612498 | aLongAccelMS | R | [LLM] |
| 006124ac | aVertAccelMS | R | [LLM] |
| 006124c0 | aLatAccelMS | R | [LLM] |
| 006124d0 | aYawRads | R | [LLM] |
| 006124dc | aPosZM | R | [LLM] |
| 006124e8 | aPosYM | R | [LLM] |
| 006124f4 | aPosXM | R | [LLM] |
| 00612500 | aElapsedTimeS | R | [LLM] |
| 00629120 | byte_629120 | R | [LLM] |
| 0062bf64 | unk_62BF64 | R | [LLM] |
| 0075aad0 | dword_75AAD0 | R | [LLM] |
| 0075cbb0 | dword_75CBB0 | R | [LLM] |
| 0075cbc4 | dword_75CBC4 | R | [LLM] |
| 00760b10 | flt_760B10 | R | [LLM] |
| 00766578 | dword_766578 | R | [LLM] |
| 00766594 | dword_766594 | R | [LLM] |
| 00766ae0 | dword_766AE0 | R | [LLM] |
| 00766b04 | dword_766B04 | R | [LLM] |
| 00766b44 | dword_766B44 | R | [LLM] |
| 007d3c50 | dword_7D3C50 | R | [LLM] |
| 007d6a5c | dword_7D6A5C | R | [LLM] |
| 007d6b50 | dword_7D6B50 | R | [LLM] |
| 007d6b58 | dword_7D6B58 | R | [LLM] |
| 007d73d0 | dword_7D73D0 | R | [LLM] |
| 007d741c | dword_7D741C | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042dba0 | sub_42DBA0 | [LLM] |
| 00430670 | ScoreSlotDeallocator [structural] | [LLM] |
| 00430bc0 | sub_430BC0 | [LLM] |
| 004d1a80 | sub_4D1A80 | [LLM] |
| 004f6a10 | sub_4F6A10 | [LLM] |
| 004fe670 | ResourceDestroy [structural] | [LLM] |
| 004fe920 | FileReadWithXORDecode [structural] | [LLM] |
| 004fea10 | sub_4FEA10 | [LLM] |
| 005208c0 | sub_5208C0 | [LLM] |
| 00521740 | sub_521740 | [LLM] |
| 00578600 | StringCopyWithBufferRealloc [structural] | [LLM] |
| 0057b490 | UtilityFunction_8a60 [structural] | [LLM] |
| 005be8ae | sub_5BE8AE | [LLM] |
| 005bea90 | _fopen | [LLM] |
| 005beab0 | _strncpy | [LLM] |
| 005bf290 | __strcmpi | [LLM] |
| 005bf36d | _rand | [LLM] |
| 005bf390 | __alloca_probe [exact] | [LLM] |
| 005bf5a6 | sub_5BF5A6 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `Clutch`
- `Clutch`
- `Brake`
- `Brake`
- `.gdb`
- `Steering`
- `Steering`
- `Throttle`
- `Throttle`
- `Oil Temperature`
- `Oil Temperature`
- `Water Temperature`
- `Water Temperature`
- `Gear`
- `Gear`
- `Corner Weight`
- `Corner Weight`
- `Tyre Wear`
- `Tyre Wear`
- `Tyre Pressure (kPa)`
- … +45 more
