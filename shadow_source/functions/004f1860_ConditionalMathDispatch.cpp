// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F1860
// Canonical corpus name: ConditionalMathDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalMathDispatch_004f1860.c

void UnknownObject::ConditionalMathDispatch()
{
    // Conditional physics solver dispatch: reads a constraint gate field (this+0x32BC) and, only when it is zero, forwards a race-time double and two parameters to SolverDispatch. When the gate field is nonzero the function does nothing.
    // GUARD: Gate on this[3247] (this+0x32BC): when the field is zero the dispatch runs; when it is nonzero the function returns without acting. [field:this:0x000032BC, source:raw]
    // CALL: SolverDispatch(&dbl_7C7428, a2, a3): passes the address of the dbl_7C7428 global as the first argument together with the integer a2 and double a3. [callee:0x0043B930, global:0x007C7428, source:raw]
    // RETURN: Implicit void return; the only exit is the gate check, so the function is a no-op when the constraint field is set. [source:raw]
    // CALL: Invoked by PitStopOperationTimer (004A6340) on the per-frame tick path. [caller:0x004A6340, source:raw]

    // Conservative worker pseudocode:
    //   void sub_4F1860(this, int a2, double a3) {
    //     if (this[3247] == 0) {
    //       SolverDispatch(&dbl_7C7428, a2, a3);
    //     }
    //   }
    // UNRESOLVED: Semantics of a2 and a3 are unknown here; only SolverDispatch knows their meaning.
    // UNRESOLVED: Meaning of the gate field this+0x32BC (a rigid-body/constraint pointer per existing analysis) is not verifiable from this packet alone.
}
