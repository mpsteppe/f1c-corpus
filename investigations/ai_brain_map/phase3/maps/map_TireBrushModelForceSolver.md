# map_TireBrushModelForceSolver - `TireBrushModelForceSolver` (GUESS name)

## Identity

- Address: `0x004E8010`; file `functions/TireBrushModelForceSolver_004e8010.c`; 427 lines.
- Signature: `void __thiscall sub_4E8010(int this, char a2)`.
- Callers (read-only corpus cache): `AccumulatorClamp`, `ActorMotionPostProcessingUpdate`, `CollisionWrapperWithLock`, `FuelConsumptionAndWear`, `LargeConfigFunctionWithPhysicsConstants`, `LoopWithConditionalSubCall`, `RepairServiceStateDispatcher`, `ScaleAudioPitch`, `sub_4F18C0`.
- Callees (from `offsets_TireBrushModelForceSolver.csv` CALL rows): none (CSV has only CALL rows of other forms or none).
- This is a terse phase-3 triage map; the name is a GUESS until reviewed.

## Inputs

| hex | dec | type | line | expr |
|---|---|---|---|---|
| 0x368C | 13964 | float | L112 | `/ (fabs(*(float *)(this + 13964) + *(float *)(this + 13716) - *(float ` |
| 0x3594 | 13716 | float | L112 | `/ (fabs(*(float *)(this + 13964) + *(float *)(this + 13716) - *(float ` |
| 0x3784 | 14212 | float | L112 | `/ (fabs(*(float *)(this + 13964) + *(float *)(this + 13716) - *(float ` |
| 0x387C | 14460 | float | L112 | `/ (fabs(*(float *)(this + 13964) + *(float *)(this + 13716) - *(float ` |
| 0x358C | 13708 | float | L115 | `/ (fabs(*(float *)(this + 13708) - *(float *)(this + 13956) + *(float ` |
| 0x3684 | 13956 | float | L115 | `/ (fabs(*(float *)(this + 13708) - *(float *)(this + 13956) + *(float ` |
| 0x377C | 14204 | float | L115 | `/ (fabs(*(float *)(this + 13708) - *(float *)(this + 13956) + *(float ` |
| 0x3874 | 14452 | float | L115 | `/ (fabs(*(float *)(this + 13708) - *(float *)(this + 13956) + *(float ` |
| 0x48 | 72 | float | L125 | `v9 = v74 * v6[18];` |
| 0x4024 | 16420 | float | L136 | `v12 = v8 * *(float *)(this + 16420);` |
| 0x48 | 72 | float | L148 | `v17 = v16 + v74 * v14[18];` |
| 0x39B4 | 14772 | _DWORD | L160 | `v21 = *(_DWORD *)(this + 14772);` |
| 0x48 | 72 | float | L185 | `v25 = v24 + v74 * v23[18];` |
| 0x48 | 72 | float | L205 | `v31 = v30 + v74 * v29[18];` |
| 0x48 | 72 | float | L225 | `v38 = v37 + v74 * v36[18];` |
| 0x39B4 | 14772 | _DWORD | L243 | `v41 = *(_DWORD *)(this + 14772);` |
| 0x38F8 | 14584 | float | L246 | `v43 = *(float *)(this + 14584) + *(float *)(this + 14336);` |
| 0x3800 | 14336 | float | L246 | `v43 = *(float *)(this + 14584) + *(float *)(this + 14336);` |
| 0x38F8 | 14584 | float | L254 | `v44 = (*(float *)(this + 14584) + *(float *)(this + 14336) + *(float *` |
| 0x3800 | 14336 | float | L254 | `v44 = (*(float *)(this + 14584) + *(float *)(this + 14336) + *(float *` |
| 0x3708 | 14088 | float | L254 | `v44 = (*(float *)(this + 14584) + *(float *)(this + 14336) + *(float *` |
| 0x3610 | 13840 | float | L254 | `v44 = (*(float *)(this + 14584) + *(float *)(this + 14336) + *(float *` |
| 0x3708 | 14088 | float | L262 | `v43 = *(float *)(this + 14088) + *(float *)(this + 13840);` |
| 0x3610 | 13840 | float | L262 | `v43 = *(float *)(this + 14088) + *(float *)(this + 13840);` |
| 0x3A44 | 14916 | float | L273 | `v49 = *(float *)(this + 14916);` |
| 0x3A30 | 14896 | float | L275 | `v49 = *(float *)(this + 14896);` |
| 0x3518 | 13592 | float | L282 | `v51 = v45 * *(float *)(this + 13592);` |
| 0x3A6C | 14956 | float | L285 | `v53 = *(float *)(this + 14956);` |
| 0x3A6C | 14956 | float | L286 | `*(float *)(this + 15684) = *(float *)(this + 14956);` |
| 0x3A70 | 14960 | float | L287 | `v54 = *(float *)(this + 14960) * 4096.0 - *(float *)(this + 13588) * -` |
| 0x3514 | 13588 | float | L287 | `v54 = *(float *)(this + 14960) * 4096.0 - *(float *)(this + 13588) * -` |
| 0x28 | 40 | float | L293 | `v98[v52] = v54 / *v46 * v46[10];` |
| 0x3BF4 | 15348 | float | L304 | `v57 = 1.0 / *(float *)(this + 15348);` |
| 0x3C | 60 | float | L312 | `*(float *)(v56 + 60) = *(float *)(v56 + 60) * v57 * 0.83999997;` |
| 0x7C | 124 | float | L313 | `*(float *)(v56 + 124) = *(float *)(v56 + 124) * v57 * 0.92000002;` |
| 0x3C | 60 | float | L327 | `*(float *)(v56 + 60) = *(float *)(v56 + 60) * v59;` |
| 0x7C | 124 | float | L328 | `*(float *)(v56 + 124) = *(float *)(v56 + 124) * 0.97000003;` |
| 0x3514 | 13588 | float | L344 | `v86 = v75 * *(float *)(this + 13588) * v75 * v96;` |
| 0x3A70 | 14960 | float | L345 | `v62 = v75 * v75 * *(float *)(this + 14960) - (v75 * v75 * 0.0 - 9.8100` |
| 0x3514 | 13588 | float | L345 | `v62 = v75 * v75 * *(float *)(this + 14960) - (v75 * v75 * 0.0 - 9.8100` |
| 0x3C3C | 15420 | float | L347 | `v63 = v62 * *(float *)(this + 15420);` |
| 0x3C40 | 15424 | float | L360 | `v65 = *(float *)(this + 4 * v64 + 15424);` |
| 0x3C44 | 15428 | float | L361 | `v80 = (*(float *)(this + 4 * v64 + 15428) - v65) * (v88 - (double)v79)` |
| 0x3C40 | 15424 | float | L365 | `v80 = *(float *)(this + 15424);` |
| 0x3C7C | 15484 | float | L367 | `v66 = v91 * *(float *)(this + 15484);` |
| 0x3C80 | 15488 | float | L380 | `v69 = *(float *)(this + 4 * v67 + 15488);` |
| 0x3C84 | 15492 | float | L381 | `v68 = v69 + (*(float *)(this + 4 * v67 + 15492) - v69) * (v89 - (doubl` |
| 0x3C80 | 15488 | float | L385 | `v68 = *(float *)(this + 15488);` |

