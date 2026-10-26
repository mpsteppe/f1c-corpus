// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055CC20
// Canonical corpus name: sub_55CC20
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_55CC20_0055cc20.c

void UnknownObject::ConfigUpdateFromSourceStruct()
{
    // Applies camera/projection configuration read from source struct a2 into the config object this. Calls sub_55CA90(this, *(a2+412), 0) as a preliminary step, packs a six-dword config array v12 from a2 fields (a2+84, a2+88, a2+100, a2+104) plus constants 0 and 1.0 (1065353216), and hands it to vtable entry +160 (field *(this+0x1100)+0xA0), storing the result in *this. Then, based on bit 0x10 at a2+128, sets the mode flag this+0x13A4 to 3 or 2 and invokes vtable entry +200 (field 0xC8) with (22, mode), unless the mode already matches. Clears bit 2 of this+0x1174 (&= ~4). If the enable flag this+0x13D4 is non-zero, performs chained buffer queries through vtable entry +152 (field 0x98) with ids 256, 3, 2, copies results between 64-byte buffers, invokes ThunkToFUN0050cba3 twice and ThunkViaGlobalFunctionPointer, then applies via vtable entry +316 (field 0x13C) with (0, v13, 4), storing the final result in *this.
    // CALL: Preliminary call sub_55CA90(this, *(a2+412), 0) before packing the configuration. [callee:0x0055CA90, function:0x0055CC20, source:raw]
    // CALCULATION: Pack the six-dword configuration array v12 from source fields a2+84, a2+88, a2+100, a2+104 with v12[4] = 0 and v12[5] = 1065353216 (1.0). [function:0x0055CC20, source:raw]
    // CALL: Invoke vtable entry +160 on the sub-struct *(this+0x1100) (field 0xA0) with the packed config array v12; store the returned value in *this. [field:*(this+0x1100):0x000000A0, field:this:0x00001100, field:this:0x00000000, function:0x0055CC20, source:raw]
    // GUARD: Test bit 0x10 at a2+128 to select which mode value to apply (3 when set, 2 otherwise). [function:0x0055CC20, source:raw]
    // STATE_TRANSITION: Set the mode flag this+0x13A4 to 3 or 2 according to the a2+128 bit, skipping the vtable call when the current mode already matches. [field:this:0x000013A4, function:0x0055CC20, source:raw]
    // CALL: Invoke vtable entry +200 on *(this+0x1100) (field 0xC8) with arguments (22, mode) where mode is 3 or 2, and store the result in *this. [field:*(this+0x1100):0x000000C8, field:this:0x00001100, field:this:0x00000000, function:0x0055CC20, source:raw]
    // ASSIGNMENT: Clear bit 2 of the bitfield this+0x1174 (&= ~4). [field:this:0x00001174, function:0x0055CC20, source:raw]
    // GUARD: Read the enable flag this+0x13D4; when non-zero, run the chained buffer-query apply block. [field:this:0x000013D4, function:0x0055CC20, source:raw]
    // CALL: Query buffers through vtable entry +152 on *(this+0x1100) (field 0x98) with ids 256, 3 and 2 into v17, v19 and v14 respectively. [field:*(this+0x1100):0x00000098, field:this:0x00001100, function:0x0055CC20, source:raw]
    // ASSIGNMENT: Copy the query results between 64-byte buffers: qmemcpy(v16, v17), qmemcpy(v18, v19), qmemcpy(v15, v14). [function:0x0055CC20, source:raw]
    // CALL: Chained thunk processing: ThunkToFUN0050cba3 invoked twice, followed by ThunkViaGlobalFunctionPointer. [callee:0x0050CBB0, callee:0x0050CDF9, function:0x0055CC20, source:raw]
    // CALL: Final apply through vtable entry +316 on *(this+0x1100) (field 0x13C) with arguments (0, v13, 4), and store the result in *this. [field:*(this+0x1100):0x0000013C, field:this:0x00001100, field:this:0x00000000, function:0x0055CC20, source:raw]
    // RETURN: Return result (the enable flag value, or the last vtable call result when the block ran). [function:0x0055CC20, source:raw]

    // Conservative worker pseudocode:
    //   sub_55CA90(this, *(DWORD**)(a2 + 412), 0);
    //   v12[0] = *(a2+104); v12[1] = *(a2+100); v12[2] = *(a2+84);
    //   v12[3] = *(a2+88); v12[4] = 0; v12[5] = 1065353216;
    //   *this = vtable[*(this+0x1100)][+160](*(this+0x1100), v12);   // field 0xA0
    //   mode = this->modeFlag;  // this+0x13A4
    //   if (a2[128] & 0x10) {
    //       if (mode == 3) goto done;
    //       this->modeFlag = 3;
    //       *this = vtable[*(this+0x1100)][+200](*(this+0x1100), 22, 3);  // field 0xC8
    //   } else {
    //       if (mode == 2) goto done;
    //       this->modeFlag = 2;
    //       *this = vtable[*(this+0x1100)][+200](*(this+0x1100), 22, 2);
    //   }
    //   this->bitfield &= ~4u;   // this+0x1174, clear bit 2
    //   done:
    //   if (this->enableFlag) {  // this+0x13D4
    //       *this = vtable[*(this+0x1100)][+152](*(this+0x1100), 256, v17);  // field 0x98
    //       *this = vtable[*(this+0x1100)][+152](*(this+0x1100), 3, v19);
    //       *this = vtable[*(this+0x1100)][+152](*(this+0x1100), 2, v14);
    //       qmemcpy(v16, v17, 64); qmemcpy(v18, v19, 64); qmemcpy(v15, v14, 64);
    //       ThunkToFUN0050cba3(); ThunkToFUN0050cba3(); ThunkViaGlobalFunctionPointer();
    //       *this = vtable[*(this+0x1100)][+316](*(this+0x1100), 0, v13, 4);  // field 0x13C
    //   }
    //   return result;
    // UNRESOLVED: The vtable entries are identified by call-site offset only (fields 0x98/0xA0/0xC8/0x13C on *(this+0x1100)); the concrete class of this and of the vtable provider is unidentified.
    // UNRESOLVED: The meaning of the three thunk calls (ThunkToFUN0050cba3 x2, ThunkViaGlobalFunctionPointer) and the exact semantics of the buffer ids (256, 3, 2) are not established.
}
