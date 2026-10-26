// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005199C5
// Canonical corpus name: InitAndChain
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/InitAndChain_005199c5.c

void UnknownObject::InitAndChain()
{
    // Resets the current animation index dword at this+0x80 (a1[32]) to zero, then chains to the SpriteFrameSelector helper with the same object pointer and returns its result.
    // ASSIGNMENT: Zero the 32-bit field at this+0x80 (dword index a1[32], the current animation position). [field:this:0x00000080]
    // CALL: Chain to the SpriteFrameSelector helper with the same object pointer to select the initial frame. [source:raw]
    // RETURN: Return the value produced by the SpriteFrameSelector call. [source:raw]

    // Conservative worker pseudocode:
    //   this->current_animation_index = 0;
    //   return SpriteFrameSelector(this);
    // UNRESOLVED: SpriteFrameSelector has no packet callee address, so its identity and the meaning of its return value are unverified.
    // UNRESOLVED: The receiver object type is unconfirmed; the field at 0x80 is only known to be zeroed by this routine.
    // UNRESOLVED: Why the animation index reset is split from the frame-selection step is unknown.
}
