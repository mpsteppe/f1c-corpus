## SmallEntryStructInit_00415520 — SmallEntryStructInit

**Summary:** Initializes a 20-byte small entry struct: sets first DWORD to 0, second to -1, calls StringCopyWithBufferRealloc to reinit the global path, sets next two DWORDS to -1/-1, and clears byte at offset 16 to 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NamedEntryLookupInFormatList (00415230), VehicleListBuilderFromGlobalArray (00415780), SceneListBuilderFromGlobalArray (00415c40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | Entry pointer/link field (cleared to 0/null) |
| this | 0x4 | RW | 18446744073709551615 | Entry ID/type field (reset to -1) |
| this | 0x8 | RW | 18446744073709551615 | Entry position/x field (reset to -1) |
| this | 0xC | RW | 18446744073709551615 | Entry position/y field (reset to -1) |
| this | 0x10 | RW | 0 | Entry flags/active byte (cleared to 0) |

**Written-by note (persistence):**
- this 0x0: unconditional; set to 0 on each call
- this 0x4: unconditional; set to -1 on each call
- this 0x8: unconditional; set to -1 on each call
- this 0xC: unconditional; set to -1 on each call
- this 0x10: unconditional; cleared to 0 on each call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | Default path string — reinitialized via StringCopyWithBufferRealloc |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566650 | StringCopyWithBufferRealloc | Reinitializes the global path string buffer as part of entry initialization |

**Guard conditions:** No guard conditions — always executes fully. All writes are unconditional.
