## StateCounterWithDispatch_00511457 — JPEG restart marker counter

**Summary:** JPEG RST marker (208-215) handler that tracks the expected restart interval counter. Compares the current marker against the expected value (this+0x1E4 + 208), dispatches state 97 on match, and increments the counter modulo 8. Falls back to an alternative handler on mismatch.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4 | R | — | second vtable entry for parameterized dispatch (state 97) |
| obj | 0x14 | RW | 97 | state code — 97 when expected RST marker found |
| obj | 0x18 | RW | — | current restart counter value (0-7) before increment |
| this | 0x0 | R | — | pointer to state dispatcher object |
| this | 0x14 | R | — | pointer to byte stream read state struct (v2[5] = alternative handler) |
| this | 0x28 | R | — | some limit/constant (unused in this function) |
| this | 0x178 | RW | 0 | current marker byte — checked/consumed by this function |
| this | 0x190 | R | — | pointer to sub-object with restart counter at +0x54 |
| this | 0x1E4 | RW | — | restart counter (0-7) — expected marker = counter + 208; incremented mod 8 |

**Written-by note (persistence):**
- obj 0x14: written to 97 on match
- obj 0x18: written with counter before increment
- this 0x178: reset to 0 after successful match dispatch
- this 0x1E4: incremented ((n+1) & 7) on success or alternative handler acceptance

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005110fc | BitstreamTokenReader | reads the next marker from byte-stuffed stream when this+0x178 is 0 |

**Guard conditions:** If this+0x178 (current marker) is 0: call BitstreamTokenReader to read next marker (PASS if reader returns success). Then check if marker == this+0x1E4 + 208 (expected RST). If match (PASS): dispatch state 97, reset counter. If no match (BLOCKED): call alternative handler at v2[5]; if that also fails, return 0.
