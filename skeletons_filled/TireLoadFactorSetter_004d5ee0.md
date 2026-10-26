## TireLoadFactorSetter_004d5ee0 — TireLoadFactorComputer

**Summary:** Computes tire load factor values: average load (a2+a3)/2, half-difference (a2-a3)/2, stores a4 as the tire load, and its reciprocal 1.0/a4. If a4 <= 0 and session is not server (5), conditionally logs "tire load factor" debug message.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** TireCompoundPerWheelPhysicsApplication (0043da10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | average of a2 and a3: (a2 + a3) * 0.5 |
| this | 0x8 | RW | — | half-difference of a2 and a3: (a2 - a3) * 0.5 |
| this | 0x10 | RW | — | tire load value (a4) |
| this | 0x18 | RW | — | reciprocal of tire load: 1.0 / a4 |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist
- this 0x8: recalc every frame — external poke does NOT persist
- this 0x10: recalc every frame — external poke does NOT persist
- this 0x18: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |
| 005d45c0 | aTireLoadFactor | R | TireLoadFactorString [DERIVED] |
| 005d45e4 | aDDevF119992002_4 | R | SourcePath_F1_1999_2002_4 [DERIVED] |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7a50 | StringSplitLoop | validates debug log source path split |
| 004d7aa0 | DebugLogWrite | writes tire load factor debug message to log |

**Guard conditions:** If a4 <= 0 and dword_7C569C != 5 (not a server session), conditionally writes debug log via StringSplitLoop guard.
