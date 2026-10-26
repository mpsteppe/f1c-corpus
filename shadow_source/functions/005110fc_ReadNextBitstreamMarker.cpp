// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005110FC
// Canonical corpus name: BitstreamTokenReader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BitstreamTokenReader_005110fc.c

void UnknownObject::ReadNextBitstreamMarker()
{
    // Reads bytes from a bitstream through a refill-callback state struct at this+0x14, handling 0xFF byte-stuffing (a 0xFF 0x00 pair counts as one escaped data byte and consecutive 0xFF bytes are skipped) until a marker byte (0xFF followed by a non-zero, non-0xFF byte) is found. Maintains an accumulated byte counter at (this+0x190)+88. When a marker is found with a non-zero byte count, writes state code 112, the count and the marker byte into the dispatcher object *v1, dispatches through the callback at *v1+4 with -1, and resets the counter; finally stores the marker byte at this+0x178 and returns 1, or 0 when a refill callback fails.
    // ASSIGNMENT: Load the byte-stream read-state struct pointer into v2 from this+0x14 (dword index 5), initializing the current read pointer v4 = *v2 and the remaining-byte count v3 = v2[1]. [field:this:0x00000014, field:*(this+0x14):0x00000000, source:raw]
    // GUARD: When the remaining-byte count v3 reaches zero, invoke the refill callback stored at v2[3]; a zero return aborts the read with return value 0, otherwise the read pointer and count are reloaded from *v2 and v2[1]. [field:*(this+0x14):0x00000000, source:raw]
    // LOOP: Consume bytes one at a time: read a byte from the current pointer, decrement the remaining-byte count and advance the pointer; the outer loop runs until a marker byte is found. [field:*(this+0x14):0x00000000, source:raw]
    // GUARD: A byte value of 255 is not a marker by itself; an escaped data byte is a 0xFF 0x00 pair, and consecutive 0xFF bytes are skipped until a non-0xFF byte is read, which ends the scan. [source:raw]
    // CALCULATION: Increment the accumulated byte counter at (this+0x190)+88 by 1 for each ordinary data byte consumed. [field:this:0x00000190, field:this:0x000001E8, source:raw]
    // CALCULATION: For an escaped 0xFF 0x00 data byte, increment the accumulated byte counter at (this+0x190)+88 by 2. [field:this:0x00000190, field:this:0x000001E8, source:raw]
    // ASSIGNMENT: Persist the updated read pointer and remaining-byte count back into *v2 and v2[1] after each consumed run of bytes. [field:*(this+0x14):0x00000000, source:raw]
    // GUARD: When the byte counter at (this+0x190)+88 is non-zero after a marker is found, report the result through the dispatcher object at *v1; if the counter is zero the marker byte is stored without dispatching. [field:this:0x00000000, field:this:0x00000190, field:this:0x000001E8, source:raw]
    // ASSIGNMENT: Write the state code 112 to the dispatcher object at *v1+20 (field obj+0x14). [field:this:0x00000000, field:obj:0x00000014, source:raw]
    // ASSIGNMENT: Write the accumulated byte count to the dispatcher object at *v1+24 (field obj+0x18). [field:this:0x00000000, field:obj:0x00000018, source:raw]
    // ASSIGNMENT: Write the detected marker byte to the dispatcher object at *v1+28 (field obj+0x1C). [field:this:0x00000000, field:obj:0x0000001C, source:raw]
    // CALL: Dispatch through the callback function pointer at *v1+4 (field obj+0x4) with the reader object and -1 as arguments. [field:this:0x00000000, field:obj:0x00000004, source:raw]
    // ASSIGNMENT: Reset the byte counter at (this+0x190)+88 to 0 after dispatching. [field:this:0x00000190, field:this:0x000001E8, source:raw]
    // ASSIGNMENT: Store the detected marker byte into this+0x178 (dword index 94) at the end of the function. [field:this:0x00000178, source:raw]
    // RETURN: Return 1 on success (a marker byte was stored), or 0 when a refill callback returns zero. [source:raw]

    // Conservative worker pseudocode:
    //   bool ReadNextBitstreamMarker(void* this) {
    //     void* stream = *(void**)(this + 0x14);
    //     byte* p = *(byte**)stream;
    //     int remaining = *(int*)(stream + 4);
    //     int marker = 0;
    //     while (true) {
    //       if (remaining == 0) {
    //         if (!refillCallback(stream + 12, this)) return false;
    //         p = *(byte**)stream;
    //         remaining = *(int*)(stream + 4);
    //       }
    //       int b = *p;
    //       --remaining;
    //       ++p;
    //       if (b != 255) {
    //         ++*(int*)(this + 0x190 + 88);
    //         *(byte**)stream = p;
    //         *(int*)(stream + 4) = remaining;
    //         continue;
    //       }
    //       do {
    //         if (remaining == 0) {
    //           if (!refillCallback(stream + 12, this)) return false;
    //           p = *(byte**)stream;
    //           remaining = *(int*)(stream + 4);
    //         }
    //         marker = *p;
    //         --remaining;
    //         ++p;
    //       } while (marker == 255);
    //       if (marker != 0) break;
    //       *(int*)(this + 0x190 + 88) += 2;
    //       *(byte**)stream = p;
    //       *(int*)(stream + 4) = remaining;
    //     }
    //     int count = *(int*)(this + 0x190 + 88);
    //     if (count != 0) {
    //       *(int*)(*(int*)this + 20) = 112;
    //       *(int*)(*(int*)this + 24) = count;
    //       *(int*)(*(int*)this + 28) = marker;
    //       dispatchCallback(*(int*)this + 4, this, -1);
    //       *(int*)(this + 0x190 + 88) = 0;
    //     }
    //     *(int*)(this + 0x178) = marker;
    //     *(byte**)stream = p;
    //     *(int*)(stream + 4) = remaining;
    //     return true;
    //   }
    // UNRESOLVED: The field this+0x18 is listed in the packet as read/write but is not referenced anywhere in the raw source body; the existing analysis speculates it caches the buffer position, which is not evidenced here.
    // UNRESOLVED: The field this+0x20 is listed in the packet as read but is not referenced in the raw source body; the existing analysis describes it as a table entry count unused in this function.
    // UNRESOLVED: The refill callback stored at v2[3] and the dispatcher object *v1 have no concrete types or owner classes evidenced in this packet; the owner is UNKNOWN.
    // UNRESOLVED: The semantics of state code 112 and the -1 dispatch argument depend on the dispatcher contract, which is outside this packet's evidence.
}
