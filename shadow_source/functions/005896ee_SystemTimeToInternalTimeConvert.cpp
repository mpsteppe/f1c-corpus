// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005896EE
// Canonical corpus name: sub_5896EE
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5896EE_005896ee.c

void UnknownObject::SystemTimeToInternalTimeConvert()
{
    // Reads local and UTC system time, then converts UTC time to an internal time format via sub_591EDF. Timezone/DST determination is cached in dword_8D3E58 and reused while the cached system-time copy (xmmword_8D3E60) still matches the current UTC time. Optionally writes the result through an output pointer. Free __cdecl utility, not a member function.
    // CALL: Get UTC system time into SystemTime via GetSystemTime. [global:0x0059E1E4]
    // CALL: Get local time into a second SYSTEMTIME via GetLocalTime. [global:0x0059E1E0]
    // GUARD: Cache-hit check: compare minute/hour/day/month/year of the current UTC time against the cached copy xmmword_8D3E60 (byte components 8D3E62/8D3E66/8D3E68/8D3E6A). [global:0x008D3E60, global:0x008D3E62, global:0x008D3E66, global:0x008D3E68, global:0x008D3E6A]
    // STATE_TRANSITION: On cache hit, reuse the previously computed flag dword_8D3E58. [global:0x008D3E58]
    // CALL: On cache miss, query timezone/DST data via GetTimeZoneInformation. [global:0x0059E1E8]
    // CALCULATION: Compute DST flag: -1 on GetTimeZoneInformation error, else 1 when return code is 2 (daylight) and both DaylightDate.wMonth and DaylightBias are non-zero. [global:0x0059E1E8, source:raw]
    // ASSIGNMENT: Refresh cache: store current UTC time into xmmword_8D3E60 and the computed flag into dword_8D3E58. [global:0x008D3E60, global:0x008D3E58]
    // CALL: Convert SystemTime year/month/day/hour/minute/second plus DST flag to internal time via sub_591EDF. [callee:0x00591EDF]
    // GUARD: If the output pointer a1 is non-null, write the result to *a1. [field:this:0x00000000]
    // RETURN: Return the converted internal time. [source:raw]

    // Conservative worker pseudocode:
    //   int SystemTimeToInternalTimeConvert(int* out) {
    //     GetLocalTime(&local);
    //     GetSystemTime(&utc);
    //     int dstFlag;
    //     if (utc.minute == cache.minute && utc.hour == cache.hour &&
    //         utc.day == cache.day && utc.month == cache.month && utc.year == cache.year) {
    //       dstFlag = cachedDstFlag;
    //     } else {
    //       DWORD r = GetTimeZoneInformation(&tzi);
    //       if (r == -1) dstFlag = -1;
    //       else dstFlag = (r == 2 && tzi.DaylightDate.wMonth != 0 && tzi.DaylightBias != 0);
    //       cache = utc;
    //       cachedDstFlag = dstFlag;
    //     }
    //     int result = sub_591EDF(utc.year, utc.month, utc.day, utc.hour, utc.minute, utc.second, dstFlag);
    //     if (out) *out = result;
    //     return result;
    //   }
    // UNRESOLVED: Internal time format produced by sub_591EDF (epoch base, units) unknown from this function.
    // UNRESOLVED: Global byte reads at 0xFF00000000005455..0xFF00000000005467 are decompiler artifacts from WORD-macro reads of the cached time; their exact provenance is not established.
}
