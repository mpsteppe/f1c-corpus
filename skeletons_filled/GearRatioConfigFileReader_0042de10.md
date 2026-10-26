## GearRatioConfigFileReader_0042de10 — GearRatioConfigReader

**Summary:** Parses gear ratio and final drive configuration from file. Opens file, reads "[GearRatios]" and "[FinalDrive]" sections, counts and extracts ratio values into allocated buffers, and stores pointer+count pairs in struct fields.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ReplayStateCopy (0042ecc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | gearRatioCount |
| this | 0x4 | RW | — | gearRatioBuffer |
| this | 0x8 | RW | 0 | finalDriveCount |
| this | 0xC | RW | — | finalDriveBuffer |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist
- this 0x4: recalc every frame — external poke does NOT persist
- this 0x8: recalc every frame — external poke does NOT persist
- this 0xC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0042dc20 | byte_42DC20 | R | sectionStartToken |
| 005c36c0 | aBevel | R | GraphicsParam_Bevel [DERIVED] |
| 005c36c8 | aFinalDrive | R | String_FinalDrive [DERIVED] |
| 005c36d8 | aRatio | R | RatioString [DERIVED] |
| 005c36e0 | aGearRatios | R | GearRatiosString [DERIVED] |
| 005c36f0 | aR | R | Token_R [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042ddd0 | ScoreSlotDeallocator | Frees any previously allocated gear ratio and final drive buffers |
| 005651b0 | sub_5651B0 | Token type parser (returns token type: 0=value, 1/4=section/comment boundary) |
| 00565760 | sub_565760 | Parses floating-point value from token string |
| 00587c03 | OperatorNewNhMallocWrapper | Memory allocation wrapper for buffer creation |
| 00587c20 | sub_587C20 | String comparison against section header marker |
| 00587ca0 | FileReadUntilNewline | Reads next line from file into buffer |
| 00587d02 | FileCloseWithLock | Closes file handle |
| 00587db0 | sub_587DB0 | Opens file for reading with mode token |
| 00587f64 | sub_587F64 | Seeks file position (rewind to section start) |
| 005890aa | sub_5890AA | Sorts numeric array (qsort wrapper) |

**Guard conditions:** Returns immediately if file open fails. Enters parsing loop only after successful newline read. Token type 0 (value) passes for extraction; token types 1 or 4 (section/comment) break the inner loop.
