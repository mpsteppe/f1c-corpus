## ErrorHandlerSet_0053ce10 — MASLoadWithErrorFlagSet

**Summary:** Wrapper around MAS file loader that sets bit 3 (value 8) at offset 0x114 of the loaded object on success. Marks the object for error handling state.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SceneFileTopLevelParser (0055b200)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x114 | RW | — | Flags field (bit 3 = error-handling state flag) |
| this | 0x0 | R | — | Pointer to loaded object (dereferenced from a1) |

**Written-by note (persistence):**
- obj 0x114: conditional — set to |= 8 only on successful load; external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053cbc0 | sub_53CBC0 | CubeMapMASFileLoader — loads MAS file and creates physics object |

**Guard conditions:** Checks sub_53CBC0 return value: only proceeds if result == 0 (success). Also checks a1 pointer is non-null before writing flag at offset 0x114.
