// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057D400
// Canonical corpus name: sub_57D400
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_57D400_0057d400.c

void UnknownObject::WSAErrorToString()
{
    // Translates a Winsock error code into a human-readable message string. When the passed value is -1 (the SOCKET_ERROR sentinel), fetches the real error code from WSAGetLastError; then a switch on the error code returns the corresponding static string. Unknown or unmapped codes fall back to a generic WSAGetLastError string.
    // ASSIGNMENT: Take the incoming value as the Winsock error code to translate (Error = this). [source:raw]
    // GUARD: If the passed value is -1 (SOCKET_ERROR sentinel), obtain the real error code by calling WSAGetLastError. [global:0x0059E324, source:raw]
    // STATE_TRANSITION: Dispatch on the error code through the switch jump table jpt_57D423, selecting the message case for each WSA code. [global:0x0057D4EC]
    // ASSIGNMENT: Case 10004 (WSAEINTR): return the aABlockingWindo_0 message string. [global:0x005E5B10]
    // ASSIGNMENT: Case 10009 (WSAEBADF): return the aForWindowsCeAf message string. [global:0x005E5C10]
    // ASSIGNMENT: Case 10013 (WSAEACCES): return the aTheRequestedAd message string. [global:0x005E5B60]
    // ASSIGNMENT: Case 10014 (WSAEFAULT): return the aTheNameOrTheNa message string. [global:0x005E5CF0]
    // ASSIGNMENT: Case 10022 (WSAEINVAL): return the aErrorCodeWsaei message string. [global:0x005E5CD8]
    // ASSIGNMENT: Case 10024 (WSAEMFILE): return the aNoMoreSocketDe message string. [global:0x005E5E58]
    // ASSIGNMENT: Case 10035 (WSAEWOULDBLOCK): return the aTheSocketIsMar message string. [global:0x005E5868]
    // ASSIGNMENT: Case 10036 (WSAEINPROGRESS): return the aABlockingWindo message string. [global:0x005E5FB8]
    // ASSIGNMENT: Case 10037 (WSAEALREADY): return the aANonblockingCo message string. [global:0x005E5EC8]
    // ASSIGNMENT: Case 10038 (WSAENOTSOCK): return the aTheDescriptorI message string. [global:0x005E5A38]
    // ASSIGNMENT: Case 10039 (WSAEDESTADDRREQ): return the aADestinationAd message string. [global:0x005E55D4]
    // ASSIGNMENT: Case 10040 (WSAEMSGSIZE): return the aTheSocketIsMes message string. [global:0x005E57F0]
    // ASSIGNMENT: Case 10041 (WSAEPROTOTYPE): return the aTheSpecifiedPr_0 message string. [global:0x005E5C9C]
    // ASSIGNMENT: Case 10043 (WSAEPROTONOSUPPORT): return the aTheSpecifiedPr message string. [global:0x005E5DF0]
    // ASSIGNMENT: Case 10044 (WSAESOCKTNOSUPPORT): return the aTheSpecifiedSo message string. [global:0x005E5C58]
    // ASSIGNMENT: Case 10045 (WSAEOPNOTSUPP): return the aMsgOobWasSpeci message string. [global:0x005E5948]
    // ASSIGNMENT: Case 10047 (WSAEAFNOSUPPORT): return the aTheSpecifiedAd message string. [global:0x005E6030]
    // ASSIGNMENT: Case 10048 (WSAEADDRINUSE): return the aTheSocketSLoca message string. [global:0x005E6060]
    // ASSIGNMENT: Case 10049 (WSAEADDRNOTAVAIL): return the aTheRemoteAddre message string. [global:0x005E5E84]
    // ASSIGNMENT: Case 10050 (WSAENETDOWN): return the aTheNetworkSubs message string. [global:0x005E61C0]
    // ASSIGNMENT: Case 10051 (WSAENETUNREACH): return the aTheNetworkCann message string. [global:0x005E5598]
    // ASSIGNMENT: Case 10052 (WSAENETRESET): return the aTheConnectionH message string. [global:0x005E5A98]
    // ASSIGNMENT: Case 10053 (WSAECONNABORTED): return the aTheVirtualCirc message string. [global:0x005E5720]
    // ASSIGNMENT: Case 10054 (WSAECONNRESET): return the aTheVirtualCirc_0 message string. [global:0x005E55F8]
    // ASSIGNMENT: Case 10055 (WSAENOBUFS): return the aNoBufferSpaceI message string. [global:0x005E5E1C]
    // ASSIGNMENT: Case 10057 (WSAENOTCONN): return the aTheSocketIsNot message string. [global:0x005E5A58]
    // ASSIGNMENT: Case 10058 (WSAESHUTDOWN): return the aTheSocketHasBe message string. [global:0x005E58B8]
    // ASSIGNMENT: Case 10060 (WSAETIMEDOUT): return the aTheConnectionH_0 message string. [global:0x005E5518]
    // ASSIGNMENT: Case 10061 (WSAECONNREFUSED): return the aTheAttemptToCo message string. [global:0x005E5DC0]
    // ASSIGNMENT: Case 10065 (WSAEHOSTUNREACH): return the aTheRemoteHostC message string. [global:0x005E57B0]
    // ASSIGNMENT: Case 10093 (WSAEPROCLIM): return the aASuccessfulWsa message string. [global:0x005E6208]
    // ASSIGNMENT: Default case: return the aWsagetlasterro generic message string. [global:0x005E54E4]
    // RETURN: Return the selected error-message string pointer. [function:0x0057D400, source:raw]

    // Conservative worker pseudocode:
    //   const char* WSAErrorToString(int error) {
    //     if (error == -1) error = WSAGetLastError();
    //     switch (error) {
    //       case 10004: return aABlockingWindo_0;
    //       case 10009: return aForWindowsCeAf;
    //       case 10013: return aTheRequestedAd;
    //       case 10014: return aTheNameOrTheNa;
    //       case 10022: return aErrorCodeWsaei;
    //       case 10024: return aNoMoreSocketDe;
    //       case 10035: return aTheSocketIsMar;
    //       case 10036: return aABlockingWindo;
    //       case 10037: return aANonblockingCo;
    //       case 10038: return aTheDescriptorI;
    //       case 10039: return aADestinationAd;
    //       case 10040: return aTheSocketIsMes;
    //       case 10041: return aTheSpecifiedPr_0;
    //       case 10043: return aTheSpecifiedPr;
    //       case 10044: return aTheSpecifiedSo;
    //       case 10045: return aMsgOobWasSpeci;
    //       case 10047: return aTheSpecifiedAd;
    //       case 10048: return aTheSocketSLoca;
    //       case 10049: return aTheRemoteAddre;
    //       case 10050: return aTheNetworkSubs;
    //       case 10051: return aTheNetworkCann;
    //       case 10052: return aTheConnectionH;
    //       case 10053: return aTheVirtualCirc;
    //       case 10054: return aTheVirtualCirc_0;
    //       case 10055: return aNoBufferSpaceI;
    //       case 10057: return aTheSocketIsNot;
    //       case 10058: return aTheSocketHasBe;
    //       case 10060: return aTheConnectionH_0;
    //       case 10061: return aTheAttemptToCo;
    //       case 10065: return aTheRemoteHostC;
    //       case 10093: return aASuccessfulWsa;
    //       default: return aWsagetlasterro;
    //     }
    //   }
    // UNRESOLVED: The exact message text behind each string global is not visible in this function; the WSA code association is inferred from the switch constant and is DERIVED.
    // UNRESOLVED: byte_57D56C is read but does not appear in the decompiled control flow; its purpose is unknown.
    // UNRESOLVED: The __thiscall convention is nominal only: the this pointer is used purely as the error-code argument (including the -1 sentinel).
}
