// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B09A0
// Canonical corpus name: TextFileReader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TextFileReader_004b09a0.c

void UnknownObject::ReadTextFileAndSetupEnvironment()
{
    // Given a file path argument, resolves it into the receiver's buffer and creates every directory level of that path (each backslash-separated prefix as well as the full path). It then selects the environment type (wet or dry) from the bit-0 flag byte_7CB710, loads the AIW scene data when the scene-file count dword_8AC488 is non-zero, and loads vehicle file data when the vehicle-file count dword_8AC390 is non-zero, copying the vehicle path strings and registering the receiver's 0x1B4 path string (falling back to byte_5EA438) with the memory-cleanup list head dword_5EA5E8. Finally it copies the save file, selects the track environment, cleans up the dual-linked list dword_7C73E8, and reads the settings file before returning 0.
    // GUARD: If the input path argument a2 is null, return -1 immediately. [source:raw]
    // CALL: Call sub_4B0180 with the input path a2 and the receiver buffer this+20 to resolve the path into the receiver's buffer. [callee:0x004B0180]
    // CALL: Call sub_568620 with size 512 to prepare the fixed-size directory-name buffer v9. [callee:0x00568620]
    // LOOP: Iterate the resolved path characters v9 from index 0 up to strlen(v9)-1, capped at 0x400; for each backslash (byte 92) call sub_587DD0 to build the parent prefix into PathName, null-terminate PathName at that index, and create the directory via CreateDirectoryAWrapper so every directory level of the path is created. [callee:0x00587DD0, callee:0x00589671]
    // CALL: Call CreateDirectoryAWrapper on the full resolved path v9 to create the final directory. [callee:0x00589671]
    // CALL: Call sub_4B01B0 with the input path a2 and the receiver buffer this+20 to reinitialize the path buffer. [callee:0x004B01B0]
    // GUARD: If bit 0 of the environment flag byte_7CB710 is set, call sub_4AE750(this, 2); otherwise call sub_4AE750(this, 1), selecting the environment type (wet vs dry). [global:0x007CB710, callee:0x004AE750]
    // GUARD: If the scene-file count dword_8AC488 is greater than zero, call AIW(this) to load the AIW scene data. [global:0x008AC488, callee:0x004C54F0]
    // GUARD: If the vehicle-file count dword_8AC390 is greater than zero, load the vehicle file data block. [global:0x008AC390]
    // CALL: Read the first vehicle path string via CurrentVehicleAccessor(&unk_8AC388), falling back to the default directory byte_5EA438 when the pointer is null, then copy it with StringCopyWithBufferRealloc. [callee:0x004C4080, global:0x008AC388, global:0x005EA438, callee:0x00566650]
    // CALL: Read the second vehicle buffer via CurrentVehicleAccessor(&unk_8AC388) at offset 188 and copy it with StringCopyWithBufferRealloc. [callee:0x004C4080, global:0x008AC388, callee:0x00566650]
    // ASSIGNMENT: Read the path string pointer at this+436 (field 0x1B4), falling back to the default directory byte_5EA438 when it is null. [field:this:0x000001B4, global:0x005EA438]
    // CALL: Call ShortComputation_5730 with the memory-cleanup list head dword_5EA5E8 and the path pointer to register the string for cleanup. [callee:0x00415730, global:0x005EA5E8]
    // CALL: Call sub_4ADD50 to copy the save file with metadata. [callee:0x004ADD50]
    // CALL: Call TrackEnvironmentSelect(this, 1) to select the track environment and initialize physics. [callee:0x004ADE20]
    // CALL: Call DualLinkedListCleanup on the list global dword_7C73E8 to release the device identity list. [callee:0x004331A0, global:0x007C73E8]
    // CALL: Call sub_4B0770(this, 1) to read the settings file. [callee:0x004B0770]
    // RETURN: Return 0 to signal success. [source:raw]

    // Conservative worker pseudocode:
    //   int ReadTextFileAndSetupEnvironment(int *this, const char *a2) {
    //     char v9[512];
    //     char PathName[1024];
    //     if (!a2) return -1;
    //     sub_4B0180(a2, this + 20);
    //     sub_568620(512);
    //     v4 = 0;
    //     v5 = strlen(v9) + 1;
    //     if ((int)(v5 - 1) > 0) {
    //       do {
    //         if (v4 >= 0x400) break;
    //         if (v9[v4] == 92) {
    //           sub_587DD0(PathName, v9, v4);
    //           PathName[v4] = 0;
    //           CreateDirectoryAWrapper(PathName);
    //         }
    //         ++v4;
    //       } while ((int)v4 < (int)(v5 - 1));
    //     }
    //     CreateDirectoryAWrapper(v9);
    //     sub_4B01B0(a2, (char *)(this + 20));
    //     if ((byte_7CB710 & 1) != 0)
    //       sub_4AE750((int *)this, 2);
    //     else
    //       sub_4AE750((int *)this, 1);
    //     if (dword_8AC488 > 0)
    //       AIW(this);
    //     if (dword_8AC390 > 0) {
    //       v6 = *(char **)CurrentVehicleAccessor(&unk_8AC388);
    //       if (!v6) v6 = byte_5EA438;
    //       StringCopyWithBufferRealloc(v6);
    //       v7 = CurrentVehicleAccessor(&unk_8AC388);
    //       StringCopyWithBufferRealloc(v7 + 188);
    //       v8 = *(char **)(this + 436);
    //       if (!v8) v8 = byte_5EA438;
    //       ShortComputation_5730((int **)&dword_5EA5E8, (int)v8);
    //     }
    //     sub_4ADD50();
    //     TrackEnvironmentSelect((_DWORD *)this, 1);
    //     DualLinkedListCleanup((int)&dword_7C73E8);
    //     sub_4B0770((int *)this, 1);
    //     return 0;
    //   }
    // UNRESOLVED: The global unk_8AC368 (0x008AC368) is listed in the packet but does not appear in the raw source text; its relationship to this function is unknown.
    // UNRESOLVED: The precise semantics of the helper calls sub_4B0180 / sub_4B01B0 (path buffer handling), sub_568620 (buffer setup), sub_587DD0 (prefix builder), AIW, CurrentVehicleAccessor, StringCopyWithBufferRealloc, sub_4ADD50 and ShortComputation_5730 are not established here.
    // UNRESOLVED: The mapping of environment values 2 and 1 to wet and dry is drawn from the existing analysis and is not directly named in the raw source.
}
