// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044C680
// Canonical corpus name: SpatialNodeInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SpatialNodeInit_0044c680.c

void UnknownObject::SpatialNodeInit()
{
    // Unconditional initialization of four global spatial-node parameters: dword_7CCA44 set to 2, flt_7CCA48 set to 0.0, dword_7CCA4C set to -1082130432 (per skeleton analysis interpreted as a -1.0f sentinel), and flt_7CCA50 set to 0.0.
    // ASSIGNMENT: Set dword_7CCA44 to 2 (node element count). [abi:lead, function:0x0044C680, global:0x007CCA44]
    // ASSIGNMENT: Set flt_7CCA48 to 0.0. [global:0x007CCA48, source:raw]
    // ASSIGNMENT: Set dword_7CCA4C to -1082130432 (skeleton analysis: -1.0f radius/sentinel value). [global:0x007CCA4C]
    // ASSIGNMENT: Set flt_7CCA50 to 0.0. [global:0x007CCA50]

    // Conservative worker pseudocode:
    //   void SpatialNodeInit() {
    //     dword_7CCA44 = 2;
    //     flt_7CCA48 = 0.0f;
    //     dword_7CCA4C = -1082130432;
    //     flt_7CCA50 = 0.0f;
    //   }
    // UNRESOLVED: Semantic role of the four globals dword_7CCA44/flt_7CCA48/dword_7CCA4C/flt_7CCA50 and their owning subsystem is unknown.
}
