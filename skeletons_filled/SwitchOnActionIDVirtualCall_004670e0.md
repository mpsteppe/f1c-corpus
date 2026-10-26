## SwitchOnActionIDVirtualCall_004670e0 — DispatchByActionID

**Summary:** Dispatches based on action ID (this[205]-236, range 0-0xB1). Uses jump table byte_46713C. Case 0: calls virtual method +28 on dword_7CD8C0 with arg 14, then ObjectNameComparison. Case 1: same with arg 11. Case 2: immediate return 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UIScreenConstructor (00470670), ShortComputation_1540 (00471540), ShortComputation_15d0 (004715d0), ConstructorLEDIndicatorSetup (00471650), GraphicsConstructorWithConstants (004716d0), ObjectInitializerWithGlobals (00471750), ComplexConstructor (004717e0), ObjectConstructorWithVTableAndFieldInit (00471860), sub_4718E0 (004718e0), ShortComputation_1970 (00471970), ObjectConstructor_1a00 (00471a00), UIObjectConstructorWithDefaults (00471b20), sub_472A80 (00472a80), ShortComputation_3c40 (00473c40), ObjectConstructor_3cc0 (00473cc0), UIObjectConstructor (00473dd0), ObjectInitWithGlobalRef (00473e50), ConstructorWithDefaults (00473ed0), UIOptionsConstructor_3fd0 (00473fd0), ObjectInitWithVTableRenderStateConfig (004742a0), UICameraConstructor2 (00474900)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x334 | R | — | field 205 — action ID used as switch index |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00467130 | jpt_4670FC | R | jump table base for action dispatch |
| 0046713c | byte_46713C | R | action-to-case mapping table (177 entries max) |
| 007cd8c0 | dword_7CD8C0 | R | GameCommandDispatchInterface [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00477280 | ObjectNameComparison | compare/check object name after dispatch |

**Guard conditions:** Action ID = this[205] - 236 must be ≤ 0xB1 (177) to enter switch. If > 177, return 0 (BLOCKED). Inside switch: case 2 returns 0 (BLOCKED/no-op). Cases 0 and 1: call virtual and ObjectNameComparison if virtual returns non-zero (PASS).
