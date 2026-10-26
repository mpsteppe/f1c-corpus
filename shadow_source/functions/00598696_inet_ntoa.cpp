// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00598696
// Canonical corpus name: inet_ntoa
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/inet_ntoa_00598696.c

void UnknownObject::inet_ntoa()
{
    // Import thunk for Winsock inet_ntoa. Converts an in_addr structure to an IPv4 dotted-quad string via __imp_inet_ntoa at 0x0059E310.
    // CALL: Forward the in_addr argument to the imported inet_ntoa (__imp_inet_ntoa at 0x0059E310) and return the resulting string pointer. [source:raw, function:0x00598696, global:0x0059E310]

    // Conservative worker pseudocode:
    //   char *inet_ntoa(struct in_addr in) {
    //       return __imp_inet_ntoa(in);
    //   }
}
