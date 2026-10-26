## ConstructorStub_004353f0 — ConstructorStub

**Summary:** Minimal constructor stub. Clears field at offset 0x9C to 0 and calls PhysicsBufferClear. Returns `this` pointer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DynamicsObjectInitialization (00438c10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x9C | RW | 0 | physics buffer state flag cleared to 0 |

**Written-by note (persistence):**
- this 0x9C: written once (set to 0). Survives.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004358f0 | PhysicsBufferClear | clear/reset physics buffer state |

**Guard conditions:** No guard conditions — all operations unconditional.
