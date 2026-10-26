## StringSplitLoop_004d7a50 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIWaypointPathCheckerRenderer (004024f0), AIDatabase_Init (004040a0), CamMan_Init (0040c920), CamMan_Restart (0040c9e0), CamMan_Post (0040cce0), ConfigIniParser (00421cd0), DynMan_Enter (0042c130), DynMan_Setup (0042c170), DynMan_Init (0042c1a0), DynMan_Restart (0042c3b0), DynMan_Post (0042c9f0), DynMan_Exit (0042ca70), MultiplayerVehiclePlacement (0042cf10), GameFileLoader (0042d260), Game_Enter (0042d370), Game_Setup (0042d5d0), Game_Init (0042d6b0), Game_Restart (0042d7a0), GamePostMainLoop (0042d8a0), Game_Post (0042da30), GameExit (0042db20), VehicleSetupFileWriter (0042fd00), VehiclePhysicsInitializer (00439210), SuspensionBarLookup (0043af50), FrontSteeringGeometrySetup (0043b040), sub_43C250 (0043c250), TireCompoundPerWheelPhysicsApplication (0043da10), HATPolygonSurfaceFit (00449a80), HWInput_Enter (00455bf0), HWInput_Setup (00455c60), HWInput_Init (00455d50), HWInput_Restart (00455da0), HWInput_Post (00455e70), HWInput_Exit (00455f00), sub_45D2D0 (0045d2d0), NetCommSessionMessageDispatcher (0045d890), NodeIDToPlayerNameLookup (0045eb50), NetCommPlayerSlotSync (0045fc50), SendServerOKRequest (00460470), NetComm_SetSelfAsReady (00460520), ClearPlayerSlots (00460cb0), ServerOpenTrackSignal (00460e90), ServerCloseTrackSignal (00461020), ServerOpenedClosedNotification (00461190), TrackOpeningProgressTimer (004612e0), StartNetworkUpdate (00461de0), SendJoinRequest (00462c00), sub_462E20 (00462e20), NetCommParseCommandLine (00463160), AutoJoinRetryLoop (004637a0), SynchronizeWithServer (00464290), MultiplayerSessionJoinHandler (0046de10), CUBESceneLoaderEntry (0048e8d0), OnScreen_Enter (0049ef40), OnScreen_Setup (0049ef70), OnScreen_Init (0049efa0), OnScreen_Restart (0049f000), OnScreen_Post (0049f0d0), OnScreen_Exit (0049f120), Options_Setup (004a0eb0), OSMan_Enter (004a18d0), PitCrewMeshLoader (004a2010), sub_4A22D0 (004a22d0), PitCrewAnimationLoader (004a2a90), sub_4B0770 (004b0770), PlayerFile_Enter (004b1820), PlayerFile_Setup (004b1870), PlayerFile_Restart (004b18d0), PlayerFile_Post (004b1900), Render_Init (004b4030), Render_Restart (004b4060), Render_Post (004b4170), sub_4BA1F0 (004ba1f0), SceneExtentComputation (004bdc10), VehFileParser (004c3200), VehicleFileLoader (004c3d80), FileFinder (004c40d0), SceneFileLoader (004c52c0), Sound_Enter (004c8a20), Sound_Setup (004c8ab0), Sound_Init (004c8ae0), Sound_Restart (004c8b20), Sound_Post (004c8ca0), Sound_Exit (004c8d00), MaterialShaderReactionEffectParser (004ca480), sub_4CADA0 (004cada0), sub_4CB120 (004cb120), sub_4CDC70 (004cdc70), SpecialFX_Enter (004cee90), SpecialFX_Setup (004ceec0), SpecialFX_Init (004cf070), SpecialFX_Restart (004cfc90), SpecialFX_Post (004cfed0), SpecialFX_Exit (004cfff0), sub_4D0110 (004d0110), StewardLightGlowNodeFinder (004d0e20), Steward_Setup (004d36d0), Steward_Init (004d38f0), Steward_Restart (004d3cf0), Steward_Post (004d4600), TireLoadFactorSetter (004d5ee0), TireSlipCurveBuilder (004d5f70), TireBrandFileParser (004d7150), CompoundIndexLookup (004d7570), TireSlipCurveNameLookup (004d75d0), TireBrandLoader (004d7660), TireBrandLookup (004d7880), TextureAdjuster (004dc770), SceneFileTEAMDIRVEHDIRNOTSPINWriter (004ddf90), VehicleGraphicsSceneLoader (004dfce0), VehicleDampingDirectionValidation (004f3240), EngineSectionParser (004f3c80), TheSvmHdvVehicleFileParser (004f4270), sub_4F9310 (004f9310), VidMan_Enter (004fa000), VidMan_Setup (004fa2f0), VidMan_Init (004fa320), VidMan_Restart (004fa640), VidMan_Post (004fac00), VidMan_Exit (004fad00), WeatherConditionsFileWriter (004fe820)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c2aac | word_5C2AAC | R | BackslashChar [DERIVED] (also: ` — backslash character (docs/08 path_util.cpp) |
| 005d4a38 | a1212s5d | R | String_1212s5d [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7aa0 | DebugLogWrite | [LLM] |
| 00587c20 | sub_587C20 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
