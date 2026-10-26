// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059A38D
// Canonical corpus name: sub_59A38D
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_59A38D_0059a38d.c

void UnknownObject::LocaleDestructorWithConditionalFree()
{
    // Destructor-style helper under the MSVC __userpurge convention: runs CDestructorWithVTableChain on the ebp-delivered argument a2, then releases the ecx-delivered receiver a1 through FreeWrapper_7bcf only when bit 0 of the flag argument a3 is set, and returns a1. The a3 flag therefore selects an ownership/free-after-teardown path.
    // CALL: Call CDestructorWithVTableChain(a2) to run the destructor with vtable chain on the ebp-delivered argument. [callee:0x00599E71, source:raw]
    // GUARD: Test bit 0 of argument a3; the free runs only when the bit is set. [source:raw]
    // CALL: Call FreeWrapper_7bcf(a1) to release the ecx-delivered receiver when a3 bit 0 is set. [callee:0x00587BCF, source:raw]
    // RETURN: Return a1 (the ecx-delivered receiver pointer) unchanged to the caller. [source:raw]

    // Conservative worker pseudocode:
    //   void *LocaleDestructorWithConditionalFree(void *a1, int a2, char a3) {
    //     CDestructorWithVTableChain(a2);
    //     if (a3 & 1) FreeWrapper_7bcf(a1);
    //     return a1;
    //   }
    // UNRESOLVED: Why CDestructorWithVTableChain receives the ebp-passed a2 rather than the ecx receiver a1 is an MSVC __userpurge artifact; the original signature and argument order are unknown.
    // UNRESOLVED: Whether the freed a1 and the destructor target a2 are the same object is not evidenced; the two register slots suggest they may differ.
    // UNRESOLVED: The owner object type is unknown; the function acts as a destructor plus conditional-free helper.
}
