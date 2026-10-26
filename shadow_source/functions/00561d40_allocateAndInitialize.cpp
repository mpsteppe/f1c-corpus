// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00561D40
// Canonical corpus name: sub_561D40
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_561D40_00561d40.c

void UnknownObject::allocateAndInitialize()
{
    // Allocates a 260-byte object via MallocWrapperForNhMalloc and, when the output pointer a1 is non-null, stores it in *a1; when a1 is null the global unk_5E4CF8 is used as the working object instead. The object is then populated with two string copies (offsets 8 and 72) and a set of scalar fields: a4 at offset 0, a3 at offset 4, a7/a8/a9/a10 at offsets 200/204/208/212, zeroed dwords at offsets 216 and 224, a flag dword 1 at offset 220, a2 at offset 228, a byte flag 1 at offset 232, a zeroed dword at offset 252, and a11 at offset 256. Returns the populated object pointer. Called by sub_561BF0.
    // CALL: Call MallocWrapperForNhMalloc(260) to allocate the 260-byte object [callee:0x0058A935, source:raw]
    // ASSIGNMENT: Store the allocated pointer in *a1 when a1 is non-null; otherwise use the global unk_5E4CF8 as the working object [source:raw, global:0x005E4CF8]
    // ASSIGNMENT: Copy string a5 to offset 8 and string a6 to offset 72 of the object [source:raw]
    // ASSIGNMENT: Write the scalar parameters to dword slots: offset 0 = a4, offset 4 = a3, offset 200 = a7, offset 204 = a8, offset 208 = a9, offset 212 = a10, offset 228 = a2, offset 256 = a11 [source:raw]
    // ASSIGNMENT: Initialize flag and zero fields: dword at offset 220 = 1, byte at offset 232 = 1, dwords at offsets 216, 224 and 252 = 0 [source:raw]
    // RETURN: Return the populated object pointer (allocated object or unk_5E4CF8 fallback) [source:raw]
    // CALL: Invoked by sub_561BF0 to create and initialize the object from its construction parameters [caller:0x00561BF0]

    // Conservative worker pseudocode:
    //   if (a1) { result = MallocWrapperForNhMalloc(260); *a1 = result; }
    //   else { result = (char *)&unk_5E4CF8; }
    //   strcpy(result + 8, a5);
    //   strcpy(result + 72, a6);
    //   *(dword*)(result + 0)   = a4;
    //   *(dword*)(result + 4)   = a3;
    //   *(dword*)(result + 200) = a7;
    //   *(dword*)(result + 204) = a8;
    //   *(dword*)(result + 208) = a9;
    //   *(dword*)(result + 212) = a10;
    //   *(dword*)(result + 216) = 0;
    //   *(dword*)(result + 220) = 1;
    //   *(dword*)(result + 224) = 0;
    //   *(dword*)(result + 228) = a2;
    //   result[232] = 1;
    //   *(dword*)(result + 252) = 0;
    //   *(dword*)(result + 256) = a11;
    //   return result;
    // UNRESOLVED: Object type and the meaning of each scalar field are unknown; the packet provides no owner or field evidence for the allocated structure
    // UNRESOLVED: The two string slots (offsets 8 and 72) likely hold names or labels but their exact roles are unverified
    // UNRESOLVED: The global unk_5E4CF8 fallback when a1 is null suggests a shared default object, but its initialization state is unknown
    // UNRESOLVED: The flag dword 1 at offset 220 and byte flag 1 at offset 232 may mark enabled or initialized states; unverified
}
