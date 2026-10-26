// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00457A00
// Canonical corpus name: CollisionResponseWithRandomPerturbation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionResponseWithRandomPerturbation_00457a00.c

void UnknownObject::CollisionResponseWithRandomPerturbation()
{
    // Collision response with random perturbation. Saves/restores the state activation flag, reads the current position components from this+0x90/+0x94/+0x98, draws three random values from UtilityFunction_6010 and reduces each to a sign multiplier of +1.0 or -1.0 (mask 0x80000001 with an evenness test), scales by a2 * a3 * 0.5 clamped at 0.5, accumulates the perturbed vector into the local components, and writes the result back through VectorCopy. Invoked by CameraShake.
    // CALL: StateActivatedPositionSaveRestore(1) saves/restores the state activation flag around the position update. [callee:0x00457B00, source:raw]
    // ASSIGNMENT: Read the current position: v19 = *(float*)(this + 144) (this+0x90), v20 = *(float*)(this + 148) (this+0x94), v21 = *(float*)(this + 152) (this+0x98). [field:this:0x00000090, field:this:0x00000094, field:this:0x00000098, source:raw]
    // CALL: Three calls to UtilityFunction_6010() draw random values; each is masked with 0x80000001 and tested for evenness of its low bit via the ((v - 1) | 0xFFFFFFFE) == -1 idiom to choose +1.0 or -1.0 as the sign multiplier for X, Y and Z. [callee:0x00456010, source:raw]
    // CALCULATION: v15 = a2 * a3 * 0.5, clamped down to 0.5 when it exceeds 0.5. [source:raw]
    // CALCULATION: Perturb each component: v19 += v17 * v15 * a3; v20 += v18 * v15 * a3; v21 += v15 * v14 * a3. [field:this:0x00000090, field:this:0x00000094, field:this:0x00000098, source:raw]
    // CALL: VectorCopy(this, &v19) writes the computed perturbed vector into the object. [callee:0x00456130, function:0x00457A00, source:raw]
    // RETURN: Return the VectorCopy result (the object pointer). [callee:0x00456130, source:raw]
    // CALL: Invoked by CameraShake (0x0040ADB0) as a collision response helper; the ABI name Collision_Response_with_Random_Perturbation is recorded as LEGACY. [abi:lead, caller:0x0040ADB0, source:raw]

    // Conservative worker pseudocode:
    //   StateActivatedPositionSaveRestore(1);
    //   float pos[3] = { this[0x90 / 4], this[0x94 / 4], this[0x98 / 4] };  // 144, 148, 152
    //   float sgn[3] = { RngSign(), RngSign(), RngSign() };  // +1.0 or -1.0 from UtilityFunction_6010
    //   float m = a2 * a3 * 0.5; if (m > 0.5) m = 0.5;
    //   pos[0] += sgn[0] * m * a3;
    //   pos[1] += sgn[1] * m * a3;
    //   pos[2] += sgn[2] * m * a3;
    //   return VectorCopy(this, pos);
    // UNRESOLVED: The three read globals flt_59E43C / flt_59E450 / flt_59E670 are recorded as reads, but the packet's raw source renders the scaling constants as literals (0.5, 1.0, -1.0); which literal each global feeds cannot be determined from this packet.
    // UNRESOLVED: VectorCopy(this, &v19) writes into the object, but the exact destination offset (the position fields at +0x90..+0x98 or the object base) is inside VectorCopy and not established here.
    // UNRESOLVED: The evenness idiom ((v & 0x80000001) then ((lowbyte - 1) | 0xFFFFFFFE) == -1) is interpreted as a low-bit parity test, but the RNG distribution semantics of UtilityFunction_6010 are not verified within this packet.
}
