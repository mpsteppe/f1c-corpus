// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004347C0
// Canonical corpus name: EngineGuardedInitializer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/EngineGuardedInitializer_004347c0.c

void UnknownObject::EngineGuardedInitializer()
{
    // Guarded one-time engine initialization guarded by a flag byte at this+0x2. If the flag is unset, initializes the engine subsystems (twice with different argument pairs), invokes a sound-system vtable method, initializes a buffer with default floats, dispatches the session phase with cascade checks using the field at this+0x8, then sets the flag. Returns the flag/result byte otherwise.
    // ASSIGNMENT: Load the guard byte at this+0x2 into result; this is the initialized flag. [field:this:0x00000002, source:raw]
    // GUARD: If the guard byte at this+0x2 is non-zero, the engine is already initialized and the body is skipped. [field:this:0x00000002]
    // CALL: First engine subsystem initialization call: sub_4D8760(-1, 0). [callee:0x004D8760, source:raw]
    // CALL: Second engine subsystem initialization call: sub_4D8760(1, 1). [callee:0x004D8760, source:raw]
    // GUARD: If the sound-system interface pointer dword_5EB10C is non-null, invoke its vtable method at offset 12. [global:0x005EB10C, source:raw]
    // CALL: Indirect thiscall through the sound-system vtable entry at offset 12, with dword_5EB10C as the this pointer. [global:0x005EB10C, source:raw]
    // CALL: Initialize the buffer at flt_5EA618 with default float values via BufferInitWith10fDefaults. [callee:0x004186A0, global:0x005EA618]
    // CALL: Dispatch the session phase with cascade checks: SessionPhaseDispatchWithCascadeChecks(&dword_5EA510, *(int*)(this+0x8), 1). [callee:0x0040D1B0, global:0x005EA510, field:this:0x00000008]
    // ASSIGNMENT: Set the guard byte at this+0x2 to 1, marking initialization complete. [field:this:0x00000002, source:raw]
    // RETURN: Return result (the previous guard byte on the already-initialized path, otherwise the dispatch result). [source:raw]

    // Conservative worker pseudocode:
    //   char result = this->initFlag;
    //   if (!result) {
    //     sub_4D8760(-1, 0);
    //     sub_4D8760(1, 1);
    //     if (dword_5EB10C)
    //       (*(void (**)())*(int*)dword_5EB10C + 12)(dword_5EB10C);
    //     BufferInitWith10fDefaults(flt_5EA618);
    //     result = SessionPhaseDispatchWithCascadeChecks(&dword_5EA510, this->field8, 1);
    //     this->initFlag = 1;
    //   }
    //   return result;
    // UNRESOLVED: dword_8AD298 is listed as a read global by the packet but is absent from the raw source; its role cannot be grounded in this function.
    // UNRESOLVED: The identity of the vtable method invoked at offset 12 on the sound-system interface is not resolvable from this packet alone.
}
