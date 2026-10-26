## ScreenDataStructInit_0047f370 — ScreenDataTextureManagerCtor

**Summary:** Initializes a ScreenData struct: zeros large region via helper, sets vtable to TextureManagerVTable, initializes three min/max range pairs to (0, -1) sentinel values, and clears texture-related data sections.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_485B90 (00485b90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer set to TextureManagerVTable |
| this | 0x210C | RW | 0 | flag/byte field cleared to 0 |
| this | 0x218C | RW | 0 | min value of first range pair (0 = default minimum) |
| this | 0x2190 | RW | 18446744073709551615 | max value of first range pair (-1 / UINT64_MAX) |
| this | 0x2194 | RW | 0 | min value of second range pair |
| this | 0x2198 | RW | 18446744073709551615 | max value of second range pair |
| this | 0x219C | RW | 0 | min value of third range pair |
| this | 0x21A0 | RW | 18446744073709551615 | max value of third range pair |

**Written-by note (persistence):**
- this 0x0: once at init; persists as vtable for object lifetime
- this 0x210C: once at init; persists unless external code modifies
- this 0x218C: once at init; persists unless external code modifies
- this 0x2190: once at init; persists unless external code modifies
- this 0x2194: once at init; persists unless external code modifies
- this 0x2198: once at init; persists unless external code modifies
- this 0x219C: once at init; persists unless external code modifies
- this 0x21A0: once at init; persists unless external code modifies

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a6e70 | off_5A6E70 | R | TextureManagerVTable [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00495190 | LargeStructZeroInit | zeros the initial region of this struct (likely memset 0) |

**Guard conditions:** none — function always executes fully with no conditional early returns.
