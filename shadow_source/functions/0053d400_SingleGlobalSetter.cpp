// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053D400
// Canonical corpus name: SingleGlobalSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SingleGlobalSetter_0053d400.c

void UnknownObject::SingleGlobalSetter()
{
    // Single global setter: writes argument a1 into the module global dword_8B8E4C and returns a1 unchanged. Called from the video-manager init and post paths (VidMan_Init, VidMan_Post); the global's downstream purpose is not established by this packet.
    // ASSIGNMENT: Copy the argument into the result register: result = a1. [source:raw]
    // ASSIGNMENT: Write a1 into the global dword_8B8E4C (0x008B8E4C), the only side effect of this setter. [global:0x008B8E4C, source:raw]
    // RETURN: Return result, i.e. the stored value a1. [function:0x0053D400, source:raw]

    // Conservative worker pseudocode:
    //   int sub_53D400(int a1) {
    //     int result = a1;
    //     dword_8B8E4C = a1;
    //     return result;
    //   }
    // UNRESOLVED: The meaning of the global dword_8B8E4C (0x008B8E4C) is unestablished; the packet records no readers.
    // UNRESOLVED: Both recorded callers (VidMan_Init, VidMan_Post) are video-manager paths, but the value semantics of a1 (e.g. a mode, handle, or width/height) are not given.
}
