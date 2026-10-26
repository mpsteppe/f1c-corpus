// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040C7A0
// Canonical corpus name: CameraTargetUpdateOnPlayerChange
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CameraTargetUpdateOnPlayerChange_0040c7a0.c

void UnknownObject::CameraTargetUpdateOnPlayerChange()
{
    // Updates the camera target when the current player's vehicle changes. Reads the current target id from this[14] (offset 0x38) and compares it against the player vehicle's target field (dword_7C54F0[dword_7C54DC] + 18580; packet field this+0x48CC). On mismatch: when no target was set (old id below 0) it stops per-vehicle sound by looping unk_5ECDC8 over stride 18624 up to the byte_7C5BC8 sentinel, then selects a new camera mode from the dispatch selector dword_7CFDC4 (falling back to dword_7CFCC8 when zero); when a target was set it derives the mode via StateCheckWithTernaryLogic and stops the current sound. It then emits the selected mode through the (canonically named) AudioSoundEffectController and stores the player vehicle's target field into this[14].
    // ASSIGNMENT: Read the current camera target id from this[14] (offset 0x38). [source:raw, field:this:0x00000038]
    // GUARD: Compare the current target id against the player vehicle's target field (dword_7C54F0[dword_7C54DC] + 18580; packet field this+0x48CC); if equal, skip the whole update. [source:raw, field:this:0x000048CC, global:0x007C54F0, global:0x007C54DC]
    // GUARD: Branch on the old target id being negative (no target currently selected). [source:raw]
    // LOOP: Iterate the vehicle array from unk_5ECDC8 by stride 18624 up to the byte_7C5BC8 sentinel, calling AudioSoundEffectController(0) per slot to stop per-vehicle sound. [source:raw, global:0x005ECDC8, global:0x007C5BC8, callee:0x004E0ED0]
    // ASSIGNMENT: Select the new camera mode from the dispatch selector dword_7CFDC4 (1 -> 1, 2 -> 3, other -> 0); when the selector is zero, mode is 2 unless dword_7CFCC8 is non-zero (then 0). [source:raw, global:0x007CFDC4, global:0x007CFCC8]
    // CALL: When a target was previously set, compute the new camera mode via StateCheckWithTernaryLogic(this). [source:raw, callee:0x0040C8D0]
    // CALL: Stop the current sound with AudioSoundEffectController(0) in the existing-target branch, then emit the selected mode with AudioSoundEffectController(mode). [source:raw, callee:0x004E0ED0]
    // ASSIGNMENT: Store the new target: this[14] = *(dword_7C54F0[dword_7C54DC] + 18580). [source:raw, field:this:0x00000038, field:this:0x000048CC, global:0x007C54F0, global:0x007C54DC]
    // RETURN: Return the current/new target value. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_40C7A0(_DWORD* this_) {
    //     int result = this_[14];
    //     if (result != *(int*)(dword_7C54F0[dword_7C54DC] + 18580)) {
    //       int mode;
    //       if (result < 0) {
    //         char* v4 = (char*)&unk_5ECDC8;
    //         do { AudioSoundEffectController(0); v4 += 18624; }
    //         while ((int)v4 < (int)byte_7C5BC8);
    //         if (dword_7CFDC4) {
    //           if (dword_7CFDC4 == 1) mode = 1;
    //           else if (dword_7CFDC4 == 2) mode = 3;
    //           else mode = 0;
    //         } else {
    //           mode = dword_7CFCC8 != 0 ? 0 : 2;
    //         }
    //       } else {
    //         mode = StateCheckWithTernaryLogic(this_);
    //         AudioSoundEffectController(0);
    //       }
    //       AudioSoundEffectController(mode);
    //       result = dword_7C54F0[dword_7C54DC];
    //       this_[14] = *(int*)(result + 18580);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The raw code dereferences the vehicle target field with literal 18580 while the packet field table labels it this+0x48CC; both representations are preserved without choosing between them.
    // UNRESOLVED: Global 0x007C54E0 is listed in the packet globals but is never referenced in the raw function body; its role here is unknown.
    // UNRESOLVED: Semantic meaning of the emitted mode values (0/1/2/3) and of the dispatch selector dword_7CFDC4 vs. queued-flag dword_7CFCC8 mapping is not established.
    // UNRESOLVED: Whether AudioSoundEffectController(mode) plays a mode-indexed sound or drives a state selector is not resolved from this packet alone.
}
