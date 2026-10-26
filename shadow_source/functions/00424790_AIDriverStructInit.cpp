// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00424790
// Canonical corpus name: AIDriverStructInit
// Owner: F1CVehicle [CONFIRMED]
// Raw source: functions/AIDriverStructInit_00424790.c

void F1CVehicle::AIDriverStructInit()
{
    // Per-frame AI driver subsystem reinitialization on an F1CVehicle: clears state flags, timers, and counters; seeds two stride arrays of waypoint/slot sentinels; resets pace, grip, pit, and speed defaults; optionally reloads waypoint data and command-queue buffers when the a2 flag is set; then returns a difficulty-scaled value passed through ScaleAudioPitch.
    // ASSIGNMENT: Write byte 0 at +0x4140 (this+16704), clearing an active/inactive byte flag. [field:this:0x00004140, source:raw]
    // ASSIGNMENT: Write byte 0 at +0x4410 (this+17424), clearing RetiredFlag. [field:this:0x00004410, source:raw]
    // ASSIGNMENT: Zero this[4383] at +0x447C. [field:this:0x0000447C, source:raw]
    // ASSIGNMENT: Zero this[4418] at +0x4508 and this[4419] at +0x450C. [field:this:0x00004508, field:this:0x0000450C, source:raw]
    // ASSIGNMENT: Zero this[4360] at +0x4420. [field:this:0x00004420, source:raw]
    // ASSIGNMENT: Write 2139095039 sentinel to this[4188] at +0x4170. [field:this:0x00004170, source:raw]
    // LOOP: Five-iteration stride loop: v5 starts at this+4205 (+0x41B4) writing -1 to *v5 each pass (v5 advances 17 slots), and v4 starts at this+4278 (+0x42D8) writing -998653952 (-999.0f) to *v4 each pass (v4 advances 7 slots). Neighbouring stride slots written by the same loop are not individually listed in the packet. [field:this:0x000041B4, field:this:0x000042D8, source:raw]
    // ASSIGNMENT: Write byte 1 at +0x4578 (this+17784). [field:this:0x00004578, source:raw]
    // ASSIGNMENT: Zero this[4364] at +0x4430, this[4425] at +0x4524, and this[4371] at +0x444C. [field:this:0x00004430, field:this:0x00004524, field:this:0x0000444C, source:raw]
    // ASSIGNMENT: Write -1082130432 (-1.0f) to this[4376] at +0x4460 and 1065353216 (1.0f) to this[4377] at +0x4464. [field:this:0x00004460, field:this:0x00004464, source:raw]
    // CALL: Call AIClearStateFlags(this) to clear AI state flags. [callee:0x0042AE00, source:raw]
    // CALCULATION: Read this[1] at +0x4 and negate it into v14. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Copy this[3675] at +0x396C into this[4397] at +0x44B4. [field:this:0x0000396C, field:this:0x000044B4, source:raw]
    // ASSIGNMENT: Write 1065353216 (1.0f) to +0x453C (LivePaceFactor), +0x44F8 (TrackAggressionEffective), and +0x44CC (PassingNorm). [field:this:0x0000453C, field:this:0x000044F8, field:this:0x000044CC, source:raw]
    // CALCULATION: Write (double)v14 * 7.0 into the float slot this[4373] at +0x4454. [field:this:0x00004454, source:raw]
    // ASSIGNMENT: Zero this[4479] at +0x45FC, this[4363] at +0x442C, and this[4420] at +0x4510 (driverStatus). [field:this:0x000045FC, field:this:0x0000442C, field:this:0x00004510, source:raw]
    // ASSIGNMENT: Write 1232348144 (999999.0f) sentinel to this[4385] at +0x4484, this[4430] at +0x4538 (maxSpeed), and this[4487] at +0x461C; write 1086324736 (6.0f) to this[4432] at +0x4540 and 1 to this[4433] at +0x4544. [field:this:0x00004484, field:this:0x00004538, field:this:0x0000461C, field:this:0x00004540, field:this:0x00004544, source:raw]
    // ASSIGNMENT: Write byte 0 at +0x4548 (this+17736, PitLaneRouteFlag); zero this[4435] at +0x454C (CallToBox), this[4436] at +0x4550 (WaypointSetSelector), this[4439] at +0x455C, this[4440] at +0x4560, and this[4441] at +0x4564; write 50 to this[4438] at +0x4558 and 1065353216 (1.0f) to this[4437] at +0x4554. [field:this:0x00004548, field:this:0x0000454C, field:this:0x00004550, field:this:0x0000455C, field:this:0x00004560, field:this:0x00004564, field:this:0x00004558, field:this:0x00004554, source:raw]
    // ASSIGNMENT: Zero this[4367] at +0x443C; write -1082130432 (-1.0f) to this[4353] at +0x4404; write -1 to this[4374] at +0x4458 and this[4396] at +0x44B0; zero this[4379] at +0x446C and this[4350] at +0x43F8; write byte 0 at +0x45F4 (this+17908, AIControlFlag). [field:this:0x0000443C, field:this:0x00004404, field:this:0x00004458, field:this:0x000044B0, field:this:0x0000446C, field:this:0x000043F8, field:this:0x000045F4, source:raw]
    // GUARD: If the low byte of parameter a2 is nonzero, reinitialize the waypoint/command-queue subsystem. [source:raw]
    // ASSIGNMENT: Zero this[4429] at +0x4534 (timeOfNextExit). [field:this:0x00004534, source:raw]
    // LOOP: Reset 5 stride-2 slots to -1 starting at this[4177] (+0x4144); the trailing stride slots are not individually listed in the packet. [field:this:0x00004144, source:raw]
    // CALL: Call sub_424080(this) to reload waypoint data. [callee:0x00424080, source:raw]
    // GUARD: If this[4394] at +0x44A8 is nonzero, free it via FreeWrapper_7bcf. [field:this:0x000044A8, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Set this[4395] at +0x44AC to 10. [field:this:0x000044AC, source:raw]
    // CALL: Allocate 80 bytes via OperatorNewNhMallocWrapper and store into this[4394] at +0x44A8. [callee:0x00587C03, field:this:0x000044A8, source:raw]
    // CALL: Call AICommandMessageQueueDispatcher(0, 0). [callee:0x00424CD0, source:raw]
    // ASSIGNMENT: Zero this[4371] at +0x444C, set this[4396] at +0x44B0 to -1, and zero this[4478] at +0x45F8. [field:this:0x0000444C, field:this:0x000044B0, field:this:0x000045F8, source:raw]
    // LOOP: Scan dword_5C329C entries of the dword_7C54F0 grid-pointer array; for each entry whose name string (read at an identical offset in each struct, raw source +18104) matches this struct's name string (reached via the +0x0 pointer) and which is not this, store that entry into +0x45F8 (this[4478]). [global:0x005C329C, global:0x007C54F0, field:this:0x00000000, field:this:0x000045F8, source:raw]
    // ASSIGNMENT: Read the pointer stored at +0x0 and write dword_5EA2D0 + (dereferenced +0x0 value at raw source +18596) into this[2] at +0x8. [field:this:0x00000000, field:this:0x00000008, global:0x005EA2D0, source:raw]
    // CALL: Call ArrayOfStructIndexedFieldCopy(dword_5EA2C0, value at the +0x0 pointer's +18596 field, v16, v17) to copy indexed struct fields into local buffers v16/v17. [callee:0x00403F70, global:0x005EA2C0, source:raw]
    // CALL: Call SpatialTreeNearestNeighborSearch(dword_5EA2C0, v16, 0, this[2] at +0x8, 0) and store the result into +0x4400 (this[4352]). [callee:0x00403AA0, global:0x005EA2C0, field:this:0x00004400, field:this:0x00000008, source:raw]
    // CALL: Call sub_429960(this). [callee:0x00429960, source:raw]
    // LOOP: Initialize 7 slots starting at this[4480] by calling GuardedCallWithCheck(v2) for v2 = 0..6; the trailing slot of this run is not individually listed in the packet. [callee:0x004A5C10, source:raw]
    // ASSIGNMENT: Write 2139095039 sentinel to this[4175] at +0x413C (PitDecisionTimer). [field:this:0x0000413C, source:raw]
    // CALCULATION: v19 = AIDifficultyInterpolation(). [callee:0x00424AC0, source:raw]
    // GUARD: If dword_7C56A4 is not 3, 4, or 5, scale v19 by flt_5EA3E8. [global:0x007C56A4, global:0x005EA3E8, source:raw]
    // RETURN: Return ScaleAudioPitch(v19). [callee:0x004F1510, source:raw]

    // Conservative worker pseudocode:
    //   init(vehicle, reinit_flag) {
    //     clear byte flags, timers, counters across the AI region;
    //     seed two stride arrays of slot sentinels (5 passes each);
    //     reset pace/grip/pit/speed fields to default literals;
    //     if (low_byte(reinit_flag)) {
    //       reset slot list to -1, reload waypoint data, rebuild command queue buffer,
    //       locate self in the grid list and stash the pointer;
    //       run spatial search and copy indexed fields;
    //     }
    //     init 7 slots via GuardedCallWithCheck;
    //     return ScaleAudioPitch(difficulty-scaled value);
    //   }
    // UNRESOLVED: obj+0x48A4 (read) has no visible read site in the raw source body; it is presumed consumed inside one of the callees in the waypoint/spatial chain.
    // UNRESOLVED: flt_59E864 (global read) has no visible read site in the raw source body; it is presumed consumed inside a callee.
    // UNRESOLVED: The stride loops (anchors +0x41B4, +0x42D8, +0x4144) write intermediate slots whose exact offsets are not individually listed in the packet field list; those targets cannot be named from packet evidence.
    // UNRESOLVED: The 7-slot GuardedCallWithCheck run writes slots this[4480]..this[4486]; only the surrounding packet fields bound this range and the trailing slot is not packet-listed.
    // UNRESOLVED: Parameter a2 is a float whose low byte gates the reinit block; the wider meaning of the flag is not established.
}
