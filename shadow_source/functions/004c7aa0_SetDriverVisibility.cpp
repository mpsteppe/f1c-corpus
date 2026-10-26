// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C7AA0
// Canonical corpus name: SetDriverVisibility
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SetDriverVisibility_004c7aa0.c

void UnknownObject::SetDriverVisibility()
{
    // Sets the driver visibility flags (bits 1 and 2) at this+0x48BC. When the show argument is non-zero, ORs in 6 (visible); when it is zero, clears those bits with 0xFFFFFFF9 (hidden). After showing, if the vehicle at dword_7C54F0[dword_7C54DC] + 18580 (0x4894) matches this+0x4894 (i.e. the vehicle is the player's), gates the engine sound through StateCheckWithTernaryLogic of the session state at dword_5EA510 and plays it via AudioSoundEffectController; otherwise plays the external-vehicle sound. Hiding always plays the stop sound (3). Called by CollisionContactIteration and LoadingPhase2.
    // CALCULATION: Reads the current visibility flags dword at this+0x48BC into v3 [field:this:0x000048BC, source:raw]
    // GUARD: Branches on the show flag a2: non-zero takes the show path, zero takes the hide path [source:raw]
    // ASSIGNMENT: Show path: writes v3 OR 6 back to this+0x48BC, setting visibility bits 1 and 2 [field:this:0x000048BC, source:raw]
    // GUARD: Compares the player vehicle team dword at dword_7C54F0[dword_7C54DC] + 18580 against this+0x4894 to decide whether this is the player's own vehicle [global:0x007C54DC, global:0x007C54F0, field:this:0x00004894, source:raw]
    // CALL: Own-vehicle show path: evaluates the session state through StateCheckWithTernaryLogic(dword_5EA510) to decide whether the engine sound should play [callee:0x0040C8D0, global:0x005EA510, source:raw]
    // CALL: Own-vehicle show path: returns the result of AudioSoundEffectController(v4), playing the engine effect [callee:0x004E0ED0, source:raw]
    // CALL: Other-vehicle show path: returns the result of AudioSoundEffectController(0), playing the external-vehicle engine effect [callee:0x004E0ED0, source:raw]
    // ASSIGNMENT: Hide path: writes v3 AND 0xFFFFFFF9 back to this+0x48BC, clearing visibility bits 1 and 2 [field:this:0x000048BC, source:raw]
    // CALL: Hide path: returns the result of AudioSoundEffectController(3), playing the stop sound [callee:0x004E0ED0, source:raw]
    // RETURN: Returns the AudioSoundEffectController result on every branch [callee:0x004E0ED0, source:raw]
    // CALL: Invoked by CollisionContactIteration and LoadingPhase2 during their handling of driver/vehicle visibility [caller:0x00460DD0, caller:0x004B8940]

    // Conservative worker pseudocode:
    //   v3 = this[0x48BC];
    //   if (a2) {
    //     this[0x48BC] = v3 | 6;
    //     if (dword_7C54F0[dword_7C54DC][0x4894] == this[0x4894]) return AudioSoundEffectController(StateCheckWithTernaryLogic(&dword_5EA510));
    //     return AudioSoundEffectController(0);
    //   }
    //   this[0x48BC] = v3 & 0xFFFFFFF9;
    //   return AudioSoundEffectController(3);
    // UNRESOLVED: The relationship between this+0x4894 and the vehicle at dword_7C54F0[dword_7C54DC]+18580 is described as a team comparison in existing analysis but the equality check itself is only demonstrated by the raw source; the concrete meaning of the dword at 18580 is not proven here
    // UNRESOLVED: AudioSoundEffectController parameter meanings (0, 3, and the session-check result) are taken from existing analysis and are not self-evident from this packet alone
}
