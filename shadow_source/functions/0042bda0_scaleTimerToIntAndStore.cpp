// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042BDA0
// Canonical corpus name: TimerConversionWithSin
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TimerConversionWithSin_0042bda0.c

void UnknownObject::scaleTimerToIntAndStore()
{
    // Scales a double timer input a1 by 400.0, feeds the scaled value to sub_5895A2 (a trigonometric/float helper with a side effect), converts the scaled value to an integer via CRTFtol, stores that integer into the global dword_7C5694, and returns it. Called by RunCollisionDetectionLoop (0045f390) and SessionSynchronizer (0045f950).
    // CALCULATION: Compute a1 * 400.0 once as the scaled value [source:raw]
    // CALL: Call sub_5895A2 with the scaled value a1 * 400.0 (float helper with side effect) [callee:0x005895A2, source:raw]
    // CALL: Call CRTFtol on the scaled value a1 * 400.0 to convert the double to an integer [callee:0x00587BDC, source:raw]
    // ASSIGNMENT: Store the converted integer result into the global dword_7C5694 [global:0x007C5694, callee:0x00587BDC, source:raw]
    // RETURN: Return the converted integer result [source:raw]
    // CALL: Invoked by RunCollisionDetectionLoop (0045f390) and SessionSynchronizer (0045f950) to produce a scaled timer-derived value [caller:0x0045F390, caller:0x0045F950]

    // Conservative worker pseudocode:
    //   sub_5895A2(a1 * 400.0);
    //   result = CRTFtol(a1 * 400.0);
    //   dword_7C5694 = result;
    //   return result;
    // UNRESOLVED: The dbl_59E9B0 global is flagged by packet facts but appears nowhere in the raw decompiled source; its role here is not verifiable
    // UNRESOLVED: The exact side effect of sub_5895A2 and whether dword_7C5694 is a timer or angle output are not documented in this function
}
