# map_AIBehaviorInitialization — declared `sub_4BF0A0`

## Identity

- Address: `0x4BF0A0`; file `functions/AIBehaviorInitialization_004bf0a0.c`; 136 lines.
- Signature: `int __thiscall sub_4BF0A0(int this, int a2, char a3)`.
- Callers: `AIOvertake` (`0x4BEB10`) L33 (`AIBehaviorInitialization(a3, v8)`); grep `functions/` for
  `AIBehaviorInitialization(` -> `functions/AIOvertake_004beb10.c`; TARGETS manifest agrees (AIOvertake only).
- Callees (from `offsets_AIBehaviorInitialization.csv` CALL rows): `ArithmeticComparison_a140` (L29),
  `sub_4BE760` (L36), `AnimationStateSetter` (L50, L57), `SLODWORD` (L57, pseudo), `memset` (L61),
  `StateFlagsLookup` (L83), `RandomVariationScaler` (L89), `AIDriverSorting` (L105).
- `this` = session object (same object as `AIOvertake`'s `this`, which passes `a3` through as first arg;
  `map_AIOvertake.md` L15-L19, L37-L38 maps 0x354/0x358/0x35C/0x360 on that object). `a2` = int input
  latched to 0x358. `a3` = char flag forcing a driver to be consumed (`a3` truthy at L107).
- Loop drivers `v9 = dword_7C54F0[v8]` are vehicles; all `v9+...` fields below are vehicle-relative.

## Inputs

Only offsets actually read (CSV access R rows, deduplicated).

| hex | dec | type | first line read | name |
|---|---|---|---|---|
| 0x34C | 844 | float | L89 | ? (`RandomVariationScaler` 4th arg) |
| 0x354 | 852 | float | L98 | ? accumulated time (session; `map_AIOvertake.md`) |
| 0x35C | 860 | _DWORD | L82 | ? TotalRaceLaps snapshot (session; `map_AIOvertake.md`) |
| 0x360 | 864 | _DWORD | L36 | ? SessionType snapshot (session; `map_AIOvertake.md`) |
| 0x32C8 | 13000 | _DWORD | L76 | vehicle flag (`v9`; AISteering part2 L368; AIPushLap L15) |
| 0x403C | 16444 | _DWORD | L81 | lapNumber (inspect; `map_AIAbility.md`) |
| 0x4044 | 16452 | float | L90 | ? ring-buffer selector (`map_AIAbility.md`) |
| 0x4064 | 16484 | _DWORD | L86 | ? state (`map_AIAbility.md`) |
| 0x4094 | 16532 | _DWORD | L91 | per-iteration step flag (`map_AIRacingLinePathFollowing.md`) |
| 0x409C | 16540 | float | L102 | bestLap (inspect; `map_Overtaking.md`) |

## Outputs

CSV access W rows. Also writes this[4*v8] at L89/L109 and `dword_5C329C`-driven loop state; those rows are
absent from the CSV (see Questions).

| hex | dec | type | first line written | name |
|---|---|---|---|---|
| 0x354 | 852 | float | L30 | ? accumulated time (session) |
| 0x358 | 856 | _DWORD | L31 | ? time threshold (session; `map_AIOvertake.md`) |
| 0x1A0 | 416 | _DWORD | L65 | indexed base of 104-dword array (`this + 4*v7 + 416`) |
| 0x403C | 16444 | _DWORD | L93 | lapNumber (increment) |
| 0x4098 | 16536 | float | L101 | ? vehicle field |
| 0x409C | 16540 | float | L103 | bestLap (inspect) |
| 0x40B8 | 16568 | float | L104 | ? vehicle field |
| 0x4064 | 16484 | _DWORD | L111 | ? state = 1 |

## Constants

Every numeric literal except 0/1; bit patterns written into float fields decoded with
`struct.unpack('<f', struct.pack('<I', N))`.

