## sub_51B7CD_0051b7cd — PlaneVisibilityRangeSetup

**Summary:** Validates and configures bitstream/visibility plane ranges — fills a 256-entry per-plane table with a target value over a specified index range, then selects and assigns decoder callback functions (BitstreamDecoder, sub_51B154, PlaneVisibilityTestWithBitfieldOutput, or sub_51B45F) to the output object based on mode flags and bitstream presence.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x124) | 0x4 | R | — | per-plane index into 256-stride table |
| *(this+0x124) | 0x14 | R | — | per-plane decode parameter A (for sub_51A5EA when bitstream absent) |
| *(this+0x124) | 0x18 | R | — | per-plane decode parameter B (for sub_51A5EA when bitstream present) |
| obj | 0x0 | R | — | virtual function table pointer for error dispatch |
| obj | 0x4 | R | — | decoder callback function pointer slot (assigned one of four decoders) |
| obj | 0x14 | RW | 49 | error code field — written 49 (validation error) or 111 (decode mismatch) |
| obj | 0x18 | RW | — | error detail: range start index (a1[90]) |
| obj | 0x1C | RW | 0 | error detail: range end index (a1[91]) |
| obj | 0x20 | RW | — | error detail: mode flag (a1[92]) |
| obj | 0x24 | RW | — | error detail: set value (a1[93]) |
| this | 0x0 | R | — | pointer to error-reporting/decode output object (obj) |
| this | 0x8C | R | — | base address of 256-byte-stride per-plane lookup table |
| this | 0xFC | R | — | stored result value (a1[63], returned as function result and copied to obj+0x34) |
| this | 0x120 | R | — | plane count (loop bound for per-plane processing) |
| this | 0x124 | R | — | pointer to per-plane descriptor array |
| this | 0x168 | R | — | range start index (inclusive lower bound for table fill loop) |
| this | 0x16C | R | — | range end index (inclusive upper bound for table fill loop) |
| this | 0x170 | R | — | mode flag: 0 = bitstream path, non-zero = visibility path |
| this | 0x174 | R | — | value to write into table entries across the range |
| this | 0x194 | R | — | pointer to decoder output configuration object (v21) |
| this | 0x198 | RW | — | per-plane decode state/context field |
| this | 0x1A4 | RW | 0 | per-plane decode output parameter slot A |
| this | 0x1A8 | RW | 0 | per-plane decode output parameter slot B |
| this | 0x1AC | RW | 0 | per-plane decode result field |
| this | 0x1B4 | RW | 0 | decoder callback state flag |
| this | 0x1B8 | RW | 0 | decoder output buffer pointer |
| this | 0x1C8 | RW | — | decode completion timestamp or counter |
| this | 0x1DC | RW | — | final decoded value or status code |

**Written-by note (persistence):**
- obj 0x14: conditional — written only on validation error, external poke does NOT survive next setup
- obj 0x18: conditional — written only on validation error, external poke does NOT survive next setup
- obj 0x1C: conditional — written only on validation error, external poke does NOT survive next setup
- obj 0x20: conditional — written only on validation error, external poke does NOT survive next setup
- obj 0x24: conditional — written only on validation error, external poke does NOT survive next setup
- this 0x198: conditional — written during plane decode setup, external poke does NOT survive next call
- this 0x1A4: once per setup — zeroed at end of processing (via v21+0x10=0), external poke does NOT survive
- this 0x1A8: once per setup — zeroed at end (via v21+0x14=0), external poke does NOT survive
- this 0x1AC: once per setup — zeroed at end, external poke does NOT survive
- this 0x1B4: once per setup — zeroed at end (via v21+0x20=0), external poke does NOT survive
- this 0x1B8: once per setup — zeroed at end, external poke does NOT survive
- this 0x1C8: once per setup — written with result value at end, external poke does NOT survive
- this 0x1DC: once per setup — zeroed at end (via v21+0x18=0), external poke does NOT survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0051af57 | BitstreamDecoder | R | decoder callback for mode=0 + bitstream-absent path |
| 0051b154 | sub_51B154 | R | decoder callback for mode=0 + bitstream-present path |
| 0051b37d | PlaneVisibilityTestWithBitfieldOutput | R | decoder callback for mode≠0 + bitstream-absent path |
| 0051b45f | sub_51B45F | R | decoder callback for mode≠0 + bitstream-present path |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0051a5ea | sub_51A5EA | initialize per-plane decode parameters and copy table entry to output buffer |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x120 | == | 1 | plane count check — used to determine v5 (a1[91]==0) vs normal range comparison |
| this | 0x120 | > | 0 | plane count > 0 → enters per-plane processing loop |
| this | 0x16C | == | 0 | range end is zero — validation flag for mismatched range bounds |
| this | 0x174 | > | 13 | set value exceeds max allowed (13) → BLOCKED (error flag set) |

**Guard interpretation:**
- this+0x120 (plane count) == 0 → no planes to process, skips loops
- this+0x120 == 1 AND this+0x16C (range end) == 0 → special single-plane path
- this+0x174 > 13 → BLOCKED: validation error; writes error code 14 to obj and dispatches via vtable
- Range mismatch (a1[90] > a1[91] or a1[91] ≥ 64) → BLOCKED: validation error
- a1[92] (mode) present but a1[93] != a1[92] - 1 → BLOCKED: validation error
- Table entry negative (< 0) before fill → BLOCKED: decode mismatch error 111, dispatches via vtable with a2=-1
- Table entry != mode flag before fill → BLOCKED: decode mismatch error 111, dispatches with a2=-1
