// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00534AE0
// Canonical corpus name: AVIFileExit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AVIFileExit_00534ae0.c

void UnknownObject::AVIFileExit()
{
    // Import thunk for the AVIFileExit AVI library routine. It unconditionally forwards to the import address table entry __imp_AVIFileExit at 0x0059E04C and returns. The function has no parameters and no explicit body beyond the indirection.
    // CALL: Indirect call through the import address table pointer __imp_AVIFileExit (0x0059E04C) to the imported AVIFileExit routine. [global:0x0059E04C, function:0x00534AE0, source:raw]
    // RETURN: Void thunk returns immediately after the forwarded call completes. [function:0x00534AE0, source:raw]

    // Conservative worker pseudocode:
    //   void AVIFileExit(void) {
    //     __imp_AVIFileExit();
    //   }
    // UNRESOLVED: The side effects of the imported AVIFileExit routine are not visible at this thunk and depend on the AVI library implementation.
}
