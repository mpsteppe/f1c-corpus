## sub_5BC1B0_005bc1b0 — scalar deleting destructor (off_729694 vtable variant)

**Summary:** Third instance of the scalar-deleting-destructor stub, paired with the off_729694 class slot (constructor stub sub_5BC140): re-installs the vtable pointer into the object's first dword, then frees the block if bit 0 of `a2` is set. Returns the block pointer.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Vtable/class pointer slot; re-assigned `off_729694` before the optional free. |

**Written-by note (persistence):**
- this 0x0: written unconditionally on every call (vtable re-install during destruction); an external poke is overwritten whenever this destructor runs.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00729694 | off_729694 | R | Class vtable/type pointer re-installed into the object's first dword during destruction (matches sub_5BC140). |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006308d3 | j__free | Heap release of the object block when the delete flag is set. |

**Guard conditions:** Single flag test: `a2 & 1`. Bit 0 set → `j__free(Block)` runs (delete path); bit 0 clear → only the vtable store runs (destructor-only path). No other checks.
