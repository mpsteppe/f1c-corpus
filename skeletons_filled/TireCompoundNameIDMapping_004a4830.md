## TireCompoundNameIDMapping_004a4830 — TireCompoundNameToId

**Summary:** Maps a tire compound name string to an integer ID: Hard→2, Soft→3, Intermediate→4, Wet→5, Monsoon→6, unknown→1. Uses sub_588410 for string comparison (returns 0 on match).

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_429960 (00429960), RandomWeightedTierSelection (00429fd0), AIPushLap (0042a180), GuardedCallWithCheck (004a5c10), sub_4F18C0 (004f18c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c7224 | aWetCompound | R | WetCompoundString [DERIVED] — "Wet" or "Wet Compound" string literal |
| 005cd4f8 | aMonsoonCompoun | R | StringMonsoonCompound [DERIVED] — "Monsoon" string literal |
| 005cd50c | aIntermediateCo | R | IntermediateCoString [DERIVED] — "Intermediate" string literal |
| 005cd524 | aSoftCompound | R | SoftCompoundString [DERIVED] — "Soft" string literal |
| 005cd534 | aHardCompound | R | HardCompoundStr [DERIVED] — "Hard" string literal |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00588410 | sub_588410 | String comparison; returns 0 on exact match, non-zero on mismatch |

**Guard conditions:** Chain of if-else comparisons against compound name strings. Each step checks if the input string matches the current compound; if yes, returns the corresponding ID. Fall-through returns default ID 1 for unknown strings.