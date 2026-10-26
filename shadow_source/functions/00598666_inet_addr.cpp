// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00598666
// Canonical corpus name: inet_addr
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/inet_addr_00598666.c

void UnknownObject::inet_addr()
{
    // Import thunk (stdcall) that forwards inet_addr(cp) to the imported Winsock implementation __imp_inet_addr. Parses a dotted-quad IPv4 address string cp into its in-network-order unsigned 32-bit representation. No local logic; the entire behavior is the forwarded import.
    // CALL: Forward the call to the imported Winsock function __imp_inet_addr(cp), which performs the actual dotted-quad string to binary address conversion. [global:0x0059E2F0, source:raw]
    // RETURN: Return the unsigned int result produced by the forwarded import call. [source:raw]
    // CALL: Used by sub_562010, sub_562D90, NetworkConnection (0x00563260), sub_563AB0 and NetworkAddressParser (0x005642B0) to convert IPv4 address strings during connection setup and address parsing. [caller:0x00562010, caller:0x00562D90, caller:0x00563260, caller:0x00563AB0, caller:0x005642B0, source:raw]

    // Conservative worker pseudocode:
    //   unsigned int inet_addr(const char *cp) {
    //     return __imp_inet_addr(cp);
    //   }
    // UNRESOLVED: The exact semantics of the conversion live inside the imported Winsock function, not in this thunk.
}
