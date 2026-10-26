// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00462940
// Canonical corpus name: CollisionEventNetworkBroadcast
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionEventNetworkBroadcast_00462940.c

void UnknownObject::CollisionEventNetworkBroadcast()
{
    // Broadcasts a collision event over the network when the object state at +0x3FC4 is 1 or 2. Reads the session time, encodes a progress-bar event, prepares a COM-owned buffer via vtable call, dispatches the event through NetworkSendDispatch, then releases the buffer through virtual dispatch. Returns true when the send reported success, false otherwise.
    // GUARD: Dereference the this vtable pointer (this+0x0) to reach the owning object; read state from that object at +0x3FC4 and proceed only when it equals 2 or 1, otherwise return false. [field:this:0x00000000, field:obj:0x00003FC4, source:raw]
    // ASSIGNMENT: Read the session time double from dbl_8AFEA0 into a local; its low dword is passed onward as the event time. [global:0x008AFEA0, source:raw]
    // ASSIGNMENT: Store the caller-supplied collision event pointer a2 into the outgoing packet buffer at word index 2. [source:raw]
    // CALL: Encode a progress-bar event via ProgressBarEventEncode with arguments (4, 32, 4, 255, session time low dword, 1). [callee:0x004B33B0, global:0x008AFEA0, source:raw]
    // CALL: Invoke COMVTableCallVia0x60 on the COM object at +0x3FB8 to obtain a buffer, then set the flag byte at buffer + 4 to 1. [callee:0x0057A680, field:obj:0x00003FB8, source:raw]
    // CALL: Dispatch the packet via NetworkSendDispatch(v8, ((v8[0] >> 8) & 0x3FF) + 8, buffer, 1, 1, -1, 0); a 0 return marks the send as successful. [callee:0x0057A6A0, source:raw]
    // CALL: Release the prepared buffer by dispatching a virtual method on the COM object at +0x3FB8 with VirtualMethodDispatch. [callee:0x0057A690, field:obj:0x00003FB8, source:raw]
    // RETURN: Return the send-success flag; return false when the state guard fails. [source:raw]

    // Conservative worker pseudocode:
    //   state = *(_DWORD*)(*(_DWORD*)this + 16324);
    //   if (state != 2 && state != 1) return false;
    //   time = dbl_8AFEA0;
    //   packet[2] = a2;
    //   ProgressBarEventEncode(4, 32, 4, 255, LODWORD(time), 1);
    //   buf = COMVTableCallVia0x60(*(_DWORD*)(*(_DWORD*)this + 16312));
    //   *(_BYTE*)(buf + 4) = 1;
    //   ok = (NetworkSendDispatch(packet, ((packet[0] >> 8) & 0x3FF) + 8, buf, 1, 1, -1, 0) == 0);
    //   VirtualMethodDispatch(*(_DWORD*)(*(_DWORD*)this + 16312), buf);
    //   return ok;
    // UNRESOLVED: Meaning of a2 (collision event structure) and the packet buffer layout (header word used for length, event word at index 2) are not confirmed.
    // UNRESOLVED: Purpose of the flag byte at buffer + 4 set to 1 is not established.
    // UNRESOLVED: Whether VirtualMethodDispatch at the end releases or re-uses the buffer is not confirmed.
    // UNRESOLVED: Two callers (ShortComputation_13e0 0x004613E0, DeferredTextureObjectLoader 0x0046E1B0) not yet characterized; the owning object class is unknown.
}
