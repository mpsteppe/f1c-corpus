## sub_4AE9F0_004ae9f0 — AIDifficultyParameterInit

**Summary:** Initializes AI/track-environment clamped parameters based on a difficulty level switch (1-4) read from this+0x1B10, with per-difficulty value sets and an additional AI-difficulty-dependent dispatch via dword_5EC4AC.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_472630 (00472630), TrackEnvironmentSelect (004ade20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x11E8 | RW | 1 | clamped parameter value (track env group 1) |
| this | 0x11F0 | R | — | min bound for parameter at 0x11E8 |
| this | 0x11F4 | R | — | max bound for parameter at 0x11E8 |
| this | 0x1254 | RW | 1 | clamped parameter value (track env group 2) |
| this | 0x125C | R | — | min bound for parameter at 0x1254 |
| this | 0x1260 | R | — | max bound for parameter at 0x1254 |
| this | 0x135C | RW | 2 | clamped parameter value (track env group 3) |
| this | 0x1364 | R | — | min bound for parameter at 0x135C |
| this | 0x1368 | R | — | max bound for parameter at 0x135C |
| this | 0x1380 | RW | 1 | clamped parameter value (track env group 4) |
| this | 0x1388 | R | — | min bound for parameter at 0x1380 |
| this | 0x138C | R | — | max bound for parameter at 0x1380 |
| this | 0x13A4 | RW | 1053609165 → 0.4f | clamped float parameter value (track env group 5, float) |
| this | 0x13AC | R | — | min bound for float parameter at 0x13A4 |
| this | 0x13B0 | R | — | max bound for float parameter at 0x13A4 |
| this | 0x13C8 | RW | 2 | clamped parameter value (track env group 6) |
| this | 0x13D0 | R | — | min bound for parameter at 0x13C8 |
| this | 0x13D4 | R | — | max bound for parameter at 0x13C8 |
| this | 0x13EC | RW | 0 | clamped parameter value (track env group 7) |
| this | 0x13F4 | R | — | min bound for parameter at 0x13EC |
| this | 0x13F8 | R | — | max bound for parameter at 0x13EC |
| this | 0x1410 | RW | 3 | clamped parameter value (track env group 8) |
| this | 0x1418 | R | — | min bound for parameter at 0x1410 |
| this | 0x141C | R | — | max bound for parameter at 0x1410 |
| this | 0x16F8 | RW | 2 | clamped parameter value (track env group 9) |
| this | 0x1700 | R | — | min bound for parameter at 0x16F8 |
| this | 0x1704 | R | — | max bound for parameter at 0x16F8 |
| this | 0x1740 | RW | 0 | clamped parameter value (track env group 10) |
| this | 0x1748 | R | — | min bound for parameter at 0x1740 |
| this | 0x174C | R | — | max bound for parameter at 0x1740 |
| this | 0x17AC | RW | 1 | clamped parameter value (track env group 11) |
| this | 0x17B4 | R | — | min bound for parameter at 0x17AC |
| this | 0x17B8 | R | — | max bound for parameter at 0x17AC |
| this | 0x17D0 | RW | 1 | clamped parameter value (track env group 12) |
| this | 0x17D8 | R | — | min bound for parameter at 0x17D0 |
| this | 0x17DC | R | — | max bound for parameter at 0x17D0 |
| this | 0x17F4 | RW | 15 | clamped parameter value (track env group 13) |
| this | 0x17FC | R | — | min bound for parameter at 0x17F4 |
| this | 0x1800 | R | — | max bound for parameter at 0x17F4 |
| this | 0x1818 | R | — | unknown read-only parameter, used as bound source |
| this | 0x1878 | RW | 1 | clamped parameter value (track env group 14) |
| this | 0x1880 | R | — | min bound for parameter at 0x1878 |
| this | 0x1884 | R | — | max bound for parameter at 0x1878 |
| this | 0x189C | RW | 1 | clamped parameter value (track env group 15) |
| this | 0x18A4 | R | — | min bound for parameter at 0x189C |
| this | 0x18A8 | R | — | max bound for parameter at 0x189C |
| this | 0x18C0 | RW | 1 | clamped parameter value (track env group 16) |
| this | 0x18C8 | R | — | min bound for parameter at 0x18C0 |
| this | 0x18CC | R | — | max bound for parameter at 0x18C0 |
| this | 0x18E4 | RW | 1 | clamped parameter value (track env group 17) |
| this | 0x18EC | R | — | min bound for parameter at 0x18E4 |
| this | 0x18F0 | R | — | max bound for parameter at 0x18E4 |
| this | 0x1908 | RW | 1 | clamped parameter value (track env group 18) |
| this | 0x1910 | R | — | min bound for parameter at 0x1908 |
| this | 0x1914 | R | — | max bound for parameter at 0x1908 |
| this | 0x1950 | RW | 2 | clamped parameter value (track env group 19) |
| this | 0x1958 | R | — | min bound for parameter at 0x1950 |
| this | 0x195C | R | — | max bound for parameter at 0x1950 |
| this | 0x1B10 | R | — | difficulty level selector (switch value: 1-4) |
| this | 0x2DB8 | RW | 1 | clamped parameter value (track env group 20) |
| this | 0x2DC0 | R | — | min bound for parameter at 0x2DB8 |
| this | 0x2DC4 | R | — | max bound for parameter at 0x2DB8 |

**Written-by note (persistence):**
- this 0x11E8: once per call, conditional on switch case 1 (difficulty level)
- this 0x1254: once per call, conditional on switch case 1
- this 0x135C: once per call, conditional on switch cases 2
- this 0x1380: once per call, conditional on switch case 1
- this 0x13A4: once per call, conditional on switch case (float, set differently per case)
- this 0x13C8: once per call, conditional on switch case 1
- this 0x13EC: once per call, conditional on switch case 1
- this 0x1410: once per call, conditional on switch case 1 (cases 1-3 set it)
- this 0x16F8: once per call, conditional on switch case 2
- this 0x1740: once per call, conditional on switch case 1
- this 0x17AC: once per call, conditional on switch case
- this 0x17D0: once per call, conditional on switch case
- this 0x17F4: once per call, conditional on switch case
- this 0x1878: once per call, conditional on switch case
- this 0x189C: once per call, conditional on switch case
- this 0x18C0: once per call, conditional on switch case
- this 0x18E4: once per call, conditional on switch case
- this 0x1908: once per call, conditional on switch case
- this 0x1950: once per call, conditional on switch case
- this 0x2DB8: once per call, conditional on switch case

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004af1f4 | jpt_4AEA03 | R | switch jump table for main difficulty dispatch (case 1-4 targets) |
| 004af204 | jpt_4AF1C0 | R | switch jump table for post-dispatch AI difficulty sub-switch |
| 005ec4ac | dword_5EC4AC | R | AIDifficultyLevel [DERIVED] (also:  AI difficulty selector (0-3) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004646c0 | FloatClamp | clamps float value between min/max bounds (used for 0x13A4 float parameter) |
| 0047f1f0 | ClampByRange | clamps integer parameter between min/max bounds read from struct |
| 004b1de0 | ClampedFloatSetter_1de0 | sets a clamped float value via global/static state |
| 004b20d0 | ArithmeticComparison_20d0 | performs arithmetic comparison and stores result for parameter tuning |

**Guard conditions:** top-level switch on this+0x1B10 (difficulty level 1-4). Cases 1-2 set integer/float parameters with clamping; case 3 sets some parameters then calls ArithmeticComparison chain; case 4 only calls ArithmeticComparison chain. Default case: no-op. After switch, if switch value non-zero, additional difficulty-dependent dispatch on dword_5EC4AC (AI difficulty 0-3). If this+0x1818 (byte) is non-zero, an extra conditional branch sets additional parameters.