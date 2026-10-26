## RenderObjectConstructor_e170_0052e170 — RenderObjectFullConstructor

**Summary:** Constructs RenderObject by first calling ObjectVTableInitialization for GameObject base, storing I/O interface pointers, then overriding vtable to SSE-optimized vtable (off_5B4810). Core constructor for render objects used in media playback.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ThreadedObjectCreatorWithSEH (0052d8d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer (set to off_5B4810 after base init) |
| this | 0x2D34 | RW | — | I/O interface pointer (read source) |
| this | 0x2D38 | RW | — | I/O secondary pointer (read source) |

**Written-by note (persistence):**
- this 0x0: written twice (base vtable then SSE override); external poke overwrites vtable
- this 0x2D34: written once; external poke overwrites I/O pointer
- this 0x2D38: written once; external poke overwrites I/O secondary pointer

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b4810 | off_5B4810 | R | SSE-optimized vtable for RenderObject |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0052d9f0 | ObjectVTableInitialization | init GameObject base vtable and zero fields |

**Guard conditions:** none — always executes all initialization steps
