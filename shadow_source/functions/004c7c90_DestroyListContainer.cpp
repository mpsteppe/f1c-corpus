// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C7C90
// Canonical corpus name: sub_4C7C90
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4C7C90_004c7c90.c

void UnknownObject::DestroyListContainer()
{
    // Destroys the global container/list object at byte_8AC494 by calling ListDestructorWithSubFree on it and returns that call's integer result. The same object is reset by 004C7C70, so these two functions form the create/reset and destroy pair for the byte_8AC494 container.
    // CALL: Call ListDestructorWithSubFree with the container base pointer &byte_8AC494 to destroy its contents. [global:0x008AC494, source:raw]
    // RETURN: Return the ListDestructorWithSubFree result directly as the function's integer result. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4C7C90(void) {
    //     return ListDestructorWithSubFree(&byte_8AC494);
    //   }
    // UNRESOLVED: The callee ListDestructorWithSubFree has no callee entry in this packet, so its own address and behavior are not evidenced here.
    // UNRESOLVED: Identity and element type of the container at byte_8AC494 are unknown.
}
