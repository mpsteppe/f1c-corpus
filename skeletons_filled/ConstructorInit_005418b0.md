## ConstructorInit_005418b0 — Constructor initializer — zero fields

**Summary:** Calls global zero-init helper to clear the object, then explicitly zeros four specific fields at offsets 0x80, 0x19C, 0x1B4, and 0x1B8.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_544E90 (00544e90), sub_548AD0 (00548ad0), sub_553700 (00553700), sub_560C10 (00560c10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x80 | RW | 0 | sub-object or flag, zeroed at init |
| this | 0x19C | RW | 0 | sub-object or flag, zeroed at init |
| this | 0x1B4 | RW | 0 | sub-object or flag, zeroed at init |
| this | 0x1B8 | RW | 0 | sub-object or flag, zeroed at init |

**Written-by note (persistence):**
- this 0x80: written once at construction (zero); persists until explicitly modified.
- this 0x19C: written once at construction (zero); persists until explicitly modified.
- this 0x1B4: written once at construction (zero); persists until explicitly modified.
- this 0x1B8: written once at construction (zero); persists until explicitly modified.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053c2a0 | GlobalZeroInit_c2a0 | zero-initialize entire object memory |

**Guard conditions:** None — always executes fully.
