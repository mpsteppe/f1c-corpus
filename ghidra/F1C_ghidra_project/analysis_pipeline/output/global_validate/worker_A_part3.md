| DAT_007cca28 | UIElementState | ui | int | read | N | UI element state flag used in element update chain and UI menu rendering |
| DAT_0059f080 | Vtable_RenderUIObject | renderer | ptr | offset | N | Vtable pointer assigned in constructor/destructor of render/UI object |
| DAT_007d0c18 | OptionAutoReverse | setup | byte | both | N | Game options flag stored in save file; byte at param_1+0x67 triggers UI update via FUN_0047f1f0 |
| DAT_0059f138 | RadToDegFactor | math_util | float | read | N | Radian-to-degree conversion factor used in 104-iteration utility function calling FUN_00464b10 |
| DAT_005c6958 | StrProfileIconBMP | ui | ptr | read | N | String literal "profileicon.bmp" for profile icon bitmap file path construction and copy operations |
| DAT_005abc28 | Vtable_UIWidget | ui | ptr | offset | N | Vtable pointer for UI widget class assigned in constructor FUN_00488b00 and destructor FUN_00488b30 |
| DAT_005cc544 | StrSetSymbol | ui | ptr | offset | N | String "SetSymbol" used as function/debug symbol name in UI rendering and debug output functions |
| DAT_005acaec | AITireGripThreshold | ai | float | read | N | Grip threshold compared against speedRatio (from vehicle offsets +0x39a0/+0x39a4) returning 3/7/0xF wheel grip bitmask |
| DAT_005acb28 | AISteerAngleThreshold | ai | float | read | N | Steering angle comparison threshold used with flt_5ACB30/flt_5ACB2C for AI path calculation |
| DAT_008affc8 | NetworkReplayPacketData | network | ptr | offset | N | Network/replay packet data area used in packet type dispatch parsing functions |
| DAT_005d2ab0 | StrTotalChampions | ui | ptr | offset | N | String "TotalChampions..." config key for championship total points option screen handler |
| DAT_005d2928 | StrGameOptFuelMult | ui | ptr | offset | N | String "GameOptFuelMult..." config key for fuel multiplier option screen handler |
| DAT_005acea8 | AudioNetworkTimingOffset | audio | float | read | N | Timing offset added to randomFloat * _DAT_0059e708 for audio/network effect jitter calculation |
| DAT_005ad034 | Vtable_UIWidgetFactory | ui | ptr | offset | N | Vtable pointer for UI widget factory dispatching type indices 0,1,2,6,7,8,0xD,0x11,0x13 to widget constructors |
| DAT_005d67b4 | RGBColorLookup | renderer | int | read | N | RGB color component lookup table returning color sets for input indices 0-4,0x2b,0xC-0x14,0x26-0x29,0x2c |
| DAT_008afe78 | NetworkPacketParam | network | int | both | N | Network packet state parameter stored from function parameter in network/render function |
| DAT_005d77f0 | CallbackFuncPtr | system | ptr | read | N | Function pointer for indirect call dispatch via (*(code *)PTR_FUN_005d77f0)() |
| DAT_008d4690 | SSE_NRConstant | math_util | double | read | N | SSE vector constant for Newton-Raphson reciprocal square root approximation in vector normalization |
| DAT_005b47e8 | Vtable_GameObject | game | ptr | offset | N | Vtable pointer for game object class assigned in constructor FUN_0052d9b0 and init FUN_0052d9f0 |
