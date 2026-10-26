// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00598D6D
// Canonical corpus name: OutputStreamWriteWithBufferFlushAbstraction
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/OutputStreamWriteWithBufferFlushAbstraction_00598d6d.c

void UnknownObject::BufferedWriteWithFlush()
{
    // Writes bytes to a buffered output stream. While a requested count a3 remains, it copies into an internal buffer (pointer at this+0x20, remaining space at this+0x30) when both are valid, using MemoryCopy_cc00; otherwise it calls the vtable method at obj+0x4 (index 1) to flush or write a single byte. Returns the total number of bytes written.
    // ASSIGNMENT: Initialize v8 to 0, the running total of bytes written. [source:raw]
    // LOOP: while (a3 > 0) — iterate until the requested byte count a3 is fully written. [source:raw]
    // GUARD: If the buffer pointer at this+0x20 is non-null and the remaining space at this+0x30 is greater than 0, take the buffered-copy path. [field:this:0x00000020, field:this:0x00000030]
    // CALCULATION: Compute v6 = min(a3, remaining space at this+0x30), the number of bytes that fit this iteration. [field:this:0x00000030]
    // CALL: MemoryCopy_cc00 copies v6 bytes from the input buffer a2 into the internal buffer at this+0x20. [callee:0x0058CC00, field:this:0x00000020]
    // CALCULATION: Advance the write state: v8 += v6, a3 -= v6, remaining space at this+0x30 -= v6, a2 += v6, and buffer pointer at this+0x20 += v6. [field:this:0x00000020, field:this:0x00000030]
    // CALL: When the buffer path is unavailable, invoke the flush/write method stored in the vtable at obj+0x4 (index 1) with one byte read from a2. [field:obj:0x00000004, field:this:0x00000000]
    // GUARD: If the flush/write call returns -1 (error), return v8 early. [field:obj:0x00000004]
    // ASSIGNMENT: Otherwise advance a2, increment v8, and decrement a3. [source:raw]
    // RETURN: Return v8, the total number of bytes written. [source:raw]

    // Conservative worker pseudocode:
    //   int BufferedWriteWithFlush(_DWORD **this, _BYTE *src, int count) {
    //     int total = 0;
    //     while (count > 0) {
    //       _BYTE *buf = (_BYTE *)*this[8];  /* this+0x20 * /
    //       int space = *this[12];           /* this+0x30 * /
    //       if (buf && space > 0) {
    //         int n = (count < space) ? count : space;
    //         MemoryCopy_cc00((unsigned int)buf, src, n);
    //         total += n; count -= n;
    //         *this[12] -= n; src += n; *this[8] += n;
    //       } else {
    //         if (((int (__thiscall *)(_DWORD **, _DWORD))(*this)[1])(this, (unsigned __int8)*src) == -1) return total;
    //         ++src; ++total; --count;
    //       }
    //     }
    //     return total;
    //   }
    // UNRESOLVED: Identity of the vtable method at index 1 (obj+0x4) is caller/constructor supplied and unknown here.
    // UNRESOLVED: Stream object class and the exact layout of the internal buffer fields at this+0x20 / this+0x30 are unresolved.
}
