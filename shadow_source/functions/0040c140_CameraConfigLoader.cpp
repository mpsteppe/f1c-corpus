// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040C140
// Canonical corpus name: sub_40C140
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_40C140_0040c140.c

void UnknownObject::CameraConfigLoader()
{
    // Lazy camera configuration loader. Allocates and initializes an 84-byte camera config object at this+0x18 on first call, truncates the path buffer, appends "cams.cfg" and invokes a vtable+4 method on the config object to load it. On success copies the settings directory path (dword_5EC440, or byte_5EA438 fallback) over the buffer, appends "default.cfg" and loads that too; when the second load succeeds, hands the config object to F_3DTransformObjectAllocator. Finally dispatches the game state via GameStateBranchDispatch and returns 0. Called by CamMan_Init.
    // GUARD: If this+0x18 (this[6]) is zero, lazily allocate the config object on first call. [field:this:0x00000018, source:raw]
    // CALL: OperatorNewNhMallocWrapper(84) allocates the 84-byte config object. [callee:0x00587C03, source:raw]
    // CALL: ShortComputation_84b0 constructs the allocated object. [callee:0x004084B0, source:raw]
    // ASSIGNMENT: Store the constructed object pointer in this+0x18 (this[6]). [field:this:0x00000018, source:raw]
    // CALL: PathTruncationUtility(v8, 512) truncates/normalizes the 512-byte path buffer. [callee:0x004B0220, source:raw]
    // ASSIGNMENT: Append the "cams.cfg" filename string to the path buffer. [source:raw]
    // CALL: Invoke the vtable+4 method on the config object (base *(this+0x18)) with the "cams.cfg" path; the fallback-directory branch is taken only when it returns non-zero. [field:*(this+0x18):0x00000004, field:this:0x00000018, source:raw]
    // ASSIGNMENT: Select the source directory path: dword_5EC440, or byte_5EA438 when dword_5EC440 is zero. [global:0x005EC440, global:0x005EA438, source:raw]
    // CALCULATION: Copy the source directory string byte-by-byte over the path buffer until the NUL terminator. [global:0x005EC440, global:0x005EA438, source:raw]
    // ASSIGNMENT: Append the "default.cfg" filename string to the path buffer. [global:0x005BE874, source:raw]
    // CALL: Invoke the vtable+4 method on the config object with the "default.cfg" path; proceed to allocation only on non-zero result. [field:*(this+0x18):0x00000004, field:this:0x00000018, source:raw]
    // CALL: F_3DTransformObjectAllocator processes the loaded 3D transform data in the config object. [callee:0x0040AA20, source:raw]
    // CALL: GameStateBranchDispatch(this) dispatches the game state after config loading. [callee:0x0040D100, source:raw]
    // RETURN: Return 0. [function:0x0040C140, source:raw]
    // CALL: Invoked by CamMan_Init (0040c920) during camera-manager initialization. [caller:0x0040C920, source:raw]

    // Conservative worker pseudocode:
    //   if (!this[6])
    //       this[6] = ShortComputation_84b0(OperatorNewNhMallocWrapper(84));
    //   PathTruncationUtility(v8, 512);
    //   strcat(v8, "cams.cfg");
    //   if (vtable+4(this[6], v8)) {
    //       src = dword_5EC440 ? dword_5EC440 : byte_5EA438;
    //       strcpy(v8, src);
    //       strcat(v8, "default.cfg");
    //       if (vtable+4(this[6], v8))
    //           F_3DTransformObjectAllocator(this[6]);
    //   }
    //   GameStateBranchDispatch(this);
    //   return 0;
    // UNRESOLVED: Globals off_59E604 and byte_7CE498 are flagged read in the packet but do not appear in the raw decompiled source; their role is not established from this packet.
}
