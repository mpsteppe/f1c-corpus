// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005633D0
// Canonical corpus name: DisplayModeQueryWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DisplayModeQueryWrapper_005633d0.c

void UnknownObject::DisplayModeQueryWrapper()
{
    // Allocates and initializes a struct by calling StructAllocInitWithSwitchBasedType (005642F0) with the switch/type selector read from this[37] (byte offset 0x94), then pushes an entry to the audio stack via AudioStackPushWithOverflowRealloc (005648D0). Returns the allocated struct. Called by NetworkConnection (00563260).
    // CALL: StructAllocInitWithSwitchBasedType(a4, this[37]) allocates and initializes a struct; this[37] (byte offset 0x94) supplies the switch-based type selector parameter [field:this:0x00000094, callee:0x005642F0, source:raw]
    // CALL: AudioStackPushWithOverflowRealloc(a3) pushes an entry to the audio stack, growing the stack on overflow [callee:0x005648D0, source:raw]
    // RETURN: Returns v5, the struct allocated and initialized by StructAllocInitWithSwitchBasedType [source:raw]
    // CALL: Called by NetworkConnection (00563260), making this an allocation/push step on a network-received event [caller:0x00563260]

    // Conservative worker pseudocode:
    //   int result = StructAllocInitWithSwitchBasedType(a4, this[37]);
    //   AudioStackPushWithOverflowRealloc(a3);
    //   return result;
    // UNRESOLVED: Parameter a2 is unused in the decompiled body and its purpose is unknown
    // UNRESOLVED: The enum of type-selector values read from this[37] (byte offset 0x94) is not documented
    // UNRESOLVED: The link between a display-mode query and an audio-stack push is unexplained; parameter roles (a3, a4) are inferred only from callee ordering
    // UNRESOLVED: The owner type is unknown; the prelabel action is 'llm' with no cluster evidence
}
