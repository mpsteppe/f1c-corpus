// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D5900
// Canonical corpus name: EncodedDataWriterWithXOR
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/EncodedDataWriterWithXOR_004d5900.c

void UnknownObject::EncodedDataWriterWithXOR()
{
    // Encodes and writes a small event record to a byte stream: maps a type selector (0→3, 1→1, 2→2, anything else→0xFF), writes it as a 1-byte tag, then XORs a 4-byte payload value with the key at this+0x8 and writes the result through sub_4D5BE0. Called by LapSplitTimeEvent (004BC390) to encode split-event data.
    // ASSIGNMENT: Map the type selector a2 into a 1-byte tag: 0→3, 1→1, 2→2, and every other value→0xFF. [source:raw]
    // CALL: Write the 1-byte encoded type tag through sub_4D5BE0(&a2, 1). [callee:0x004D5BE0, source:raw]
    // CALCULATION: XOR the payload a3 with the key field at this+0x8: v5 = a3 ^ this[2]. [field:this:0x00000008, source:raw]
    // CALL: Write the 4-byte XOR-encoded payload through sub_4D5BE0(&v5, 4). [callee:0x004D5BE0, source:raw]
    // CALL: Invoked by LapSplitTimeEvent (004BC390) to encode split-event data into the byte stream. [caller:0x004BC390, source:raw]

    // Conservative worker pseudocode:
    //   tag = (a2 == 0) ? 3 : (a2 == 1) ? 1 : (a2 == 2) ? 2 : 0xFF;
    //   sub_4D5BE0(&tag, 1);
    //   encoded = a3 ^ this[2];
    //   return sub_4D5BE0(&encoded, 4);
    // UNRESOLVED: sub_4D5BE0's destination stream (the output buffer or object it writes into) is not resolved in this packet.
    // UNRESOLVED: The origin and lifetime of the XOR key at this+0x8 is not established in this packet.
}
