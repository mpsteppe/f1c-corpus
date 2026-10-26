// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050FEA7
// Canonical corpus name: sub_50FEA7
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_50FEA7_0050fea7.c

void UnknownObject::InitD3DPSGPFunctionTable()
{
    // Initializes a D3D PSGP function-pointer table. With Data non-zero, copies a template table from off_5D78B0 into off_5D77C8, initializes it via FunctionTableInit, reads the "DisableD3DXPSGP" registry override, and otherwise patches the table for the best detected CPU feature (SSE2/SSE/3DNow!), recording the selected variant in dword_5D7998. With Data zero, resets dword_5D7998 to 0xFFFF (uninitialized) and restores the template copy. Returns dword_5D7998.
    // GUARD: If Data is non-zero, run the CPU-feature-dependent table initialization; otherwise take the reset branch. [source:raw]
    // ASSIGNMENT: Set dword_5D7998 = 0 as the in-progress initialization state marker. [global:0x005D7998, source:raw]
    // CALL: Copy the template function table from off_5D78B0 into off_5D77C8 (0xE4 bytes). [global:0x005D77C8, global:0x005D78B0, source:raw]
    // CALL: Initialize the copied table with FunctionTableInit(&off_5D77C8). [callee:0x00517927, global:0x005D77C8, source:raw]
    // CALL: Read the DisableD3DXPSGP registry override via sub_50FBFC(4, aDisabled3dxpsg, &Data, 4); on failure Data is forced to 0. [callee:0x0050FBFC, global:0x005ADE84, source:raw]
    // GUARD: If Data != 1 (override not forcing the disabled state), detect the CPU feature and patch the table for it. [source:raw]
    // GUARD: If OSVersionDetection(7) succeeds, patch the table with sub_5172A5(&off_5D77C8) and set dword_5D7998 = 1. [callee:0x0050FDF3, callee:0x005172A5, global:0x005D77C8, global:0x005D7998, source:raw]
    // GUARD: Else if OSVersionDetection(0xA) succeeds, patch the table with sub_5170C0(&off_5D77C8) and set dword_5D7998 = 2. [callee:0x0050FDF3, callee:0x005170C0, global:0x005D77C8, global:0x005D7998, source:raw]
    // GUARD: Else if OSVersionDetection(6) succeeds, patch the table with UnidentifiedLogicFunctionTable(&off_5D77C8) and set dword_5D7998 = 3. [callee:0x0050FDF3, callee:0x00516FB0, global:0x005D77C8, global:0x005D7998, source:raw]
    // ASSIGNMENT: Reset branch: set dword_5D7998 = 0xFFFF (uninitialized marker) and restore the template copy off_5D78B0 into off_5D77C8. [global:0x005D7998, global:0x005D77C8, global:0x005D78B0, source:raw]
    // RETURN: Return dword_5D7998 as the current table state. [global:0x005D7998, source:raw]

    // Conservative worker pseudocode:
    //   if (Data) {
    //     if (dword_5D7998 == 0xFFFF) {
    //       dword_5D7998 = 0;
    //       qmemcpy(&off_5D77C8, off_5D78B0, 0xE4);
    //       FunctionTableInit(&off_5D77C8);
    //       if (!sub_50FBFC(4, aDisabled3dxpsg, &Data, 4)) Data = 0;
    //       if (Data != 1) {
    //         if (OSVersionDetection(7)) { sub_5172A5(&off_5D77C8); dword_5D7998 = 1; }
    //         else if (OSVersionDetection(0xA)) { sub_5170C0(&off_5D77C8); dword_5D7998 = 2; }
    //         else if (OSVersionDetection(6)) { UnidentifiedLogicFunctionTable(&off_5D77C8); dword_5D7998 = 3; }
    //       }
    //     }
    //   } else {
    //     dword_5D7998 = 0xFFFF;
    //     qmemcpy(&off_5D77C8, off_5D78B0, 0xE4);
    //   }
    //   return dword_5D7998;
    // UNRESOLVED: The mapping of OSVersionDetection codes 7, 0xA and 6 to specific CPU features (SSE2/SSE/3DNow!) is taken from existing_analysis prose and is not grounded in the packet.
    // UNRESOLVED: The Data parameter is reused as an output buffer for the registry read, so its post-call value is not the original caller argument.
    // UNRESOLVED: The identity of the function table stored at off_5D77C8 and the meaning of each variant state 1/2/3 are not evidenced in the packet.
}
