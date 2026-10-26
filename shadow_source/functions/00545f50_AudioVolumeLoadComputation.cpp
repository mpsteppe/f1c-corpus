// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00545F50
// Canonical corpus name: AudioVolumeLoadComputation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AudioVolumeLoadComputation_00545f50.c

void UnknownObject::AudioVolumeLoadComputation()
{
    // Computes an audio buffer load ratio and passes it to a stored callback. Returns 0 immediately if the callback pointer dword_8B8F00 is null. Otherwise dispatches on buffer state dword_8B8EF8: case 1 computes (1 - dword_8B8EE8/dword_8B8EF0) * 20.0, case 2 computes (1 - Addend/dword_8B8EF4) * 80.0 + 20.0; both clamp to return 0 when the value is below 0.25, else pass the float to the callback. Case 3 passes literal 1120403456 to the callback. Default returns 0.
    // GUARD: If dword_8B8F00 (callback pointer) is null, return 0 immediately. [global:0x008B8F00]
    // CALCULATION: Dispatch on dword_8B8EF8 (buffer ready state) via jump table jpt_545F6C with cases 1, 2, 3 and a default. [global:0x008B8EF8, global:0x00545FF8]
    // CALCULATION: Case 1: v1 = (1.0 - (double)dword_8B8EE8 / (double)dword_8B8EF0) * 20.0. [global:0x008B8EE8, global:0x008B8EF0]
    // GUARD: Case 1: if v1 < 0.25, return 0; otherwise fall through to the callback invocation. [source:raw]
    // CALCULATION: Case 2: v1 = (1.0 - (double)Addend / (double)dword_8B8EF4) * 80.0 + 20.0. [global:0x008B8EEC, global:0x008B8EF4]
    // GUARD: Case 2: if v1 < 0.25, return 0; otherwise fall through to the callback invocation. [source:raw]
    // CALL: Cases 1 and 2: v3 = v1, then invoke the callback dword_8B8F00(0, LODWORD(v3)). [global:0x008B8F00, source:raw]
    // CALL: Case 3: invoke the callback dword_8B8F00(0, 1120403456). [global:0x008B8F00, source:raw]
    // RETURN: Return 0 after a handled case (result = 0); default case also returns 0. [source:raw]

    // Conservative worker pseudocode:
    //   if (!dword_8B8F00) return 0;
    //   switch (dword_8B8EF8) {
    //     case 1: v1 = (1.0 - (double)dword_8B8EE8 / (double)dword_8B8EF0) * 20.0;
    //             if (v1 < 0.25) return 0;
    //             v3 = v1; dword_8B8F00(0, LODWORD(v3)); break;
    //     case 2: v1 = (1.0 - (double)Addend / (double)dword_8B8EF4) * 80.0 + 20.0;
    //             if (v1 < 0.25) return 0;
    //             v3 = v1; dword_8B8F00(0, LODWORD(v3)); break;
    //     case 3: dword_8B8F00(0, 1120403456); break;
    //     default: return 0;
    //   }
    //   return 0;
    // UNRESOLVED: Globals flt_59E43C, flt_59E7F8, flt_59E8EC, flt_59E990 appear in the packet globals list as reads but are absent from the decompiled source; likely folded/optimized references, placed in unresolved_evidence_refs.
    // UNRESOLVED: Meaning of the callback's two arguments and of literal 1120403456 is not confirmed beyond the raw spelling.
}
