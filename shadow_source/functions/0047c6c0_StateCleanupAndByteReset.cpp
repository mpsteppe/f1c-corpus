// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047C6C0
// Canonical corpus name: sub_47C6C0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_47C6C0_0047c6c0.c

void UnknownObject::StateCleanupAndByteReset()
{
    // thiscall receiver method: first notifies the object's state machinery that cleanup is happening (StateCleanupNotification), then writes 0 to the byte field named by ByteSetterAt0xe0 at offset 0xe0, and unconditionally returns 0. The owning object type is unknown; the offset 0xe0 is carried only by the callee's legacy name, not by any field evidence in this packet.
    // CALL: StateCleanupNotification invoked on this to signal that state cleanup is taking place [callee:0x00489CB0, source:raw]
    // CALL: ByteSetterAt0xe0 invoked on this with the value 0, resetting the byte at offset 0xe0 [callee:0x0048A3B0, source:raw]
    // RETURN: Function always returns integer 0 after the two calls [function:0x0047C6C0, source:raw]

    // Conservative worker pseudocode:
    //   StateCleanupNotification(this);
    //   ByteSetterAt0xe0(this, 0);
    //   return 0;
    // UNRESOLVED: The receiving object type is unknown, so the semantics of the +0xe0 byte reset (flag, counter low byte, state byte) cannot be established from this packet
    // UNRESOLVED: The meaning of the constant return value 0 is unknown
}
