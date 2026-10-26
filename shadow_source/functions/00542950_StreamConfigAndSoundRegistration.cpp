// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00542950
// Canonical corpus name: UtilityFunction_2950
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UtilityFunction_2950_00542950.c

void UnknownObject::StreamConfigAndSoundRegistration()
{
    // Configures stream parameters on `this` and optionally registers it with the sound/stream manager. First validates the mode via sub_5426E0(this, a4, a5), returning -1 on failure. Then stores a5 into this[6] (this+0x18), a2 into this[7] (this+0x1C), and a3 into this[8] (this+0x20). If the low nibble of a5 is nonzero, registers `this` against the manager singleton dword_8B78A0 via sub_53F720, returning -1 if registration fails. Returns 0 on success.
    // GUARD: If sub_5426E0(this, a4, a5) returns nonzero (mode validation/reconfiguration failure), return -1 without storing or registering. [callee:0x005426E0]
    // ASSIGNMENT: Store parameter a2 into this[7] (field this+0x1C). [field:this:0x0000001C]
    // ASSIGNMENT: Store parameter a3 into this[8] (field this+0x20). [field:this:0x00000020]
    // ASSIGNMENT: Store parameter a5 into this[6] (field this+0x18). [field:this:0x00000018]
    // GUARD: If (a5 & 0xF) != 0 (streaming-mode flag set) and sub_53F720(&dword_8B78A0, this, 0) returns nonzero (registration of `this` with the sound/stream manager singleton fails), return -1. [global:0x008B78A0, callee:0x0053F720]
    // RETURN: Return 0 on success. [source:raw]

    // Conservative worker pseudocode:
    //   if (sub_5426E0(this, a4, a5) != 0) return -1;
    //   this->streamFlags = a5;   // this[6]  / +0x18
    //   this->paramA = a2;        // this[7]  / +0x1C
    //   this->paramB = a3;        // this[8]  / +0x20
    //   if ((a5 & 0xF) != 0 && sub_53F720(&dword_8B78A0, this, 0) != 0) return -1;
    //   return 0;
    // UNRESOLVED: The exact meanings of arguments a2/a3/a4 and of the a5 & 0xF mode bits are not evidenced beyond the stored-field writes and the registration guard.
    // UNRESOLVED: sub_5426E0's contract (what a4/a5 select, what its nonzero return signifies) is not detailed in this packet.
}
