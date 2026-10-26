// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D4800
// Canonical corpus name: StateGetSetWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StateGetSetWrapper_004d4800.c

void UnknownObject::StateGetSetWrapper()
{
    // State read/modify wrapper: reads an array-state value, delegates once with a mode argument of 2, re-reads the array-state value, delegates a second time passing the first read value with a mode argument of 0, then returns the second read value. The two reads bracket a state-setting call that uses a fixed mode.
    // CALL: v2 = ArrayStateRead(this): read the current array state via 0x004D47E0. [callee:0x004D47E0, source:raw]
    // CALL: Delegation_47c0(this, 0, 2): delegate to 0x004D47C0 with a fixed mode of 2 and argument 0. [callee:0x004D47C0, source:raw]
    // CALL: v3 = ArrayStateRead(this): re-read the array state via 0x004D47E0 after the delegation. [callee:0x004D47E0, source:raw]
    // CALL: Delegation_47c0(this, v2, 0): delegate to 0x004D47C0 again, passing the earlier read value v2 with a mode of 0. [callee:0x004D47C0, source:raw]
    // RETURN: Return v3, the array state re-read after the second delegation. [source:raw]

    // Conservative worker pseudocode:
    //   int StateGetSetWrapper(void* this) {
    //     int v2 = ArrayStateRead(this);
    //     Delegation_47c0((int)this, 0, 2);
    //     int v3 = ArrayStateRead(this);
    //     Delegation_47c0((int)this, v2, 0);
    //     return v3;
    //   }
    // UNRESOLVED: Meaning of the Delegation_47c0 mode arguments 0 and 2 (likely an enum) is not established here.
    // UNRESOLVED: Purpose of the double ArrayStateRead and why the first value v2 is passed back into the second delegation is unknown.
    // UNRESOLVED: The object behind 'this' and what array state it represents is unnamed.
}
