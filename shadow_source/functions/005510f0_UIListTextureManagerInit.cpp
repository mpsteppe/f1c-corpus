// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005510F0
// Canonical corpus name: sub_5510F0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5510F0_005510f0.c

void UnknownObject::UIListTextureManagerInit()
{
    // Constructor-style initializer for a UI list/texture manager object. Zero-initializes the whole struct via GlobalZeroInit_c2a0, allocates and initializes a 76-byte sub-object (sub_556220) stored at this+0x0, registers the object via sub_556260(1), allocates a count array of 136-byte stride scale-default elements with a leading count header, and fills the remaining fields: count at this+0x14, array pointer at this+0x18, zeroed fields at this+0x8/0xC/0x10/0x1C/0x20/0x24, and the constant flag 0x20000 at this+0x4. Returns the object pointer.
    // CALL: Zero-initialize the whole struct with GlobalZeroInit_c2a0(this). [callee:0x0053C2A0, source:raw]
    // ASSIGNMENT: Allocate a 76-byte sub-object via OperatorNewNhMallocWrapper, initialize it with sub_556220, and store the resulting pointer at this+0x0 (null when the allocation fails). [callee:0x00587C03, callee:0x00556220, field:this:0x00000000, source:raw]
    // CALL: Register the object through sub_556260(1) after the sub-object is attached. [callee:0x00556260, source:raw]
    // CALCULATION: Allocate the element array with OperatorNewNhMallocWrapper sized 136 * a2 + 4 bytes: a 4-byte count header plus a2 elements of 136-byte stride. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Store the element count a2 in the array header at v6[0] and point v7 at the first element slot v6 + 1. [source:raw]
    // LOOP: When the count minus 1 is non-negative, iterate a2 times calling StructInitWithScaleDefaults on each element slot, advancing by 34 dwords (136 bytes) per element. [callee:0x00550760, source:raw]
    // ASSIGNMENT: Clear the fields at this+0x8, this+0xC, this+0x10, this+0x1C, this+0x20 and this+0x24 to zero. [field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, source:raw]
    // ASSIGNMENT: Store the element array pointer v7 at this+0x18 and the saved element count at this+0x14; v7 is the first element slot on success or null on allocation failure. [field:this:0x00000018, field:this:0x00000014, source:raw]
    // ASSIGNMENT: Set the constant flag 0x20000 at this+0x4. [field:this:0x00000004, source:raw]
    // RETURN: Return the initialized object pointer this. [source:raw]

    // Conservative worker pseudocode:
    //   GlobalZeroInit_c2a0(this);
    //   v3 = OperatorNewNhMallocWrapper(76);
    //   *this = v3 ? sub_556220(v3) : 0;
    //   sub_556260(1);
    //   v5 = a2;
    //   v6 = OperatorNewNhMallocWrapper(136 * a2 + 4);
    //   if (v6) {
    //     v7 = v6 + 1;
    //     *v6 = a2;
    //     v8 = v6 + 1;
    //     if (a2 - 1 >= 0) {
    //       do { StructInitWithScaleDefaults(v8); v8 += 34; --a2; } while (a2);
    //     }
    //   } else {
    //     v7 = 0;
    //   }
    //   this[2] = 0; this[3] = 0; this[4] = 0;
    //   this[7] = 0; this[8] = 0; this[9] = 0;
    //   this[6] = (int)v7;
    //   this[5] = v5;
    //   this[1] = 0x20000;
    //   return this;
    // UNRESOLVED: The purpose of the 76-byte sub-object constructor sub_556220 (0x00556220) and the registration helper sub_556260 (0x00556260) are inferred from the surrounding init sequence only.
    // UNRESOLVED: The meaning of the 0x20000 flag at this+0x4 and the element type of the 136-byte stride array are caller-contract details not documented in this function.
    // UNRESOLVED: Element count is stored both in the array header (v6[0]) and at this+0x14; which one is authoritative for consumers is unknown here.
}
