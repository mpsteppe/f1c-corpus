## RecursiveTraversal_0054bcd0 — Recursive scene graph traversal with state dispatch

**Summary:** Recursively traverses a scene graph tree (subtree at this+0x44, then subtree at this+0x4C) and dispatches state processing to either StateArrayWordSignExtension (if a4 non-null) or UIElementBitfieldStateSetter (if a4 null). Part of scene graph initialization/update — propagates state and bitfield updates through the hierarchy.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_545D00 (00545d00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x44 | R | — | Pointer to first subtree for recursive traversal |
| this | 0x4C | R | — | Pointer to second subtree for recursive traversal |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054bcd0 | RecursiveTraversal | Recursive call for subtree traversal |
| 0054bdc0 | UIElementBitfieldStateSetter | Process bitfield state update (when a4 is null) |
| 0054bf10 | StateArrayWordSignExtension | Process state array word update (when a4 is non-null) |

**Guard conditions:** First recursion BLOCKED if `this[0x44]` is null. Second recursion BLOCKED if `this[0x4C]` is null. Terminal dispatch: if `a4` is non-null → calls StateArrayWordSignExtension; if null → calls UIElementBitfieldStateSetter.
