// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00536560
// Canonical corpus name: DecompressionStreamRead
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DecompressionStreamRead_00536560.c

void UnknownObject::DecompressionStreamRead()
{
    // Buffered decompression-stream read: reads up to a3 bytes from a buffered stream object (a1), clamped to available bytes at stream+4, advancing the internal read pointer and total-read counter, with conditional consumption bookkeeping through sub_537D10 when a flag at *(*(a1+28)+24) is clear.
    // CALCULATION: clamp requested count: v4 = min(available bytes at stream+4, requested a3) [source:raw]
    // GUARD: if v4 is zero, return 0 immediately (nothing readable) [source:raw]
    // ASSIGNMENT: reduce remaining-bytes counter at stream+4 by v4 [source:raw]
    // GUARD: if the flag at *(*(stream+28)+24) is zero, run consumption bookkeeping and store its result at stream+48 [source:raw]
    // CALL: call sub_537D10(v4); result written into stream+48 [callee:0x00537D10, source:raw]
    // ASSIGNMENT: copy v4 bytes from the current buffer pointer at stream+0 into destination a2 [source:raw]
    // ASSIGNMENT: advance the current buffer pointer at stream+0 by v4 [source:raw]
    // ASSIGNMENT: accumulate v4 into the total-read counter at stream+8 [source:raw]
    // RETURN: return v4 (number of bytes actually read) [source:raw]

    // Conservative worker pseudocode:
    //   avail = this->bytes_remaining;
    //   n = (avail > requested) ? requested : avail;
    //   if (n == 0) return 0;
    //   this->bytes_remaining -= n;
    //   if (*(this->source_or_flag + 24) == 0) this->consumed = sub_537D10(n);
    //   copy_n(dest, this->cursor, n);
    //   this->cursor += n;
    //   this->total_read += n;
    //   return n;
    // UNRESOLVED: exact role of the value returned by sub_537D10 and stored at stream+48 (consumed/read bookkeeping)
    // UNRESOLVED: identity of the object behind stream+28 and the meaning of its +24 flag
    // UNRESOLVED: whether stream+8 is a total-bytes-read counter or an unrelated accumulator
}
