// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C6920
// Canonical corpus name: VehicleObjectConstructor
// Owner: VehicleObject [DERIVED]
// Raw source: functions/VehicleObjectConstructor_004c6920.c

void VehicleObject::VehicleObjectConstructor()
{
    // Vehicle-object constructor. Calls RaceStructInit to zero-initialise the struct, sets the field at offset 0x4894 to -1 (all bits set) to mark an unset handle/ID, clears the driver-info substructure via VehicleDriverInfoClear, then stores a persistent self-reference via LargeStructFieldSetterWithStoredReference and returns the object pointer.
    // CALL: Call RaceStructInit(this) to zero-initialise the vehicle/race struct fields. [callee:0x00423E80]
    // ASSIGNMENT: Write this[4645] (offset 0x4894) = -1, i.e. 18446744073709551615 as an unsigned 64-bit literal (all bits set), marking the handle/ID as uninitialised. [field:this:0x00004894]
    // CALL: Call VehicleDriverInfoClear(this) to clear the driver-info substructure fields. [callee:0x004C79E0]
    // CALL: Call LargeStructFieldSetterWithStoredReference(this, this) to store a persistent self-reference pointer inside the object. [callee:0x00424040]
    // RETURN: Return the constructed object pointer (this). [function:0x004C6920, source:raw]

    // Conservative worker pseudocode:
    //   RaceStructInit(this);
    //   this[4645] = -1;
    //   VehicleDriverInfoClear(this);
    //   LargeStructFieldSetterWithStoredReference(this, this);
    //   return this;
    // UNRESOLVED: Semantic purpose of the handle/ID at offset 0x4894 beyond 'default-initialised to unset' is not established.
    // UNRESOLVED: Construction context and preconditions from caller RepeatedCallLoop (0x0042BB50) are not resolved here.
}
