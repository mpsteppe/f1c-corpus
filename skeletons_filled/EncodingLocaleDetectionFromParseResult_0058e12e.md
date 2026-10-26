## EncodingLocaleDetectionFromParseResult_0058e12e — Locale/code page encoding detection

**Summary:** Parses a locale or encoding string to detect code page and encoding flags. Returns bitmask flags (0x80=ANSI/SBCS, 0x100=Unicode/DBCS?, 0x200=OEM), a double parameter, and byte count consumed. Used during CRT locale initialization.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_58850F (0058850f), sub_58B077 (0058b077)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Encoding flags (0x80/0x100/0x200) |
| this | 0x4 | RW | — | Byte count consumed from input string |
| this | 0x10 | RW | — | Double value from locale encoding parameter |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist
- this 0x4: recalc every frame — external poke does NOT persist
- this 0x10: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00595524 | StringParseViaDelegate | Parse numeric double value from locale string representation |
| 00596245 | sub_596245 | Initial locale string parse returning format classification flags |

**Guard conditions:** If parse result has bit 2 (0x04) set, encoding is OEM code page (0x200). Otherwise, checks bit 1 (0x02) or parse return==1 for ANSI (0x80); checks bit 0 (0x01) or parse return==2 for Unicode/DBCS (0x100). Results ORed together for combined encoding.
