## ConstructorWithMultipleFieldInitsAndGlobalRef_00474ba0 — UIListScoringGateInit

**Summary:** Constructs a UI list item for a scoring gate setting — sets vtable, binds to ScoringGateFlag global, initializes flags (enabled, selected state), registers two UI text handles via linked list, and sets a hardcoded value 438.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Vtable pointer for UI list item |
| this | 0x31C | RW | — | Pointer to ScoringGateFlag global — game state binding |
| this | 0x324 | RW | 1 | Enabled/visible flag |
| this | 0x328 | RW | 0 | Selected/highlighted flag |
| this | 0x32C | RW | 1 | Interactive/focusable flag |
| this | 0x330 | RW | 1 | Boolean flag (toggle/check state) |
| this | 0x334 | RW | 438 | Numeric value (max value or resource ID) |

**Written-by note (persistence):**
- this 0x0: set once; external vtable swap survives
- this 0x31C: set once; external poke to global NOT reflected (pointer snapshot)
- this 0x324: unconditional init; external poke survives
- this 0x328: unconditional init; external poke survives
- this 0x32C: unconditional init; external poke survives
- this 0x330: unconditional init; external poke survives
- this 0x334: unconditional init; external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a3fc0 | off_5A3FC0 | R | Vtable for UI list item type |
| 005be704 | off_5BE704 | R | UITextHandle_5be704 [DERIVED] — text resource for list item label |
| 005c32c8 | aOn | R | UIStringHandle [DERIVED] — text resource "On"/status string |
| 007d0038 | dword_7D0038 | R | ScoringGateFlag [DERIVED] — game state flag bound to this item |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00466d60 | ShortComputation_6d60 | Base class field initialization |
| 00486f30 | LinkedListInsertWithNodeAllocation | Inserts text handle node into UI list item's string list |

**Guard conditions:** No guards — always executes fully.
