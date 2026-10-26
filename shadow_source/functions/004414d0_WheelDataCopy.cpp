// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004414D0
// Canonical corpus name: WheelDataCopy
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/WheelDataCopy_004414d0.c

void UnknownObject::WheelDataCopy()
{
    // Advances wheel state history: copies the history header fields forward (current slots take the previous-slot values), rotates the per-wheel state history slots, and copies per-wheel delta buffers from the previous-state buffer into the current-state buffer. Then dispatches the suspension wheel dynamics solver, two batch iterators, a per-body update pass, and the physics sub-object free routine.
    // ASSIGNMENT: Copy wheel-state history header forward: current slots this+0x1C64/0x1C68 take the previous values at this+0x1C5C/0x1C60, and current slots this+0x1E40/0x1E44 take the previous values at this+0x1E38/0x1E3C. [field:this:0x00001C5C, field:this:0x00001C60, field:this:0x00001C64, field:this:0x00001C68, field:this:0x00001E38, field:this:0x00001E3C, field:this:0x00001E40, field:this:0x00001E44, source:raw]
    // LOOP: Per-wheel history slot rotation: 4 iterations over wheel blocks with a 1124-byte stride. Inside each block the dword pair at +0x340/+0x344 is copied from two dwords earlier, the pair at +0x350/+0x354 is copied from +0x348/+0x34C, and a 32-byte block is copied forward within the block. [field:this:0x00000340, field:this:0x00000344, field:this:0x00000348, field:this:0x0000034C, field:this:0x00000350, field:this:0x00000354, source:raw]
    // GUARD: If the wheel-state count at this+0x15AC is greater than zero, run the per-wheel delta-state buffer copy loop. [guard:0, field:this:0x000015AC, source:raw]
    // LOOP: Per-wheel delta copy: for each wheel (count at this+0x15AC), copy 24 bytes from the previous-state buffer entry (this+0x15B0, 580-byte stride) at offsets +308 and +332 into the current-state buffer entry (this+0x162C, 48-byte stride). [field:this:0x000015AC, field:this:0x000015B0, field:this:0x0000162C, source:raw]
    // CALL: SuspensionWheelDynamicsSolver(this, a2) runs the suspension wheel dynamics solve for the vehicle object. [callee:0x0043F7F0, source:raw]
    // CALL: sub_56ECF0(&this[0x15AC]) iterates the wheel-state region at this+0x15AC. [callee:0x0056ECF0, field:this:0x000015AC, source:raw]
    // CALL: sub_56EE40(&this[0x15AC]) iterates the wheel-state region at this+0x15AC. [callee:0x0056EE40, field:this:0x000015AC, source:raw]
    // CALL: IteratePhysicsBodiesCallUpdateFunction(a2) runs the per-body update pass with the same time-step parameter. [callee:0x0056F020, source:raw]
    // RETURN: Return the result of PhysicsSubObjectFree(this). [callee:0x00441450, source:raw]
    // CALL: Invoked from the frame-path integration step VehiclePhysicsIntegrationStep (00441650). [caller:0x00441650, source:raw]

    // Conservative worker pseudocode:
    //   // header: this[0x1C64]=this[0x1C5C]; this[0x1C68]=this[0x1C60];
    //   //         this[0x1E40]=this[0x1E38]; this[0x1E44]=this[0x1E3C];
    //   // for 4 wheel blocks (1124-byte stride): rotate the +0x340/+0x350 history pairs; copy 32 bytes
    //   // if (this[0x15AC] > 0) for each wheel:
    //   //   copy 24 bytes from prev buffer (this+0x15B0, stride 580) +308 and +332 into current buffer (this+0x162C, stride 48)
    //   // SuspensionWheelDynamicsSolver(this, a2);
    //   // sub_56ECF0(&this[0x15AC]); sub_56EE40(&this[0x15AC]);
    //   // IteratePhysicsBodiesCallUpdateFunction(a2);
    //   // return PhysicsSubObjectFree(this);
    // UNRESOLVED: The two batch-iterator callees sub_56ECF0 and sub_56EE40 have no packet names or known semantics beyond taking the wheel-state region at this+0x15AC.
    // UNRESOLVED: The 580-byte previous-state stride and 48-byte current-state stride are deterministic from the raw source loop increments but the meaning of the copied 24-byte records is not confirmed.
    // UNRESOLVED: The history-header offsets this+0x1C5C/0x1C64 and this+0x1E38/0x1E40 pairs are treated as two independent history buffers based on their symmetric copy pattern; their distinct roles are DERIVED.
}
