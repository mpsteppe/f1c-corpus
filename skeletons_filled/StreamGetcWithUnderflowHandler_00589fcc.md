## StreamGetcWithUnderflowHandler_00589fcc — StreamGetChar

**Summary:** Reads one byte from buffered stream. Decrements remaining count, if underflow occurs calls refill handler, otherwise reads byte and advances pointer. Thread-safe via critical section.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** FileReadWithXORDecode (004d5af0), UtilityFunction_8a60 (00568a60), sub_5990AE (005990ae), CharByCharBackwardScanWithValidation (00599707), sub_59A103 (0059a103)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Current read pointer in stream buffer (incremented after read) |
| this | 0x4 | R | — | Remaining byte count in buffer (decremented before read) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058c1b1 | StreamBufferLockViaCriticalSection | Lock stream buffer via critical section for thread safety |
| 0058c203 | AddressRangeCriticalSectionLeave | Unlock stream buffer after read |
| 0058c255 | sub_58C255 | Refill stream buffer on underflow (count went negative) |

**Guard conditions:** Decrements field at this+0x4 (remaining count). If result < 0, buffer underflow: calls sub_58C255 to refill. Otherwise reads byte from *this (current pointer) and increments pointer. Always enters and leaves critical section.
