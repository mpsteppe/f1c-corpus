## ArithmeticComparison_a140_004ba140 — Byte field setter via pointer chain

**Summary:** Stores a byte argument into a nested struct field at offset 0xF80, accessed through pointer at this+0x8. Returns the intermediate pointer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AIBehaviorInitialization (004bf0a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | Pointer to target data struct |
| this | 0xF80 | RW | — | Byte field (flag/state) written with argument a2 |

**Written-by note (persistence):**
- this 0xF80: set per-call to a2; persists until next write

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional write.
