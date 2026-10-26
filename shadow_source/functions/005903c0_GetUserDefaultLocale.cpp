// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005903C0
// Canonical corpus name: sub_5903C0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5903C0_005903c0.c

void UnknownObject::GetUserDefaultLocale()
{
    // Locale resolver. Sets flag bits on the dword_8D3FB0 validation word, queries the Win32 GetUserDefaultLCID API, stores the returned locale ID into both dword_8D3FB4 and the Locale global, and returns the same value. Called by sub_58FD90 (0058fd90) during locale setup.
    // ASSIGNMENT: Sets flag bits on the low word of dword_8D3FB0: LOWORD(dword_8D3FB0) = dword_8D3FB0 | 0x104 [global:0x008D3FB0, source:raw]
    // CALL: Calls GetUserDefaultLCID (import at 0x0059E134) to obtain the user default locale ID [global:0x0059E134, source:raw]
    // ASSIGNMENT: dword_8D3FB4 = result, storing the resolved locale ID [global:0x008D3FB4, source:raw]
    // ASSIGNMENT: Locale = result, storing the same locale ID in the Locale global [global:0x008D3F98, source:raw]
    // RETURN: Returns the locale ID obtained from GetUserDefaultLCID [source:raw]
    // CALL: Invoked by sub_58FD90 (0058fd90) as part of locale initialization [caller:0x0058FD90]

    // Conservative worker pseudocode:
    //   LOWORD(dword_8D3FB0) = dword_8D3FB0 | 0x104;
    //   result = GetUserDefaultLCID();
    //   dword_8D3FB4 = result;
    //   Locale = result;
    //   return result;
    // UNRESOLVED: The meaning of the 0x104 flag bits on dword_8D3FB0 is not established from this packet; it may mark the locale as resolved or validated
    // UNRESOLVED: The exact role of the Locale global versus dword_8D3FB4 is not distinguished by this packet
}