## Outputs

| hex | dec | type | line | expr |
|---|---|---|---|---|
| 0x3BFC | 15356 | float | L106 | `*(float *)(this + 15356) = v5;` |
| 0x3C3C | 15420 | float | L107 | `*(float *)(this + 15420) = v5;` |
| 0x3C7C | 15484 | float | L108 | `*(float *)(this + 15484) = v5;` |
| 0x3CBC | 15548 | float | L109 | `*(float *)(this + 15548) = v5;` |
| 0x3CFC | 15612 | float | L110 | `*(float *)(this + 15612) = 1.0 / (v87 * 0.071428575);` |
| 0x3D40 | 15680 | float | L257 | `*(float *)(this + 15680) = v44;` |
| 0x3D3C | 15676 | float | L284 | `*(float *)(this + 15676) = v51;` |
| 0x3D44 | 15684 | float | L286 | `*(float *)(this + 15684) = *(float *)(this + 14956);` |
| 0x3D44 | 15684 | float | L300 | `*(float *)(this + 15684) = ((v98[3] + v98[2]) * 0.27500001 + (v98[1] +` |
| 0x3D3C | 15676 | float | L303 | `*(float *)(this + 15676) = v51 * 0.92000002;` |
| 0x3C | 60 | float | L312 | `*(float *)(v56 + 60) = *(float *)(v56 + 60) * v57 * 0.83999997;` |
| 0x7C | 124 | float | L313 | `*(float *)(v56 + 124) = *(float *)(v56 + 124) * v57 * 0.92000002;` |
| 0x3D3C | 15676 | float | L319 | `*(float *)(this + 15676) = v51 * flt_7D020C;` |
| 0x3C | 60 | float | L327 | `*(float *)(v56 + 60) = *(float *)(v56 + 60) * v59;` |
| 0x7C | 124 | float | L328 | `*(float *)(v56 + 124) = *(float *)(v56 + 124) * 0.97000003;` |

## Constants

Every numeric literal except 0/1 in the quoted source lines below.

## Logic

```
     void __thiscall sub_4E8010(int this, char a2)   [L1]
```

## Meaning (GUESS)

- GUESS Full tyre brush force solver (427 lines) called by the physics update; AI consumes its effects only indirectly through the tyre tables.
- GUESS AI relevance: low -- shared physics, not on the AI decision path.

## Questions

- None for this triage map; name and meaning stay GUESS.
