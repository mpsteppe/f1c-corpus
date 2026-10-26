// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050AF57
// Canonical corpus name: InputDeviceDataRead
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/InputDeviceDataRead_0050af57.c

void UnknownObject::InputDeviceDataRead()
{
    // Reads a texture/surface region into a caller buffer. Calls sub_50AB51 to lock/read the surface at coordinates (this[0x1034] + a2, this[0x1040] + a3) with mode 1; on success (return >= 0) copies 16 * this[0x1058] bytes from this[0x106C] + 16 * (this[0x1030] - this[0x1070]) into a4. When the flag at 0x10 is non-zero, runs ContactManifoldCleanup over the copied buffer.
    // CALL: Call sub_50AB51(this, this[0x1034] + a2, this[0x1040] + a3, 1) to acquire a surface region: the x coordinate is the offset-0x1034 field plus a2, the y coordinate is the offset-0x1040 field plus a3, with a constant argument of 1. [callee:0x0050AB51, field:this:0x00001034, field:this:0x00001040, source:raw]
    // GUARD: Guard on sub_50AB51 returning >= 0 (success); the copy and post-process steps run only when the call succeeds. [source:raw, callee:0x0050AB51]
    // CALCULATION: Compute the copy source address = this[0x106C] + 16 * (this[0x1030] - this[0x1070]) and the copy size = 16 * this[0x1058] bytes (16 bytes per unit times the count at offset 0x1058). [source:raw, field:this:0x0000106C, field:this:0x00001030, field:this:0x00001070, field:this:0x00001058]
    // ASSIGNMENT: qmemcpy a4 from the computed source region: 16 * this[0x1058] bytes copied into the caller-provided buffer a4. [source:raw]
    // GUARD: Guard on this[4] (flag at offset 0x10): if non-zero, run the post-process step over the copied buffer a4. [source:raw, field:this:0x00000010]
    // CALL: Call ContactManifoldCleanup(this, a4) as the conditional post-process over the copied buffer. [callee:0x00507845, source:raw]

    // Conservative worker pseudocode:
    //   void ReadSurfaceData(DWORD* this, int a2, int a3, void* a4) {
    //     if (sub_50AB51((int)this, this[1037] + a2, this[1040] + a3, 1) >= 0) {
    //       qmemcpy(a4, (void*)(this[1051] + 16 * (this[1036] - this[1052])), 16 * this[1046]);
    //       if (this[4]) ContactManifoldCleanup((int)this, (unsigned int)a4);
    //     }
    //   }
    // UNRESOLVED: sub_50AB51 semantics (surface lock vs read) are a DERIVED inference; the constant argument of 1 is uninterpreted.
    // UNRESOLVED: The relationship between the offset-0x1030 field (this[1036]) and offset-0x1070 field (this[1052]) - cursor position minus start offset - is inferred from the pointer arithmetic, not externally established.
    // UNRESOLVED: ContactManifoldCleanup post-process semantics (what the flag at 0x10 selects) are not established here.
    // UNRESOLVED: The copy treats the source as a run of 16-byte rows; whether this[0x1058] is a row count or byte quantity is not independently verified.
}
