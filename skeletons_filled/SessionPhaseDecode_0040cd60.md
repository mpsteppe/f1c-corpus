## SessionPhaseDecode_0040cd60 — SessionPhaseDecode

**Summary:** Decodes session phase identifier (0-4) from a session pointer into a stored field, or sets fallback code 5 on mismatch. Used across audio, random state machine, and session dispatch systems.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** RandomStateMachineWithTimerAndTrigger (0040c070), SessionPhaseDispatchWithCascadeChecks (0040d1b0), ShortComputation_d3c0 (0040d3c0), ShortComputation_d410 (0040d410), sub_49F870 (0049f870), sub_4B9890 (004b9890), AudioSoundEffectController (004e0ed0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | Expected/active session pointer compared against current session |
| this | 0xC | RW | 5 | Decoded phase result (0-4 on match, 5 on mismatch/fallback) |
| this | 0x18 | R | — | Current session pointer (this[6]) |
| this | 0x4C | R | — | Session phase value (0-4) from session object, used as switch key |

**Written-by note (persistence):**
- this 0xC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0040cdbc | jpt_40CD70 | R | Jump table for 5-case phase decode switch |

**Functions called:**
*(none)*

**Guard conditions:** this[6] (current session) == this[2] (expected session) → decode phase from session object field, mapping 0-4 to same values. Mismatch → set this[3] = 5 (fallback/error state).
