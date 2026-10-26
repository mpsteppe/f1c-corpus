// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C6980
// Canonical corpus name: SetDriverName
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SetDriverName_004c6980.c

void UnknownObject::SetDriverName()
{
    // Sets a driver's full name. A bounded string copy (sub_587DD0, max 63 chars) copies the source name a2 into the 64-byte driver name buffer at this + 17952 (offset 0x4620), the final byte at this + 0x465F is forced to zero as the terminator, then DriverAbbreviationNameFormatter derives and stores the abbreviated driver name and its result is returned.
    // ASSIGNMENT: Set v3 = this + 17952, the 64-byte driver full name buffer whose last byte is this + 0x465F. [field:this:0x0000465F, source:raw]
    // CALL: Call sub_587DD0(this + 17952, a2, 63), a bounded string copy of at most 63 characters from a2 into the driver name buffer. [callee:0x00587DD0, field:this:0x0000465F, source:raw]
    // ASSIGNMENT: Force the last buffer byte to zero: v3[63] = 0 at this + 0x465F, guaranteeing NUL termination. [field:this:0x0000465F, source:raw]
    // CALL: Call DriverAbbreviationNameFormatter(this) to derive and store the abbreviated driver name from the full name field. [callee:0x004C6A10, source:raw]
    // RETURN: Return the result of DriverAbbreviationNameFormatter. [callee:0x004C6A10, function:0x004C6980, source:raw]

    // Conservative worker pseudocode:
    //   v3 = this + 17952;              // 64-byte driver name buffer at offset 0x4620
    //   sub_587DD0(v3, a2, 63);         // bounded copy, at most 63 chars
    //   v3[63] = 0;                     // force NUL terminator at this + 0x465F
    //   return DriverAbbreviationNameFormatter(this);
    // UNRESOLVED: Owner object type is unknown; the packet carries no object identity for the driver record.
    // UNRESOLVED: The field evidence only names the terminator byte at 0x465F; the buffer start at 0x4620 is derived from the 17952 base in the raw source.
    // UNRESOLVED: sub_587DD0's exact copy semantics are described in its own reconstruction (boundedStringCopy) and are not re-verified here.
}
