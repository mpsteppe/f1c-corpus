## SimpleObjectConstructor_00474ff0 — UIObjectWithIntParamInit

**Summary:** Initializes a UI object: calls base constructor with zeroed params, stores an integer parameter in field 0xE4, and sets vtable to off_5A42C0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Vtable pointer for UI object |
| this | 0xE4 | RW | — | Stores constructor integer parameter (a2) |

**Written-by note (persistence):**
- this 0x0: set once; external vtable swap survives
- this 0xE4: set once per call; external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a42c0 | off_5A42C0 | R | Vtable for UI object |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00487220 | ConstructorWithByteParams | Base class constructor with byte initialization parameters |

**Guard conditions:** No guards — always executes fully.
