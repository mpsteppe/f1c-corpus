## RingBufferWriteWithBoundsCheck_00516531 — RingBufferWriteValidate

**Summary:** Validates write parameters against ring buffer state at a2: checks capacity (a2+4), max write size (a2+12), and buffer existence. Updates write position (a2+24) and written-position bound (a2+28). Optionally zero-fills new elements or dispatches via sub_51641E. Returns pointer into buffer array at computed offset.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x14 | W | 20 | written with error code 20 (capacity/flag validation failure) or 68 (bounds check failure) |

**Written-by note (persistence):**
- obj 0x14: written conditionally on validation failures with error codes

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005159a8 | MemoryZeroFill | zero-fills element at given pointer to given size |
| 0051641e | sub_51641E | dispatches chunks via selected callback for out-of-bounds regions |

**Guard conditions:**
1. a3 + a4 > *(a2+4) OR a4 > *(a2+12) OR *(a2) == NULL: capacity/write-size/existence check fails — error (code 20), but continues with v6 set
2. a3 < v7 OR v5 > v7 + *(a2+16): write range outside current position window — enters reposition path
   - *(a2+34) == 0: reprocess not allowed — error (code 68)
   - *(a2+33) != 0: needs reprocess — dispatches sub_51641E with flag 1, then clears flag
   - a3 <= v7: special-case reposition when start before current position
3. v9 (*(a2+28)) < v5: written-position bound exceeded
   - v9 >= a3: use current bound as start
   - otherwise: if a5 flag set → error (code 20); else use a3 as start
   - a5 flag: updates *(a2+28) to v5
   - *(a2+32) != 0: zero-fill elements from v10 to v5
   - *(a2+32) == 0 AND a5 == 0: error (code 20)
4. a5 != 0: final path — sets flag *(a2+33)=1, returns early with pointer into buffer
