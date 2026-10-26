// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F8C90
// Canonical corpus name: ModuleUnload
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ModuleUnload_004f8c90.c

void UnknownObject::ModuleUnload()
{
    // Module teardown guard-and-release. If the loaded-module handle hLibModule (0x008AFC78) is not set, returns 3 without acting. Otherwise invokes VFXClose (function pointer stored at 0x008AFC80), releases the library via FreeLibrary (IAT slot 0x0059E0C4), clears hLibModule, and returns 0. Called by HWInput_Exit (0x00455F00).
    // GUARD: If hLibModule (0x008AFC78) is null, bail out early. [global:0x008AFC78, source:raw]
    // RETURN: Return 3 when the module handle was never loaded. [global:0x008AFC78, source:raw]
    // CALL: Call the VFX close function through the pointer at 0x008AFC80. [global:0x008AFC80, source:raw]
    // CALL: Call FreeLibrary(hLibModule) through the import slot at 0x0059E0C4 to release the loaded module. [global:0x0059E0C4, global:0x008AFC78, source:raw]
    // ASSIGNMENT: Clear hLibModule to 0 so a later unload is a no-op. [global:0x008AFC78, source:raw]
    // RETURN: Return 0 on the successful unload path. [source:raw]

    // Conservative worker pseudocode:
    //   if (!hLibModule) return 3;
    //   VFXClose();
    //   FreeLibrary(hLibModule);
    //   hLibModule = 0;
    //   return 0;
    // UNRESOLVED: Semantic meaning of the return code 3 (early-out) is unknown.
    // UNRESOLVED: VFXClose at 0x008AFC80 is an indirect call target; the actual close routine is not identified here.
}
