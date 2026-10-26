## TireSlipCurveBuilder_004d5f70 — tire slip-angle curve builder (spline fit from parsed slip/force data points)

**Summary:** Parses a tire slip-curve definition file (name, step size, and data points), builds a cubic Hermite spline through the data points, finds the peak grip slip angle, and normalizes all spline coefficients by the peak force value.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TireBrandFileParser (004d7150)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x14) | 0x0 | R | — | cubic coefficient a (x³ term, double) of a spline segment |
| *(this+0x14) | 0x8 | R | — | cubic coefficient b (x² term, double) of a spline segment |
| *(this+0x14) | 0x10 | R | — | cubic coefficient c (x term, double) of a spline segment |
| *(this+0x14) | 0x18 | R | — | cubic coefficient d (constant term, double) of a spline segment |
| this | 0x8 | RW | 0 | peak slip value (this[1] as double) — stores the slip angle where grip is maximum |
| this | 0xC | RW | 0 | counter/state variable (dword[3]), reset to 0 before peak-search loop |
| this | 0x10 | RW | — | number of data points parsed (set to v3 after parsing, then used as spline segment count) |
| this | 0x14 | RW | — | pointer to allocated spline-coefficient array (4 doubles × segment_count, 32 bytes each) |

**Written-by note (persistence):**
- this 0x8: written once during peak-search loop (this[1] set whenever a higher force value is found); survives across calls as the stored peak slip angle for this tire
- this 0xC: written once (reset to 0 before peak-search), then incremented as loop counter; internal state, not meaningful between calls
- this 0x10: written once (set to data-point count after parsing); persistent count of spline segments
- this 0x14: written once (allocated via OperatorNewNhMallocWrapper); pointer survives as the spline data array for this tire model

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059e7d8 | dbl_59E7D8 | R | ThermalInflectionThreshold [DERIVED] (also: ` — inflection point threshold) |
| 0059e7e0 | dbl_59E7E0 | R | LookupThreshold_14 [DERIVED] |
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |
| 0059ec10 | dbl_59EC10 | R | DoublePhysicsZero [DERIVED] |
| 005d45e4 | aDDevF119992002_4 | R | SourcePath_F1_1999_2002_4 [DERIVED] |
| 005d4610 | aFirstDataPoint | R | FirstDataPointString [DERIVED] |
| 005d4648 | aNeedAtLeastDDa | R | Str_NeedAtLeastDDa [DERIVED] |
| 005d4684 | aTireSlipCurveS | R | StringTireSlipCurveS [DERIVED] |
| 005d46bc | aSkippingUnexpe | R | SkippingUnexpectedString [DERIVED] |
| 005d46f8 | off_5D46F8 | R | VTable_5D46F8 [DERIVED] |
| 005d46fc | unk_5D46FC | R | UnknownPtr_5D46FC [DERIVED] |
| 005d4700 | aData | R | "Data" keyword string — triggers start of data-point parsing section |
| 005d4708 | aStep | R | StepStr [DERIVED] |
| 005d4710 | aName | R | Str_Name [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7a50 | StringSplitLoop | debug-logging gate: conditionally prints verbose messages if debug flag set |
| 004d7aa0 | DebugLogWrite | writes formatted debug/log message to debug message buffer |
| 005651b0 | sub_5651B0 | reads next token/line type from the text input buffer (returns 1=EOF, 4=error, 0=ok) |
| 005654a0 | sub_5654A0 | parses a keyword+value from the "Name" field into the output buffer |
| 00565aa0 | sub_565AA0 | parses a keyword+value from the "Step" field, populating v58 (step size) |
| 00566650 | StringCopyWithBufferRealloc | copies string with reallocation (stores the parsed curve name) |
| 00566cc0 | ConditionalDispatchBasedOnFlag | reads the next line from the line-buffer into the parse buffer; returns 1 if a line was read |
| 005677b0 | sub_5677B0 | cubic spline solver: given 4 control-point pairs, determines if segment is degenerate (linear) |
| 00587bcf | FreeWrapper_7bcf | frees memory: releases the temporary data-point array v48 |
| 00587c03 | OperatorNewNhMallocWrapper | allocates memory: creates spline coefficient array and temp data-point buffer |
| 00587c20 | sub_587C20 | keyword-match check: returns nonzero if the current token matches "Data" |
| 005887ed | StrlenFormatCallWrapper | parses a float value from string using format dispatch; returns 1 on success |
| 005897ca | sub_5897CA | iterates/resumes string tokenizer on the current parse context |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x10 | <= | 3 | data-point count — if <= 3 use simple two-point slope; if > 3 use cubic central-difference derivative |

**Guard interpretation:** The guard at line 197 (`if (*((int *)this + 4) <= 3)`) checks the number of parsed data points stored in this+0x10. When <= 3 (fewer than 4 points), the initial slope v11 is computed as the simple difference between the first two points (v48[1] - v48[0]). When > 3, it uses a cubic central-difference formula `(v48[2] - v48[0] + v48[2] - v48[0] - (v48[3] - v48[1])) * 0.5`. This affects only the derivative estimation accuracy; both paths produce valid splines.

Additional guards (not in the table above but present in code):
- step size v58 <= 0.0: function returns early with debug-log error "TireSlipCurveS" (BLOCKED)
- data-point count < 3: function returns early with "NeedAtLeastDDa" (BLOCKED — need at least 3 points for a spline)
- first data point *v48 != 0.0: function returns early with "FirstDataPoint" error (BLOCKED — slip curve must start at origin)
