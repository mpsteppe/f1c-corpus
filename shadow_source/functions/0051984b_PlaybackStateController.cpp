// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051984B
// Canonical corpus name: PlaybackStateController
// Owner: PlaybackStateController [DERIVED]
// Raw source: functions/PlaybackStateController_0051984b.c

void PlaybackStateController::PlaybackStateController()
{
    // Dispatches playback state transitions on a state controller: selects a stream-buffer callback (RendererVtableDispatchWrapper, BufferedDataStreamWrite, or AudioStreamBufferFill), writes a function-dispatch index into the controller vtable, and resets stream state fields, branching on command parameter a2 and an audio-buffer readiness flag.
    // CALCULATION: Cache stream-buffer object pointer: streamBuffer = *(this + 0x180). [field:this:0x00000180]
    // GUARD: If a2 (command) is nonzero, take the command-dispatch branch. [function:0x0051984B]
    // CALCULATION: result = a2 - 2 (residual value returned only on the a2 == 2 path). [source:raw]
    // GUARD: If a2 == 2, select the renderer-dispatch callback. [function:0x0051984B]
    // ASSIGNMENT: streamBuffer+0x4 (this+0x184) = RendererVtableDispatchWrapper (renderer dispatch path). [field:this:0x00000184, global:0x00519828]
    // ASSIGNMENT: Read controller vtable pointer (*a1) and write 4 into vtable slot at +0x14 (function-dispatch index). [field:obj:0x00000000, field:obj:0x00000014]
    // CALL: Dispatch via controller vtable entry 0: return (*a1)(a1). [field:this:0x00000000]
    // GUARD: Else (a2 == 0): enter the state-refresh path. [function:0x0051984B]
    // CALCULATION: status = *(this + 0x19C); pointer to audio-buffer status structure (also initial result value). [field:this:0x0000019C]
    // GUARD: If byte at (*(this+0x19C)) + 0x8 is nonzero, audio buffer is ready. [field:this:0x000001A4]
    // ASSIGNMENT: streamBuffer+0x4 (this+0x184) = AudioStreamBufferFill (audio stream path). [field:this:0x00000184, global:0x00519720]
    // CALL: result = TextureRowCopy(a1). [callee:0x0051941D]
    // ASSIGNMENT: streamBuffer+0x40 (this+0x1C0) = 0. [field:this:0x000001C0]
    // ASSIGNMENT: streamBuffer+0x44 (this+0x1C4) = 0. [field:this:0x000001C4]
    // ASSIGNMENT: streamBuffer+0x4C (this+0x1CC) = 0. [field:this:0x000001CC]
    // ASSIGNMENT: Else (audio buffer not ready): streamBuffer+0x4 (this+0x184) = BufferedDataStreamWrite. [field:this:0x00000184, global:0x005196B8]
    // ASSIGNMENT: streamBuffer+0x30 (this+0x1B0) byte = 0. [field:this:0x000001B0]
    // ASSIGNMENT: streamBuffer+0x34 (this+0x1B4) = 0. [field:this:0x000001B4]
    // RETURN: Return result: a2-2 on the a2 == 2 path, TextureRowCopy return on the audio-ready path, or the status pointer on the buffered path. [function:0x0051984B]

    // Conservative worker pseudocode:
    //   int PlaybackStateController(void* this, int command) {
    //       void* streamBuffer = *(void**)((char*)this + 0x180);
    //       if (command != 0) {
    //           if (command == 2) {
    //               *(int*)((char*)streamBuffer + 0x4) = RendererVtableDispatchWrapper;
    //               return command - 2;
    //           }
    //           *(int*)(*(int**)this + 0x14) = 4;
    //           return (*(int (__cdecl **)(void*))*(int**)this)(this);
    //       }
    //       char* status = *(char**)((char*)this + 0x19C);
    //       if (status[8]) {
    //           *(int*)((char*)streamBuffer + 0x4) = AudioStreamBufferFill;
    //           int result = TextureRowCopy(this);
    //           *(int*)((char*)streamBuffer + 0x40) = 0;
    //           *(int*)((char*)streamBuffer + 0x44) = 0;
    //           *(int*)((char*)streamBuffer + 0x4C) = 0;
    //           *(char*)((char*)streamBuffer + 0x30) = 0;
    //           *(int*)((char*)streamBuffer + 0x34) = 0;
    //           return result;
    //       }
    //       *(int*)((char*)streamBuffer + 0x4) = BufferedDataStreamWrite;
    //       *(char*)((char*)streamBuffer + 0x30) = 0;
    //       *(int*)((char*)streamBuffer + 0x34) = 0;
    //       return (int)status;
    //   }
    // UNRESOLVED: Indirect dispatch target at controller vtable entry 0 (this+0x0) is unknown; no static callee recorded.
    // UNRESOLVED: The three stream-buffer callbacks (RendererVtableDispatchWrapper, AudioStreamBufferFill, BufferedDataStreamWrite) are referenced as function pointers but their internal behavior is not resolved here.
    // UNRESOLVED: Semantics of the byte flag at status+0x8 (audio-buffer readiness) and fields 0x40/0x44/0x4C are inferred from context only.
    // UNRESOLVED: Owner identification rests on the legacy ABI label; no runtime or static cross-evidence confirms the PlaybackStateController name.
}
