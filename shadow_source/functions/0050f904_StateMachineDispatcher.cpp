// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050F904
// Canonical corpus name: StateMachineDispatcher
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StateMachineDispatcher_0050f904.c

void UnknownObject::StateMachineDispatcher()
{
    // State-machine dispatcher for an object whose state variable lives at this+0x10. On states 205/206 with the flag byte at this+0x40 clear, it conditionally posts operation code 66 to the target object's vtable data (*(*(this)+0x14)) when the counter at this+0x78 is below the limit at this+0x60, calls the state-transition function pointer at *(this+0x17C)+4, and moves to state 210. State 207 also moves to 210. Any other non-210 state posts operation code 18 plus the current state to the target and performs a vtable dispatch. After the state block, a do-while loop polls the processing function pointer at *(this+0x18C)+0; when the completion byte at *(this+0x18C)+0x11 is set it invokes the final-dispatch pointer at *(this+0x14)+0x18 and calls VirtualDispatchConditionalValue before returning 1. Returns 0 when the polled processing function reports no further work.
    // GUARD: Read the current state v1 = this+0x10; the first branch is taken when v1 is 205 or 206 and the byte at this+0x40 is zero. [field:this:0x00000010, field:this:0x00000040]
    // ASSIGNMENT: In the 205/206 branch, when the counter this+0x78 is below the limit this+0x60, write operation code 66 to the target object's slot *(*(this)+0x14) and perform a vtable dispatch through the pointer at this+0x0. [field:this:0x00000078, field:this:0x00000060, field:obj:0x00000014, field:obj:0x00000000, field:this:0x00000000]
    // CALL: In the 205/206 branch, call the state-transition function pointer at *(this+0x17C)+4, then set the state this+0x10 to 210. [field:this:0x0000017C, field:*(this+0x17C):0x00000004, field:this:0x00000010]
    // STATE_TRANSITION: When the state v1 is 207, move directly to state 210 by writing this+0x10 = 210. [field:this:0x00000010]
    // STATE_TRANSITION: For any other state v1 that is not 210, write operation code 18 to *(*(this)+0x14), copy the current state v1 to *(*(this)+0x18), and perform a vtable dispatch through the pointer at this+0x0. [field:obj:0x00000014, field:obj:0x00000018, field:obj:0x00000000, field:this:0x00000000]
    // LOOP: Enter the do-while processing loop: read the processing function pointer at *(this+0x18C)+0; if the completion byte at *(this+0x18C)+0x11 is set, invoke the final-dispatch pointer at *(this+0x14)+0x18, call VirtualDispatchConditionalValue, and return 1. [field:this:0x0000018C, field:*(this+0x18C):0x00000011, field:this:0x00000014, field:*(this+0x14):0x00000018, callee:0x00516937]
    // LOOP: Continue polling while the processing function pointer at *(this+0x18C)+0 returns nonzero; when it returns zero, exit the loop. [field:*(this+0x18C):0x00000000, field:this:0x0000018C]
    // RETURN: Return 0 after the processing loop exits with the polled function returning zero. [function:0x0050F904, source:raw]

    // Conservative worker pseudocode:
    //   char StateMachineDispatcher(int this) {
    //     int state = *(DWORD*)(this + 16);
    //     if ((state == 205 || state == 206) && !*(BYTE*)(this + 64)) {
    //       if (*(DWORD*)(this + 120) < *(DWORD*)(this + 96)) {
    //         *(DWORD*)(*(DWORD*)this + 20) = 66;
    //         (**(void(__cdecl***)(int))this)(this);
    //       }
    //       (*(void(__cdecl**)(int))(*(DWORD*)(this + 380) + 4))(this);
    //       *(DWORD*)(this + 16) = 210;
    //     } else if (state == 207) {
    //       *(DWORD*)(this + 16) = 210;
    //     } else if (state != 210) {
    //       *(DWORD*)(*(DWORD*)this + 20) = 18;
    //       *(DWORD*)(*(DWORD*)this + 24) = *(DWORD*)(this + 16);
    //       (**(void(__cdecl***)(int))this)(this);
    //     }
    //     do {
    //       if (*(BYTE*)(*(DWORD*)(this + 396) + 17)) {
    //         (*(void(__cdecl**)(int))(*(DWORD*)(this + 20) + 24))(this);
    //         VirtualDispatchConditionalValue(this);
    //         return 1;
    //       }
    //     } while ((**(int(__cdecl***)(int))(this + 396))(this));
    //     return 0;
    //   }
    // UNRESOLVED: The meaning of the operation codes 66 and 18 written to the target object's vtable data is not established by this packet; the target object type is unknown.
    // UNRESOLVED: The concrete processing/transition functions behind the pointer slots at *(this+0x18C)+0, *(this+0x17C)+4 and *(this+0x14)+0x18 are assigned elsewhere at runtime and are not evidenced here.
    // UNRESOLVED: The semantics of states 205/206/207/210 and of the counter/limit comparison at this+0x78 versus this+0x60 are inferred from the transition structure only; no higher-level state chart is evidenced.
    // UNRESOLVED: The sole static caller is ImageTextureDecompressor (0x00501722), but the calling relationship does not establish the owner class.
}
