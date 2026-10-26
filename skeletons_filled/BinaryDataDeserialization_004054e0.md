## BinaryDataDeserialization_004054e0 — BinaryDataDeserializationDispatch

**Summary:** Reads binary data at a given index from a file/buffer handle: parses a 40-byte header, extracts type field via bitfield, dispatches type-specific deserialization (type 0 = raw offset, type 1 = threaded object creation with SEH, type 2 = direct seek).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_406790 (00406790)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | file/buffer handle for reading data |
| this | 0x10 | R | — | secondary handle or context pointer |
| this | 0x14 | R | — | count of available data entries (upper bound for a2) |
| this | 0x18 | R | — | offset table base pointer (indexed by a2 to get seek position) |
| this | 0x1C | RW | — | current entry index (set to a2) |
| this | 0x20 | RW | 0 | dword zeroed during deserialization |
| this | 0x24 | RW | — | computed data offset/size after header |
| this | 0x28 | RW | — | seek position (v5 + 40, after header) |
| this | 0x2C | RW | — | extracted type field from bitfield header (-1=invalid, 0=raw, 1=threaded, 2=seek) |
| this | 0x34 | R | — | vtable pointer for dispatch (method at +12) |
| this | 0x38 | RW | — | result from sub_58AE69 (type 1 path) |
| this | 0x40 | R | — | vtable dispatch target offset |

**Written-by note (persistence):**
- this 0x1C: set to a2 once per call
- this 0x20: zeroed once per call
- this 0x24: set based on type-specific computation
- this 0x28: set to v5 + 40 once per call
- this 0x2C: set from bitfield extraction
- this 0x38: set in type 1 path

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be828 | aRb | R | FileModeRb [DERIVED] (also: ` — string comparison template) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00404fe0 | OneTimeInitializationWithAtexitStyleRegistration | ensures static singleton initialization |
| 00405630 | StructInitWithVTableDispatchAndZeroFill | reinitializes struct after failed object creation |
| 004056a0 | MemoryAllocation_56a0 | processes/allocates memory based on header data |
| 00407ef0 | BitfieldExtractFromStruct | extracts type/flag field from binary header bitfield |
| 0052d8d0 | ThreadedObjectCreatorWithSEH | creates a threaded object with structured exception handling |
| 00587f64 | sub_587F64 | seeks to position in file/buffer |
| 0058803f | ThreadSafeReadWrapper_803f | reads data with thread safety |
| 0058ae69 | sub_58AE69 | performs string/file-mode comparison |
| 0059b650 | sub_59B650 | retrieves/creates resource context by index |

**Guard conditions:** Checks this[3] (handle) is non-null and a2 < this[5] (count). PASSES: proceeds with deserialization. BLOCKED (returns 1): null handle or a2 out of bounds. Also returns 1 if bitfield type == -1, or if read/seek fails.
