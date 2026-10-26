// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059988B
// Canonical corpus name: FunctionCallWrapper_988b
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FunctionCallWrapper_988b_0059988b.c

void UnknownObject::ForwarderGlobalToBool()
{
    // Trivial delegation thunk: reads the global ForwarderToSub5998A1 and forwards its value as the integer argument to BooleanToIntConversion, returning the conversion result directly. No branches, no local state.
    // ASSIGNMENT: Load the global ForwarderToSub5998A1 from 0x00599897 as the integer argument passed to the callee. [global:0x00599897]
    // CALL: Call BooleanToIntConversion with the loaded global value as its sole argument. [callee:0x00587B3E, source:raw]
    // RETURN: Return the result of BooleanToIntConversion unchanged. [source:raw]

    // Conservative worker pseudocode:
    //   int ForwarderGlobalToBool() {
    //     return BooleanToIntConversion((int)ForwarderToSub5998A1);
    //   }
    // UNRESOLVED: Semantic role of the global ForwarderToSub5998A1 (value interpreted as a boolean by the callee) is caller-dependent and unknown here.
}
