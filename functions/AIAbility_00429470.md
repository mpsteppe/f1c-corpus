## AIAbility_00429470 — AI speed-multiplier adjustment with difficulty scalars and pit-lane logic

**Summary:** Per-frame AI ability recalculation. Adjusts `this[4431]` (+0x453C, AI speed multiplier) by ±0.01 toward a target zone bounded by `this[4413]` (+0x44F4) and `this[4406]+this[4413]` (+0x44D8+0x44F4), with occasional probability-driven overshoot/undershoot and a hard 0.85× override when disqualification state (+0x4064) is 1. Also manages pit-exit logic, tire-compound selection, fuel-weight sanity, and clears several state fields.

**Struct fields accessed:**

| Offset (dec) | Offset (hex) | Read/Write | Init value (if written as literal) | Purpose inferred from code |
|---|---|---|---|---|
| `this[0]` as int* | +0x0000 | Read | — | Vtable/object-base pointer; dereferenced for health-flag guards |
| `this[3390]` (float) | +0x34F8 | Write | 0.0 | Cleared during pit-cleanup |
| `this[3391]` (float) | +0x34FC | Write | 0.0 | Cleared during pit-cleanup |
| `this[3392]` (float) | +0x3500 | Write | 0.0 | Cleared during pit-cleanup |
| `this[3681]` (float) | +0x3984 | Read | — | Speed threshold for pit-entry logic (>0.001) |
| `this[3682]` (float) | +0x3988 | Read | — | Current tire-wear (compared vs threshold at +0x4594) |
| `this[4096]` (float) | +0x4000 | Read | — | Gate value: when >0.0 AND +0x4068==0, sets +0x4068=6 |
| `this[4113]` (float) | +0x4044 | Read | — | Ring-buffer key for AI-difficulty routing (values 0,1,2) |
| `*((_DWORD *)this + 4111)` (int) | +0x403C | Read | — | Track-position index |
| `*((_DWORD *)this + 4112)` (int) | +0x4040 | Read | — | Secondary track-position index |
| `*((_DWORD *)this + 4121)` (int) | +0x4064 | Read | — | DQ state (0=normal, 1=DQ pending, 3=DQ final) |
| `*((_DWORD *)this + 4122)` (int) | +0x4068 | **Write** | 6 | Conditional gate (written when +0x4000>0 AND +0x4068==0) |
| `this[4350]` (float) | +0x43F8 | Write | 0.0 | Cleared during pit-cleanup |
| `this[4360]` (float) | +0x4420 | Write | ±(track curvature from +0x4354) | Steering/heading adjustment from track curve radius |
| `this[4361]` (float) | +0x4424 | Write | 0.0 | Cleared during pit-cleanup |
| `this[4362]` (float) | +0x4428 | Read | — | Used with track-curve radius at +0x4354→+52/+56 |
| `this[4365]` (float) | +0x4434 | Write | 0.0 | Cleared during pit-cleanup |
| `this[4366]` (float) | +0x4438 | Write | 1.0 | Set to 1.0 during pit-cleanup |
| `this[4367]` (float) | +0x443C | Write | 0.0 | Cleaned during pit-cleanup |
| `this[4368]` (float) | +0x4440 | Read | — | Speed/lap threshold: <5.0 bypasses lane-pit; <1.0 triggers full pit-stop path |
| `this[4396]` (float) | +0x44B0 | Write | NAN | Cleared to NAN at end |
| `this[4405]` (float) | +0x44D4 | Read | — | Probability scalar for random overshoot/undershoot |
| `this[4406]` (float) | +0x44D8 | Read | — | Upper-bound additive (summed with +0x44F4) |
| `this[4413]` (float) | +0x44F4 | Read | — | AI target-speed baseline |
| `this[4418]` (float) | +0x4508 | Read/Write | **Write 0.0** | Direction flag (0=slower, nonzero=faster); cleared after use |
| `this[4419]` (float) | +0x450C | Read/Write | **Write 0.0** | Probability variance; cleared after use |
| `*((_DWORD *)this + 4420)` (int) | +0x4510 | Write | 4 or 5 | Pit-state mode: 4 during race, 5 otherwise |
| `this[4425]` (float) | +0x4524 | Write | 0.0 | Cleaned during pit-cleanup |
| `this[4429]` (float) | +0x4534 | Write | 120.0 + dbl_8AFEA0 or 180.0 + dbl_8AFEA0 | Pit-stop timer (120s or 180s base) |
| **`this[4431]` (float)** | **+0x453C** | **Write** | ±0.01 steps, 0.85×, probability push | **AI speed multiplier — main output** |
| `this[4433]` (float) | +0x4544 | Write | 0.0 | Cleared (set to 1.0 early, overwritten to 0.0 later) |
| `this[4435]` (float) | +0x454C | Write | 0.0 | Cleaned during pit-cleanup |
| `*((_DWORD *)this + 4436)` (int) | +0x4550 | Write | 1 | Pit-cleanup flag (set twice) |
| `*((_DWORD *)this + 4447)` (float) | +0x457C | Write | AIDifficultyScalar() * 0.75 or full scalar | Difficulty-scaled parameter |
| `*((_BYTE *)this + 17736)` | +0x4548 | Write | 1 | Pit-cleanup indicator |
| `*((_BYTE *)this + 17785)` | +0x4579 | Write | 0 | Lane-pit state clear |
| `*((_BYTE *)this + 17908)` | +0x45F4 | Write | 0 | Pit-stop state clear |
| `*((_DWORD *)this + 4472)` (int) | +0x45E0 | Read | — | Tire-compound index (×4 for offset into array at +0x4594) |
| `this[4453]` (float) | +0x4594 | Read | — | Tire-wear threshold array entry (indexed by compound*4) |
| `*((_DWORD *)this + 4478)` (int) | +0x45F8 | Read | — | Pointer for fuel-weight double-check |
| `*this + 3284` (int) | vtable+0xCD4 | Read | — | Boolean guard for forced pit exit |
| `*this + 3348` (byte) | vtable+0xD14 | Read | — | Boolean guard for forced pit exit |
| `*this + 3352` (int) | vtable+0xD18 | Read | — | Boolean guard for forced pit exit |
| `*this + 3416` (byte) | vtable+0xD58 | Read | — | Boolean guard for forced pit exit |
| `*((_BYTE *)this + 14842)` | +0x39FA | Read | — | Boolean guard for forced pit exit |

