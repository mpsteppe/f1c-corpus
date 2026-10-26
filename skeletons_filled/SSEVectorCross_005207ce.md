## SSEVectorCross_005207ce — SSEVectorCrossProduct

**Summary:** Computes 3D cross product of three vectors (a2, a3, a4) using SSE intrinsics. Algorithm is identical to SSE3DCrossProductWith33Matrix (load/shuffle/multiply/subtract/add) but uses a distinct XOR mask (xmmword_5D8C20) for sign flip. Stores result in output __m128 at a1. Part of SSE math library.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Output __m128 result of 3D cross product |

**Written-by note (persistence):**
- this 0x0: unconditionally written with cross product result; persists as output

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d8c20 | xmmword_5D8C20 | R | XOR mask for cross product sign flip (right-hand rule) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard — always computes cross product unconditionally.