| value | lines | note |
|---|---|---|
| 7 | L40, L83 | `dword_7C56A4` (SessionType) compare |
| 2, 3 | L87 | `v12` state values checked |
| 104 | L67 | loop count for `this[4*v7]` / `this[4*v7+416]` |
| 416 | L65 | array base offset (`this + 4*v7++ + 416`) |
| 844, 852, 856, 860, 864 | L89, L82-L107, L36 | session/vehicle offsets (see tables) |
| 13000, 16444, 16452, 16484, 16532, 16536, 16540, 16568 | L76-L104 | vehicle offsets (see tables) |
| 0.0 | L44, L53, L70, L92, L100, L102 | zero returns/assignments/clamps |
| 1.0 | L42, L50 | `1.0 / flt_8ACF9C`; float arg to `AnimationStateSetter` |
| 1065353216 (0x3F800000) | L50 | float `1.0` passed as int bit pattern |
| 1110704128 (0x42340000) | L50, L57 | float `45.0` passed as int bit pattern |
| -1082130432 (0xBF800000) | L64, L109 | float `-1.0` written into float fields (`this + 4*v7`, `this + 4*v8`) |
| 0.0083333338 | L35 | `dword_7D01A0 * (1/120)` |

## Logic

Direct `this + N` reads use hex names (decimal N is present in the cited source lines); scaled
`this[idx]` / `this + 4*v` forms stay literal (no hex token).

```
ArithmeticComparison_a140(&dword_8AB6E4, 1); v3 = v26 = dword_5C329C          [L27,L28,L29]
*(float *)(this + 0x354) = dbl_8AFEA0                                         [L30]
*(this + 0x358) = a2                                                          [L31]
v5 = dword_7CE5EC; if (!v5) v5 = byte_5EA438                                  [L32,L33,L34]
v24 = dword_7D01A0 * 0.0083333338                                             [L35]
sub_4BE760(this, *(this + 0x360), (int)v5, v24)                               [L36]
switch (dword_7CEA5C)                                                         [L37]
  case 1: if (dword_7C56A4 != 7) goto LABEL_39                                [L39,L40,L41]
          v21 = 1.0 / flt_8ACF9C; v22 = v21                                   [L42,L43]
          if (v21 == 0.0) goto LABEL_5                                        [L44,L45]
          v6 = 1; goto LABEL_6                                                [L46,L47]
  case 2: LABEL_39: AnimationStateSetter(this, 1, 1, 1065353216, 1110704128); break  [L48,L49,L50,L51]
  default: v22 = 0.0                                                          [L53]
          LABEL_5: v6 = 0                                                     [L55]
          LABEL_6: AnimationStateSetter(this, 1, v6, SLODWORD(v22), 1110704128); break  [L57]
v7 = 0; memset(v27, 0, sizeof(v27))                                           [L60,L61]
do { *(float *)(this + 4*v7) = -1082130432;                                  [L64]
     *(this + 4*v7++ + 416) = 0 } while (v7 < 104)                            [L65,L67]
v8 = 0; v25 = flt_5EA3FC; v23 = 0.0                                           [L68,L69,L70]
if (v3 > 0)                                                                   [L71]
  do {    [L73]
    v9 = dword_7C54F0[v8]; v10 = *(v9 + 0x32C8)                               [L75,L76]
    if (v10 == -1) skip                                                       [L77,L78]
    if (v10) {                                                                [L79,L80]
      v11 = *(v9 + 0x403C)                                                    [L81]
      if (v11 < *(this + 0x35C)                                              [L82]
          && (dword_7C56A4 == 7 || v11 <= StateFlagsLookup(dword_7C54F0[v8])) [L83]
          && *(v9 + 0x4064) != 1) {                                           [L84]
        v12 = *(v9 + 0x4064)                                                  [L86]
        if (v12 != 3 && v12 != 2) {                                           [L87]
          this[4*v8] = RandomVariationScaler(this, v7, v9, *(this + 0x34C))   [L89]
          v13 = *(v9 + 0x4044)                                                [L90]
          if (*(v9 + 0x4094) <= 1) v13 = 0.0                                  [L91,L92]
          ++*(v9 + 0x403C)                                                    [L93]
          v14 = (v25 - v13) * (this[4*v8] / v25)                              [L94]
          v27[v8] = v14                                                       [L95]
          if (!(v16 | v17)) v23 = v14                                         [L96,L97]
          v18 = v14 + *(this + 0x354)                                         [L98]
          if (v18 < 0.0) v18 = 0.0                                            [L99,L100]
          *(v9 + 0x4098) = v18                                                [L101]
          if (*(v9 + 0x409C) <= 0.0 || *(v9 + 0x409C) > this[4*v8])           [L102]
            *(v9 + 0x409C) = this[4*v8]                                       [L103]
          *(v9 + 0x40B8) = *(this + 0x354) - flt_8ACF90 + v27[v8]             [L104]
          AIDriverSorting(v9)                                                 [L105]
          v7 = *(v9 + 0x403C)                                                 [L106]
          if (v7 >= *(this + 0x35C) || a3) {                                  [L107]
            this[4*v8] = -1082130432                                          [L109]
            if (*(v9 + 0x4064) != 3) *(v9 + 0x4064) = 1                       [L110,L111]
          }    [L112]
        }    [L113]
      }    [L114]
    }    [L115]
    v3 = v26; ++v8                                                            [L117,L118]
  } while (v8 < v26)                                                          [L120]
result = 0                                                                    [L122]
*(this + 0x354) = v23 + *(this + 0x354)                                       [L123]
if (v3 > 0) { v20 = this + 416;                                               [L124,L125,L126]
  do { ++result; v20 += 4; *(v20 - 4) = v23 - v27[result - 1]; } while (result < v3) }  [L129,L130,L131,L132,L133]
return result                                                                 [L135]
```

