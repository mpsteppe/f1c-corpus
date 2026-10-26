// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00595550
// Canonical corpus name: BufferFormatHelper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BufferFormatHelper_00595550.c

void UnknownObject::BufferFormatHelper()
{
    // Format-and-parse helper: fills a local 6-element unsigned 16-bit buffer v3 by calling sub_596245(v3, &a2, a2, 0, 0, 0, 0) with a2 passed both by reference and by value plus six zero literal arguments, then returns the result of StringParseViaDelegate(v3, a1), which parses the formatted buffer into the output pointer a1.
    // CALL: Fill the format buffer: call sub_596245(v3, &a2, a2, 0, 0, 0, 0), passing a2 both by reference and by value followed by six zero literal arguments. [callee:0x00596245, source:raw]
    // CALL: Parse the formatted buffer: call StringParseViaDelegate(v3, a1) with the buffer v3 and the caller output pointer a1. [callee:0x00595524, source:raw]
    // RETURN: Return the result of StringParseViaDelegate(v3, a1). [source:raw]

    // Conservative worker pseudocode:
    //   unsigned short v3[6];
    //   sub_596245(v3, &a2, a2, 0, 0, 0, 0);
    //   return StringParseViaDelegate(v3, a1);
    // UNRESOLVED: sub_596245's exact formatting behavior and the meaning of the six zero literal arguments are unresolved; the buffer is evidenced only as a 6-element unsigned 16-bit array.
    // UNRESOLVED: The owning class or subsystem of this __cdecl helper is unknown; caller sub_58BD8F (0x0058BD8F) is the only recorded invocation context.
    // UNRESOLVED: The destination type of a1 (what StringParseViaDelegate writes) is not evidenced in this packet.
}
