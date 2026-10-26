// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004ADE20
// Canonical corpus name: TrackEnvironmentSelect
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TrackEnvironmentSelect_004ade20.c

void UnknownObject::TrackEnvironmentSelect()
{
    // Track environment selection and physics setup (canonical name TrackEnvironmentSelect): when a2 is set, selects the environment variant through sub_4AE750 based on the byte_7CB710 / byte_7CBB0C flag bits (2, 3, or 1), otherwise records environment select flag 1 in this[1723]; clamps the camera index this[1732] into the [this[1734], this[1735]] range after stepping dword_5EC4A8 + 1 up to 4; loads the current track scene through TrackSceneLoader; then runs the physics, driving-mode, car-part-visibility, sub_4AE9F0 and tire-compound setup chain, returning the TireCompoundClamp result.
    // STATE_TRANSITION: Environment selection when a2 is set: if byte_7CB710 has bit 0 set call sub_4AE750(2), else if byte_7CBB0C has bit 0 set call sub_4AE750(3), else call sub_4AE750(1). [global:0x007CB710, global:0x007CBB0C, callee:0x004AE750, source:raw]
    // ASSIGNMENT: When a2 is clear, set the environment selection flag this[1723] (offset 0x1AEC) to 1 instead of calling sub_4AE750. [field:this:0x00001AEC, source:raw]
    // GUARD: Guard on the camera index this[1732] (offset 0x1B10): the clamping block runs only when the current index is greater than 0. [field:this:0x00001B10, guard:0, source:raw]
    // CALCULATION: Step and clamp the camera index: v3 = min(dword_5EC4A8 + 1, 4), assign this[1732] = v3, then clamp into the range bounded by this[1734] (offset 0x1B18) and this[1735] (offset 0x1B1C): below the lower bound the index becomes the bound, above the upper bound it becomes the upper bound. [global:0x005EC4A8, field:this:0x00001B10, field:this:0x00001B18, field:this:0x00001B1C, source:raw]
    // CALCULATION: Track scene load: compute v7 = dword_8AC490 + 396 * dword_8AC48C; when non-zero, call TrackSceneLoader(v7 + 260). [global:0x008AC490, global:0x008AC48C, callee:0x004C55B0, source:raw]
    // CALL: PhysicsParameterInitialization(this) initializes the physics parameters on the object. [callee:0x004AF3A0, source:raw]
    // CALL: EmptyStub_0170(this) runs as part of the setup chain. [callee:0x004B0170, source:raw]
    // CALL: DrivingModeParameterSetup(this) configures the driving mode parameters. [callee:0x004ADF10, source:raw]
    // CALL: CarPartVisibilityController(this) sets car part visibility. [callee:0x004AE490, source:raw]
    // CALL: sub_4AE9F0(this) runs as part of the environment setup chain. [callee:0x004AE9F0, source:raw]
    // RETURN: The function returns the result of TireCompoundClamp(this), the last call in the chain. [callee:0x004AF220, source:raw]
    // CALL: Invoked by TextFileReader (0x004B09A0) to select the track environment during configuration loading. [caller:0x004B09A0, source:raw]

    // Conservative worker pseudocode:
    //   int TrackEnvironmentSelect(this, int select) {
    //     if (select) {
    //       if (byte_7CB710 & 1) sub_4AE750(2);
    //       else if (byte_7CBB0C & 1) sub_4AE750(3);
    //       else sub_4AE750(1);
    //     } else {
    //       this[0x1AEC] = 1;
    //     }
    //     if (this[0x1B10] > 0) {
    //       int step = min(dword_5EC4A8 + 1, 4);
    //       this[0x1B10] = step;
    //       if (this[0x1B10] < this[0x1B18]) this[0x1B10] = this[0x1B18];
    //       else if (this[0x1B10] > this[0x1B1C]) this[0x1B10] = this[0x1B1C];
    //     }
    //     int scene = dword_8AC490 + 396 * dword_8AC48C;
    //     if (scene) TrackSceneLoader(scene + 260);
    //     PhysicsParameterInitialization(this);
    //     EmptyStub_0170(this);
    //     DrivingModeParameterSetup(this);
    //     CarPartVisibilityController(this);
    //     sub_4AE9F0(this);
    //     return TireCompoundClamp(this);
    //   }
    // UNRESOLVED: The owner object is not established; fields 0x1AEC, 0x1B10, 0x1B18 and 0x1B1C are consistent with an environment/camera selection record but the class is unknown.
    // UNRESOLVED: The exact environment meaning of the sub_4AE750 arguments (1, 2, 3) and the byte_7CB710 / byte_7CBB0C flag bit interpretation are not independently grounded.
}
