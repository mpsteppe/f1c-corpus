## sub_50FEA7_0050fea7 — D3D PSGP function table init by CPU feature

**Summary:** Initializes the D3D PSGP (parallel shader graphics pipeline) function pointer table by detecting CPU features (3DNow!, SSE2, SSE). Copies a template table, then patches entries based on the best available CPU feature, with registry override "DisableD3DXPSGP". Tracks state in dword_5D7998.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** FAILNODOCENTRY_c07c (0050c07c), sub_50C134 (0050c134), DispatchWithVTableCall (0050c20d), StartupCallWrapper (0050c27f), DirectXCallWrapper (0050c2a6), MathTrampoline3 (0050c2b9), NetworkAudioSend (0050c391), LockFunctionPointerCall (0050c48c), DispatchCallPair (0050c5b0), ShortComputation_c636 (0050c636), MathTrampoline (0050c647), D3DWrapperHook (0050c762), ProxyCallToPTRFUN005d789c (0050c85d), IndirectFunctionCallWrapper (0050c97a), PreDispatchWrapper (0050cba3), sub_50CDEC (0050cdec), ShortComputation_d0af (0050d0af), sub_50D44F (0050d44f), DelegationWrapperWithPreCall (0050d4d9), DispatchWithVTableCall_d563 (0050d563), DXWrapper (0050d5f9), NetworkAudioSend_d690 (0050d690), LockFunctionPointerCall_d728 (0050d728), DispatchCallPair_d84a (0050d84a), ArithmeticComparison_d93f (0050d93f), ProxyCallToPTRFUN005d7864 (0050d96d), IndirectCallViaGlobalPointer (0050d97e), IndirectCall (0050dc90), sub_50DD0C (0050dd0c), ShortComputation_de19 (0050de19), Thunk_df88 (0050df88), IndirectDispatchViaGlobalFunctionPointer (0050e174), DXWrapper_e281 (0050e281), NetworkAudioDispatchViaGlobal (0050e302), MathTrampoline2 (0050e313), LockIndirectCall (0050e3cd)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ade84 | aDisabled3dxpsg | R | "DisableD3DXPSGP" registry value name string |
| 005d77c8 | off_5D77C8 | R | PSGP function table (destination copy) |
| 005d78b0 | off_5D78B0 | R | PSGP function table template (source) |
| 005d7998 | dword_5D7998 | RW | PSGP init state: 0xFFFF=uninit, 0=none, 1=3DNow!, 2=SSE2, 3=SSE |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0050fbfc | sub_50FBFC | queries registry "DisableD3DXPSGP" DWORD override |
| 0050fdf3 | OSVersionDetection | checks CPU feature support (7=3DNow!, 10=SSE2, 6=SSE) |
| 00516fb0 | UnidentifiedLogicFunctionTable | PSGP table patcher for SSE (lowest priority) |
| 005170c0 | sub_5170C0 | PSGP table patcher for SSE2 |
| 005172a5 | sub_5172A5 | PSGP table patcher for 3DNow! (highest priority) |
| 00517927 | FunctionTableInit | resolves/initializes function table entries |

**Guard conditions:** Data parameter gates path: Data=0 → reset dword_5D7998 to 0xFFFF, re-copy template. Data!=0 → check if dword_5D7998 is uninitialized (0xFFFF). If already initialized (PASS through the init check is BLOCKED — skip init). Inside init: registry "DisableD3DXPSGP" with non-zero value sets Data=0, which then blocks all CPU feature patching (Data==1 emerges as the explicit force flag). Feature selection: 3DNow! checked first (highest priority), then SSE2, then SSE; if none match, table stays baseline (state 0).
