## sub_4BB8E0_004bb8e0 — SessionStateReset

**Summary:** For non-qualifying sessions (SessionType <= 6), resets AI racing line path and clears float/flag fields if object condition is met; always zeroes status flag bytes at the end.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4C6B60 (004c6b60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x32C8 | R | — | object condition flag (checked <= 1) |
| this | 0x0 | R | — | pointer to vehicle/object |
| this | 0x18 | RW | 18446744072627421184 → -1.0f | float field reset to -1.0 |
| this | 0x1C | RW | 18446744072627421184 → -1.0f | float field reset to -1.0 |
| this | 0x20 | RW | 18446744072627421184 → -1.0f | float field reset to -1.0 |
| this | 0x60 | RW | 1 | mode flag (reset from 2 to 1) |
| this | 0xA8 | RW | 0 | status flag byte |
| this | 0xAC | RW | 0 | status flag byte |
| this | 0xB0 | RW | 0 | status flag byte |
| this | 0xB4 | RW | 0 | status flag byte |
| this | 0xD0 | RW | 0 | status flag byte |
| this | 0xD4 | RW | 0 | status flag byte |

**Written-by note (persistence):**
- this 0x18: recalc every frame — external poke does NOT persist
- this 0x1C: recalc every frame — external poke does NOT persist
- this 0x20: recalc every frame — external poke does NOT persist
- this 0x60: recalc every frame — external poke does NOT persist
- this 0xA8: recalc every frame — external poke does NOT persist
- this 0xAC: recalc every frame — external poke does NOT persist
- this 0xB0: recalc every frame — external poke does NOT persist
- this 0xB4: recalc every frame — external poke does NOT persist
- this 0xD0: recalc every frame — external poke does NOT persist
- this 0xD4: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004e9ca0 | AIRacingLinePathFollowing | update AI racing line path following |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x60 | == | 2 | mode flag (reset to 1 when == 2) |

**Guard interpretation:** BLOCKED (skips AI path reset and float clear) when SessionType > 6 (qualifying type 7) OR when obj+13000 > 1. The inner check this[24]==2 is a conditional reset (not a guard — if 2, set to 1). Status byte zeroing at bottom always runs regardless.
