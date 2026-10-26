# map_RaceStartCountdownStateUpdate — declared `sub_4EF930`

## Identity

- Address: `0x4EF930`; file `functions/RaceStartCountdownStateUpdate_004ef930.c`; 48 lines.
- Signature: `void __thiscall sub_4EF930(int this, int a2)`.
- Callers (grep `functions/` for `RaceStartCountdownStateUpdate(`): `AIMainUpdate` (`0x424E70`) L101 (0);
  `PhysicsGearShiftLogicWithThresholds` (`0x426330`) L12 (-1), L17 (0), L29 (`v2 + 1`);
  `PitStopReadyCheck` (`0x4A6200`) L23 (0); `SteeringAngleController` (`0x425670`) L68 (`v10 - 1`).
- Callees (from `offsets_RaceStartCountdownStateUpdate.csv` CALL rows): `SoundEffectTrigger_89a0`
  (`0x4F89A0`), `PositionUpdateWithTelemetryRecording` (`0x4EF4F0`), `SoundEffectTrigger` (`0x4F88A0`).
- `this` = F1CVehicle-like session object; all accesses are direct `this + N` byte offsets.

## Inputs

| hex | dec | type | first line read | name |
|---|---|---|---|---|
| 0x39EE | 14830 | _BYTE | L6 (`v3 = *(_BYTE *)(this + 14830)`) | ? gate byte (non-zero skips the whole update) |
| 0x3A04 | 14852 | float | L17 (`*(float *)(this + 14852) <= 0.0`) | ? countdown timer (also copied as DWORD at L23/L35) |
| 0x39F0 | 14832 | _DWORD | L20 (`a2 <= *(_DWORD *)(this + 14832)`) | ? previously announced step |
| 0x3A00 | 14848 | _DWORD | L23 (`= *(_DWORD *)(this + 14848)`) | ? reload value A written into 0x3A04 |
| 0x3578 | 13688 | float | L25 (`*(float *)(this + 13688) > 0.0`) | ? start condition 1 (must be > 0) |
| 0x3978 | 14712 | float | L26 (`*(float *)(this + 14712) > 0.0`) | ? start condition 2 (must be > 0; same byte offset as `this[3678]` pointer in RandomWeightedTierSelection) |
| 0x3998 | 14744 | float | L27 (`*(float *)(this + 14744) * 0.5 < *(float *)(this + 14740)`) | ? scaled lower side of the start test |
| 0x3994 | 14740 | float | L27 (same test) | ? upper side of the start test |
| 0x39FC | 14844 | _DWORD | L35 (`= *(_DWORD *)(this + 14844)`) | ? reload value B written into 0x3A04 |

Global: none (callees may read globals internally).

## Outputs

| hex | dec | type | first line written | name |
|---|---|---|---|---|
| 0x39EC | 14828 | _BYTE | L7 (`*(_BYTE *)(this + 14828) = 0`) | ? start latch / flag (set to 1 at L40) |
| 0x3A08 | 14856 | _DWORD | L12 (`= 0`) | ? step state (0 reset; 1 latch; else a2) |
| 0x3A04 | 14852 | _DWORD | L13 (`= 0`) | ? countdown timer (reloaded from 0x3A00 / 0x39FC) |
| 0x39F0 | 14832 | _DWORD | L14 (`= 0`) | ? previously announced step (cleared on reset/update) |

## Constants

| value | lines | note |
|---|---|---|
| 14830, 14828, 14856, 14852, 14832, 14848, 14844 | L6-L45 | direct `this` byte offsets (state block) |
| 13688, 14712, 14744, 14740 | L25-L27 | float field byte offsets |
| 0.5 | L27 | scale on the 0x3998 term |
| 0.0 | L17, L25, L26 | float compares (timer <= 0; two start gates > 0) |

## Logic

