## ___init_ctype_0063a3b3 — Ctype table initializer (codepage-aware)

**Summary:** CRT startup routine that builds the character-classification (ctype) tables for the active code page: it derives lead-byte ranges from GetCPInfo, generates the CT_CTYPE1 table via ___crtGetStringTypeA, and publishes the resulting table pointer globally; falls back to a static ASCII table when no locale is active.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f127c | GetCPInfo | R | Import thunk: fetches MaxCharSize and the lead-byte ranges for CodePage |
| 00730ac8 | asc_730AC8 | R | Static default character-type table used when dword_FB83E4 is zero |
| 00912b08 | dword_912B08 | R | Runtime state word saved to a local at entry |
| 00913150 | off_913150 | W | Published active ctype table pointer (v1+128 on the built path, asc_730AC8 on the default path) |
| 009131a0 | SrcSizeInBytes | RW | Holds the code page's MaxCharSize after GetCPInfo succeeds; read again by the lead-byte marking loop |
| 00fb83e4 | dword_FB83E4 | R | Master flag: nonzero enables building codepage-specific tables, zero selects the static ASCII default |
| 00fb83f4 | CodePage | R | Active code page number; if zero it is fetched via locale string ID 4100 |
| 00fb840c | word_FB840C | R | Locale value passed with string ID 4100 when loading the code page |
| 00fbb5e8 | dword_FBB5E8 | W | Published pointer to the table entry just before the active table (v1+127), or 0 on the default path |
| 00fbb5ec | dword_FBB5EC | W | Published pointer to the 4-byte companion block (v14), or 0 on the default path |
| ff0000000000a643 | byte_FF0000000000A643 | R | unknown — not traceable in the decompiled body |
| ff0000000000a645 | byte_FF0000000000A645 | R | unknown — not traceable in the decompiled body |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00634919 | _free | Releases the temporary mapping buffer (always) and the table/companion blocks on the failure path |
| 006349bb | sub_6349BB | unknown — no call visible in the decompiled body |
| 00634c1d | _malloc | Allocates the 4-byte companion block, the 0x300-byte wchar type table, and the 0x101-byte byte→index map |
| 00635560 | _memcpy_0 | Copies 0xFE bytes from v1+256 back to v1 to relocate the type table prefix |
| 0063af98 | ___crtGetStringTypeA | Fills the CT_CTYPE1 character-type table for the 256 mapped bytes into v1+128 |
| 006422f4 | sub_6422F4 | Locale string loader used to fetch the code page (ID 4100) when CodePage is zero |

**Guard conditions:** `dword_FB83E4 == 0` → default path: off_913150 = asc_730AC8, dword_FBB5EC = dword_FBB5E8 = 0, return 0. Otherwise: if `CodePage == 0` and the ID-4100 locale load fails → skip the build (cleanup path, return 1). Allocation of any of the three blocks failing → cleanup path, return 1. After the identity-fill loop (Block[i] = i, i < 256): requires `GetCPInfo(CodePage, &CPInfo)` to succeed and `CPInfo.MaxCharSize <= 5`; otherwise cleanup path, return 1. With MaxCharSize > 1 and a nonzero LeadByte[0], each lead-byte range [start..end] has its Block entries zeroed. ___crtGetStringTypeA must return nonzero or the build fails (return 1). On success: v1[127] = 0, lead-byte entries in the wide table set to 0x8000, memcpy of 0xFE bytes, globals published, v11 = 0, Block freed.

**String literals referenced (deterministic):**

- `         (((((                  H`
