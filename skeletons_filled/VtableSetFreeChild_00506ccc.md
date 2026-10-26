## VtableSetFreeChild_00506ccc — Set vtable to static table and free child pointer

**Summary:** Retrieves child pointer from this[1043], sets this vtable pointer to off_5ADB80 (static vtable), and frees the old child pointer via FreeWrapper_7bcf.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ComplexDestructorWithLoop (00506fd9), ShortComputation_76e2 (005076e2), DestructorWithResourceCleanup_b830 (0050b830)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer, set to static off_5ADB80 |
| this | 0x104C | R | — | child/payload pointer at this[1043], freed via FreeWrapper_7bcf |

**Written-by note (persistence):**
- this 0x0: once — overwritten with static vtable; external poke survives but object semantics change

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005adb80 | off_5ADB80 | R | VTable_5ADB80 [DERIVED] — static vtable pointer assigned to this after cleanup |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | frees the child pointer stored at this[1043] |

**Guard conditions:** No guards — always executes: saves child pointer, sets vtable, frees child.
