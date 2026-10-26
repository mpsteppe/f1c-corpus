## ProgressBarDataStore_004d2260 — Store two values to progress bar ring buffer

**Summary:** Encodes a progress bar event (type 21, subtype 8) with two custom data values (a1, a2) plus current session time to the ring buffer. Used for logging paired integer data to the replay/progress system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4D4580 (004d4580)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0083ee60 | dword_83EE60 | RW | RingBufferCount — counter for ring buffer entries |
| 008aae64 | dword_8AAE64 | RW | RingBufferWritePtr — current write position in ring buffer |
| 008afea0 | dbl_8AFEA0 | R | SessionTime — timestamp for progress bar event |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b33b0 | ProgressBarEventEncode | Encodes event header (type 21, subtype 8) into ring buffer |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| dword_83EE60 | — | < | 1023 | Ring buffer capacity check |

**Guard interpretation:** If ring buffer count < 1023 (not full), increment count and advance write pointer by 432 bytes. Always writes event data (even if counter not incremented) — the event is written at the current write position regardless.
