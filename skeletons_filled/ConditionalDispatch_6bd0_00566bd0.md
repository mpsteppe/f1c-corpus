## ConditionalDispatch_6bd0_00566bd0 — dispatch read: buffer or file

**Summary:** Routes read operation based on mode flag at this[4] (offset 0x10). If non-zero, reads from buffer with timeout via BufferFillWithTimeout. If zero, reads from file with lock via FileReadWrapperWithLock. File/buffer I/O dispatch.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SpatialHashKeyGeneration (00449ed0), sub_44A4B0 (0044a4b0), sub_44BC50 (0044bc50), FileStreamWriter (004b41e0), FAILWRONGDESCRIPTION_42e0 (004b42e0), FileHandleCloseRegistration (004b4470), sub_4B4FB0 (004b4fb0), VehicleForceAerodynamicsComputation (004b6a10), sub_4B7500 (004b7500), NetworkBufferRead (004b7c80), sub_4BA1F0 (004ba1f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | handle/resource identifier (passed as parameter to read functions) |
| this | 0x10 | R | — | mode flag: non-zero = buffer read, zero = file read |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00535220 | BufferFillWithTimeout | read from memory buffer with timeout |
| 00588678 | FileReadWrapperWithLock | read from file with locking |

**Guard conditions:** this[4] == 0 → FileReadWrapperWithLock (file path). this[4] != 0 → BufferFillWithTimeout (buffer path).
