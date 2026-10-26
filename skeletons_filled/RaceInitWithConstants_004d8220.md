## RaceInitWithConstants_004d8220 — Race state init with screen constants

**Summary:** Initializes a race-related struct: computes normalized screen dimensions from pixel values, then calls a sequence of init subroutines (struct setup, per-channel batch init 1-5, audio/timer init, and finalization).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** OnScreen_Init (0049efa0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xE4 | RW | 0.00078125001 × dword_5D6D60 | Normalized screen width (pixels × 1/1280) |
| this | 0xE8 | RW | 0.0009765625 × dword_5D6D64 | Normalized screen height (pixels × 1/1024) |

**Written-by note (persistence):**
- this 0xE4: Overwritten each call with fresh computation; external poke survives (direct assignment, not incremental)
- this 0xE8: Same as 0xE4 — direct overwrite each call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005acf38 | flt_5ACF38 | R | GBChannelScaleFactor [DERIVED] |
| 005acf3c | flt_5ACF3C | R | Renderer_SceneScaleFactor [DERIVED] |
| 005d6d60 | dword_5D6D60 | R | ScreenWidth [DERIVED] |
| 005d6d64 | dword_5D6D64 | R | ScreenWidth [DERIVED] (also: input device parameters) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d8720 | UtilityFunction_8720 | General struct utility initialization |
| 004d8760 | sub_4D8760 | Finalization step returning result status |
| 004d88d0 | sub_4D88D0 | Audio/timer sub-component init |
| 004d8ab0 | sub_4D8AB0 | Sub-component init of this struct |
| 004d8cf0 | sub_4D8CF0 | Per-index batch init (called for indices 1–5) |

**Guard conditions:** None — unconditional init sequence; all calls execute without branches.
