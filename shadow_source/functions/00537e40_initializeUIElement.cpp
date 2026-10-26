// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00537E40
// Canonical corpus name: UIElementInitialization
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIElementInitialization_00537e40.c

void UnknownObject::initializeUIElement()
{
    // Initializes an object: calls the stub EmptyStub_7eb0 (0x00537EB0), installs self-relative buffer pointers (this+0xB0E = this+138, this+0xB1A = this+2430, this+0xB26 = this+2674), stores two static table pointers (this+0xB16 = &off_5DA928, this+0xB22 = &off_5DA93C) and a pointer to unk_5DA950 (this+0xB2E), sets a capacity word at this+0x16A7 to 8, zeroes this+0x16AB (word) and this+0x16AD (dword), then returns the result of ScorecardZero(this) (named only in raw source; not present in callee evidence). Called by ConditionalMultiFieldReset (0x00535E10).
    // CALL: Call EmptyStub_7eb0() [callee:0x00537EB0, source:raw, function:0x00537E40]
    // ASSIGNMENT: this+0xB0E = this + 138 (self-relative buffer pointer) [field:this:0x00000B0E]
    // ASSIGNMENT: this+0xB1A = this + 2430 (self-relative buffer pointer) [field:this:0x00000B1A]
    // ASSIGNMENT: this+0xB16 = &off_5DA928 (static data pointer) [field:this:0x00000B16, global:0x005DA928]
    // ASSIGNMENT: this+0xB22 = &off_5DA93C (static data pointer) [field:this:0x00000B22, global:0x005DA93C]
    // ASSIGNMENT: this+0xB26 = this + 2674 (self-relative buffer pointer) [field:this:0x00000B26]
    // ASSIGNMENT: this+0xB2E = &unk_5DA950 (pointer to unlabeled static data) [field:this:0x00000B2E, global:0x005DA950]
    // ASSIGNMENT: this+0x16AB (word) = 0 [field:this:0x000016AB]
    // ASSIGNMENT: this+0x16AD (dword) = 0 [field:this:0x000016AD]
    // ASSIGNMENT: this+0x16A7 (dword) = 8 (capacity/size field) [field:this:0x000016A7]
    // CALL: Return the result of ScorecardZero(this); the target has no callee evidence record in this packet and is named only in the raw source [source:raw, abi:lead]

    // Conservative worker pseudocode:
    //   int initializeUIElement(int *this) {
    //       EmptyStub_7eb0();
    //       *(this + 2830) = this + 138;
    //       *(this + 2842) = this + 2430;
    //       *(this + 2838) = &off_5DA928;
    //       *(this + 2850) = &off_5DA93C;
    //       *(this + 2854) = this + 2674;
    //       *(this + 2862) = &unk_5DA950;
    //       *(short*)(this + 5803) = 0;
    //       *(this + 5805) = 0;
    //       *(this + 5799) = 8;
    //       return ScorecardZero(this);
    //   }
    // UNRESOLVED: Object class unknown; semantics of the self-relative pointers, the two static tables, and unk_5DA950 are not established. The ScorecardZero call target is not in the packet callee evidence, so its address is unknown.
    // UNRESOLVED: Existing analysis prose labels this an audio codec / D3D initialization; that semantic interpretation is not adopted as fact here.
}
