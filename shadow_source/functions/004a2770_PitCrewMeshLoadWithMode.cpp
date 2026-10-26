// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A2770
// Canonical corpus name: ModeDependentSubsystemCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ModeDependentSubsystemCall_004a2770.c

void UnknownObject::PitCrewMeshLoadWithMode()
{
    // Stores a mode byte at this+0x2 and a DWORD parameter at this+0x48, then loads the pit crew mesh via PitCrewMeshLoader(this, a4, a5, a6, 0). When the DWORD guard at this+0x64 (fill label: 3D sound-source handle, DERIVED) is non-zero, adjusts runtime flags through FlagFieldBitManipulation, using (1, 1, 0, 0) when the stored mode byte is non-zero and (0, 0, 0, 0) when it is zero. Returns the flag-manipulation result in that guarded path, otherwise the mesh-loader result.
    // ASSIGNMENT: Store the mode/type byte: *(BYTE*)(this+0x2) = a2. [field:this:0x00000002, source:raw]
    // ASSIGNMENT: Store the DWORD parameter: *(DWORD*)(this+0x48) = a3. [field:this:0x00000048, source:raw]
    // CALL: result = PitCrewMeshLoader(this, a4, a5, a6, 0): load the pit crew mesh into the object. [callee:0x004A2010, source:raw]
    // GUARD: If *(DWORD*)(this+0x64) is non-zero (fill label: 3D sound-source handle present, DERIVED), enter the flag-adjust path; otherwise return the mesh loader result. [field:this:0x00000064, source:raw]
    // CALL: When the stored mode byte at this+0x2 is non-zero, FlagFieldBitManipulation(1, 1, 0, 0). [callee:0x0054C030, field:this:0x00000002, source:raw]
    // CALL: When the stored mode byte at this+0x2 is zero, FlagFieldBitManipulation(0, 0, 0, 0). [callee:0x0054C030, field:this:0x00000002, source:raw]
    // RETURN: Return the FlagFieldBitManipulation result from the guarded path, or the mesh loader result when the guard field at this+0x64 is zero. [source:raw]

    // Conservative worker pseudocode:
    //   *(BYTE*)(this+2) = a2;
    //   *(DWORD*)(this+72) = a3;
    //   result = PitCrewMeshLoader(this, a4, a5, a6, 0);
    //   if (*(DWORD*)(this+100)) {
    //       if (*(BYTE*)(this+2)) return FlagFieldBitManipulation(1, 1, 0, 0);
    //       return FlagFieldBitManipulation(0, 0, 0, 0);
    //   }
    //   return result;
    // UNRESOLVED: The meaning of PitCrewMeshLoader arguments a4/a5/a6 is not named in the packet; the fill only describes them as mesh-loader inputs.
    // UNRESOLVED: The guard at this+0x64 as a 3D sound-source handle is a fill claim (DERIVED); the raw source only reads the field as a non-zero guard.
    // UNRESOLVED: The meaning of FlagFieldBitManipulation's (1, 1, 0, 0) / (0, 0, 0, 0) argument tuples is not documented in the packet.
    // UNRESOLVED: The packet ABI legacy name Mode_Dependent_Subsystem_Call (LEGACY trust) is generic and not used as the proposal.
}
