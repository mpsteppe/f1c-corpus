## BufferedDataStreamWrite_005196b8 — BufferedDataStreamWrite

**Summary:** Writes data to a buffered stream. Initializes the buffer on first call, dispatches data write via vtable callback, tracks buffer fill level, and resets buffer when full. Part of buffered output stream system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x114 | R | — | buffer size limit (stride/frame dimension) |
| this | 0x180 | R | — | pointer to buffer descriptor struct (v4 base) |
| this | 0x184 | R | — | buffer descriptor +4 |
| this | 0x188 | R | — | buffer descriptor +8 |
| this | 0x18C | R | — | buffer descriptor +12 |
| this | 0x190 | R | — | buffer descriptor +16 |
| this | 0x1B0 | RW | 0 | buffer descriptor +48 (initialized flag) |
| this | 0x1B4 | RW | 0 | buffer descriptor +52 (fill position counter) |

**Written-by note (persistence):**
- this 0x1B0: set to 1 on first init, reset to 0 when buffer full; external poke toggles ready state
- this 0x1B4: incremented with each write, reset to 0 when full; external poke corrupts position

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If buffer initialized flag (0x1B0) is 0, calls vtable[97]+12 to initialize, sets flag to 1. If buffer fill position after write reaches limit (this->0x114), resets initialized flag and position to 0 for next cycle.
