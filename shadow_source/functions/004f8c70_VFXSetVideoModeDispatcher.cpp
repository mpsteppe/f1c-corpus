// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F8C70
// Canonical corpus name: GlobalCallbackDispatcher
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GlobalCallbackDispatcher_004f8c70.c

void UnknownObject::VFXSetVideoModeDispatcher()
{
    // Late-bound callback dispatcher (__thiscall): if the global function pointer VFXSetVideoMode at 0x008AFC88 is not registered, return 4; otherwise invoke it, forwarding the receiver this pointer, and return 0. Called by DualSourceAcquireWithFallback (0x004F8AE0).
    // GUARD: Guard on the global function pointer VFXSetVideoMode being non-null; when null the function returns 4 (callback not registered). [global:0x008AFC88, source:raw]
    // CALL: Invoke the VFXSetVideoMode callback stored at global 0x008AFC88, passing the receiver this pointer as its argument. [global:0x008AFC88, source:raw]
    // RETURN: Return 0 after the callback runs, or 4 when VFXSetVideoMode was null. [global:0x008AFC88, source:raw]
    // CALL: DualSourceAcquireWithFallback (0x004F8AE0) calls this dispatcher as part of its acquisition path. [caller:0x004F8AE0, source:raw]

    // Conservative worker pseudocode:
    //   int VFXSetVideoModeDispatcher(void* this) {
    //     if (!VFXSetVideoMode) return 4;
    //     VFXSetVideoMode(this);
    //     return 0;
    //   }
    // UNRESOLVED: VFXSetVideoMode is a global function pointer; the concrete type of the receiver and what setting its video mode entails are not stated in the packet.
    // UNRESOLVED: The meaning of the 4 / 0 return-code convention is not stated in the packet.
}
