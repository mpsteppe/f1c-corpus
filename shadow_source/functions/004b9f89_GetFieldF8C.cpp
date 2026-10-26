// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B9F89
// Canonical corpus name: sub_4B9F89
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4B9F89_004b9f89.c

void UnknownObject::GetFieldF8C()
{
    // Trivial getter: reads the DWORD at this+0xF8C and returns it. No side effects, no guard, no callees.
    // RETURN: Return the DWORD read at this+0xF8C (offset 3980 from the __usercall argument a1). [field:this:0x00000F8C, source:raw]

    // Conservative worker pseudocode:
    //   int sub_4B9F89(int a1) {
    //     return *(int *)(a1 + 3980);
    //   }
    // UNRESOLVED: The owning class of this is unknown; the semantic role of field 0xF8C is not grounded in this packet.
}
