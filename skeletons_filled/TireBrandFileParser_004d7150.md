## TireBrandFileParser_004d7150 — Tire Physics File Parser (SlipCurve + Compound)

**Summary:** Parses a tire physics data file containing "SlipCurve" and "Compound" sections. Makes two passes: first counts entries and allocates typed arrays (24-byte slip curves, 680-byte compounds), second fills them via TireSlipCurveBuilder and compound initializer. Validates counts match and reports errors on overflow or mismatch.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TireBrandLoader (004d7660)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | slip curve entry count (incremented during first pass, read in second) |
| this | 0xC | RW | — | slip curve data array pointer (allocated after first pass, 24 bytes per entry + 4-byte count header) |
| this | 0x10 | R | — | compound entry count (incremented during first pass, read in second) |
| this | 0x14 | RW | — | compound data array pointer (allocated after first pass, 680 bytes per entry + 4-byte count header) |

**Written-by note (persistence):**
- this 0xC: written once after first-pass counting and allocation (line 110); persists as allocated slip curve array across calls until ArrayBlockCleanup
- this 0x14: written once after first-pass counting and allocation (line 138); persists as allocated compound array across calls until ArrayBlockCleanup

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c6810 | aCouldNotOpenS | R | "Could not open" error message string |
| 005d45e4 | aDDevF119992002_4 | R | source file path / debug identifier string for error reporting |
| 005d4880 | aBadSyntaxInFil_1 | R | "Bad syntax in file" error string for count mismatch at end |
| 005d48a8 | aBadSyntaxInFil_0 | R | "Bad syntax in file" error string for compound section overflow |
| 005d48e0 | aBadSyntaxInFil | R | "Bad syntax in file" error string for slip curve section overflow |
| 005d491c | aNoCompoundsFou | R | "No compounds found" error message string |
| 005d4938 | aCompound | R | "Compound" keyword string for file section detection |
| 005d4944 | aSlipcurve | R | "SlipCurve" keyword string for file section detection |
| 008ad25c | dword_8AD25C | R | debug message output buffer (destination for DebugLogWrite) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d5f70 | TireSlipCurveBuilder | construct tire slip curve data from parsed file data into 24-byte block |
| 004d68a0 | PhysicsStateStructureInitializer | initialize physics state structure to default values within compound block |
| 004d6b00 | sub_4D6B00 | construct tire compound data from parsed file data into 680-byte block |
| 004d7050 | ArrayBlockCleanup | free previously allocated slip curve and compound arrays on this object |
| 004d7a50 | StringSplitLoop | split/format string for debug output (returns boolean for conditional logging) |
| 004d7aa0 | DebugLogWrite | write formatted message to debug log buffer |
| 005651b0 | sub_5651B0 | parse/tokenize current line from file stream into buffer |
| 00566650 | StringCopyWithBufferRealloc | copy string with reallocation of destination buffer |
| 005668b0 | ZeroInitSmallStruct | zero-initialize small structure (likely file handle wrapper) |
| 005668d0 | SubCallWithConditionalFieldFree | conditionally free fields and return (cleanup wrapper) |
| 00566b20 | AudioStreamOpen | open file stream for reading (returns success boolean) |
| 00566b90 | ConditionalFileHandleCloseWithFlagDispatch | close file handle conditionally based on flags |
| 00566cc0 | ConditionalDispatchBasedOnFlag | read next line/section from file stream (returns true while data available) |
| 00566d30 | ConditionalAllocInitDispatch | conditionally allocate and initialize buffer |
| 00568a60 | UtilityFunction_8a60 | set/initialize field with constant (called with 91, this+8) |
| 00587c03 | OperatorNewNhMallocWrapper | allocate memory with new-handler fallback |
| 00587c20 | sub_587C20 | string comparison/search (strstr-like) — used to detect "SlipCurve" and "Compound" keywords |
| 00587dd0 | sub_587DD0 | bounded string copy with length limit |
| 00589901 | sub_589901 | transform/process string (likely case conversion or normalization) |

**Guard conditions:**
1. `AudioStreamOpen(a2, 1)` returns 0 → error path: **BLOCKS** parsing when file cannot be opened; logs "Could not open" error. **PASSES** to parsing when file opens successfully.
2. First pass line loop: `ConditionalDispatchBasedOnFlag(v32, 384)` → **PASSES** while lines remain in file; terminates at EOF.
3. `sub_587C20(line, "SlipCurve")` → increment slip curve count: **PASSES** when line contains "SlipCurve" keyword.
4. `sub_587C20(line, "Compound")` → increment compound count: **PASSES** when line contains "Compound" keyword.
5. After allocation: `(!compound_count || !compound_array) && StringSplitLoop(...)` → log "No compounds found": **PASSES** (logs error) when compound count is zero or allocation failed. Non-blocking — continues.
6. Second pass: `v18 >= this[2]` on "SlipCurve" → overflow: **BLOCKS** further slip curve processing when parsed count exceeds first-pass count; logs "Bad syntax" and breaks loop. **PASSES** when within bounds.
7. Second pass: `v23 >= this[4]` on "Compound" → overflow: **BLOCKS** further compound processing when parsed count exceeds first-pass count; logs "Bad syntax" and breaks loop. **PASSES** when within bounds.
8. Final validation: `v18 != this[2] || v23 != this[4]` → count mismatch: **BLOCKS** (logs "Bad syntax in file" error) when second-pass counts don't match first-pass counts. **PASSES** when counts match exactly.
