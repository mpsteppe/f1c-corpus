// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00568320
// Canonical corpus name: sub_568320
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_568320_00568320.c

void UnknownObject::sub_568320()
{
    // Hash-bucket tree insertion keyed by a string. Computes a hash index v8 = StringHash(StringPointerAccessor(a2)) into the bucket array `this`; based on flags read from a2 (a2[1], a2[3], a2[9], a2[10]) and the result of sub_563E70(a2), inserts one of a2's node pointers (a2[1] or a2[3]) as the new bucket root or relinks it into the existing tree rooted at the bucket, updating tree links at node offsets +4/+8/+12/+36/+40. Always finishes by freeing a2 via RecursiveTreeTraversalFree and returns 0.
    // GUARD: The whole insertion body runs only when a2 is non-null; a null a2 skips to the cleanup/free path. [source:raw]
    // CALL: Call sub_563E70(a2) and record v12 = (result == 0) as a branch flag. [callee:0x00563E70, source:raw]
    // CALCULATION: Read flags from the a2 container: v5=a2[9], v6=(a2[1]!=0), v13=(a2[3]!=0), v11=(a2[9]!=0), v10 = !(a2[9] || a2[10]). [source:raw]
    // CALL: Obtain the key string via StringPointerAccessor(a2). [callee:0x00499E20, source:raw]
    // CALL: Hash the key string with StringHash to produce the bucket index v8 used to select this[v8]. [callee:0x00567D00, source:raw]
    // ASSIGNMENT: Insert into the bucket this[v8]: when v12 (and v10), store a2[3] or a2[1] as the bucket root and clear/set its links (+4, +40); otherwise relink the existing root's +8 child pointer to a2[3]/a2[1] and set +4/+12/+36/+40 parent/neighbor links across the tree nodes. [source:raw, function:0x00568320]
    // CALL: Free the source container a2 (and any tree it owns) via RecursiveTreeTraversalFree before returning 0. [callee:0x00567A90, source:raw]
    // RETURN: Every path returns 0 (success), including the early returns after a successful insert-and-free. [source:raw]
    // CALL: Invoked by ObjectIDLookupAcross9Arrays as an object-ID insertion helper. [caller:0x005684A0]

    // Conservative worker pseudocode:
    //   char sub_568320(_DWORD *this, _DWORD *a2) {
    //     if (a2) {
    //       int v4 = sub_563E70(a2);
    //       int v5 = a2[9];
    //       bool v12 = (v4 == 0);
    //       bool v6 = (a2[1] != 0);
    //       bool v13 = (a2[3] != 0);
    //       bool v11 = (v5 != 0);
    //       bool v10 = !(v5 || a2[10]);
    //       char *v7 = StringPointerAccessor(a2);
    //       int v8 = StringHash(v7);
    //       if (v12) {
    //         if (v10) {
    //           if (v13) { this[v8] = a2[3]; *(DWORD*)(a2[3]+40) = 0; *(DWORD*)(a2[3]+4) = a2[1]; RecursiveTreeTraversalFree(a2); return 0; }
    //           this[v8] = a2[1]; goto L14;
    //         }
    //       } else if (v10) {
    //         if (v13) { *(DWORD*)(*a2+8) = a2[3]; *(DWORD*)(a2[3]+40) = 0; *(DWORD*)(a2[3]+4) = a2[1]; *(DWORD*)a2[3] = *a2; RecursiveTreeTraversalFree(a2); return 0; }
    //         *(DWORD*)(*a2+8) = a2[1];
    //   L14:  if (v6) { *(DWORD*)(a2[1]+36) = 0; RecursiveTreeTraversalFree(a2); return 0; }
    //       }
    //       if (v11) {
    //         *(DWORD*)(a2[9]+4) = a2[1];
    //         if (v6) { *(DWORD*)(a2[1]+36) = a2[9]; RecursiveTreeTraversalFree(a2); return 0; }
    //       } else {
    //         *(DWORD*)(a2[10]+12) = a2[3];
    //         if (v13) *(DWORD*)(a2[3]+40) = a2[10];
    //       }
    //     }
    //     RecursiveTreeTraversalFree(a2);
    //     return 0;
    //   }
    // UNRESOLVED: Semantics of the tree links at node offsets +4, +8, +12, +36, +40 (which are parent/child/neighbor fields) is not named by the packet; the node layout is unknown.
    // UNRESOLVED: Meaning of sub_563E70's return and why it selects a separate insertion branch is unresolved.
    // UNRESOLVED: Whether `this` is a flat hash table of bucket roots or a 9-slot object-ID table (per the caller name ObjectIDLookupAcross9Arrays) is not evidenced here.
}
