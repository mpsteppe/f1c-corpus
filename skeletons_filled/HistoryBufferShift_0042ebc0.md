## HistoryBufferShift_0042ebc0 — HistoryBufferShift

**Summary:** Shifts a history buffer by one position (FIFO shift). Copies each element over the next, discarding the oldest entry. Operates on two separate buffer regions within the struct.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ValidateVehicleConfigurationFile (00433ed0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC8 | RW | — | Start of first history buffer (4 groups × 11 elements × 16 bytes) |
| this | 0xBC8 | RW | — | Start of second history buffer (55 elements × 16 bytes) |

**Written-by note (persistence):**
- this 0xC8: All entries at 0xC8+16*N overwritten with previous entry each call. Repeated shift erases oldest data.
- this 0xBC8: All entries at 0xBC8+16*N overwritten with previous entry each call. Repeated shift erases oldest data.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard — always shifts all elements unconditionally.
