## sub_517ADC_00517adc — InflateBlockProcessor

**Summary:** Processes a deflate-compressed data block through a state machine (header parsing, optional dictionary, decompression via sub_527752, and CRC/adler32 checksum verification). Part of zlib decompression system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_511B7C (00511b7c), sub_519019 (00519019)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | input compressed data byte pointer |
| this | 0x0 | R | — | current decompression state variable (switch selector) |
| this | 0x4 | RW | — | sub-state / bit buffer accumulator |
| this | 0x8 | R | — | window size or buffer limit |
| this | 0x18 | RW | — | error message string pointer |
| this | 0x1C | RW | 12 | pointer to internal state structure (adler32/CRC window) |
| this | 0x20 | RW | 0 | remaining bytes count / data pointer |
| this | 0x24 | RW | — | accumulated checksum value (adler32 or CRC) |
| this | 0x28 | R | — | pointer to decompression context (sub_527752) |
| this | 0x2C | R | — | stored expected checksum for comparison |
| this | 0x30 | RW | — | output/target value for state transitions |

**Written-by note (persistence):**
- this 0x4: updated per byte consumed; external poke corrupts stream position
- this 0x18: set to error string on failure; external poke would change error
- this 0x1C: set during init; external poke corrupts state pointer
- this 0x20: decremented as data consumed; external poke corrupts count
- this 0x24: built up from input bytes; external poke corrupts checksum
- this 0x30: set during state transitions; external poke corrupts result

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00517e0b | jpt_517B19 | R | jump table for switch-state transitions |
| 005afa20 | aNeedDictionary | R | NeedDictionaryString [DERIVED] |
| 005afa30 | aIncorrectDataC | R | IncorrectDataChecksumString [DERIVED] |
| 005afa48 | aIncorrectHeade | R | String_IncorrectHeader [DERIVED] |
| 005afa60 | aInvalidWindowS | R | aInvalidWindowS [DERIVED] |
| 005afa74 | aUnknownCompres | R | UnknownCompres [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0052765a | sub_52765A | finalize checksum after decompression is complete |
| 00527752 | sub_527752 | perform actual inflate/deflate decompression into output buffer |

**Guard conditions:** Parameter a2=4 triggers initial state setup. Input pointer a1[7] and data pointer *a1 must be non-null. Switch on state 0-13: state 0 parses zlib header (checks compression method==8, window size ≤ *((_DWORD *)a1[7] + 4), header checksum mod 31==0). State 7 runs inflate decompression via sub_527752; on -3 returns error, on 0 continues; after completion validates checksum against expected (state 8-11). State 6 returns "need dictionary". State 12 returns 1 (done). State 13 returns -3 (error). Any mismatch returns -2 (invalid).
