## CConstructor_0052d9b0 — GameObjectConstructorWithDeferredCheck

**Summary:** Sets vtable pointer (off_5B47E8) on object and conditionally calls DeferredDeactivation based on flag byte at offset 0x24EC. Part of GameObject construction.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DestructorWithConditionalFree_d9d0 (0052d9d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer (set to off_5B47E8) |
| this | 0x24EC | R | — | flag byte controlling deferred deactivation call |

**Written-by note (persistence):**
- this 0x0: written once with vtable address; external poke overwrites vtable

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b47e8 | off_5B47E8 | R | vtable pointer for GameObject class |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** if byte at this+0x24EC is non-zero, calls DeferredDeactivation and returns 1; otherwise returns 0 (no deactivation)
