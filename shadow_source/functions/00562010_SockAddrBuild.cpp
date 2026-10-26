// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00562010
// Canonical corpus name: sub_562010
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_562010_00562010.c

void UnknownObject::SockAddrBuild()
{
    // Builds a sockaddr_in structure in the caller-provided buffer a3 from a host string and a port. Writes address family 2 (AF_INET), the port in network byte order via htons, and the binary IP address. Tries inet_addr first; on failure falls back to gethostbyname DNS resolution unless the host string is the broadcast literal '255.255.255.255'. Optionally reports the resolved result through output pointer a4.
    // ASSIGNMENT: Set address-family field at the start of the a3 buffer to 2 (AF_INET) [source:raw, function:0x00562010]
    // ASSIGNMENT: Set port field at offset 2 to htons(hostshort), converting to network byte order [source:raw, callee:0x0059866C]
    // GUARD: If host string cp is non-null, resolve the IP with inet_addr; otherwise write 0 (INADDR_ANY) to the address field [source:raw]
    // ASSIGNMENT: Write binary IP address at offset 4: inet_addr(cp) when cp is non-null, else 0 [source:raw, callee:0x00598666]
    // GUARD: Accept the inet_addr result unless it equals -1 and the string is not the broadcast literal '255.255.255.255' (global a255255255255) [source:raw, global:0x005E4E80]
    // CALL: DNS fallback: call gethostbyname(cp); if it returns null, return that null result immediately; otherwise take the first address via the triple dereference at result + 12 and write it to offset 4 [source:raw, callee:0x00598660]
    // GUARD: If output pointer a4 is non-null, store the resolved result through it (sockaddr buffer address on the inet_addr path, hostent pointer on the DNS path) [source:raw]
    // RETURN: Return 1 on success; return 0 only when gethostbyname fails [source:raw]

    // Conservative worker pseudocode:
    //   family = 2;
    //   port = htons(host_port);
    //   addr = (cp != NULL) ? inet_addr(cp) : 0;
    //   if (addr == -1 && strcmp(cp, "255.255.255.255") != 0) {
    //       he = gethostbyname(cp);
    //       if (!he) return 0;
    //       addr = *(uint32_t*)(*(char**)(he + 12)); // h_addr_list[0]
    //   }
    //   if (out) *out = result;
    //   return 1;
    // UNRESOLVED: The value stored through a4 is the sockaddr buffer address when inet_addr succeeds but the hostent pointer when DNS resolution is used; the two types are inconsistent and the caller's expectation is unknown.
    // UNRESOLVED: The buffer a3 is written without any length validation; the game trusts callers to provide a sockaddr_in-sized buffer.
    // UNRESOLVED: The triple dereference at result + 12 is assumed to be h_addr_list[0]; the hostent layout is not validated in this function.
}
