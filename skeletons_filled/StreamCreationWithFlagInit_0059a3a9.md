## StreamCreationWithFlagInit_0059a3a9 — Stream creation with flag init and optional finalize

**Summary:** Initializes stream object: stores handle at offset 0x28, resets flag at offset 0x2C to 0, writes a space byte to stream at offset 0x30, conditionally opens stream (via sub_59A5FE) when handle is null by setting bit 2 on flags at offset 0x4, and optionally calls sub_59A8FA to finalize construction based on a3 parameter.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CEHFrameSetup (00599b1c), LocaleObjectAllocAndVtableSetup (00599bf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | flags field; bit 2 set to trigger stream open when handle is null |
| this | 0x28 | RW | — | stream handle/path parameter |
| this | 0x2C | RW | 0 | init flag, reset to 0 |
| this | 0x30 | RW | — | result of SingleByteWriteViaStream(space byte 0x20) |

**Written-by note (persistence):**
- this 0x28: written once to a2; persists until overwritten
- this 0x2C: written once to 0; persists until overwritten
- this 0x30: written with SingleByteWriteViaStream result; persists until overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0059a5fe | sub_59A5FE | opens/creates stream when handle is null |
| 0059a8fa | sub_59A8FA | finalizes stream object construction |
| 0059a948 | StructFieldInitWithConditionalCall | initializes remaining struct fields |
| 0059b208 | SingleByteWriteViaStream | writes a single byte (0x20 space) to stream |

**Guard conditions:** If this+0x28 (handle) is zero, opens stream by setting bit 2 on flags at offset 0x4 and calling sub_59A5FE. If a3 (third parameter) is non-zero, calls sub_59A8FA to finalize; if zero, skips finalization.
