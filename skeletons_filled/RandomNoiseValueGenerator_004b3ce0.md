## RandomNoiseValueGenerator_004b3ce0 — Gaussian noise value generator

**Summary:** Generates noise value approximating normal distribution by computing popcount of hash-based PRNG result (binomial approximation), combining with noise table float and scaling by 0.35355338 (1/sqrt(8)). Part of random/audio/noise system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_43C250 (0043c250), EngineWearFailureSimulation (004ee150), sub_4FD8B0 (004fd8b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Noise table index (auto-incremented, used to read float at offset this[*this + 257]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 005accf8 | flt_5ACCF8 | R | FinalScaleFactor [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b3c60 | DeterministicHashPseudoRandomGenerator | Generate hash-based pseudo-random value for popcount and noise table index |

**Guard conditions:** No guard conditions — always generates output.
