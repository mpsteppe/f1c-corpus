## sub_4FCAA0_004fcaa0 — Weather Parameter Block Initializer

**Summary:** Initializes weather parameters: reads or writes weather.txt file, sets up weather mode constants (0.75/0.5 scaling factors, 175/675 range limits, 150.0 default, 0.01 threshold), computes derived values from orientation angles and field lookups, and delegates to sub_4FBA10 for cloud/skybox scene graph setup. Called from Game_Init.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Init (0042d6b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | RW | 1065353216 → 1.0f | weather state reset value (set to 1.0f) |
| this | 0x10 | RW | 18446744073709551615 | weather param slot (set to -1 as invalid sentinel) |
| this | 0x18 | RW | 18446744072627421184 → -1.0f | weather param float (set to -1.0f sentinel) |
| this | 0xA4 | RW | 18446744072627421184 → -1.0f | weather effect param float (set to -1.0f sentinel) |
| this | 0xA8 | R | — | weather timing multiplier (read from ShortFieldAccessor, used in formula: (0.01 - E0) * A8) |
| this | 0xB4 | RW | — | scaled color/weather component R (packed short * 0.0039215689 ≈ /255) |
| this | 0xB8 | RW | — | scaled color/weather component G (packed short * 0.0039215689) |
| this | 0xBC | RW | — | scaled color/weather component B (packed short * 0.0039215689) |
| this | 0xC0 | RW | 1061158912 → 0.75f | weather blend factor (interpolation constant, 0.75) |
| this | 0xC4 | RW | 1061158912 → 0.75f | weather blend factor (interpolation constant, 0.75) |
| this | 0xC8 | RW | 1061158912 → 0.75f | weather blend factor (interpolation constant, 0.75) |
| this | 0xCC | RW | 1056964608 → 0.5f | weather half-factor (0.5) |
| this | 0xD0 | RW | 1056964608 → 0.5f | weather half-factor (0.5) |
| this | 0xD4 | RW | 1056964608 → 0.5f | weather half-factor (0.5) |
| this | 0xE0 | R | — | weather base value (read from FieldGetter_3a60, used in: 0.01 - value) |
| this | 0xE4 | RW | 1127153664 → 175.0f | weather range max (175.0f) |
| this | 0xE8 | RW | 1143521280 → 675.0f | weather range upper max (675.0f) |
| this | 0xEC | RW | — | computed weather derived value (A8 * (0.01 - E0) + E0) |
| this | 0xF0 | RW | 0 | weather counter/state (initialized to 0) |
| this | 0xF4 | RW | 1125515264 → 150.0f | weather default float (150.0f) |
| this | 0xF8 | RW | 1008981770 → 0.01f | weather epsilon/threshold (0.01f) |
| this | 0x1C4 | RW | 0 | cloud/skybox state byte (null terminator, set after sub_4FBA10) |

**Written-by note (persistence):**
- this 0xC: set once at game init — external poke does NOT survive re-init
- this 0x10: set once at game init — external poke does NOT survive re-init
- this 0x18: set once at game init — external poke does NOT survive re-init
- this 0xA4: set once at game init — external poke does NOT survive re-init
- this 0xB4: set once at game init — external poke does NOT survive re-init
- this 0xB8: set once at game init — external poke does NOT survive re-init
- this 0xBC: set once at game init — external poke does NOT survive re-init
- this 0xC0: set once at game init — external poke does NOT survive re-init
- this 0xC4: set once at game init — external poke does NOT survive re-init
- this 0xC8: set once at game init — external poke does NOT survive re-init
- this 0xCC: set once at game init — external poke does NOT survive re-init
- this 0xD0: set once at game init — external poke does NOT survive re-init
- this 0xD4: set once at game init — external poke does NOT survive re-init
- this 0xE4: set once at game init — external poke does NOT survive re-init
- this 0xE8: set once at game init — external poke does NOT survive re-init
- this 0xEC: set once at game init — external poke does NOT survive re-init
- this 0xF0: set once at game init — external poke does NOT survive re-init
- this 0xF4: set once at game init — external poke does NOT survive re-init
- this 0xF8: set once at game init — external poke does NOT survive re-init
- this 0x1C4: set once at game init — external poke does NOT survive re-init

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e444 | flt_59E444 | R | FrameDelta [DERIVED] (also: ` — float 0.016667 (1/60, frame delta) |
| 0059e460 | flt_59E460 | R | AlphaScaleFactor [DERIVED] |
| 005d6f68 | aSweatherTxt | R | StrSWeatherTxt [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec438 | dword_5EC438 | R | WeatherDir [DERIVED] (also: ` — SeasonDir/LoadPath, docs/12) |
| 007cf080 | dword_7CF080 | R | WeatherMode (0-5) [DERIVED] |
| 008afe88 | dword_8AFE88 | R | CollisionGeometryHandle [DERIVED] (also: ` — global collision geometry handle) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004fba10 | sub_4FBA10 | initializes cloud/skybox scene graph (called with this+264 as sub-struct) |
| 004fd840 | DualLinkedListDestruction | destroys/clears linked list before re-initialization |
| 004fd8b0 | sub_4FD8B0 | sets weather time range (0.0 to 432000.0 = 5 days in seconds) for weather mode 0 |
| 004fe820 | WeatherConditionsFileWriter | writes weather conditions to weather.txt file |
| 004fefc0 | ClampedReciprocalWithGuard | computes clamped reciprocal of 0.25 with guard |
| 004ff040 | ValueClampRange | clamps a value to range [0.0, 0.5] |
| 005439f0 | ShortFieldAccessor | reads packed short fields (RGB components) from weather data |
| 00543a30 | GetOrientationAngleValues | reads orientation angle values from weather/scene data |
| 00543a60 | FieldGetter_3a60 | reads a float field value from weather/scene data |
| 0058815f | StringFormatWithBufferOverflowCheck | formats "%sweather.txt" path string |

**Guard conditions:** WeatherMode (dword_7CF080) check: if == 0, writes weather.txt file and sets time range via sub_4FD8B0; otherwise skips file I/O and proceeds directly to parameter initialization. All other initialization is unconditional. Cloud/skybox sub-struct is always initialized via sub_4FBA10 at end.