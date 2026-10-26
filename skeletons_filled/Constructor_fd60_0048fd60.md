## Constructor_fd60_0048fd60 — UIStructConstructor

**Summary:** Constructor for a UI structure. Calls base init, sets vtable pointer, and zero-initializes a field.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ObjectNameComparison (00477280)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | VTable pointer |
| this | 0x30 | RW | 0 | Some field initialized to zero |

**Written-by note (persistence):**
- this 0x0: Once — set to vtable pointer at construction; survives unless deliberately changed.
- this 0x30: Once — zero-initialized; persists until explicitly modified.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ac69c | off_5AC69C | R | VTablePtr [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048e9e0 | UIStructInit_e9e0 | Base struct initializer (zeroes or sets defaults) |

**Guard conditions:** None — unconditional constructor; no null checks or early returns.
