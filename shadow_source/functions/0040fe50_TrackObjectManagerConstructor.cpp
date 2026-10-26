// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040FE50
// Canonical corpus name: sub_40FE50
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_40FE50_0040fe50.c

void UnknownObject::TrackObjectManagerConstructor()
{
    // Constructor-style initializer for the dynamic track-object manager (the global instance dword_5EA560, called from DynMan_Init). Allocates and fills a fixed 104-entry vehicle data array (36-byte entries seeded from the static table at unk_5EC6E4), then walks the scene node list (count from AudioNetworkNodeCount) and categorizes each linked-list node by its name string (dspoly, dsindicator, dscone, cone, post, sign, wheel, wing, part) into per-category count buckets kept in a local scratch array. For each category it allocates a small 36-byte-entry array and a large vtable-led array (792/808-byte entries with off_59E720 as the initial vtable), fills the small arrays from the scratch buckets and the large arrays from the buckets plus reserved capacity (wheel +416, wing +208, part +832) with static per-object data, appends five global node pointers (dword_8AD074..8AD084) to the dspoly bucket, and finally allocates a combined pointer array of total-count entries returned to the caller.
    // ASSIGNMENT: Set the fixed vehicle count: this[3] = 104. [field:this:0x0000000C, source:raw]
    // CALL: Allocate the vehicle data array: v3 = OperatorNewNhMallocWrapper(3748) (104 * 36 + 4); on success write the count header *v3 = 104 and initialize 104 entries of 36 bytes with StructInitializerWithSentinelValues. [callee:0x00587C03, callee:0x0040E6D0, field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Store the array pointer: this[4] = v4 (v4 = 0 when allocation failed). [field:this:0x00000010, source:raw]
    // LOOP: Seed each vehicle entry: for index 0 while index < this[3], call ShortComputation_e860(this[4] + 36*index, index, unk_5EC6E4 + 18624*index); the static table unk_5EC6E4 is read in 18624-byte strides. [callee:0x0040E860, field:this:0x00000010, field:this:0x0000000C, global:0x005EC6E4, source:raw]
    // ASSIGNMENT: Reset all category count buckets to 0: this[24], this[21], this[18], this[15], this[12], this[9], this[5], this[7] = 0. [field:this:0x00000060, field:this:0x00000054, field:this:0x00000048, field:this:0x0000003C, field:this:0x00000030, field:this:0x00000024, field:this:0x00000014, field:this:0x0000001C, source:raw]
    // CALL: v12 = AudioNetworkNodeCount(dword_8AFE88): count the scene nodes; allocate v148 = OperatorNewNhMallocWrapper(4 * v12 + 4) as the node-pointer list. [callee:0x005452F0, global:0x008AFE88, callee:0x00587C03, source:raw]
    // LOOP: For each node index v11 from 0 while v11 < v12: v13 = LinkedListNodeFinder(v11) resolves the node; the loop body classifies it by name. [callee:0x00545340, source:raw]
    // GUARD: Node flag test: when (*(_DWORD*)(v13 + 60) & 0x10) == 0x10 the node carries a named-object bit and enters the flag-set branch. [source:raw]
    // CALL: Flag-set branch: SelfRelativeStringCopy(v149) copies the node name; then for each of dspoly, dsindicator, dscone, cone, post, sign, wheel, wing, part the code compares with sub_588640(name, literal, len) and on a match stores v13 into the corresponding v150 bucket and increments that category count (this[5] for dspoly/dsindicator at +64, this[9] for dscone/cone at +1088, this[12] for post at +3136, this[15] for sign at +5184, this[18] for wheel at +2112, this[21] for wing at +4160, this[24] for part at +6208). [callee:0x0054BDA0, callee:0x00588640, global:0x005BEBA4, global:0x005BEB98, global:0x005BEB90, global:0x005BEB88, global:0x005BEB80, global:0x005BEB78, global:0x005BEB70, global:0x005BEB68, global:0x005BEB60, field:this:0x00000014, field:this:0x00000024, field:this:0x00000030, field:this:0x0000003C, field:this:0x00000048, field:this:0x00000054, field:this:0x00000060, source:raw]
    // CALL: After classifying the flagged node, call SceneNodeVisibilityToggle(0). [callee:0x0054FB40, source:raw]
    // GUARD: Non-flag branch: copy the name into v150; when it is neither dspoly nor dsindicator, test LinkedListFlagBitExtraction(v13) and that v13 is not one of dword_8AD074..dword_8AD084 before appending it to the special list v148[this[7]++]. [callee:0x0054BDA0, callee:0x00588640, callee:0x0054FB70, global:0x008AD074, global:0x008AD078, global:0x008AD07C, global:0x008AD080, global:0x008AD084, field:this:0x0000001C, source:raw]
    // STATE_TRANSITION: Non-flag branch fall-through: if the node name is dspoly or dsindicator, store it into the this[5] bucket at v150[4*this[5]+64] like the flag-set branch. [callee:0x00588640, callee:0x0054BDA0, field:this:0x00000014, source:raw]
    // CALCULATION: Reserve capacity: this[24] += 832, this[21] += 208, this[18] += 416. These extra counts (which equal the large-array fill thresholds below) size the part/wing/wheel large arrays. [field:this:0x00000060, field:this:0x00000054, field:this:0x00000048, source:raw]
    // GUARD: Append the five global node pointers dword_8AD074, dword_8AD078, dword_8AD07C, dword_8AD080, dword_8AD084 to the this[5] dspoly bucket when each is non-null. [global:0x008AD074, global:0x008AD078, global:0x008AD07C, global:0x008AD080, global:0x008AD084, field:this:0x00000014, source:raw]
    // CALL: Allocate the dspoly small array: v33 = OperatorNewNhMallocWrapper(36 * this[5] + 4), header *v33 = this[5], each 36-byte entry initialized with StructInitializerWithSentinelValues; store this[6] = v34. [callee:0x00587C03, callee:0x0040E6D0, field:this:0x00000014, field:this:0x00000018, source:raw]
    // LOOP: Fill the dspoly small array: for index while index < this[5], StructFieldInitializer_e880(this[6] + 36*index, index, v150[4*index + 64]). [callee:0x0040E880, field:this:0x00000018, field:this:0x00000014, source:raw]
    // CALL: Allocate the non-DSP array: v41 = OperatorNewNhMallocWrapper(36 * this[7] + 4), header *v41 = this[7], 36-byte entries via StructInitializerWithSentinelValues; store this[8] = v42. [callee:0x00587C03, callee:0x0040E6D0, field:this:0x0000001C, field:this:0x00000020, source:raw]
    // LOOP: Fill the non-DSP array: for index while index < this[7], StructSetupWithTwoCalls(this[8] + 36*index, index, v148[index]); then FreeWrapper_7bcf(v148) releases the temporary node list. [callee:0x0040E8B0, field:this:0x00000020, field:this:0x0000001C, callee:0x00587BCF, source:raw]
    // CALL: Cone small array: v50 = OperatorNewNhMallocWrapper(36 * this[9] + 4), header count, 36-byte entries via StructInitializerWithSentinelValues; store this[10] = v56. [callee:0x00587C03, callee:0x0040E6D0, field:this:0x00000024, field:this:0x00000028, source:raw]
    // CALL: Cone large array: v58 = OperatorNewNhMallocWrapper(792 * this[9] + 4), header count; each 792-byte entry runs ShortComputation_8e30(entry + 53 dwords), sets *entry = &off_59E720, StructInitWithFloatConstants(entry), then *entry = &off_59E768; store this[11] = v63. [callee:0x00587C03, callee:0x00568E30, callee:0x004594D0, global:0x0059E720, global:0x0059E768, field:this:0x00000024, field:this:0x0000002C, source:raw]
    // GUARD: Cone fill guard: when this[9] > 0, loop index 0 while index < this[9] calling StructInitWithFloatConstantsAndSubCalls(this[10] + 36*index, index, this[11] + 792*index, v150[4*index + 1088]). [guard:0, callee:0x0040E8F0, field:this:0x00000028, field:this:0x0000002C, field:this:0x00000024, source:raw]
    // CALL: Post small array: v68 = OperatorNewNhMallocWrapper(36 * this[12] + 4), header count, entries via StructInitializerWithSentinelValues; store this[13] = v72. [callee:0x00587C03, callee:0x0040E6D0, field:this:0x00000030, field:this:0x00000034, source:raw]
    // CALL: Post large array: v74 = OperatorNewNhMallocWrapper(792 * this[12] + 4), header count; each entry runs ShortComputation_8e30, sets *entry = &off_59E720, StructInitWithFloatConstants, then *entry = &off_59E75C; store this[14] = v77. [callee:0x00587C03, callee:0x00568E30, callee:0x004594D0, global:0x0059E720, global:0x0059E75C, field:this:0x00000030, field:this:0x00000038, source:raw]
    // GUARD: Post fill guard: when this[12] > 0, loop calling StructInitWithFloatConstantsAndSubCalls_e990(this[13] + 36*index, index, this[14] + 792*index, v150[4*index + 3136]). [guard:1, callee:0x0040E990, field:this:0x00000034, field:this:0x00000038, field:this:0x00000030, source:raw]
    // CALL: Sign small array: v82 = OperatorNewNhMallocWrapper(36 * this[15] + 4), header count, entries via StructInitializerWithSentinelValues; store this[16] = v86. [callee:0x00587C03, callee:0x0040E6D0, field:this:0x0000003C, field:this:0x00000040, source:raw]
    // CALL: Sign large array: v88 = OperatorNewNhMallocWrapper(792 * this[15] + 4), header count; each entry runs ShortComputation_8e30, sets *entry = &off_59E720, StructInitWithFloatConstants, then *entry = &off_59E750; store this[17] = v91. [callee:0x00587C03, callee:0x00568E30, callee:0x004594D0, global:0x0059E720, global:0x0059E750, field:this:0x0000003C, field:this:0x00000044, source:raw]
    // GUARD: Sign fill guard: when this[15] > 0, loop calling sub_40EA30(this[16] + 36*index, index, this[17] + 792*index, v150[4*index + 5184]). [guard:2, callee:0x0040EA30, field:this:0x00000040, field:this:0x00000044, field:this:0x0000003C, source:raw]
    // CALL: Wheel small array: v96 = OperatorNewNhMallocWrapper(36 * this[18] + 4), header count, entries via StructInitializerWithSentinelValues; store this[19] = v100. [callee:0x00587C03, callee:0x0040E6D0, field:this:0x00000048, field:this:0x0000004C, source:raw]
    // CALL: Wheel large array: v102 = OperatorNewNhMallocWrapper(808 * this[18] + 4), header count; each 808-byte entry (202 dwords) runs ShortComputation_8e30, sets *entry = &off_59E720, StructInitWithFloatConstants, then *entry = off_59E744; store this[20] = v105. [callee:0x00587C03, callee:0x00568E30, callee:0x004594D0, global:0x0059E720, global:0x0059E744, field:this:0x00000048, field:this:0x00000050, source:raw]
    // GUARD: Wheel fill guard: when this[18] > 0, loop calling CameraProjectionMatrixInitWithFloatConstants(this[19] + 36*index, index, v145, v146); for the first 416 entries (v108 < 336128) v145/v146 come from the array-relative form, beyond that from the local pointer table v148 (v147[532]). [guard:3, callee:0x0040EB30, field:this:0x0000004C, field:this:0x00000050, field:this:0x00000048, source:raw]
    // CALL: Wing small array: v112 = OperatorNewNhMallocWrapper(36 * this[21] + 4), header count, entries via StructInitializerWithSentinelValues; store this[22] = v116. [callee:0x00587C03, callee:0x0040E6D0, field:this:0x00000054, field:this:0x00000058, source:raw]
    // CALL: Wing large array: v118 = OperatorNewNhMallocWrapper(792 * this[21] + 4), header count; each entry runs ShortComputation_8e30, sets *entry = &off_59E720, StructInitWithFloatConstants, then *entry = &off_59E738; store this[23] = v121. [callee:0x00587C03, callee:0x00568E30, callee:0x004594D0, global:0x0059E720, global:0x0059E738, field:this:0x00000054, field:this:0x0000005C, source:raw]
    // GUARD: Wing fill guard: when this[21] > 0, loop calling UtilityFunction_ebd0(this[22] + 36*index, index, v145, v146); for the first 208 entries (v124 < 164736) v145/v146 use the array-relative form, beyond that the local pointer table. [guard:4, callee:0x0040EBD0, field:this:0x00000058, field:this:0x0000005C, field:this:0x00000054, source:raw]
    // CALL: Part small array: v128 = OperatorNewNhMallocWrapper(36 * this[24] + 4), header count, entries via StructInitializerWithSentinelValues; store this[25] = v132. [callee:0x00587C03, callee:0x0040E6D0, field:this:0x00000060, field:this:0x00000064, source:raw]
    // CALL: Part large array: v134 = OperatorNewNhMallocWrapper(792 * this[24] + 4), header count; each entry runs ShortComputation_8e30, sets *entry = &off_59E720, StructInitWithFloatConstants, then *entry = &off_59E72C; store this[26] = v137. [callee:0x00587C03, callee:0x00568E30, callee:0x004594D0, global:0x0059E720, global:0x0059E72C, field:this:0x00000060, field:this:0x00000068, source:raw]
    // GUARD: Part fill guard: when this[24] > 0, loop calling StructInitializerWithFloatConstants(this[25] + 36*index, index, v145, v146); for the first 832 entries (v140 < 658944) v145/v146 use the array-relative form, beyond that the local pointer table. [guard:5, callee:0x0040EC70, field:this:0x00000064, field:this:0x00000068, field:this:0x00000060, source:raw]
    // CALCULATION: Total and combined array: v143 = sum of all category counts (this[9] + this[15] + this[21] + this[5] + this[12] + this[18] + this[24] + this[3]); this[1] = v143; *this = 0. [field:this:0x00000024, field:this:0x0000003C, field:this:0x00000054, field:this:0x00000014, field:this:0x00000030, field:this:0x00000048, field:this:0x00000060, field:this:0x0000000C, field:this:0x00000004, field:this:0x00000000, source:raw]
    // CALL: Allocate the combined pointer array: result = OperatorNewNhMallocWrapper(4 * v143); store this[2] = result. [callee:0x00587C03, field:this:0x00000008, source:raw]
    // RETURN: Return result (the combined pointer array; the large local v150 forces a stack probe via __alloca_probe). [callee:0x005881C0, source:raw]
    // CALL: Invoked by DynMan_Init on the global instance dword_5EA560. [caller:0x0042C1A0, source:raw]

    // Conservative worker pseudocode:
    //   this[3] = 104;
    //   v4 = alloc(104*36 + 4); if (v4) { v4[-1] = 104; for each: StructInitializerWithSentinelValues(p); p += 36; }
    //   this[4] = v4;
    //   for (i = 0; i < this[3]; ++i) ShortComputation_e860(this[4] + 36*i, i, unk_5EC6E4 + 18624*i);
    //   zeroCounts();
    //   v12 = AudioNetworkNodeCount(dword_8AFE88); v148 = alloc(4*v12 + 4);
    //   for (v11 = 0; v11 < v12; ++v11) {
    //       v13 = LinkedListNodeFinder(v11);
    //       if ((*(DWORD*)(v13+60) & 0x10) == 0x10) {
    //           SelfRelativeStringCopy(v149);
    //           classifyNodeIntoBuckets(v13); SceneNodeVisibilityToggle(0);
    //       } else {
    //           SelfRelativeStringCopy(v150);
    //           if (dspoly && dsindicator) {
    //               if (LinkedListFlagBitExtraction(v13) && v13 not in {dword_8AD074..84}) v148[this[7]++] = v13;
    //           } else { dspolyOrIndicatorBucket(v13); }
    //       }
    //   }
    //   this[24] += 832; this[21] += 208; this[18] += 416;
    //   appendGlobalsToDspolyBucket();
    //   buildSmallAndLargeArrays();
    //   v143 = totalCount(); this[1] = v143; *this = 0;
    //   result = alloc(4 * v143); this[2] = result;
    //   return result;
    // UNRESOLVED: The exact role of the reserved capacity (wheel +416, wing +208, part +832) in the large arrays and the static per-object data read past the threshold (v148 pointer tables) is inferred from the threshold literals matching the capacity additions; the data source beyond the buckets is not confirmed.
    // UNRESOLVED: Whether unk_5EC6E4 + 18624*index is a per-vehicle static table or a scene-geometry table is unknown from this packet.
    // UNRESOLVED: The named category callees (StructInitializerWithSentinelValues, StructInitWithFloatConstants, etc.) are generic initializer names from the corpus, not confirmed class constructors.
    // UNRESOLVED: The meaning of the five global node pointers dword_8AD074..8AD084 (special objects appended to the dspoly bucket) is unknown.
    // UNRESOLVED: dword_8AFE88 passed to AudioNetworkNodeCount is assumed to be the scene-root/node-list handle from its call position.
}
