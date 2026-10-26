// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004988D0
// Canonical corpus name: sub_4988D0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4988D0_004988d0.c

void UnknownObject::ContextRenderingSetup()
{
    // Contextual rendering setup: guarded on a non-empty string a2 and a non-zero validity field on the sub-object at this[6]+80, creates a rendering context via RenderingContextSetup(this, a2), then drives four virtual calls on the returned context (init, Setter apply, two-field copy, finalize). Called from MultiplayerPasswordValidation, sub_485B90 and UIClickEventDispatch.
    // GUARD: Return when a2 is null. [source:raw]
    // GUARD: Return when a2 is an empty string (strlen(a2) == 0). [source:raw]
    // GUARD: Return when the sub-object pointer at this[6] is null or its field at +80 is zero. [field:this:0x00000018, source:raw]
    // CALL: Create a rendering context from this and string a2. [callee:0x00497750, source:raw]
    // GUARD: Only proceed when the context object returned is non-null. [source:raw]
    // CALL: Call the context virtual init method (vtable slot at +140) on the new context. [source:raw]
    // CALL: Apply rendering state from the context back onto this via Setter. [callee:0x004979C0, source:raw]
    // CALL: Copy two dword fields from the context (indices [3] and [1]) to the rendering target. [callee:0x00553050, source:raw]
    // CALL: Call the context virtual finalize method (vtable slot at +144) on the context. [source:raw]

    // Conservative worker pseudocode:
    //   void sub_4988D0(DWORD *this, const char *a2) {
    //     if (!a2 || !strlen(a2) || !*(_DWORD *)(this[6] + 80)) return;
    //     DWORD *ctx = (DWORD *)RenderingContextSetup(this, (int)a2);
    //     if (ctx) {
    //       (*(void (**)(int))(*(_DWORD *)ctx + 140))(ctx);
    //       Setter(this, (int)ctx);
    //       TwoFieldSetter_3050(ctx[3], ctx[1]);
    //       (*(void (**)(DWORD *))(*ctx + 144))(ctx);
    //     }
    //   }
    // UNRESOLVED: Purpose of this+0x68 is not directly evidenced in the raw source.
    // UNRESOLVED: Identity of the context class and the meaning of its vtable slots +140 and +144 (init/finalize) are unknown.
    // UNRESOLVED: What the two dword fields copied by TwoFieldSetter_3050 represent is unresolved.
}
