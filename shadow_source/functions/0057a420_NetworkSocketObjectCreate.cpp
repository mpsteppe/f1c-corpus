// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057A420
// Canonical corpus name: NetworkSocketObjectCreate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NetworkSocketObjectCreate_0057a420.c

void UnknownObject::NetworkSocketObjectCreate()
{
    // Allocates and initializes a network socket object into the output slot *this, with a caller-visible error flag *a3. Clears *a3 first; if the config value *a2 is greater than 1 it skips allocation and sets error (*a3 = 1, *this = 0). Otherwise allocates 3064 bytes via OperatorNewNhMallocWrapper and initializes through sub_57BA10(a2, a3); on allocation failure *this is set to 0. If *a3 ends set (initialization failed), invokes the vtable destructor at offset 68 on the object when present and nulls *this. Returns this. Called by sub_57ABB0 (0057ABB0).
    // ASSIGNMENT: Clears the output error flag *a3 to 0 before any validation or allocation [source:raw]
    // GUARD: When the config value *a2 is greater than 1, rejects the request: writes 0 to the output slot *this and sets the error flag *a3 to 1, skipping allocation entirely [field:this:0x00000000, source:raw]
    // CALL: In the accepted path, allocates 3064 bytes with OperatorNewNhMallocWrapper; on success initializes the object via sub_57BA10(a2, a3), otherwise v4 is 0 [callee:0x00587C03, callee:0x0057BA10, source:raw]
    // ASSIGNMENT: Stores the allocation result (v4 or 0 on failure) into the output slot *this [field:this:0x00000000, source:raw]
    // GUARD: If the init path set *a3 (failure), and v4 is non-null, calls the vtable destructor at object offset 68 (this+0x44) with argument 1, then nulls the output slot *this [field:this:0x00000000, source:raw]
    // RETURN: Returns this, the output slot pointer, in all paths [source:raw]
    // CALL: Invoked by sub_57ABB0 (0057ABB0) to create the socket object [caller:0x0057ABB0, source:raw]

    // Conservative worker pseudocode:
    //   *a3 = 0;
    //   if (*a2 > 1) {
    //     *this = 0;
    //     *a3 = 1;
    //   } else {
    //     if (OperatorNewNhMallocWrapper(3064))
    //       v4 = sub_57BA10(a2, a3);
    //     else
    //       v4 = 0;
    //     *this = v4;
    //     if (*a3) {
    //       if (v4)
    //         (*(void (**)(int, int))*(v4 + 68))(v4, 1);
    //       *this = 0;
    //     }
    //   }
    //   return this;
    // UNRESOLVED: The packet flags the SEH handler global SEH_57A420 (0x0059C75B) as read, but it never appears in the raw decompiled source; exception-safety wrapping is unverifiable from this packet
    // UNRESOLVED: The object layout (vtable at offset 0, destructor slot at offset 68, 3064-byte body) is implied by the raw source but the concrete struct type is unknown
}
