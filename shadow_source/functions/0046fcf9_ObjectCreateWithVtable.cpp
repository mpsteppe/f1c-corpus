// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046FCF9
// Canonical corpus name: ObjectCreateWithVtable
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectCreateWithVtable_0046fcf9.c

void UnknownObject::ObjectCreateWithVtable()
{
    // Object factory: invokes an interface callback at offset 0x6A of the caller-supplied interface, applies a byte accumulation to a pointer, calls the base constructor ConstructorWithByteParams with two byte parameters, stores the input byte a2 at object offset 228 (0xE4), installs vtable off_5A00F0 at the object head, and returns the constructed object pointer. Signature is userpurge, returning the object in eax with the interface in esi.
    // CALL: Invoke function pointer stored at interface offset 0x6A (106) on the caller-supplied interface a1. [field:this:0x0000006A, source:raw]
    // CALCULATION: Accumulate the high byte of v3 into the byte pointed to by v2 (source register edx); v2/v3 provenance is a decompiler artifact and unresolved. [source:raw]
    // CALL: Call base constructor ConstructorWithByteParams with byte parameters v6 and v7. [callee:0x00487220, source:raw]
    // ASSIGNMENT: Store the input byte a2 at new object offset 228 (0xE4). [source:raw]
    // ASSIGNMENT: Install vtable pointer off_5A00F0 at the head of the new object. [global:0x005A00F0, source:raw]
    // RETURN: Return the new object pointer in eax. [function:0x0046FCF9, source:raw]

    // Conservative worker pseudocode:
    //   Object* ObjectCreateWithVtable(Interface* iface, byte initByte) {
    //       (*(callable_t)((byte*)iface + 0x6A))();
    //       *v2 += highByte(v3);
    //       Object* obj = ConstructorWithByteParams(pByteParamA, pByteParamB);
    //       obj->byte_at_228 = initByte;
    //       obj->vtable = &off_5A00F0;
    //       return obj;
    //   }
    // UNRESOLVED: Source and meaning of the byte pointer v2 (edx) and word v3 (ecx) feeding the byte accumulation are not recoverable from this frame.
    // UNRESOLVED: Byte write at object offset 228 (0xE4) has no packet field evidence reference; treated as raw source data only.
    // UNRESOLVED: Interface callback at offset 0x6A and the constructor's two byte parameters have unknown contracts.
    // UNRESOLVED: Top-level function: no static callers recorded.
}
