// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00464C10
// Canonical corpus name: LargeStructInitialization
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LargeStructInitialization_00464c10.c

void UnknownObject::LargeStructInitialization()
{
    // Constructor-style initialization of a large collision-sensor object: zeroes the leading dword block (this[27..34] = this+0x6C..0x88) after StructZeroInit_8ba0(this+1), then creates 104 sensor entries on a 560-byte stride — each constructed via sub_401000 with callback sub_464D20, per-entry zero fields, an 8-byte allocated tracking node (entry backref + a float bit pattern), a node pointer field, and CollisionSensorInit. Afterwards zeroes the tail dwords this+0xE5B0..0xE5CC, initializes the QPC timer, sets scale defaults (1.0f at this+0x60/+0x64) and -1 sentinels (this+0x50/+0x54), and fills an 0x1A0-byte block at this+0xE410 with 0xFF.
    // CALL: Zero the leading block: StructZeroInit_8ba0(this+1) from byte offset 4, followed by explicit zero writes to the eight dword fields this+0x6C, this+0x70, this+0x74, this+0x78, this+0x7C, this+0x80, this+0x84, this+0x88. [callee:0x00568BA0, field:this:0x0000006C, field:this:0x00000070, field:this:0x00000074, field:this:0x00000078, field:this:0x0000007C, field:this:0x00000080, field:this:0x00000084, field:this:0x00000088, source:raw]
    // LOOP: Sensor-entry creation loop: 104 iterations over 560-byte-stride entries starting at this+0x8C. Each entry calls sub_401000(entry, 1, 104, sub_464D20) with the callback sub_464D20, zeroes the dword fields entry+0x2AC and entry+0x2B0, zeroes the word at entry+0x2B4, allocates an 8-byte tracking node via OperatorNewNhMallocWrapper (storing the entry backref and the -1082130432 float; null on failure), saves the node pointer at entry+0x2B8, and calls CollisionSensorInit(entry). [callee:0x00401000, global:0x00464D20, callee:0x00587C03, callee:0x00464A40, field:this:0x000002AC, field:this:0x000002B0, field:this:0x000002B4, field:this:0x000002B8, source:raw]
    // ASSIGNMENT: Zero the eight tail dwords this+0xE5B0, this+0xE5B4, this+0xE5B8, this+0xE5BC, this+0xE5C0, this+0xE5C4, this+0xE5C8, this+0xE5CC. [field:this:0x0000E5B0, field:this:0x0000E5B4, field:this:0x0000E5B8, field:this:0x0000E5BC, field:this:0x0000E5C0, field:this:0x0000E5C4, field:this:0x0000E5C8, field:this:0x0000E5CC, source:raw]
    // CALL: Initialize the high-resolution timer: QPCTimerInitialization(1). [callee:0x00568BE0, source:raw]
    // ASSIGNMENT: Default scale and sentinels: write 1065353216 (1.0f) to this+0x60 and this+0x64; write the -1 sentinel to this+0x50 and this+0x54. [field:this:0x00000060, field:this:0x00000064, field:this:0x00000050, field:this:0x00000054, source:raw]
    // ASSIGNMENT: Zero this+0xE40C and fill the 0x1A0-byte block at this+0xE410 with 0xFF bytes via memset. [field:this:0x0000E40C, source:raw]
    // RETURN: Return the initialized object pointer (this). [function:0x00464C10, source:raw]

    // Conservative worker pseudocode:
    //   StructZeroInit_8ba0(this+1);
    //   this[27..34] = 0;  // this+0x6C .. this+0x88
    //   cursor = this+0x8C;
    //   for (n = 104; n > 0; n--) {
    //     sub_401000(cursor, 1, 104, sub_464D20);
    //     cursor[0x2AC] = 0; cursor[0x2B0] = 0; *(word*)(cursor+0x2B4) = 0;
    //     node = OperatorNewNhMallocWrapper(8);
    //     if (node) { node[0] = cursor; node[1] = -1082130432; }
    //     cursor[0x2B8] = node;
    //     CollisionSensorInit(cursor);
    //     cursor += 560;
    //   }
    //   this[14700..14707] = 0;  // this+0xE5B0 .. this+0xE5CC
    //   QPCTimerInitialization(1);
    //   this[0x64] = this[0x60] = 1065353216;  // 1.0f
    //   this[0x50] = this[0x54] = -1;
    //   this[0xE40C] = 0;
    //   memset(this+0xE410, 0xFF, 0x1A0);
    //   return this;
    // UNRESOLVED: The memset region at this+0xE410 (0x1A0 bytes) is not enumerated among the packet fields; its end falls just below the zeroed this+0xE5B0 tail block.
    // UNRESOLVED: The literal -1082130432 written to the tracking node's second dword is a two's-complement bit pattern equal to -1.0f as a float; its role is DERIVED, not stated in the packet.
    // UNRESOLVED: The dword-index writes (this[20/21/24/25/27..34/14595/14700..14707]) are mapped to byte offsets arithmetically; the packet enumerates only the resulting byte offsets.
    // UNRESOLVED: The object is a large collision-sensor container per existing analysis, but no class symbol is present in the packet, so owner identity stays unknown.
    // UNRESOLVED: The single caller (SingleFunctionCallWrapper_4930 0x00464930) is listed but not exercised in the body.
}
