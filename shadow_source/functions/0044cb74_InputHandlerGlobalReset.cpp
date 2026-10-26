// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044CB74
// Canonical corpus name: InputHandlerGlobalReset
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/InputHandlerGlobalReset_0044cb74.c

void UnknownObject::InputHandlerGlobalReset()
{
    // Trivial void global-reset routine. Stores 0.0 into flt_7CD110 and the constant 1065353216 into dword_7CD114. No parameters, no guards, no calls, no return value.
    // ASSIGNMENT: Write the constant 0.0 into global flt_7CD110 [global:0x007CD110, source:raw]
    // ASSIGNMENT: Write the constant 1065353216 into global dword_7CD114 [global:0x007CD114, source:raw]
    // RETURN: Returns void immediately after the two stores [function:0x0044CB74, source:raw]

    // Conservative worker pseudocode:
    //   void InputHandlerGlobalReset() {
    //     flt_7CD110 = 0.0;
    //     dword_7CD114 = 1065353216;
    //   }
    // UNRESOLVED: The role of the two globals and the intended meaning of the 1065353216 constant are not evidenced by this packet
}
