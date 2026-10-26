// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00589278
// Canonical corpus name: CallWrapperWith0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CallWrapperWith0_00589278.c

void UnknownObject::CallWithZeroFourthArg()
{
    // Forwarding wrapper: passes a1, a2 and a3 plus the constant 0 as a fourth argument to sub_58928F (0x0058928F) and returns its int result.
    // CALL: Calls sub_58928F(a1, a2, a3, 0), forwarding the three arguments and appending the constant 0 as a fourth argument. [callee:0x0058928F, source:raw]
    // RETURN: Returns the int result of the forwarded call unchanged. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_589278(int a1, int a2, int a3) {
    //       return sub_58928F(a1, a2, a3, 0);
    //   }
    // UNRESOLVED: The meaning of the constant fourth argument 0 to sub_58928F (mode/flag selection) is not grounded in this packet.
    // UNRESOLVED: Owner is UnknownObject; the three callers sub_424080 (0x00424080, the .rcd parser), sub_559F00 (0x00559F00) and sub_593115 (0x00593115) are not analyzed.
}
