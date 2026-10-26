// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004533A0
// Canonical corpus name: GlobalStateInitializerWithEnumValues
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GlobalStateInitializerWithEnumValues_004533a0.c

void UnknownObject::GlobalStateInitializerWithEnumValues()
{
    // Configures global state by calling ThunkToFUN004530a0 (callee 0x00453370) with (state index, mode) pairs. A fixed sequence sets states 3,2,0,1,4,5,6 to mode 2, then a loop sets states 26..33 to mode 2 when byte_7D1370 equals 1 else mode 0, followed by a long fixed sequence of index/mode pairs, ending with index 43 mode 2 whose result is returned.
    // CALL: Call init with states 3, 2, 0, 1, 4, 5, 6, each with mode 2. [callee:0x00453370, source:raw]
    // LOOP: Loop over state indices 26 through 33 inclusive, calling init for each. [callee:0x00453370, source:raw]
    // GUARD: Inside the 26..33 loop: use mode 2 when byte_7D1370 equals 1, otherwise mode 0. [global:0x007D1370, source:raw]
    // CALL: Call init with states 7, 21, 19, 20, each with mode 2. [callee:0x00453370, source:raw]
    // CALL: Call init with states 17 and 18 with mode 1, and states 16 and 23 with mode 0. [callee:0x00453370, source:raw]
    // CALL: Call init with state 8 mode 1, state 9 mode 0, and states 10, 11, 12, 13 with mode 1. [callee:0x00453370, source:raw]
    // CALL: Call init with remaining fixed pairs: 25->0, 34->2, 24->0, 14->2, 15->2, 22->0, 35->0, 36->0, 37->2, 38->0, 39->2, 40->2, 41->2, 42->2. [callee:0x00453370, source:raw]
    // RETURN: Return the result of the final init call for state 43 with mode 2. [callee:0x00453370, function:0x004533A0, source:raw]

    // Conservative worker pseudocode:
    //   init(this, 3, 2); init(this, 2, 2); init(this, 0, 2);
    //   init(this, 1, 2); init(this, 4, 2); init(this, 5, 2);
    //   init(this, 6, 2);
    //   for (i = 26; i <= 33; ++i)
    //       init(this, i, byte_7D1370 == 1 ? 2 : 0);
    //   init(this, 7, 2); init(this, 21, 2); init(this, 19, 2);
    //   init(this, 20, 2);
    //   init(this, 17, 1); init(this, 18, 1);
    //   init(this, 16, 0); init(this, 23, 0);
    //   init(this, 8, 1); init(this, 9, 0);
    //   init(this, 10, 1); init(this, 11, 1);
    //   init(this, 12, 1); init(this, 13, 1);
    //   init(this, 25, 0); init(this, 34, 2);
    //   init(this, 24, 0); init(this, 14, 2); init(this, 15, 2);
    //   init(this, 22, 0); init(this, 35, 0); init(this, 36, 0);
    //   init(this, 37, 2); init(this, 38, 0);
    //   init(this, 39, 2); init(this, 40, 2); init(this, 41, 2);
    //   init(this, 42, 2);
    //   return init(this, 43, 2);
    // UNRESOLVED: Meaning of the state indices (0..43) as an enum is not confirmed.
    // UNRESOLVED: Meaning of the mode values (0/1/2) is not confirmed; the second argument may select enablement/value.
    // UNRESOLVED: Purpose of byte_7D1370 gating only indices 26..33 is unknown.
    // UNRESOLVED: Semantics of callee 0x00453370 (named ThunkToFUN004530a0) are not established.
}
