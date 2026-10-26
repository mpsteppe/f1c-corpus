## FlagCheckWithConditionalPathDispatch_005575f0 — FlagGuardedInitDispatch

**Summary:** Check object flags: if bit 0x400 is set, return immediately (already initialized). Otherwise dispatch to one of two init paths based on bit 0x8, then set bit 0x400 on success.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_544740 (00544740)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x20 | RW | — | Flags bitmask: bit 0x8 = dispatches to Return0Stub vs sub_558310; bit 0x400 = init-done guard |

**Written-by note (persistence):**
- this 0x20: Bit 0x400 set once on success; survives external pokes between calls; bits persist until explicitly cleared

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0047abb0 | Return0Stub | Returns 0 unconditionally |
| 00558310 | sub_558310 | Init function; returns 0 on success, non-zero on failure |

**Guard conditions:**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x20 | & | 0x8 | Flags bit 3 — path selector |
| this | 0x20 | & | 0x400 | Flags bit 10 — init-done guard |

**Guard interpretation:** Bit 0x400 check: PASS if set → return 0 early (already done), BLOCKED if clear → proceed with init. Bit 0x8 dispatches: PASS = take Return0Stub path, FAIL = take sub_558310 path. Both paths return -1 if the called function returns non-zero.
