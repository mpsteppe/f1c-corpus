## StringCopyWithFlagUnion_0055d2a0 — String copy with flag union and scene state setup

**Summary:** ORs parameter flags into this+0x0, copies source string (a2) into this+0x58, and stores scene state setup result (via SceneStateSetup with SoundManager global) into this+0x4. Returns 0. Part of sound/scene property initialization.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_545430 (00545430)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Bitfield flags — OR-ed with input a3 |
| this | 0x4 | RW | — | Scene state setup result — written from SceneStateSetup call with SoundManager |

**Written-by note (persistence):**
- this 0x0: OR-ed with a3 each call. External poke partially survives unless same bits overwritten.
- this 0x4: Overwritten each call. External poke does not survive.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b78a0 | dword_8B78A0 | R | SoundManager — passed to SceneStateSetup |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00541500 | SceneStateSetup | Returns scene/sound state handle from SoundManager and flags |

**Guard conditions:** None — always executes unconditionally.
