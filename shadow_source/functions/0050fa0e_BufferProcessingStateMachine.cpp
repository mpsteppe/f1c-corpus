// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050FA0E
// Canonical corpus name: BufferProcessingStateMachine
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BufferProcessingStateMachine_0050fa0e.c

void UnknownObject::BufferProcessingStateMachine()
{
    // Buffer-processing state machine. When the state at this+0x10 is not 204, reinitializes: calls the init function at *(this+0x17C)+0, resets the counter this+0x78 to 0 and sets the state to 204. While the active-flag byte at *(this+0x17C)+0x8 is nonzero it loops over buffered chunks: a batch boundary (counter this+0x78 at or above the limit this+0x60) flushes by calling *(this+0x17C)+4 then *(this+0x17C)+0 and resets the counter to 0; per chunk it writes the current counter and the limit into the callback object at this+0x8 (slots +4 and +8), calls the callback vtable at *(this+0x8)+0 when the object is non-null, and advances through the processing function at *(this+0x180)+4. If the counter is unchanged after a processing call it returns 0; otherwise it continues until the batch is drained. When the active flag clears, it sets the final state this+0x10 to 205 plus the nonzero-ness of the byte at this+0x41 (205 when the byte is nonzero, otherwise 206) and returns 1.
    // GUARD: If the state this+0x10 is not 204, take the reinitialization path. [guard:0, field:this:0x00000010]
    // ASSIGNMENT: Reinitialization: call the init function at *(this+0x17C)+0, reset the counter this+0x78 to 0, and set the state this+0x10 to 204. [field:this:0x0000017C, field:*(this+0x17C):0x00000000, field:this:0x00000078, field:this:0x00000010]
    // GUARD: If the active-flag byte at *(this+0x17C)+0x8 is nonzero, enter the batch processing loops; otherwise jump to the completion state. [field:this:0x0000017C, field:*(this+0x17C):0x00000008]
    // GUARD: First loop: read the counter v2 = this+0x78; while the counter is at or above the limit this+0x60, run a batch boundary; break out to the per-chunk loop when the counter drops below the limit. [field:this:0x00000078, field:this:0x00000060]
    // LOOP: Batch boundary: call the flush function at *(this+0x17C)+4, call the init function at *(this+0x17C)+0, and reset the counter this+0x78 to 0; when the active flag at *(this+0x17C)+0x8 is then clear, exit to the completion state. [field:this:0x0000017C, field:*(this+0x17C):0x00000004, field:*(this+0x17C):0x00000000, field:this:0x00000078, field:*(this+0x17C):0x00000008]
    // LOOP: Per-chunk loop: if the callback object at this+0x8 is non-null, write the current counter value to the object's +4 slot and the limit this+0x60 to its +8 slot, then call the callback vtable at *(this+0x8)+0. [field:this:0x00000008, field:*(this+0x8):0x00000004, field:*(this+0x8):0x00000008, field:this:0x00000060, field:*(this+0x8):0x00000000]
    // CALL: Snapshot the counter v4 = this+0x78, call the data-processing function at *(this+0x180)+4 with arguments (this, 0, &this+0x78, 0), then re-read the counter. [field:this:0x00000078, field:this:0x00000180, field:*(this+0x180):0x00000004]
    // GUARD: If the counter this+0x78 is unchanged since the snapshot v4, return 0 (no progress). [field:this:0x00000078]
    // LOOP: If the re-read counter is at or above the limit this+0x60, return to the batch boundary; otherwise continue the per-chunk loop. [field:this:0x00000078, field:this:0x00000060]
    // STATE_TRANSITION: Completion path: set the final state this+0x10 to 205 when the byte at this+0x41 is nonzero, otherwise 206, and return 1. [guard:1, field:this:0x00000041, field:this:0x00000010]
    // RETURN: Return 1 from the completion path after the final state is set, or 0 from the no-progress guard inside the per-chunk loop. [function:0x0050FA0E, source:raw]

    // Conservative worker pseudocode:
    //   char BufferProcessingStateMachine(int this) {
    //     if (*(DWORD*)(this + 16) != 204) {
    //       (*(void(__cdecl***)(int))(this + 380))(this);
    //       *(DWORD*)(this + 120) = 0;
    //       *(DWORD*)(this + 16) = 204;
    //     }
    //     if (*(BYTE*)(*(DWORD*)(this + 380) + 8)) {
    //       unsigned int* counter = (unsigned int*)(this + 120);
    //       for (;;) {
    //         unsigned int v2 = *counter;
    //         if (*counter < *(DWORD*)(this + 96)) break;
    //         batch_boundary:
    //         (*(void(__cdecl**)(int))(*(DWORD*)(this + 380) + 4))(this);
    //         (**(void(__cdecl***)(int))(this + 380))(this);
    //         *counter = 0;
    //         if (!*(BYTE*)(*(DWORD*)(this + 380) + 8)) goto complete;
    //       }
    //       for (;;) {
    //         int cb = *(DWORD*)(this + 8);
    //         if (cb) {
    //           *(DWORD*)(cb + 4) = v2;
    //           *(DWORD*)(*(DWORD*)(this + 8) + 8) = *(DWORD*)(this + 96);
    //           (**(void(__cdecl***)(int))(this + 8))(this);
    //         }
    //         unsigned int before = *counter;
    //         (*(void(__cdecl**)(int, DWORD, int, DWORD))(*(DWORD*)(this + 384) + 4))(this, 0, this + 120, 0);
    //         v2 = *counter;
    //         if (*counter == before) return 0;
    //         if (v2 >= *(DWORD*)(this + 96)) goto batch_boundary;
    //       }
    //     }
    //     complete:
    //     *(DWORD*)(this + 16) = (*(BYTE*)(this + 65) != 0) + 205;
    //     return 1;
    //   }
    // UNRESOLVED: The concrete functions behind the pointer slots at *(this+0x17C)+0, *(this+0x17C)+4, *(this+0x180)+4 and the callback vtable at *(this+0x8)+0 are assigned elsewhere at runtime and are not evidenced here.
    // UNRESOLVED: The meaning of the four-argument data-processing call (this, 0, &this+0x78, 0) beyond 'advance the counter' is not established by this packet; the packet lists no callees.
    // UNRESOLVED: The role of the byte at this+0x41 in selecting between final states 205 and 206 is inferred from the completion formula only.
    // UNRESOLVED: The sole static caller is StateMachineWithDispatch (0x0050FB3B), but the calling relationship does not establish the owner class.
}
