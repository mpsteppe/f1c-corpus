## ShortComputation_ac20_004bac20 — ListNode triple-field initializer

**Summary:** Initializes a 3-field node struct: sets data value (a2), zeroes next pointer, sets byte flag (a3). Returns this.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DirectoryFileEnumerator (00431db0), sub_490D00 (00490d00), CollisionBroadphaseBuilder (00490ee0), CollisionObjectListManagement (004b4b50), PhysicsObjectListManager (004b4e10), CollisionFilterAABBCull (004b5630), AIPathPerformanceFunction (004bfa00), NetworkConnectionListDuplication (0057b330)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Node data value/pointer (set from a2) |
| this | 0x4 | RW | 0 | Node next pointer (initialized to null) |
| this | 0x8 | RW | — | Node byte flag (set from a3) |

**Written-by note (persistence):**
- this 0x0: written per call with a2
- this 0x4: written to 0 per call
- this 0x8: written per call with a3

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional initializer.
