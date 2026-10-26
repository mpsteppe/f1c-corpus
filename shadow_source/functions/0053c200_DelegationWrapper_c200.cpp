// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053C200
// Canonical corpus name: DelegationWrapper_c200
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DelegationWrapper_c200_0053c200.c

void UnknownObject::DelegationWrapper_c200()
{
    // Trivial delegation wrapper: calls DirectXDeviceSurfaceInitialization with the address of global dword_8B78A0 (0x008B78A0) as its single argument, and returns the callee's int result unchanged.
    // CALL: Call DirectXDeviceSurfaceInitialization passing the address of global dword_8B78A0 (0x008B78A0) as the single argument. [global:0x008B78A0, source:raw]
    // RETURN: Return the callee's int result unchanged. [source:raw]

    // Conservative worker pseudocode:
    //   return DirectXDeviceSurfaceInitialization((int)&dword_8B78A0);
    // UNRESOLVED: The target function DirectXDeviceSurfaceInitialization is not resolved in this packet; its exact identity and side effects are unknown here.
    // UNRESOLVED: The content and role of global dword_8B78A0 (0x008B78A0) are unknown.
}
