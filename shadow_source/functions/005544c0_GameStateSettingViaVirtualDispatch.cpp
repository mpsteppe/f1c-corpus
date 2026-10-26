// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005544C0
// Canonical corpus name: GameStateSettingViaVirtualDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GameStateSettingViaVirtualDispatch_005544c0.c

void UnknownObject::GameStateSettingViaVirtualDispatch()
{
    // Sets a game-state parameter on the global object at 0x008B89A0 via its vtable entry at offset 252. Skips entirely when a2 is -1 or equals the previously stored state this[14]. Maps a2 (0, 1, 2) to dispatch value (1, 3, 2) and records a2 into this[14] on change.
    // GUARD: Skip when a2 is -1 or when a2 already equals the stored previous state this[14] (offset 0x38). [field:this:0x00000038, function:0x005544C0, source:raw]
    // CALL: When a2 is 0, dispatch on the global object at 0x008B89A0 through vtable+252 with (*this, 13, 1). [global:0x008B89A0, field:this:0x00000000, source:raw]
    // CALL: When a2 is 1, dispatch on the global object at 0x008B89A0 through vtable+252 with (*this, 13, 3). [global:0x008B89A0, field:this:0x00000000, source:raw]
    // CALL: When a2 is 2, dispatch on the global object at 0x008B89A0 through vtable+252 with (*this, 13, 2). [global:0x008B89A0, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Record the new value a2 into this[14] (offset 0x38) after a successful dispatch. [field:this:0x00000038, source:raw]

    // Conservative worker pseudocode:
    //   void sub_5544C0(int *this, int a2) {
    //     if (a2 == -1 || a2 == this[14]) return;
    //     int v = (a2 == 1) ? 3 : (a2 == 2) ? 2 : 1;
    //     ((void (__stdcall *)(int, int, int, int))vtable252_of(*(int*)0x8B89A0))(*0x8B89A0, *this, 13, v);
    //     this[14] = a2;
    //   }
    // UNRESOLVED: The meaning of state parameter 13 and of the 1/3/2 value mapping is owned by the vtable+252 handler on the global object, not by this function.
    // UNRESOLVED: this[14] (offset 0x38) is compared and updated here but consumed elsewhere.
}
