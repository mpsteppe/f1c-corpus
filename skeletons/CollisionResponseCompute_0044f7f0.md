## CollisionResponseCompute_0044f7f0 — Compute collision force feedback response

**Summary:** Queries a device/force-feedback object at offset 0x80 for range data via vtable call, then computes collision response parameters: output range bounds, center value, inverse range values for mapping. Called from texture stage setup path.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** D3DTextureStage (0044f8f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x80) | 0x14 | R | — | Vtable offset 0x14 (5th method) — device/IOCTL query for range data |
| this | 0x80 | R | — | Pointer to device/force-feedback object |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|------|

**Guard conditions:** BLOCKED if this[32] (offset 0x80 device pointer) is zero → skip all response computation. PASSES only with valid device pointer.
