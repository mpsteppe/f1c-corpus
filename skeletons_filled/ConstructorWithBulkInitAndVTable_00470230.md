## ConstructorWithBulkInitAndVTable_00470230 — SeasonDbObjectConstructor

**Summary:** Constructor called from SeasonDatabaseObjectFactory: calls ConstructorWithStringCopy base initializer (7 params, last=1), sets vtable to off_5A0250, and returns the object.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SeasonDatabaseObjectFactory (0047f440)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer, set to off_5A0250 |

**Written-by note (persistence):**
- this 0x0: set once to vtable off_5A0250; overwritten if external code changes vtable

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a0250 | off_5A0250 | R | vtable pointer assigned to this object |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048b420 | ConstructorWithStringCopy | base object constructor with string copy capability (called with zeros and trailing 1) |

**Guard conditions:** No guards — unconditional initialization.
