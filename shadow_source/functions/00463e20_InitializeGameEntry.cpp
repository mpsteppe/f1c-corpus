// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00463E20
// Canonical corpus name: sub_463E20
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_463E20_00463e20.c

void UnknownObject::InitializeGameEntry()
{
    // Game entry initializer called from Game_Enter (0x0042D370). Initializes a local audio-stream struct with defaults, links it to the game object (v3[1] = gamePtr + 16316, v3[0] = 0), records the instance handle (hinst) and a word global (word_7D1004), and formats a title string "%s %.3f" with aF1Challenge990 and 1.026. If StackBufferCopyPredicateCall succeeds, sets the success flag at game+0x1D0 to 1, stores the game pointer at game+0x3FC0, and stores a VTableQueryWithStackBufferResult result at game+0x417C; otherwise clears the flag to 0. Always initializes the network replay buffer at game+112528 and returns its result.
    // CALL: AudioStreamStructInitWithDefaults(v3) fills the local audio descriptor with default values. [callee:0x0057A3F0, source:raw]
    // ASSIGNMENT: v3[1] = *(dword*)this + 16316: link the descriptor to a location inside the game object (dereferenced from the this pointer). [field:this:0x00000000, source:raw]
    // ASSIGNMENT: v3[0] = 0 clears the descriptor's first DWORD. [source:raw]
    // ASSIGNMENT: v5 = hinst copies the global instance handle. [global:0x007CE2A0, source:raw]
    // ASSIGNMENT: v4 = word_7D1004 copies the word global. [global:0x007D1004, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck(v6, "%s %.3f" [aS3f], aF1Challenge990, 1.026) formats the game-title string into the 32-byte stack buffer. [callee:0x0058815F, global:0x005C6618, global:0x005C6620, source:raw]
    // GUARD: Branch on StackBufferCopyPredicateCall(v3, *(dword*)this + 16312); the sub-object pointer at game+0x3FB8 is the second argument source. [callee:0x0057AAF0, field:obj:0x00003FB8, source:raw]
    // ASSIGNMENT: On success, set the init flag at game+0x1D0 to 1. [field:obj:0x000001D0, source:raw]
    // ASSIGNMENT: On success, store the game pointer itself at game+0x3FC0. [field:obj:0x00003FC0, field:this:0x00000000, source:raw]
    // ASSIGNMENT: On success, store VTableQueryWithStackBufferResult(*(dword*)(game+0x3FB8)) at game+0x417C. [callee:0x0057A880, field:obj:0x0000417C, field:obj:0x00003FB8, source:raw]
    // ASSIGNMENT: On the else path, clear the init flag at game+0x1D0 to 0. [field:obj:0x000001D0, source:raw]
    // CALL: NetworkReplayBufferInit(game+112528) initializes the network replay buffer and provides the function's return value. [callee:0x0045D260, source:raw]
    // RETURN: Return the NetworkReplayBufferInit result. [function:0x00463E20, source:raw]
    // CALL: Invoked by Game_Enter (0x0042D370) during game entry setup. [caller:0x0042D370]

    // Conservative worker pseudocode:
    //   int InitializeGameEntry(void* this) {
    //     dword v3[2]; word v4; HINSTANCE v5; byte v6[32];
    //     AudioStreamStructInitWithDefaults(v3);
    //     v3[1] = *(dword*)this + 16316;
    //     v3[0] = 0;
    //     v5 = hinst; v4 = word_7D1004;
    //     StringFormatWithBufferOverflowCheck(v6, aS3f, aF1Challenge990, 1.026f);
    //     if (StackBufferCopyPredicateCall(v3, *(dword*)this + 16312)) {
    //       *(dword*)(*(dword*)this + 464) = 1;
    //       *(dword*)(*(dword*)this + 16320) = *(dword*)this;
    //       *(dword*)(*(dword*)this + 16764) = VTableQueryWithStackBufferResult(*(dword*)(*(dword*)this + 16312));
    //     } else {
    //       *(dword*)(*(dword*)this + 464) = 0;
    //     }
    //     return NetworkReplayBufferInit((dword*)(*(dword*)this + 112528));
    //   }
    // UNRESOLVED: Owning class of the game object is unknown; the packed object offsets (0x1D0, 0x3FB8, 0x3FC0, 0x417C) are observed behavior, not a proven layout.
    // UNRESOLVED: The semantics of StackBufferCopyPredicateCall (0x0057AAF0) and VTableQueryWithStackBufferResult (0x0057A880) beyond this call site are unknown.
    // UNRESOLVED: The role of word_7D1004 and the exact meaning of the 1.026 title constant are not established.
}
