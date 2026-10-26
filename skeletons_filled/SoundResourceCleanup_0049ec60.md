## SoundResourceCleanup_0049ec60 — Sound/vehicle node resource cleanup

**Summary:** Releases and frees the resource pointer stored at this[2] (offset 0x8). Calls destructor, stub cleanup, and free wrapper, then clears pointer to 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MultiStageCleanupWithRepeatedCallCycle (0049d150)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | 0 | vehicle/sound node pointer (cleared after cleanup) |

**Written-by note (persistence):**
- this 0x8: set to 0 after cleanup. If external poke writes here, value is lost on next cleanup call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005502c0 | DestructorWithConditionalFreeFlagClear | destructor with conditional free flag handling |
| 00557470 | EmptyStub_7470 | stub cleanup function |
| 00587bcf | FreeWrapper_7bcf | frees allocated memory block |

**Guard conditions:** Checks `this[2]` (0x8) non-null — skips cleanup if already null.
