// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00497940
// Canonical corpus name: LookupDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LookupDispatch_00497940.c

void UnknownObject::LookupDispatch()
{
    // Generic UI-list lookup dispatch bridge on `this`. When the lookup key a2 is non-zero, searches the owning list via UIListSearchByName_76c0 and, if a matching item handle is found (v4 non-zero), forwards it together with the pass-through argument a3 to UtilityFunction_7890, returning its result; otherwise returns 0. Used by 16 UI, menu, multiplayer and key-binding handlers as a single lookup-plus-dispatch entry point.
    // GUARD: If a2 (the lookup key) is non-zero, proceed to the search; otherwise fall through to return 0 [source:raw]
    // CALL: v4 = UIListSearchByName_76c0(this, a2): searches the UI list object `this` for the item matching key a2 and stores the resulting item handle in v4 [callee:0x004976C0, source:raw]
    // GUARD: If v4 (the found UI item handle) is non-zero, dispatch to the utility handler; otherwise return 0 [source:raw]
    // CALL: UtilityFunction_7890(this, v4, a3): invokes the utility handler with the owning object, the found UI item handle v4 and the pass-through argument a3, and returns its result [callee:0x00497890, source:raw]
    // RETURN: Return the result of UtilityFunction_7890 when a valid item was found, otherwise return 0 on any failed lookup [source:raw]
    // CALL: Invoked by 16 UI, menu, multiplayer and key-binding handlers (MainMenuTransition, ClientGridDisplayTimer, KeyBindingUIPressKeyOrController, MultiplayerSessionJoinHandler, GameMode, MultiplayerPasswordValidation, AutoJoinRetryLoop and others) as a generic lookup-plus-dispatch entry point [caller:0x00404F30, caller:0x0046B0C0, caller:0x0046D6D0, caller:0x0046DE10, caller:0x0046DD30, caller:0x004637A0]

    // Conservative worker pseudocode:
    //   int LookupDispatch(UIList* this, key_t a2, payload_t a3) {
    //       if (a2 == 0)
    //           return 0;
    //       item_t* v4 = UIListSearchByName_76c0(this, a2);
    //       if (v4 == 0)
    //           return 0;
    //       return UtilityFunction_7890(this, v4, a3);
    //   }
    // UNRESOLVED: The exact meanings of a2 (lookup key) and a3 (pass-through payload) are inferred from call context only and are not documented in this function
    // UNRESOLVED: The owning class of `this` and the precise semantics of the two untyped callees (UIListSearchByName_76c0, UtilityFunction_7890) are unknown
}
