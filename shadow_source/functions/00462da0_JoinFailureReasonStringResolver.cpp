// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00462DA0
// Canonical corpus name: sub_462DA0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_462DA0_00462da0.c

void UnknownObject::JoinFailureReasonStringResolver()
{
    // Maps a join-failure code (a1) to a localized message string via the jump table at jpt_462DAA. Switch on a1: 1 -> aIncompatibleGa, 2 -> aTheGameIsFull, 3 -> aGameClosed, 4 -> aBadPassword, 5 -> aJoinTimedOut; any other value -> aNoJoinFailure. Every input resolves to a string, so there is no failure return path.
    // GUARD: Dispatch on a1 through the jump table at jpt_462DAA; cases 1-5 select specific strings and the default case catches everything else. [global:0x00462DE4, source:raw]
    // ASSIGNMENT: a1 == 1: select aIncompatibleGa (Incompatible Game). [global:0x005C6274]
    // ASSIGNMENT: a1 == 2: select aTheGameIsFull (The Game is Full). [global:0x005C6260]
    // ASSIGNMENT: a1 == 3: select aGameClosed (Game Closed). [global:0x005C6250]
    // ASSIGNMENT: a1 == 4: select aBadPassword (Bad Password). [global:0x005C6240]
    // ASSIGNMENT: a1 == 5: select aJoinTimedOut (Join Timed Out). [global:0x005C6230]
    // ASSIGNMENT: default: select aNoJoinFailure (No Join Failure). [global:0x005C621C]
    // RETURN: Return the selected string pointer. [source:raw]

    // Conservative worker pseudocode:
    //   char *sub_462DA0(int a1) {
    //     switch (a1) {
    //       case 1: return aIncompatibleGa;
    //       case 2: return aTheGameIsFull;
    //       case 3: return aGameClosed;
    //       case 4: return aBadPassword;
    //       case 5: return aJoinTimedOut;
    //       default: return aNoJoinFailure;
    //     }
    //   }
    // UNRESOLVED: Whether the selected strings are rendered directly or are subject to further translation downstream is not established by this packet.
    // UNRESOLVED: The string globals carry corpus symbol names only; their localized display text is not verified here.
}
