## TextFormatStructInitializer_004149a0 — TextFormatStructInitializer

**Summary:** Resets a text format struct by setting groups of fields (DWORD/DWORD/BYTE triples) to -1/-1/0 across 8 named slots plus 2 extra trailing slots, interleaved with global path string reinitialization via StringCopyWithBufferRealloc.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GlobalListTripleCleanupWithTimerRemoval (00414210), sub_414600 (00414600), DrawableResourceCleanup (004150c0), NamedEntryLookupInFormatList (00415230), VehicleListBuilderFromGlobalArray (00415780), StructDestructor (00415900)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | 18446744073709551615 | Slot 0 — position/x field (reset to -1) |
| this | 0xC | RW | 18446744073709551615 | Slot 0 — position/y field (reset to -1) |
| this | 0x10 | RW | 0 | Slot 0 — flags/active byte (cleared to 0) |
| this | 0x18 | RW | 18446744073709551615 | Slot 1 — position/x field (reset to -1) |
| this | 0x1C | RW | 18446744073709551615 | Slot 1 — position/y field (reset to -1) |
| this | 0x20 | RW | 0 | Slot 1 — flags/active byte (cleared to 0) |
| this | 0x2C | RW | 18446744073709551615 | Slot 2 — position/x field (reset to -1) |
| this | 0x30 | RW | 18446744073709551615 | Slot 2 — position/y field (reset to -1) |
| this | 0x34 | RW | 0 | Slot 2 — flags/active byte (cleared to 0) |
| this | 0x40 | RW | 18446744073709551615 | Slot 3 — position/x field (reset to -1) |
| this | 0x44 | RW | 18446744073709551615 | Slot 3 — position/y field (reset to -1) |
| this | 0x48 | RW | 0 | Slot 3 — flags/active byte (cleared to 0) |
| this | 0x54 | RW | 18446744073709551615 | Slot 4 — position/x field (reset to -1) |
| this | 0x58 | RW | 18446744073709551615 | Slot 4 — position/y field (reset to -1) |
| this | 0x5C | RW | 0 | Slot 4 — flags/active byte (cleared to 0) |
| this | 0x68 | RW | 18446744073709551615 | Slot 5 — position/x field (reset to -1) |
| this | 0x6C | RW | 18446744073709551615 | Slot 5 — position/y field (reset to -1) |
| this | 0x70 | RW | 0 | Slot 5 — flags/active byte (cleared to 0) |
| this | 0x7C | RW | 18446744073709551615 | Slot 6 — position/x field (reset to -1) |
| this | 0x80 | RW | 18446744073709551615 | Slot 6 — position/y field (reset to -1) |
| this | 0x84 | RW | 0 | Slot 6 — flags/active byte (cleared to 0) |
| this | 0x90 | RW | 18446744073709551615 | Slot 7 — position/x field (reset to -1) |
| this | 0x94 | RW | 18446744073709551615 | Slot 7 — position/y field (reset to -1) |
| this | 0x98 | RW | 0 | Slot 7 — flags/active byte (cleared to 0) |

**Written-by note (persistence):**
- this 0x8: unconditional; reset to -1 on each call
- this 0xC: unconditional; reset to -1 on each call
- this 0x10: unconditional; cleared to 0 on each call
- this 0x18: unconditional; reset to -1 on each call
- this 0x1C: unconditional; reset to -1 on each call
- this 0x20: unconditional; cleared to 0 on each call
- this 0x2C: unconditional; reset to -1 on each call
- this 0x30: unconditional; reset to -1 on each call
- this 0x34: unconditional; cleared to 0 on each call
- this 0x40: unconditional; reset to -1 on each call
- this 0x44: unconditional; reset to -1 on each call
- this 0x48: unconditional; cleared to 0 on each call
- this 0x54: unconditional; reset to -1 on each call
- this 0x58: unconditional; reset to -1 on each call
- this 0x5C: unconditional; cleared to 0 on each call
- this 0x68: unconditional; reset to -1 on each call
- this 0x6C: unconditional; reset to -1 on each call
- this 0x70: unconditional; cleared to 0 on each call
- this 0x7C: unconditional; reset to -1 on each call
- this 0x80: unconditional; reset to -1 on each call
- this 0x84: unconditional; cleared to 0 on each call
- this 0x90: unconditional; reset to -1 on each call
- this 0x94: unconditional; reset to -1 on each call
- this 0x98: unconditional; cleared to 0 on each call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566650 | StringCopyWithBufferRealloc | Called 10 times to reinitialize the global path string buffer between slot resets |

**Guard conditions:** No guard conditions — always executes fully. All writes are unconditional.
