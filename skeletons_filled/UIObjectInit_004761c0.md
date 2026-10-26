## UIObjectInit_004761c0 — UIGameFilterInit

**Summary:** Initializes a game filter UI object: calls base UI constructor, zeroes field at 0x40 (query/index), sets field at 0x44 to -1 (sentinel), and sets vtable to off_5A4478.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameFilterSetup (00477830)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Vtable pointer for game filter UI object |
| this | 0x40 | RW | 0 | Filter query/index field |
| this | 0x44 | RW | 18446744073709551615 | Filter record sentinel (-1 = not set) |

**Written-by note (persistence):**
- this 0x0: set once; external vtable swap survives
- this 0x40: unconditional zero; external poke survives
- this 0x44: unconditional -1; external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a4478 | off_5A4478 | R | Vtable for game filter UI object |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048fc50 | UIObjectConstructor_fc50 | Base UI object constructor |

**Guard conditions:** No guards — always executes fully.
