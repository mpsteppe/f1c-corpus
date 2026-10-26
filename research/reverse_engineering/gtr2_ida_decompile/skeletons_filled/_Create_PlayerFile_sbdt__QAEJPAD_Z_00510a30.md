## ?Create@PlayerFile@sbdt@@QAEJPAD@Z_00510a30 — PlayerFile::Create

**Summary:** Creates an sbdt::PlayerFile for the player name in a2: formats the path "<root><name>\" (root from dword_91CB00, else WindowName) into this+20, then runs a fixed sequence of engine/file initialization calls, choosing a mode from bit 0 of byte_B6A7F4 and wiring global state. Returns -1 when a2 is null, otherwise 0.

**Called by:** sub_4AECB0 (004aecb0), sub_519B5D (00519b5d)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f16bc | WindowName | R | Fallback root path when dword_91CB00 is null, and fallback string when the BE1CDC-derived name is null |
| 00700948 | aSS_6 | R | Format string "%s%s\" used by sprintf to build the player path |
| 0091cb00 | dword_91CB00 | R | Root/base directory path prefix for the player file path; null selects WindowName |
| 00b66000 | dword_B66000 | R | Global passed by address to sub_437A90 |
| 00b6a7f4 | byte_B6A7F4 | R | Flag byte; bit 0 selects sub_50F6B0 mode 2 (set) vs 1 (clear) |
| 00be1bd4 | dword_BE1BD4 | R | Count/flag; when > 0 triggers the block that reads name strings from unk_BE1CDC |
| 00be1cd0 | dword_BE1CD0 | R | Count/flag; when > 0 triggers sub_53A160(this) |
| 00be1cdc | unk_BE1CDC | R | Structure passed to sub_538790; string at +0 and a second string at +1852 are stored via sub_615860 |
| 00be1cfd | unk_BE1CFD | R | unknown (not visible in the decompiled body) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041b2b0 | sub_41B2B0 | No-argument step in the create sequence (role not evident from the call site) |
| 00437a90 | sub_437A90 | Operates on the global at &dword_B66000 during creation |
| 00501770 | sub_501770 | No-argument step in the create sequence |
| 00501ac0 | sub_501AC0 | No-argument step in the create sequence |
| 00501ff0 | sub_501FF0 | No-argument step in the create sequence |
| 0050f6b0 | sub_50F6B0 | Applies a state/mode to this; mode 2 when byte_B6A7F4 bit 0 is set, else mode 1, third arg 0.0 |
| 00510360 | sub_510360 | Called with this and 1 during the create sequence |
| 00510770 | sub_510770 | Called with this and 0 during the create sequence |
| 00538790 | sub_538790 | Accessor on unk_BE1CDC returning a base pointer; caller reads a string pointer at +0 and another string at +1852 |
| 0053a160 | AIW [structural] | Helper invoked with this only when dword_BE1CD0 > 0 |
| 00615860 | StringCopyWithBufferRealloc [structural] | Stores the name strings obtained from the BE1CDC structure |
| 00617930 | sub_617930 | Called with the constant 512 (buffer/size setup) |
| 00631761 | _sprintf | Formats "%s%s\" into this+20 (offset 20) to build the player path |

**Guard conditions:** BLOCKED (return -1) when a2 is null — no initialization runs. dword_91CB00 being null silently falls back to WindowName for the path root. byte_B6A7F4 bit 0 selects sub_50F6B0 mode 2 when set, mode 1 when clear. sub_53A160 is only called when dword_BE1CD0 > 0; the string-storing block only runs when dword_BE1BD4 > 0, and within it a null string pointer also falls back to WindowName. Otherwise the create sequence completes and returns 0.

**String literals referenced (deterministic):**

- `%s%s\`
