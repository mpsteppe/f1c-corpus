// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00564530
// Canonical corpus name: StringComparisonWithConstantDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringComparisonWithConstantDispatch_00564530.c

void UnknownObject::StringComparisonWithConstantDispatch()
{
    // String-keyed dispatch. If a2 equals the literal "ping", returns ShortToIntFieldGetter(a1), reading a short field from a1 as an int. Otherwise dispatches through DoubleCallWrapper(a1, a2); when it returns non-null, returns the result of SingleFunctionCallWrapper_7f59 on v4[1]; when null, returns the default value a3. Called by SendJoinRequest (00462C00) and sub_563F20 (00563F20).
    // GUARD: Compares a2 against the "ping" string constant (aPing) and takes the ping-handler path when they match [global:0x005C61EC, source:raw]
    // CALL: On the ping path, calls ShortToIntFieldGetter(a1) which reads a short field from a1 and returns it as the function result [callee:0x00564480, source:raw]
    // CALL: Otherwise dispatches through DoubleCallWrapper(a1, a2), which resolves a two-argument callable and returns a result pointer v4 [callee:0x005644F0, source:raw]
    // GUARD: When v4 is non-null, calls SingleFunctionCallWrapper_7f59(v4[1]) and returns its int result [callee:0x00587F59, source:raw]
    // RETURN: When the dispatch wrapper returns null, falls back to returning the default value a3 [source:raw]
    // CALL: Used by SendJoinRequest (00462C00) and sub_563F20 (00563F20) as a string-dispatch helper [caller:0x00462C00, caller:0x00563F20, source:raw]

    // Conservative worker pseudocode:
    //   if (strcmp(a2, "ping") == 0)
    //     return ShortToIntFieldGetter(a1);
    //   v4 = DoubleCallWrapper(a1, a2);
    //   if (v4)
    //     return SingleFunctionCallWrapper_7f59(v4[1]);
    //   return a3;
    // UNRESOLVED: The meaning of the a1 context pointer and the dispatch namespace behind DoubleCallWrapper are not established from this packet
}
