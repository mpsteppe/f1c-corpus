// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00542420
// Canonical corpus name: TwoCallDelegation_2420
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TwoCallDelegation_2420_00542420.c

void UnknownObject::TwoCallDelegation()
{
    // Thin delegation: calls F_3FieldGetter(a4, a5, a6) first, then returns the result of TripleFieldGetter_2460(a1, a2, a3). All six arguments are passed through unchanged to the two getter callees; no value is computed here.
    // CALL: Call F_3FieldGetter(a4, a5, a6); the return value is discarded. [callee:0x00542490, source:raw]
    // CALL: Call TripleFieldGetter_2460(a1, a2, a3); its result becomes the function result. [callee:0x00542460, source:raw]
    // RETURN: Return the value produced by TripleFieldGetter_2460. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_542420(int a1, int a2, int a3, int a4, int a5, int a6) {
    //     F_3FieldGetter(a4, a5, a6);
    //     return TripleFieldGetter_2460(a1, a2, a3);
    //   }
    // UNRESOLVED: Semantics of the three getter fields behind TripleFieldGetter_2460 and the F_3FieldGetter call are not visible here.
    // UNRESOLVED: Argument meaning depends on the caller sites (MainCameraDirectorUpdate 0x0040CA30, sub_466350).
    // UNRESOLVED: Owner class is unknown; the six-argument stdcall shape suggests a forwarding helper.
}
