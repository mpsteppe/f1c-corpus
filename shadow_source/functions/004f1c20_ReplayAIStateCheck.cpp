// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F1C20
// Canonical corpus name: ReplayAIStateCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ReplayAIStateCheck_004f1c20.c

void UnknownObject::ReplayAIStateCheck()
{
    // Boolean state predicate: reads a pointer to a per-vehicle AI/replay state object from this+0x3A9C and returns TRUE only when that pointer is non-null AND the dword at byte offset 300 inside the pointed object equals 1. Used by the overtaking system to test whether AI/replay driving is active for a vehicle.
    // ASSIGNMENT: Load the AI/replay state object pointer v1 from this[3751] (dword index; byte offset 0x3A9C). [field:this:0x00003A9C, source:raw]
    // GUARD: Guard: v1 must be non-null AND the dword at *(v1 + 300) must equal 1 for the function to return TRUE. [field:this:0x00003BC8, guard:0, source:raw]
    // RETURN: Return the conjunction: v1 && (*(v1 + 300) == 1). [field:this:0x00003BC8, guard:0, source:raw]
    // CALL: Called by Overtaking (0x0042AF70) on the frame path to gate overtaking logic on AI/replay activity. [caller:0x0042AF70, abi:lead, function:0x004F1C20, source:raw]

    // Conservative worker pseudocode:
    //   BOOL sub_4F1C20(_DWORD *this) {
    //     int v1 = this[3751];
    //     return v1 && *(_DWORD *)(v1 + 300) == 1;
    //   }
    // UNRESOLVED: Type of the object pointed at by this+0x3A9C and the meaning of the flag at byte offset 300 (value 1 = active) are inferred from the existing analysis only.
    // UNRESOLVED: Offset 0x3BC8 on this is the packet's representation of the dereferenced flag at pointer-offset 300; the exact relationship is not pinned.
}
