## RandomNoiseTableInitialization_004b3bd0 — RandomNoiseTableInit

**Summary:** Initializes 514-float noise table: index 0 set to 0.0, indices 1-256 filled with uniform random values [0,1), indices 257-512 filled with uniform random values [-1,1), index 513 seeded with RDTSC timestamp. Called from GameFileLoader during startup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameFileLoader (0042d260)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Noise table entry [0] — set to 0.0 |

**Written-by note (persistence):**
- this 0x0: written once — initialized to 0.0 at start of function

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e0d4 | __imp_GetTickCount | R | Seed source for RNG initialization |
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e6e0 | flt_59E6E0 | R | RandomScalingFactor [DERIVED] |
| 005accf0 | flt_5ACCF0 | R | RandomRangeScale [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0055687b | RDTSCTimestampRead | Read CPU timestamp counter and write to noise table slot 513 |
| 005884e0 | TLSFieldSetter | Seed TLS-based PRNG with GetTickCount value |
| 005884ed | RandLCGRandomNumberGenerator | Generate next LCG random float for noise table fill |

**Guard conditions:** No guard conditions — always executes fully (linear, loops are fixed 256 iterations each).
