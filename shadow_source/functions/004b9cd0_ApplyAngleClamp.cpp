// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B9CD0
// Canonical corpus name: SingleCallWrapper_9cd0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SingleCallWrapper_9cd0_004b9cd0.c

void UnknownObject::ApplyAngleClamp()
{
    // Thin __thiscall void forwarder: reads the int stored at this+0x0 and calls AngleClampWrap(*this, a2), passing the field value together with the incoming float parameter a2. The prelabel getter template is not accurate for the actual behavior, which is a delegation with a float argument. Caller analysis shows it feeds time/accumulator values (from sub_4B9890 and FloatAccumulator), consistent with an angle/time clamp application.
    // ASSIGNMENT: Dereference this to obtain the int value stored at this+0x0. [field:this:0x00000000, source:raw]
    // CALL: AngleClampWrap(*this, a2) forwards the field int and the float parameter a2 to the clamp routine (ABI name Delegates_to_FUN_004b86e0); the target is not in the packet callee set, so it is referenced only via the raw source. [source:raw]
    // CALL: Invoked by sub_4B9890, which applies the computed session time delta through this wrapper. [caller:0x004B9890]
    // CALL: Invoked by FloatAccumulator (0x004B9D00), which forwards an accumulated float sum to this wrapper. [caller:0x004B9D00]

    // Conservative worker pseudocode:
    //   void ApplyAngleClamp(int* this, float a2) {
    //     AngleClampWrap(*this, a2);
    //   }
    // UNRESOLVED: The meaning of the int at this+0x0 (a pointer or handle consumed by the clamp routine) is unknown.
    // UNRESOLVED: The exact clamping semantics of the delegated routine (ABI name Delegates_to_FUN_004b86e0) are not documented in this packet.
    // UNRESOLVED: The prelabel claims a getter template (DERIVED), but the raw source is a void forwarder with a float argument; the getter classification does not match.
}
