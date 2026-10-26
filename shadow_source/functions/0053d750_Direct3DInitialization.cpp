// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053D750
// Canonical corpus name: sub_53D750
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_53D750_0053d750.c

void UnknownObject::Direct3DInitialization()
{
    // Initializes the Direct3D8 rendering context: releases any existing D3D and device interfaces held at this+0x10FC/this+0x1100, creates a new D3D8 object via Direct3DCreate8(220), selects a render-mode flag from the config value at this+0x13E0, runs the setup helper sub_540760, zeros the render-state fields, and returns 0. On allocation failure it reports the error string aErrorCreatingD through sub_53C590 and returns -1.
    // GUARD: Guard: existing D3D interface pointer *(this+0x10FC) must be released before re-initialization. [field:this:0x000010FC, source:raw]
    // GUARD: Guard: existing device interface pointer *(this+0x1100) is also released when present. [field:this:0x00001100, source:raw]
    // CALL: Call vfunc+8 on the old device interface at *(this+0x1100) and store its result into this+0 (device/render handle); then clear *(this+0x1100)=0. [field:*(this+0x1100):0x00000008, field:this:0x00000000, field:this:0x00001100, source:raw]
    // ASSIGNMENT: Zero the 0x34-byte device state block starting at this+0x1104 (memset on the dword region this[1089..]) after releasing the device. [field:this:0x00001100, source:raw]
    // CALL: Call vfunc+8 on the old D3D interface at *(this+0x10FC) and store its result into this+0; then clear *(this+0x10FC)=0. [field:*(this+0x10FC):0x00000008, field:this:0x00000000, field:this:0x000010FC, source:raw]
    // ASSIGNMENT: Reset render-state fields: *(this+0x8)=0, *(this+0x4)=0, *(this+0x1138)=0. [field:this:0x00000008, field:this:0x00000004, field:this:0x00001138, source:raw]
    // CALL: Direct3DCreate8(220) creates the D3D8 object with SDK version 220 and stores it at *(this+0x10FC). [callee:0x0059B250, field:this:0x000010FC, source:raw]
    // GUARD: Guard: proceed with configuration only when the D3D8 object was created successfully. [source:raw]
    // CALCULATION: Render-mode selection from config *(this+0x13E0): when zero set flag *(this+0x13DC)=0; when value is 1 or 2 set flag *(this+0x13DC)=1. [field:this:0x000013E0, field:this:0x000013DC, source:raw]
    // CALL: sub_540760(this) performs the further rendering-setup step on the newly created D3D context. [callee:0x00540760, source:raw]
    // ASSIGNMENT: Zero the render-state block after setup: *(this+0x13E8)=0, *(this+0x13EC)=0, *(this+0x13F0)=0, *(this+0x13F4)=0, *(this+0x13F8)=0, *(this+0x13FC)=0, *(this+0x1400)=0, *(this+0x1404)=0, *(this+0x14F0)=0, *(this+0x1518)=0, *(this+0x1580)=0. [field:this:0x000013E8, field:this:0x000013EC, field:this:0x000013F0, field:this:0x000013F4, field:this:0x000013F8, field:this:0x000013FC, field:this:0x00001400, field:this:0x00001404, field:this:0x000014F0, field:this:0x00001518, field:this:0x00001580, source:raw]
    // RETURN: Return 0 on successful initialization. [source:raw]
    // CALL: On D3D8 creation failure: sub_53C590(-1, aErrorCreatingD) reports the error using the error string global. [callee:0x0053C590, global:0x005DBC30, source:raw]
    // RETURN: Return -1 on failure. [source:raw]

    // Conservative worker pseudocode:
    //   int Direct3DInitialization(D3DRenderer* this) {
    //     if (this[0x10FC/4]) {
    //       if (this[0x1100/4]) {
    //         this[0] = vtable_call(this[0x1100/4], 0x8);
    //         this[0x1100/4] = 0;
    //         memset(this + 0x1104/4, 0, 0x34);
    //       }
    //       this[0] = vtable_call(this[0x10FC/4], 0x8);
    //       this[0x10FC/4] = 0;
    //     }
    //     this[2] = 0; this[1] = 0; this[0x1138/4] = 0;
    //     this[0x10FC/4] = Direct3DCreate8(220);
    //     if (this[0x10FC/4]) {
    //       int mode = this[0x13E0/4];
    //       if (mode) { if ((unsigned)(mode - 1) <= 1) this[0x13DC/4] = 1; }
    //       else this[0x13DC/4] = 0;
    //       sub_540760(this);
    //       this[0x14F0/4] = 0;
    //       this[0x13E8/4] = 0; this[0x13EC/4] = 0; this[0x13F0/4] = 0;
    //       this[0x13F4/4] = 0; this[0x13F8/4] = 0; this[0x13FC/4] = 0;
    //       this[0x1400/4] = 0; this[0x1404/4] = 0;
    //       this[0x1518/4] = 0; this[0x1580/4] = 0;
    //       return 0;
    //     }
    //     sub_53C590(-1, aErrorCreatingD);
    //     return -1;
    //   }
    // UNRESOLVED: Object identity of this (D3D8 renderer/system) is unknown; owner left UNKNOWN.
    // UNRESOLVED: Meaning of the render-mode flag at this+0x13DC and the vfunc+8 return value stored at this+0 is inferred from call shape only.
    // UNRESOLVED: The exact render-state semantics of the many zeroed fields are not established by this function alone.
}
