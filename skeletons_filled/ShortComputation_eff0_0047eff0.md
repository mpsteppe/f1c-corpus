## ShortComputation_eff0_0047eff0 — ObjectInitWithVTable_eff0

**Summary:** Minimal object constructor calling base init and setting vtable pointer to off_5A6D20.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer, set to off_5A6D20 |

**Written-by note (persistence):**
- this 0x0: written once on construction; persists for object lifetime

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a6d20 | off_5A6D20 | R | VTable_47EFF0 [DERIVED] — vtable pointer for this object type |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00488b00 | ConstructorInitVTable | base object constructor with vtable and sentinel value -1 |

**Guard conditions:** none — always executes full init, returns this
