## LargeTableCopyFromROMData_005317c0 — ROM-to-RAM table copy (interleaved)

**Summary:** Copies two audio/DCT lookup tables from ROM (unk_5B6F0C, unk_5B730C) into runtime buffer unk_8B1924 with interleaved 32-byte stride pattern. Initializes AudioWavetableBuffer from ROM data.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b6f0c | unk_5B6F0C | R | DCT_LookupTableA [DERIVED] — source DCT coefficient table A |
| 005b730c | unk_5B730C | R | AudioDSPTable [DERIVED] — source audio DSP coefficient table |
| 008b1924 | unk_8B1924 | R | AudioWavetableBuffer [DERIVED] — destination runtime wavetable buffer |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b0170 | EmptyStub_0170 | no-op stub (likely debug/placeholder) |

**Guard conditions:** No branches. Always copies both tables unconditionally.
