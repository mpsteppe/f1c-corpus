// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045F2B0
// Canonical corpus name: SessionUIElementRenderer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SessionUIElementRenderer_0045f2b0.c

void UnknownObject::SessionUIElementRenderer()
{
    // Encodes a session UI element: reads session type from global dword_7C56A4; when it equals 7, copies a variable-length payload (byte count at this+0x3FD9, data starting at this+0x3FDA) into a local buffer and derives a size, otherwise uses a minimal payload. Encodes a progress-bar event with the current session time (dbl_8AFEA0), creates a COM object via the interface pointer at this+0x3FB8, applies the a2 argument (or a flag when a2 == -1), dispatches the element over the network, and returns the virtual-method dispatch result.
    // ASSIGNMENT: v8 = dword_7C56A4 (session type global). [global:0x007C56A4]
    // GUARD: Guard: when dword_7C56A4 == 7, read byte count v9 from this+0x3FD9, copy the payload from this+0x3FDA into the local buffer, and compute v3 = 4 * v9 + 2. [field:this:0x00003FD9]
    // ASSIGNMENT: Else branch: v9 = 0 and v3 = 1, a minimal payload size. [source:raw]
    // ASSIGNMENT: v6 = dbl_8AFEA0 (session time used for the progress-bar encode). [global:0x008AFEA0]
    // CALL: ProgressBarEventEncode(4, 2, v3, 255, LODWORD(session time), 1) encodes the progress-bar/session event. [callee:0x004B33B0]
    // CALL: Create the UI element COM object via COMVTableCallVia0x60 on the interface pointer stored at this+0x3FB8. [callee:0x0057A680, field:this:0x00003FB8]
    // GUARD: Guard: when a2 == -1 set object flag v4[4] = 1; otherwise call the vtable method at offset 12 on the object with a2 as the argument. [source:raw]
    // CALL: NetworkSendDispatch dispatches the encoded UI element, with a size computed from the local v7 ((v7 >> 8) & 0x3FF) + 8. [callee:0x0057A6A0]
    // RETURN: Return VirtualMethodDispatch on the object and the interface pointer at this+0x3FB8. [callee:0x0057A690, field:this:0x00003FB8]

    // Conservative worker pseudocode:
    //   int SessionUIElementRenderer(int self, int a2) {
    //     v8 = dword_7C56A4;
    //     int size;
    //     char count;
    //     if (dword_7C56A4 == 7) {
    //       count = *(BYTE *)(self + 16345);
    //       qmemcpy(payload, (void *)(self + 16346), 4 * ((unsigned)(4 * count) >> 2));
    //       size = 4 * count + 2;
    //     } else {
    //       count = 0; size = 1;
    //     }
    //     ProgressBarEventEncode(4, 2, size, 255, LODWORD(dbl_8AFEA0), 1);
    //     obj = COMVTableCallVia0x60(*(DWORD *)(self + 16312));
    //     if (a2 == -1) obj[4] = 1; else obj->vtbl[3](obj, a2);
    //     NetworkSendDispatch(&v7, ((v7 >> 8) & 0x3FF) + 8, obj, 1, 1, -1, 0);
    //     return VirtualMethodDispatch(*(DWORD *)(self + 16312), obj);
    //   }
    // UNRESOLVED: The local v7 used for the NetworkSendDispatch size is not written before the call in the raw source; its derivation is indirect and unresolved.
    // UNRESOLVED: The network message id derived from ((v7 >> 8) & 0x3FF) + 8 depends on that unresolved v7 value.
    // UNRESOLVED: The object created by COMVTableCallVia0x60 is COM-owned; its lifetime is not evidenced here.
}
