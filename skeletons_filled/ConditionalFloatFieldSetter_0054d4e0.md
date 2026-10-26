## ConditionalFloatFieldSetter_0054d4e0 — Conditional float field setter with sentinel

**Summary:** Sets two float fields on an object, but only if the input values are not the -1.0 sentinel (indicating "no change"). Used by scene node initialization to optionally override default values.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SceneNode (0055a910)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xF4 | RW | — | First float field (set when a2 != -1.0) |
| this | 0xF8 | RW | — | Second float field (set when a3 != -1.0) |

**Written-by note (persistence):**
- this 0xF4: conditionally written when a2 != -1.0; overwritten each call or survives
- this 0xF8: conditionally written when a3 != -1.0; overwritten each call or survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e428 | dbl_59E428 | R | -1.0 sentinel constant used for comparison |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If `a2 != -1.0`, PASSES: writes a2 to this[61] (+0xF4). If `a2 == -1.0`, BLOCKED: field unchanged. Same for `a3` against this[62] (+0xF8).
