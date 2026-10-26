## AnimationStateSetter_004be9e0 — AnimationStateSetter

**Summary:** Copies four animation/behavior parameters into struct: two byte flags (offsets 0x340, 0x341), a DWORD at offset 0x344, and a DWORD at offset 0x350. Returns the third parameter (a4).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AIBehaviorInitialization (004bf0a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x340 | RW | — | first animation/behavior boolean flag |
| this | 0x341 | RW | — | second animation/behavior boolean flag |
| this | 0x344 | RW | — | float parameter 1 (collision response multiplier) |
| this | 0x350 | RW | — | float accumulator increment step |

**Written-by note (persistence):**
- this 0x340: written each call from parameter a2; external poke overwritten
- this 0x341: written each call from parameter a3; external poke overwritten
- this 0x344: written each call from parameter a4; external poke overwritten
- this 0x350: written each call from parameter a5; external poke overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — unconditional write of all four parameters
