## SessionStateByte7CE25FSetter_00464600 — Conditional setter for restart-progress flag byte_7CE25F

**Summary:** Called from Game_Post to set `byte_7CE25F = 1` when the restart-precondition guard `byte_7CE260` is NOT set AND either of two object status bytes at `(*this) + 0xC5` or `(*this) + 0xC6` is nonzero. Also performs track-config name building and guarded initialization on sub-objects. The flag `byte_7CE25F` is never cleared here — consumed/cleared elsewhere (e.g., RestartGate via sub_485B90).

**Struct fields accessed:**

| Offset (dec) | Offset (hex) | Read/Write | Init value (if written as literal) | Purpose inferred from code |
|---|---|---|---|---|
| `*this + 197` (byte) | +0xC5 | Read | — | Object status byte 1; if nonzero → sets byte_7CE25F=1 |
| `*this + 198` (byte) | +0xC6 | Read | — | Object status byte 2; if nonzero → sets byte_7CE25F=1 |
| `*(_DWORD *)(*this + 16324)` | +0x3FC4 | Read | — | Nonzero check gates ShortComputation_3140 + GuardedInitCall |
| `*(_DWORD *)(*this + 16312)` | +0x3FB8 | Read | — | Passed to SingleFunctionCallWrapper_a910 |
| `*this + 112528` (byte area) | +0x1B790 | Passed to call | — | Address passed to GuardedInitCall |

**Guard conditions:**

| Field | Checked values | What PASSES | What is BLOCKED |
|---|---|---|---|
| `byte_7CE260` | zero vs nonzero | **0** = enters function body (sets flag) | Nonzero = entire body skipped, returns byte_7CE260 value |
| `*(_DWORD *)(*this + 0x3FC4)` | zero vs nonzero | Nonzero = runs ShortComputation + GuardedInitCall | Zero = skips those calls |
| `*(_BYTE *)(v3 + 0xC5)` | zero vs nonzero | Nonzero → `byte_7CE25F = 1` | Zero → checks next byte |
| `*(_BYTE *)(v3 + 0xC6)` | zero vs nonzero | Nonzero → `byte_7CE25F = 1` | Zero → flag NOT set |

**Written-by note:** The only write is `byte_7CE25F = 1` — written conditionally when either +0xC5 or +0xC6 is nonzero. Written once per call. Never cleared here. Because Frame-path is NOT_FOUND, call frequency is UNKNOWN — an external poke to `byte_7CE25F` will persist until this function next runs. The flag is consumed elsewhere (sub_485B90 in RestartGate reads it).

**Globals referenced:**

| Address | IDA name | Read/Write | Role |
|---|---|---|---|
| 0x007CE260 | byte_7CE260 | Read | Restart precondition guard; nonzero blocks entire function |
| 0x007CE25F | byte_7CE25F | **Write** (set to 1) | Restart-progress flag (read by sub_485B90 in RestartGate) |
| 0x007CE498 | byte_7CE498 | Write (via TrackConfigurationNameBuilder) | Track configuration name buffer |

**Functions called:**

| Address | IDA name | Inferred purpose |
|---|---|---|
| — | TrackConfigurationNameBuilder | Build track configuration name into byte_7CE498 |
| — | ShortComputation_3140 | Computation (gated by +0x3FC4 being nonzero) |
| — | GuardedInitCall | Initialization of sub-object at *this + 0x1B790 |
| — | SingleFunctionCallWrapper_a910 | Single function call on *this + 0x3FB8 |

**Call frequency:** UNKNOWN (Frame-path: NOT_FOUND — called from Game_Post, likely event-driven on session state changes)
