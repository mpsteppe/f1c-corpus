// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004CC1D0
// Canonical corpus name: ParticleInstanceUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ParticleInstanceUpdate_004cc1d0.c

void UnknownObject::ParticleInstanceUpdate()
{
    // Updates particle instances: removes particles whose elapsed time falls outside their lifetime window, interpolates particle position from motion fields plus base offsets, runs collision detection against nearby drivers (range-scan path or direct driver lookup path), writes the texture-layer and array positions, computes a time-based alpha value, and writes a packed ARGB color per particle.
    // GUARD: If the global dword_8AB6E4 equals 2, invoke Delegation(&dword_8AB6EC); otherwise take the default simulation time value from dbl_8AFEA0. [global:0x008AB6E4, global:0x008AB6EC, global:0x008AFEA0, callee:0x004B9CE0, abi:lead, function:0x004CC1D0, source:raw]
    // ASSIGNMENT: Read the active particle count from this+0x64 and the particle array pointer from this+0x68; iterate the array from index 0 while the index is below the count. [field:this:0x00000064, field:this:0x00000068, source:raw]
    // LOOP: For each particle descriptor, compare the current time against the lifetime window fields at descriptor indices 2 and 3; if outside the window, remove the particle via ArrayElementRemoval and step the loop index back. [callee:0x004CB5A0, source:raw]
    // CALCULATION: Compute elapsed time as current time minus the particle spawn field (descriptor index 2); build the interpolated particle position from descriptor motion fields 14, 15, 16 added to descriptor base offsets 11, 12, 13. [source:raw]
    // CALCULATION: Scale the elapsed motion by descriptor field 26, multiply each component by the this+0x18 / 0x1C / 0x20 time-scaled multipliers, and add the this+0xC / 0x10 / 0x14 base position to produce the world-space position. [field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, source:raw]
    // GUARD: If the particle carries a non-negative target/driver index (descriptor dword 17), run the collision detection branch. [source:raw]
    // GUARD: If byte_7CF9EC is set, call FindDriversInRange(flt_8AC4E0, position, flt_5D3494, &v33) to obtain nearby drivers; for each driver, compare proximity against threshold flt_5D3490 and call RaySphereIntersection against the particle sphere when close and owned by a different driver. [global:0x007CF9EC, global:0x008AC4E0, global:0x005D3494, global:0x005D3490, callee:0x004C9C70, callee:0x004CBDD0, source:raw]
    // CALCULATION: Else branch: read the target position from unk_5ECE1C at index v10 (per-entry stride of 18624 bytes), and if the target is within threshold flt_5D3490 call RaySphereIntersection against the particle sphere. [global:0x005ECE1C, global:0x005D3490, callee:0x004CBDD0, source:raw]
    // CALL: Write the particle position through TextureLayerFlagSet and ArrayElementFlagSetWithBoundsCheck using the computed position components. [callee:0x00558C60, callee:0x00558CB0, source:raw]
    // CALCULATION: Compute the alpha value: early-life boost (elapsed * descriptor field 8 * field 10) while elapsed is within field 5, else constant field 10, else linear fade (1.0 - (elapsed - field 6) * field 9) * field 10; pack as (alpha << 24) | 0xFFFFFF and write via BoundsCheckedArrayWrite. [callee:0x00558CF0, source:raw]
    // RETURN: Return the active particle count read from this+0x64. [source:raw]
    // UNRESOLVED: The two comparison flag bits v18/v19 (FPU c0/c3) that select the alpha branch are not documented.
    // UNRESOLVED: The direct-lookup branch reads a driver-like position from unk_5ECE1C at a per-target stride of 18624 bytes; that stride and the target struct layout are not packet evidence.
    // UNRESOLVED: The exact semantics of the particle descriptor fields (lifetime window indices 2,3; motion 14,15,16,26; base 11,12,13; sphere 21; alpha 5,6,8,9,10) are inferred from usage only.
    // UNRESOLVED: The byte_7CF9EC switch between range-scan collision and direct driver lookup, and the exact trigger for each path, is unclear.
    // UNRESOLVED: Particle descriptor layout (indices beyond the packet-listed this fields) is not covered by packet field evidence.
}
