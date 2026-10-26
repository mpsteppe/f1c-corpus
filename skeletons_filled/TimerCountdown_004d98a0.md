## TimerCountdown_004d98a0 — Countdown phase handler with driver info

**Summary:** Decrements a countdown timer (this[4]) by delta time each call. While timer is active (>= 0), renders current player's grid position, driver name, and team/car name at fixed HUD positions. Returns 1 when timer expires.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TimerDisplayRender (004d9dd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | RW | — | Countdown timer value (float, seconds); decremented by dbl_8AFE98 each call; < 0 means expired |

**Written-by note (persistence):**
- this 0x10: Decremented each call by dbl_8AFE98. External poke survives (incremental change). Persists across frames during countdown phase.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005acf60 | flt_5ACF60 | R | TextColorDefault [DERIVED] |
| 005ccef0 | aC | R | FormatString [DERIVED] |
| 005d4ae8 | byte_5D4AE8 | R | Base character for position number display |
| 007c54e0 | dword_7C54E0 | R | postProcessInput [CONFIRMED] — current player vehicle pointer; null means no player |
| 008afe98 | dbl_8AFE98 | R | ScoringDefaultReturn [DERIVED] — delta time constant subtracted from countdown each frame |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7e40 | UITextRenderWithScale | Renders position number, driver name, team name at HUD positions |
| 0058815f | StringFormatWithBufferOverflowCheck | Formats position character from index |
| 00589901 | sub_589901 | String sanitization before rendering |

**Guard conditions:** `this[4] < 0.0` (offset 0x10) → countdown expired, return 1 (skip all rendering and decrement). `dword_7C54E0` (player vehicle) == NULL → skip all driver info rendering. `position-1 > 24` (offset 0x4060 on vehicle) → skip position number display.
