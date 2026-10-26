## sub_5FCA80_005fca80 — Unlock first buffer, clear cached pointer

**Summary:** Unlock counterpart of the buffer-lock sequence: if the 0x100000 lock flag is set, it calls the global manager's vtable slot 416 to unlock the first buffer (this[0x40]+44) passing a2, then clears the 0x100000 bit and zeroes the cached data pointer at this+0x44. Returns the updated flag word.

**Called by:** sub_5FD150 (005fd150)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Flag word; 0x100000 (buffer-locked) is cleared here via `*this & 0xFFEFFFFF` |
| this | 0x40 | R | — | Pointer (this[16]) to the object owning the buffer slot at +44 |
| this | 0x44 | RW | 0 | Cached locked data pointer (this[17]); zeroed when the buffer is unlocked |
| this | 0x6C | R | — | The first buffer/stream object (this[16]+44) passed to the unlock call |

**Written-by note (persistence):**
- this 0x0: the 0x100000 bit is conditionally cleared in a single masked write, only when it was set; an external poke setting it without a real lock would make the next call attempt an unlock and clear it again.
- this 0x44: written to 0 only when the flag was set; an external poke survives only until the next call that finds 0x100000 set.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00fb27a4 | dword_FB27A4 | R | Global buffer/device manager: vtable slot 416 unlocks the buffer (manager, buffer object, a2) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Single gate: `(*this & 0x100000) != 0`. PASS (lock flag set): the unlock call fires, the flag bit is cleared, and this+0x44 is zeroed. BLOCKED (flag clear): nothing happens — no call, no writes; the function simply returns whatever is left in the result register (undefined in the decompilation).
