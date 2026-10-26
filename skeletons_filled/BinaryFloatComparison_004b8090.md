## BinaryFloatComparison_004b8090 — SerializationMagicCheck

**Summary:** Writes sentinel values ("xxxx" and -1.0f) to the serialization backend, then reads them back to verify they match expected constants. Used for serialization format version detection.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ModelSceneFileLoader (004b6c90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d2434 | off_5D2434 | R | SerializeMagic [DERIVED] |
| 005d2438 | flt_5D2438 | R | CheckpointTime [DERIVED] |
| 005d246c | dword_5D246C | R | FloatCmp_Value [DERIVED] |
| 005d2470 | byte_5D2470 | R | ByteCompareValue [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566c00 | FileWriteWithBackendDispatch | writes data through serialization backend |
| 00566d30 | ConditionalAllocInitDispatch | initialises allocation context for serialization operation |

**Guard conditions:** None — always executes both writes. Returns comparison result of sentinels against expected constants.
