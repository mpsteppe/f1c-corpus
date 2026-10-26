// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005804A0
// Canonical corpus name: NetworkSocketInitializationAndListen
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NetworkSocketInitializationAndListen_005804a0.c

void UnknownObject::NetworkSocketInitializationAndListen()
{
    // Initializes a network listener object: runs the virtual init callback (vtable+72), resumes the object's thread, binds the UDP socket at this+0x93C to the base port this+0x910 and the TCP socket at this+0x938 to base port + 50, stores the incoming IP string via sub_587DD0 and configures the byte flags at this+0x967..this+0x96B, then on success starts a TCP listen with a 0x7FFFFFFF backlog and dispatches the post-listen virtual callback (vtable+144) with a locally built value before returning 0; returns 6 when either bind fails.
    // CALL: Dispatches the virtual init callback at vtable+72 (obj+0x48) with this as the instance. [field:obj:0x00000048, field:this:0x00000000, source:raw]
    // CALL: Calls ThreadResumeWithMutexWait(this) to resume the object's thread under its mutex. [callee:0x00585680, source:raw]
    // ASSIGNMENT: Initializes locals: v4 = 1 (success), v10 = 0, v11 = 0, and reads v5 (socket handle) from this+0x93C and v6 (base port WORD) from this+0x910. [field:this:0x0000093C, field:this:0x00000910, source:raw]
    // GUARD: Guard on the two binds: if SocketBindPortScan(v5, v6) < 0 or SocketBindPortScan(TCP handle at this+0x938, base port + 50) < 0 then v4 = 0. [callee:0x0057C7B0, field:this:0x00000938, field:this:0x0000093C, source:raw]
    // CALL: Calls sub_587DD0(this + byte offset 2376, a2, 0x1F) to copy the incoming IP string a2 into the config buffer bounded to 0x1F bytes. [callee:0x00587DD0, source:raw]
    // ASSIGNMENT: Configures the byte flags: this+0x967 = 0, this+0x968 = 1, this+0x96B = a3, this+0x96A = 1. [field:this:0x00000967, field:this:0x00000968, field:this:0x0000096A, field:this:0x0000096B, source:raw]
    // STATE_TRANSITION: When v4 is zero (a bind failed) the routine returns error code 6 before any listen starts. [function:0x005804A0, source:raw]
    // CALL: Calls the imported listen() with the TCP socket handle at this+0x938 and backlog 0x7FFFFFFF. [global:0x0059E330, field:this:0x00000938, source:raw]
    // CALL: Calls ThreadSafeWriteWithMutex(this, 4) to record listener state 4 under the object's mutex. [callee:0x00585CD0, source:raw]
    // CALL: Dispatches the post-listen virtual callback at vtable+144 (obj+0x90) with arguments (this, &v9, 2, 1) where v9 starts at 0. [field:obj:0x00000090, field:this:0x00000000, source:raw]
    // CALL: Calls MutexProtectedFieldWrite(this, v9) to publish the value produced by the post-listen callback. [callee:0x005857C0, source:raw]
    // RETURN: Returns 0 on the success path. [function:0x005804A0, source:raw]

    // Conservative worker pseudocode:
    //   int NetworkSocketInitializationAndListen(__int16 *this, char *a2, char a3) {
    //     (*(vtable + 72))(this);
    //     ThreadResumeWithMutexWait((int)this);
    //     int v4 = 1;
    //     SOCKET v5 = this[591];
    //     __int16 v6 = this[1160];
    //     if ( SocketBindPortScan(v5, v6) < 0
    //       || SocketBindPortScan(this[590], this[1160] + 50) < 0 )
    //       v4 = 0;
    //     sub_587DD0((_BYTE *)this + 2376, a2, 0x1F);
    //     this[2407] = 0; this[2408] = 1; this[2411] = a3; this[2410] = 1;
    //     if ( !v4 )
    //       return 6;
    //     listen(this[590], 0x7FFFFFFF);
    //     ThreadSafeWriteWithMutex(this, 4);
    //     int v9 = 0;
    //     (*(vtable + 144))(this, &v9, 2, 1);
    //     MutexProtectedFieldWrite(this, v9);
    //     return 0;
    //   }
    // UNRESOLVED: Global 0x0059CA8B (SEH_5804A0) registers a structured exception handler for this routine but the handler's role and the failure it guards are not evidenced in the raw text.
    // UNRESOLVED: Meaning of the vtable+144 call arguments (2, 1) and of the value stored via MutexProtectedFieldWrite is not established.
    // UNRESOLVED: The buffer at this + byte offset 2376 is written by sub_587DD0 but has no named field evidence; its size/role beyond the 0x1F copy bound is unknown.
    // UNRESOLVED: Error code 6's meaning to the caller and the semantic of ThreadSafeWriteWithMutex constant 4 are not evidenced.
}