```
v3 = *(_BYTE *)(this + 0x39EE)                                  [L6]
*(_BYTE *)(this + 0x39EC) = 0                                   [L7]
if (!v3) {                                                      [L8]
    if (!a2) {                                                  [L10]
        *(_DWORD *)(this + 0x3A08) = 0                          [L12]
        *(_DWORD *)(this + 0x3A04) = 0                          [L13]
        *(_DWORD *)(this + 0x39F0) = 0                          [L14]
        return                                                  [L15]
    }
    if (*(float *)(this + 0x3A04) <= 0.0) {                     [L17]
        v4 = this + 8                                           [L19]
        if (a2 <= *(_DWORD *)(this + 0x39F0)) {                 [L20]
            SoundEffectTrigger_89a0(v4)                         [L22]
            *(_DWORD *)(this + 0x3A04) = *(_DWORD *)(this + 0x3A00)   [L23]
            if (a2 >= 1                                         [L24]
                && *(float *)(this + 0x3578) > 0.0              [L25]
                && *(float *)(this + 0x3978) > 0.0              [L26]
                && *(float *)(this + 0x3998) * 0.5 < *(float *)(this + 0x3994))  [L27]
                PositionUpdateWithTelemetryRecording(this)      [L29]
        } else {
            SoundEffectTrigger(v4)                              [L34]
            *(_DWORD *)(this + 0x3A04) = *(_DWORD *)(this + 0x39FC)   [L35]
            if (a2 == 1 && !*(_DWORD *)(this + 0x39F0)) {       [L36]
                *(_DWORD *)(this + 0x3A08) = 1                  [L38]
                *(_DWORD *)(this + 0x39F0) = 0                  [L39]
                *(_BYTE *)(this + 0x39EC) = 1                   [L40]
                return                                          [L41]
            }
        }
        *(_DWORD *)(this + 0x3A08) = a2                         [L44]
        *(_DWORD *)(this + 0x39F0) = 0                          [L45]
    }
}
```

## Meaning (GUESS)

- GUESS Race-start countdown / start-light state machine: byte 0x39EE gates all work (non-zero -> only
  0x39EC is cleared), and 0x39EC is cleared on every entry [L6,L7,L8].
- GUESS `a2` is the requested countdown step: 0 resets state 0x3A08, timer 0x3A04 and step 0x39F0 and
  returns without sound; positive steps compare against the previous step 0x39F0 [L10-L20,L44,L45].
- GUESS When timer 0x3A04 is <= 0 and `a2 <= 0x39F0` (step not advanced) it plays `SoundEffectTrigger_89a0`
  on the audio object at `this + 8`, reloads the timer from 0x3A00, and when the start conditions
  (0x3578 > 0, 0x3978 > 0, `0x3998 * 0.5 < 0x3994`) hold, snapshots position/telemetry via
  `PositionUpdateWithTelemetryRecording` [L17-L31].
- GUESS When the step advanced (`a2 > 0x39F0`) it plays the other sound `SoundEffectTrigger`, reloads the
  timer from 0x39FC, and on the first step (a2 == 1 with previous 0x39F0 == 0) latches 0x3A08 = 1 and
  0x39EC = 1 and returns — the "race start" edge [L32-L42].
- GUESS Otherwise (timer still positive) it only records `a2` into 0x3A08 and zeroes 0x39F0 [L44,L45],
  so repeated calls with the same step do not re-fire.
- GUESS Callers drive `a2` around zero/start: -1, 0, `v2 + 1`, `v10 - 1`; the exact light sequence is not
  in this function [callers].
- GUESS 0x3998 * 0.5 < 0x3994 is a speed/countdown threshold pair; 0x3578/0x3978 are prerequisites
  (possibly engine/session ready flags) [L24-L27].

## Questions

- What is the object at `this + 8` passed to `SoundEffectTrigger_89a0` (vehicle audio state)? The
  extractor listed only `v4 = this + 8` (unmatched file) — no CSV row, treated as an unparsed argument.
- 0x3978 is read as a positive float here but `RandomWeightedTierSelection` treats `this[3678]` (same byte
  offset 0x3978) as a pointer to a tire-compound table (`*(this[3678] + 16)` loop count). Union, or two
  different object layouts?
- What are 0x3A00 / 0x39FC (timer reload values) and their unit (ms / ticks)?
- What are the semantics of gate byte 0x39EE and latch 0x39EC (start enabled / start fired)?
- Do `SoundEffectTrigger_89a0` and `SoundEffectTrigger` differ by start-light count vs final start sound?
- unmatched_ list has one entry: `L19: v4 = this + 8;` (argument address, not an offset field).
