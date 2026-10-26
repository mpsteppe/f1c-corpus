// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B9E40
// Canonical corpus name: PitServiceSteeringAnimationStep
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PitServiceSteeringAnimationStep_004b9e40.c

void UnknownObject::PitServiceSteeringAnimationStep()
{
    // Advances the pit-service steering animation by one step. A switch on the animation step state at obj + 0xF8C selects direction and speed of the steering wheel rotation: states 0/1 peek the event queue, adjust the target angle by +/-0.001, clamp it and transition to state 5; states 2-8 feed FloatAccumulator with dbl_8AFE90 scaled by -1.6666666..3.3333333 factors. Default returns without action.
    // CALCULATION: Dereference the this pointer (field this + 0) to obtain the pit-service data block pointer v2, which is then used for queue peeks. [field:this:0x00000000, source:raw]
    // GUARD: Switch on the animation step state at obj + 0xF8C (cases 0-8); default returns with no action. Jump targets resolved through the switch jump table jpt_4B9E58. [field:obj:0x00000F8C, global:0x004B9F48, source:raw]
    // CALL: States 0 and 1 peek the event/command queue via QueuePeek (v2,&v11,&v12) for state 0 and (v2,&v12,&v11) for state 1, yielding the next target steering value. [callee:0x004B87A0, source:raw]
    // CALCULATION: States 0/1 compute the new target angle as v11 + 0.001 (state 0) or v11 - 0.001 (state 1), a small step toward the peeked queue angle. [source:raw]
    // CALL: Clamp/wrap the computed angle into the valid range via AngleClampWrap(v2, angle). [callee:0x004B86E0, source:raw]
    // STATE_TRANSITION: After states 0/1 complete, store state 5 back to obj + 0xF8C (the initializer literal for this field) and return. [field:obj:0x00000F8C, source:raw]
    // CALCULATION: States 2-8 build a steering rate from dbl_8AFE90 scaled by -1.0 (states 2/4), -1.6666666 (state 3), +1.0 (states 6/8) or +1.6666666 (state 7); states 2 and 8 additionally apply a 3.3333333 multiplier. [global:0x008AFE90, source:raw]
    // CALL: States 2-8 apply the scaled steering rate via FloatAccumulator(this, rate), integrating it into the steering position/speed. [callee:0x004B9D00, source:raw]
    // RETURN: Default switch case returns immediately with no state change; states 0/1 also return after reaching state 5. [source:raw]
    // CALL: Dispatched from ConditionalMultiPathDispatcher as one step of the pit-service animation pipeline. [caller:0x004BA180]

    // Conservative worker pseudocode:
    //   void PitServiceSteeringAnimationStep(void* this) {
    //     float* v2 = *this;
    //     switch (*(int*)&v2[995]) {
    //       case 0: QueuePeek(v2, &angle, &state); step = angle + 0.001f; goto clamp;
    //       case 1: QueuePeek(v2, &state, &angle); step = angle - 0.001f;
    //         clamp: AngleClampWrap(v2, step); *(int*)&v2[995] = 5; return;
    //       case 2: rate = -dbl_8AFE90 * 3.3333333f; break;
    //       case 3: rate = -dbl_8AFE90 * 1.6666666f; break;
    //       case 4: rate = -dbl_8AFE90; break;
    //       case 6: rate = dbl_8AFE90; break;
    //       case 7: rate = dbl_8AFE90 * 1.6666666f; break;
    //       case 8: rate = dbl_8AFE90 * 3.3333333f; break;
    //       default: return;
    //     }
    //     FloatAccumulator(this, rate);
    //   }
    // UNRESOLVED: Global scalars flt_59E600, flt_5ACD14 and flt_5ACD18 are listed as referenced globals but do not appear in the raw source; their role in the animation is unclear.
    // UNRESOLVED: Semantics of the queue peek arguments (angle vs state ordering) are inferred from call order only.
    // UNRESOLVED: Meaning of the 0xF8C state values beyond 0-8 (e.g. external progression sources) is not established.
}
