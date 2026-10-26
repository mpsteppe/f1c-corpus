// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050F632
// Canonical corpus name: sub_50F632
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_50F632_0050f632.c

void UnknownObject::sub_50F632()
{
    // Render/camera object initializer (a1) with parameter dispatch. Clears flag at this+0x4, dispatches through the object's vtable when a2 != 61 (opcode 10, expected 61) and when a3 != 424 (opcode 19, expected 424), then zeroes the 0x1A8-byte struct while preserving and restoring the vtable pointer, sets ready byte at this+0xC to 1, calls RenderVTableObjectInit, zeroes trailing fields, calls sub_5115EE, calls DirectorCameraObjectSetup, conditionally updates global byte_5D79DC via EFLAGSRegisterCheck when it equals 2, sets count field this+0x10 to 200 and returns the last call result.
    // ASSIGNMENT: Clear error/status flag a1[1] at this+0x4 to 0 [field:this:0x00000004]
    // GUARD: If a2 != 61, perform first parameter dispatch [source:raw, field:obj:0x00000014, field:obj:0x00000018, field:obj:0x0000001C]
    // ASSIGNMENT: Write dispatch opcode 10 to obj+0x14 [field:obj:0x00000014]
    // ASSIGNMENT: Write expected value 61 to obj+0x18 [field:obj:0x00000018]
    // ASSIGNMENT: Write parameter a2 to obj+0x1C [field:obj:0x0000001C]
    // CALL: Dispatch via object vtable[0] passing a1 [field:obj:0x00000000]
    // GUARD: If a3 != 424, perform second parameter dispatch [source:raw, field:obj:0x00000014, field:obj:0x00000018, field:obj:0x0000001C]
    // ASSIGNMENT: Write dispatch opcode 19 to obj+0x14 [field:obj:0x00000014]
    // ASSIGNMENT: Write expected value 424 to obj+0x18 [field:obj:0x00000018]
    // ASSIGNMENT: Write parameter a3 to obj+0x1C [field:obj:0x0000001C]
    // CALL: Dispatch via object vtable[0] passing a1 [field:obj:0x00000000]
    // ASSIGNMENT: Save vtable pointer *a1 into a local before zeroing [field:this:0x00000000]
    // CALCULATION: Zero 0x1A8 bytes of a1 (whole struct) [source:raw]
    // ASSIGNMENT: Restore vtable pointer to a1[0] after memset [field:this:0x00000000]
    // ASSIGNMENT: Set ready/activation byte at this+0xC to 1 [field:this:0x0000000C]
    // CALL: Call RenderVTableObjectInit(a1) for render vtable initialization [callee:0x00516883]
    // ASSIGNMENT: Set a1[2] at this+0x8 to 0 [field:this:0x00000008]
    // ASSIGNMENT: Set a1[5] at this+0x14 to 0 [field:this:0x00000014]
    // ASSIGNMENT: Zero four state dwords a1[36..39] at this+0x90 through this+0x9C [field:this:0x00000090, field:this:0x00000094, field:this:0x00000098, field:this:0x0000009C]
    // LOOP: Loop 4 times zeroing two dwords per iteration immediately after the a1[36..39] state block [source:raw]
    // CALL: Call sub_5115EE(a1) [callee:0x005115EE]
    // CALL: Call DirectorCameraObjectSetup(a1); result retained [callee:0x00515ECD]
    // GUARD: If global byte_5D79DC equals 2, refresh it [global:0x005D79DC]
    // ASSIGNMENT: Set byte_5D79DC to the result of EFLAGSRegisterCheck() [callee:0x005159C3, global:0x005D79DC]
    // ASSIGNMENT: Set count/limit field a1[4] at this+0x10 to 200 [field:this:0x00000010]
    // RETURN: Return the DirectorCameraObjectSetup result (or EFLAGS result when refresh path ran) [source:raw]

    // Conservative worker pseudocode:
    //   int init_render_object(_DWORD* a1, int a2, int a3) {
    //       a1[1] = 0;
    //       if (a2 != 61) { obj->opcode = 10; obj->expected = 61; obj->param = a2; vtable_call(a1); }
    //       if (a3 != 424) { obj->opcode = 19; obj->expected = 424; obj->param = a3; vtable_call(a1); }
    //       saved = *a1;
    //       memset(a1, 0, 0x1A8);
    //       *a1 = saved;
    //       *((_BYTE*)a1 + 12) = 1;
    //       RenderVTableObjectInit(a1);
    //       a1[2] = 0; a1[5] = 0; a1[36] = a1[37] = a1[38] = a1[39] = 0;
    //       for (i = 0; i < 4; i++) { a1[40+i*2] = 0; a1[44+i*2] = 0; }
    //       sub_5115EE(a1);
    //       result = DirectorCameraObjectSetup(a1);
    //       if (byte_5D79DC == 2) byte_5D79DC = EFLAGSRegisterCheck();
    //       a1[4] = 200;
    //       return result;
    //   }
    // UNRESOLVED: Object type behind a1 is unknown; vtable opcodes 10/19 and expected values 61/424 encode an undocumented configuration protocol.
    // UNRESOLVED: Purpose of EFLAGSRegisterCheck refresh on byte_5D79DC and meaning of count 200 are unconfirmed.
    // UNRESOLVED: Only static caller is ImageTextureDecompressor (0x00501722); class identity not established.
}
