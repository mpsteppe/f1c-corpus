## TextOverlayDisplayTimer_004186f0 — TextOverlayTickUpdate

**Summary:** Per-tick update for timed text overlay display (commentary/subtitles). Checks race active, track condition, and init state; updates audio object, manages display cooldown timer and slot expiration; renders active overlay text via font subsystem; resets and compacts slots after display.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Options_Setup (004a0eb0), RenderTickUpdate (004c8b70), sub_4F9480 (004f9480)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0xAF4)+0x0) | 0x4 | R | — | vfunc+4 — render method on audio/text object |
| *(*(this+0xAF4)+0x0) | 0x8 | R | — | vfunc+8 — query method (0=ready, non-zero=busy) |
| *(*(this+0xAF4)+0x0) | 0x18 | R | — | vfunc+24 — update/process method on audio object |
| *(this+0xAF4) | 0x0 | R | — | vtable pointer of audio/text object |
| this | 0x864 | R | — | Current active display slot index (-1 = none) |
| this | 0x86C | R | — | Float time threshold for overlay display |
| this | 0xAE4 | RW | 1 | Pending display flag (byte), cleared when display fires |
| this | 0xAE8 | RW | — | Last display timestamp (float) |
| this | 0xAEC | RW | 18446744073709551615 | Active overlay item ID (-1 = none) |
| this | 0xAF0 | R | — | Initialized flag (byte), must be set to process |
| this | 0xAF4 | R | — | Pointer to audio/text overlay object (vtable-based) |
| this | 0x135C | RW | — | Decrementing cooldown counter for display throttle |

**Written-by note (persistence):**
- this 0xAE4: cleared to 0 when display condition met, set to 1 on successful render
- this 0xAE8: set to current elapsed time (dbl_8AFEA8) on display and reset
- this 0xAEC: set to -1 on timeout or early exit; set to active slot index on render
- this 0x135C: decremented each frame when cooldown active; reset on timer expiry

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005bf9ac | flt_5BF9AC | R | AnimationTimingFloats [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007cf278 | dword_7CF278 | R | PitWindowTimeThreshold [DERIVED] |
| 007cf3c8 | flt_7CF3C8 | R | TrackConditionState [CONFIRMED] |
| 007d0308 | dword_7D0308 | R | RaceActiveFlag [FACT] |
| 008afea8 | dbl_8AFEA8 | R | InputAxisDeadZone [DERIVED] (also: ` â€” axis threshold (float) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00411840 | FontRenderingPrep | Prepares font display data from slot array into output buffer |
| 004144d0 | StructInitWithSentinelValues | Resets slot struct at this+0x864 to defaults after display |
| 00418ac0 | ArraySlotCompactionWithGapFilling | Compacts slot array, removing gaps from expired slots |
| 00566650 | StringCopyWithBufferRealloc | Copies string content for overlay buffer construction |
| 00587bcf | FreeWrapper_7bcf | Frees allocated memory for overlay data buffers |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x864 | == | 18446744073709551615 | Slot index sentinel (-1 = no active slot) |

**Guard interpretation:** When this+0x864 == -1 (no active display slot), function returns 0 without processing — BLOCKED. When slot >= 0 (active slot exists), processing continues — PASSES.
