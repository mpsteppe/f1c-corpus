## TypeInfoDestructor_0059baa3 — TypeInfoDestructor

**Summary:** Destructor for MSVC RTTI type info object: restores vtable pointer and frees the type descriptor name string under critical section 27.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ExceptionDestructorWithConditionalFree_bacc (0059bacc)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | VTable pointer (restored to off_5B9DB8 on destruction) |
| this | 0x4 | R | — | Pointer to type descriptor name string (freed if non-null) |

**Written-by note (persistence):**
- this 0x0: written once (vtable restored before destruction)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b9db8 | off_5B9DB8 | R | TypeInfoVFTable [DERIVED] — canonical vtable for RTTI TypeDescriptor |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058aa6f | sub_58AA6F | Free/release type descriptor name string |
| 0058dfea | CriticalSectionLazyInitEnter | Enter critical section 27 for thread safety |
| 0058e04b | CritSectLeave | Leave critical section 27 |

**Guard conditions:** None for entry. Free of this[1] happens only if non-null.
