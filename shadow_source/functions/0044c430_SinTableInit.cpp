// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044C430
// Canonical corpus name: SinTableInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SinTableInit_0044c430.c

void UnknownObject::SinTableInit()
{
    // Lookup-table initializer: fills a small sine table flt_7CA384 with sin(index * 0.2243994752564138) for indices 0 through 6 in a do-while loop, then writes 1.0 into dbl-indexed global dword_7CA388[7] and returns the final index (7). The step constant 0.2243994752564138 corresponds to the read-only double dbl_59EF50. Invoked from the scene-track-file loading path.
    // ASSIGNMENT: Initialize loop variables result = 0 and v2 = 0 before the loop. [source:raw]
    // LOOP: do-while loop that runs while result < 7, producing indices 0 through 6. [source:raw]
    // CALCULATION: Compute sin((double)v2 * 0.2243994752564138) using the angle-step constant from dbl_59EF50. [global:0x0059EF50, source:raw]
    // ASSIGNMENT: Write the computed sine value into flt_7CA384[result]. [global:0x007CA384, source:raw]
    // CALCULATION: Advance the loop counter: v2 = ++result. [source:raw]
    // ASSIGNMENT: After the loop ends (result == 7), write 1.0 into dword_7CA388[result]. [global:0x007CA388, source:raw]
    // RETURN: Return the final index result (7). [source:raw]
    // CALL: Called by SceneTrackFileLoader (0x0044C0E0) during scene-track file loading. [caller:0x0044C0E0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_44C430() {
    //     int result = 0;
    //     int v2 = 0;
    //     do {
    //       double ang = (double)v2 * 0.2243994752564138;
    //       v2 = ++result;
    //       flt_7CA384[result] = sin(ang);
    //     } while (result < 7);
    //     dword_7CA388[result] = 1.0;
    //     return result;
    //   }
    // UNRESOLVED: How the sine-table globals flt_7CA384 / dword_7CA388 are consumed by the scene-track renderer is unknown.
    // UNRESOLVED: Meaning of the trailing dword_7CA388[result] = 1.0 write (index 7) is not established.
    // UNRESOLVED: Why the angle step is 0.2243994752564138 (dbl_59EF50) and what angular range it represents is unknown.
}
