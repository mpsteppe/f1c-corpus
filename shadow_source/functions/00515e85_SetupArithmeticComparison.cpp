// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00515E85
// Canonical corpus name: ArithmeticComparison_5e85
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArithmeticComparison_5e85_00515e85.c

void UnknownObject::SetupArithmeticComparison()
{
    // Initializes an embedded arithmetic-comparison sub-object at this+0x18C: stores the UIScreenStateMachine symbol pointer into sub-object word 0, clears its two byte flags, sets its active byte to 1, dispatches the object vtable init at obj+0x10, invokes the first function-table entry at this+0x190, then clears the result/completion dword at this+0x8C and returns the dispatch result.
    // ASSIGNMENT: Load the sub-object pointer from this+0x18C. [field:this:0x0000018C]
    // ASSIGNMENT: Store the UIScreenStateMachine symbol pointer into sub-object word 0. [field:*(this+0x18C):0x00000000, global:0x00515DF2]
    // ASSIGNMENT: Clear the sub-object byte flags at +0x10 and +0x11. [field:*(this+0x18C):0x00000010, field:*(this+0x18C):0x00000011]
    // ASSIGNMENT: Set the sub-object active/enabled byte at +0x14 to 1. [field:*(this+0x18C):0x00000014]
    // CALL: Dispatch the object vtable entry at obj+0x10 (4th entry, virtual init) with this. [field:this:0x00000000, field:obj:0x00000010]
    // CALL: Invoke the first function-table entry at this+0x190 with this and capture its result. [field:this:0x00000190, field:*(this+0x190):0x00000000]
    // ASSIGNMENT: Clear the result/completion dword at this+0x8C to 0. [field:this:0x0000008C]
    // RETURN: Return the result captured from the this+0x190 dispatch. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_515E85(ObjectOwner* this) {
    //     ArithSub* sub = (ArithSub*)this->sub;             // this+0x18C
    //     sub->screen = &UIScreenStateMachine;              // sub+0x0
    //     sub->flagA = 0; sub->flagB = 0;                   // sub+0x10 / sub+0x11
    //     sub->active = 1;                                  // sub+0x14
    //     this->obj->init(this);                            // obj vtable +0x10
    //     int result = this->table[0](this);                // this+0x190 first entry
    //     this->resultState = 0;                            // this+0x8C
    //     return result;
    //   }
    // UNRESOLVED: The semantics of the UIScreenStateMachine pointer stored into the sub-object and of the this+0x190 dispatch result are not defined here.
}
