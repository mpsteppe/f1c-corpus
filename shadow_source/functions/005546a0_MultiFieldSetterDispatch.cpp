// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005546A0
// Canonical corpus name: MultiFieldSetterDispatchingTo7SubSetters
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MultiFieldSetterDispatchingTo7SubSetters_005546a0.c

void UnknownObject::MultiFieldSetterDispatch()
{
    // Orchestrator: writes this[0] from a3, then dispatches to 7 sub-setter calls using consecutive dword values a2[8]..a2[14]. Each sub-setter receives the same this pointer plus one a2 element; no early-exit guards in this function.
    // ASSIGNMENT: Set this[0] (object state/ID) to a3. [field:this:0x00000000, source:raw]
    // CALL: Call sub_553FC0(this, a2[8]) - primary state machine transition handler (field group 1). [callee:0x00553FC0, source:raw]
    // CALL: Call sub_5542F0(this, a2[9]) - secondary state machine transition handler (field group 2). [callee:0x005542F0, source:raw]
    // CALL: Call SetterWithNotification(this, a2[10]) - state setter with notification. [callee:0x005545E0, source:raw]
    // CALL: Call sub_554560(this, a2[12]) - state setter with conditional routing. [callee:0x00554560, source:raw]
    // CALL: Call StateParameterSetterWithVirtualDeviceNotify(this, a2[11]) - parameter setter via virtual device notify. [callee:0x00554610, source:raw]
    // CALL: Call GameStateSettingViaVirtualDispatch(this, a2[13]) - game state setting via virtual dispatch. [callee:0x005544C0, source:raw]
    // CALL: Call EnumToIDMappingWithVTableNotify(this, a2[14]) - enum-to-ID mapping with vtable notify. [callee:0x00554510, source:raw]

    // Conservative worker pseudocode:
    //   void MultiFieldSetterDispatch(this, a2, a3) {
    //     this[0] = a3;
    //     sub_553FC0(this, a2[8]);
    //     sub_5542F0(this, a2[9]);
    //     SetterWithNotification(this, a2[10]);
    //     sub_554560(this, a2[12]);
    //     StateParameterSetterWithVirtualDeviceNotify(this, a2[11]);
    //     GameStateSettingViaVirtualDispatch(this, a2[13]);
    //     EnumToIDMappingWithVTableNotify(this, a2[14]);
    //   }
    // UNRESOLVED: Semantic meaning of a2[8..14] and of each sub-setter's target field is owned by the callees, not this orchestrator.
}
