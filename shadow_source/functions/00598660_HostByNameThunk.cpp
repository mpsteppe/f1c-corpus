// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00598660
// Canonical corpus name: gethostbyname
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/gethostbyname_00598660.c

void UnknownObject::HostByNameThunk()
{
    // stdcall import thunk that forwards the host-name string unchanged to the import pointer __imp_gethostbyname (0x0059E2EC) and returns the resulting hostent pointer. Called by sub_562010 (0x00562010) and sub_562D90 (0x00562D90), consistent with DNS/host-name resolution use.
    // CALL: Forward name to __imp_gethostbyname, the import pointer read at global 0x0059E2EC [global:0x0059E2EC, source:raw]
    // RETURN: Return the hostent pointer from the import call unchanged (return thunk) [function:0x00598660, source:raw]
    // CALL: Invoked by sub_562010 (0x00562010) and sub_562D90 (0x00562D90) [caller:0x00562010, caller:0x00562D90, source:raw]

    // Conservative worker pseudocode:
    //   struct hostent *__stdcall HostByNameThunk(const char *name)
    //   {
    //       return __imp_gethostbyname(name);
    //   }
    // UNRESOLVED: __imp_gethostbyname is a load-time import pointer; the specific resolver library binding (ws2_32/wsock32) is not recorded in this packet.
}
