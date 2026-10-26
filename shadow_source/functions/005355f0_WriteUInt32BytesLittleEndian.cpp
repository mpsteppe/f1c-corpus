// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005355F0
// Canonical corpus name: ArithmeticComparison_55f0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArithmeticComparison_55f0_005355f0.c

void UnknownObject::WriteUInt32BytesLittleEndian()
{
    // Fastcall helper that serializes the 32-bit value a2 to a buffered character writer as four bytes, least-significant byte first (little-endian). Repeats exactly four times: each iteration writes the low byte of a2 via BufferedCharacterWriteWithOverflowHandling((unsigned __int8)a2, a1), then shifts a2 right by 8. Returns the result of the last write.
    // ASSIGNMENT: Initialize the loop counter v4 to 4. [source:raw]
    // LOOP: do-while loop that runs exactly four iterations (one per byte of a2). [source:raw]
    // CALL: Each iteration writes the low byte of a2: BufferedCharacterWriteWithOverflowHandling((unsigned __int8)a2, a1); its return value is stored as result. [callee:0x00589898, source:raw]
    // CALCULATION: Shift the source value to expose the next byte: a2 >>= 8. [source:raw]
    // CALCULATION: Decrement the loop counter: --v4. [source:raw]
    // RETURN: Return the result of the last BufferedCharacterWriteWithOverflowHandling call. [source:raw]
    // CALL: Invoked by StreamFileTypeCheckWithDispatch (0x005355A0) to emit a 32-bit quantity into a serialized stream. [caller:0x005355A0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_5355F0(int a1, unsigned int a2) {
    //     int result;
    //     int v4 = 4;
    //     do {
    //       result = BufferedCharacterWriteWithOverflowHandling((unsigned __int8)a2, a1);
    //       a2 >>= 8;
    //       --v4;
    //     } while (v4);
    //     return result;
    //   }
    // UNRESOLVED: Role of a1 (destination/buffer context) passed to BufferedCharacterWriteWithOverflowHandling depends on the caller.
    // UNRESOLVED: Whether the four bytes are a raw little-endian integer, a checksum, or a fixed-size tag is caller-dependent.
}
