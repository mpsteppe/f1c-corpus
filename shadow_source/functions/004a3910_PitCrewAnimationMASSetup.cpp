// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A3910
// Canonical corpus name: PitCrewAnimationMASSetup
// Owner: PitCrewAnimationMASFileLoader [DERIVED]
// Raw source: functions/PitCrewAnimationMASSetup_004a3910.c

void PitCrewAnimationMASFileLoader::PitCrewAnimationMASSetup()
{
    // Loads pit-crew animation MAS files. Copies the 'pitguy' path prefix into the 16-bit header, builds the season/track sub-path (base override dword_5EC3D8, component override dword_5EC420, then 'pits'), selects a 'left' or 'normal' hand variant by byte_5EA3EC, registers the assembled path, resolves the animation MAS name via sub_53CBC0, and for each of two animation name constants (byte_5CD4A4, byte_5CD490) appends '.anm' and loads the file via sub_4A22D0. If the slot count (this+0x70) is high enough, sets animation ranges with RangeProportionInitializer and stores the resulting end values at this+0x7C/this+0x80. Frees the resolved MAS object. Called by sub_4A4900.
    // ASSIGNMENT: Zero the 16-bit header at this+0. [field:this:0x00000000, source:raw]
    // CALL: Copy the 'pitguy' animation path prefix aPitguycMts into this's header buffer via StringCopyWithReverse; reverse flag = (dword_7CF884 >= 1). [callee:0x004A21D0, global:0x005CD4C0, global:0x007CF884, field:this:0x00000000, source:raw]
    // CALL: Call Camera(this) during setup. [callee:0x004A3B50, source:raw]
    // ASSIGNMENT: Select base path: dword_5EC3D8 if nonzero else shared buffer byte_5EA438. [global:0x005EC3D8, global:0x005EA438, source:raw]
    // CALL: StringCopyWithBufferRealloc on the selected base path. [callee:0x00566650, global:0x005EC3D8, global:0x005EA438, source:raw]
    // CALL: Select second path component: dword_5EC420 if nonzero else byte_5EA438, then append it with sub_5665B0. [global:0x005EC420, global:0x005EA438, callee:0x005665B0, source:raw]
    // CALL: Append the 'pits' string aPits_0 to the assembled path. [global:0x005CD4B8, callee:0x005665B0, source:raw]
    // GUARD: If byte_5EA3EC is set append the 'left' variant aLeft, else append the 'normal' variant aNormal_0. [global:0x005EA3EC, global:0x005CD4B0, global:0x005C6E74, callee:0x005665B0, source:raw]
    // CALL: Register the assembled path string via StringRegistry(byte_5EA438). [callee:0x0053C800, global:0x005EA438, source:raw]
    // CALL: Reset a2 to 0 and resolve the animation MAS name via sub_53CBC0(&a2, aPitanimsMas); result pointer stored back into a2. [callee:0x0053CBC0, global:0x005CD480, source:raw]
    // LOOP: Copy the first animation name constant byte_5CD4A4 byte-by-byte into v15 until a zero terminator. [global:0x005CD4A4, source:raw]
    // CALL: StringCopyWithBufferRealloc(v15) to make a heap copy of the first animation name. [callee:0x00566650, source:raw]
    // CALL: Append the '.anm' extension aAnm to the animation name. [global:0x005CD49C, callee:0x005665B0, source:raw]
    // CALL: Load the first animation MAS via sub_4A22D0(this, v15, byte_5EA438, 0, 0). [callee:0x004A22D0, global:0x005EA438, source:raw]
    // GUARD: If the slot count at this+0x70 is greater than 0. [guard:0, field:this:0x00000070, source:raw]
    // CALL: RangeProportionInitializer on the animation data pointer *(this+0x74) with range [0.0, duration at *(this+0x74)+0x10]. [callee:0x004A1FD0, field:this:0x00000074, field:*(this+0x74):0x00000010, source:raw]
    // ASSIGNMENT: Store the range end value at this+0x7C (source register v8 uninitialized in decompiler output). [field:this:0x0000007C, source:raw]
    // LOOP: Copy the second animation name constant byte_5CD490 byte-by-byte into v15 until a zero terminator. [global:0x005CD490, source:raw]
    // CALL: StringCopyWithBufferRealloc(v15) to make a heap copy of the second animation name. [callee:0x00566650, source:raw]
    // CALL: Append the '.anm' extension aAnm to the second animation name. [global:0x005CD49C, callee:0x005665B0, source:raw]
    // CALL: Load the second animation MAS via sub_4A22D0(this, v15, byte_5EA438, 0, 0). [callee:0x004A22D0, global:0x005EA438, source:raw]
    // GUARD: If the slot count at this+0x70 is greater than 1. [guard:1, field:this:0x00000070, source:raw]
    // CALCULATION: Compute rangeUpper v14 = *(animData+0x2C) + *(this+0x7C), chaining the second range onto the first range end. [field:*(this+0x74):0x0000002C, field:this:0x0000007C, source:raw]
    // CALL: RangeProportionInitializer on *(animData+0x1C) with range [*(this+0x7C), v14] for the second animation. [callee:0x004A1FD0, field:this:0x00000074, field:this:0x0000007C, field:*(this+0x74):0x0000002C, source:raw]
    // ASSIGNMENT: Store the second range end value at this+0x80 (source register v12 uninitialized in decompiler output). [field:this:0x00000080, source:raw]
    // CALL: If the resolved MAS object a2 is nonzero, free it via PhysicsObjectLinkedListRemoval(a2). [callee:0x0053CE40, source:raw]
    // CALL: Finalize the shared path string via StringMatchWithFlagSet(byte_5EA438). [callee:0x0053C900, global:0x005EA438, source:raw]
    // CALL: Call ShortComputation_3fe0(this) before returning. [callee:0x004A3FE0, source:raw]
    // RETURN: Return 0 to the caller sub_4A4900. [caller:0x004A4900, function:0x004A3910, source:raw]

    // Conservative worker pseudocode:
    //   zero16(this+0);
    //   StringCopyWithReverse(this, a2, "pitguy"-path, 0, dword_7CF884 >= 1);
    //   Camera(this);
    //   base = dword_5EC3D8 ? dword_5EC3D8 : byte_5EA438;  StringCopyWithBufferRealloc(base);
    //   comp = dword_5EC420 ? dword_5EC420 : byte_5EA438;  append(comp);  append("pits");
    //   append(byte_5EA3EC ? "left" : "normal");
    //   StringRegistry(byte_5EA438);
    //   a2 = 0;  sub_53CBC0(&a2, "pitanims.mas");
    //   for each name in {byte_5CD4A4, byte_5CD490}:
    //       copy name to v15;  StringCopyWithBufferRealloc(v15);  append(".anm");
    //       sub_4A22D0(this, v15, byte_5EA438, 0, 0);
    //   if (slotCount(this+0x70) > 0):
    //       RangeProportionInitializer(animData, 0.0, animData.duration[0]);
    //       this+0x7C = animData.endValue;
    //   if (slotCount(this+0x70) > 1):
    //       RangeProportionInitializer(animData+0x1C, this+0x7C, this+0x7C + animData.offset_0x2C);
    //       this+0x80 = animData.endValue;
    //   if (a2) PhysicsObjectLinkedListRemoval(a2);
    //   StringMatchWithFlagSet(byte_5EA438);
    //   ShortComputation_3fe0(this);
    //   return 0;
    // UNRESOLVED: The raw decompiled text is a __thiscall on 'this' but the object layout (header buffer at +0, slot count at +0x70, animation-data pointer at +0x74, range ends at +0x7C/+0x80) is only partially evidenced; the '+0x1C' target of the second RangeProportionInitializer is an offset inference, not a packet field ref.
    // UNRESOLVED: The +4 reads at this+0x7C and this+0x80 use uninitialized decompiler registers (v8, v12); the true producer of those end values is not visible in the raw text.
    // UNRESOLVED: a2 is reused as the const char* input and then as the out-pointer of sub_53CBC0; the lifetime relationship between the input name and the resolved MAS object freed by PhysicsObjectLinkedListRemoval is not explicit.
    // UNRESOLVED: FreeWrapper_7bcf (0x00587BCF) is listed as a callee but no matching call appears in the raw decompiled text.
    // UNRESOLVED: dword_8AFE64 (0x008AFE64) is listed as a global but does not appear in the raw decompiled text.
    // UNRESOLVED: The semantic roles of Camera(this) and ShortComputation_3fe0(this) in the setup flow are unknown from this function alone.
}
