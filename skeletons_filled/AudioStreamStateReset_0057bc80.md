## AudioStreamStateReset_0057bc80 — ResetAudioStreamState

**Summary:** Resets two audio stream state fields (WORD at 0x12C and DWORD at 0x130) to zero, then calls SmallStructFieldInit for further initialization.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x12C | RW | 0 | audio stream state/status WORD (reset to 0) |
| this | 0x130 | RW | 0 | audio stream position/count DWORD (reset to 0) |

**Written-by note (persistence):**
- this 0x12C: unconditionally set to 0 per call; external poke does not survive
- this 0x130: unconditionally set to 0 per call; external poke does not survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — always executes unconditionally.
