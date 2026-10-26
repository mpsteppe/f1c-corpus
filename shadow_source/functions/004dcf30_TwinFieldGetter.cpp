// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DCF30
// Canonical corpus name: TwinFieldGetter_cf30
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TwinFieldGetter_cf30_004dcf30.c

void UnknownObject::TwinFieldGetter()
{
    // Two-field getter (__thiscall): copies the object field at this+0x14 (this[5]) into *a2 when a2 is non-null, and the field at this+0x18 (this[6]) into *a3 when a3 is non-null; returns a3 as the result. No side effects; called from UI cursor-rectangle, collision-damage decay and text-render dispatcher paths.
    // GUARD: Guard on output pointer a2 being non-null; when null, skip writing the this+0x14 field. [source:raw]
    // ASSIGNMENT: Copy this[5] (field at this+0x14) into the caller output *a2. [field:this:0x00000014, source:raw]
    // GUARD: Guard on output pointer a3 being non-null; when null, skip writing the this+0x18 field. [source:raw]
    // ASSIGNMENT: Copy this[6] (field at this+0x18) into the caller output *a3. [field:this:0x00000018, source:raw]
    // RETURN: Return a3 as the function result. [source:raw]

    // Conservative worker pseudocode:
    //   TwinFieldGetter(this, out a2, out a3) {
    //     if (a2 != null) *a2 = this->field_14;
    //     if (a3 != null) *a3 = this->field_18;
    //     return a3;
    //   }
    // UNRESOLVED: Identity of the owner object and the semantic meaning of the two returned fields are not established by the packet.
    // UNRESOLVED: The existing analysis labels the fields as width/height based on caller context, but that naming has no direct packet evidence.
    // UNRESOLVED: Whether both outputs must be provided together (a2 null while a3 used) is caller-dependent and unverified here.
}
