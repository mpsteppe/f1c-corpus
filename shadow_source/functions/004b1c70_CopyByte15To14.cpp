// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B1C70
// Canonical corpus name: sub_4B1C70
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4B1C70_004b1c70.c

void UnknownObject::CopyByte15To14()
{
    // Unconditional byte copy: reads the byte at this[21] (offset +0x15), writes it to this[20] (offset +0x14), and returns the copied byte value. No branches, guards, calls, or globals involved.
    // ASSIGNMENT: Read the byte at this[21] (+0x15) into the result value. [field:this:0x00000015, source:raw]
    // ASSIGNMENT: Write the read byte to this[20] (+0x14), overwriting any previous value. [field:this:0x00000014]
    // RETURN: Return the copied byte value. [source:raw]

    // Conservative worker pseudocode:
    //   char sub_4B1C70(char *this) {
    //     char result = this[21];
    //     this[20] = result;
    //     return result;
    //   }
    // UNRESOLVED: The owner class of this object and the meaning of the +0x14/+0x15 byte fields are unknown.
}
