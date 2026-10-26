## TireSlipCurveNameLookup_004d75d0 — TireSlipCurveNameSearcher

**Summary:** Searches a tire slip curve name table for a matching string. Iterates up to this[2] entries at this[3] with 24-byte stride, comparing each name via sub_588410. Returns pointer to matching entry, or 0 if not found (with optional debug log).

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** TireCompoundPerWheelPhysicsApplication (0043da10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | number of slip curve name entries |
| this | 0xC | R | — | pointer to array of slip curve entries (24-byte stride, first member is name string pointer) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d45e4 | aDDevF119992002_4 | R | SourcePath_F1_1999_2002_4 [DERIVED] |
| 005d497c | aTireBrandDoesn_0 | R | Str_TireBrandDoesn_0 [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7a50 | StringSplitLoop | validates debug source path before logging |
| 004d7aa0 | DebugLogWrite | writes not-found error to debug log |
| 00588410 | sub_588410 | string comparison function (case-insensitive or path-aware) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x8 | <= | 0 | entry count — if zero or negative, skip table and go to error |

**Guard interpretation:** If this[2] <= 0 (table is empty/missing), returns 0 immediately. Otherwise iterates entries; if no match found after all entries, conditionally logs error.
