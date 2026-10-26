// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0043B930
// Canonical corpus name: SolverDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SolverDispatch_0043b930.c

void UnknownObject::SolverDispatch()
{
    // Dispatches on a solver operation-type id a2 and routes a scalar argument a3 to one of six physics solver functions. Cases 9 and 10 both target QuadraticSpringEval but at different offsets of this (0x1838 and 0x189C of the object, shown as 6200/6300). Case 3 updates a delta-tracking accumulator, case 14 solves constraint forces, cases 27-29 evaluate quadratic/spring-damper force-torque helpers. Any other type id returns immediately. Called per-frame by ConditionalMathDispatch.
    // STATE_TRANSITION: switch(a2) selects a solver path through the jump table; table base jpt_43B947 and index data byte_43B9F8 are read to resolve the target. [global:0x0043B9D8, global:0x0043B9F8, source:raw]
    // CALL: case 3: DeltaUpdateTracking(a3) — update the delta-smoothing accumulator. [callee:0x0043BB00, source:raw]
    // CALL: case 9: QuadraticSpringEval(this + 6200, a3) — evaluate the quadratic spring at object offset 6200 (0x1838). [callee:0x00436470, source:raw]
    // CALL: case 10: QuadraticSpringEval(this + 6300, a3) — evaluate the quadratic spring at object offset 6300 (0x189C). [callee:0x00436470, source:raw]
    // CALL: case 14: ConstraintForceSolver(a3) — solve constraint forces. [callee:0x0043BA20, source:raw]
    // CALL: case 27: QuadFunctionEval(a3) — evaluate the quadratic function. [callee:0x0043BB30, source:raw]
    // CALL: case 28: QuadraticForceTorqueCalculator(a3) — compute quadratic force/torque. [callee:0x0043BB80, source:raw]
    // CALL: case 29: SpringDamperCompute(a3) — compute spring-damper force. [callee:0x0043BBD0, source:raw]
    // RETURN: default: return without dispatching for any unrecognized operation type id. [source:raw]

    // Conservative worker pseudocode:
    //   void sub_43B930(void *this, int type, double scalar) {
    //     switch (type) {
    //       case 3:  DeltaUpdateTracking(scalar); break;
    //       case 9:  QuadraticSpringEval((char*)this + 6200, scalar); break;
    //       case 10: QuadraticSpringEval((char*)this + 6300, scalar); break;
    //       case 14: ConstraintForceSolver(scalar); break;
    //       case 27: QuadFunctionEval(scalar); break;
    //       case 28: QuadraticForceTorqueCalculator(scalar); break;
    //       case 29: SpringDamperCompute(scalar); break;
    //       default: return;
    //     }
    //   }
    // UNRESOLVED: Semantic meaning of each operation-type id (3, 9, 10, 14, 27, 28, 29) is not established by this packet alone.
    // UNRESOLVED: Object offsets 6200/6300 in cases 9/10 are not backed by a packet field entry; their struct role is unknown.
    // UNRESOLVED: The dispatch semantics supplied by the single caller ConditionalMathDispatch (0x004F1860) are not analyzed here.
}
