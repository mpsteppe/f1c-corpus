// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00402220
// Canonical corpus name: sub_402220
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_402220_00402220.c

void UnknownObject::VehicleWheelContactHeightCheck()
{
    // Computes the wheel contact patch position and its terrain penetration for a vehicle wheel. Takes a wheel-geometry array a2 (origin a2[0..2], length-scale, direction a2[8..10]) and a contact-type selector a4; writes the contact position, a half-extent probe frame and final suspension-compression/lateral-tilt values into the output a3. Computes a3[0..2] = a2[0..2] + scale * a2[8..10] where scale is a2[7] (a4==1) or a2[6] / a2[71]+a2[6] (other paths), then scales a direction vector by half of a scalar read from this (this[1] on the a4==1 path, *this elsewhere) to build the a3[3..5] half-extent. Queries SpatialGridQuery at the contact center and at plus/minus the half-extent, resolves side-height disagreement beyond a 0.35 threshold by mirroring the farther sample, then writes a3[1] = max(center, average of sides) + 0.06 and a3[4] = half the side-height difference.
    // GUARD: Dispatch on a4 (contact-type selector): a4 == 1 takes the steering-aligned path using a2[7] as the scale; a4 == 0 selects the extended-spring length a2[71] + a2[6]; any other non-zero a4 uses a2[6] alone. [source:raw]
    // CALCULATION: Contact-point computation: a3[0..2] = a2[0..2] + scale * a2[8..10], where scale is a2[7] on the a4 == 1 path and v5 (a2[6] or a2[71] + a2[6]) on the other paths. [source:raw]
    // ASSIGNMENT: Write the computed contact position into the output a3 (a3[0], a3[1], a3[2]). [source:raw]
    // CALCULATION: Half-extent frame: read the scalar v8 from this — this[1] on the a4 == 1 path, *this otherwise — and set a3[3..5] = (v8 * 0.5) * a2[8..10]. [field:this:0x00000000, field:this:0x00000004, source:raw]
    // CALL: SpatialGridQuery(&v46): terrain-height query at the contact position a3 (v46 = {a3[0], a3[1], a3[2]}); on success the returned height is captured in v53 (v29 = v53). [callee:0x0044C4C0, source:raw]
    // CALL: SpatialGridQuery at the low-side probe (a3[0]-a3[3], a3[1], a3[2]-a3[5]); the returned height v30 falls back to the center height v29 when the query fails. [callee:0x0044C4C0, source:raw]
    // CALL: SpatialGridQuery at the high-side probe (a3[0]+a3[3], a3[1], a3[2]+a3[5]); the returned height v25 falls back to v29 when the query fails. [callee:0x0044C4C0, source:raw]
    // GUARD: Side-sample consistency: when v25 differs from (2 * v29 - v30) by more than 0.35, keep the side sample closer to the center and mirror the farther one (v30 = 2 * v29 - v25 or v25 = 2 * v29 - v30) so both sides agree with the center height. [source:raw]
    // CALCULATION: Average the two side heights v28 = (v30 + v25) * 0.5, then clamp v28 to be at least the center height (v28 = v29 when v29 > v28). [source:raw]
    // ASSIGNMENT: Update the contact state in a3: a3[1] = v28 + 0.06 (compressed suspension height) and a3[4] = (v25 - v30) * 0.5 (lateral tilt from the side-height difference). [source:raw]
    // CALCULATION: Read-only scalar constants loaded from the globals 0x0059E450, 0x0059E454, 0x0059E458 and 0x007C9360 and consumed by the half-extent, threshold and lift arithmetic (the raw source renders the float constants as literals such as 0.5, 0.34999999 and 0.059999999). [global:0x0059E450, global:0x0059E454, global:0x0059E458, global:0x007C9360, source:raw]

    // Conservative worker pseudocode:
    //   scale = (a4 == 1) ? a2[7] : ((a4 == 0) ? (a2[6] + a2[71]) : a2[6]);
    //   a3[0..2] = a2[0..2] + scale * a2[8..10];
    //   half = ((a4 == 1) ? this[1] : *this) * 0.5;
    //   a3[3..5] = half * a2[8..10];
    //   v29 = SpatialGridQuery(a3);
    //   v30 = SpatialGridQuery(a3 - a3[3..5]) or v29;
    //   v25 = SpatialGridQuery(a3 + a3[3..5]) or v29;
    //   if (v25 outside (2*v29 - v30) +/- 0.35) mirror the farther side sample;
    //   avg = max(v29, (v30 + v25) * 0.5);
    //   a3[1] = avg + 0.06;
    //   a3[4] = (v25 - v30) * 0.5;
    // UNRESOLVED: Exact mapping of the four read-only globals (0x0059E450, 0x0059E454, 0x0059E458, 0x007C9360) to the floating-point literals in the raw source (0.5, 0.34999999, 0.059999999) is not established by the packet; the existing analysis labels them DegreesToRadians / PhysicsConstant_59E454 / ConstraintForceEpsilon / Unknown_Struct_7C9360 at DERIVED trust, which is not adopted here.
    // UNRESOLVED: The legacy ABI label 'Ray_Sphere_Intersection' (abi:lead) is inconsistent with the raw source, which performs terrain-height queries; the proposed name follows the existing analysis fill (VehicleWheelContactHeightCheck).
    // UNRESOLVED: The exact meanings of the a2 fields (wheel origin/spring length/scale/direction) and of this[0]/this[1] (a vehicle half-height scalar) are interpretations from the fill, not independently evidenced.
}
