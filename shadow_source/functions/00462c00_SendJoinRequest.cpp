// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00462C00
// Canonical corpus name: SendJoinRequest
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SendJoinRequest_00462c00.c

void UnknownObject::SendJoinRequest()
{
    // Sends a multiplayer join request to the host. Looks up the session entry at index a2 from the entry array at obj+0x1B79C (offset 112540) via IndexBoundsCheckedArrayRead and returns 0 when it is missing. Formats a host:port string into a local buffer (IPAddressToString after StringComparisonWithConstantDispatch, then StringFormatWithBufferOverflowCheck with the aHostport format literal). Debug-logs 'sending join request' through DebugLogWrite when the session-type global dword_7C569C is not 5 and the dev string check passes, resets the join flag at obj+0x378 (offset 888) to 0, and delegates the send to CollisionSpatialQuery. Invoked by MultiplayerPasswordValidation (0x0046DD30).
    // CALL: Bounds-checked read of the session entry at index a2 from the entry array stored at obj+0x1B79C (offset 112540 in raw source), where obj is the object behind the primary pointer at this+0x0 [callee:0x00563E80, field:obj:0x0001B79C, field:this:0x00000000, source:raw]
    // GUARD: If the session entry lookup returns null, the function returns 0 without sending [source:raw]
    // ASSIGNMENT: Initializes the host:port buffer: copies byte_5EA438[0], zero-fills the rest with memset, and clears the trailing port/terminator fields [global:0x005EA438, source:raw]
    // CALL: StringComparisonWithConstantDispatch(0) selects the string-conversion mode used by the address formatting [callee:0x00564530, source:raw]
    // CALL: IPAddressToString converts the session entry to an address string [callee:0x00564490, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck formats the host:port '%s:%d' string into the local buffer using the address string and port; the format literal is the packet global aHostport [callee:0x0058815F, global:0x005C5C28, source:raw]
    // GUARD: Debug logging is gated on the session-type global dword_7C569C being different from 5 [global:0x007C569C, source:raw]
    // CALL: StringSplitLoop(1, aDDevF119992002_1, 6657) performs the dev-build string check; when it succeeds, DebugLogWrite logs the aSendingJoinReq message through the dword_8AD25C buffer [callee:0x004D7A50, callee:0x004D7AA0, global:0x005C5CE4, global:0x005C61F4, global:0x008AD25C, source:raw]
    // ASSIGNMENT: Resets the join flag at obj+0x378 (offset 888 in raw source) to 0 before sending [field:obj:0x00000378, source:raw]
    // CALL: Delegates the actual send to CollisionSpatialQuery(host:port string, a3) and returns its result [callee:0x00462CE0, source:raw]
    // CALL: Invoked by MultiplayerPasswordValidation (0x0046DD30) after the password validation path [caller:0x0046DD30, source:raw]

    // Conservative worker pseudocode:
    //   entry = IndexBoundsCheckedArrayRead(*(*this + 112540), a2);
    //   if (!entry) return 0;
    //   buf[0] = byte_5EA438[0]; memset(buf+1, 0, 0x4C); clear trailing port and terminator fields;
    //   addr = IPAddressToString(entry, StringComparisonWithConstantDispatch(0));
    //   StringFormatWithBufferOverflowCheck(buf, "%s:%d", addr, port);
    //   if (dword_7C569C != 5 && StringSplitLoop(1, aDDevF119992002_1, 6657))
    //     DebugLogWrite(&dword_8AD25C, aSendingJoinReq);
    //   *(*this + 888) = 0;
    //   return CollisionSpatialQuery(buf, a3);
    // UNRESOLVED: Packet global aSD_2 (0x005C6214) is flagged as referenced but does not appear in the raw decompiled source, so its role cannot be established here
    // UNRESOLVED: The byte_5EA438 prefix copied into the host:port buffer is uninterpreted; existing analysis labels it only DERIVED as a directory/path string
    // UNRESOLVED: The a3 argument is forwarded opaque to CollisionSpatialQuery; its semantics are unresolved
    // UNRESOLVED: CollisionSpatialQuery's actual network send mechanism is outside this packet
}
