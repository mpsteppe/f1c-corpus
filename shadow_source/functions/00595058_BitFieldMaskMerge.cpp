// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00595058
// Canonical corpus name: BitFieldMaskMerge
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BitFieldMaskMerge_00595058.c

void UnknownObject::BitFieldMaskMerge()
{
    // Merges the two parameters into a bit-field value, using a mask argument a1 to decide which bits come from a2 and which are inherited from an existing bit-field read via sub_5950A3(): v2 = (a2 & a1) | (~a2 & sub_5950A3()). The merged value is stored via sub_595135(v2) and also returned.
    // CALL: Read the current bit-field value by calling sub_5950A3() as the inherited-mask source. [callee:0x005950A3, source:raw]
    // CALCULATION: Merge: v2 = (a2 & a1) | (~a2 & sub_5950A3()), where a1 selects a2's bits and the complement of a2 inherits from the existing value. [source:raw]
    // CALL: Persist the merged value by calling sub_595135(v2). [callee:0x00595135, source:raw]
    // RETURN: Return the merged value v2. [source:raw]

    // Conservative worker pseudocode:
    //   int BitFieldMaskMerge(int a1, int a2) {
    //     int v2 = (a2 & a1) | (~a2 & sub_5950A3());
    //     sub_595135(v2);
    //     return v2;
    //   }
    // UNRESOLVED: The meaning of the bit-field read by sub_5950A3 and the store performed by sub_595135 is not established; both callees are unanalysed here.
    // UNRESOLVED: The single caller sub_59508D supplies the two parameters, but its context is not in this packet.
}
