// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DFBB0
// Canonical corpus name: sub_4DFBB0
// Owner: TirePhysicsComponent [DERIVED]
// Raw source: functions/sub_4DFBB0_004dfbb0.c

void TirePhysicsComponent::Init()
{
    // Constructor-style initializer (thiscall, returns this) for a tire-physics component. Called by PhysicsTireSystemConstructor (0x004E4500) to build the component tail of the tire system. Zero-initializes the head record after this+0x4, sets a counter field at +0x90 to 0 and a sentinel at +0x94 to -1, then runs four aggregate blocks: four repeated per-tire sub-records (74-dword stride) each zeroed via LargeZeroInit/zero-loop helpers and given a dual-call init; a 1396-byte base record and two more zero-loop blocks; eight repeated 68-byte records zero-initialized; a chain of 28-byte records each passed to sub_4DFB90 until that helper returns 1; and eleven repeated 187-dword records each passed to F_2FieldInitCall. Finally clears the root dword, two trailing dwords at +0xBA8/+0x2BD4, and calls VehicleResetClear on the whole object before returning this.
    // CALL: Zero-initialize the tail of the component's head record at this+4 via F_17ElementZeroInitLoop. [callee:0x004DFA50, source:raw]
    // ASSIGNMENT: Write 0 to the counter field at this+0x90. [field:this:0x00000090, source:raw]
    // ASSIGNMENT: Write -1 to the sentinel field at this+0x94. [field:this:0x00000094, source:raw]
    // LOOP: Loop four times over per-tire sub-records starting at this+212 (74-dword stride), calling LargeZeroInit, two F_17ElementZeroInitLoop passes, and InitWithDualCall on each record. [callee:0x004DFB00, callee:0x004DFA50, callee:0x004DFB60, source:raw]
    // CALL: Zero-initialize the base record at this+1396 via LargeZeroInit. [callee:0x004DFB00, source:raw]
    // CALL: Zero-initialize the records at this+1508 and this+1576 via F_17ElementZeroInitLoop. [callee:0x004DFA50, source:raw]
    // LOOP: Loop eight times over 68-byte records starting at this+1644, zero-initializing each via F_17ElementZeroInitLoop. [callee:0x004DFA50, source:raw]
    // LOOP: Walk 28-byte records starting at this+2448, calling sub_4DFB90 on each and advancing until that helper returns 1. [callee:0x004DFB90, source:raw]
    // LOOP: Loop eleven times over 187-dword records starting at this+2988, calling F_2FieldInitCall on each. [callee:0x004DE5F0, source:raw]
    // ASSIGNMENT: Write 0 to the root dword at this+0x0. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Write 0 to the field at this+0xBA8. [field:this:0x00000BA8, source:raw]
    // ASSIGNMENT: Write 0 to the field at this+0x2BD4. [field:this:0x00002BD4, source:raw]
    // CALL: Run VehicleResetClear over the whole component to bring it to a known clean state. [callee:0x004E09E0, source:raw]
    // RETURN: Return the initialized this pointer, completing the constructor-style init. [source:raw]
    // CALL: Invoked by PhysicsTireSystemConstructor (0x004E4500) as part of tire-system construction. [caller:0x004E4500, source:raw]

    // Conservative worker pseudocode:
    //   void* Init(void* this) {
    //     F_17ElementZeroInitLoop(this + 4);
    //     *(int*)(this + 0x90) = 0;
    //     *(int*)(this + 0x94) = -1;
    //     for (i = 0; i < 4; i++) {
    //       rec = this + 212 + i * 296;
    //       LargeZeroInit(rec);
    //       F_17ElementZeroInitLoop(rec + 28);
    //       F_17ElementZeroInitLoop(rec + 45);
    //       InitWithDualCall(rec);
    //     }
    //     LargeZeroInit(this + 1396);
    //     F_17ElementZeroInitLoop(this + 1508);
    //     F_17ElementZeroInitLoop(this + 1576);
    //     for (i = 0; i < 8; i++) F_17ElementZeroInitLoop(this + 1644 + i * 68);
    //     do { sub_4DFB90(this + 2448 + i * 28); } while (returnValue != 1);
    //     for (i = 0; i < 11; i++) F_2FieldInitCall(this + 2988 + i * 748);
    //     *(int*)this = 0;
    //     *(int*)(this + 0xBA8) = 0;
    //     *(int*)(this + 0x2BD4) = 0;
    //     VehicleResetClear(this);
    //     return this;
    //   }
    // UNRESOLVED: The exact role of each per-tire sub-record and of the 11 field-init records is not resolvable from this packet alone.
    // UNRESOLVED: Owner type TirePhysicsComponent is DERIVED from the caller name PhysicsTireSystemConstructor (0x004E4500); the component's own class identity is unproven.
    // UNRESOLVED: The termination condition of the sub_4DFB90 loop (return value 1) reflects the raw decompiler control flow; the meaning of that sentinel is unknown.
}
