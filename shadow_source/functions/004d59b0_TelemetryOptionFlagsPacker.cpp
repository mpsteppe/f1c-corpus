// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D59B0
// Canonical corpus name: sub_4D59B0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4D59B0_004d59b0.c

void UnknownObject::TelemetryOptionFlagsPacker()
{
    // Packs eleven per-car option flags from byte_7C749A into a bitfield at two bits per flag, appends two dword option values, one conditional bit based on a field of the player vehicle object, and two more byte flags, then writes the packed dword and five float physics values through the sub_4D5BE0 data writer. Two float values are written with a 273.16 offset (Celsius-to-Kelvin baseline).
    // CALL: Write a single header byte of value 4 through sub_4D5BE0 with size 1. [callee:0x004D5BE0, source:raw]
    // LOOP: Iterate v1 from 0 to 10 (eleven option flags) reading byte_7C749A[v1] and accumulating each value shifted into a bitfield at two-bit steps. [global:0x007C749A, source:raw]
    // GUARD: At index 5, when dword_7CEA5C is zero, force the option flag value to 1 before packing. [global:0x007CEA5C, source:raw]
    // CALCULATION: Accumulate each flag shifted left by the running bit offset and advance the offset by two bits per flag. [source:raw]
    // CALCULATION: Append dword_7CE6D0 at the current bit offset and dword_7CE958 two bits further into the packed value. [global:0x007CE6D0, global:0x007CE958, source:raw]
    // GUARD: If the dword at player vehicle object dword_7C54E8 plus field offset 4180 equals 1, add one additional bit at the next bit position. [global:0x007C54E8, source:raw]
    // CALCULATION: Append byte_7CE88C and byte_7CE874 as two more packed bits to produce the final bitfield value. [global:0x007CE88C, global:0x007CE874, source:raw]
    // CALL: Write the packed four-byte bitfield through sub_4D5BE0 with size 4. [callee:0x004D5BE0, source:raw]
    // CALL: Write float flt_8AFEE4 through sub_4D5BE0 with size 4. [global:0x008AFEE4, callee:0x004D5BE0, source:raw]
    // CALL: Write float flt_8AFEE8 through sub_4D5BE0 with size 4. [global:0x008AFEE8, callee:0x004D5BE0, source:raw]
    // CALL: Write float flt_8AFEEC through sub_4D5BE0 with size 4. [global:0x008AFEEC, callee:0x004D5BE0, source:raw]
    // CALL: Write float flt_8AFEF0 incremented by 273.16 through sub_4D5BE0 with size 4. [global:0x008AFEF0, callee:0x004D5BE0, source:raw]
    // CALL: Write float flt_8AFEF4 incremented by 273.16 through sub_4D5BE0 with size 4. [global:0x008AFEF4, callee:0x004D5BE0, source:raw]
    // RETURN: Return the result of the final sub_4D5BE0 write. [callee:0x004D5BE0, source:raw]

    // Conservative worker pseudocode:
    //   void pack_telemetry_flags() {
    //     char hdr = 4;
    //     writer(&hdr, 1);
    //     int packed = 0;
    //     int shift = 0;
    //     for (int i = 0; i < 11; ++i) {
    //       int flag = byte_7C749A[i];
    //       if (i == 5 && !dword_7CEA5C) flag = 1;
    //       packed += flag << shift;
    //       shift += 2;
    //     }
    //     packed += dword_7CE6D0 << shift;
    //     shift += 2;
    //     packed += dword_7CE958 << shift;
    //     shift += 1;
    //     if (*(int *)(dword_7C54E8 + 4180) == 1) packed += 1 << shift;
    //     packed += byte_7CE88C << (shift + 2);
    //     packed += byte_7CE874 << (shift + 1);
    //     writer(&packed, 4);
    //     float f;
    //     f = flt_8AFEE4;   writer(&f, 4);
    //     f = flt_8AFEE8;   writer(&f, 4);
    //     f = flt_8AFEEC;   writer(&f, 4);
    //     f = flt_8AFEF0 + 273.16; writer(&f, 4);
    //     f = flt_8AFEF4 + 273.16; writer(&f, 4);
    //   }
    // UNRESOLVED: Meaning of the packed flag values (per-option 2-bit codes) is not derivable from this function alone.
    // UNRESOLVED: The dword_7C54E8 object at offset 4180 (player vehicle) is read but its field meaning is unknown here.
    // UNRESOLVED: flt_5ACAFC appears in the packet globals but is not read anywhere in the raw source text.
}
