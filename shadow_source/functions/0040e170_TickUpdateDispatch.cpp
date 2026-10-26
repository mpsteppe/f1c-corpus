// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040E170
// Canonical corpus name: TickUpdateDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TickUpdateDispatch_0040e170.c

void UnknownObject::TickUpdateDispatch()
{
    // Tick update dispatch on a this-object: if the sub-struct pointer at this+0x88 is non-null and its field at +0x24 equals 10, run the guarded engine initializer with this+20; read the sub-struct at this+0x8 and, if the pointer at its +0xAF4 is non-null, invoke that object's vtable method at +0xC; reinitialize the buffer with 10f defaults, then tail-call the camera-director reset init passing this.
    // GUARD: guard: enter the initializer branch only when the pointer at this+0x88 is non-null and its field at +0x24 equals 10 [field:this:0x00000088, field:*(this+0x88):0x00000024, guard:0]
    // CALL: call EngineGuardedInitializer with this+20 when the flag==10 guard passes [callee:0x004347C0, guard:0]
    // ASSIGNMENT: read the sub-struct pointer at this+0x8 into v3 [field:this:0x00000008]
    // ASSIGNMENT: read the pointer at v3+0xAF4 into v4 [field:*(this+0x8):0x00000AF4]
    // GUARD: guard: only dispatch when the pointer v4 (this+0x8 -> +0xAF4) is non-null [field:*(this+0x8):0x00000AF4]
    // CALL: virtual call on v4: load the vtable pointer at v4+0x0 and invoke the method at vtable+0xC (vtable[3]) [field:*(*(this+0x8)+0xAF4):0x00000000, field:*(*(*(this+0x8)+0xAF4)+0x0):0x0000000C]
    // CALL: call BufferInitWith10fDefaults on the v3 sub-struct to (re)initialize its buffer with 10f defaults [callee:0x004186A0]
    // RETURN: tail call: return CameraDirectorResetInit(this); the reset-init target is named only in the raw source and has no callee record in this packet [source:raw, function:0x0040E170]

    // Conservative worker pseudocode:
    //   if ( *(DWORD*)((char*)this + 0x88) && *(DWORD*)(*(DWORD*)((char*)this + 0x88) + 0x24) == 10 )
    //       EngineGuardedInitializer((char*)this + 20);
    //   DWORD* sub = *(DWORD**)((char*)this + 0x8);
    //   void* disp = *(void**)((char*)sub + 0xAF4);
    //   if ( disp ) (*(void(__thiscall**)(void*))(*(DWORD*)disp + 0xC))(disp);
    //   BufferInitWith10fDefaults(sub);
    //   return CameraDirectorResetInit((char*)this);
    // UNRESOLVED: Owner object type is unknown; packet owner is UNKNOWN/UnknownObject.
    // UNRESOLVED: The CameraDirectorResetInit tail-call target has no callee evidence record in this packet, so its address is not recoverable from this packet.
}
