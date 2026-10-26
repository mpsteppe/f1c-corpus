// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059AC7F
// Canonical corpus name: ObjectTeardownWithIteratorCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectTeardownWithIteratorCleanup_0059ac7f.c

void UnknownObject::ObjectTeardownWithIteratorCleanup()
{
    // Teardown routine for an object that holds an array of facet pointers. Installs an SEH frame, iterates the facet array (array at this+0x8, count at this+0xC) from last slot to first, decrements each non-null facet's reference count via RefcountDecrementWithLock and conditionally destroys the facet whose count reached zero, frees the array allocation, releases the string buffer at this+6, and finally restores the vtable to std::locale::facet. Called by ExceptionDestructorWithConditionalFree (0059ac63).
    // CALL: Install the SEH handler frame on the stack before touching object state. [callee:0x0058A5D8]
    // ASSIGNMENT: Store the object base and set its vtable to off_5B9D4C, the facet-container vtable. [global:0x005B9D4C, source:raw]
    // CALL: Run the CRT-init prologue sub_59A54D. [callee:0x0059A54D]
    // LOOP: Iterate the facet array (this+0x8) from count (this+0xC) down to zero, one slot per step, decrementing the count before each access. [source:raw]
    // GUARD: Skip array slots whose facet pointer is null. [source:raw]
    // CALL: For each non-null facet, decrement its reference count via RefcountDecrementWithLock and, if the returned pointer is non-null, invoke the destructor it points to on that facet. [callee:0x00598C88]
    // CALL: Free the heap-allocated facet pointer array with sub_58AA6F. [callee:0x0058AA6F]
    // CALL: Run the CRT-cleanup epilogue sub_59A5E9. [callee:0x0059A5E9]
    // CALL: Release the string buffer at this+6 via ReferenceCountDecrementWithConditionalFree. [callee:0x005993AF]
    // ASSIGNMENT: Reset the vtable to the std::locale::facet vftable (??_7facet@locale@std@@6B@). [global:0x005B9D54]

    // Conservative worker pseudocode:
    //   // Teardown of an object holding an array of facet pointers.
    //   size_t count = this[3];                       // facet count, this+0xC
    //   while (count != 0) {
    //       count -= 1;
    //       void* facet = array[count];               // array at this+0x8
    //       if (facet != 0)
    //           ReleaseFacet(facet);                   // refcount decrement + conditional destroy
    //   }
    //   free(array);
    //   this->stringBuffer.Release();                  // this+6
    //   this->vftable = &std::locale_facet_vftable;
    // UNRESOLVED: loc_59D537 is the SEH continuation/landing-pad address; its role in unwinding this teardown is not visible in the raw body.
    // UNRESOLVED: The count/array offsets this+0xC and this+0x8 are DERIVED from the dword indices (v2[3], v2[2]) in the raw body; not independently confirmed.
    // UNRESOLVED: The object's concrete owner/type is unknown; the canonical name suggests locale-facet storage but no class evidence exists.
}
