// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057BC80
// Canonical corpus name: AudioStreamStateReset
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AudioStreamStateReset_0057bc80.c

void UnknownObject::AudioStreamStateReset()
{
    // Resets two audio stream state fields on the receiver (WORD at this+0x12C, DWORD at this+0x130) to zero, then chains to a small struct field-init helper and returns its result.
    // ASSIGNMENT: Zero the 16-bit field at this+0x12C (audio stream state/status word). [field:this:0x0000012C]
    // ASSIGNMENT: Zero the 32-bit field at this+0x130 (audio stream position/count dword). [field:this:0x00000130]
    // CALL: Chain to the SmallStructFieldInit helper with this pointer for further member initialization. [source:raw]
    // RETURN: Return the value produced by the SmallStructFieldInit call. [source:raw]

    // Conservative worker pseudocode:
    //   this->stream_status_word = 0;
    //   this->stream_position_dword = 0;
    //   return SmallStructFieldInit(this);
    // UNRESOLVED: SmallStructFieldInit has no packet callee address, so its identity, arguments beyond this, and return semantics are unverified.
    // UNRESOLVED: The receiver object type is unconfirmed; fields at 0x12C/0x130 are only known to be reset to zero by this routine.
}
