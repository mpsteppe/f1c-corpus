// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049ED00
// Canonical corpus name: FieldSetterTrigger
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FieldSetterTrigger_0049ed00.c

void UnknownObject::FieldSetterTrigger()
{
    // Stores the incoming parameter a2 into this[7] (byte offset 0x1C of the __thiscall object), then invokes UISparkleEffect and returns its result. A simple field setter followed by a triggering side-effect call.
    // ASSIGNMENT: Store parameter a2 into this[7], the dword at byte offset 0x1C of the __thiscall object. [field:this:0x0000001C, source:raw]
    // CALL: Invoke UISparkleEffect with no arguments; its return value becomes this function's result. [callee:0x0049ED30, source:raw]
    // RETURN: Return the value produced by UISparkleEffect. [source:raw]
    // CALL: Called by ParamRangeClampedLerp to commit a computed value into this+0x1C before triggering the sparkle effect. [caller:0x0049F530, source:raw]

    // Conservative worker pseudocode:
    //   int sub_49ED00(DWORD* this, int a2) {
    //     this[7] = a2;
    //     return UISparkleEffect();
    //   }
    // UNRESOLVED: Semantic meaning and type of the stored value at this+0x1C (existing analysis asserts a normalized float-as-int consumed by UISparkleEffect) is not re-established from the raw source alone.
}
