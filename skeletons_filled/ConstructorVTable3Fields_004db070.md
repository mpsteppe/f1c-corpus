## ConstructorVTable3Fields_004db070 — ThreeFieldStructConstructor

**Summary:** Initializes a 4-field structure: sets vtable pointer to off_5AD06C, stores two caller-provided parameters (a2 at +4, a3 at +8), and zeros field at +0xC. Simple inline constructor. Part of widget/object initialization.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Direct3DObjectFactory (004daea0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Vtable pointer set to off_5AD06C (AudioFilterVtable) |
| this | 0x4 | RW | — | Stored parameter a2 (type/identifier code) |
| this | 0x8 | RW | — | Stored parameter a3 (boolean/flag byte) |
| this | 0xC | RW | 0 | Cleared to zero (reserved/null pointer) |

**Written-by note (persistence):**
- this 0x0: Written once (vtable), fixed for object lifetime
- this 0x4: Written once from parameter a2; survives until overwritten
- this 0x8: Written once from parameter a3; survives until overwritten
- this 0xC: Written once to 0; persists as initialized null

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ad06c | off_5AD06C | R | AudioFilterVtable [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — all writes unconditional.
