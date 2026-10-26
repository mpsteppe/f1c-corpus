// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C6C40
// Canonical corpus name: VehgenScnFileLoader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VehgenScnFileLoader_004c6c40.c

void UnknownObject::VehgenScnFileLoader()
{
    // Vehicle-generation scene loader. Allocates a 128-byte scratch buffer, derives the load path from dword_5EC438 (fallback byte_5EA438), establishes the scene file name aVehgenScn ("vehgen.scn"), writes the TEAMDIR/VEHDIR/NOTSPIN scene flag via SceneFileTEAMDIRVEHDIRNOTSPINWriter using the team id at this+0x4894, then drives vehicle-graphics scene loading (sub_4A4900, VehicleGraphicsSceneLoader, FileAttributesExistenceCheck) and a scene-teardown branch (ArithmeticComparison_8370, ZeroTwoFields). Resets this+0x48A4 and this+0x48A8 to -1. When this+0x32C8 is zero, reads config via sub_4B0B20, sets the driver name, copies the nationality data path (dword_7CE684, fallback byte_5EA438) into this+0x4660 with a 23-char limit and null-terminates it at this+0x4677. Then sets the driver number, runs ShortComputation_0b20 on dword_5EA560 and this+0xC, and frees the scratch buffer via FreeWrapper_7bcf.
    // CALL: Allocate 128-byte scratch buffer via OperatorNewNhMallocWrapper(128). [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Initialize scratch buffer first byte to 0. [source:raw]
    // CALL: Set load path from dword_5EC438 (fallback byte_5EA438) via StringCopyWithBufferRealloc. [callee:0x00566650, global:0x005EC438, global:0x005EA438, source:raw]
    // CALL: Establish the scene file name via sub_5665B0 with the aVehgenScn ("vehgen.scn") string constant. [callee:0x005665B0, global:0x005D3224, source:raw]
    // CALL: Write the TEAMDIR/VEHDIR/NOTSPIN scene flag via SceneFileTEAMDIRVEHDIRNOTSPINWriter using the team id field this+0x4894 and value 0. [callee:0x004DDF90, field:this:0x00004894, source:raw]
    // CALL: sub_4A4900 on the this+0x32CC field with the scratch-or-fallback path string. [callee:0x004A4900, source:raw]
    // CALL: Load vehicle graphics scene via VehicleGraphicsSceneLoader(scratch, a2). [callee:0x004DFCE0, source:raw]
    // CALL: Check the scene file exists via FileAttributesExistenceCheck on the scratch-or-fallback path. [callee:0x00568540, source:raw]
    // CALL: Run scene teardown comparison branch ArithmeticComparison_8370 on this+0x14. [callee:0x004F8370, source:raw]
    // CALL: Zero two fields at this+0x4034 via ZeroTwoFields. [callee:0x004BB800, source:raw]
    // ASSIGNMENT: Reset this+0x48A4 to -1. [field:this:0x000048A4, source:raw]
    // ASSIGNMENT: Reset this+0x48A8 to -1. [field:this:0x000048A8, source:raw]
    // GUARD: Guard: field this+0x32C8 is zero, enabling the driver-name loading block. [field:this:0x000032C8, source:raw]
    // CALL: Fill a 63-byte driver-name buffer from byte_7CE498 via sub_4B0B20. [callee:0x004B0B20, global:0x007CE498, source:raw]
    // CALL: Set the driver name via SetDriverName on the this object with the filled buffer. [callee:0x004C6980, source:raw]
    // CALL: Copy nationality data path dword_7CE684 (fallback byte_5EA438) into this+0x4660 via sub_587DD0 with a 23-char limit. [callee:0x00587DD0, global:0x007CE684, global:0x005EA438, source:raw]
    // ASSIGNMENT: Null-terminate the nationality/path string at this+0x4677. [field:this:0x00004677, source:raw]
    // CALL: Set up the driver number via VehicleSetupDriverNumber(this). [callee:0x004C7B50, source:raw]
    // CALL: ShortComputation_0b20 on global dword_5EA560 and this+0xC. [callee:0x00410B20, global:0x005EA560, source:raw]
    // GUARD: Guard: scratch buffer non-null before freeing. [source:raw]
    // CALL: Free the scratch buffer via FreeWrapper_7bcf and return it. [callee:0x00587BCF, source:raw]
    // RETURN: Return the scratch buffer (null when allocation returned null). [source:raw]

    // Conservative worker pseudocode:
    //   char* sub_4C6C40(int this, char a2) {
    //     char* buf = OperatorNewNhMallocWrapper(128);
    //     if (buf) *buf = 0;
    //     StringCopyWithBufferRealloc(dword_5EC438 ? dword_5EC438 : byte_5EA438);
    //     sub_5665B0(aVehgenScn);
    //     SceneFileTEAMDIRVEHDIRNOTSPINWriter(*(DWORD*)(this + 18580), 0);
    //     sub_4A4900((DWORD*)(this + 13004), buf ? buf : byte_5EA438);
    //     VehicleGraphicsSceneLoader(buf ? buf : byte_5EA438, a2);
    //     FileAttributesExistenceCheck(buf ? buf : byte_5EA438);
    //     ArithmeticComparison_8370(this + 20);
    //     ZeroTwoFields((DWORD*)(this + 16436));
    //     *(DWORD*)(this + 18596) = -1;
    //     *(DWORD*)(this + 18600) = -1;
    //     if (!*(DWORD*)(this + 13000)) {
    //       char name[64];
    //       sub_4B0B20(byte_7CE498, name, 63);
    //       SetDriverName((char*)this, (int)name);
    //       sub_587DD0(this + 18016, dword_7CE684 ? dword_7CE684 : byte_5EA438, 23);
    //       *(BYTE*)(this + 18039) = 0;
    //     }
    //     VehicleSetupDriverNumber(this);
    //     ShortComputation_0b20(dword_5EA560, this + 12);
    //     if (buf) return FreeWrapper_7bcf(buf);
    //     return buf;
    //   }
    // UNRESOLVED: Role of the this+0x4894 team id and the exact TEAMDIR/VEHDIR/NOTSPIN writer semantics are derived from surrounding context only.
    // UNRESOLVED: The meaning of the a2 flag parameter passed to VehicleGraphicsSceneLoader is unknown.
    // UNRESOLVED: Fields this+0x32CC, this+0x4034, this+0x14 and this+0x4660 are read/written in the raw source but have no packet field entries.
    // UNRESOLVED: VehicleLookupByName-style lookup internals of sub_5665B0 are not evidenced.
}
