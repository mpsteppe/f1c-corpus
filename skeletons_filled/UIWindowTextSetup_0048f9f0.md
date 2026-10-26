## UIWindowTextSetup_0048f9f0 — UITextWindowConfigLoader

**Summary:** Loads and configures UI text window properties from configuration files: builds file path from directory, searches for .HOT extension files, loads two resources via SingleFunctionCallWrapper_7f59 into fields at 0x154 and 0x150, and determines layout mode (offset 0xE0) by comparing loaded file extension against known tokens (.c=1, .R=2, else 0).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UIDimensionCapture (0048ebd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xB8 | R | — | directory path string pointer |
| this | 0xE0 | RW | 2 | layout mode: 0=unknown, 1=.c layout, 2=.R layout |
| this | 0x150 | RW | — | resource A (first loaded via SingleFunctionCallWrapper_7f59) |
| this | 0x154 | RW | — | resource B (second loaded via SingleFunctionCallWrapper_7f59) |

**Written-by note (persistence):**
- this 0xE0: set based on extension comparison; survives until reload
- this 0x150: set if resource load succeeds; survives until reload
- this 0x154: set if resource load succeeds; survives until reload

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c32d8 | word_5C32D8 | R | HotExtension (.HOT) [DERIVED] |
| 005c36f0 | aR | R | Token_R [DERIVED] |
| 005cc210 | aC_0 | R | StrExtension_c [DERIVED] |
| 005cc21c | byte_5CC21C | R | Str_UI_Load [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587dd0 | sub_587DD0 | build file path from directory name |
| 00587f59 | SingleFunctionCallWrapper_7f59 | load/set resource from file handle |
| 00588410 | sub_588410 | string comparison against token |
| 005897ca | sub_5897CA | find/extract file handle with given extension |

**Guard conditions:**
- If this[46] (dir path at 0xB8) is null → substitute default byte_5EA438
- File path built via sub_587DD0
- If sub_5897CA returns non-zero for first search → load resource A at 0x154
- If sub_5897CA returns non-zero for second search → load resource B at 0x150
- If sub_5897CA returns non-zero for third search (v6):
  - if !sub_588410(v6, Str_UI_Load) → set mode at 0xE0 to 0
  - if !sub_588410(v6, StrExtension_c) → set mode at 0xE0 to 1
  - if !sub_588410(v6, Token_R) → set mode at 0xE0 to 2
