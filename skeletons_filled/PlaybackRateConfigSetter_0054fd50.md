## PlaybackRateConfigSetter_0054fd50 — Mode selector with rate parameter

**Summary:** Sets a two-bit mode field (values 0, 4, or 8) at this+0x40 and a rate/value field at this+0x44 based on input parameters. Mode 8 uses a3 as the rate (with -1 sentinel for invalid input < 1); mode 4 uses a3 directly; default clears mode and sets rate to 1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DirectXMeshVertexBufferParsingAndLoading (00547b40), D3DTextureResourceCreation (00548190)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x40 | RW | — | Mode field; bits 2-3 encode mode (0=default, 4=mode1, 8=mode2) |
| this | 0x44 | RW | 1 | Rate/value parameter; set to a3 (or -1 if invalid, or 1 default) |

**Written-by note (persistence):**
- this 0x40: mode bits overwritten each call, other bits preserved via &= 0xFFFFFFF3
- this 0x44: unconditionally written each call; initialized to 1

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If a2 == 8, PASSES: mode=8 branch, rate guarded by a3 < 1 (sets -1). Else if a2 == 4, PASSES: mode=4 branch. Else (default), PASSES: clears mode bits, sets rate=1. No early return without writing both fields.
