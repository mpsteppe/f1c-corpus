// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042D260
// Canonical corpus name: GameFileLoader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GameFileLoader_0042d260.c

void UnknownObject::GameFileLoader()
{
    // Loads game assets: resolves the application path, builds a base directory from an override pointer (falling back to a default buffer), initializes the random noise table, loads tire brands, scene files and vehicle files. Returns 1 when no scene or vehicle files are present, and 0 when both load successfully.
    // CALL: Call GetModuleFileNameA(0, Filename, 0x100) to write the executable's module path into the Filename buffer. [global:0x0059E0EC, source:raw]
    // GUARD: If GetModuleFileNameA returned nonzero, call UtilityFunction_8a60(7, this + 28). [global:0x0059E0EC, source:raw]
    // CALL: Call UtilityFunction_8a60(7, this + 28) to record the module path into the object at this + 28. [callee:0x00568A60, source:raw]
    // ASSIGNMENT: Resolve the base directory: v2 = dword_5EC408, or when dword_5EC408 is 0 fall back to &byte_5EA438. [global:0x005EC408, global:0x005EA438, source:raw]
    // CALL: Call sub_423890(byte_5EC4C0, v2, 0) to build the full asset path string into byte_5EC4C0 from the resolved base directory. [callee:0x00423890, global:0x005EC4C0, source:raw]
    // CALL: Call RandomNoiseTableInitialization(&dword_8AAE70) to initialize the random/weather noise lookup table. [callee:0x004B3BD0, global:0x008AAE70, source:raw]
    // CALL: Call TireBrandLoader(&dword_8AD254) to load tire brand data. [callee:0x004D7660, global:0x008AD254, source:raw]
    // CALL: Call SceneFileLoader(&unk_8AC368) to load scene files. [callee:0x004C52C0, global:0x008AC368, source:raw]
    // GUARD: If dword_8AC488 (loaded scene count) is 0 or negative, log the missing-scenes error and return 1. [global:0x008AC488, source:raw]
    // CALL: Call StringSplitLoop(1, aDDevF119992002_11, 326); when it returns true, proceed to log the error. [callee:0x004D7A50, global:0x005C3590, source:raw]
    // CALL: Call DebugLogWrite(&dword_8AD25C, aNoSceneFilesFo) to write the no-scene-files message. [callee:0x004D7AA0, global:0x008AD25C, global:0x005C35E8, source:raw]
    // RETURN: Return 1 when the scene file count is not positive. [function:0x0042D260, source:raw]
    // CALL: Call VehicleFileLoader(&unk_8AC388) to load vehicle definition files. [callee:0x004C3D80, global:0x008AC388, source:raw]
    // GUARD: If dword_8AC390 (loaded vehicle count) is 0 or negative, log the missing-vehicles error and return 1. [global:0x008AC390, source:raw]
    // CALL: Call StringSplitLoop(1, aDDevF119992002_11, 335); when it returns true, proceed to log the error. [callee:0x004D7A50, global:0x005C3590, source:raw]
    // CALL: Call DebugLogWrite(&dword_8AD25C, aNoVehicleFiles) to write the no-vehicle-files message. [callee:0x004D7AA0, global:0x008AD25C, global:0x005C35D0, source:raw]
    // RETURN: Return 1 when the vehicle file count is not positive. [function:0x0042D260, source:raw]
    // RETURN: Return 0 on the full-success path where both scene and vehicle files loaded. [function:0x0042D260, source:raw]

    // Conservative worker pseudocode:
    //   char Filename[256];
    //   if (GetModuleFileNameA(0, Filename, 0x100))
    //     UtilityFunction_8a60(7, this + 28);
    //   base = dword_5EC408 ? dword_5EC408 : &byte_5EA438;
    //   sub_423890(byte_5EC4C0, base, 0);
    //   RandomNoiseTableInitialization(&dword_8AAE70);
    //   TireBrandLoader(&dword_8AD254);
    //   SceneFileLoader(&unk_8AC368);
    //   if (dword_8AC488 <= 0) {
    //     if (StringSplitLoop(1, aDDevF119992002_11, 326))
    //       DebugLogWrite(&dword_8AD25C, aNoSceneFilesFo);
    //     return 1;
    //   }
    //   VehicleFileLoader(&unk_8AC388);
    //   if (dword_8AC390 <= 0) {
    //     if (StringSplitLoop(1, aDDevF119992002_11, 335))
    //       DebugLogWrite(&dword_8AD25C, aNoVehicleFiles);
    //     return 1;
    //   }
    //   return 0;
    // UNRESOLVED: Semantics of the UtilityFunction_8a60(7, this + 28) call and the meaning of its constant 7 are unknown; this + 28 has no field record in the packet.
    // UNRESOLVED: dword_5EC408 as an override path pointer and dword_8AC488/dword_8AC390 as counts are carried over from existing analysis prose, not proven by raw evidence.
    // UNRESOLVED: The 326 and 335 constants passed to StringSplitLoop (debug-log gating) are unexplained.
}
