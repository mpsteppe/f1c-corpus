## AVIStreamCleanup_0045bea0 — AVIStreamCleanup

**Summary:** Releases AVI file and stream handles, nullifies pointers, then delegates to AVIPlayerCleanup. Part of video playback teardown.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_45BE80 (0045be80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x38 | RW | 0 | AVIFile handle pointer |
| this | 0x3C | RW | 0 | First AVIStream handle pointer |
| this | 0x40 | RW | 0 | Second AVIStream handle pointer |

**Written-by note (persistence):**
- this 0x38: cleared to 0 during cleanup after release; external poke does not survive because cleanup re-initializes
- this 0x3C: cleared to 0 during cleanup after release; external poke does not survive
- this 0x40: cleared to 0 during cleanup after release; external poke does not survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00534ae6 | AVIFileRelease | Releases AVI file interface handle |
| 00534aec | AVIStreamRelease | Releases AVI stream interface handle |

**Guard conditions:** Each handle pointer (0x38, 0x3C, 0x40) checked for non-null before release. Null pointer → skip release (already freed or never opened).
