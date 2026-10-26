// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D4600
// Canonical corpus name: Steward_Post
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Steward_Post_004d4600.c

void UnknownObject::Steward_Post()
{
    // Steward post-race cleanup: debug-log entry, frees D3D audio state pointer at this+0xA8, resets comparison/camera director state, frees state arrays at this+0x110 and this+0x114, conditionally refreshes season scoring, resets every vehicle substate, frees the counted array at this+0x1AC (with its container), and zeroes 52 dword-pairs starting at this+0x1B0 and this+0x280.
    // GUARD: If StringSplitLoop(2, aDDevF119992002_3, 2855) returns non-zero, log 'Entered Steward Post' via DebugLogWrite(&dword_8AD25C, aEnteredSteward_2). [callee:0x004D7A50, callee:0x004D7AA0, global:0x005D3B6C, global:0x005D43AC, global:0x008AD25C]
    // GUARD: If the D3D audio state pointer at this+0xA8 is non-null, run D3DStateInit on it, re-read this+0xA8 and free it via FreeWrapper_7bcf, then set this+0xA8 to 0. [field:this:0x000000A8, callee:0x004482D0, callee:0x00587BCF]
    // ASSIGNMENT: Set this+0xA8 to 0 after freeing the audio state. [field:this:0x000000A8]
    // CALL: ArithmeticComparison_2e20(this) resets comparison state on the steward object. [callee:0x004D2E20]
    // CALL: sub_4D24D0() runs a follow-up reset routine. [callee:0x004D24D0]
    // CALL: CameraDirectorResetInit(this) resets camera director state. [callee:0x0040DA30]
    // ASSIGNMENT: Set this+0x10C to 0. [field:this:0x0000010C]
    // GUARD: If the state array pointer at this+0x110 is non-null, free it via FreeWrapper_7bcf and set this+0x110 to 0. [field:this:0x00000110, callee:0x00587BCF]
    // GUARD: If the pointer at this+0x114 is non-null, free it via FreeWrapper_7bcf and set this+0x114 to 0. [field:this:0x00000114, callee:0x00587BCF]
    // GUARD: If dword_7D0410 != 4, call SeasonScoringInfoUpdater(dword_7D2DB0) to refresh season scoring. [global:0x007D0410, global:0x007D2DB0, callee:0x004C2A80]
    // LOOP: For i in [0, dword_5C329C): call StructResetReinitializer(dword_7C54F0[i] + 16436) to reset each vehicle substate (16436 = 0x4034). [global:0x005C329C, global:0x007C54F0, callee:0x004BB950]
    // GUARD: Second check of this+0x110: if still non-null, free it again via FreeWrapper_7bcf and set this+0x110 to 0. [field:this:0x00000110, callee:0x00587BCF]
    // ASSIGNMENT: Set this+0x1A8 (count) to 0. [field:this:0x000001A8]
    // LOOP: If the counted array pointer at this+0x1AC is non-null, read its element count from the container header (ptr-4), walk the 8-byte-strided element slots from the last to the first freeing each non-null element via FreeWrapper_7bcf, free the container header, then set this+0x1AC to 0. [field:this:0x000001AC, callee:0x00587BCF]
    // LOOP: Zero 52 pairs of dwords: for each of 52 iterations write 0 at (this+0x1B0 + 8*k) and (this+0x280 + 8*k), clearing two parallel arrays of 52 entries each. [function:0x004D4600, source:raw]
    // RETURN: Return result, a pointer just past the zeroed 52-pair region. [function:0x004D4600, source:raw]

    // Conservative worker pseudocode:
    //   if StringSplitLoop(2, "d:\dev\f1 1999-2002\...", 2855) then DebugLogWrite(&dword_8AD25C, "Entered Steward Post")
    //   if this->d3dAudioState then { D3DStateInit(this->d3dAudioState); FreeWrapper_7bcf(this->d3dAudioState); this->d3dAudioState = 0 }
    //   ArithmeticComparison_2e20(this); sub_4D24D0(); CameraDirectorResetInit(this)
    //   this->stateCount = 0
    //   if this->stateArray then { FreeWrapper_7bcf(this->stateArray); this->stateArray = 0 }
    //   if this->prevStateArray then { FreeWrapper_7bcf(this->prevStateArray); this->prevStateArray = 0 }
    //   if dword_7D0410 != 4 then SeasonScoringInfoUpdater(dword_7D2DB0)
    //   for i in 0 .. dword_5C329C-1: StructResetReinitializer(dword_7C54F0[i] + 16436)
    //   if this->stateArray then { FreeWrapper_7bcf(this->stateArray); this->stateArray = 0 }
    //   this->count = 0
    //   if this->arrayPtr then { free each of count elements at 8-byte stride; FreeWrapper_7bcf(header); this->arrayPtr = 0 }
    //   for k in 0 .. 51: this->arrayA[8k] = 0; this->arrayB[8k] = 0
    //   return pointer past cleared region
    // UNRESOLVED: Source frees this+0x110 twice (two identical guard/free blocks); may be dead code or an intentional second pass.
    // UNRESOLVED: The counted array header layout (count at ptr-4, elements at 8-byte stride) is inferred from indexing, not from a named struct.
}
