## VehicleStructFieldCopy_0051bfa6 — Vehicle parameter struct copy

**Summary:** Copies two dimension/size values (at offsets 0x110 and 0x60) from the main struct into a target sub-struct pointed to by offset 0x19C. Unconditional field-level copy within a vehicle or physics system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x60 | R | — | Source value dimension/parameter — copied to target sub-struct offset 0x60 |
| this | 0x110 | R | — | Source value dimension/parameter — copied to target sub-struct offset 0x5C |
| this | 0x19C | R | — | Pointer to target sub-struct receiving the copied values |
| this | 0x1F8 | RW | — | Target sub-struct field at offset 0x5C — written with value from offset 0x110 |
| this | 0x1FC | RW | — | Target sub-struct field at offset 0x60 — written with value from offset 0x60 |

**Written-by note (persistence):**
- this 0x1F8: Written unconditionally each call. Survives external pokes.
- this 0x1FC: Written unconditionally each call. Survives external pokes.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guards — unconditional field copy. Always executes both writes.
