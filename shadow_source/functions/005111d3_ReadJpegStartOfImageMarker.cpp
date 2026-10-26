// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005111D3
// Canonical corpus name: JPEGMarkerReader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/JPEGMarkerReader_005111d3.c

void UnknownObject::ReadJpegStartOfImageMarker()
{
    // Reads two bytes from the byte stream (refilling transparently when the buffer is empty) and validates them as the JPEG SOI marker 0xFF 0xD8. On mismatch it reports error state 52 with the two unexpected bytes and dispatches through the state-dispatcher vtable. The second byte is stored at this+0x178 unconditionally, the stream read pointer and remaining count are advanced, and 1 is returned.
    // GUARD: If the stream's remaining byte count is zero, call the refill function at stream+0xC; abort with return 0 when the refill fails [field:*(this+0x14):0x00000000, field:this:0x00000014, source:raw]
    // CALCULATION: Consume the first stream byte, decrement the remaining count, refill again if that leaves zero, then consume the second stream byte and decrement again [field:*(this+0x14):0x00000000, field:this:0x00000014, source:raw]
    // GUARD: Validation guard: the marker only passes when the first byte equals 255 (0xFF) and the second byte equals 216 (0xD8), the JPEG Start-Of-Image marker [source:raw]
    // ASSIGNMENT: On a failed marker check, write state 52 to obj+0x14, the first byte to obj+0x18 and the second byte to obj+0x1C, then dispatch through the state-dispatcher vtable (obj+0x0) [field:obj:0x00000014, field:obj:0x00000018, field:obj:0x0000001C, field:obj:0x00000000, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Store the second stream byte at this+0x178 regardless of marker validity (this+0x178 acts as the current-marker field for downstream consumers) [field:this:0x00000178, source:raw]
    // ASSIGNMENT: Write the advanced read pointer and remaining count back into the stream read-state struct at this+0x14 [field:*(this+0x14):0x00000000, field:this:0x00000014, source:raw]
    // RETURN: Return 1 after consuming the marker; return 0 when a stream refill fails; invoked by CommandDispatchStateMachine (0x0051126A) [caller:0x0051126A, function:0x005111D3, source:raw]

    // Conservative worker pseudocode:
    //   stream = this[0x14/4];
    //   refill_buffer_if_empty(stream);           /* stream[3] refill function, fail -> return 0 * /
    //   byte1 = read_byte(stream);
    //   refill_buffer_if_empty(stream);
    //   byte2 = read_byte(stream);
    //   if (byte1 != 0xFF || byte2 != 0xD8) {
    //     obj[0x14/4] = 52;  obj[0x18/4] = byte1;  obj[0x1C/4] = byte2;
    //     dispatch_state(obj);
    //   }
    //   this[0x178/4] = byte2;
    //   stream[0] = read_ptr;  stream[1] = remaining;
    //   return 1;
    // UNRESOLVED: Field this+0x18 (cached buffer pointer) and this+0x20 (table entry count) appear in the packet field list but are never accessed by the raw source of this function
}
