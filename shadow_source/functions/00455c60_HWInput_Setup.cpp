// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00455C60
// Canonical corpus name: HWInput_Setup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/HWInput_Setup_00455c60.c

void UnknownObject::HWInput_Setup()
{
    // Hardware input setup: logs an entry message when the session type is not 5 and debug logging is enabled, creates a DirectInput8 interface, then on success builds and re-initializes a set of input sub-device slots in the ppvOut array (window surface, two device slots each initialized, destroyed and re-initialized). Returns the final sub-device global-state initializer result on success, or the DirectInput8Create HRESULT on failure.
    // GUARD: If dword_7C569C != 5 (session type is not 5) and StringSplitLoop(2, aDDevF119992002_13, 5225) returns true, debug logging is enabled for this path. [global:0x007C569C, global:0x005C56A4, callee:0x004D7A50, source:raw]
    // CALL: Call DebugLogWrite(&dword_8AD25C, aEnteredHwinput_0) to log the input-setup entry message. [callee:0x004D7AA0, global:0x008AD25C, global:0x005C56CC, source:raw]
    // CALL: Call DirectInput8Create(hinst, 0x800, &riidltf, ppvOut, 0) to create the DirectInput8 interface and store it into ppvOut. [callee:0x0052D8B0, global:0x007CE2A0, global:0x005AD4A0, source:raw]
    // GUARD: Proceed with sub-device setup only when result (the DirectInput8Create HRESULT) is 0. [source:raw]
    // CALL: Call D3DWindowSurfaceCreation(ppvOut + 1, hWnd, byte_5EC4A4, 2) to create a D3D window surface for the first input sub-device. [callee:0x0044EE10, global:0x007CE2DC, global:0x005EC4A4, source:raw]
    // CALL: Call DirectXDeviceInitialization(ppvOut + 866, hWnd, byte_5EC4A4) to initialize sub-device slot 866. [callee:0x0044FA60, global:0x007CE2DC, global:0x005EC4A4, source:raw]
    // CALL: Call DirectXDeviceInitialization(ppvOut + 1121, hWnd, byte_5EC4A4) to initialize sub-device slot 1121. [callee:0x0044FA60, global:0x007CE2DC, global:0x005EC4A4, source:raw]
    // CALL: Call CollisionObjectDestructor(ppvOut + 1121) to tear down sub-device slot 1121. [callee:0x0044FBE0, source:raw]
    // CALL: Call CollisionObjectDestructor(ppvOut + 866) to tear down sub-device slot 866. [callee:0x0044FBE0, source:raw]
    // CALL: Call DirectXDeviceInitialization(ppvOut + 866, hWnd, byte_5EC4A4) to re-initialize sub-device slot 866. [callee:0x0044FA60, global:0x007CE2DC, global:0x005EC4A4, source:raw]
    // CALL: Call DirectXDeviceInitialization(ppvOut + 1121, hWnd, byte_5EC4A4) to re-initialize sub-device slot 1121. [callee:0x0044FA60, global:0x007CE2DC, global:0x005EC4A4, source:raw]
    // RETURN: On success, return the result of the final call that initializes global state from enum values over ppvOut (named GlobalStateInitializerWithEnumValues in the raw source; not present in the packet callee records). [source:raw]
    // RETURN: On DirectInput8Create failure, return result (the nonzero HRESULT). [function:0x00455C60, source:raw]

    // Conservative worker pseudocode:
    //   if (dword_7C569C != 5 && StringSplitLoop(2, aDDevF119992002_13, 5225))
    //     DebugLogWrite(&dword_8AD25C, aEnteredHwinput_0);
    //   result = DirectInput8Create(hinst, 0x800, &riidltf, ppvOut, 0);
    //   if (!result) {
    //     D3DWindowSurfaceCreation(ppvOut + 1, hWnd, byte_5EC4A4, 2);
    //     DirectXDeviceInitialization(ppvOut + 866, hWnd, byte_5EC4A4);
    //     DirectXDeviceInitialization(ppvOut + 1121, hWnd, byte_5EC4A4);
    //     CollisionObjectDestructor(ppvOut + 1121);
    //     CollisionObjectDestructor(ppvOut + 866);
    //     DirectXDeviceInitialization(ppvOut + 866, hWnd, byte_5EC4A4);
    //     DirectXDeviceInitialization(ppvOut + 1121, hWnd, byte_5EC4A4);
    //     return GlobalStateInitializerWithEnumValues(ppvOut);
    //   }
    //   return result;
    // UNRESOLVED: The final success-path call (GlobalStateInitializerWithEnumValues per raw source) has no address in the packet callee records; its target cannot be pinned from this packet alone.
    // UNRESOLVED: Which physical input device each element slot (866, 1121) corresponds to is unknown; the slots are identified by raw-source element indices only.
    // UNRESOLVED: The 0x800 argument to DirectInput8Create and the role of byte_5EC4A4 (window surface configuration) are unverified from packet evidence.
    // UNRESOLVED: Legacy ABI name HWInput_Setup (abi:lead) is retained as a lead only; the owning object type remains unknown.
}
