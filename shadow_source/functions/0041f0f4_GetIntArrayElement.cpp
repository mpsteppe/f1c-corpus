// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0041F0F4
// Canonical corpus name: sub_41F0F4
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_41F0F4_0041f0f4.c

void UnknownObject::GetIntArrayElement()
{
    // Element getter: a2 is a __usercall base pointer (passed in ESI) to a structure whose 32-bit element array begins at offset +20; a1 (passed in EAX) is the element index. Returns the dword at base + 4*a1 + 20.
    // CALCULATION: Compute the element address as a2 + 4*a1 + 20, i.e. index a1 into a 4-byte-element array located at offset 20 of the object a2 points to. [source:raw]
    // RETURN: Load and return the dword at the computed address (element a1 of the array at a2+20). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_41F0F4(int a1, int a2) {
    //     return *(int *)(a2 + 4 * a1 + 20);
    //   }
    // UNRESOLVED: The object type a2 references and the semantic meaning of the indexed 32-bit elements are unknown from this function alone.
    // UNRESOLVED: No bounds check on a1 exists, so out-of-range indexes read past the array.
}
