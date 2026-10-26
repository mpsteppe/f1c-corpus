## FontRenderingPrep_00411840 — FontAndEventRenderDispatcher

**Summary:** Prepares font rendering and dispatch for a text overlay. Resolves generation and sub-indices via helper calls, initializes a track-load state block on first invocation (setting sentinels to -1), then dispatches in sequence: CharacterCodeMapper, RaceEventMessageDispatcher (decrements counter), FontCharacterRenderDispatcher, and SoundEventDispatcher. Returns count of successful dispatches (0-2). Called during text overlay display timer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TextOverlayDisplayTimer (004186f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | first DWORD of input array — generation/index parameter |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004119b0 | sub_4119B0 | R | called during first-time initialization via BooleanToIntConversion |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] — file path string used with StringCopyWithBufferRealloc |
| 005ea5d0 | dword_5EA5D0 | RW | TrackLoadState [DERIVED] — track/load state block, reset to 0 on first init, used as state buffer |
| 005ea5d4 | dword_5EA5D4 | W | FileLoadSentinel [DERIVED] — set to -1 on first init |
| 005ea5d8 | dword_5EA5D8 | W | FileEnumSentinel [CONFIRMED] — set to -1 each call |
| 005ea5dc | dword_5EA5DC | W | FileEnumSentinel [DERIVED] — set to -1 each call |
| 005ea5e0 | byte_5EA5E0 | RW | InitGateFlag [DERIVED] — bit 0 checked/set for one-time initialization |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004119d0 | ShortComputation_19d0 | resolves generation/index level 0 from *a1 |
| 00411a00 | ShortComputation_1a00 | resolves sub-index level 1 from *a1 and generation |
| 00411a50 | ShortComputation_1a50 | resolves sub-index level 2 from *a1 |
| 00411b50 | CharacterCodeMapper | maps character code to font/event ID |
| 00411bf0 | RaceEventMessageDispatcher | dispatches race event message using state block |
| 00411db0 | FontCharacterRenderDispatcher | dispatches font character rendering using state block |
| 00411e90 | SoundEventDispatcher | dispatches sound event using state block |
| 00414140 | DecrementCounterWithFloorAtZero | decrements counter at a2 offset, floor at 0 |
| 00566650 | StringCopyWithBufferRealloc | copies/resets file path string to byte_5EA438 |
| 00587b3e | BooleanToIntConversion | converts boolean result of sub_4119B0 to int (first init only) |

**Guard conditions:** if ShortComputation_19d0 returns -1 → return 0. If either ShortComputation_1a00 or ShortComputation_1a50 result < 0 → return 0. If CharacterCodeMapper returns non-zero → return 0. If RaceEventMessageDispatcher returns != 1 → continue to FontCharacterRenderDispatcher check (else case falls through to return 0).
