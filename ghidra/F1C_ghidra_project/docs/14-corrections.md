# Corrections to Prior Community Model

## Corrections to Prior Community Model

Binary analysis confirms some community beliefs were directionally correct but mechanistically wrong.
Sources for each correction are the decompiled functions listed below.

### RainAbility â€” NOT additive to RaceAbility

**Community model (REF-04-ai-plr-rcd.md, REF-09):**
> "RainAbility is added to RaceAbility to compute wet-weather pace."

**Actual mechanism (`FUN_00424080` @ `0x00424080`):**
```c
param_1[0x1132] = RainAbility * 0.01 * global_rain_scale   // stored separately
param_1[0x1160] = 1.0 - current_wetness * param_1[0x1132]  // multiplicative wet speed factor
```

RainAbility is a **separate multiplicative wet speed penalty**, not a sum with RaceAbility.
A driver with RA=3, RainAbility=8 at full wet is NOT equivalent to RA=11 dry.
They have RA=3 base speed PLUS a `1.0 - (8 Ã— 0.01 Ã— scale)` speed multiplier applied
independently. The two effects compound multiplicatively, not additively.

The community got the direction right (higher = worse in wet) but the math wrong.

---

### RaceAbility ceiling â€” 6.2 is NOT the internal reference max

**Community model:**
> "RaceAbility range 0â€“6.2 (per file comment). Above 6.2 AI uses less than full throttle."

**Actual mechanism (`FUN_00424080` @ `0x00424080`, `_DAT_0059e85c` confirmed from `.rdata`):**
```c
raw_delta = (22.0 - RaceAbility) / 22.0   // internal slowness fraction
```

Internal reference maximum is **22.0**. The formula is linear across the entire vanilla RA range
(1.8â€“15.98). 6.2 is not a mathematical boundary â€” it is where the community empirically
observed 100% throttle usage, which is a downstream behavior threshold, not the formula input.
The 22.0 ceiling is the true reference; values above 22.0 produce zero or negative raw_delta
(meaning RA=22 is theoretically the slowest possible driver the formula was designed for).

---

### AI Difficulty Slider â€” NOT linear

**Community model (implicit):**
> Difficulty slider maps linearly to AI pace. 80% slider = 80% of full AI speed.

**Actual mechanism (`FUN_00424080` @ `0x00424080`):**
```c
if (slider < 100):
    param_1[0x1131] = (slider/100)Â² Ã— raw_delta
```

The per-car slowness fraction is scaled by `(slider/100)Â²` â€” **quadratic**.

| Slider | Community expectation | Actual scaling |
|--------|----------------------|----------------|
| 100% | 1.00Ã— | 1.00Ã— (correct â€” slider â‰¥ 100 skips this branch) |
| 90% | 0.90Ã— | **0.81Ã—** |
| 80% | 0.80Ã— | **0.64Ã—** |
| 70% | 0.70Ã— | **0.49Ã—** |

At 70% slider, AI difficulty is compressed far more than expected. This also means
chaos/randomizer RA deltas have ~half the perceived impact at 70% vs 100%.

Note: the **global** speed multiplier (`aiDB[0x46]`) is linear (0.5â€“1.3Ã—). Only the
**per-car** RA scaling is quadratic. They are independent stages in the pipeline.

---

### StartsDry / StartsWet â€” NOT position deltas

**Community model (implicit, multiple modding guides):**
> "StartsDry/StartsWet = positions gained/lost on race start."

**Actual mechanism (`FUN_00424080` @ `0x00424080`):**
```c
raw_start = current_wetness * StartsWet + (1 - current_wetness) * StartsDry;
raw_start += (rand() % 200) * 0.01;       // Â±1.0 random jitter
raw_start  = clamp(raw_start, -4.0, 4.0);
param_1[0x112e] = raw_start * 0.1 + 1.0; // maps [-4, +4] â†’ [0.60, 1.40]
```

`param_1[0x112e]` is a **tire start temperature multiplier**. 1.0 = nominal temperature;
0.60 = cold tires; 1.40 = very warm tires. Higher value = better grip at race start.

The field is NOT a position delta. Any observed correlation between the values and start
performance is indirect â€” warm tires produce better initial grip â†’ better launch â†’ net
positions gained. The community got the direction correct but the mechanism wrong.

The Â±4.0 clamp is applied by the engine; mods's `STAT_CLAMP` bounds match it.

---


