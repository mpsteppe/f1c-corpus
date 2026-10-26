// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00564600
// Canonical corpus name: IndirectDwordCompare
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IndirectDwordCompare_00564600.c

void UnknownObject::IndirectDwordCompare()
{
    // Dereferences both dword pointers a1 and a2 and forwards the two values to a shared comparison helper. The raw source names the helper sub_588410 and returns its result directly; the packet does not list the helper in its callee evidence, so the delegate cannot be cited as an evidence reference. The prelabel getter template (returns field 0x0 of this) does not match the raw source, which delegates comparison rather than returning the field; raw source is taken as authoritative.
    // ASSIGNMENT: Dereference the first operand a1 to obtain the first comparison value (dword at offset 0x0 of this). [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Dereference the second operand a2 to obtain the second comparison value. [source:raw]
    // CALL: Forward the two dereferenced dwords to the shared comparator sub_588410 named by the raw source; the comparator is absent from this packet's callee evidence and therefore has no evidence reference here. [abi:lead, source:raw]
    // RETURN: Return the comparator's result to the caller. [function:0x00564600, abi:lead, source:raw]

    // Conservative worker pseudocode:
    //   int IndirectDwordCompare(int *a1, int *a2) {
    //     return sub_588410(*a1, *a2);
    //   }
    // UNRESOLVED: Semantics of the delegated comparator sub_588410 are unknown; it is named only in the raw source and has no packet callee evidence.
    // UNRESOLVED: The prelabel getter-template summary (returns field 0x0 of this) conflicts with the raw source, which delegates comparison; raw source taken as authoritative.
    // UNRESOLVED: The owner of the object whose this+0x0 field is dereferenced is unknown.
}
