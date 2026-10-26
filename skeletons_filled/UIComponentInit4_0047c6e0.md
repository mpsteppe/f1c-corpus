## UIComponentInit4_0047c6e0 — UIComponentParamInit

**Summary:** Initializes a UI component by calling sub_48C070 with argument 1 and setting vtable pointer to off_5A68F0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer, set to off_5A68F0 |

**Written-by note (persistence):**
- this 0x0: written once on construction; persists for object lifetime

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a68f0 | off_5A68F0 | R | vtable pointer for this UI component type |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048c070 | sub_48C070 | base UI component initialization with parameter |

**Guard conditions:** none — always executes full init, returns this
