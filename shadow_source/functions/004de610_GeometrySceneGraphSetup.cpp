// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DE610
// Canonical corpus name: sub_4DE610
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4DE610_004de610.c

void UnknownObject::GeometrySceneGraphSetup()
{
    // Scene-graph geometry setup. Stores the root scene node into this+0x4, reads the child count into this+0x8 via SceneGraphChildCount, and allocates a per-child record array (this+0xC) of 12-byte records. For every child it resolves the packed element list, copies position/normal/index data into 64-byte sorted records, and builds triangle-adjacency links from the per-node triangle list. It then allocates the output transform array (24-byte records, this+0x14) from a2[3], copies 24-byte transforms from a2[4], optionally subtracts a node position offset when the byte flag at (this+0x4)+0x46 is set, and builds a per-entry two-pass index buffer. Returns the transform array data pointer.
    // ASSIGNMENT: Store the scene-graph root pointer a3 into this+0x4; the setup object now owns the node pointer that later field reads (including the +0x46 flag and the position-offset source) dereference. [field:this:0x00000004, source:raw]
    // CALL: Query the root scene-graph node for its child count with SceneGraphChildCount(*a3) and store it into this+0x8. [callee:0x0054C210, field:this:0x00000008, source:raw]
    // CALL: Allocate the per-child record array via OperatorNewNhMallocWrapper(12*count+4); store the count in the header word and zero 3 dwords (12 bytes) per child; keep the data pointer in this+0xC. [callee:0x00587C03, field:this:0x0000000C, source:raw]
    // GUARD: Guard: run the per-child setup only while this+0x8 (child count) is greater than 0. [field:this:0x00000008, guard:0, source:raw]
    // LOOP: Per child: fetch the scene node with LinkedListIndexedAccessor_c230(childIndex) into record+0, store PackedArrayTotalSize(node) into record+4, and allocate the packed vertex buffer (count*64 bytes) via OperatorNewNhMallocWrapper into record+8. [callee:0x0054C230, callee:0x0054E100, callee:0x00587C03, source:raw]
    // LOOP: Per packed element (resolved with PackedArrayIndexLookup(i)): copy position (x/y/z from src+0/+4/+8) and normal (src+12/+16/+20) plus the +24 index into the 64-byte slot, then zero 28 bytes after the 36-byte header (memset 0x1C). [callee:0x0054E120, source:raw]
    // CALCULATION: Seed the slot +16 field from *a2 and, for each of the a2[1] reference records, keep the smaller +16 value (minimum selection; the raw v24|v25 FP-flag guard is ambiguous). [source:raw]
    // CALL: Sort the per-child packed vertex array with sub_5890AA(base, count, 64, compare), passing sub_4DE590 as the comparison callback. [callee:0x005890AA, global:0x004DE590, source:raw]
    // GUARD: Guard: build triangle-adjacency links only when the per-node triangle count at (*childRecord + 288) is greater than 0. [source:raw]
    // CALL: Resolve the three triangle vertices by calling sub_4DE5D0(triangleBase, i) for i in 0..2. [callee:0x004DE5D0, source:raw]
    // CALCULATION: Compute the z-extent of the three vertices, shrink the lower bound by 0.0049999999 into v79 and grow the upper bound by the same epsilon into v67. [source:raw]
    // LOOP: Binary-search the sorted vertex array over the +12 z field to find the record range whose z lies in [v79, v67]. [source:raw]
    // GUARD: For each candidate record in range, proceed only while record+28 + 0.0049999999 >= fabs(record+16 - candidate[1]), a positional window test. [source:raw]
    // CALL: Compute the current triangle's face normal with TriangleNormalComputation(v0, v1, v2, &v87). [callee:0x004DD9F0, source:raw]
    // CALCULATION: Test the dot product of the face normal with the candidate record's normal (record+1..+3); only candidates with dot > 0.0 enter the adjacency walk. [callee:0x004DD9F0, source:raw]
    // LOOP: Walk the candidate's adjacency slots (+36, up to 7 entries): for each linked neighbour resolve its vertices with sub_4DE5D0 and recompute TriangleNormalComputation; stop early when a neighbour shares the same normal, otherwise continue up to the 7-slot limit. [callee:0x004DE5D0, callee:0x004DD9F0, source:raw]
    // ASSIGNMENT: When the adjacency walk reaches an empty slot, append the triangle index (v78) into the record's adjacency list (record+36+v41). [source:raw]
    // ASSIGNMENT: Store a2[3] into this+0x10, allocate the output transform array via OperatorNewNhMallocWrapper(24*count+4), zero 6 dwords (24 bytes) per entry, and keep the data pointer in this+0x14. [callee:0x00587C03, field:this:0x00000010, field:this:0x00000014, source:raw]
    // GUARD: Guard: when this+0x10 is not greater than 0, set this+0x18 to 0 and skip the transform-fill loop. [field:this:0x00000010, field:this:0x00000018, guard:1, source:raw]
    // LOOP: Per output transform entry: copy 24 bytes from a2[4] and zero the entry +16 field. [source:raw]
    // GUARD: If the byte flag at (this+0x4)+0x46 is set, subtract the offsets at (this+0x4)+0x4/+0x8/+0xC from the entry x/y/z. [field:this:0x00000004, field:this:0x00000046, source:raw]
    // LOOP: Two-pass index build per entry: pass 0 counts candidate records (v76) across all child records (+4 count, 12-byte stride, +8 base); pass 1 allocates the index buffer (4*v76) via OperatorNewNhMallocWrapper at entry+20 and appends each candidate's index (record+8 + 64*idx) to it. [callee:0x00587C03, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // ASSIGNMENT: On the transform-fill path, terminate with this+0x18 = 0. [field:this:0x00000018, source:raw]
    // RETURN: Return the built transform data pointer, which was also stored at this+0x14. [field:this:0x00000014, source:raw]

    // Conservative worker pseudocode:
    //   this[1] = a3; this[2] = SceneGraphChildCount(*a3);
    //   this[3] = alloc(12*count+4, header=count, zero 12 bytes per child);
    //   if (this[2] > 0) for each child i:
    //     node = LinkedListIndexedAccessor_c230(i); rec+0 = node; rec+4 = PackedArrayTotalSize(node); rec+8 = alloc(rec+4 * 64);
    //     for each packed element: v = PackedArrayIndexLookup(k); copy pos/normal/index into 64-byte slot; memset(slot+36, 0, 0x1C);
    //     keep min of slot+16 across a2[1] reference records;
    //     sort(rec+8, rec+4, 64, sub_4DE590);
    //     if (*(*rec + 288) > 0) for each triangle:
    //       (v0, v1, v2) = sub_4DE5D0(base, i); compute z range +/- 0.0049999999;
    //       binary-search sorted array for records with +12 z inside the range;
    //       for candidates in the window: if (rec+28 + eps >= fabs(rec+16 - cand[1])):
    //         TriangleNormalComputation(v0, v1, v2, &n);
    //         if (dot(n, cand+1..+3) > 0.0):
    //           walk adjacency slots (+36, max 7): if neighbour normal equals n break;
    //           else if a slot is empty store the triangle index there;
    //   this[4] = a2[3]; this[5] = alloc(24*count+4, header=count, zero 24 bytes per entry);
    //   if (this[4] <= 0) this[6] = 0;
    //   else for each entry: qmemcpy(entry, a2[4]+i*24, 24); entry[4] = 0.0;
    //     if (*(*(this+0x4) + 0x46)) entry.xyz -= *(*(this+0x4)+0x4/+0x8/+0xC);
    //     for j in 0..1: if j==1 entry+20 = alloc(4*v76); count candidate records; fill the index buffer;
    //     this[6] = 0;
    //   return this[5];
    // UNRESOLVED: Globals flt_59E440, flt_5ACD3C, flt_5AD13C are referenced by the function in the IDB but do not appear in the raw decompiled body; their roles here are unknown.
    // UNRESOLVED: The v24|v25, v39|v40, v62|v63 FP condition-code guards are Hex-Rays artifacts of comparison flags; the exact relational operators are not determinable from the packet.
    // UNRESOLVED: The a2 argument points to an unnamed source descriptor (a2[0..4] are used: seed value, reference count, reference base, transform count, transform source); its structure is unverified.
    // UNRESOLVED: Single caller is sub_4E3360 (0x004E3360); the caller-side invocation context is not analyzed here.
}
