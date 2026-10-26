// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059083B
// Canonical corpus name: Ctrandisp1CRTFloatDisplayFormat
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Ctrandisp1CRTFloatDisplayFormat_0059083b.c

void UnknownObject::CRTFloatDisplayFormat()
{
    // CRT float display-format wrapper in the Trandisp1 module. Loads the double argument a1 into the x87 float stack through CRTFload, calls Trandisp1 passing the loaded value together with register-sourced arguments (v2/edx, v3/cx, v4/fps) and the address of the saved-register frame, then calls sub_590703 on that same frame and returns its result. No callers are recorded, so the display context is unknown.
    // CALL: Load the double argument a1 through CRTFload into the x87 float value v1 (st7). [callee:0x0059086E, source:raw]
    // CALL: Call Trandisp1 with the register-sourced arguments v2 (edx), v3 (cx), v4 (fps), the address of the saved-register frame savedregs and the loaded float v1. [callee:0x0058DA70, source:raw]
    // CALL: Call sub_590703 with the saved-register frame address savedregs to derive the final result. [callee:0x00590703, source:raw]
    // RETURN: Return the result of sub_590703 directly; the function has no other side effect. [function:0x0059083B, source:raw]

    // Conservative worker pseudocode:
    //   double v1 = CRTFload(a1);
    //   Trandisp1(v2, v3, &savedregs, v4, v1);
    //   return sub_590703(&savedregs);
    // UNRESOLVED: Arguments v2 (edx), v3 (cx) and v4 (fps) are consumed by Trandisp1 but never initialized in this function; their provenance is unknown from this packet.
    // UNRESOLVED: The role of sub_590703 and the layout of the saved-register frame threaded through Trandisp1 are not established.
    // UNRESOLVED: No callers are recorded, so the display context and the meaning of the double argument cannot be confirmed.
}
