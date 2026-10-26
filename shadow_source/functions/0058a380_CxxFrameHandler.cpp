// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058A380
// Canonical corpus name: ___CxxFrameHandler
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/___CxxFrameHandler_0058a380.c

void UnknownObject::CxxFrameHandler()
{
    // MSVC C++ exception dispatch entry point (__usercall, first argument a1 delivered in eax). Passes its arguments through to sub_593446, appending the eax-delivered a1 and three zero-valued tail arguments, and returns sub_593446's result. Compiler-emitted frame-handler trampoline rather than hand-written game logic.
    // CALL: Call sub_593446 forwarding a2, a3, a4, a5 followed by the eax-delivered first argument a1 and three zero constants. [callee:0x00593446, source:raw]
    // RETURN: Return the result of sub_593446 unchanged. [source:raw]

    // Conservative worker pseudocode:
    //   int __usercall __CxxFrameHandler@<eax>(int a1@<eax>, int a2, int a3, int a4, int a5) {
    //     return sub_593446(a2, a3, a4, a5, a1, 0, 0, 0);
    //   }
    // UNRESOLVED: Sub_593446 likely implements the real C++ frame-handler logic (__CxxFrameHandler2/4 style); not established here.
    // UNRESOLVED: Meaning of the three zero tail arguments is only known to the compiler-emitted protocol.
}
