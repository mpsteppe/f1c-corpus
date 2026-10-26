// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059868A
// Canonical corpus name: setsockopt
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/setsockopt_0059868a.c

void UnknownObject::setsockopt()
{
    // Import thunk for Winsock2 setsockopt. Forwards SOCKET s, level, optname, optval, and optlen to __imp_setsockopt at 0x0059E308.
    // CALL: Forward all arguments to the imported setsockopt (__imp_setsockopt at 0x0059E308) and return its result. [source:raw, function:0x0059868A, global:0x0059E308]

    // Conservative worker pseudocode:
    //   int setsockopt(SOCKET s, int level, int optname, const char *optval, int optlen) {
    //       return __imp_setsockopt(s, level, optname, optval, optlen);
    //   }
}
