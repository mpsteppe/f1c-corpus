// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00564090
// Canonical corpus name: sub_564090
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_564090_00564090.c

void UnknownObject::ResolveContextStringCompare()
{
    // Comparison callback over two indirect address/name handles. Dereferences both in_addr** parameters, resolves each through sub_5644B0 using the context reference string at dword_8D46B4+128 and the byte_5EA438 buffer, compares the resolved strings with sub_588410, and returns the comparison result negated when the direction flag at dword_8D46B4+132 is zero (reverse sort).
    // ASSIGNMENT: Dereference the first indirect handle: v2 = *a1, reading the handle pointer at this+0x0 [field:this:0x00000000, source:raw]
    // CALL: sub_5644B0 resolves the second handle (*a2) using the context reference string at dword_8D46B4+128 and the byte_5EA438 buffer, producing v5 [callee:0x005644B0, global:0x008D46B4, global:0x005EA438, source:raw]
    // CALL: sub_5644B0 resolves the first handle (v2) with the same context reference string and byte_5EA438 buffer, producing v3 [callee:0x005644B0, global:0x008D46B4, global:0x005EA438, source:raw]
    // CALL: sub_588410 compares the two resolved strings v3 and v5 and returns the ordering result [callee:0x00588410, source:raw]
    // GUARD: When the sort-direction flag at dword_8D46B4+132 is zero, the comparison result is negated (reverse sort); otherwise it is returned as-is [global:0x008D46B4, source:raw]
    // RETURN: Return the (possibly negated) comparison result [function:0x00564090]

    // Conservative worker pseudocode:
    //   v2 = *a1;
    //   v5 = sub_5644B0(*a2, *(char**)(dword_8D46B4 + 128), byte_5EA438);
    //   v3 = sub_5644B0(v2, *(char**)(dword_8D46B4 + 128), byte_5EA438);
    //   result = sub_588410(v3, v5);
    //   if (*(int*)(dword_8D46B4 + 132) == 0)
    //       return -result;
    //   return result;
    // UNRESOLVED: The object behind dword_8D46B4 and the semantics of its +128/+132 slots (context reference string vs sort-direction flag) are not documented in this packet
    // UNRESOLVED: The exact role of the in_addr** handles is unclear: they behave as opaque indirect keys rather than literal network address structs
    // UNRESOLVED: The content of byte_5EA438 (default application directory) cannot be confirmed from this function
}
