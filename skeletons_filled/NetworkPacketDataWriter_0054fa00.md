## NetworkPacketDataWriter_0054fa00 — NetworkPacketDataEntryWriter

**Summary:** Writes 6 data fields from a source struct into a specific entry slot of a network/communication packet buffer array, marking the entry as dirty (bit 3).

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsVelocityAngularVelocityIntegrator (00459ae0), VehicleOrientationMatrixConstruction (0045b050), VehicleBodyToWheelContactDistanceComputation (004e9a40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1E0 | R | — | pointer to packet buffer descriptor (count at +4, data at +8) |
| this | 0x1E4 | R | — | element count limit from descriptor |
| this | 0x1E8 | R | — | pointer to packet data array from descriptor |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If data pointer (from *(this+0x1E0)+8) is null OR index a3 >= element count (from *(this+0x1E0)+4) → skip write, return 0 (BLOCKED). PASSES: data pointer non-null AND index within bounds.
