## _LanguageEnumProc@4_0063ab48 — EnumLanguageProc: locale language matcher

**Summary:** EnumLanguageProc callback used while enumerating system languages: converts each enumerated hex LCID string, fetches its localized language name, and compares it against the target name to select the matching locale; sets the found flag and locale globals to stop enumeration.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00912b08 | dword_912B08 | R | Runtime state word saved to a local at entry |
| 00fb83b8 | dword_FB83B8 | RW | Result/status flags: cleared to 0 when the name fetch fails, OR'd with 4 when a matching locale is found |
| 00fb83bc | Locale | W | Receives the matched LCID |
| 00fb83c0 | dword_FB83C0 | W | Also receives the matched LCID (companion to Locale) |
| 00fb83c4 | dword_FB83C4 | R | Mode flag: selects info ID 3 vs 4097 and skips the prefix-match path when set |
| 00fb83d0 | MaxCount | R | Length limit for the __strnicmp prefix comparison against the target name |
| 00fb83d4 | dword_FB83D4 | R | Target language name string being matched |
| 00fb83d8 | dword_FB83D8 | R | Function pointer to the locale-info retrieval routine |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00631c0d | __stricmp | Full case-insensitive comparison of the fetched localized name against the target name |
| 006349bb | sub_6349BB | unknown — no call visible in the decompiled body |
| 0063a7d7 | ByteBufferSwap [structural] | Converts the enumerated LCID hex string (a2) into an LCID value (invoked as LcidFromHexString in the body) |
| 0063a8bd | _TestDefaultLanguage | Additional acceptance test for the candidate LCID (called with flag 1 on full-name match, 0 on prefix match) |
| 0064241b | __strnicmp | Bounded case-insensitive prefix comparison of the target name against the fetched name using MaxCount |

**Guard conditions:** If the locale-info fetch fails → dword_FB83B8 = 0 and return TRUE (keep enumerating). Full match (`_stricmp == 0`): if dword_FB83C4 is set → found; else accept only if TestDefaultLanguage(v2, 1) is TRUE. No full match: if `dword_FB83C4 != 0 || MaxCount == 0 || _strnicmp(...) != 0` → return `(dword_FB83B8 & 4) == 0` without a candidate; otherwise accept if TestDefaultLanguage(v2, 0) is TRUE. On acceptance: dword_FB83B8 |= 4, dword_FB83C0 = Locale = v2, and the return becomes 0 (stop enumeration). Non-matching iterations return `(dword_FB83B8 & 4) == 0`, i.e., TRUE while the found flag is still clear.
