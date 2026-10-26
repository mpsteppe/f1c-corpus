## PlayerNameNeverUsedProfileFileCreateRead_004b03f0 — PlayerNameNeverUsedProfileFileCreateRead

**Summary:** Attempts to find player profile files via directory iteration. If a profile file exists, copies it to the settings directory. If no profile files exist, reads default "PlayerNameNever..." text file, calls itself recursively, and sets two flag bytes at this+0x49A8 and this+0x49A9 to 1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ProfileAlreadyExistsPageHandler (0046cb50), sub_485B90 (00485b90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x49A8 | RW | 1 | profile-created flag byte (set to 1 on recursive create) |
| this | 0x49A9 | RW | 1 | secondary profile flag byte (set to 1 on recursive create) |

**Written-by note (persistence):**
- this 0x49A8: set to 1 unconditionally when no existing profile files found (recursive branch)
- this 0x49A9: set to 1 unconditionally when no existing profile files found (recursive branch)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be860 | aSS | R | PathFormatString [DERIVED] (also: ` â€” format string for path construction) |
| 005c6970 | aPlayernameneve | R | Str_UI_PlayerNameNever [DERIVED] |
| 005cc1f4 | aPlr | R | StringSuffixDword [DERIVED] (also: � Suffix dword) |
| 005d1ff0 | off_5D1FF0 | R | VTable_FUN_004b03f0 [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec440 | dword_5EC440 | R | SettingsDirectory [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b03f0 | PlayerNameNeverUsedProfileFileCreateRead | recursive self-call when no existing profile found (creates default profile) |
| 004b04e0 | StringCopyFileCheckDispatch | copies file from source to settings directory if file exists |
| 004b09a0 | TextFileReader | reads default "PlayerNameNever..." text file when no profiles exist |
| 00565dc0 | AllocateStructWithDefaultValues | allocates and initializes directory iterator structure |
| 00565e20 | LinkedListDestructorWithChildCleanup | frees directory iterator linked list nodes |
| 00565f80 | sub_565F80 | sets up search path for profile files with suffix filter |
| 005662d0 | DirectoryEntryIterator | iterates directory entries, returns first matching filename |
| 00566380 | sub_566380 | configures directory iterator search parameters |
| 0058815f | StringFormatWithBufferOverflowCheck | safe sprintf, formats "plr" filename |

**Guard conditions:** Guards based on DirectoryEntryIterator result:
- If iterator returns non-null (existing profile found): copy file via StringCopyFileCheckDispatch, then cleanup. Flags NOT set.
- If iterator returns null (no existing profile): read default text file, call self recursively, set flags at this+0x49A8/0x49A9 to 1. Passes (no profile) → creates default. Blocked (has profile) → copies existing.
