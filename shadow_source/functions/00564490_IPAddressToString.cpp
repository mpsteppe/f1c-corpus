// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00564490
// Canonical corpus name: IPAddressToString
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IPAddressToString_00564490.c

void UnknownObject::IPAddressToString()
{
    // Thin wrapper around inet_ntoa: reads the 4-byte in_addr value stored at this+0x0 and passes it by value to inet_ntoa, returning the resulting dotted-quad char* string. No fields beyond this+0x0 are touched and there are no side effects.
    // CALL: Call inet_ntoa(0x00598696) with the in_addr value dereferenced from this+0x0 (read by value). [callee:0x00598696, field:this:0x00000000, source:raw]
    // RETURN: Return the char* dotted-quad string produced by inet_ntoa. [source:raw, function:0x00564490]

    // Conservative worker pseudocode:
    //   char* IPAddressToString(struct in_addr* this) {
    //     return inet_ntoa(*this);
    //   }
    // UNRESOLVED: Callers SendJoinRequest (0x00462C00), sub_563AB0 and sub_5644B0 are listed but the packet gives no context for how the returned string is consumed.
    // UNRESOLVED: The in_addr at this+0x0 is read by value (4 bytes); its network/host byte order is not established here.
    // UNRESOLVED: The prelabel 'structural twin of ConditionalFreeWithBit0Flag (00404f70)' conflicts with the raw wrapper source and is not used; raw source outranks the cluster label.
}
