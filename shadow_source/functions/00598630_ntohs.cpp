// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00598630
// Canonical corpus name: ntohs
// Owner: ws2_32 [DERIVED]
// Raw source: functions/ntohs_00598630.c

void ws2_32::ntohs()
{
    // Import thunk for the Winsock2 ntohs (network to host short) function: reads the import-address-table pointer __imp_ntohs at 0x0059E2CC, calls it with the single u_short argument, and returns its result unchanged. Identified as ntohs by the ABI name, the function name and the __imp_ntohs IAT global.
    // CALL: Call the imported ntohs through the IAT pointer __imp_ntohs (read at 0x0059E2CC) with the u_short argument. [global:0x0059E2CC, source:raw]
    // RETURN: Return the u_short result of the imported ntohs unchanged. [source:raw]
    // CALL: Consumed by network-endianness callers sub_561BF0 (0x00561BF0) and sub_563410 (0x00563410). [caller:0x00561BF0, caller:0x00563410, source:raw]

    // Conservative worker pseudocode:
    //   u_short ntohs(u_short netshort) {
    //     return __imp_ntohs(netshort);
    //   }
    // UNRESOLVED: The concrete socket/network subsystem served by callers sub_561BF0 and sub_563410 is outside this packet.
}
