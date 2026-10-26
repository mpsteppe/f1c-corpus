## ConstructorInitVTable_00488b00 — UIWidgetInit

**Summary:** Initializes a UI widget: zeroes fields via ShortComputation_5e30, stores parameters a2/a3 at offsets 0xE0/0xE4, sets vtable to UIWidget, and sets flag at 0xE8 to 1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_47DAF0 (0047daf0), GameOptionsUIConstructor (0047e960), ShortComputation_eff0 (0047eff0), VTablePointerConstructor (0047f080), ObjectInitWithFieldZeroing (0048aa40), ConstructorDualSubInit (0048d660), sub_493FC0 (00493fc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Vtable pointer — set to UIWidget vtable |
| this | 0xE0 | RW | — | First constructor parameter (scroll delta / config) |
| this | 0xE4 | RW | — | Second constructor parameter |
| this | 0xE8 | RW | 1 | Boolean flag — set to 1 (active/enabled) |

**Written-by note (persistence):**
- this 0x0: Written once during construction. Not modified after init.
- this 0xE0: Written once with parameter. May be overwritten by setters later.
- this 0xE4: Written once with parameter. May be overwritten by setters later.
- this 0xE8: Written once with literal 1 (active). May be modified later.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005abc28 | off_5ABC28 | R | Vtable_UIWidget [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00485e30 | ShortComputation_5e30 | Zero-initialize fields / base init |

**Guard conditions:** None — unconditional init function.
