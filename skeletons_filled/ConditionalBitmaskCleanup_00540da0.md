## ConditionalBitmaskCleanup_00540da0 — Conditional buffer/surface cleanup via bitmask

**Summary:** Conditionally resets buffer lock at a1[8] (via ArithmeticComparison_0f90) when a2 bit 4 set, and surface lock at a1[10] (via GuardedVirtualDecrement) when a2 bit 8 set. Zeroes the pointer after cleanup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_557670 (00557670), sub_558310 (00558310)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1C | R | — | this[7] — buffer pointer argument to ArithmeticComparison_0f90 |
| this | 0x20 | RW | 0 | this[8] — set to 0 after ArithmeticComparison_0f90 |
| this | 0x24 | R | — | this[9] — surface pointer argument to GuardedVirtualDecrement |
| this | 0x28 | RW | 0 | this[10] — set to 0 after GuardedVirtualDecrement |

**Written-by note (persistence):**
- this 0x20: set to 0 after cleanup — cleared
- this 0x28: set to 0 after cleanup — cleared

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00540f90 | ArithmeticComparison_0f90 | comparison/release for buffer lock |
| 005410f0 | GuardedVirtualDecrement | guarded decrement/release for surface lock |

**Guard conditions:** If a1 is null → no-op. If a2 & 4 → calls ArithmeticComparison_0f90 on this[7], sets this[8]=0. If a2 & 8 → calls GuardedVirtualDecrement on this[9], sets this[10]=0.
