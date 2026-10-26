## FloatRangeIndexLookup_004d7c10 — WrappedFloatRangeIndexer

**Summary:** Wraps float a2 into range [0, this[9]) by repeatedly adding/subtracting this[9]. If result is <= flt_5EA404 (small threshold), returns 0. Otherwise scans 3 predefined range thresholds (at flt_5EA404, flt_5EA404-4, flt_5EA404-8) to find which segment the value falls into, returning index 0, 1, or 2 (or -1 if none match).

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AISessionModeTransition (004193a0), sub_41B250 (0041b250), PitSelectionStateMachine (0041b3c0), sub_4BCCC0 (004bccc0), FloatWrapTableInterpolation (004d7cf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24 | R | — | wrap range (period) — value is wrapped into [0, this[9]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005ea404 | flt_5EA404 | R | TrackRefValueArray [DERIVED] (also: ` — track reference values) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If wrapped value <= flt_5EA404, returns 0 (first segment). If wrapped value > this[9] after subtract loop, continues wrapping. Scans three range thresholds descending — if value exceeds none, returns -1.
