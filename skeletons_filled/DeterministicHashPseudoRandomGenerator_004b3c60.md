## DeterministicHashPseudoRandomGenerator_004b3c60 — Deterministic hash-based PRNG

**Summary:** Generates pseudo-random DWORD by combining RDTSC timestamp, GetTickCount, LCG random, and internal state counters (0x0, 0x804). Reads from a float noise table indexed by auto-incrementing counter. Part of random number generation system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** RandomNoiseValueGenerator (004b3ce0), AIDriverCountSetup (004bfd90), sub_4CB120 (004cb120), TelemetryDataDump (004d4a80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Noise table index counter (auto-incrementing, wraps as byte) |
| this | 0x804 | RW | — | Accumulator state (multiplicative LCG state, updated per call) |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist
- this 0x804: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e0d4 | __imp_GetTickCount | R | Windows GetTickCount import for system timer seed |
| 005accf4 | flt_5ACCF4 | R | RandomSeedMult [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0055687b | RDTSCTimestampRead | Read x86 RDTSC timestamp counter for high-res entropy |
| 00587bdc | CRTFtol | Truncate float to integer for GetTickCount difference |
| 005884ed | RandLCGRandomNumberGenerator | LCG random number generator for additional entropy |

**Guard conditions:** No guard conditions — always executes full entropy gathering.
