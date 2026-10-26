## ConditionalConstructorDestructor_00485720 — SubObjDtor_5A9448

**Summary:** Destructor that cleans a sub-object at offset 224 via ConditionalDualCleanup, calls base destructor sub_485EB0, then optionally frees self. Sets vtable to off_5A9448.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer set to off_5A9448 |

**Written-by note (persistence):**
- this 0x0: set at entry; overwritten by sub_485EB0 base destructor

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a9448 | off_5A9448 | R | vtable pointer for this object type |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00485eb0 | sub_485EB0 | chains to base class destructor |
| 00499b50 | ConditionalDualCleanup | cleans up a two-field sub-object (conditionally freeing embedded pointers) |
| 00587bcf | FreeWrapper_7bcf | memory deallocation wrapper |

**Guard conditions:** No field-based guards; only the a2 flag controls self-deallocation.
