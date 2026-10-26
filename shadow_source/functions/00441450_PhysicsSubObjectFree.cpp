// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00441450
// Canonical corpus name: PhysicsSubObjectFree
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PhysicsSubObjectFree_00441450.c

void UnknownObject::PhysicsSubObjectFree()
{
    // Copies suspension datasets into the physics engine via SuspensionDataCopyToPhysicsEngine. First two copies use wheel 0 and wheel 1 suspension pointers; remaining two copies branch on a shared suspension ID selector at this[1287] — when set, both share that ID as source, otherwise each wheel uses its own suspension pointer (this[813], this[1094]). Returns the result of the final copy.
    // CALL: Copy first suspension dataset: SuspensionDataCopyToPhysicsEngine(dest=this+163, source=this[251]). [callee:0x004389B0, field:this:0x000003EC, source:raw]
    // CALL: Copy second suspension dataset: SuspensionDataCopyToPhysicsEngine(dest=this+444, source=this[532]). [callee:0x004389B0, field:this:0x00000850, source:raw]
    // GUARD: Branch on shared suspension selector this[1287]: non-zero selects the shared suspension ID for the remaining wheel copies; zero selects per-wheel suspension IDs. [field:this:0x0000141C, source:raw]
    // CALL: Shared-ID path: SuspensionDataCopyToPhysicsEngine(dest=this+725, source=this[1287]). [callee:0x004389B0, field:this:0x0000141C, source:raw]
    // RETURN: Shared-ID path: SuspensionDataCopyToPhysicsEngine(dest=this+1006, source=this[1287]) and return its result. [callee:0x004389B0, field:this:0x0000141C, source:raw]
    // CALL: Per-wheel path: SuspensionDataCopyToPhysicsEngine(dest=this+725, source=this[813]). [callee:0x004389B0, field:this:0x00000CB4, source:raw]
    // RETURN: Per-wheel path: SuspensionDataCopyToPhysicsEngine(dest=this+1006, source=this[1094]) and return its result. [callee:0x004389B0, field:this:0x00001118, source:raw]

    // Conservative worker pseudocode:
    //   SuspensionDataCopyToPhysicsEngine(dest=this+163, src=this[251]);
    //   SuspensionDataCopyToPhysicsEngine(dest=this+444, src=this[532]);
    //   if (this[1287]) {
    //     SuspensionDataCopyToPhysicsEngine(dest=this+725, src=this[1287]);
    //     return SuspensionDataCopyToPhysicsEngine(dest=this+1006, src=this[1287]);
    //   } else {
    //     SuspensionDataCopyToPhysicsEngine(dest=this+725, src=this[813]);
    //     return SuspensionDataCopyToPhysicsEngine(dest=this+1006, src=this[1094]);
    //   }
    // UNRESOLVED: Destination offsets (this+163, this+444, this+725, this+1006) are int-element addresses derived from the raw source only; they have no separate field evidence refs and their struct roles are unproven.
    // UNRESOLVED: Source values this[251], this[532], this[1287], this[813], this[1094] are suspension data pointers per existing analysis, but that interpretation is DERIVED prose, not packet evidence.
}
