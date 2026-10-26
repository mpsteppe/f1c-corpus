## TrackConfig_0042e530 — TrackSetupPerFrameUpdate

**Summary:** Per-frame updates vehicle setup parameters (gear ratios, ride heights, spoiler angle, track-type adjustments) based on component/subcomponent indices a2/a3, clamping values, firing state-change events, and re-matching floating-point setup indices to nearest allowed steps.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIGearSelectionSet (0042eaa0), ListSelectionClamp (0042eb60), TheSvmHdvVehicleFileParser (004f4270)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x130 | R | — | float base value for final setup ratio calc (this+304) |
| this | 0x138 | R | — | float step multiplier for final setup ratio (this+312) |
| this | 0x144 | R | — | integer index for front setup slot (this+324) |
| this | 0x3F0 | R | — | float base value for second setup array (this+1008) |
| this | 0x3F8 | R | — | float step for second setup array (this+1016) |
| this | 0x400 | R | — | maximum count for second setup array loop (this+1024) |
| this | 0x404 | RW | — | best-match index written into second setup array (this+1028) |
| this | 0x6B0 | R | — | float base value for front ride-height / setup group (this+1712) |
| this | 0x6B8 | R | — | float step for front setup group (this+1720) |
| this | 0x6C4 | R | — | integer index into front setup group (this+1732) |
| this | 0x970 | R | — | float base value for rear ride-height / setup group (this+2416) |
| this | 0x978 | R | — | float step for rear setup group (this+2424) |
| this | 0x980 | R | — | maximum count for rear setup group loop (this+2432) |
| this | 0x984 | RW | — | current index into rear setup group, incremented to meet threshold (this+2436) |
| this | 0xBC4 | RW | 0 | gear-selection index, reset to zero when not on road course (this+3012) |
| this | 0xCC0 | R | — | session-dependent maximum value for decrement clamp (this+3264) |
| this | 0xCC4 | RW | — | session-dependent value, decremented when session active and component matches (this+3268) |
| this | 0x12B0 | R | — | float base value for rear spoiler angle array (this+4784) |
| this | 0x12B8 | R | — | float step for rear spoiler angle array (this+4792) |
| this | 0x12C0 | R | — | maximum count for spoiler angle array loop (this+4800) |
| this | 0x12C4 | RW | — | best-match index into spoiler angle array (this+4804) |
| this | 0x1988 | R | — | boolean flag: if set, use event-trigger mode; otherwise use weighted-sum comparator mode (this+6536) |
| this | 0x1990 | R | — | master enable flag: if != 1, return early (skip all processing) (this+6544) |

**Written-by note (persistence):**
- this 0x404: recalc every frame — external poke does NOT persist
- this 0x984: recalc every frame — external poke does NOT persist
- this 0xBC4: recalc every frame — external poke does NOT persist
- this 0xCC4: recalc every frame — external poke does NOT persist
- this 0x12C4: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e9f8 | dbl_59E9F8 | R | SceneLoadTimeout [DERIVED] |
| 005c3704 | aRoadCourse | R | Road course track-type identifier string ("RoadCourse"), compared against track type config |
| 005c3710 | aTrackType | R | Track type configuration string key, read from config and compared |
| 005c371c | aRearspoilerang | R | Rear spoiler angle configuration string key, parsed to float for spoiler matching |
| 007c56a4 | dword_7C56A4 | R | Session type / game mode flag: non-zero = active session, triggers session-value decrement |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042e470 | EventTriggerOnStateChange | Triggers state-change event notifications on pairs of config-value blocks (front/rear setup groups) |
| 0042e4a0 | WeightedSumComparatorWithBinaryAdjustment | Compares two config-value blocks via weighted sum and binary adjustment; third argument is a boolean trigger condition |
| 004c58a0 | StringCopyWithValidation | Copies and validates a configuration string from settings storage into a buffer |
| 00588410 | sub_588410 | String comparison (strcmp equivalent); used here to check if track type equals "RoadCourse" |
| 0058850f | sub_58850F | Parses configuration string to double/float (used for rear spoiler angle value) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1990 | != | 1 | master track-config enable flag (this+6544) |

**Guard interpretation:** If this+0x1990 (the master enable flag) is NOT equal to 1, the function returns early without doing any setup processing. When the flag IS 1, all per-frame setup adjustments proceed: gear selection clamping, event/weighted-sum triggers on config groups, spoiler-angle best-match search, session-value decrement, track-type detection (road course), and ride-height index advancement with threshold checks.