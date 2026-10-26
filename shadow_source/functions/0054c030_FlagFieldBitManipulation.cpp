// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054C030
// Canonical corpus name: FlagFieldBitManipulation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FlagFieldBitManipulation_0054c030.c

void UnknownObject::FlagFieldBitManipulation()
{
    // Manipulates bits 0x2 and 0x4 of the flag field at this[15] (offset 0x3C) driven by a2 and a3: a2==1 clears bit 0x2, a2==0 sets bits 0x2 and 0x4; a3==1 clears bit 0x4, a3==0 sets bit 0x4. When a4==1, recursively propagates the operation to the child objects referenced at this[17] (offset 0x44) and, if a5 is set and this[19] (offset 0x4C) is non-null, to that second child as well.
    // GUARD: If a4 == 1, propagation of the operation to child objects is enabled. [source:raw]
    // GUARD: If this[17] (child pointer at offset 0x44) is non-null, propagate. [field:this:0x00000044, source:raw]
    // CALL: Recursive call FlagFieldBitManipulation(a2, a3, 1, 1) to propagate the operation to the first child. [callee:0x0054C030, field:this:0x00000044, source:raw]
    // GUARD: If a5 is set and this[19] (child pointer at offset 0x4C) is non-null, propagate to the second child. [field:this:0x0000004C, source:raw]
    // CALL: Recursive call FlagFieldBitManipulation(a2, a3, 1, 1) to propagate the operation to the second child. [callee:0x0054C030, field:this:0x0000004C, source:raw]
    // ASSIGNMENT: If a2 == 1, compute v6 = this[15] & 0xFFFFFFFD, clearing bit 0x2 of the flag field at offset 0x3C. [field:this:0x0000003C, source:raw]
    // ASSIGNMENT: If a2 == 0, compute v6 = this[15] | 6, setting bits 0x2 and 0x4 of the flag field at offset 0x3C. [field:this:0x0000003C, source:raw]
    // ASSIGNMENT: Store the new value back into this[15] (offset 0x3C) for the a2 == 1 and a2 == 0 branches. [field:this:0x0000003C, source:raw]
    // ASSIGNMENT: If a3 == 1, this[15] &= ~4, clearing bit 0x4 of the flag field at offset 0x3C. [field:this:0x0000003C, source:raw]
    // ASSIGNMENT: If a3 == 0, this[15] |= 4, setting bit 0x4 of the flag field at offset 0x3C. [field:this:0x0000003C, source:raw]

    // Conservative worker pseudocode:
    //   void FlagFieldBitManipulation(int *this, int a2, int a3, int a4, int a5) {
    //       if (a4 == 1) {
    //           if (this[17])
    //               FlagFieldBitManipulation(a2, a3, 1, 1);
    //           if (a5 && this[19])
    //               FlagFieldBitManipulation(a2, a3, 1, 1);
    //       }
    //       if (a2 == 1) {
    //           this[15] &= 0xFFFFFFFD;
    //       } else if (a2 == 0) {
    //           this[15] |= 6;
    //       }
    //       if (a3 == 1) {
    //           this[15] &= ~4;
    //       } else if (a3 == 0) {
    //           this[15] |= 4;
    //       }
    //   }
    // UNRESOLVED: Semantic meaning of bits 0x2 and 0x4 in the flag field at offset 0x3C is not established.
    // UNRESOLVED: The exact role of arguments a2/a3 as an action/enable pair is not evidenced beyond the raw bit operations.
}
