## ObjectInitWithVTable_0047c0d0 — TextDisplayObjectConstructor

**Summary:** Constructs a text display object by calling UITextDisplayConstructor base init and setting vtable pointer to off_5A6838.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer, set to off_5A6838 |

**Written-by note (persistence):**
- this 0x0: written once on construction; persists for object lifetime

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a6838 | off_5A6838 | R | vtable pointer for text display object |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00488180 | UITextDisplayConstructor | base text display object initialization / constructor chain |

**Guard conditions:** none — always executes full init, returns this
