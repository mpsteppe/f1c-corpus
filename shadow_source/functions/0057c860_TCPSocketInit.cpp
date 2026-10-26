// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057C860
// Canonical corpus name: TCPSocketInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TCPSocketInit_0057c860.c

void UnknownObject::TCPSocketInit()
{
    // Socket option setup for an already-created socket. Branches on the optval parameter: when non-zero it calls setsockopt(s, 6, 1, &val, 4) then setsockopt(s, 0xFFFF, 8, &val, 4); when zero it calls setsockopt(s, 0xFFFF, 32, &val, 4). In both paths it then registers asynchronous network events with WSAAsyncSelect(v3, dword_8D3E28, 0x1A0A, 63) and returns 1. All setsockopt calls resolve through the imported thunk at 0x0059E308 and WSAAsyncSelect through the thunk at 0x0059E320. Called by sub_57DC10 (0057DC10) and NetworkConnectionThread (0057FC80).
    // GUARD: Branches on the optval parameter: non-zero selects the two-call keepalive configuration path, zero selects the single-call broadcast configuration path [source:raw]
    // CALL: setsockopt(s, 6, 1, &val, 4) on the non-zero path, with val forced to 1; option set at level 6 (IPPROTO_TCP) via the imported thunk 0x0059E308 [global:0x0059E308, source:raw]
    // CALL: setsockopt(v3, 0xFFFF, 8, &val, 4) on the non-zero path, with val forced to 1; option set at level 0xFFFF (SOL_SOCKET) via the imported thunk 0x0059E308 [global:0x0059E308, source:raw]
    // CALL: setsockopt(s, 0xFFFF, 32, &val, 4) on the zero path, passing the optval variable itself as the option value; option set at level 0xFFFF (SOL_SOCKET) via the imported thunk 0x0059E308 [global:0x0059E308, source:raw]
    // CALL: WSAAsyncSelect(v3, dword_8D3E28, 0x1A0A, 63) registers asynchronous network events against the window handle stored at global 0x008D3E28, via the imported thunk 0x0059E320 [global:0x0059E320, global:0x008D3E28, source:raw]
    // RETURN: Returns constant 1 on both paths, signalling setup success [source:raw]
    // CALL: Invoked by sub_57DC10 (0057DC10) and NetworkConnectionThread (0057FC80) as part of network connection setup [caller:0x0057DC10, caller:0x0057FC80]

    // Conservative worker pseudocode:
    //   if (optval) {
    //     optval = 1;
    //     setsockopt(s, 6, 1, &optval, 4);
    //     s = 1;
    //     setsockopt(s, 0xFFFF, 8, &s, 4);
    //   } else {
    //     setsockopt(s, 0xFFFF, 32, &optval, 4);
    //   }
    //   WSAAsyncSelect(s, dword_8D3E28, 0x1A0A, 63);
    //   return 1;
    // UNRESOLVED: The numeric setsockopt level/option pairs (6/1, 0xFFFF/8, 0xFFFF/32) are used verbatim from the source; their Winsock constant meanings are not confirmed by packet evidence
    // UNRESOLVED: dword_8D3E28 is read as the WSAAsyncSelect window handle; its identity and type are unconfirmed
    // UNRESOLVED: The event mask 63 and message 0x1A0A are passed as literals; their enumerated meanings are not decoded by this packet
}
