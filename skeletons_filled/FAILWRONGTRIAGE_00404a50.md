## FAILWRONGTRIAGE_00404a50 — StructAllocAndConstructor

**Summary:** Allocates an 88-byte object via heap allocator, zero-initializes most fields, sets some fields to -1 and offset 24 to 3.0f (float), stores pointer in caller's struct field at offset 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | pointer to newly allocated object (output); set to address or NULL on failure |

**Written-by note (persistence):**
- this 0x0: written once per call with allocation result; external poke survives until next call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e48c | dword_59E48C | R | ObjectInitConstant [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587c03 | OperatorNewNhMallocWrapper | allocates heap memory of given size (88 bytes) |

**Guard conditions:** Checks if allocation returned non-null. PASSES: alloc succeeded, initializes object fields and stores pointer. BLOCKED (else): alloc failed, stores NULL in this->0.
