// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00461ED0
// Canonical corpus name: DirectoryStringProcessingWithDecode
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DirectoryStringProcessingWithDecode_00461ed0.c

void UnknownObject::DirectoryStringProcessingWithDecode()
{
    // Directory-string lookup and network connect: guards on a network system pointer held in the object at byte offset 0x1B79C (reached through a first dword dereference of `this`), copies the caller string a2 into a fixed buffer, optionally decodes it against config byte_5C3F6C and resolves a port from the decoded value, then calls NetworkConnection with the decoded buffer, resolved port, and fixed literal flags (1, 5). Always returns 1.
    // ASSIGNMENT: Dereference this at offset 0x0 to obtain the object pointer; the network system pointer is read from it at offset 0x1B79C. [source:raw, field:this:0x00000000, field:obj:0x0001B79C]
    // GUARD: Proceed only when the network system pointer at obj+0x1B79C is non-null; otherwise the body is skipped. [source:raw, field:obj:0x0001B79C]
    // ASSIGNMENT: Seed the port value v3 from the session port base word_7D0FE8, truncated to unsigned 16-bit. [source:raw, global:0x007D0FE8]
    // ASSIGNMENT: Terminate the destination buffer by writing zero to its first byte. [source:raw]
    // CALL: Copy the caller string a2 into the buffer with a 63-character limit via sub_587DD0. [source:raw, callee:0x00587DD0]
    // ASSIGNMENT: Force the buffer terminator by writing zero at index 63. [source:raw]
    // GUARD: Compare the copied buffer against config byte_5C3F6C with sub_587C20; the decode path runs only on a match. [source:raw, callee:0x00587C20, global:0x005C3F6C]
    // CALL: Decode the buffer against config byte_5C3F6C in place via sub_5897CA. [source:raw, callee:0x005897CA, global:0x005C3F6C]
    // CALL: Query the decoded config value with a null buffer via sub_5897CA, capturing the returned pointer/descriptor as v4. [source:raw, callee:0x005897CA, global:0x005C3F6C]
    // GUARD: If the query result v4 is non-null, resolve the connection port from it with sub_587ECE, overriding the seeded base port. [source:raw, callee:0x00587ECE]
    // CALL: Establish the network connection via NetworkConnection using the network system pointer at obj+0x1B79C, the decoded buffer, the resolved port v3, and literal arguments 1 and 5. [source:raw, callee:0x00563260, field:obj:0x0001B79C]
    // RETURN: Return the constant 1 in all paths. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_461ED0(void *this, int a2) {
    //     int port = (unsigned short)word_7D0FE8;
    //     char buf[64];
    //     void *obj = *(void**)this;
    //     if (obj && *(void**)((char*)obj + 0x1B79C)) {
    //       buf[0] = 0;
    //       sub_587DD0(buf, a2, 63);
    //       buf[63] = 0;
    //       if (sub_587C20(buf, byte_5C3F6C)) {
    //         sub_5897CA(buf, byte_5C3F6C);
    //         void *v4 = sub_5897CA(0, byte_5C3F6C);
    //         if (v4) port = sub_587ECE(v4);
    //       }
    //       NetworkConnection(*(void**)((char*)obj + 0x1B79C), buf, port, 1, 5);
    //     }
    //     return 1;
    //   }
    // UNRESOLVED: Exact semantics of the sub_587C20 / sub_5897CA decode-compare chain and what byte_5C3F6C config data represents are defined in those callees, not grounded here.
    // UNRESOLVED: What a2 points to and how it is produced by the caller are caller-supplied.
    // UNRESOLVED: Meaning of the two fixed NetworkConnection literal arguments (1, 5) is unverified.
}
