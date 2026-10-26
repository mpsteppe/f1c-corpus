## DynamicsObjectInitialization_00438c10 — Vehicle dynamics state initializer

**Summary:** Initializes a vehicle dynamics object: zeroes 0x1F38-byte main struct, initializes 4 per-wheel substructures at 0x464-byte stride with alternating state values, calls sub-component initializers and wheel dynamics setup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x5D8 | RW | 18446744071819766006 | wheel dynamics first state constant (bit pattern 0x8FAAAA76) |
| this | 0x5DC | RW | 1081507266 → 3.8514f | wheel dynamics initial float parameter |
| this | 0x5E0 | RW | — | copy of first state constant (redundant state slot) |
| this | 0x5E4 | RW | — | copy of initial float parameter (redundant state slot) |
| this | 0x5E8 | RW | — | copy of first state constant (triplicate slot) |
| this | 0x5EC | RW | — | copy of initial float parameter (triplicate slot) |

**Written-by note (persistence):**
- this 0x5D8: unconditional — external poke overwritten on re-init
- this 0x5DC: unconditional — external poke overwritten on re-init
- this 0x5E0: unconditional — external poke overwritten on re-init
- this 0x5E4: unconditional — external poke overwritten on re-init
- this 0x5E8: unconditional — external poke overwritten on re-init
- this 0x5EC: unconditional — external poke overwritten on re-init

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042e1c0 | StructInitializer | initializes sub-struct at offset 0x156C |
| 004353f0 | ConstructorStub | stub constructor for sub-component at offset 0x1EC |
| 004363d0 | DoubleArrayZero | zeros array of 25 doubles starting at offset 0x1838 |
| 0043e230 | WheelDynamicsInit | finalizes wheel dynamics subsystem initialization |
| 0056d3e0 | StructInitWithZeroFillSubCall | zero-fills struct at offset 0x15AC |

**Guard conditions:** None — always executes fully, no conditional branches.
