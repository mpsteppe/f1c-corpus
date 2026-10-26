## DirectXDeviceInitialization_0044fa60 — Create and initialize Direct3D device

**Summary:** Creates a Direct3D device, sets up vertex buffer, texture format, viewport parameters, and initializes force-feedback axis parameters. Stores device pointer at offset 0x80 and calls D3DTextureStage to finish setup. Called from HWInput_Setup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** HWInput_Setup (00455c60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x80)+0x0) | 0xC | R | — | Device vtable offset 0xC (method 3) — get caps/state interface |
| *(*(this+0x80)+0x0) | 0x18 | R | — | Device vtable offset 0x18 (method 6) — set/configure property |
| *(*(this+0x80)+0x0) | 0x1C | R | — | Device vtable offset 0x1C (method 7) — device method |
| *(*(this+0x80)+0x0) | 0x20 | R | — | Device vtable offset 0x20 (method 8) — create device/buffer |
| *(*(this+0x80)+0x0) | 0x2C | R | — | Device vtable offset 0x2C (method 11) — set texture format |
| *(*(this+0x80)+0x0) | 0x34 | R | — | Device vtable offset 0x34 (method 13) — set cooperative level |
| *(this+0x80) | 0x0 | R | — | Device vtable pointer |
| this | 0x80 | RW | 0 | Direct3D device pointer (cleared then set by CreateDevice) |
| this | 0x2C8 | RW | 44 | Viewport/parameter size for caps query (set to 44 = sizeof(D3DVIEWPORT9)) |
| this | 0x2F4 | R | — | Device interface count or capability version |

**Written-by note (persistence):**
- this 0x80: set once during init (overwritten if re-init); external poke survives
- this 0x2C8: set to 44 unconditionally; external poke overwrites

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0044ed10 | sub_44ED10 | R | Callback/enumeration function for device creation |
| 005ad490 | unk_5AD490 | R | D3D_VertexBufferDesc [DERIVED] |
| 005b108c | unk_5B108C | R | D3DTextureFormatDesc [DERIVED] |
| 007ca590 | ppvOut | R | ModulePtrArray [DERIVED] |
| 007cb310 | dword_7CB310 | W | DeviceCreateResult [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0044f8f0 | D3DTextureStage | Configures texture stage and force-feedback response after device creation |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x2F4 | != | 20 | Interface version/capability count — device re-creation guard |

**Guard interpretation:** BLOCKED: if offset 0x2F4 != 20, device is re-created from scratch (sets dword_7CB310 = 0, calls enum callback). PASSES: if already == 20, skips device re-creation and uses existing device interface.
