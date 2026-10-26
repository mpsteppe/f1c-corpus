## sub_5FCBD0_005fcbd0 — Reset or resize the active record list

**Summary:** List-length control: with a2 == 0 it clears the queued bit and sequence number of every record (stride 132) and zeroes the count; with a2 != 0 it first removes all queued records via sub_5FCB20, then re-registers records 0..min(a2, capacity)-1 (negative a2 clamps to 0), assigning them fresh sequence numbers and buffer offsets.

**Called by:** sub_5FDB10 (005fdb10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24 | R | — | Element size multiplier (this[9]) used in the 64-byte-scaled offset formula during re-registration |
| this | 0x2C | RW | — | Capacity (this[11]): clamp bound for a2 and the bound for both loops; no store to it is visible in the decompiled body |
| this | 0x30 | RW | 0 | Count (this[12]): set to 0 in reset mode, incremented per re-registered record |
| this | 0x34 | R | — | Base of the 132-byte record array (this[13]) iterated in both modes |
| this | 0x38 | R | — | List array (this[14]) receiving record pointers during re-registration |
| this | 0x60 | R | — | Data base (this[24]) used in the re-registration offset computation |
| this | 0xAC | RW | — | unknown — no direct access visible in this listing; may be affected only through helper behavior |

**Written-by note (persistence):**
- this 0x2C: unknown — the extractor classifies it RW, but only reads (clamp bound / loop bounds) appear in the decompiled body; no store to this+0x2C is visible here.
- this 0x30: written in both modes — reset mode stores 0 directly; resize mode rebuilds it via removals in sub_5FCB20 and the per-record increments, so after any call with a2 != 0 the value always ends at the number of successfully re-registered records; an external poke is overwritten on the next call.
- this 0xAC: unknown — no write to this+0xAC is visible in the decompiled body; nothing in this function demonstrably touches it.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005fcb20 | sub_5FCB20 | Removes a queued record (swap-with-last compaction); called once per index to empty the list before re-registration |

**Guard conditions:** If a2 == 0 the clear-all branch runs: every record (count = this[11] iterations, stride 132) gets record+4 = 0 and bit 0x100 cleared, then the count is set to 0. If a2 != 0 the resize branch runs: negative a2 clamps v2 to 0 (nothing re-added); a2 above capacity clamps to this[11]. The removal sweep calls sub_5FCB20(this, i) for i = 0..this[11]-1. The re-add loop runs only while v11 < v2 and, inside, only when the count is below capacity and the record's 0x100 bit is clear (already-queued records are skipped); records ready for queueing get sequence number, offset, list slot, and the 0x100 bit set.
