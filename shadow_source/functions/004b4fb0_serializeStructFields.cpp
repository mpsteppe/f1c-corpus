// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B4FB0
// Canonical corpus name: sub_4B4FB0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4B4FB0_004b4fb0.c

void UnknownObject::serializeStructFields()
{
    // __thiscall struct serialization write: emits a sequence of fields through ConditionalDispatch_6bd0. Emits a leading marker value 1 for the receiver pointer, measures the embedded NUL-terminated string at this+1 with strlen, emits that length, re-emits the string bytes, then emits two byte-sized fields at this+65 and this+97 with the constant 32 and two fields at this+132 and this+136 with the constant 4. Always returns 1. ABI label Struct_Serialization_Write and caller VehicleForceAerodynamicsComputation suggest a vehicle-struct serialization helper.
    // CALL: ConditionalDispatch_6bd0(this, 1): emits a leading marker/value 1 associated with the receiver pointer. [callee:0x00566BD0, source:raw]
    // CALCULATION: a2 = strlen(this + 1): measures the length of the NUL-terminated string embedded at byte offset 1 of the receiver, overwriting the incoming a2 parameter. [source:raw]
    // CALL: ConditionalDispatch_6bd0(&a2, 1): emits the computed string length stored in a2. [callee:0x00566BD0, source:raw]
    // CALL: ConditionalDispatch_6bd0(this + 1, a2): emits the string contents at this+1 with its length as the second argument. [callee:0x00566BD0, source:raw]
    // CALL: ConditionalDispatch_6bd0(this + 65, 32): emits the byte-sized field at byte offset 65 with the constant 32. [callee:0x00566BD0, source:raw]
    // CALL: ConditionalDispatch_6bd0(this + 97, 32): emits the byte-sized field at byte offset 97 with the constant 32. [callee:0x00566BD0, source:raw]
    // CALL: ConditionalDispatch_6bd0(this + 132, 4): emits the field at byte offset 132 with the constant 4. [callee:0x00566BD0, source:raw]
    // CALL: ConditionalDispatch_6bd0(this + 136, 4): emits the field at byte offset 136 with the constant 4. [callee:0x00566BD0, source:raw]
    // RETURN: Returns the constant 1 unconditionally after the field emissions. [source:raw, function:0x004B4FB0]

    // Conservative worker pseudocode:
    //   void serializeStructFields(this) {
    //     ConditionalDispatch_6bd0(this, 1);
    //     unsigned char len = strlen(this + 1);
    //     ConditionalDispatch_6bd0(&len, 1);
    //     ConditionalDispatch_6bd0(this + 1, len);
    //     ConditionalDispatch_6bd0(this + 65, 32);
    //     ConditionalDispatch_6bd0(this + 97, 32);
    //     ConditionalDispatch_6bd0(this + 132, 4);
    //     ConditionalDispatch_6bd0(this + 136, 4);
    //     return 1;
    //   }
    // UNRESOLVED: ConditionalDispatch_6bd0's body is outside this packet, so whether it appends to a stream, dispatches to a writer, or conditionally stores is unverified.
    // UNRESOLVED: The meaning of the constants 32 (two byte fields) and 4 (two fields) is not determinable here; 32 may be a default space/pad byte or an unrelated value.
    // UNRESOLVED: Whether the string at this+1 is re-serialized in place or into a separate sink depends on ConditionalDispatch_6bd0 semantics.
    // UNRESOLVED: The owner class is unknown; the ABI label Struct_Serialization_Write and caller VehicleForceAerodynamicsComputation are DERIVED signals only.
}
