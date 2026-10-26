## TextureCreationWrapper_00462250 — TextureCreateNetworkSend

**Summary:** Creates a texture/data object via COM vtable, sets/overrides its type by argument, and sends it over the network.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetCommSessionMessageDispatcher (0045d890), MouseInputHandler (0045f030), InputCommandDispatchToEntities (0045f4a0), TeamRadioNetworkMessageProcessing (0045f710), SessionSynchronizer (0045f950), SendServerOKRequest (00460470), ParticleSoundEffectSpawner (004607a0), WeatherSurfaceUpdate (004628a0), SessionMessageUICommandHandler (00470490)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x3FB8 | R | — | COM interface pointer for object creation/dispatch |
| this | 0x0 | R | — | This pointer dereference |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057a680 | COMVTableCallVia0x60 | Create COM object via vtable at offset 0x60 |
| 0057a690 | VirtualMethodDispatch | Release/destroy the COM temporary object |
| 0057a6a0 | NetworkSendDispatch | Send the created object data over network |

**Guard conditions:** None — function always executes. When a4 == -1, sets byte at COM object+4 to 1 (default type). Otherwise calls vtable method at offset 12 on COM object to set type.
