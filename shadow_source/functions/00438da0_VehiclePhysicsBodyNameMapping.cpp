// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00438DA0
// Canonical corpus name: VehiclePhysicsBodyNameMapping
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VehiclePhysicsBodyNameMapping_00438da0.c

void UnknownObject::VehiclePhysicsBodyNameMapping()
{
    // Initializes the vehicle physics body name-to-index mapping: loads the physics joint system, allocates a per-body joint data array sized by the body count (48 bytes per body), then resolves the array indices of named physics bodies (body, steering arms, wheels, spindles, rear axle, fuel tank, driver head) via linear search and stores them in indexed fields for fast lookup during simulation. Called from the tire-model initialization path TireModelInit (0x0043E050).
    // CALL: Load the physics joint system through VehiclePhysicsJointSystemLoader(a2) before name-to-index resolution. [callee:0x0056D930, source:raw]
    // ASSIGNMENT: Read the body count from this[1387] and allocate the joint data array: this[1419] = OperatorNewNhMallocWrapper(48 * bodyCount), 48 bytes per body entry. [field:this:0x000015AC, field:this:0x0000162C, callee:0x00587C03, source:raw]
    // ASSIGNMENT: Resolve the main body index: this[1404] = LinearSearchWithLargeStructStride('Body'). [field:this:0x000015F0, global:0x005C41D4, callee:0x0056EAD0, source:raw]
    // ASSIGNMENT: Resolve the front-left steering index via LinearSearchInStructArrayByString('FlSteering'): if the found entry field [1] equals the stored body index this[1404], take field [2], otherwise field [4]; store the result in this[1420]. [field:this:0x000015F0, field:this:0x00001630, global:0x005C41C8, callee:0x0056EB30, source:raw]
    // ASSIGNMENT: Resolve the front-right steering index via LinearSearchInStructArrayByString('FrSteering') using the same body-index comparison against this[1404], storing field [2] or [4] into this[1425]. [field:this:0x000015F0, field:this:0x00001644, global:0x005C41BC, callee:0x0056EB30, source:raw]
    // ASSIGNMENT: Store front-left wheel and spindle indices: this[250] from 'FlWheel', this[251] from 'FlSpindle'. [field:this:0x000003E8, field:this:0x000003EC, global:0x005C41B0, global:0x005C41A4, callee:0x0056EAD0, source:raw]
    // ASSIGNMENT: Store front-right wheel and spindle indices: this[531] from 'FrWheel', this[532] from 'FrSpindle'. [field:this:0x0000084C, field:this:0x00000850, global:0x005C4198, global:0x005C418C, callee:0x0056EAD0, source:raw]
    // ASSIGNMENT: Store rear-left wheel and spindle indices: this[812] from 'RlWheel', this[813] from 'RlSpindle'. [field:this:0x00000CB0, field:this:0x00000CB4, global:0x005C4180, global:0x005C4174, callee:0x0056EAD0, source:raw]
    // ASSIGNMENT: Store rear-right wheel and spindle indices: this[1093] from 'RrWheel', this[1094] from 'RrSpindle'. [field:this:0x00001114, field:this:0x00001118, global:0x005C4168, global:0x005C415C, callee:0x0056EAD0, source:raw]
    // ASSIGNMENT: Store the rear axle index: this[1287] from 'RearAxle'. [field:this:0x0000141C, global:0x005C4150, callee:0x0056EAD0, source:raw]
    // ASSIGNMENT: Store the fuel tank index: this[117] from 'FuelTank'. [field:this:0x000001D4, global:0x005C4144, callee:0x0056EAD0, source:raw]
    // RETURN: Store the driver head index this[122] from 'DriverHead' and return it as the function result. [field:this:0x000001E8, global:0x005C4138, callee:0x0056EAD0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_438DA0(DWORD* this, int a2) {
    //     VehiclePhysicsJointSystemLoader(a2);
    //     this[1419] = OperatorNewNhMallocWrapper(48 * this[1387]);
    //     this[1404] = LinearSearchWithLargeStructStride("Body");
    //     e = LinearSearchInStructArrayByString("FlSteering");
    //     this[1420] = (e[1] == this[1404]) ? e[2] : e[4];
    //     e = LinearSearchInStructArrayByString("FrSteering");
    //     this[1425] = (e[1] == this[1404]) ? e[2] : e[4];
    //     this[250] = LinearSearchWithLargeStructStride("FlWheel");
    //     this[251] = LinearSearchWithLargeStructStride("FlSpindle");
    //     this[531] = LinearSearchWithLargeStructStride("FrWheel");
    //     this[532] = LinearSearchWithLargeStructStride("FrSpindle");
    //     this[812] = LinearSearchWithLargeStructStride("RlWheel");
    //     this[813] = LinearSearchWithLargeStructStride("RlSpindle");
    //     this[1093] = LinearSearchWithLargeStructStride("RrWheel");
    //     this[1094] = LinearSearchWithLargeStructStride("RrSpindle");
    //     this[1287] = LinearSearchWithLargeStructStride("RearAxle");
    //     this[117] = LinearSearchWithLargeStructStride("FuelTank");
    //     result = LinearSearchWithLargeStructStride("DriverHead");
    //     this[122] = result;
    //     return result;
    //   }
    // UNRESOLVED: Layout of entries returned by LinearSearchInStructArrayByString (fields [1], [2], [4]) is unknown; the conditional against this[1404] selects between two candidate index fields.
    // UNRESOLVED: Identity of this[1404] (main body index) compared against steering entry field [1] is inferred from the search helpers; the compared value type is not independently confirmed.
    // UNRESOLVED: The physical body object this belongs to is not established; the 0x0043E050 caller (TireModelInit) is the only context signal.
}