## Meaning (GUESS)

- GUESS Per-tick driver-behavior initialization: latches session inputs, sets an animation/state via
  `AnimationStateSetter`, resets a per-grid-slot float array `this[4*v7]` to -1.0 and a matching 104-dword
  array at +416 to 0, then walks `dword_7C54F0[v8]` drivers [L30-L67].
- GUESS For each qualifying driver it draws a randomized target (`RandomVariationScaler`), scales it by a
  ring-buffer selector and a budget `v25 = flt_5EA3FC`, and accumulates the budget deltas into
  `v27[]`, `v23` [L89-L97].
- GUESS It writes driver fields 0x4098/0x409C/0x40B8 and increments lapNumber 0x403C, then calls
  `AIDriverSorting`, apparently ordering the grid by the computed times [L93-L105].
- GUESS A driver is "consumed" (array slot set to -1.0, state set to 1) when its lapNumber reaches the
  session total 0x35C or when the `a3` force flag is set [L107-L111].
- GUESS The tail writes per-slot offsets `v23 - v27[i]` into `this[4*i + 416]`, i.e. a sorted delta array,
  and adds `v23` to the session accumulated time 0x354 [L123-L133].
- GUESS `dword_7D01A0` (the AIDifficultyScalar global) scales time via `*1/120` in the `sub_4BE760` call,
  i.e. difficulty affects behavior timing [L35].

## Questions

- `AIOvertake` calls `AIBehaviorInitialization(a3, v8)` (2 args) against a 3-arg `__thiscall`; which
  variable is `a3` (force flag) and is it initialized? `a3` is used only at L107.
- The extractor has no rows for the writes `*(float *)(this + 4*v7) = -1082130432` (L64),
  `*(float *)(this + 4*v8) = -1082130432` (L109) and `*(float *)(this + 4*v8) = RandomVariationScaler(...)`
  (L89); `unmatched_AIBehaviorInitialization.txt` lists L64/L94/L109/L126. Effective offsets are
  `this + 4*index` with no fixed byte offset.
- `v16 | v17` at L96 is an x87 flag artifact (`c0`/`c3`); the real condition is the preceding compare
  inside `RandomVariationScaler`/`v14` evaluation - not reconstructible from this decompile.
- What are the 104-entry arrays at `this` and `this+416` (per-slot budgets / sorted deltas?), and what is
  `flt_5EA3FC` / `flt_8ACF90`? Are they per-session constants?
- `ArithmeticComparison_a140(&dword_8AB6E4, 1)` and `sub_4BE760` remain semantically open.
- Is `dword_5C329C` (grid size, latched into `v3`/`v26`) the same as `dword_7C54F0` array length? The loop
  re-reads `v3 = v26` after each iteration [L117].
