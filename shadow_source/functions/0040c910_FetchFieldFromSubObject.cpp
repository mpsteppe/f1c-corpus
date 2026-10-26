// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040C910
// Canonical corpus name: ShortComputation_c910
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_c910_0040c910.c

void UnknownObject::FetchFieldFromSubObject()
{
    // Trivial field accessor: reads the dword at offset 4 of a sub-object pointer stored at this+8 and returns it. No guards, no calls, no globals. Called by MainCameraDirectorUpdate (0040CA30), CarSelectionStateMachine (00434460), sub_49F870 (0049F870), ArithmeticComparison_9000 (004C9000) and CameraViewportRenderSetup (004FBD70).
    // CALCULATION: Dereference the pointer at this+8 to obtain the sub-object pointer, then add 4 to reach the returned field. [field:this:0x00000008, source:raw]
    // RETURN: Return the dword read from sub-object offset 4. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_40C910(void *this) {
    //     return *(DWORD *)(*(DWORD *)(this + 8) + 4);
    //   }
    // UNRESOLVED: Identity of the sub-object (the pointer stored at this+8) is unknown here.
    // UNRESOLVED: Meaning of the returned dword at sub-object offset 4 depends on the callers' object type.
}
