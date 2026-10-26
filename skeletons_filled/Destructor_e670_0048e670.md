## Destructor_e670_0048e670 — UIObjectStructDestroy

**Summary:** Destructor for UI struct: restores vtable to off_5AC540 for safe virtual dispatch during destruction, calls ResourceCleanup to release resources, conditionally frees handle at offset 0xE0 if non-null, then chains to base destructor sub_485EB0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DestructorWithConditionalSelfFree (0048e650)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer (restored for safe destruction) |
| this | 0xE0 | R | — | resource handle / allocated buffer, checked before free |

**Written-by note (persistence):**
- this 0x0: overwritten during destruction; object invalid after

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ac540 | off_5AC540 | R | PTR_VTABLE_5AC540 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048e890 | ResourceCleanup | release associated resources |
| 00587bcf | FreeWrapper_7bcf | memory deallocation wrapper |

**Guard conditions:** if (this[56] != 0) → PASS (free handle at 0xE0 via FreeWrapper_7bcf); if zero → BLOCKED (skip free).
