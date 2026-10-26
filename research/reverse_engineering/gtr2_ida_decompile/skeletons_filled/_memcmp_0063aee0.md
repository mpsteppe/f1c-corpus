## _memcmp_0063aee0 — Byte comparison (memcmp)

**Summary:** C runtime memory comparison with an alignment-aware fast path: compares aligned regions dword-wise, otherwise byte- or word-wise, and returns 0 on equality or a -1/+1 sign from the first differing byte.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | First byte of the compared region (used in the odd-size leading-byte test and the byte loop) |
| this | 0x1 | R | — | Second byte of the compared region (second byte of each pair in the two-byte loop) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00ff0000 | dword_FF0000 | R | Mask 0x00FF0000 applied to both compared dwords to isolate the third byte during the aligned-path mismatch resolution |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** `Size == 0` → return 0 immediately. If both buffers have the same 2-bit alignment (`(Buf1 | Buf2) & 3 == 0`) → dword-at-a-time loop; on a dword mismatch the first differing byte within the last compared dword sequence is located via the `(unsigned __int8)`/`BYTE1`/masked-HIWORD checks at offsets −4. On an all-equal run, the `Size & 3` remainder is compared byte by byte from the current position. If alignment differs: `Size` even → two-byte-at-a-time loop; `Size` odd → compare the single leading byte first, then the remaining even part in the two-byte loop. Every mismatch returns `-v6 - (v6 - 1)` — that is -1 when the Buf1 byte is less, +1 when greater; equality within Size returns 0.
