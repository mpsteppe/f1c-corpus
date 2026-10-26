## StreamRead2ByteTokenParser_00510f89 — Fixed-size 2-byte token reader

**Summary:** Reads a 4-byte token from a byte stream: a 2-byte big-endian size that must equal exactly 4, followed by a 2-byte big-endian value. Stores the extracted value at this+0xFC and dispatches state 81.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CommandDispatchStateMachine (0051126a)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x14)+0x0) | 0x0 | R | — | byte at buffer read pointer (indirect double deref) |
| *(this+0x14) | 0x0 | RW | — | byte stream buffer current read pointer |
| *(this+0x14) | 0x4 | RW | — | byte stream remaining bytes count |
| *(this+0x14) | 0xC | R | — | refill function pointer (v2[3]) |
| obj | 0x0 | R | — | vtable base for state dispatcher (vfunc 0 for error state 9) |
| obj | 0x4 | R | — | second vtable entry for parameterized dispatch (state 81) |
| obj | 0x14 | RW | 81 | state code — 81(token), 9(size mismatch) |
| obj | 0x18 | RW | — | parsed 2-byte big-endian token value |
| this | 0x0 | R | — | pointer to state dispatcher object |
| this | 0x14 | R | — | pointer to byte stream read state struct |
| this | 0xFC | RW | — | token storage — written with the parsed value at end |

**Written-by note (persistence):**
- *(this+0x14) 0x0: updated to point past consumed bytes
- *(this+0x14) 0x4: decremented by bytes consumed
- obj 0x14: written — 81 (success) or 9 (error)
- obj 0x18: written with token value
- this 0xFC: written once with parsed token value

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Big-endian size field (bytes 0-1) must equal exactly 4. If size != 4 (BLOCKED from normal path): set error state 9, call vfunc 0. If size == 4 (PASS): read the 2-byte token value from bytes 2-3, store it, proceed to state 81.
