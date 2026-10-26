// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053CE40
// Canonical corpus name: PhysicsObjectLinkedListRemoval
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PhysicsObjectLinkedListRemoval_0053ce40.c

void UnknownObject::UnlinkAndFreePhysicsNode()
{
    // Removes a physics-object node from a global doubly-linked list (head at dword_8B8F14, prev/next links at node +0x12C/+0x130). Walks the next-pointer chain from the head until the target node a1 is found; returns 0 early if the chain ends without a match. Unlinks by patching the predecessor's next and the successor's prev, then if the node has no predecessor updates the global head to its successor. Runs DualFieldCleanupWithNullChecks and EmptyStub_7470 on the node, frees it via FreeWrapper_7bcf, and decrements the global physics-object count at dword_8B6AC0.
    // GUARD: Removal logic runs only while the global list head at dword_8B8F14 is non-null [global:0x008B8F14, source:raw]
    // LOOP: Walk the next-pointer chain at +0x130 from the head until the cursor equals a1; if the chain reaches 0 first, return 0 without unlinking [field:this:0x00000130, global:0x008B8F14, source:raw]
    // ASSIGNMENT: Unlink from the left: if the predecessor at +0x12C is non-null, its next pointer (+0x130) is set to the node's successor [field:this:0x0000012C, field:this:0x00000130, source:raw]
    // ASSIGNMENT: Unlink from the right: if the successor at +0x130 is non-null, its prev pointer (+0x12C) is set to the node's predecessor [field:this:0x0000012C, field:this:0x00000130, source:raw]
    // ASSIGNMENT: Head update: when the node has no predecessor (a1[75] at +0x12C is zero), the global head dword_8B8F14 becomes a1[76], the node's successor at +0x130 [field:this:0x0000012C, field:this:0x00000130, global:0x008B8F14, source:raw]
    // CALL: DualFieldCleanupWithNullChecks(a1) cleans up two fields of the node before teardown [callee:0x0055FE30, source:raw]
    // CALL: EmptyStub_7470(a1) is invoked as a debug/logging stub on the node [callee:0x00557470, source:raw]
    // CALL: FreeWrapper_7bcf(a1) releases the node memory [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Global physics-object count at dword_8B6AC0 is decremented after the removal [global:0x008B6AC0, source:raw]
    // RETURN: Returns 0 on both the not-found and the successful-removal paths [source:raw]
    // CALL: Reached from many cockpit, pit-crew, animation and special-FX setup/teardown paths (0049b0a0, 0049ca00, 0049cd80, 004a3220, 004a3910, 004a4900, 004cf070, 004d0110, 004d1450, 004d8ab0, 004dcba0, 004ddad0, 004f8d70, 004fc550) as a shared node teardown helper [caller:0x0049B0A0, caller:0x0049CA00, caller:0x0049CD80, caller:0x004A3220, caller:0x004A3910, caller:0x004A4900, caller:0x004CF070, caller:0x004D0110, caller:0x004D1450, caller:0x004D8AB0, caller:0x004DCBA0, caller:0x004DDAD0, caller:0x004F8D70, caller:0x004FC550, source:raw]

    // Conservative worker pseudocode:
    //   int sub_53CE40(a1) {
    //     result = dword_8B8F14;
    //     if (dword_8B8F14) {
    //       while (a1 != (void*)result) {
    //         result = *(int*)(result + 304);
    //         if (!result) return result;
    //       }
    //       v2 = *(int*)(result + 300);
    //       if (v2) *(int*)(v2 + 304) = *(int*)(result + 304);
    //       v3 = *(int*)(result + 304);
    //       if (v3) *(int*)(v3 + 300) = *(int*)(result + 300);
    //       if (!a1[75]) dword_8B8F14 = a1[76];
    //       DualFieldCleanupWithNullChecks(a1);
    //       EmptyStub_7470(a1);
    //       FreeWrapper_7bcf(a1);
    //       --dword_8B6AC0;
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: The exact owner type of the node is unknown; the many callers span unrelated subsystems so equal offsets do not prove identical classes.
    // UNRESOLVED: What DualFieldCleanupWithNullChecks releases (the two fields at +0x12C/+0x130 or other members) is not visible in this packet.
    // UNRESOLVED: Subsystem tag 'vehicle' plus the global count suggest a shared physics/resource object pool, unverified here.
}
