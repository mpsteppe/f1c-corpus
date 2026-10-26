## SettingsIniFileWriter_004c0690 — Career standings ini writer

**Summary:** Writes career season standings data to an ini-style text buffer. Outputs per-driver finish positions/points (up to 48 entries) and season totals including grid positions and control type.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PlayerOpponentStateWriter (004c0cc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x18 | R | — | start of per-entry finish data array (terminated by negative sentinel) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c30b4 | word_5C30B4 | R | config/config separator token |
| 005d2720 | aActiveD | R | "Active" field key for ini output |
| 005d272c | aControltypeD | R | "ControlType" field key |
| 005d273c | aCurrentgridpos_0 | R | "CurrentGridPos" field key for ini output |
| 005d2754 | aOriginalgridpo_0 | R | "OriginalGridPos" field key for ini output |
| 005d2770 | aPolestakenD | R | "PolesTaken" field key |
| 005d2780 | aPointsposition_0 | R | "PointsPosition" field key |
| 005d2794 | aSeasonpointsD | R | "SeasonPoints" field key |
| 005d27a8 | aFinishpoints22 | R | "FinishPoints" format key |
| 005d27c0 | aFinishposition_0 | R | "FinishPosition" format key |
| 005d27d8 | aRcdfileS | R | "RcdFile" field key |
| 005d27e8 | aVehfileS | R | "VehFile" field key |
| 005d27f8 | aNameS | R | "Name" field key |
| 005ea438 | byte_5EA438 | R | default application directory path |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566c30 | BufferWriteWithStringLengthCheck | write key-value pair to output buffer with length check |
| 00566cf0 | ResourceLookupWithDualPath | resolve resource path for output file |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x18 | < | 0 | per-entry finish data sentinel check |

**Guard interpretation:** Loop iterates up to 48 entries; breaks early when per-entry finish data value at this+0x18 + 4*entry is negative (unused entry sentinel). Also returns early if output buffer a2 is NULL/empty.
