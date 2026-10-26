// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005642B0
// Canonical corpus name: NetworkAddressParser
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NetworkAddressParser_005642b0.c

void UnknownObject::NetworkAddressParser()
{
    // Parses a host:port address string: locates the ':' delimiter (ASCII 58) with sub_589DB0, null-terminates the string at the delimiter to split host and port, stores inet_addr(a2) into the dword at a1, parses the port substring after the delimiter via SingleFunctionCallWrapper_7f59 and stores its low word into the word at a1+4. Returns the parsed port value, or the null delimiter result when no ':' was present. Invoked by sub_564110.
    // CALL: Locate the first ':' delimiter (ASCII 58) in the input string a2 via sub_589DB0 and keep it as v5/result. [callee:0x00589DB0, source:raw]
    // GUARD: Branch on the delimiter search result: the host/port split and parsing run only when a ':' character was found in a2. [source:raw]
    // ASSIGNMENT: Null-terminate the string at the delimiter, splitting a2 into host and port substrings. [source:raw]
    // ASSIGNMENT: Convert the host substring via inet_addr and store the resulting network address into the dword at a1. [callee:0x00598666, source:raw]
    // CALL: Parse the port substring immediately after the delimiter (v5 + 1) through SingleFunctionCallWrapper_7f59. [callee:0x00587F59, source:raw]
    // ASSIGNMENT: Store the low word of the parsed port value into the word at a1 + 4. [source:raw]
    // RETURN: Return the parsed port value; when no delimiter was found, return the null delimiter search result. [source:raw]
    // CALL: Invoked by sub_564110 to perform host:port address parsing. [caller:0x00564110, source:raw]

    // Conservative worker pseudocode:
    //   BYTE* sub_5642B0(int a1, const char* a2) {
    //     BYTE* colon = (BYTE*)sub_589DB0(a2, 58);
    //     BYTE* result = colon;
    //     if (colon) {
    //       *colon = 0;
    //       *(DWORD*)a1 = inet_addr(a2);
    //       result = (BYTE*)SingleFunctionCallWrapper_7f59(colon + 1);
    //       *(WORD*)(a1 + 4) = (WORD)result;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Return value and exact semantics of SingleFunctionCallWrapper_7f59 (port string to integer conversion is inferred, not evidenced).
    // UNRESOLVED: Layout and consumers of the network record written at a1 and a1+4 are outside this function's evidence.
}
