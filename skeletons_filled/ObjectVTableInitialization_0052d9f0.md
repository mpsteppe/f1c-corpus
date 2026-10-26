## ObjectVTableInitialization_0052d9f0 — GameObjectVTableAndFieldInit

**Summary:** Initializes GameObject by setting vtable pointer to off_5B47E8 and zeroing fields at offsets 0x24EC (flag byte) and 0x24F0 (default header word). Called during RenderObject construction.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RenderObjectConstructor_e170 (0052e170)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer (set to off_5B47E8) |
| this | 0x24EC | RW | 0 | flag byte (cleared) |
| this | 0x24F0 | RW | 0 | default header word (cleared) |

**Written-by note (persistence):**
- this 0x0: written once with vtable; external poke overwrites vtable
- this 0x24EC: written once to 0; external poke survives until next init
- this 0x24F0: written once to 0; external poke survives until next init

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b47e8 | off_5B47E8 | R | vtable pointer for GameObject class |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — always executes all three writes
