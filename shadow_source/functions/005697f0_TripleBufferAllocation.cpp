// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005697F0
// Canonical corpus name: TripleBufferAllocation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TripleBufferAllocation_005697f0.c

void UnknownObject::TripleBufferAllocation()
{
    // Allocates three element-group buffers for the constraint/joint system. First group: 56 * this[139] bytes stored to this[140]; second group: 132 * this[141] bytes stored to this[142]; third group: 88 * this[143] bytes stored to this[144]. Each element-count field is reset to 0 immediately after its buffer is allocated.
    // CALL: Allocate 56 * this[139] bytes via OperatorNewNhMallocWrapper and store the returned pointer in this[140] (field this+0x230). [callee:0x00587C03, field:this:0x00000230, source:raw]
    // ASSIGNMENT: Reset first-group element count this[139] (field this+0x22C) to 0. [field:this:0x0000022C, source:raw]
    // CALCULATION: Compute second allocation size 132 * this[141] (field this+0x234) into local v6. [field:this:0x00000234, source:raw]
    // CALL: Allocate v6 bytes via OperatorNewNhMallocWrapper and store the returned pointer in this[142] (field this+0x238). [callee:0x00587C03, field:this:0x00000238, source:raw]
    // ASSIGNMENT: Reset second-group element count this[141] (field this+0x234) to 0. [field:this:0x00000234, source:raw]
    // CALCULATION: Compute third allocation size 88 * this[143] (field this+0x23C) into local v5. [field:this:0x0000023C, source:raw]
    // CALL: Allocate v5 bytes via OperatorNewNhMallocWrapper, store the returned pointer in this[144] (field this+0x240), and keep it as the return value. [callee:0x00587C03, field:this:0x00000240, source:raw]
    // ASSIGNMENT: Reset third-group element count this[143] (field this+0x23C) to 0. [field:this:0x0000023C, source:raw]
    // RETURN: Return the third buffer pointer (result of the last allocation). [source:raw]

    // Conservative worker pseudocode:
    //   this[140] = OperatorNewNhMallocWrapper(56 * this[139]); this[139] = 0;
    //   this[142] = OperatorNewNhMallocWrapper(132 * this[141]); this[141] = 0;
    //   result = OperatorNewNhMallocWrapper(88 * this[143]); this[144] = result; this[143] = 0; return result;
    // UNRESOLVED: Caller VehiclePhysicsJointSystemLoader (0x0056D930) is contextual only; no owning class is evidenced for the this object.
}
