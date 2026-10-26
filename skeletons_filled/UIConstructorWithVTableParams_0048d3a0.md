## UIConstructorWithVTableParams_0048d3a0 — UIObjectConstructorWithStoredParams

**Summary:** Initializes a UI widget object by calling base init (ShortComputation_5e30) and field init (F_5FieldInit), then stores the vtable pointer and two integer parameters (a2 at +0xF4, a3 at +0xF8). Two byte flags at +0xF0 and +0xF1 are zeroed.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** InitVTableSet (004668e0), VtableSetWithInitCall (00466980), VTableSetInit (004795e0), sub_479C30 (00479c30), ConstructorWithRangeInitAndFlag (00479cd0), UIObjectInitWithFloatConstant (0047c7c0), sub_47C910 (0047c910)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Vtable pointer set to off_5AC118 |
| this | 0xF0 | RW | 0 | Byte flag, zero-initialized |
| this | 0xF1 | RW | 0 | Byte flag, zero-initialized |
| this | 0xF4 | RW | — | Stored integer parameter a2 |
| this | 0xF8 | RW | — | Stored integer parameter a3 |

**Written-by note (persistence):**
- this 0x0: set every call; survives external poke (standard vtable init)
- this 0xF0: set to 0 every call; survives external poke
- this 0xF1: set to 0 every call; survives external poke
- this 0xF4: set every call; survives external poke
- this 0xF8: set every call; survives external poke

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ac118 | off_5AC118 | R | VtablePtr_5AC118 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00485e30 | ShortComputation_5e30 | Base object initialization |
| 004883a0 | F_5FieldInit | Additional field initialization |

**Guard conditions:** None — unconditional initialization.
