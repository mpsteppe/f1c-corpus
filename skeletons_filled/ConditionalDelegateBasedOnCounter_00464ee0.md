## ConditionalDelegateBasedOnCounter_00464ee0 — Counter-based buffer size lookup

**Summary:** Returns counter value at this[20] if positive; otherwise delegates to BufferSizeLookup with *this as argument.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DivisionWithCapComputation (00464f50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Argument passed to BufferSizeLookup as fallback |
| this | 0x50 | R | — | Counter value; returned directly if positive |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00464e90 | BufferSizeLookup | Maps input to buffer size (called when counter <= 0) |

**Guard conditions:** Checks this[20]. If <= 0, delegates to BufferSizeLookup (PASSES to fallback). If > 0, returns this[20] directly (BLOCKED the fallback path).
