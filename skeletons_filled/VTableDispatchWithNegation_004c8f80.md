## VTableDispatchWithNegation_004c8f80 — VTableDispatchWithNegation

**Summary:** Stores parameter handle, retrieves scene node position, negates Y coordinate, then dispatches vtable method at offset 4. Returns 1 if a2 is null.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetworkMessageReceiveAndDispatch (004c7ca0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | VTable pointer |
| this | 0x4 | RW | — | Stored parameter/handle from a2 |
| this | 0xC | RW | — | Y-position (negated before dispatch) |

**Written-by note (persistence):**
- this 0x4: Set to a2 on each call; persists until next call
- this 0xC: Set by SceneNodePositionGetter then negated; persists position value

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054b950 | SceneNodePositionGetter | Reads scene node position into 3 float outputs (X, Y, Z) |

**Guard conditions:** a2 must be non-null; if null, returns 1 immediately.
