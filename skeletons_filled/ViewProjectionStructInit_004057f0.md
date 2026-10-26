## ViewProjectionStructInit_004057f0 — AudioProcessingConfigInit

**Summary:** Initializes audio processing configuration struct with Miles Sound System vtable, sets sample rate (44100 Hz), volume/pan factors (0.5, 0.975, 0.01), copies file path string from caller parameter (or default path), and zeroes state/sentinel fields.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LinkedListNodeInsertWithAllocation (00407810)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | VTable pointer (Object VTable_59E490) |
| this | 0x4 | RW | 0 | Counter/index field, zeroed on init |
| this | 0x8 | RW | 18446744073709551615 | Sentinel/key field, set to -1 |
| this | 0xC | RW | — | Copied from caller parameter a2+8 (config data) |
| this | 0x10 | RW | — | Copied from caller parameter a2+12 (config data) |
| this | 0x14 | RW | — | Copied from caller parameter a3 (config data) |
| this | 0x18 | RW | — | Copied from caller parameter a4 (config data) |
| this | 0x1C | RW | 1008981770 → 0.01f | Audio gain/threshold factor |
| this | 0x20 | RW | 1064933786 → 0.975f | Audio decay/smoothing factor |
| this | 0x24 | RW | 1056964608 → 0.5f | Audio pan/balance center value |
| this | 0x44 | RW | 1194083328 → 44100.0f | Audio sample rate (44100 Hz) |
| this | 0x4C | RW | 0 | State/flag, zeroed on init |
| this | 0x54 | RW | — | Copied from caller parameter a5 (config data) |
| this | 0x58 | RW | 0 | State/counter field, zeroed on init |
| this | 0x5C | RW | 0 | State/handle field, zeroed on init |
| this | 0x60 | RW | 18446744073709551615 | Sentinel/key field, set to -1 |
| this | 0x64 | RW | 0 | State field, zeroed on init |
| this | 0x68 | RW | 0 | State field, zeroed on init |

**Written-by note (persistence):**
- this 0x0: once (vtable set, survives unless swapped)
- this 0x4: once (zeroed, survives unless overwritten)
- this 0x8: once (-1 sentinel, survives unless overwritten)
- this 0xC: once (copied from param, survives unless overwritten)
- this 0x10: once (copied from param, survives unless overwritten)
- this 0x14: once (copied from param, survives unless overwritten)
- this 0x18: once (copied from param, survives unless overwritten)
- this 0x1C: once (0.01f constant, survives unless overwritten)
- this 0x20: once (0.975f constant, survives unless overwritten)
- this 0x24: once (0.5f constant, survives unless overwritten)
- this 0x44: once (44100.0f constant, survives unless overwritten)
- this 0x4C: once (zeroed, survives unless overwritten)
- this 0x54: once (copied from param, survives unless overwritten)
- this 0x58: once (zeroed, survives unless overwritten)
- this 0x5C: once (zeroed, survives unless overwritten)
- this 0x60: once (-1 sentinel, survives unless overwritten)
- this 0x64: once (zeroed, survives unless overwritten)
- this 0x68: once (zeroed, survives unless overwritten)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e490 | off_59E490 | R | VTable_Object_59E490 [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566650 | StringCopyWithBufferRealloc | Copy audio file path string from parameter or default |

**Guard conditions:** Checks if `*(_DWORD *)a2` (first DWORD of parameter a2) is zero. If zero (null/empty path), falls back to `byte_5EA438` (default application directory) as the file path. No early return/block — only affects which string pointer is passed to StringCopyWithBufferRealloc.
