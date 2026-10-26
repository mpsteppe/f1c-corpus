// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044FA60
// Canonical corpus name: DirectXDeviceInitialization
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DirectXDeviceInitialization_0044fa60.c

void UnknownObject::DirectXDeviceInitialization()
{
    // Creates and configures a Direct3D-style rendering device for the input/HW module. Seeds two constant arrays with an 8-iteration loop, optionally re-enumerates the device through the ppvOut interface when the capability/version field at offset 0x2F4 differs from 20, creates the device (pointer stored at offset 0x80), releases a temporary interface handle, configures the device through vtable slots (offset 0xC parameter block, 0x18/0x1C/0x20/0x2C/0x34 methods), and finishes by calling D3DTextureStage. Called from HWInput_Setup (0x00455C60).
    // LOOP: Repeat 8 times: write 1028443341 into this[8+i] and 1065353216 into this[190+i], advancing the destination pointer each iteration. [source:raw]
    // ASSIGNMENT: Set dword_7CB310 to 0 inside the capability-version guard body. [guard:0, global:0x007CB310]
    // GUARD: If this[189] (field offset 0x2F4) != 20, call the ppvOut interface method at vtable offset 16 with (ppvOut, 4, sub_44ED10, 20, 1); return -1 if that call succeeds with a failure result or if the field still differs from 20. [guard:0, field:this:0x000002F4, global:0x007CA590, global:0x0044ED10, source:raw]
    // CALL: Call the ppvOut interface method at vtable offset 12 with (ppvOut, this + 34 dwords, &v11, 0); return -1 if it fails. [global:0x007CA590, source:raw]
    // ASSIGNMENT: Clear the device pointer field this[32] (offset 0x80) to 0 before creating the device. [field:this:0x00000080]
    // CALL: Call the interface obtained from v11 (its vtable slot 0) with (&unk_5AD490, this + 32); return -1 if it fails. On success the device pointer is stored into this[32] (offset 0x80). [global:0x005AD490, field:this:0x00000080, source:raw]
    // GUARD: If this[32] (device pointer at offset 0x80) is still zero after the create call, return -1. [field:this:0x00000080]
    // CALL: Release the temporary v11 interface through its vtable method at offset 8. [source:raw]
    // CALL: Call the new device's vtable method at offset 32 (field 0x20 of *(*(this+0x80)+0x0)) with the device pointer. [field:*(this+0x80):0x00000000, field:*(*(this+0x80)+0x0):0x00000020]
    // CALL: Call the device vtable method at offset 44 (field 0x2C of *(*(this+0x80)+0x0)) with (&unk_5B108C); return -1 on failure. [field:*(this+0x80):0x00000000, field:*(*(this+0x80)+0x0):0x0000002C, global:0x005B108C]
    // CALL: Call the device vtable method at offset 52 (field 0x34 of *(*(this+0x80)+0x0)) with (a2, 9); return -1 on failure. [field:*(this+0x80):0x00000000, field:*(*(this+0x80)+0x0):0x00000034]
    // ASSIGNMENT: Set this[178] (offset 0x2C8) to 44 before the offset 12 device method call. [field:this:0x000002C8]
    // CALL: Call the device vtable method at offset 12 (field 0xC of *(*(this+0x80)+0x0)) with (device, this + 178 / offset 0x2C8); return -1 on failure. [field:*(this+0x80):0x00000000, field:*(*(this+0x80)+0x0):0x0000000C, field:this:0x000002C8]
    // ASSIGNMENT: Fill the v12 parameter block: v12[0]=20, v12[1]=16, and zero the remaining 12 bytes. [source:raw]
    // CALL: Call the device vtable method at offset 24 (field 0x18 of *(*(this+0x80)+0x0)) with (device, 5, v12). [field:*(this+0x80):0x00000000, field:*(*(this+0x80)+0x0):0x00000018]
    // CALL: Call the device vtable method at offset 28 (field 0x1C of *(*(this+0x80)+0x0)) with the device pointer. [field:*(this+0x80):0x00000000, field:*(*(this+0x80)+0x0):0x0000001C]
    // RETURN: Return the result of D3DTextureStage((int)this); every earlier failure path returns -1. [callee:0x0044F8F0, caller:0x00455C60, source:raw]

    // Conservative worker pseudocode:
    //   for (i = 0; i < 8; ++i) { this[8 + i] = 1028443341; this[190 + i] = 1065353216; }
    //   if (this[189] != 20) {
    //       dword_7CB310 = 0;
    //       if (ppvOut->method16(ppvOut, 4, sub_44ED10, 20, 1) || this[189] != 20) return -1;
    //   }
    //   if (ppvOut->method12(ppvOut, &this[34], &v11, 0)) return -1;
    //   this[32] = 0;
    //   if (v11->method0(&unk_5AD490, &this[32])) return -1;
    //   if (!this[32]) return -1;
    //   v11->method8();
    //   device->method32();
    //   if (device->method44(&unk_5B108C)) return -1;
    //   if (device->method52(a2, 9)) return -1;
    //   this[178] = 44;
    //   if (device->method12(&this[178])) return -1;
    //   v12[0] = 20; v12[1] = 16; memset(&v12[2], 0, 12);
    //   device->method24(5, v12);
    //   device->method28();
    //   return D3DTextureStage((int)this);
    // UNRESOLVED: The interface obtained from ppvOut (global 0x007CA590) and the device stored at this+0x80 are only exercised through vtable slots; the exact Direct3D/DirectDraw interface identities are not established by the packet.
    // UNRESOLVED: The 8-iteration loop writes this[8..15] and this[190..197], offsets absent from the packet field table; the literal constants 1028443341 and 1065353216 are kept in packet spelling.
    // UNRESOLVED: The vtable slots invoked through ppvOut and v11 (offsets 0, 8, 12, 16) have no packet field evidence refs and are described only from source:raw.
}
