## UIOptionsConstructor_6030_00476030 — UIOptionsScreenInit

**Summary:** Initializes an options screen UI object: calls base UI object constructor, sets vtable to off_5A4428, and zeroes field at 0x3C.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Vtable pointer for options screen object |
| this | 0x3C | RW | 0 | Options state/flag (zeroed at init) |

**Written-by note (persistence):**
- this 0x0: set once; external vtable swap survives
- this 0x3C: set once per call; external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a4428 | off_5A4428 | R | Vtable for options screen UI object |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048fc50 | UIObjectConstructor_fc50 | Base UI object constructor |

**Guard conditions:** No guards — always executes fully.
