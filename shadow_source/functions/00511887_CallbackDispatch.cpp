// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00511887
// Canonical corpus name: CallbackDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CallbackDispatch_00511887.c

void UnknownObject::CallbackDispatch()
{
    // Dispatches an optional per-object callback. Loads a function pointer from the receiver struct at offset 0x44 (this + 68); when non-null it is invoked with (receiver, argument) and its result returned, otherwise NULL is returned. An indirect-call-through-slot helper with no side effects on failure.
    // ASSIGNMENT: Load the callback function pointer from this + 0x44 (this + 68) into result. [field:this:0x00000044, source:raw]
    // GUARD: Guard on result: only invoke the callback when the loaded pointer is non-null; otherwise fall through and return the null result. [source:raw]
    // CALL: Indirect call of the loaded callback with the receiver and argument: result(a1, a2). [function:0x00511887, source:raw]
    // RETURN: Return the callback's result when a callback is installed, or NULL when it is not. [function:0x00511887, source:raw]
    // CALL: Invoked from ten call sites, including TwoStepDelegation (0x005118C1) and eight anonymous sub_* helpers. [caller:0x005118C1, caller:0x005121AE, caller:0x00513A71, caller:0x00513BF9, caller:0x00518511, caller:0x00518AAA, caller:0x00518BD4, caller:0x00518C1E, caller:0x00518D29, caller:0x00518E18]

    // Conservative worker pseudocode:
    //   Callback* CallbackDispatch(Obj* receiver, int arg) {
    //     Callback* cb = *(Callback**)((char*)receiver + 0x44);
    //     if (cb) return cb(receiver, arg);
    //     return cb;
    //   }
    // UNRESOLVED: The callback slot at offset 0x44 is a function pointer that is called with the receiver as first argument, but no callback registration site or owner type is evidenced in this packet.
    // UNRESOLVED: All callers except TwoStepDelegation are anonymous sub_* helpers, so the semantic context of the dispatch is not confirmed.
    // UNRESOLVED: The exact call convention of the stored callback (receiver as argument 1 vs. an implicit this) is not resolved.
}
