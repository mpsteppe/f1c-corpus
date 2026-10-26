// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00585400
// Canonical corpus name: VTableDispatchWithConditionalBranch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VTableDispatchWithConditionalBranch_00585400.c

void UnknownObject::DispatchBitmapOrVTable()
{
    // Conditional dispatcher: when a bitmap-range occupancy test on a2 succeeds, appends via sub_584DD0(this, a2); otherwise it dispatches through vtable slot 44 (obj+0x2C), runs sub_584230(this, a2), then dispatches through vtable slot 92 (obj+0x5C). Always returns 1.
    // CALL: Evaluate the occupancy guard: BitmapRangeOccupancyTestViaBitOps(a2). [callee:0x00586D00]
    // CALL: Occupied path: append via sub_584DD0(this, a2). [callee:0x00584DD0]
    // CALL: Free path: dispatch through vtable slot 44 at obj+0x2C with (this, a2). [field:obj:0x0000002C]
    // CALL: Free path: process via sub_584230(this, a2). [callee:0x00584230]
    // CALL: Free path: dispatch through vtable slot 92 at obj+0x5C with (this, a2). [field:obj:0x0000005C]
    // ASSIGNMENT: Read the vtable pointer from this+0 to resolve the dispatched slot functions. [field:this:0x00000000]
    // RETURN: Return the constant success value 1 on both paths. [source:raw]

    // Conservative worker pseudocode:
    //   char DispatchBitmapOrVTable(int *this, unsigned *a2) {
    //     if (BitmapRangeOccupancyTestViaBitOps(a2)) {
    //       sub_584DD0(this, a2);
    //     } else {
    //       (*(void (__thiscall **)(int*, unsigned*))(*this + 44))(this, a2);
    //       sub_584230(this, a2);
    //       (*(void (__thiscall **)(int*, unsigned*))(*this + 92))(this, a2);
    //     }
    //     return 1;
    //   }
    // UNRESOLVED: The purpose of the bitmap occupancy test and the identities of the two dispatched vtable slots are caller-dependent and unproven.
    // UNRESOLVED: What sub_584DD0 (list append) versus the vtable dispatch pair represents semantically (buffer tracking, resource registration) is not established by the packet.
}
