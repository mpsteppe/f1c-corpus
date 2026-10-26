// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005903DA
// Canonical corpus name: sub_5903DA
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5903DA_005903da.c

void UnknownObject::ResolveCodePageName()
{
    // Resolves the locale/codepage name for a CPInfo object: when a1 is a valid object belonging to the module byte_5B94D4 and matching the vtable off_5B94D0, the name string is extracted directly with sub_587ECE(a1). Otherwise the locale is queried through the function pointer dword_8D3FB8 (parameter dword_8D3FB4, message 11 or 4100, 8-byte buffer) and, on success, the name is extracted from that buffer; a failed query propagates a 0 return.
    // ASSIGNMENT: Set v1 = a1 as the byte pointer into the CPInfo object. [source:raw]
    // GUARD: Take the CPInfo path only when a1 is non-null, its first byte (this:0x0) is non-zero, and sub_58FB90(a1, byte_5B94D4) reports the object belongs to the module identified by byte_5B94D4. [callee:0x0058FB90, field:this:0x00000000, global:0x005B94D4, source:raw]
    // CALL: Membership test against the vtable: sub_58FB90(a1, &off_5B94D0) checks whether the object is the CPInfo vtable entry. [callee:0x0058FB90, global:0x005B94D0, source:raw]
    // RETURN: When the object matches the vtable off_5B94D0, extract and return the name string directly with sub_587ECE(a1). [callee:0x00587ECE, source:raw]
    // CALL: CPInfo fallback: query the locale via dword_8D3FB8(dword_8D3FB4, 11, v3, 8) into the 8-byte stack buffer. [global:0x008D3FB4, global:0x008D3FB8, source:raw]
    // CALL: Else branch (invalid CPInfo object): query the locale via dword_8D3FB8(dword_8D3FB4, 4100, v3, 8). [global:0x008D3FB4, global:0x008D3FB8, source:raw]
    // GUARD: If the locale query returns 0, propagate the failure by returning 0 immediately. [source:raw]
    // ASSIGNMENT: Repoint v1 to the stack buffer v3 filled by the successful locale query. [source:raw]
    // RETURN: Extract the null-terminated name string from the buffer with sub_587ECE(v1) and return it. [callee:0x00587ECE, source:raw]
    // CALL: Called by sub_58FD90 (0x0058FD90) to resolve the codepage/locale name during locale setup. [caller:0x0058FD90, source:raw]

    // Conservative worker pseudocode:
    //   int sub_5903DA(unsigned int *a1) {
    //     byte *v1 = (byte*)a1;
    //     if (a1 && *((byte*)a1) && sub_58FB90(a1, byte_5B94D4)) {
    //       if (sub_58FB90(a1, &off_5B94D0)) return sub_587ECE(v1);
    //       result = dword_8D3FB8(dword_8D3FB4, 11, v3, 8);
    //     } else {
    //       result = dword_8D3FB8(dword_8D3FB4, 4100, v3, 8);
    //     }
    //     if (!result) return result;
    //     v1 = v3;
    //     return sub_587ECE(v1);
    //   }
    // UNRESOLVED: dword_8D3FB8 is invoked as a function pointer; its calling convention and the meaning of its parameter dword_8D3FB4 are inferred. Message ids 11 and 4100 are uninterpreted.
    // UNRESOLVED: The roles of byte_5B94D4 (interpreted as a module handle) and off_5B94D0 (interpreted as a vtable) are inferred from the two membership-test call sites.
    // UNRESOLVED: The CPInfo object layout beyond byte 0 is unknown.
    // UNRESOLVED: sub_587ECE's buffer-to-string extraction contract is external to this function.
}
