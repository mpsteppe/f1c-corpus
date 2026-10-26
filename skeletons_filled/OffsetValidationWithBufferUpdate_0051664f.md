## OffsetValidationWithBufferUpdate_0051664f — BufferWriteValidateOffset

**Summary:** Validates write parameters against buffer state at a2, similar to RingBufferWriteValidate but with alternative reposition logic (sets position to a3 on else) and different zero-fill stride (element_size * 128). Dispatches out-of-bounds regions via sub_5164A6.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | first field of sub-object, read for vtable dispatch on error |
| obj | 0x14 | RW | 20 | written with error codes 20 (capacity/flag failure) or 68 (bounds failure) |
| this | 0x0 | R | — | vtable pointer for virtual dispatch of error handlers |

**Written-by note (persistence):**
- obj 0x14: written conditionally on validation failures with error codes

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005159a8 | MemoryZeroFill | zero-fills elements with size (element_size * 128) |
| 005164a6 | sub_5164A6 | dispatches chunks via callback for out-of-bounds regions |

**Guard conditions:**
1. a3+a4 > *(a2+4) OR a4 > *(a2+12) OR *(a2) == NULL: capacity/write-size/buffer check fails — error (code 20)
2. a3 < v7 OR v6 > v7 + *(a2+16): write range outside position window — enters reposition path
   - *(a2+34) == 0: reprocess not allowed — error (code 68)
   - *(a2+33) != 0: needs reprocess — dispatches sub_5164A6(flag=1), clears flag
   - a3 <= v7: reposition using v5-*(a2+16) clamped to 0
   - else: reposition to a3
3. v9 (*(a2+28)) < v6: written-position bound exceeded
   - v9 < a3 AND a5 == 0: error (code 20); if a5 set, use a3 as start
   - a5: updates *(a2+28) to v6
   - *(a2+32) != 0: zero-fill elements (size = element_size * 128) from v9 to v6
   - *(a2+32) == 0 AND a5 == 0: error (code 20)
4. a5 != 0: final path — sets flag *(a2+33)=1, returns early with buffer pointer
