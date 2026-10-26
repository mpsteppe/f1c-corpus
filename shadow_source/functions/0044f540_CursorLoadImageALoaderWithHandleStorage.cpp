// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044F540
// Canonical corpus name: CursorLoadImageALoaderWithHandleStorage
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CursorLoadImageALoaderWithHandleStorage_0044f540.c

void UnknownObject::CursorLoadImageALoaderWithHandleStorage()
{
    // Loads a cursor image from disk and stores its handle in a slot-indexed handle array. Builds the full path from an override-or-default directory prefix plus the given cursor filename, calls LoadImageA with the cursor image type and load-from-file flag, then on success zeroes the selected five-dword slot and stores the handle, advancing the cursor count.
    // ASSIGNMENT: Initialize the local path buffer with byte_5EA438[0] as the first character, zero-fill the next 0xFC bytes, and terminate with a zero 16-bit word and zero byte. [global:0x005EA438, source:raw]
    // GUARD: Guard on dword_5EC408 being non-zero to select the override directory prefix; otherwise fall back to byte_5EA438 as the default directory. [global:0x005EC408, global:0x005EA438, source:raw]
    // CALL: Build the full cursor path by formatting the directory prefix and the cursor filename a2 into the local buffer with StringFormatWithBufferOverflowCheck using the "%s%s" format. [callee:0x0058815F, global:0x005BE860, source:raw]
    // CALL: Call LoadImageA with NULL instance, the built path, image type 2 (cursor), width 0, height 0, and flag 0x10 (load from file). [global:0x0059E2A8, source:raw]
    // GUARD: Guard on the LoadImageA result being non-zero; only a successful load is stored into the handle array. [source:raw]
    // ASSIGNMENT: Select the slot at this[5*this[42]+12] and zero its five dwords before storing the handle. [field:this:0x000000A8, source:raw]
    // ASSIGNMENT: Store the ImageA handle into slot this[5*this[42]++ +12] and post-increment the cursor count at this[42]. [field:this:0x000000A8, source:raw]
    // RETURN: Return 0 unconditionally. [source:raw]

    // Conservative worker pseudocode:
    //   char CursorLoadImageALoaderWithHandleStorage(int* this, const char* a2) {
    //     char name[256]; name[0] = byte_5EA438[0]; memset(name + 1, 0, 0xFC);
    //     const char* prefix = dword_5EC408 ? (const char*)dword_5EC408 : byte_5EA438;
    //     StringFormatWithBufferOverflowCheck(name, "%s%s", prefix, a2);
    //     HANDLE img = LoadImageA(0, name, 2, 0, 0, 0x10);
    //     if (img) {
    //       int* slot = &this[5 * this[42] + 12]; slot[0] = slot[1] = slot[2] = slot[3] = slot[4] = 0;
    //       this[5 * this[42]++ + 12] = img;
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Receiver identity is unknown; the function is called by sub_44F4E0.
    // UNRESOLVED: The five dwords at each handle slot and the meaning of the cursor count at this[42] are not grounded beyond handle storage.
    // UNRESOLVED: Role of byte_5EA438 vs dword_5EC408 as directory sources is inferred from the prefix selection branch.
}
