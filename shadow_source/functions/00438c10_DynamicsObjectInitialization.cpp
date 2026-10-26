// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00438C10
// Canonical corpus name: DynamicsObjectInitialization
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DynamicsObjectInitialization_00438c10.c

void UnknownObject::DynamicsObjectInitialization()
{
    // Vehicle dynamics state initializer: zeroes the 0x1F38-byte main struct, runs sub-component initializers (constructor stub, struct initializer, zero-fill sub-call, two double-array zeros), then initializes four per-wheel 6-dword state blocks at 0x464-byte stride from this+0x5D8 with an alternating state-constant/float pattern, finishing with wheel dynamics setup and returning this.
    // CALL: Call ConstructorStub on the sub-component at this + 123 dwords. [callee:0x004353F0, source:raw]
    // CALL: Call StructInitializer on the sub-struct at this + 1371 dwords. [callee:0x0042E1C0, source:raw]
    // CALL: Call StructInitWithZeroFillSubCall on the sub-struct at this + 1387 dwords. [callee:0x0056D3E0, source:raw]
    // CALL: Zero the 25-double array at this + 1550 dwords via DoubleArrayZero. [callee:0x004363D0, source:raw]
    // CALL: Zero the 25-double array at this + 1575 dwords via DoubleArrayZero. [callee:0x004363D0, source:raw]
    // ASSIGNMENT: memset the entire 0x1F38-byte struct to zero before per-wheel setup. [source:raw]
    // LOOP: do-while loop, 4 iterations (one per wheel), with the base pointer starting at this + 374 dwords (this+0x5D8) and advancing by 281 dwords each iteration. Per wheel writes six dwords: *v2 = state constant (init literal 18446744071819766006), v2[1] = 1081507266 (3.8514f), v2[2] = copy of *v2, v2[3] = copy of v2[1], v2[4] = copy of v2[2], v2[5] = copy of v2[3]. [field:this:0x000005D8, field:this:0x000005DC, field:this:0x000005E0, field:this:0x000005E4, field:this:0x000005E8, field:this:0x000005EC, source:raw]
    // CALL: Call WheelDynamicsInit(this) to finish wheel dynamics setup. [callee:0x0043E230, source:raw]
    // RETURN: Return this as the initialized object. [function:0x00438C10, source:raw]

    // Conservative worker pseudocode:
    //   void* sub_438C10(void* this) {
    //     ConstructorStub(this + 123);
    //     StructInitializer(this + 1371);
    //     StructInitWithZeroFillSubCall(this + 1387);
    //     DoubleArrayZero(this + 1550);
    //     DoubleArrayZero(this + 1575);
    //     memset(this, 0, 0x1F38);
    //     unsigned* p = (unsigned*)this + 374;
    //     int n = 4;
    //     do {
    //       p[0] = 18446744071819766006;
    //       p[1] = 1081507266;
    //       p[2] = p[0];
    //       p[3] = p[1];
    //       p[4] = p[2];
    //       p[5] = p[3];
    //       p += 281;
    //     } while (--n);
    //     WheelDynamicsInit(this);
    //     return this;
    //   }
    // UNRESOLVED: Exact semantics of the 6-dword per-wheel state block (state constant plus 3.8514f initial float and their copies) are caller-dependent.
    // UNRESOLVED: Purpose of the sub-component initializers at this+123, this+1371 and this+1387 dwords is not resolved from this function alone.
}
