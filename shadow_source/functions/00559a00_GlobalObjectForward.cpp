// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00559A00
// Canonical corpus name: sub_559A00
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_559A00_00559a00.c

void UnknownObject::GlobalObjectForward()
{
    // Stdcall dispatcher: when the global object pointer dword_8B8F2C is non-null, forwards all three arguments to the __stdcall handler sub_559570 with that global as the first (this-like) argument and returns its result; otherwise logs the error string aCouldNotFindRe via sub_53C590 with a -1 code and returns -1. Called by Steward_Setup during setup to request a named resource through the registry object.
    // GUARD: Guard on the global object pointer dword_8B8F2C (0x008B8F2C): when non-null the forward path is taken, when null the error path is taken. [global:0x008B8F2C, source:raw]
    // CALL: Forward path: call sub_559570 with dword_8B8F2C as the first (this-like) argument followed by a1, a2, a3, and return its result unchanged. [function:0x00559A00, source:raw]
    // CALL: Error path: call sub_53C590 (0x0053C590) with argument -1 and the aCouldNotFindRe (0x005DC1D8) string to report that the registry object was not found. [callee:0x0053C590, global:0x005DC1D8, source:raw]
    // RETURN: Return -1 after the error log, and return sub_559570's result on the forward path. [source:raw]
    // CALL: Called by Steward_Setup (0x004D36D0) during setup to dispatch a resource request through the global registry object. [caller:0x004D36D0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_559A00(const char *a1, int a2, int a3) {
    //     if (dword_8B8F2C)
    //       return sub_559570((int *)dword_8B8F2C, a1, a2, a3);
    //     sub_53C590(-1, aCouldNotFindRe);
    //     return -1;
    //   }
    // UNRESOLVED: Identity and semantics of the forward handler sub_559570 are not present in this packet's callee evidence; the call is taken from the raw source only.
    // UNRESOLVED: Type and meaning of the global object at dword_8B8F2C are unknown here.
    // UNRESOLVED: Full content and purpose of the aCouldNotFindRe message string are unknown.
}
