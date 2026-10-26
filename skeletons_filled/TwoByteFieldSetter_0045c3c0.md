## TwoByteFieldSetter_0045c3c0 — TwoByteFieldSetter

**Summary:** Sets two consecutive byte fields on a struct from parameters and returns the first value. Part of particle/sound configuration initialization.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ParticleSoundEffectSpawner (004607a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | First byte field (copied from a2) |
| this | 0x1 | RW | — | Second byte field (copied from a3) |

**Written-by note (persistence):**
- this 0x0: written unconditionally every call; external poke overwritten on each call
- this 0x1: written unconditionally every call; external poke overwritten on each call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional write of both byte fields.
