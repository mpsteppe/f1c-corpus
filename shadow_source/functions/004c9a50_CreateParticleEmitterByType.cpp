// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C9A50
// Canonical corpus name: MemoryAllocation_9a50
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MemoryAllocation_9a50_004c9a50.c

void UnknownObject::CreateParticleEmitterByType()
{
    // Factory that allocates and initializes a particle emitter object selected by an integer type id passed in the this parameter. Types 1, 2, 5, 6 and 7 each allocate a distinct heap block (44, 40, 28, 36, 32 bytes), initialize it through ParticleEmitterInit with a per-type lifetime parameter, install a type-specific virtual table pointer, and return the emitter. Types 3 and 4 and the default case return null; every allocation is null-checked and returns null on failure. Called by NetworkMessageReceiveAndDispatch.
    // ASSIGNMENT: Initialize the result pointer to null before dispatch. [source:raw]
    // GUARD: Switch on the unsigned integer type id carried in this; the jump table global jpt_4C9A5C dispatches cases 1, 2, 5, 6 and 7 to distinct constructions, cases 3 and 4 fall through to the null result, and the default returns the pre-initialized null result directly. [global:0x004C9AF4, source:raw, function:0x004C9A50]
    // CALL: Type 1: allocate a 44-byte heap block via OperatorNewNhMallocWrapper; guard on the allocation result, returning null if it failed. [callee:0x00587C03, source:raw]
    // CALL: Type 1: initialize the emitter through ParticleEmitterInit with lifetime parameter 1.0. [callee:0x004C8F10, source:raw]
    // ASSIGNMENT: Type 1: install the type-1 virtual table pointer (off_5ACE3C in the raw source, not in the fact table) and zero the dword fields at indices 7, 8, 9 and 10; return the emitter. [source:raw]
    // CALL: Type 2: allocate a 40-byte heap block via OperatorNewNhMallocWrapper; guard on the allocation result, returning null if it failed. [callee:0x00587C03, source:raw]
    // CALL: Type 2: initialize the emitter through ParticleEmitterInit with lifetime parameter 1.0. [callee:0x004C8F10, source:raw]
    // ASSIGNMENT: Type 2: install the type-2 virtual table pointer (off_5ACE4C in the raw source, not in the fact table) and zero the dword fields at indices 7, 8 and 9; return the emitter. [source:raw]
    // RETURN: Types 3 and 4 share the null-return path: they perform no allocation and fall through to the initialized null result. [source:raw]
    // CALL: Type 5: allocate a 28-byte heap block via OperatorNewNhMallocWrapper; guard on the allocation result, returning null if it failed. [callee:0x00587C03, source:raw]
    // CALL: Type 5: initialize the emitter through ParticleEmitterInit with lifetime parameter 0.050000001. [callee:0x004C8F10, source:raw]
    // ASSIGNMENT: Type 5: install the virtual table pointer from global off_5ACE7C and return the emitter. [global:0x005ACE7C, source:raw]
    // ASSIGNMENT: Type 5: the lifetime parameter is linked by existing DERIVED analysis to global flt_5ACE18 (ObjectFactoryParamType5); the raw source only shows the literal 0.050000001. [global:0x005ACE18, source:raw]
    // CALL: Type 6: allocate a 36-byte heap block via OperatorNewNhMallocWrapper; guard on the allocation result, returning null if it failed. [callee:0x00587C03, source:raw]
    // CALL: Type 6: initialize the emitter through ParticleEmitterInit with lifetime parameter 5.0. [callee:0x004C8F10, source:raw]
    // ASSIGNMENT: Type 6: install the type-6 virtual table pointer (off_5ACE5C in the raw source, not in the fact table). [source:raw]
    // CALL: Type 6: call RandLCGRandomNumberGenerator (raw source name; not present in the packet callee table) to seed the random state, then zero the float fields at indices 7 and 8 and return the emitter. [source:raw]
    // CALL: Type 7: allocate a 32-byte heap block via OperatorNewNhMallocWrapper; guard on the allocation result, returning null if it failed. [callee:0x00587C03, source:raw]
    // CALL: Type 7: initialize the emitter through ParticleEmitterInit with lifetime parameter 1.7014117e38 (maximum single-precision float). [callee:0x004C8F10, source:raw]
    // ASSIGNMENT: Type 7: install the virtual table pointer from global off_5ACE6C, zero the float field at index 7, and return the emitter. [global:0x005ACE6C, source:raw]
    // RETURN: Return the constructed emitter pointer, or null on allocation failure or an unsupported type id; the result is consumed by the caller NetworkMessageReceiveAndDispatch. [caller:0x004C7CA0, source:raw]

    // Conservative worker pseudocode:
    //   float *CreateParticleEmitterByType(unsigned type) {
    //     void *p;
    //     switch (type) {
    //     case 1: p = OperatorNewNhMallocWrapper(44); if (!p) return 0; ParticleEmitterInit(p, 1.0); p[0] = vtbl1; p[7] = p[8] = p[9] = p[10] = 0; return p;
    //     case 2: p = OperatorNewNhMallocWrapper(40); if (!p) return 0; ParticleEmitterInit(p, 1.0); p[0] = vtbl2; p[7] = p[8] = p[9] = 0; return p;
    //     case 3: case 4: return 0;
    //     case 5: p = OperatorNewNhMallocWrapper(28); if (!p) return 0; ParticleEmitterInit(p, 0.050000001); p[0] = vtbl5; return p;
    //     case 6: p = OperatorNewNhMallocWrapper(36); if (!p) return 0; ParticleEmitterInit(p, 5.0); p[0] = vtbl6; RandLCGRandomNumberGenerator(); p[7] = 0.0; p[8] = 0.0; return p;
    //     case 7: p = OperatorNewNhMallocWrapper(32); if (!p) return 0; ParticleEmitterInit(p, 1.7014117e38); p[0] = vtbl7; p[7] = 0.0; return p;
    //     default: return 0;
    //     }
    //   }
    // UNRESOLVED: RandLCGRandomNumberGenerator appears in the raw source but has no packet callee entry; the seeding side effect (state write vs. state read) is unresolved.
    // UNRESOLVED: Exact emitter class identities behind the per-type virtual table pointers are unresolved; only the type-5 (off_5ACE7C) and type-7 (off_5ACE6C) vtable globals are named in the fact table.
    // UNRESOLVED: Linkage of global flt_5ACE18 to the type-5 lifetime parameter is DERIVED from existing analysis only, not proven from the raw source.
    // UNRESOLVED: The this parameter doubles as the type selector; the ABI label (Memory_Allocation_Particle_Emitter_Factory, LEGACY) suggests a factory but the owning class is unknown.
    // UNRESOLVED: Types 3 and 4 return null with no allocation, which may be placeholder ids or handled by another path.
}
