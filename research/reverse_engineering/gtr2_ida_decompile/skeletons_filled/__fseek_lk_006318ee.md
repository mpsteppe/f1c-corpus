## __fseek_lk_006318ee — CRT _fseek_lk (locked fseek core)

**Summary:** MSVC CRT internal `_fseek_lk`: validates and performs a seek on a FILE stream — converts SEEK_CUR to an absolute offset via `_ftell_lk`, flushes buffered data, adjusts stream state flags, and calls the low-level `_lseek`. Returns 0 on success, -1 on failure.

**Called by:** _fseek (0063197d)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | RW | — | FILE `_flag` word: read to validate the stream is open (0x83 mask), EOF bit 0x10 cleared on a successful seek, direction bits 0x3 cleared when 0x80 (update) is set |
| this | 0x10 | R | — | FILE `_file` field: OS file descriptor passed to `_lseek` |
| this | 0x18 | RW | 512 | FILE `_bufsiz` field: reset to 512 when the stream is read-capable, buffered, and not already in the excluded mode |

**Written-by note (persistence):**
- this 0xC: conditionally rewritten on each call (EOF/update-flag adjustments); next fseek/read on the stream will overwrite them again.
- this 0x18: written only under the flag combination (0x1 & 0x8 set, 0x400 clear); external poke to _bufsiz survives until the next such fseek.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006341be | __ftell_lk | Returns the current stream position (used to resolve SEEK_CUR relative offsets) |
| 00634487 | __flush | Flushes/discards buffered stream data before the seek so the underlying fd position is authoritative |
| 006351e0 | __errno | Returns pointer to the thread-local errno; set to 22 (EINVAL) on invalid arguments |
| 00637d9e | __lseek | Low-level OS seek on the stream's file descriptor; -1 indicates failure |

**Guard conditions:** Entry requires `(a1[3] & 0x83) != 0` (stream open for read, write, or update — any of bits 0x1/0x2/0x80) AND `Origin <= 2` (SEEK_SET=0, SEEK_CUR=1, SEEK_END=2; unsigned compare also rejects negative origins). Otherwise errno = 22 (EINVAL) and return -1 — BLOCKED. On the valid path: EOF bit 0x10 cleared from _flag; Origin==1 adds `_ftell_lk` and switches to absolute mode (v4=0); `_flush` runs; if flag 0x80 (update) set, bits 0x3 are cleared, else if flags 0x1|0x8 set and 0x400 clear, _bufsiz = 512. Final `_lseek(fd, Offset, v4)` — return is 0 if lseek succeeded, -1 if it failed.