**Guard conditions:**

| Field | Checked values | What PASSES (execution continues) | What is BLOCKED (early return/skip) |
|---|---|---|---|
| `RingBufferAccessWithWrap(this[4113])` | ring-buffer result | **2** = enters first branch (difficulty scalar *0.75, zero flag) | 0 or 1 = enters else-branch (full scalar, speed-multiplier math) |
| `dword_7C56A4` (SessionType) | 7 (race) vs other | 7 = enters AI speed-math block | Other = skips AI speed-math block entirely |
| `this[4418]` | 0.0 vs nonzero | 0 = targets slower bound (this[4413] - 0.01) | nonzero = targets faster bound (this[4406]+this[4413] +0.01) |
| Probability check: `(this[4405] - this[4419]*0.5)*100 >= random%100` | boolean | >= random → pushes toward faster bound | < random → pushes toward slower bound (undershoot to this[4413]*0.5) |
| `*((_DWORD *)this + 4121)` (DQ state) | 1 vs other | **1** = enters DQ-speed-reduction path: `this[4431] = AIDifficultyScalar()*0.75; this[4433]=0.0` | Other = skip |
| `*((_DWORD *)this + 3931)` | 2 vs 1 vs other | 2 = skip pit-exit checks. 1 = enters ForcePitExit guards | Other than 2 → checked further |
| `this[3681] > 0.001` | float | true (speed high enough) → continues pit-exit check | false → skip |
| `this[4096] <= 0.0` | float | true (gate zero) → continues pit-exit check | false → skip |
| `*((_DWORD *)this + 4111) != dword_8ACF8C - 1` | index vs last | Not last → enters lane-pit logic | Last → continues to next check |
| `*((_DWORD *)this + 4112)` | 2 or -1 vs other | 2 or -1 → enters lane-pit logic | Other → continues |
| `this[4368] < 5.0` | float | <5.0 → enters lane-pit logic | >=5.0 → skip lane-pit |
| `this[4368] < 1.0` | float | <1.0 → enters full pit-stop path | >=1.0 → skip |
| `dword_7C56A4 == 7` (SessionType) | 7 vs not | Session-specific paths for pit-stop, lane-clear, fuel check | Non-7 = alternative path |

**Written-by note:** Main write target is `this[4431]` (+0x453C, AI speed multiplier). Written in 4 distinct paths:
1. **Line 142** — `this[4431] = clamped ±0.01 adjustment` toward target zone (when SessionType==7, outer else-branch)
2. **Line 159** — `this[4431] = probability-driven push` (when random check triggers, overwriting prior value)
3. **Line 183** — `this[4431] = this[4413] * 0.85` (when DQ state==1, pit-related state matched)
4. **No-write path** — When RingBuffer result is 2, `this[4431]` is NOT changed (only `this[4433]` and `this[4447]` written)

Because Frame-path is ON_FRAME_PATH and this field is recalculated every frame (with or without change), **any external poke to this[4431] will NOT persist** — overwritten next tick. Same applies to every Write-field listed: all are refreshed or cleared regularly.

**Globals referenced:**

| Address | IDA name | Read/Write | Role |
|---|---|---|---|
| 0x007C56A4 | dword_7C56A4 (SessionType) | Read | Session type guard (7 = race) |
| 0x008ACF8C | dword_8ACF8C | Read | Vehicle count or track-position max |
| 0x008AFEA0 | dbl_8AFEA0 | Read | Base offset for pit-stop timer (added to 120.0 or 180.0) |

**Functions called:**

| Address | IDA name | Inferred purpose |
|---|---|---|
| — | RingBufferAccessWithWrap | Lookup AI difficulty from ring buffer |
| — | AIDifficultyScalar | Return scalar for current AI difficulty level |
| — | RandLCGRandomNumberGenerator | Generate random integer (LCRNG) |
| — | ForcePitExit | Force vehicle to exit pit lane |
| — | ConditionalGate | Session-type-gated gate check |
| — | PitStopDecisionTireCompound | Select tire compound for upcoming pit stop |
| — | SpeedValueSetterWithGlobalMirror | Write speed value with global mirror sync |
| — | PostPitCleanup | Post-pit-stop state reset |
| — | ParameterValueSetter (arg 18) | Set parameter 18 |
| — | AIClearStateFlags | Clear AI state flags |
| — | sub_426430 | Unknown; called during pit-cleanup |
| — | FuelMultiplierValue | Compute fuel multiplier |
| — | FuelWeightLimitCheck | Check fuel weight limit |
| — | RacePhasePitEntryTrigger | Trigger pit-entry logic per race phase |

**Call frequency:** per-frame tick (ON_FRAME_PATH from MainGameTickUpdate)
