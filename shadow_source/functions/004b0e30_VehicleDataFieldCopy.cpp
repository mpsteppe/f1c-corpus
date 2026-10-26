// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B0E30
// Canonical corpus name: VehicleDataFieldCopy
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VehicleDataFieldCopy_004b0e30.c

void UnknownObject::VehicleDataFieldCopy()
{
    // Copies 15 vehicle-state fields from scattered source offsets into a contiguous 60-byte destination block beginning at this+0x496C (offsets 0x496C..0x49A4): 14 dword copies, one byte copy (source 0xD44 into byte 0x4984) and one float copy (source 0x2390 into 0x4994). No branches, globals or callees. Returns 1 unconditionally, consistent with a snapshot or save-state capture used by the caller-side init paths.
    // ASSIGNMENT: Copy dword this+0x654 into snapshot field this+0x496C. [field:this:0x00000654, field:this:0x0000496C, source:raw]
    // ASSIGNMENT: Copy dword this+0x888 into snapshot field this+0x4970. [field:this:0x00000888, field:this:0x00004970, source:raw]
    // ASSIGNMENT: Copy dword this+0x984 into snapshot field this+0x4974. [field:this:0x00000984, field:this:0x00004974, source:raw]
    // ASSIGNMENT: Copy dword this+0xA80 into snapshot field this+0x4978. [field:this:0x00000A80, field:this:0x00004978, source:raw]
    // ASSIGNMENT: Copy dword this+0xB7C into snapshot field this+0x497C. [field:this:0x00000B7C, field:this:0x0000497C, source:raw]
    // ASSIGNMENT: Copy dword this+0xC78 into snapshot field this+0x4980. [field:this:0x00000C78, field:this:0x00004980, source:raw]
    // ASSIGNMENT: Copy byte this+0xD44 into snapshot byte field this+0x4984. [field:this:0x00000D44, field:this:0x00004984, source:raw]
    // ASSIGNMENT: Copy dword this+0x209C into snapshot field this+0x4988. [field:this:0x0000209C, field:this:0x00004988, source:raw]
    // ASSIGNMENT: Copy dword this+0x2198 into snapshot field this+0x498C. [field:this:0x00002198, field:this:0x0000498C, source:raw]
    // ASSIGNMENT: Copy dword this+0x2294 into snapshot field this+0x4990. [field:this:0x00002294, field:this:0x00004990, source:raw]
    // ASSIGNMENT: Copy float this+0x2390 into snapshot float field this+0x4994 (float copied via v1). [field:this:0x00002390, field:this:0x00004994, source:raw]
    // ASSIGNMENT: Copy dword this+0x248C into snapshot field this+0x49A4 (source read last, via v13). [field:this:0x0000248C, field:this:0x000049A4, source:raw]
    // ASSIGNMENT: Copy dword this+0x2588 into snapshot field this+0x4998. [field:this:0x00002588, field:this:0x00004998, source:raw]
    // ASSIGNMENT: Copy dword this+0x275C into snapshot field this+0x499C. [field:this:0x0000275C, field:this:0x0000499C, source:raw]
    // ASSIGNMENT: Copy dword this+0x2858 into snapshot field this+0x49A0. [field:this:0x00002858, field:this:0x000049A0, source:raw]
    // RETURN: Return 1 unconditionally (success indicator for the snapshot copy). [function:0x004B0E30, source:raw]
    // CALL: Invoked by F_5StepInit (004B0720) and SettingsFileInit (004B0930), consistent with a vehicle-data snapshot captured during init. [caller:0x004B0720, caller:0x004B0930, source:raw]

    // Conservative worker pseudocode:
    //   char VehicleDataFieldCopy(this) {
    //     float v1 = *(float*)(this + 0x2390);
    //     int v2 = *(int*)(this + 0x888);
    //     *(int*)(this + 0x496C) = *(int*)(this + 0x654);
    //     int v3 = *(int*)(this + 0x984);
    //     *(int*)(this + 0x4970) = v2;
    //     int v4 = *(int*)(this + 0xA80);
    //     *(int*)(this + 0x4974) = v3;
    //     int v5 = *(int*)(this + 0xB7C);
    //     *(int*)(this + 0x4978) = v4;
    //     int v6 = *(int*)(this + 0xC78);
    //     *(int*)(this + 0x497C) = v5;
    //     v5 = *(byte*)(this + 0xD44);
    //     *(int*)(this + 0x4980) = v6;
    //     int v7 = *(int*)(this + 0x209C);
    //     *(byte*)(this + 0x4984) = v5;
    //     int v8 = *(int*)(this + 0x2198);
    //     *(int*)(this + 0x4988) = v7;
    //     int v9 = *(int*)(this + 0x2294);
    //     *(int*)(this + 0x498C) = v8;
    //     int v10 = *(int*)(this + 0x2588);
    //     *(int*)(this + 0x4990) = v9;
    //     int v11 = *(int*)(this + 0x275C);
    //     *(int*)(this + 0x4998) = v10;
    //     int v12 = *(int*)(this + 0x2858);
    //     *(int*)(this + 0x499C) = v11;
    //     int v13 = *(int*)(this + 0x248C);
    //     *(float*)(this + 0x4994) = v1;
    //     *(int*)(this + 0x49A0) = v12;
    //     *(int*)(this + 0x49A4) = v13;
    //     return 1;
    //   }
    // UNRESOLVED: Field semantics of the 15 source offsets and the snapshot block are not documented; meaning depends on the vehicle-struct layout
    // UNRESOLVED: Existing analysis names the callers F_5StepInit and SettingsFileInit, but the snapshot's consumer is not established here
}
