// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005471D0
// Canonical corpus name: SwitchBasedFloatSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SwitchBasedFloatSetter_005471d0.c

void UnknownObject::SwitchBasedFloatSetter()
{
    // Channel-indexed float setter. Dispatches on index a2 via jump table jpt_5471DA (0x00547224); for a2 in 1..4 it stores the integer a3 scaled by the float constant 0.0039215689 (~1/255) into one of four float fields selected by channel (this+0x60, this+0x50, this+0x70, this+0x80 for channels 1..4). The default case writes nothing. Every path returns result = a2 - 1. Called by ConstructorInputControlInit (0x00546250).
    // CALCULATION: Compute result = a2 - 1, the value returned from every path [source:raw]
    // GUARD: Switch dispatch on channel index a2 via jump table jpt_5471DA (0x00547224); only a2 in 1..4 reach a field write, the default case returns result without writing any field [global:0x00547224, source:raw]
    // ASSIGNMENT: Case 1: store (double)a3 * 0.0039215689 into this[24] (this+0x60) [field:this:0x00000060, global:0x0059E460, source:raw]
    // ASSIGNMENT: Case 2: store (double)a3 * 0.0039215689 into this[20] (this+0x50) [field:this:0x00000050, global:0x0059E460, source:raw]
    // ASSIGNMENT: Case 3: store (double)a3 * 0.0039215689 into this[28] (this+0x70) [field:this:0x00000070, global:0x0059E460, source:raw]
    // ASSIGNMENT: Case 4: store (double)a3 * 0.0039215689 into this[32] (this+0x80) [field:this:0x00000080, global:0x0059E460, source:raw]
    // RETURN: Return result (a2 - 1) from every path; the function is invoked by ConstructorInputControlInit (0x00546250) [function:0x005471D0, caller:0x00546250, source:raw]

    // Conservative worker pseudocode:
    //   result = a2 - 1;
    //   switch (a2) {
    //     case 1: this[24] = (double)a3 * 0.0039215689; break;
    //     case 2: this[20] = (double)a3 * 0.0039215689; break;
    //     case 3: this[28] = (double)a3 * 0.0039215689; break;
    //     case 4: this[32] = (double)a3 * 0.0039215689; break;
    //     default: return result;
    //   }
    //   return result;
    // UNRESOLVED: The object owning the four float fields (this+0x50/0x60/0x70/0x80) is unidentified; the sole caller ConstructorInputControlInit (0x00546250) suggests an input-control setup path but no owner class is established
    // UNRESOLVED: The semantic role of the four channel fields is not independently confirmed; the existing analysis labels them color/alpha channels (DERIVED), and the constant 0.0039215689 equals approximately 1/255, scaling a3 into the 0..1 range
    // UNRESOLVED: Read-only float constant flt_59E460 (0.0039215689) is loaded from a global; its exact purpose as an external constant is not verifiable from this function alone
}
