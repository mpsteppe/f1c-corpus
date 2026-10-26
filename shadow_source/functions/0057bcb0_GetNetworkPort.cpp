// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057BCB0
// Canonical corpus name: NetworkGetPort
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NetworkGetPort_0057bcb0.c

void UnknownObject::GetNetworkPort()
{
    // Reads the network port from this+0x12C (u_short element 150 of the u_short* receiver, i.e. byte offset 0x12C) and returns it converted from network to host byte order via ntohs (__imp_ntohs, 0x0059E2CC). The receiver object is otherwise opaque.
    // CALCULATION: Read the u_short network port at this+0x12C, addressed as element 150 of the u_short* receiver. [field:this:0x0000012C, source:raw]
    // CALL: Convert the port from network to host byte order through ntohs (__imp_ntohs, 0x0059E2CC). [global:0x0059E2CC, source:raw]
    // RETURN: Return the converted host-order u_short port value. [field:this:0x0000012C, global:0x0059E2CC, function:0x0057BCB0, source:raw]

    // Conservative worker pseudocode:
    //   u_short GetNetworkPort(u_short* this) {
    //     return ntohs(this[150]);
    //   }
    // UNRESOLVED: The receiver object type and the role of this+0x12C beyond 'network port' are unresolved; the owning class is not determinable from this packet.
    // UNRESOLVED: Who writes the port field and how the receiver is created is not visible here.
}
