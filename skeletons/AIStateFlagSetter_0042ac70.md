## AIStateFlagSetter_0042ac70 — AIStateFlagSetter

**Summary:** Sets callToBox flag (this[0x454C]) to 0 or 1. Guarded: only writes when a2 <= 1. Returns the input value unchanged.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIMainUpdate (00424e70), ForcePitExit (0042a110), WrapPlayerCallback (0042ac90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x454C | RW | — | callToBox [CONFIRMED] — set to 0 or 1 to request pit stop |

**Written-by note (persistence):**
- this 0x454C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Only writes callToBox when a2 <= 1. Values > 1 are silently ignored (field unchanged).
