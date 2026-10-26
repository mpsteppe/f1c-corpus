// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042AF40
// Canonical corpus name: AIStateReset
// Owner: F1CVehicle [DERIVED]
// Raw source: functions/AIStateReset_0042af40.c

void F1CVehicle::AIStateReset()
{
    // Unconditional AI driver state reset (__thiscall on a vehicle object). Notifies the state-change event handler StateChangeNotify with argument 0, evaluates ConditionalGate at this+12 (the return value is also the function result), sets the byte flag at this+0x4410 to 1 and the byte flag at this+0x45F4 to 0, then returns the gate result. No guards: both flags are overwritten on every call.
    // CALL: Notify the state-change event handler: StateChangeNotify(0). [callee:0x004A5C80, source:raw]
    // CALL: Evaluate the conditional gate at this+12 via ConditionalGate(this + 12); the returned value is stored and later returned. [callee:0x004EFAC0, source:raw]
    // ASSIGNMENT: Set the byte flag at this+0x4410 (this[17424]) to 1. [field:this:0x00004410, source:raw]
    // ASSIGNMENT: Clear the byte flag at this+0x45F4 (this[17908]) to 0. [field:this:0x000045F4, source:raw]
    // RETURN: Return the result of ConditionalGate(this + 12). [source:raw]

    // Conservative worker pseudocode:
    //   StateChangeNotify(0);
    //   result = ConditionalGate(this + 12);
    //   this[17424] = 1;
    //   this[17908] = 0;
    //   return result;
    // UNRESOLVED: The packet does not name the owner type; the F1CVehicle owner is DERIVED from the fills (this-relative vehicle flags RetiredFlag at +0x4410 and ActiveFlag at +0x45F4) and the PitCrewStateMachine caller, not from packet evidence.
    // UNRESOLVED: The semantics of the ConditionalGate argument this+12 and what the returned value means to the caller are not evidenced in this packet.
    // UNRESOLVED: StateChangeNotify(0) argument semantics (event type 0) are not described by the packet.
}
