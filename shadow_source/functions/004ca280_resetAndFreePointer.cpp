// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004CA280
// Canonical corpus name: sub_4CA280
// Owner: SpecialFX [DERIVED]
// Raw source: functions/sub_4CA280_004ca280.c

void SpecialFX::resetAndFreePointer()
{
    // Reset/cleanup routine for a 15-dword object called by both SpecialFX_Init (0x004CF070) and SpecialFX_Post (0x004CFED0). Zeroes all 15 dwords this[0]..this[14] (offsets 0x0..0x38). Before clearing the pointer slot it saves this[14], frees the saved pointer through FreeWrapper_7bcf when non-null, then stores the free result as the return value. Effectively clears every field and releases the one owned allocation held at offset 0x38.
    // ASSIGNMENT: Zero the first four dwords this[0]..this[3] (offsets 0x0, 0x4, 0x8, 0xC). [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Save the pointer held at this[14] (offset 0x38) into result before the slot is cleared. [field:this:0x00000038, source:raw]
    // ASSIGNMENT: Zero dwords this[4]..this[13] (offsets 0x10, 0x14, 0x18, 0x1C, 0x20, 0x24, 0x28, 0x2C, 0x30, 0x34). [field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030, field:this:0x00000034, source:raw]
    // CALL: If the saved pointer at this[14] is non-null, release it via FreeWrapper_7bcf and keep the free result. [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Clear the freed pointer slot: this[14] = 0 (offset 0x38). [field:this:0x00000038, source:raw]
    // RETURN: Return the previously saved (and now freed) pointer value. [source:raw]

    // Conservative worker pseudocode:
    //   this[0] = 0; this[1] = 0; this[2] = 0; this[3] = 0;
    //   result = this[14];
    //   this[4] = 0; this[5] = 0; this[6] = 0; this[7] = 0; this[8] = 0;
    //   this[9] = 0; this[10] = 0; this[11] = 0; this[12] = 0; this[13] = 0;
    //   if (result) result = FreeWrapper_7bcf(result);
    //   this[14] = 0;
    //   return result;
    // UNRESOLVED: The object layout (15 dwords with an owned pointer slot at +0x38) and the identity of the freed allocation are not established by the packet.
    // UNRESOLVED: The routine is called by both SpecialFX_Init (0x004CF070) and SpecialFX_Post (0x004CFED0); whether it is a constructor, destructor or standalone reset helper is not proven.
    // UNRESOLVED: The caller-derived owner SpecialFX is DERIVED only; the actual class type is unverified.
}
