// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042E470
// Canonical corpus name: EventTriggerOnStateChange
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/EventTriggerOnStateChange_0042e470.c

void UnknownObject::EventTriggerOnStateChange()
{
    // State-change event trigger on a tracked entity. Compares the entity ID dwords at a2+16 and a3+16; when they match, reads the state dword at a2+20 and, if a3+20 differs, copies the new state into a3+20 and raises the trigger flags at this+0x0 and this+0x19A4 to 1. Returns a2 (or the matched state value). Called from TrackConfig (0042E530) and AIGearSelectionSet (0042EAA0) on the per-frame path.
    // ASSIGNMENT: result = a2: initialize the return value with the reference entity pointer [source:raw]
    // GUARD: Guard on entity ID match: proceed only when *(a2+16) equals *(a3+16); otherwise return result without action [source:raw]
    // ASSIGNMENT: result = *(a2+20): read the reference entity state field [source:raw]
    // GUARD: Guard on state change: proceed only when *(a3+20) differs from the reference state [source:raw]
    // ASSIGNMENT: *(a3+20) = result: copy the reference state into the current entity [source:raw]
    // ASSIGNMENT: this[0x19A4] = 1: raise the state-change-detected flag on the trigger object [field:this:0x000019A4, source:raw]
    // ASSIGNMENT: this[0x0] = 1: raise the event-trigger flag at the start of the trigger object [field:this:0x00000000, source:raw]
    // RETURN: Return result (the reference state value copied to the current entity) [source:raw]
    // CALL: Invoked from TrackConfig (0042E530) on the per-frame tick path [caller:0x0042E530]
    // CALL: Invoked from AIGearSelectionSet (0042EAA0) on the per-frame tick path [caller:0x0042EAA0]

    // Conservative worker pseudocode:
    //   int EventTriggerOnStateChange(_BYTE *this, int a2, int a3) {
    //     int result = a2;
    //     if (*(_DWORD *)(a2 + 16) == *(_DWORD *)(a3 + 16)) {
    //       result = *(_DWORD *)(a2 + 20);
    //       if (*(_DWORD *)(a3 + 20) != result) {
    //         *(_DWORD *)(a3 + 20) = result;
    //         this[6564] = 1;
    //         this[0] = 1;
    //       }
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Semantic roles of the entity ID at +16 and the state at +20 are inferred from the guard structure; the raw source gives no type or meaning for these offsets.
    // UNRESOLVED: The trigger object owner is unproven; this[0x0] and this[0x19A4] semantics (eventTriggerFlag / stateChangeDetectedFlag) come only from the existing analysis.
}
