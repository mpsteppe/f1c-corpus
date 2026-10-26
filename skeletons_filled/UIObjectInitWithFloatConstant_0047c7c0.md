## UIObjectInitWithFloatConstant_0047c7c0 — UIObjectFloatConstantInit

**Summary:** Constructs a UI object by calling UIConstructorWithVTableParams with default float value 1.0 (0x3F800000), stores caller-provided parameter at offset 0xFC, and sets vtable pointer to off_5A69B0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer, set to off_5A69B0 |
| this | 0xFC | RW | — | caller-provided value (parameter a2), stored after construction |

**Written-by note (persistence):**
- this 0x0: written once on construction; persists for object lifetime
- this 0xFC: written once with caller parameter; persists unless explicitly changed

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a69b0 | off_5A69B0 | R | vtable pointer for this UI object type |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048d3a0 | UIConstructorWithVTableParams | base UI object constructor with vtable, zero-int, and float 1.0 parameters |

**Guard conditions:** none — always executes full init, returns this
