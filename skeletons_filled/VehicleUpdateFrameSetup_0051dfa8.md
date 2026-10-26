## VehicleUpdateFrameSetup_0051dfa8 — VehicleFrameUpdateSetup

**Summary:** Sets up rendering frame for vehicle display. Copies palette pointer from context to working slot, calls RenderBufferSetup with step size parameter, sets context dirty/init flag to 1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1A4) | 0x10 | R | — | palette data pointer (copied to working slot) |
| *(this+0x1A4) | 0x14 | R | — | render step size parameter |
| *(this+0x1A4) | 0x1C | RW | 1 | dirty/init flag set to 1 after setup |
| this | 0x74 | RW | — | working palette pointer (updated from context) |
| this | 0x1A4 | R | — | context pointer |

**Written-by note (persistence):**
- *(this+0x1A4) 0x1C: set to 1 once per call; survives until cleared externally
- this 0x74: set to palette pointer each call; survives until overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0051d80a | RenderBufferSetup | sets up render buffer with occupancy scan and centroid computation |

**Guard conditions:** none — function always executes unconditionally.
