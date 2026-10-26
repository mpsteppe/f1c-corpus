// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004054E0
// Canonical corpus name: BinaryDataDeserialization
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BinaryDataDeserialization_004054e0.c

void UnknownObject::BinaryDataDeserialization()
{
    // Deserializes one binary data entry selected by index a2 from a reader object: validates the file handle and index bounds, seeks to the entry offset, reads a 40-byte header, extracts a type field via bitfield, and dispatches per type (0 = raw offset record, 1 = threaded object creation through a vtable dispatch plus SEH guard, 2 = direct seek past the header). Returns 0 on a successful type 0/2 path and 1 on guards/failures.
    // GUARD: Validate the reader state: require the file/buffer handle at this+0xC and that entry index a2 is below the count at this+0x14; otherwise return 1. [field:this:0x0000000C, field:this:0x00000014, source:raw]
    // CALCULATION: Load the entry seek offset v5 = *(this+0x18 + 4 * a2) from the offset table base at this+0x18. [field:this:0x00000018, source:raw]
    // CALL: Seek the handle to the entry offset via sub_587F64(this+0xC, v5, 0); return 1 when the seek fails. [callee:0x00587F64, field:this:0x0000000C, source:raw]
    // CALL: Read the 40-byte header into the stack buffer through ThreadSafeReadWrapper_803f(buf, 40, 1, this+0xC); return 1 when the read fails. [callee:0x0058803F, field:this:0x0000000C, source:raw]
    // CALL: Run OneTimeInitializationWithAtexitStyleRegistration() before parsing the header. [callee:0x00404FE0, source:raw]
    // CALL: Extract the type field from the header with BitfieldExtractFromStruct(buf) and store it into this+0x2C. [callee:0x00407EF0, field:this:0x0000002C, source:raw]
    // GUARD: When the extracted type at this+0x2C is -1 the header is invalid and the function returns 1. [field:this:0x0000002C, source:raw]
    // CALL: MemoryAllocation_56a0(buf) processes the header buffer. [callee:0x004056A0, source:raw]
    // ASSIGNMENT: Record deserialization state: this+0x1C = a2, this+0x20 = 0, and this+0x28 = v5 + 40 (seek position just past the header). [field:this:0x0000001C, field:this:0x00000020, field:this:0x00000028, source:raw]
    // ASSIGNMENT: Type 0 path: set this+0x24 from a header buffer local plus 44 and return 0. [field:this:0x00000024, source:raw]
    // GUARD: Type 1 path: when header bit (v15 & 4) is set compute this+0x24 from another header buffer local plus 44, otherwise set the failure flag. [field:this:0x00000024, source:raw]
    // CALL: Resolve an object handle: sub_59B650(this+0x10) feeds sub_58AE69(result, aRb), and the result is stored into this+0x38. [callee:0x0059B650, callee:0x0058AE69, global:0x005BE828, field:this:0x00000010, field:this:0x00000038, source:raw]
    // CALL: Dispatch through the sub-object vtable: call the __thiscall pointer stored at this+0x34 + 12 with (this+0x34, this+0x28, 0). [field:this:0x00000034, field:this:0x00000028, source:raw]
    // CALL: Create the threaded object via ThreadedObjectCreatorWithSEH(this+0x34, this+0x28, this+0x24 - 44); return the current result when it succeeds. [callee:0x0052D8D0, field:this:0x00000034, field:this:0x00000028, field:this:0x00000024, source:raw]
    // CALL: On creation failure run StructInitWithVTableDispatchAndZeroFill(this) and return 1. [callee:0x00405630, source:raw]
    // ASSIGNMENT: Type 2 path: set this+0x24 from a header buffer local, seek again via sub_587F64(this+0xC, v5 + 40, 0), and return 0. [callee:0x00587F64, field:this:0x00000024, field:this:0x0000000C, source:raw]
    // RETURN: Return 1 on any guard or failure and 0 on a successful type 0/2 deserialization. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4054E0(void *self, unsigned int index) {
    //     if (!self->handle || index >= self->count) return 1;
    //     unsigned int off = self->offsetTable[index];
    //     if (sub_587F64(self->handle, off, 0)) return 1;
    //     unsigned char hdr[40];
    //     if (!ThreadSafeReadWrapper_803f(hdr, 40, 1, self->handle)) return 1;
    //     OneTimeInitializationWithAtexitStyleRegistration();
    //     int type = BitfieldExtractFromStruct(hdr);
    //     self->type = type;
    //     if (type == -1) return 1;
    //     MemoryAllocation_56a0(hdr);
    //     self->index = index; self->pad = 0; self->dataPos = off + 40;
    //     if (type == 0) { self->dataOff = hdrLocalA + 44; return 0; }
    //     if (type == 1) {
    //       self->dataOff = (hdrLocalB & 4) ? hdrLocalC + 44 : self->dataOff;
    //       int obj = sub_58AE69(sub_59B650(self->ctx), aRb);
    //       self->resolved = obj;
    //       (*(void (**)(void*, int, int))(self->sub + 12))(self->sub, self->dataPos, 0);
    //       if (ThreadedObjectCreatorWithSEH(self->sub, self->dataPos, self->dataOff - 44)) return result;
    //       StructInitWithVTableDispatchAndZeroFill(self); return 1;
    //     }
    //     if (type == 2) { self->dataOff = hdrLocalA; sub_587F64(self->handle, off + 40, 0); return 0; }
    //     return 1;
    //   }
    // UNRESOLVED: Header buffer locals v14/v15/v16 are bytes of the 40-byte header read by ThreadSafeReadWrapper_803f; their concrete meaning depends on the on-disk entry layout and the bitfield decoder BitfieldExtractFromStruct.
    // UNRESOLVED: The exact purpose of this+0x10 (feeds sub_59B650), the aRb string global, and the sub-object at this+0x34 is caller/format dependent and not derivable here.
    // UNRESOLVED: this+0x40 is listed by the packet but is not referenced anywhere in the raw source.
}
