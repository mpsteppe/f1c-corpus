## PostPitCleanup_0042a6f0 — PostPitCleanup

**Summary:** Post-pit-exit cleanup routine. Fills a sentinel slot, optionally increments tire change counter (if flag at 0x4584 is clear), clears timeOfNextExit for race sessions, and sets next pit window timestamp to session time + 4.0. Returns the tire-change flag byte.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIAbility (00429470), PitStopDecisionTireCompound (0042a3d0), PitStopProgress (004a68b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x447C | RW | — | next pit exit timestamp (set to sessionTime + 4.0 seconds) |
| this | 0x4534 | RW | 0 | timeOfNextExit [CONFIRMED] — cleared to 0 for race sessions |
| this | 0x4584 | R | — | tire-change flag byte — if 0, tire change counter is incremented |
| this | 0x45E0 | R | — | tire change counter (incremented when flag at 0x4584 is 0) |

**Written-by note (persistence):**
- this 0x447C: recalc every frame — external poke does NOT persist
- this 0x4534: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e46c | flt_59E46C | R | TireSlipOffset [DERIVED] (also: ` — offset value) |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] — 7 = race session (triggers timeOfNextExit clear) |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time, used for next exit timestamp) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004bd760 | SentinelSlotFill | fills a sentinel/slot entry related to pit state tracking |

**Guard conditions:** No guard at function level. Flag at 0x4584 controls tire counter increment: if 0 (no change yet), counter increases. Session type == 7 gates the timeOfNextExit clear. All other operations execute unconditionally.
