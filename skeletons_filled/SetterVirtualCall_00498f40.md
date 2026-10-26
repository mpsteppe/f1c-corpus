## SetterVirtualCall_00498f40 — Conditional Setter With Virtual Call

**Summary:** Conditionally stores a value into field at offset 0x50, then unconditionally calls virtual method at vtable offset 44 with argument 1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LinkedListSearchWithAction (004974a0), UtilityFunction_7890 (00497890)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x2C | R | — | unknown — not directly referenced in decompiled C |
| this | 0x0 | R | — | Vtable pointer; used to dispatch virtual method at offset 44 |
| this | 0x50 | RW | — | Field conditionally set to a2 when a2 is non-zero |

**Written-by note (persistence):**
- this 0x50: Written conditionally when a2 != 0; persists until next write. Skipped when a2 is 0.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:**
- `a2 == 0` → skip field write, still invoke virtual method (BLOCKED for write, PASSES for virtual call)
- `a2 != 0` → write a2 to this[20], then invoke virtual method (PASSES: both write and call)
