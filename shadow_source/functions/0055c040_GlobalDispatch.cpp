// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055C040
// Canonical corpus name: GlobalDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GlobalDispatch_0055c040.c

void UnknownObject::GlobalDispatch()
{
    // Thin cdecl wrapper that forwards two globals, dword_8B78A0 and dword_8B8F0C, to RendererResourceCleanup (0x0053EAD0) and returns that callee's result unchanged. Invoked by VidMan_Exit (0x004FAD00), making it part of the renderer/video-manager teardown path.
    // CALL: Call RendererResourceCleanup(dword_8B78A0, dword_8B8F0C): forward the two global renderer handle/state values to the cleanup routine. [callee:0x0053EAD0, global:0x008B78A0, global:0x008B8F0C, source:raw]
    // RETURN: Return the integer result produced by RendererResourceCleanup unchanged. [source:raw]
    // CALL: Invoked by VidMan_Exit (0x004FAD00) during video-manager shutdown; the wrapper is the renderer resource cleanup step of that exit sequence. [caller:0x004FAD00, source:raw]

    // Conservative worker pseudocode:
    //   int GlobalDispatch() {
    //     return RendererResourceCleanup(dword_8B78A0, dword_8B8F0C);
    //   }
    // UNRESOLVED: Role and concrete type of the two globals dword_8B78A0 and dword_8B8F0C (handles vs pointers) are not present in the packet.
    // UNRESOLVED: Semantics of RendererResourceCleanup's return value (success flag vs count) are unproven; only its name and signature are known.
    // UNRESOLVED: Relationship to the wider VidMan_Exit teardown order is not provable from this packet.
}
