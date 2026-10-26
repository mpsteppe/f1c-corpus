## TextFormatStructInitializer_4fe0_00414fe0 — TextFormatStructInitializer_4fe0

**Summary:** Resets a smaller text format struct variant by setting groups of fields (DWORD/DWORD/BYTE triples) to -1/-1/0 across 3 slots plus 2 extra trailing slots, interleaved with global path string reinitialization via StringCopyWithBufferRealloc.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MultiPointerFree (00414420), DrawableResourceCleanup (004150c0), SceneListBuilderFromGlobalArray (00415c40), ShortComputation_8cf0 (00418cf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | 18446744073709551615 | Slot 0 — single position field pair 1 (reset to -1) |
| this | 0xC | RW | 18446744073709551615 | Slot 0 — single position field pair 2 (reset to -1) |
| this | 0x10 | RW | 0 | Slot 0 — flags/active byte (cleared to 0) |
| this | 0x14 | RW | 18446744073709551615 | Slot 1 — position/x field (reset to -1) |
| this | 0x18 | RW | 18446744073709551615 | Slot 1 — position/y field (reset to -1) |
| this | 0x1C | RW | 0 | Slot 1 — flags/active byte (cleared to 0) |
| this | 0x28 | RW | 18446744073709551615 | Slot 2 — position/x field (reset to -1) |
| this | 0x2C | RW | 18446744073709551615 | Slot 2 — position/y field (reset to -1) |
| this | 0x30 | RW | 0 | Slot 2 — flags/active byte (cleared to 0) |
| this | 0x3C | RW | 18446744073709551615 | Slot 3 — position/x field (reset to -1) |
| this | 0x40 | RW | 18446744073709551615 | Slot 3 — position/y field (reset to -1) |
| this | 0x44 | RW | 0 | Slot 3 — flags/active byte (cleared to 0) |

**Written-by note (persistence):**
- this 0x8: unconditional; reset to -1 on each call
- this 0xC: unconditional; reset to -1 on each call
- this 0x10: unconditional; cleared to 0 on each call
- this 0x14: unconditional; reset to -1 on each call
- this 0x18: unconditional; reset to -1 on each call
- this 0x1C: unconditional; cleared to 0 on each call
- this 0x28: unconditional; reset to -1 on each call
- this 0x2C: unconditional; reset to -1 on each call
- this 0x30: unconditional; cleared to 0 on each call
- this 0x3C: unconditional; reset to -1 on each call
- this 0x40: unconditional; reset to -1 on each call
- this 0x44: unconditional; cleared to 0 on each call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566650 | StringCopyWithBufferRealloc | Called 5 times to reinitialize the global path string buffer between slot resets |

**Guard conditions:** No guard conditions — always executes fully. All writes are unconditional.
