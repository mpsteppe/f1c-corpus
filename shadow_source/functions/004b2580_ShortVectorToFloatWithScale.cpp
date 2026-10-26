// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B2580
// Canonical corpus name: ShortVectorToFloatWithScale
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortVectorToFloatWithScale_004b2580.c

void UnknownObject::ShortVectorToFloatWithScale()
{
    // Unpacks three int16 values from this[15..17] into floats scaled by 0.02 (1/50), writing to the output float array a2. Inverse of the short-vector packing routine; on the per-frame physics/audio path.
    // ASSIGNMENT: a2[0] = (double)this[15] * 0.02; write scaled float 0 [field:this:0x0000001E, global:0x0059E6EC, function:0x004B2580, source:raw]
    // ASSIGNMENT: a2[1] = (double)this[16] * 0.02; write scaled float 1 [field:this:0x00000020, global:0x0059E6EC, function:0x004B2580, source:raw]
    // ASSIGNMENT: a2[2] = (double)this[17] * 0.02; write scaled float 2 [field:this:0x00000022, global:0x0059E6EC, function:0x004B2580, source:raw]
    // RETURN: return a2; the output float pointer [function:0x004B2580, source:raw]

    // Conservative worker pseudocode:
    //   a2[0] = (float)this[15] * 0.02;
    //   a2[1] = (float)this[16] * 0.02;
    //   a2[2] = (float)this[17] * 0.02;
    //   return a2;
    // UNRESOLVED: global flt_59E6EC is read (R) but is not referenced in the raw source text, which spells the scale as literal 0.02; existing analysis names it ShortIntToWorldScale [DERIVED] - role here unverified
}
