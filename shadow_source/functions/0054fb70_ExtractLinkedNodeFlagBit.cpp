// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054FB70
// Canonical corpus name: LinkedListFlagBitExtraction
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListFlagBitExtraction_0054fb70.c

void UnknownObject::ExtractLinkedNodeFlagBit()
{
    // Reads the node pointer stored at this+0x204 (this[129]), loads the byte at offset +0x14 (20) of that node, masks it with 0x40, and returns bit 6 shifted down, i.e. a 0/1 boolean. Called by sub_40FE50 and SceneExtentComputation (0x004BDC10) during scene extent work to query a node property flag.
    // CALCULATION: Load the linked node pointer held at this[129] (this+0x204). [source:raw, field:this:0x00000204]
    // CALCULATION: Read the byte at offset +0x14 (20) of the pointed-to node and mask it with 0x40 (bit 6). [source:raw]
    // RETURN: Shift the masked bit right by 6, returning a 0 or 1 boolean. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_54FB70(void* this) {
    //     unsigned char flags = *(unsigned char*)(this[129] + 20);
    //     return (flags & 0x40) >> 6;
    //   }
    // UNRESOLVED: Identity and layout of the node pointed to by this+0x204; the byte at +0x14 and the meaning of its bit 6 (0x40) flag are unknown.
    // UNRESOLVED: Object type of this itself and why the flag matters to the scene-extent callers is undetermined.
    // UNRESOLVED: Packet records a read of this+0x218, but the raw source performs no access at that offset; its role is unresolved.
}
