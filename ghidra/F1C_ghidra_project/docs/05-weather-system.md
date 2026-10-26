# Weather System - Internal Mechanics

## Weather System â€” Internal Mechanics

Source: `FUN_004fcc30` @ `0x004fcc30` (weather loader), `FUN_004fe350` @ `0x004fe350`

### Weather mode variable
`DAT_007cf080` â€” current weather mode (stored per season: `&DAT_007cf080 + season * 9`)

| `DAT_007cf080` | Mode | Behavior |
|---|---|---|
| 0 | Selected Season | reads `weather.txt` file |
| 1 | From GDB | reads `Weather` section from track GDB |
| 3 | Raining | hardcoded OnPath/OffPath wetness = **0.65** |
| 4 | Overcast | hardcoded wetness = **0.82** |
| 5 | Monsoon | hardcoded wetness = **0.94** |
| other | Dry | hardcoded wetness = **0.30** |

### Default temperature
AmbientTemp default = **20Â°C**. TrackTemp default = AmbientTemp + **2Â°C**.

### OffPathWetness constraint
If `OffPathWetness < OnPathWetness` at load, game forces `OffPathWetness = OnPathWetness`.
(Grooved racing line can't be wetter than the marbles â€” enforced at parse time.)

### Weather variance seed
The 256-slot ring buffer (`DAT_008aae70`) that also drives QA noise is consumed once
per weather session init to seed variance: `result * 0.05`. Weather conditions vary
slightly between sessions even with identical config for the same reason QA times vary.

### Track wetness data structure (from `FUN_004fe350`)
Read from weather file into per-session state:
```
param_1 + 0x20  = (init 0)
param_1 + 0x28  = OnPathWetness
param_1 + 0x2c  = OffPathWetness
param_1 + 0x30  = AmbientTemp
param_1 + 0x34  = TrackTemp
param_1 + 0x38  = linked list of {time, AmbientTemp, Conditions} nodes (per-minute)
```

---


## weather.cpp - Weather System (3 new functions)
### weather.cpp â€” Weather System (3 new functions)

#### FUN_004fcaa0 â€” Weather Initializer

Called by Game::Init (FUN_0042d6b0). If `DAT_007cf080 == 0` (Selected Season
mode), loads `weather.txt` from DAT_005ec438 directory via FUN_004fe820.

**Weather struct defaults (param_1):**
| Offset | Value | Meaning |
|--------|-------|---------|
| +0x0c | 1.0 | unknown flag |
| +0x10 | -1 (0xFFFFFFFF) | unknown |
| +0x18 | -1.0 | unknown |
| +0xa4 | -1.0 | unknown |
| +0xb4â€“0xbc | track position (Ã— _DAT_0059e460) | sun/light position |
| +0xc0â€“0xc8 | 0.75 | fog params |
| +0xccâ€“0xd4 | 0.5 | fog params |
| +0xe4 | 175.0 | unknown |
| +0xe8 | 700.0 | unknown |
| +0xec | computed | derived from sun position |
| +0xf0 | 0 | unknown |
| +0xf4 | 150.0 | unknown |
| +0xf8 | 0.01 | unknown |

Calls FUN_004fefc0 (fog init with 0.125), FUN_004fba10 (weather state init).

#### FUN_004fe820 â€” Weather File Writer

Writes `weather.txt` with 8 session entries. Each session writes:
- `Conditions` (interpolated from linked list)
- `OnPathWetness` (Ã— 100.0 for percentage)
- `OffPathWetness` (Ã— 100.0)
- `AmbientTemp`
- `TrackTemp`
- Per-minute changes (linked list at param_1+0x38, iterated while time diff â‰¤ _DAT_005acb08)

**Constants:**
- `_DAT_0059e6f8` = 100.0 (percentage conversion)
- `_DAT_0059e5fc` = time step per weather change
- `_DAT_005acb08` = minute threshold for weather changes

#### FUN_004fe7c0 â€” Weather Section Reader

Opens file, finds `Weather` section, calls FUN_004fe350 (already documented
weather data reader). Simple wrapper.

## FUN_004fe0d0 — Weather Name → Wetness Multiplier

Source: weather/gdb module. Maps weather condition name strings to float wetness multipliers (0.0 = dry, 1.0 = fully wet). Used to determine track grip level from weather type.

**Mapping:**
| Name | Wetness | Constant |
|------|---------|----------|
| (empty/DAT_005d6fa4) | 0.0 | _DAT_005ad324 |
| (unknown/DAT_005d6f9c) | ~0.001 | _DAT_0059e8b4 |
| Clear | 0.0 | _DAT_0059e4e8 |
| Overcast | ~0.007 | _DAT_0059e8f8 |
| Drizzle | ~0.34 | _DAT_005ad320 |
| (unknown/DAT_005d6f84) | ~0.46 | _DAT_0059e908 |
| Monsoon | ~0.61 | _DAT_005ad31c |

**Fallback:** If name doesn't match any known weather type, parses as float (FUN_0058850f), multiplies by `_DAT_0059e444`, clamps to [0, 1].

**Calls:** FUN_00588410 (string compare), FUN_0058850f (parse float)

**Moddability:** Yes — **moddable field.** Confirms `.gdb` weather severity values are clamped [0, 1]. mods could write custom wetness values for weather names.

---

## FUN_004fe1e0 — Weather Severity → Grip Multiplier

Source: weather/gdb module. Maps weather severity name strings to float grip multipliers (0.0 = no grip, 1.0 = full grip). Used to model rain severity on track grip.

**Mapping:**
| Name | Grip | Constant |
|------|------|----------|
| (normal/PTR_DAT_005c6e98) | 0.0 | DAT_0059e440 |
| (light rain/DAT_005d6fb4) | ~0.002 | _DAT_0059e7f8 |
| (moderate/PTR_DAT_005c7234) | ~0.01 | _DAT_0059e450 |
| Soaked | ~0.05 | _DAT_0059e7fc |
| Monsoon | 1.0 | _DAT_0059e43c |

**Fallback:** If name doesn't match, parses as float, multiplies by `_DAT_0059e444`, clamps to [0, 1].

**Calls:** FUN_00588410 (string compare), FUN_0058850f (parse float)

**Moddability:** Yes — **moddable field.** Confirms grip multiplier range [0, 1]. mods could modulate grip via custom weather severity names.

---

## FUN_00470da0 — Weather Mode UI Constructor

Source: options/UI module. Initializes the weather selection UI with 5 weather mode options.

**Options:**
1. Selected Season (reads weather from season data)
2. Monsoon (full wet)
3. Raining (wet)
4. Overcast (damp)
5. Changing Weather (dynamic weather)

**Key logic:**
- Sets vtable to PTR_FUN_005a09c0
- Sets weather ptr: `&DAT_007cf080 + DAT_007d0410 * 9` (per-season weather offset)
- Sets param_1[0xc9] = 5 (5 options)
- param_1[0xca] = 0 (default index)
- param_1[0xcb] = 1 (active)
- param_1[0xcc] = 1
- param_1[0xcd] = 0x19b (scroll offset)
- Calls FUN_00486f30 for each string

**Calls:** FUN_00466d60 (UI init), FUN_00486f30 (add option)

**Moddability:** No — weather mode UI only.

---
## FUN_004D37B0 — TrackTemperatureDisplay

Source: weather.cpp. Updates on-screen track/ambient temperature display when temperature changes exceed 3.0°C threshold.

**Key logic:**
- Calls `sub_54C150(&v5, 2048)` twice (parser read two key-values)
- Indexes vehicle struct via `&unk_5EC6D8 + 18624 * v5` (0x48C0 stride = SeasonScoringDB/weather struct)
- If `v6 != -11`: calls `sub_424CD0(5, 0)` (display priority 5), `sub_4A5F20(v2 + 13004)` (setup temp display)
  - If player vehicle (`v2 == dword_7C54E8`): calls `pfnAPC(0)` + `sub_40D450` (trigger A/C update)
- If `v6 == -11`: calls `sub_424CD0(4, 0)`, `sub_4A5EA0(v2 + 13004)` (alt setup)
  - If player vehicle: `pfnAPC(1)` (heater update)
- If `|dbl_8AFEA0 - flt_8AC4B0| <= 3.0`: skip update (debounce threshold)
- Otherwise: increment counter `dword_83EE60` (max 1023), add 432 to offset `dword_8AAE64`
  - Calls `sub_4B33B0(3, 7, 0, v2[4645], temp, 0)` (display temperature, format 3/7)
  - Updates `flt_8AC4B0 = dbl_8AFEA0` (last displayed temp)

**Globals:**
- `unk_5EC6D8` — weather/season data array (base)
- `dword_7C54E8` — PlayerVehiclePtr
- `dbl_8AFEA0` — current ambient/track temperature (double)
- `flt_8AC4B0` — last displayed temperature (float)
- `dword_83EE60` — display update counter (caps at 1023)
- `dword_8AAE64` — display offset accumulator

**Calls:** sub_54C150 (parser key-value), sub_424CD0 (display priority set), sub_4A5F20 (setup weather display), sub_4A5EA0 (setup alt weather display), sub_40D450 (A/C control), sub_4B33B0 (display formatted number), sub_54FAE0 (timer/mutex unlock), pfnAPC (async procedure call)

**Moddability:** `hardcoded` — 3.0°C threshold is literal, 1023 display cap

<!-- target: docs/20-math-utilities.md -->

