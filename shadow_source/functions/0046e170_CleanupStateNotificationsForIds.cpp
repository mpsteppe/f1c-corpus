// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046E170
// Canonical corpus name: ShortComputation_e170
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_e170_0046e170.c

void UnknownObject::CleanupStateNotificationsForIds()
{
    // On the global session/plugin object dword_7CD8C0, invokes its vtable slot at offset +28 twice: first with argument 36, then with argument 35. Each returned object pointer, when non-null, is passed to StateCleanupNotification (0x00489CB0). Returns the result of the second StateCleanupNotification call, or the second vtable call result when null.
    // CALL: Invoke vtable[+28] on dword_7CD8C0 (global object pointer) with argument 36; store the returned pointer in v0. [global:0x007CD8C0, source:raw]
    // GUARD: If v0 is non-null, pass it to StateCleanupNotification (0x00489CB0); the return value of that call is discarded. [callee:0x00489CB0, source:raw]
    // CALL: Invoke the same vtable[+28] on dword_7CD8C0 with argument 35; store the returned pointer in result. [global:0x007CD8C0, source:raw]
    // GUARD: If result is non-null, call StateCleanupNotification(result) (0x00489CB0) and return its value. [callee:0x00489CB0, source:raw]
    // RETURN: Return result unchanged when the second vtable call returned null. [source:raw, function:0x0046E170]

    // Conservative worker pseudocode:
    //   v0 = dword_7CD8C0->vtable[+28](dword_7CD8C0, 36);
    //   if (v0) StateCleanupNotification(v0);
    //   result = dword_7CD8C0->vtable[+28](dword_7CD8C0, 35);
    //   if (result) return StateCleanupNotification(result);
    //   return result;
    // UNRESOLVED: dword_7CD8C0 is a global object pointer whose class is unknown; the vtable slot at offset +28 is identified only by its raw offset, not by a name.
    // UNRESOLVED: The meaning of the notification/state identifiers 35 and 36 is unknown.
    // UNRESOLVED: The first StateCleanupNotification return value is discarded, so any error propagation from the 36 path is lost.
    // UNRESOLVED: The caller is MultiplayerSessionJoinHandler, which suggests session teardown, but the concrete object identity is not established by the packet.
}
