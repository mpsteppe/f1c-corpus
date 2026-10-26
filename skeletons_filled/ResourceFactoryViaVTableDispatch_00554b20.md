## ResourceFactoryViaVTableDispatch_00554b20 — ResourceFactoryViaVTableDispatch

**Summary:** Creates or configures a resource via virtual dispatch on device object. Extracts parameters via sub_5424E0, conditionally clips render region, then dispatches to vtable+144 with format/mode selected by a2 byte flags.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_5550E0 (005550e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1100) | 0x90 | R | — | Virtual dispatch via vtable+144 on device object |
| this | 0x0 | RW | — | Result / handle from resource creation |
| this | 0x1100 | R | — | Pointer to device object (this[1088]) |
| this | 0x1528 | R | — | ClippedRenderRegion parameter (this[1354]) |

**Written-by note (persistence):**
- this 0x0: Updated from dispatch return; external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005424e0 | sub_5424E0 | Extracts resource parameters (coordinates, dimensions) from a2 |
| 00543250 | ClippedRenderRegion | Clips render region to bounds; only called when a2+416 pointer is non-null and a3 is zero |

**Guard conditions:** If a3 is non-null → skips ClippedRenderRegion, goes straight to vtable+144 dispatch with mode 2. If a2+416 pointer is null → also skips clipping. Byte flag at a2+128 bit 1 selects mode 3 (with a2[124] as param) vs mode 2.
