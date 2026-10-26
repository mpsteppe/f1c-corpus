## AudioStreamBufferFill_00519720 — AudioStreamBufferFill

**Summary:** Fills audio/stream buffer using a 3-state machine (init, write, flush). Manages double-buffering with XOR toggle, tracks write cycles, and dispatches per-index buffer copy when cycle completes. Part of streaming output system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x114 | R | — | buffer size limit (frame dimension) |
| this | 0x118 | R | — | write cycle limit for triggering array processing |
| this | 0x180 | R | — | pointer to buffer descriptor struct (v4 base) |
| this | 0x184 | R | — | buffer descriptor +4 |
| this | 0x188 | R | — | buffer descriptor +8 |
| this | 0x18C | R | — | buffer descriptor +12 |
| this | 0x190 | R | — | buffer descriptor +16 |
| this | 0x1B0 | RW | 0 | buffer descriptor offset 0x30 (initialized flag) |
| this | 0x1B4 | RW | 0 | buffer descriptor offset 0x34 (fill position) |
| this | 0x1C0 | RW | — | buffer descriptor offset 0x40 (output row size / write target) |
| this | 0x1C4 | RW | 2 | buffer descriptor offset 0x44 (state: 0=init, 1=write, 2=flush) |
| this | 0x1C8 | RW | — | buffer descriptor offset 0x48 (write cycle counter) |
| this | 0x1CC | R | — | buffer descriptor offset 0x4C (write cycle limit) |

**Written-by note (persistence):**
- this 0x1B0: reset to 0 on buffer full; external poke toggles ready state
- this 0x1B4: updated with each write; external poke corrupts position
- this 0x1C0: updated when buffer fills; external poke corrupts target size
- this 0x1C4: updated through state transitions; external poke corrupts state machine
- this 0x1C8: incremented each write cycle; external poke corrupts cycle count

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0051954e | PerIndexBufferCopyWithInterleavedOffset | copy interleaved data when write cycle completes |
| 00519622 | ArrayProcessingWithScaling | process array scaling on first write cycle reaching limit |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1CC | == | 1 | write cycle limit equals 1 |

**Guard interpretation:** If write cycle counter (v4+76) equals cycle limit (this->0x1CC == 1, PASSES), triggers ArrayProcessingWithScaling during state 0. State machine: state 0 initializes buffer position and target size, then transitions to state 1; state 1 writes data via vtable, and when position reaches target, toggles double-buffer (XOR 1 on v4+64) and transitions to state 2; state 2 flushes remaining data and resets to state 0 when all data consumed.
