## UtilityFunction_2950_00542950 — StreamConfigAndSoundRegistration

**Summary:** Initializes stream configuration fields on `this` and optionally registers with the sound manager. Delegates mode validation to sub_5426E0; if `a5 & 0xF` is nonzero, registers the object with the sound manager via sub_53F720.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_53EB70 (0053eb70), MemoryAllocationWithFallback (00543a80), sub_544740 (00544740), sub_54FEC0 (0054fec0), sub_551FD0 (00551fd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x18 | RW | — | store flags/configuration parameter (a5) |
| this | 0x1C | RW | — | store parameter a2 |
| this | 0x20 | RW | — | store parameter a3 |

**Written-by note (persistence):**
- this 0x18: set unconditionally from a5 on each call
- this 0x1C: set unconditionally from a2 on each call
- this 0x20: set unconditionally from a3 on each call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b78a0 | dword_8B78A0 | R | SoundManager singleton pointer |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053f720 | sub_53F720 | register sound/stream object with SoundManager |
| 005426e0 | sub_5426E0 | validate and set stream mode configuration |

**Guard conditions:** BLOCKED when sub_5426E0 returns non-zero (mode validation fails) → returns -1. Also BLOCKED when (a5 & 0xF) != 0 and registration sub_53F720 fails → returns -1.
