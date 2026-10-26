// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057E8D0
// Canonical corpus name: NetworkGetLocalIP
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NetworkGetLocalIP_0057e8d0.c

void UnknownObject::NetworkGetLocalIP()
{
    // Returns the local machine IP address as a dotted-decimal string. Initializes an in_addr via htonl(0) (INADDR_ANY), copies a 16-byte network context from this+673 into a local buffer, converts the address with inet_ntoa, then copies the result into an output buffer through sub_587DD0 with a size limit of a3-1 and appends a null terminator. Returns 1 on success, 0 if inet_ntoa fails.
    // CALL: Call htonl(0) to obtain INADDR_ANY in network byte order and store into the local in_addr. [global:0x0059E2D8, source:raw, function:0x0057E8D0]
    // CALL: Call htons(0) (port 0 in network byte order); result unused. [global:0x0059E2F4, source:raw, function:0x0057E8D0]
    // CALL: Copy a 16-byte network context struct from this+673 into the local buffer via Copy4DwordsStructToStruct. [callee:0x0057B9F0, source:raw, function:0x0057E8D0]
    // CALL: Call inet_ntoa(in) to convert the in_addr to a dotted-decimal string stored in v4. [global:0x0059E310, source:raw, function:0x0057E8D0]
    // GUARD: If inet_ntoa returned NULL, return 0 (failure). [global:0x0059E310, source:raw, function:0x0057E8D0]
    // CALL: Call sub_587DD0(a2, v4, a3 - 1) to copy the IP string into the output buffer with a copy limit of a3-1 bytes. [callee:0x00587DD0, source:raw, function:0x0057E8D0]
    // ASSIGNMENT: Write a null terminator at the last output buffer position: *(a3 - 1 + a2) = 0. [source:raw, function:0x0057E8D0]
    // RETURN: Return 1 to signal success. [source:raw, function:0x0057E8D0]

    // Conservative worker pseudocode:
    //   in = htonl(0);  // INADDR_ANY, network byte order
    //   htons(0);       // port 0, result discarded
    //   Copy4DwordsStructToStruct(this + 673, &local_buffer);
    //   v4 = inet_ntoa(in);
    //   if (v4 == NULL) return 0;
    //   sub_587DD0(a2, v4, a3 - 1);
    //   *(a2 + a3 - 1) = 0;
    //   return 1;
    // UNRESOLVED: Purpose of the 16-byte context copied from this+673 into the local buffer is not established; only its size is known from Copy4DwordsStructToStruct.
    // UNRESOLVED: Output buffer size semantics: copy limit is a3-1 and terminator lands at a3-1+a2, so a3 likely includes the terminator; not independently verified.
    // UNRESOLVED: Globals byte_FF00000000005983 and byte_FF00000000005990 are listed as RW but do not appear in the function body; treated as decompiler artifacts.
}
