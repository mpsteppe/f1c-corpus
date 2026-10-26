// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057A229
// Canonical corpus name: sub_57A229
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_57A229_0057a229.c

void UnknownObject::DualAdjacentByteWrite()
{
    // Thiscall-style helper that writes the incoming byte value result into two adjacent byte fields (offsets 43 and 44) of the object a2 and returns the same value. Likely sets two sibling byte flags/state fields to a common value.
    // ASSIGNMENT: Store result into the byte field at a2 + 43. [source:raw]
    // ASSIGNMENT: Store result into the byte field at a2 + 44. [source:raw]
    // RETURN: Return result unchanged. [source:raw]

    // Conservative worker pseudocode:
    //   char __usercall sub_57A229(char result, int a2) {
    //     *(_BYTE *)(a2 + 43) = result;
    //     *(_BYTE *)(a2 + 44) = result;
    //     return result;
    //   }
    // UNRESOLVED: Semantics of the two byte fields at a2 + 43 and a2 + 44 (sibling flags, counters, state pair) is unknown without a caller or a known struct layout.
    // UNRESOLVED: Owner object is unknown.
}
