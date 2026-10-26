## ShortComputation_9180_00499180 — Vtable setup with destruction call

**Summary:** Sets vtable pointer to off_5ACA30 then calls DualListDestruction. Part of object teardown/transition sequence.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_499160 (00499160)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | off_5ACA30 | vtable pointer — set before calling destructor/teardown |

**Written-by note (persistence):**
- this 0x0: written once unconditionally; vtable pointer persists afterward

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005aca30 | off_5ACA30 | R | PTR_VTABLE_5ACA30 [DERIVED] — vtable assigned before destruction |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — unconditional vtable write + destruction call
