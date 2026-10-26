// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00562605
// Canonical corpus name: CharSwap
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CharSwap_00562605.c

void UnknownObject::CharSwap()
{
    // Exchanges the single bytes stored at the two char pointers a1 and a2. Reads the current byte at a1 (the this+0x0 field), overwrites a1 with the byte at a2, writes the saved old byte back through a2, and returns the original a1 byte. Structural twin of FloatClamp (004646c0) per the packet prelabel.
    // ASSIGNMENT: Save the current byte at a1 (offset 0x0 of this) into the result register before any write. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Write the byte read from a2 into a1. [source:raw]
    // ASSIGNMENT: Write the previously saved a1 byte into a2, completing the swap. [source:raw]
    // RETURN: Return the original byte previously stored at a1 (this+0x0). [field:this:0x00000000, abi:lead, source:raw]

    // Conservative worker pseudocode:
    //   char CharSwap(char *a1, char *a2) {
    //     char old = *a1;
    //     *a1 = *a2;
    //     *a2 = old;
    //     return old;
    //   }
    // UNRESOLVED: The object owning the exchanged buffer is unknown; the packet only provides a single this+0x0 field while the raw source operates on two independent char pointers.
    // UNRESOLVED: How a1 and a2 relate to this (which pointer is the receiver) is not established.
}
