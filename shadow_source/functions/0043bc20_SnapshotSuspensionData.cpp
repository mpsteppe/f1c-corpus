// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0043BC20
// Canonical corpus name: sub_43BC20
// Owner: SuspensionPhysicsSnapshot [DERIVED]
// Raw source: functions/sub_43BC20_0043bc20.c

void SuspensionPhysicsSnapshot::SnapshotSuspensionData()
{
    // Per-frame suspension physics state snapshot copy. Copies two collision-geometry blocks from the source physics object (a3+324, a3+408) into this+6200 and this+6300, evaluates quadratic-spring terms from the parameter descriptor a2 into them, then copies force/torque parameters, wheel/damper blocks (six 24-byte entries plus a 24-byte tail each), and quad/force-torque/spring-damper results into the snapshot struct. The three result-producing helpers (QuadFunctionEval, QuadraticForceTorqueCalculator, SpringDamperCompute) each return a result-block pointer whose fields are copied into this, with several fields mirrored into a this+0x1C08..0x1C4C window. Spring scalars at this+6152/this+6168 are scaled by the descriptor coefficient v18 plus an offset. Returns the SpringDamperCompute result-block pointer.
    // CALL: Copy collision geometry block 0: CollisionStructCopy(this+6200, a3+324) transfers a 72-byte collision struct from the source physics block into the snapshot. [callee:0x004363F0, source:raw]
    // CALL: Evaluate the first quadratic-spring term: QuadraticSpringEval(v4, (double)*(int*)(a2+3588) * *(double*)(a2+3576) + *(double*)(a2+3568)); the result lands in the just-copied collision block at this+6200. [callee:0x00436470, source:raw]
    // CALL: Copy collision geometry block 1: CollisionStructCopy(this+6300, a3+408) transfers the second 72-byte collision struct into the snapshot. [callee:0x004363F0, source:raw]
    // CALL: Evaluate the second quadratic-spring term: QuadraticSpringEval(v5, (double)*(int*)(a2+3652) * *(double*)(a2+3640) + *(double*)(a2+3632)); result lands in the collision block at this+6300. [callee:0x00436470, source:raw]
    // ASSIGNMENT: State flag and zero init: copy the byte at a3+492 into this+6400 and write literal 0 into this+6404. [field:this:0x00001900, field:this:0x00001904]
    // ASSIGNMENT: Force parameters from source: this+6416 = a3+496 and this+6420 = a3+500; the same two dwords are re-copied from a3 later in the function. [field:this:0x00001910, field:this:0x00001914]
    // ASSIGNMENT: Torque parameters from source: this+6456/6460/6464/6468 = a3+552/556/560/564; these four dwords are re-copied from a3 later in the function. [field:this:0x00001938, field:this:0x0000193C, field:this:0x00001940, field:this:0x00001944]
    // LOOP: Six-iteration do/while loop: qmemcpy 24 bytes per iteration from a3+568 into this+6496, advancing both cursors by 24; copies 144 bytes of wheel/damper data. The same block is re-copied once more later. [function:0x0043BC20, source:raw]
    // ASSIGNMENT: Tail 24-byte copy of the wheel/damper block: qmemcpy(this+6640, a3+712, 0x18); re-copied once more later. [function:0x0043BC20, source:raw]
    // ASSIGNMENT: Force-rate group from source: this+6056..6076 = a3+528..548 (six dwords). [field:this:0x000017A8, field:this:0x000017AC, field:this:0x000017B0, field:this:0x000017B4, field:this:0x000017B8, field:this:0x000017BC]
    // ASSIGNMENT: Force/torque vector group from source: this+6080..6096 = a3+504..520 (five dwords) and this+6100 = a3+524. [field:this:0x000017C0, field:this:0x000017C4, field:this:0x000017C8, field:this:0x000017CC, field:this:0x000017D0, field:this:0x000017D4]
    // ASSIGNMENT: Mirror the force-rate group into this+7176..7188: read back this+6056/6060/6080/6084 and store into this+7176/7180/7184/7188 respectively. [field:this:0x00001C08, field:this:0x00001C0C, field:this:0x00001C10, field:this:0x00001C14, field:this:0x000017A8, field:this:0x000017AC, field:this:0x000017C0, field:this:0x000017C4]
    // CALL: Quadratic force evaluation: QuadFunctionEval(this, (double)*(int*)(a2+4740) * *(double*)(a2+4728) + *(double*)(a2+4720)); returns a result-block pointer used by the following copies. [callee:0x0043BB30, source:raw]
    // ASSIGNMENT: From the quad-eval result block (v14): copy the byte at v14+760 into this+6664, and the dwords v14+812/v14+816 into this+6676/this+6680. [field:this:0x00001A08, field:this:0x00001A14, field:this:0x00001A18]
    // LOOP: Six-iteration do/while loop: qmemcpy 24 bytes per iteration from v14+820 into this+6708, advancing both cursors by 24; copies 144 bytes. [function:0x0043BC20, source:raw]
    // ASSIGNMENT: Tail 24-byte copy of the quad-eval block: qmemcpy(this+6852, v14+964, 0x18). [function:0x0043BC20, source:raw]
    // ASSIGNMENT: Quad force parameters into this+6104..6124 from v14+788..808 (six dwords). [field:this:0x000017D8, field:this:0x000017DC, field:this:0x000017E0, field:this:0x000017E4, field:this:0x000017E8, field:this:0x000017EC]
    // ASSIGNMENT: Quad force/torque vectors into this+6128..6148 from v14+764..784 (six dwords). [field:this:0x000017F0, field:this:0x000017F4, field:this:0x000017F8, field:this:0x000017FC, field:this:0x00001800, field:this:0x00001804]
    // ASSIGNMENT: Mirror four quad-eval results into this+7232..7244 from this+6104/6108/6128/6132. [field:this:0x00001C40, field:this:0x00001C44, field:this:0x00001C48, field:this:0x00001C4C]
    // CALL: Quadratic force/torque computation: QuadraticForceTorqueCalculator(this, (double)*(int*)(a2+4804) * *(double*)(a2+4792) + *(double*)(a2+4784)); returns a result-block pointer used by the following copies. [callee:0x0043BB80, source:raw]
    // ASSIGNMENT: From the force/torque result block (v16): this+6184..6196 = v16+4864..4876 (four dwords) and this+6884..6904 = v16+1020..1040 (six dwords). [field:this:0x00001828, field:this:0x0000182C, field:this:0x00001830, field:this:0x00001834, field:this:0x00001AE4, field:this:0x00001AE8, field:this:0x00001AEC, field:this:0x00001AF0, field:this:0x00001AF4, field:this:0x00001AF8]
    // LOOP: Six-iteration do/while loop: qmemcpy 24 bytes per iteration from v16+1068 into this+6932, advancing both cursors by 24; copies 144 bytes. [function:0x0043BC20, source:raw]
    // ASSIGNMENT: Tail 24-byte copy of the force/torque block: qmemcpy(this+7076, v16+1212, 0x18). [function:0x0043BC20, source:raw]
    // CALCULATION: Spring offset computation: v18 = (double)*(int*)(a2+4932) * *(double*)(a2+4920) + *(double*)(a2+4912). Scale the double at this+6152 by v18 * *(double*)(v16+1328) + *(double*)(this+7060), and the double at this+6168 by v18 * *(double*)(v16+1320) + *(double*)(v16+1012). [field:this:0x00001808, field:this:0x00001818, field:this:0x00001B94]
    // ASSIGNMENT: Spring geometry group: this+6160/6164 = v16+1312/1316 and this+6176/6180 = v16+1304/1308. [field:this:0x00001810, field:this:0x00001814, field:this:0x00001820, field:this:0x00001824]
    // ASSIGNMENT: Mirror spring scalars into this+7200..7212 from this+6152/6156/6168/6172. [field:this:0x00001C20, field:this:0x00001C24, field:this:0x00001C28, field:this:0x00001C2C, field:this:0x0000180C, field:this:0x0000181C]
    // CALL: Spring/damper computation: SpringDamperCompute(this, (double)*(int*)(a2+4868) * *(double*)(a2+4856) + *(double*)(a2+4848)); returns a result-block pointer that is returned to the caller. [callee:0x0043BBD0, source:raw]
    // ASSIGNMENT: From the spring/damper result block: copy the byte at result+1236 into this+7100, the double at result+1240 into this+7104 and mirror it into this+7216, and the eight dwords result+1248..1276 into this+7112..7140. [field:this:0x00001BBC, field:this:0x00001BC0, field:this:0x00001BC8, field:this:0x00001BCC, field:this:0x00001BD0, field:this:0x00001BD4, field:this:0x00001BD8, field:this:0x00001BDC, field:this:0x00001BE0, field:this:0x00001BE4, field:this:0x00001C30]
    // RETURN: Return the SpringDamperCompute result-block pointer. [source:raw]

    // Conservative worker pseudocode:
    //   // copy two 72-byte collision blocks from a3 into this+6200/this+6300
    //   // evaluate the two quadratic-spring terms (a2 descriptors) into those blocks
    //   // state flag byte + zero init + force/torque param copies from a3 (force/torque params re-copied below)
    //   // 6x24-byte wheel/damper block + 24-byte tail from a3 (re-copied once more below)
    //   // mirror force-rate group into this+7176..7188
    //   // QuadFunctionEval -> flag byte, quad force params, 6x24-byte block + tail; mirror into this+7232..7244
    //   // QuadraticForceTorqueCalculator -> geometry dwords, force/torque vectors, 6x24-byte block + tail
    //   // v18 = a2[4932]*a2[4920]+a2[4912]; spring scalars this+6152/this+6168 = v18*src + offset; mirror
    //   // SpringDamperCompute -> flag byte + scalar double (mirrored) + 8-dword vector; return result pointer
    // UNRESOLVED: CollisionStructCopy destinations this+6200 and this+6300, and the three 6x24-byte loop destinations (this+6496, this+6708, this+6932) plus their 24-byte tails (this+6640, this+6852, this+7076) have no packet field entries; their internal layout is inferred only from copy sizes.
    // UNRESOLVED: QuadraticSpringEval receives v4/v5 which are uninitialized in the pseudocode; the destination block is the just-copied collision struct at this+6200/this+6300 (DERIVED from the existing fill, no direct field evidence).
    // UNRESOLVED: a2 (parameter descriptor) and a3 (source physics block) are not tied to named structs; their offsets are preserved as decimal per the packet source.
    // UNRESOLVED: The duplicate re-copies of this+6416/6420/6456..6468 and of the this+6496/this+6640 block (source lines 74-93) appear twice; treated as redundant double-writes, semantic significance unknown.
}
