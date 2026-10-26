// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00587CA0
// Canonical corpus name: FileReadUntilNewline
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FileReadUntilNewline_00587ca0.c

void UnknownObject::FileReadUntilNewline()
{
    // Reads one line from a file stream into a caller-supplied buffer under a critical section. If the requested length a2 is non-positive it returns 0 immediately. Otherwise it locks the stream via StreamBufferLockViaCriticalSection, then reads bytes one at a time: it decrements the remaining-buffer counter a3[1] and, when that goes negative, refills via sub_58C255, otherwise consumes *a3++ from the current stream position (field this+0x0). Bytes are copied into the output buffer until a newline (0x0A) or end of input is reached; a 0 terminator is appended. On EOF with no bytes read it returns 0, otherwise it returns the buffer pointer. The critical section is released via AddressRangeCriticalSectionLeave before returning.
    // GUARD: If the maximum read length a2 is <= 0, return 0 immediately without touching the stream. [abi:lead, function:0x00587CA0, source:raw]
    // CALL: Lock the stream object a3 via StreamBufferLockViaCriticalSection before reading. [callee:0x0058C1B1, source:raw]
    // LOOP: Read-until-newline loop: guard a2 (stop when it reaches 0); fetch the next byte from the stream, refilling the buffer via sub_58C255 when the remaining counter a3[1] underflows, otherwise consuming the byte at the stream position held in a3[0] (field this+0x0). [callee:0x0058C255, field:this:0x00000000, source:raw]
    // CALCULATION: Read the next byte from the stream: dereference the current position pointer at a3[0] and advance it (*(*a3)++), or obtain it via the sub_58C255 refill path. [field:this:0x00000000, source:raw]
    // GUARD: If the byte read equals -1 (end of input): return 0 when nothing has been written yet (v4 == a1), otherwise break out of the loop. [source:raw]
    // ASSIGNMENT: Append the read byte to the output buffer at the write cursor and advance the cursor. [source:raw]
    // LOOP: Continue the loop while the last byte written is not a newline (0x0A). [source:raw]
    // ASSIGNMENT: NUL-terminate the output buffer at the write cursor. [source:raw]
    // CALL: Release the stream critical section via AddressRangeCriticalSectionLeave(a3) before returning. [callee:0x0058C203, source:raw]
    // RETURN: Return the buffer pointer (or 0 when end of input was hit before any byte was read). [source:raw]
    // CALL: Used as a generic config/file line reader by many parsers: ConfigIniParser (0x00421CD0), GearRatioConfigFileReader (0x0042DE10), PitCrewAnimationLoader (0x004A2A90), VehFileParser (0x004C3200), SpecialFX_Init (0x004CF070), ConditionalDispatchBasedOnFlag (0x00566CC0), and sub_402690 / sub_479170. [caller:0x00402690, caller:0x00421CD0, caller:0x0042DE10, caller:0x00479170, caller:0x004A2A90, caller:0x004C3200, caller:0x004CF070, caller:0x00566CC0]

    // Conservative worker pseudocode:
    //   // Read one line from stream a3 into buffer a1, up to a2 bytes.
    //   if (a2 <= 0) return 0;
    //   StreamBufferLockViaCriticalSection(a3);
    //   out = a1;
    //   do {
    //       if (--a2 == 0) break;
    //       if (--a3[1] < 0) byte = sub_58C255(a3);
    //       else byte = *a3[0]++;
    //       if (byte == -1) { if (out == a1) { result = 0; goto done; } break; }
    //       *out++ = byte;
    //   } while (byte != 0x0A);
    //   *out = 0;
    //   done:
    //   AddressRangeCriticalSectionLeave(a3);
    //   return result;
    // UNRESOLVED: The refill counter a3[1] (offset +4 of the stream object) is not present in the packet field evidence set; the stream struct layout is unconfirmed.
    // UNRESOLVED: sub_58C255 (refill/read-more path) semantics are not detailed in the packet.
    // UNRESOLVED: The prelabel cluster_copy proposal names a ResourceDestroy function as a structural twin; the correspondence is DERIVED and not verified.
    // UNRESOLVED: Owner object identity is UNKNOWN; callers indicate a shared file/stream helper but no class evidence exists.
}
