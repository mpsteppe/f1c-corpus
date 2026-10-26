// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00568E70
// Canonical corpus name: sub_568E70
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_568E70_00568e70.c

void UnknownObject::InitInertiaTensorParameters()
{
    // Initializes a physics inertia-tensor parameter object on `this`: allocates and copies the name string a2 into this+0x0, stores the scalar value a3 and its reciprocal at this+0xAC and this+0xB4, copies a 3-component inertia vector from a4 into this+0xBC through this+0xCC, stores the per-component reciprocals at this+0xD4, this+0xDC and this+0xE4, then delegates to InertiaTensorWorldSpaceTransform to finish the setup.
    // CALL: Allocate a name buffer of strlen(a2) + 1 bytes via OperatorNewNhMallocWrapper. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Store the allocated name pointer at this+0x0. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Copy the input name string a2 into the allocated buffer (strcpy). [source:raw]
    // ASSIGNMENT: Store the scalar value a3 (mass or moment) as a double at this+0xAC. [field:this:0x000000AC, source:raw]
    // CALCULATION: Store the reciprocal 1.0 / a3 at this+0xB4; the 1.0 constant comes from dbl_59E420. [field:this:0x000000B4, global:0x0059E420, source:raw]
    // ASSIGNMENT: Copy 24 bytes (0x18) of a4 into this+0xBC, populating the 3-component inertia vector at this+0xBC, this+0xC4 and this+0xCC. [field:this:0x000000BC, source:raw]
    // CALCULATION: Store the reciprocal 1.0 / this+0xBC at this+0xD4. [field:this:0x000000D4, field:this:0x000000BC, source:raw]
    // CALCULATION: Store the reciprocal 1.0 / this+0xC4 at this+0xDC. [field:this:0x000000DC, field:this:0x000000C4, source:raw]
    // CALCULATION: Store the reciprocal 1.0 / this+0xCC at this+0xE4. [field:this:0x000000E4, field:this:0x000000CC, source:raw]
    // CALL: Call InertiaTensorWorldSpaceTransform(this) to compute the world-space transform of the inertia tensor. [callee:0x00569410, source:raw]
    // RETURN: Return the result of InertiaTensorWorldSpaceTransform. [source:raw]

    // Conservative worker pseudocode:
    //   int InitInertiaTensorParameters(this, const char* name, double scalar, const void* vec) {
    //     char* s = (char*)OperatorNewNhMallocWrapper(strlen(name) + 1);
    //     *(void**)this = s;
    //     strcpy(s, name);
    //     *(double*)(this + 172) = scalar;
    //     *(double*)(this + 180) = 1.0 / scalar;
    //     qmemcpy((void*)(this + 188), vec, 0x18);
    //     *(double*)(this + 212) = 1.0 / *(double*)(this + 188);
    //     *(double*)(this + 220) = 1.0 / *(double*)(this + 196);
    //     *(double*)(this + 228) = 1.0 / *(double*)(this + 204);
    //     return InertiaTensorWorldSpaceTransform(this);
    //   }
    // UNRESOLVED: The exact physical meaning of the scalar a3 (mass versus a moment value) and the 3-component vector a4 (principal inertia diagonal) is not established from this function alone.
    // UNRESOLVED: Owner object is UnknownObject; the caller VehiclePhysicsJointSystemLoader places it in a vehicle physics joint/inertia subsystem, but no owner type is confirmed.
}
