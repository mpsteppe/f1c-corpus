## sub_5FCA00_005fca00 — Lock first buffer, cache its CPU data pointer

**Summary:** Ensures the first buffer/stream object (this[0x40]+44) is filled/locked via the global manager's vtable slot 412 and caches the CPU-side pointer exposed at buffer+0x4C into this+0x44, setting the 0x100000 "locked" flag on success. If the buffer is missing, the manager's byte at +4813 is set, the flag is already set, or the buffer's status byte reports not-ready, this+0x44 is reset to 0.

**Called by:** sub_5FCE80 (005fce80), sub_5FD150 (005fd150)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x6C) | 0x0 | R | — | Status byte of the buffer object (first byte); its sign is tested — negative means the lock/fill reported ready |
| *(this+0x6C) | 0x4C | R | — | CPU-side data pointer inside the buffer (offset 76), cached into this+0x44 on successful lock |
| this | 0x0 | RW | — | Flag word; 0x100000 marks "buffer locked/valid" and is OR-set on success |
| this | 0x40 | R | — | Pointer (this[16]) to the object owning the buffer slot at +44 and the fill parameters at +8/+52 |
| this | 0x44 | RW | 0 | Cached locked data pointer (this[17]); reset to 0 when unavailable, set to buffer+0x4C when locked |
| this | 0x48 | R | — | Size/buffer parameter read as `*(this[16]+8)` and passed as third argument of the fill call |
| this | 0x6C | R | — | The first buffer/stream object (this[16]+44) that is filled/locked through the manager |
| this | 0x74 | R | — | Offset parameter read as `*(this[16]+52)` and passed as second argument of the fill call |

**Written-by note (persistence):**
- this 0x0: 0x100000 is conditionally OR-set once, on the first successful lock (the lock call itself is skipped while the bit is set); the bit persists across calls until cleared elsewhere — an external poke clearing it forces a re-lock attempt on the next call.
- this 0x44: recalculated on every call — set to 0 when the buffer is absent/disabled/not-ready, set to the locked pointer on success; an external poke is overwritten the next time this runs.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00fb27a4 | dword_FB27A4 | R | Global buffer/device manager: vtable slot 412 performs the fill/lock (buffer, offset, size, a2); byte at +4813 acts as a global disable/reset switch that forces this+0x44 to 0 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0x6C) | 0x0 | >= | 0 | Buffer status byte; non-negative (sign bit clear) means lock/ready NOT confirmed |

**Guard interpretation:** BLOCKED paths: if the buffer pointer (this[16]+44) is null, or the manager byte at +4813 is nonzero, this+0x44 is simply reset to 0 and no lock call is made. The lock call (slot 412) is skipped entirely while `(*this & 0x100000)` is set — that flag means a previous lock already succeeded. After the call, the status byte at buffer+0x0 is tested: >= 0 (sign clear) BLOCKS the pointer cache — this+0x44 is reset to 0 and the flag stays clear; only a negative status byte PASSES: buffer+0x4C is cached into this+0x44 and 0x100000 is OR-set into the flag word.
