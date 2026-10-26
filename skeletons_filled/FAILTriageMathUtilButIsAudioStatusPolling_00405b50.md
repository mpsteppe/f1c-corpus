## FAILTriageMathUtilButIsAudioStatusPolling_00405b50 — AudioSampleStatusPoll

**Summary:** Polls Miles audio sample playback status via AIL_sample_status — returns non-zero (loop mode flag) if status is DONE (4) or STOPPED (16), otherwise returns 2 (still playing/other).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | R | — | Loop mode flag (returned as verdict when sample is done) |
| this | 0x58 | R | — | Pointer to sample handle struct |
| this | 0x68 | R | — | Indirection to sample handle (this[0x68]→0x10 = sample handle) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e3c8 | _AIL_sample_status@4 | R | Query Miles sample playback status |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x14 | != | 0 | Loop mode flag — used as return value when sample is done |

**Guard interpretation:** First checks if `this[22]` (offset 0x58) is null. If null → blocked (returns 2). If non-null, queries AIL_sample_status. If status is 4 (DONE) or 16 (STOPPED) → PASSES: returns `this[5]` (offset 0x14, loop mode flag, non-zero if continuous). Otherwise → BLOCKED: returns 2 (sample still active or other status).
