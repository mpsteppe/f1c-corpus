## AudioSampleStream_0051cd53 — Audio sample stream with buffered partial read

**Summary:** Streams audio samples from input to output with a single-sample buffer for handling partial reads. When a pending sample is buffered (flag set), flushes it first via block copy. Otherwise reads 1-2 samples, stores partial reads for next call, and dispatches via function pointer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x19C) | 0xC | R | — | v7[3]: Function pointer — called on v12 (sample pair) for each stream operation |
| *(this+0x19C) | 0x20 | R | — | v7[8]: Pending sample buffer — stores first sample when only 1 is available |
| *(this+0x19C) | 0x24 | RW | 1 | v7[9]: Pending flag byte — 0 = no pending data, non-zero = buffered sample exists |
| *(this+0x19C) | 0x28 | R | — | v7[10]: Block copy size — passed to F_2DArrayBlockCopy for buffered flush |
| *(this+0x19C) | 0x2C | RW | — | v7[11]: Remaining sample count — decremented as samples are processed |
| this | 0x19C | R | — | Pointer to audio stream sub-struct (v7) |

**Written-by note (persistence):**
- *(this+0x19C) 0x24: Toggled between 0 and 1 as samples are buffered/flushed. External pokes survive but affect behavior next call.
- *(this+0x19C) 0x2C: Decremented by v9 each call. External pokes survive but change remaining count.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0051593f | F_2DArrayBlockCopy | Copies buffered sample data to output when pending flag is set |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0x19C) | 0x2C | < | 2 | Remaining sample count — if <2, clamp copy count to available samples |

**Guard interpretation:** Pending flag guard (line 13): if byte at v7+36 != 0, flush buffered sample via F_2DArrayBlockCopy and clear flag. If 0, read fresh samples — default 2, clamped to min(remaining, output space). If remaining < 2, v9 = remaining (may be 1), triggering partial read: store sample in v7+32, set flag=1. On full 2-sample read, no buffering. After processing: if flag still 0, advance source pointer *a3.
