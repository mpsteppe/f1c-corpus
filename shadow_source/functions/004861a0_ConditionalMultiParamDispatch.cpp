// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004861A0
// Canonical corpus name: ConditionalMultiParamDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalMultiParamDispatch_004861a0.c

void UnknownObject::ConditionalMultiParamDispatch()
{
    // Conditional two-channel dispatch. If the low byte of a1 is nonzero, TwinFieldGetter (0x00499EE0) fills v3 from a1, and when both a1 and v3 are positive PositionUpdate (0x0049AA70) runs. Then, if the low byte of a2 is nonzero, TwoChannel16BitReader (0x00499F00) fills a1, v4, v3 and a2, and if any of them is nonzero the function returns MultiFieldStructWriter (0x0049AA10) applied to the four values. Otherwise it returns the trailing result value (a2, then a1). Called from sub_492A40 (0x00492A40).
    // GUARD: If the low byte of a1 is nonzero, enter the first dispatch path. [source:raw]
    // CALL: Call TwinFieldGetter (0x00499EE0) with pointers to a1 and the local v3, reading two related fields out of a1. [callee:0x00499EE0]
    // GUARD: Only if a1 > 0 and v3 > 0, invoke PositionUpdate. [source:raw]
    // CALL: Call PositionUpdate (0x0049AA70) with the two positive values a1 and v3. [callee:0x0049AA70, source:raw]
    // ASSIGNMENT: Default the return value to a2 before evaluating the second channel. [source:raw]
    // GUARD: If the low byte of a2 is nonzero, enter the second dispatch path. [source:raw]
    // CALL: Call TwoChannel16BitReader (0x00499F00) with pointers to a1, v4, v3 and a2, refilling all four values. [callee:0x00499F00]
    // ASSIGNMENT: After the read, set the return value to a1. [source:raw]
    // GUARD: If any of a1, v4, v3 or a2 is nonzero, short-circuit with the MultiFieldStructWriter result. [source:raw]
    // CALL: Call MultiFieldStructWriter (0x0049AA10) with a1, v4, v3 and a2 and return its value immediately. [callee:0x0049AA10, source:raw]
    // RETURN: Otherwise return the trailing result (a2 when the second channel never ran, else a1). [source:raw]

    // Conservative worker pseudocode:
    //   char sub_4861A0(int a1, int a2) {
    //     int v3, v4;
    //     if ((char)a1) {
    //       TwinFieldGetter(&a1, &v3);
    //       if (a1 > 0 && v3 > 0) PositionUpdate(a1, v3);
    //     }
    //     char result = (char)a2;
    //     if ((char)a2) {
    //       TwoChannel16BitReader(&a1, &v4, &v3, &a2);
    //       result = (char)a1;
    //       if (a1 || v4 || v3 || a2) return MultiFieldStructWriter(a1, v4, v3, a2);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Prelabel cluster-copy marks this as a structural twin of sub_45B5C0 (address 0045b5c0 in packet prelabel), trust DERIVED; the twin identity is not independently verified.
    // UNRESOLVED: Meaning of the two byte-gated channels a1/a2 and the fields handled by TwinFieldGetter, TwoChannel16BitReader and MultiFieldStructWriter is unknown.
    // UNRESOLVED: Why the return value transitions from a2 to a1 after the second read is not established.
}
