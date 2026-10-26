// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059AAB9
// Canonical corpus name: sub_59AAB9
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_59AAB9_0059aab9.c

void UnknownObject::encodingSingletonLazyInit()
{
    // Lazily initializes and returns the encoding singleton stored in dword_8D4650, called from LocaleRefcountAcquireUnderLock (0x00598C1C). After an SEH frame is set up with SEHHandlerInit (continuation labels loc_59D4EA / loc_59D4FC) and the CRT prologue sub_59A54D runs, it checks dword_8D4650; when the singleton is already set it skips initialization. On first call it allocates a 40-byte object with OperatorNewNhMallocWrapper(40), constructs it with ObjectConstructorWithVTableAndStringInit(0) (falling back to null on allocation failure), stores the result into dword_8D4650, evaluates the constructed-object guard via BooleanToIntConversion with landing pad loc_59AB83, writes code page identifier 63 to object offset +16, copies the string at dword_5B9D44 into object offset +24 via Strlen + BufferWriteWithNullTerminate, links the singleton into dword_8D464C and, when &dword_8D4648 is addressable, into dword_8D4648, and increments the object's reference count with CounterIncrementThreadSafe. Finally it marks the frame, runs the CRT epilogue sub_59A5E9 and returns dword_8D4650.
    // CALL: Set up the SEH frame with SEHHandlerInit (continuation targets loc_59D4EA and loc_59D4FC) and run the CRT prologue sub_59A54D(a1-16). [callee:0x0058A5D8, global:0x0059D4EA, global:0x0059D4FC, callee:0x0059A54D, source:raw]
    // GUARD: If dword_8D4650 (the singleton pointer) is already non-null, skip the initialization block. [global:0x008D4650, source:raw]
    // CALL: Allocate the 40-byte singleton object: v1 = OperatorNewNhMallocWrapper(40). [callee:0x00587C03, source:raw]
    // CALL: If v1 is non-null, construct the object with ObjectConstructorWithVTableAndStringInit(0), otherwise v2 = 0; then store the result into dword_8D4650. [callee:0x0059ABCD, global:0x008D4650, source:raw]
    // CALL: Evaluate the constructed-object guard via BooleanToIntConversion(&loc_59AB83), a landing-pad conversion. [callee:0x00587B3E, global:0x0059AB83, source:raw]
    // ASSIGNMENT: Store the code page identifier 63 into the object at offset +16: *(dword_8D4650 + 16) = 63. [global:0x008D4650, source:raw]
    // CALL: Copy the string at dword_5B9D44 into the object buffer at offset +24: Strlen(dword_5B9D44) then BufferWriteWithNullTerminate(dword_8D4650+24, dword_5B9D44, len). [callee:0x0058E1B0, callee:0x00599615, global:0x005B9D44, global:0x008D4650, source:raw]
    // CALL: Link the singleton into the manager/instance globals: dword_8D464C = dword_8D4650, CounterIncrementThreadSafe(dword_8D4650) bumps the refcount, and if &dword_8D4648 is non-null then dword_8D4648 = dword_8D464C. [global:0x008D464C, global:0x008D4648, global:0x008D4650, callee:0x00598C4A, source:raw]
    // RETURN: Cache v5 = dword_8D4650, flag the frame (*(a1-4) = -1), run the CRT epilogue sub_59A5E9, and return v5. [global:0x008D4650, callee:0x0059A5E9, source:raw]

    // Conservative worker pseudocode:
    //   SEHHandlerInit(); sub_59A54D(a1 - 16);
    //   if (!dword_8D4650) {
    //     v1 = OperatorNewNhMallocWrapper(40);
    //     dword_8D4650 = v1 ? ObjectConstructorWithVTableAndStringInit(0) : 0;
    //     BooleanToIntConversion(&loc_59AB83);
    //     *(dword_8D4650 + 16) = 63;
    //     BufferWriteWithNullTerminate(dword_8D4650 + 24, dword_5B9D44, Strlen(dword_5B9D44));
    //     dword_8D464C = dword_8D4650;
    //     CounterIncrementThreadSafe(dword_8D4650);
    //     if (&dword_8D4648) dword_8D4648 = dword_8D464C;
    //   }
    //   v5 = dword_8D4650;
    //   sub_59A5E9();
    //   return v5;
    // UNRESOLVED: RefcountDecrementWithLock (0x00598C88) is listed as a callee but does not appear in the raw source text; it is presumed to belong to the SEH unwind/refcount-release path exercised when construction fails. Not resolved here.
    // UNRESOLVED: The constructed object's vtable/type is not evidenced; offset +16 receives 63 (interpreted as a code page identifier per existing analysis) and offset +24 receives the string copy.
    // UNRESOLVED: The loc_59AB83 landing-pad mechanism of BooleanToIntConversion and the exact guard semantics it encodes are opaque from the raw text.
    // UNRESOLVED: The 'if (&dword_8D4648)' test always evaluates true since it takes the address of a global; its intent is not evidenced.
}
