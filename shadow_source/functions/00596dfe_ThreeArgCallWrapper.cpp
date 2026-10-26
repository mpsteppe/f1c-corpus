// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00596DFE
// Canonical corpus name: ThreeArgCallWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ThreeArgCallWrapper_00596dfe.c

void UnknownObject::ThreeArgCallWrapper()
{
    // Trivial cdecl forwarding wrapper: passes its single char argument a1 plus the fixed arguments 0 and 4 to sub_596E0F and returns the result unchanged. Legacy ABI name Three_Arg_Call_Wrapper matches the shape; the meaning of the fixed arguments is owned by sub_596E0F.
    // CALL: Forward a1 to sub_596E0F together with the constant arguments 0 and 4. [callee:0x00596E0F, source:raw]
    // RETURN: Return the int result of sub_596E0F unchanged. [source:raw]
    // CALL: Invoked from sub_592A9C (0x00592A9C) as the only caller. [caller:0x00592A9C, source:raw]

    // Conservative worker pseudocode:
    //   int sub_596DFE(char a1) {
    //     return sub_596E0F(a1, 0, 4);
    //   }
    // UNRESOLVED: Meaning of the fixed arguments 0 and 4 depends on sub_596E0F's contract, which is outside this packet.
    // UNRESOLVED: Why a1 is a char and how it is used by sub_596E0F is unknown here.
}
