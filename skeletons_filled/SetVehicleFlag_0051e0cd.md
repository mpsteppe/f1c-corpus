## SetVehicleFlag_0051e0cd — SetVehicleDirtyFlag

**Summary:** Sets the initialization/dirty flag at context offset 0x1C to 1, indicating render state needs refresh.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1A4) | 0x1C | RW | 1 | dirty/init flag (set to 1 to signal render state change) |
| this | 0x1A4 | R | — | context pointer |

**Written-by note (persistence):**
- *(this+0x1A4) 0x1C: set to 1 unconditionally; survives until cleared by VehicleUpdateFrameSetup

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — always sets flag unconditionally.
