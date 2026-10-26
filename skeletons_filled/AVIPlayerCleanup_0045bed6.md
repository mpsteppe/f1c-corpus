## AVIPlayerCleanup_0045bed6 — AVIPlayerCleanup

**Summary:** Releases two resource pointers if not already set to sentinel, zeroes out the playback struct, then exits AVI file system. Final step of video playback teardown.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045bf10 | WideStructZeroInit | Zero-initializes the AVI player struct |
| 0053cb90 | sub_53CB90 | Releases resource at offset 0x44 |
| 00587bcf | FreeWrapper_7bcf | Frees heap-allocated resource at offset 0x50 |

**Guard conditions:** Pointer at offset 0x44 checked against sentinel a1 before release; if equal → skip. Pointer at offset 0x50 checked against sentinel a1 before free; if equal → skip.
