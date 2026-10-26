// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C0AB0
// Canonical corpus name: AudioSubsystemInitializer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AudioSubsystemInitializer_004c0ab0.c

void UnknownObject::AudioSubsystemInitializer()
{
    // Initializes the audio subsystem state block. Runs ArithmeticComparison_03c0 over 103 sub-blocks of 109 dwords (436 bytes) starting at 'this', plus one further call at this+0xAF6C (44908), then StructInitWithDefaults at this+0xB120 (45344). Sets the trailing scalar fields: this+0xB144 = 0, this+0xB148 = -1, this+0xB14C = 1, this+0xB150 = 0. Returns 'this'.
    // LOOP: Run ArithmeticComparison_03c0 103 times, advancing the pointer by 109 dwords (436 bytes) per iteration to initialize each sub-block. [callee:0x004C03C0, source:raw]
    // CALL: ArithmeticComparison_03c0(this + 44908) initializes one trailing sub-block past the loop range. [callee:0x004C03C0, source:raw]
    // CALL: StructInitWithDefaults(this + 45344) initializes a defaults-filled sub-structure. [callee:0x004C0370, source:raw]
    // ASSIGNMENT: *(this + 45380) = 0 sets field 0xB144. [field:this:0x0000B144, source:raw]
    // ASSIGNMENT: *(this + 45392) = 0 sets field 0xB150. [field:this:0x0000B150, source:raw]
    // ASSIGNMENT: *(this + 45384) = -1 sets field 0xB148 to the all-ones sentinel. [field:this:0x0000B148, source:raw]
    // ASSIGNMENT: *(this + 45388) = 1 sets field 0xB14C. [field:this:0x0000B14C, source:raw]
    // RETURN: Return this, the initialized block pointer. [source:raw]

    // Conservative worker pseudocode:
    //   for (i = 103; i != 0; i--) {
    //       ArithmeticComparison_03c0(p);
    //       p += 109;
    //   }
    //   ArithmeticComparison_03c0(this + 44908);
    //   StructInitWithDefaults(this + 45344);
    //   *(int*)(this + 45380) = 0;
    //   *(char*)(this + 45392) = 0;
    //   *(int*)(this + 45384) = -1;
    //   *(int*)(this + 45388) = 1;
    //   return this;
    // UNRESOLVED: abi:lead names this function Audio_Subsystem_Initializer (LEGACY); canonical name AudioSubsystemInitializer retained.
    // UNRESOLVED: The existing analysis labels this a career-standings initializer, which conflicts with the 'audio' subsystem tag; the sub-block layout and the object type are not independently confirmed.
    // UNRESOLVED: Semantics of ArithmeticComparison_03c0 and StructInitWithDefaults are transcribed from names only; their internal behavior is unknown.
    // UNRESOLVED: The trailing scalar fields' meaning (sentinel -1, flag values 0/1) is described from the assigned literals only.
}
