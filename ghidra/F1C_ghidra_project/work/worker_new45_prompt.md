# F1C Worker — Document 45 Newly Discovered Functions

These 45 functions were found by Phase 0 binary coverage audit — Ghidra missed them
during initial analysis. They have now been created and decompiled. Document each one
in full `## FUN_` format (Mode 2).

## YOUR TASK

For each function below:
1. Read the decompiled C source provided
2. Write a full `## FUN_XXXXXXXX — Name` entry
3. Route it to the correct docs file via `<!-- target: docs/XX-name.md -->`
4. Use the DOCS MAPPING below to choose the target

## DOCS MAPPING

| Doc file | Content |
|----------|---------|
| `docs/01-engine-architecture.md` | Module lifecycle, game state machine, main loop |
| `docs/02-ai-system.md` | AI ability, qualifying, difficulty, shift logic, waypoints |
| `docs/03-engine-wear-damage.md` | Damage model, failures, RPM limits, thermal model |
| `docs/04-tire-system.md` | Tire compounds, slip curves, tire wear |
| `docs/05-weather-system.md` | Weather modes, rain, track conditions |
| `docs/06-session-race-logic.md` | Penalties, scoring, standings, grid, race state |
| `docs/07-pit-system.md` | Pit strategy, crew, animations, repair |
| `docs/08-file-formats.md` | File parsers (.svm/.hdv/.veh/.scn) |
| `docs/09-track-system.md` | Track DB, surface materials, cameras |
| `docs/10-vehicle-physics.md` | Suspension, brakes, aero, body mapping |
| `docs/17-physics-collision.md` | Collision detection, contact manifold |
| `docs/18-physics-dynamics.md` | Rigid body, tire brush model, integration |
| `docs/19-renderer.md` | D3D pipeline, mesh, LOD, rendering |
| `docs/20-math-utilities.md` | Pure math leaf functions |
| `docs/21-audio-network-internals.md` | Audio mixing, network packets |

## ENTRY FORMAT

```markdown
<!-- target: docs/XX-name.md -->
## FUN_00XXXXXX — Descriptive Name

Source: likely_source.cpp. One-line summary.

**Key logic:**
- Step-by-step behavior
- Thresholds, comparisons, state transitions

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0xXXX | FieldName | type, purpose |

**Globals:**
- `DAT_XXXXXXXX` — meaning

**Calls:** FUN_00AAAAAA (purpose)

**Moddability:** `hardcoded` | `configurable` | `hookable`
```

## RULES
- Header MUST be `## FUN_` (h2), never h3 or h1
- `<!-- target: -->` comment MUST appear on line immediately before `## FUN_`
- No double `.md.md` in target path
- If function is pure math/utility with no game globals → target `docs/20-math-utilities.md`
- Do not skip any function

---

## FUNCTIONS TO DOCUMENT


### Source: 0x00538a90__FUN_00538a90.c

```c

void __fastcall FUN_00538a90(int param_1,int param_2,int param_3,int param_4)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int unaff_retaddr;
  
  iVar2 = *(int *)(param_1 + 0x16ad);
  iVar3 = param_2 + -0x101;
  if (iVar2 < 0xc) {
    *(ushort *)(param_1 + 0x16ab) =
         *(ushort *)(param_1 + 0x16ab) | (ushort)(iVar3 << ((byte)iVar2 & 0x1f));
    *(int *)(param_1 + 0x16ad) = iVar2 + 5;
  }
  else {
    *(ushort *)(param_1 + 0x16ab) =
         *(ushort *)(param_1 + 0x16ab) | (ushort)(iVar3 << ((byte)iVar2 & 0x1f));
    *(undefined1 *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 8)) =
         *(undefined1 *)(param_1 + 0x16ab);
    iVar2 = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x14) = iVar2;
    *(undefined1 *)(iVar2 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16ac);
    iVar2 = *(int *)(param_1 + 0x16ad);
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x16ad) = iVar2 + -0xb;
    *(ushort *)(param_1 + 0x16ab) = (ushort)iVar3 >> (0x10U - (char)iVar2 & 0x1f);
  }
  iVar3 = *(int *)(param_1 + 0x16ad);
  param_3 = param_3 + -1;
  if (iVar3 < 0xc) {
    *(ushort *)(param_1 + 0x16ab) =
         *(ushort *)(param_1 + 0x16ab) | (ushort)(param_3 << ((byte)iVar3 & 0x1f));
    *(int *)(param_1 + 0x16ad) = iVar3 + 5;
  }
  else {
    *(ushort *)(param_1 + 0x16ab) =
         *(ushort *)(param_1 + 0x16ab) | (ushort)(param_3 << ((byte)iVar3 & 0x1f));
    *(undefined1 *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 8)) =
         *(undefined1 *)(param_1 + 0x16ab);
    iVar3 = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x14) = iVar3;
    *(undefined1 *)(iVar3 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16ac);
    iVar3 = *(int *)(param_1 + 0x16ad);
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x16ad) = iVar3 + -0xb;
    *(ushort *)(param_1 + 0x16ab) = (ushort)param_3 >> (0x10U - (char)iVar3 & 0x1f);
  }
  iVar2 = *(int *)(param_1 + 0x16ad);
  iVar3 = param_4 + -4;
  if (iVar2 < 0xd) {
    *(ushort *)(param_1 + 0x16ab) =
         *(ushort *)(param_1 + 0x16ab) | (ushort)(iVar3 << ((byte)iVar2 & 0x1f));
    *(int *)(param_1 + 0x16ad) = iVar2 + 4;
  }
  else {
    *(ushort *)(param_1 + 0x16ab) =
         *(ushort *)(param_1 + 0x16ab) | (ushort)(iVar3 << ((byte)iVar2 & 0x1f));
    *(undefined1 *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 8)) =
         *(undefined1 *)(param_1 + 0x16ab);
    iVar2 = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x14) = iVar2;
    *(undefined1 *)(iVar2 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16ac);
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    iVar2 = *(int *)(param_1 + 0x16ad);
    *(int *)(param_1 + 0x16ad) = iVar2 + -0xc;
    *(ushort *)(param_1 + 0x16ab) = (ushort)iVar3 >> (0x10U - (char)iVar2 & 0x1f);
  }
  iVar3 = 0;
  if (0 < param_4) {
    do {
      iVar2 = *(int *)(param_1 + 0x16ad);
      if (iVar2 < 0xe) {
        *(ushort *)(param_1 + 0x16ab) =
             *(ushort *)(param_1 + 0x16ab) |
             *(short *)(param_1 + 0xa74 + (uint)(byte)(&UNK_005b7dec)[iVar3] * 4) <<
             ((byte)iVar2 & 0x1f);
        *(int *)(param_1 + 0x16ad) = iVar2 + 3;
      }
      else {
        uVar1 = *(ushort *)(param_1 + 0xa74 + (uint)(byte)(&UNK_005b7dec)[iVar3] * 4);
        *(ushort *)(param_1 + 0x16ab) =
             *(ushort *)(param_1 + 0x16ab) | uVar1 << ((byte)iVar2 & 0x1f);
        *(undefined1 *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 8)) =
             *(undefined1 *)(param_1 + 0x16ab);
        iVar2 = *(int *)(param_1 + 0x14) + 1;
        *(int *)(param_1 + 0x14) = iVar2;
        *(undefined1 *)(iVar2 + *(int *)(param_1 + 8)) = *(undefined1 *)(param_1 + 0x16ac);
        *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
        iVar2 = *(int *)(param_1 + 0x16ad);
        *(int *)(param_1 + 0x16ad) = iVar2 + -0xd;
        *(ushort *)(param_1 + 0x16ab) = uVar1 >> (0x10U - (char)iVar2 & 0x1f);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_4);
  }
  func_0x00538ce0(param_2 + -1);
  func_0x00538ce0(unaff_retaddr + -1);
  return;
}
```

---

### Source: 0x0047b1e0__FUN_0047b1e0.c

```c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0047b1e0(int *param_1)

{
  float fVar1;
  int iVar2;
  float10 fVar3;
  int iStack_c;
  undefined4 auStack_8 [2];
  
  (**(code **)(*param_1 + 0x2c))(1);
  FUN_00498880(auStack_8,&iStack_c);
  fVar3 = (float10)FUN_00498730();
  fVar1 = (float)(fVar3 + (float10)(float)param_1[0x42]);
  param_1[0x42] = (int)fVar1;
  switch(param_1[0x41]) {
  case 1:
    iVar2 = FUN_0047b850(auStack_8[0],iStack_c);
    fVar1 = _DAT_0059e4e0;
    param_1[0x39] = iVar2;
    if (fVar1 < (float)param_1[0x42]) {
      param_1[0x42] = (int)((float)param_1[0x42] - _DAT_0059e4e0);
      if (iStack_c <= param_1[1] + param_1[0x3f]) {
        FUN_0047bae0(0xffffffff);
      }
      if (param_1[2] - param_1[0x3f] <= iStack_c) {
        FUN_0047bae0(1);
        (**(code **)(*param_1 + 0x54))();
        return;
      }
    }
    break;
  case 2:
    if (_DAT_0059e4e0 < fVar1) {
      param_1[0x42] = (int)(fVar1 - _DAT_0059e4e0);
      FUN_0047bae0(0xffffffff);
      (**(code **)(*param_1 + 0x54))();
      return;
    }
    break;
  case 3:
    if (_DAT_0059e4e0 < fVar1) {
      param_1[0x42] = (int)(fVar1 - _DAT_0059e4e0);
      FUN_0047bae0(1);
      (**(code **)(*param_1 + 0x54))();
      return;
    }
    break;
  case 4:
    iStack_c = iStack_c - param_1[0x47];
    param_1[0x44] = iStack_c;
    if (-1 < iStack_c) {
      if (param_1[0x45] < iStack_c) {
        param_1[0x44] = param_1[0x45];
      }
      FUN_0047be00();
      (**(code **)(*param_1 + 0x54))();
      return;
    }
    param_1[0x44] = 0;
    FUN_0047be00();
    (**(code **)(*param_1 + 0x54))();
    return;
  case 5:
    if (_DAT_0059e7f8 < fVar1) {
      param_1[0x42] = (int)(fVar1 - _DAT_0059e7f8);
      FUN_0047bb40(iStack_c);
    }
  }
  (**(code **)(*param_1 + 0x54))();
  return;
}
```

---

### Source: 0x004cd220__FUN_004cd220.c

```c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004cd220(int param_1)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  float fStack_b0;
  int iStack_a8;
  int iStack_a0;
  float fStack_9c;
  float fStack_98;
  float fStack_94;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  undefined4 uStack_5c;
  float fStack_58;
  float fStack_54;
  undefined4 uStack_50;
  float fStack_4c;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_4;
  
  iVar4 = FUN_0040c870();
  fStack_90 = *(float *)(iVar4 + 0x24);
  fStack_8c = *(float *)(iVar4 + 0x28);
  fStack_88 = *(float *)(iVar4 + 0x2c);
  if (DAT_008ab6e4 == 2) {
    iVar4 = FUN_004b9e30();
    if (iVar4 == 5) {
      fStack_b0 = 0.0;
      goto LAB_004cd28d;
    }
    fVar7 = (float10)FUN_004b9cf0();
  }
  else {
    fVar7 = (float10)_DAT_008afe98;
  }
  fStack_b0 = (float)fVar7;
LAB_004cd28d:
  if (DAT_008ab6e4 == 2) {
    fVar7 = (float10)FUN_004b9ce0();
  }
  else {
    fVar7 = (float10)_DAT_008afea0;
  }
  iStack_a8 = 0;
  if (0 < *(int *)(param_1 + 100)) {
    do {
      iVar4 = *(int *)(*(int *)(param_1 + 0x68) + iStack_a8 * 4);
      if ((*(float *)(iVar4 + 0xc) < (float)fVar7) || ((float)fVar7 < *(float *)(iVar4 + 8))) {
        FUN_004cb5a0(iVar4);
        iStack_a8 = iStack_a8 + -1;
      }
      else {
        pfVar1 = (float *)(iVar4 + 0x2c);
        *pfVar1 = fStack_b0 * *(float *)(iVar4 + 0x38) + *pfVar1;
        *(float *)(iVar4 + 0x30) = fStack_b0 * *(float *)(iVar4 + 0x3c) + *(float *)(iVar4 + 0x30);
        *(float *)(iVar4 + 0x34) = fStack_b0 * *(float *)(iVar4 + 0x40) + *(float *)(iVar4 + 0x34);
        *(float *)(iVar4 + 0x3c) = *(float *)(iVar4 + 0x3c) - ABS(fStack_b0) * _DAT_005aceb8;
        fVar2 = *pfVar1 * *(float *)(iVar4 + 0x54) +
                *(float *)(iVar4 + 0x30) * *(float *)(iVar4 + 0x58) +
                *(float *)(iVar4 + 0x34) * *(float *)(iVar4 + 0x5c);
        if (fVar2 < *(float *)(iVar4 + 100)) {
          fVar2 = *(float *)(iVar4 + 100) - fVar2;
          fStack_44 = fVar2 * *(float *)(iVar4 + 0x58);
          fStack_40 = fVar2 * *(float *)(iVar4 + 0x5c);
          *pfVar1 = fVar2 * *(float *)(iVar4 + 0x54) + *pfVar1;
          *(float *)(iVar4 + 0x30) = fStack_44 + *(float *)(iVar4 + 0x30);
          *(float *)(iVar4 + 0x34) = fStack_40 + *(float *)(iVar4 + 0x34);
          fVar2 = *(float *)(iVar4 + 0x38) * *(float *)(iVar4 + 0x54) +
                  *(float *)(iVar4 + 0x3c) * *(float *)(iVar4 + 0x58) +
                  *(float *)(iVar4 + 0x40) * *(float *)(iVar4 + 0x5c);
          fVar2 = fVar2 + fVar2;
          fStack_2c = fVar2 * *(float *)(iVar4 + 0x58);
          fStack_28 = fVar2 * *(float *)(iVar4 + 0x5c);
          *(float *)(iVar4 + 0x38) = *(float *)(iVar4 + 0x38) - fVar2 * *(float *)(iVar4 + 0x54);
          *(float *)(iVar4 + 0x3c) = *(float *)(iVar4 + 0x3c) - fStack_2c;
          *(float *)(iVar4 + 0x40) = *(float *)(iVar4 + 0x40) - fStack_28;
          fVar2 = *(float *)(iVar4 + 0x38);
          if (fStack_b0 < DAT_0059e440) {
            *(float *)(iVar4 + 0x38) = fVar2 + fVar2;
            *(float *)(iVar4 + 0x3c) = *(float *)(iVar4 + 0x3c) + *(float *)(iVar4 + 0x3c);
            *(float *)(iVar4 + 0x40) = *(float *)(iVar4 + 0x40) + *(float *)(iVar4 + 0x40);
          }
          else {
            *(float *)(iVar4 + 0x38) = fVar2 * _DAT_0059e450;
            *(float *)(iVar4 + 0x3c) = *(float *)(iVar4 + 0x3c) * _DAT_0059e450;
            *(float *)(iVar4 + 0x40) = *(float *)(iVar4 + 0x40) * _DAT_0059e450;
          }
        }
        if ((DAT_007cfa4c & 3) != 0) {
          fStack_9c = *(float *)(iVar4 + 0x38) * _DAT_0059ed18;
          fStack_98 = *(float *)(iVar4 + 0x3c) * _DAT_0059ed18;
          fStack_94 = *(float *)(iVar4 + 0x40) * _DAT_0059ed18;
          if (DAT_007cfa4c == 1) {
            if (DAT_007c54e0 != 0) {
              fStack_60 = *(float *)(DAT_007c54e0 + 0x744);
              uStack_5c = *(undefined4 *)(DAT_007c54e0 + 0x748);
              fStack_58 = *(float *)(DAT_007c54e0 + 0x74c);
              if ((ABS(fStack_60 - *pfVar1) < _DAT_0059e46c) &&
                 (ABS(fStack_58 - *(float *)(iVar4 + 0x34)) < _DAT_0059e46c)) {
                fStack_6c = fStack_9c + *pfVar1;
                fStack_68 = fStack_98 + *(float *)(iVar4 + 0x30);
                fStack_64 = fStack_94 + *(float *)(iVar4 + 0x34);
                fStack_18 = fStack_6c;
                fStack_14 = fStack_68;
                fStack_10 = fStack_64;
                FUN_004cbf50(&fStack_18,pfVar1,DAT_007c54e0 + 0x6f0);
              }
            }
          }
          else {
            iVar5 = FUN_004c9c70(*pfVar1 + *(float *)(iVar4 + 0x34),0x40b504f3,&iStack_a0);
            iVar6 = 0;
            if (0 < iStack_a0) {
              do {
                iVar3 = *(int *)(iVar5 + iVar6 * 4);
                fStack_54 = *(float *)(iVar3 + 0x738);
                uStack_50 = *(undefined4 *)(iVar3 + 0x73c);
                fStack_4c = *(float *)(iVar3 + 0x740);
                if (((ABS(fStack_54 - *pfVar1) < _DAT_0059e46c) &&
                    (ABS(fStack_4c - *(float *)(iVar4 + 0x34)) < _DAT_0059e46c)) &&
                   (((DAT_007cfa4c & 1) != 0 || (*(int *)(iVar3 + 4) != DAT_007c54dc)))) {
                  fStack_78 = fStack_9c + *pfVar1;
                  fStack_74 = fStack_98 + *(float *)(iVar4 + 0x30);
                  fStack_70 = fStack_94 + *(float *)(iVar4 + 0x34);
                  fStack_3c = fStack_78;
                  fStack_38 = fStack_74;
                  fStack_34 = fStack_70;
                  FUN_004cbf50(&fStack_3c,pfVar1,iVar3 + 0x6e4);
                }
                iVar6 = iVar6 + 1;
              } while (iVar6 < iStack_a0);
            }
          }
        }
        fStack_4 = *(float *)(iVar4 + 0x40) - fStack_88;
        fStack_84 = (*(float *)(iVar4 + 0x38) - fStack_90) * _DAT_0059ed18;
        fStack_80 = (*(float *)(iVar4 + 0x3c) - fStack_8c) * _DAT_0059ed18;
        fStack_7c = fStack_4 * _DAT_0059ed18;
        fStack_24 = fStack_84;
        fStack_20 = fStack_80;
        fStack_1c = fStack_7c;
        FUN_004cc500(iVar4,&fStack_24);
      }
      iStack_a8 = iStack_a8 + 1;
    } while (iStack_a8 < *(int *)(param_1 + 100));
  }
  return;
}
```

---

### Source: 0x00486ac0__FUN_00486ac0.c

```c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00486ac0(int *param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int **ppiVar6;
  int **ppiVar7;
  int unaff_EBX;
  int iVar8;
  int unaff_EBP;
  int *piVar9;
  int unaff_ESI;
  int unaff_EDI;
  undefined4 *******pppppppuVar10;
  undefined4 *******pppppppuVar11;
  int iVar12;
  int iVar13;
  int *piVar14;
  undefined1 auStack_5c [3];
  char cStack_59;
  int iStack_58;
  int iStack_54;
  int *piStack_50;
  undefined4 ******ppppppuStack_4c;
  int **ppiStack_48;
  int iStack_44;
  float fStack_40;
  int iStack_3c;
  float fStack_38;
  int iStack_34;
  undefined1 auStack_30 [4];
  undefined1 auStack_2c [4];
  int **ppiStack_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  int iStack_8;
  undefined4 uStack_4;
  
  if ((char)param_1[0x1b] != '\0') {
    (**(code **)(*param_1 + 0xa0))();
    *(undefined1 *)(param_1 + 0x1b) = 0;
  }
  ppiStack_48 = (int **)FUN_00495150();
  auStack_5c = (undefined1  [3])CONCAT12(0,auStack_5c._0_2_);
  if (*(int *)(param_1[0x10] + 0x38) == 2) {
    ppiStack_48 = (int **)FUN_00495110();
    auStack_5c = (undefined1  [3])CONCAT12(1,auStack_5c._0_2_);
  }
  uStack_4 = FUN_00486830();
  iVar2 = FUN_00486830();
  if ((iVar2 == 0) && (auStack_5c[2] == '\0')) {
    return 0xffffffff;
  }
  if (*(char *)((int)param_1 + 0x65) == '\0') {
    return 0;
  }
  cVar1 = (**(code **)(*param_1 + 0x14))();
  _auStack_5c = CONCAT13(cVar1,auStack_5c);
  if (cVar1 != '\0') {
    (**(code **)(*param_1 + 8))(auStack_30,auStack_2c);
  }
  (**(code **)(*param_1 + 0xc))();
  piVar3 = (int *)FUN_00486460(param_1[0x21]);
  iVar2 = param_1[0x22];
  if (0 < iVar2) {
    do {
      if (piVar3 != (int *)0x0) {
        piVar3 = (int *)piVar3[10];
      }
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  if (piVar3 != (int *)0x0) {
    iStack_58 = param_1[3];
    iStack_54 = param_1[1];
    iStack_34 = piVar3[2];
    iStack_8 = *piVar3;
    iVar2 = *(int *)(piVar3[8] + 0xc);
    iVar12 = piVar3[1] - iStack_8;
    if (*(int *)(iVar2 + 0x1c) < piVar3[1] - iStack_8) {
      iVar12 = *(int *)(iVar2 + 0x1c);
    }
    iVar8 = piVar3[3] - iStack_34;
    if (*(int *)(iVar2 + 0x20) < piVar3[3] - iStack_34) {
      iVar8 = *(int *)(iVar2 + 0x20);
    }
    iStack_44 = iVar8;
    iStack_3c = iVar12;
    if (auStack_5c[2] == '\0') {
      FUN_00494a30(iVar2,iStack_8,iStack_34,ppiStack_48,iStack_58,iStack_54,iVar12,iVar8,0,0);
      (**(code **)(*param_1 + 0x10))(iStack_54,iVar8 + iStack_54,iStack_58,iVar12 + iStack_58);
    }
    else {
      FUN_00495120(&iStack_20,&iStack_1c);
      fStack_38 = (float)iStack_20 * _DAT_005a68ec;
      fStack_40 = (float)iStack_1c * _DAT_005a68e8;
      iStack_54 = __ftol();
      iStack_58 = __ftol();
      (**(code **)(*param_1 + 0x88))(&uStack_c,&uStack_10,&uStack_14,&uStack_18);
      uVar4 = __ftol(uStack_c,uStack_10,uStack_14,uStack_18);
      uVar5 = __ftol(uVar4);
      FUN_00494a70(*(undefined4 *)(piVar3[8] + 0xc),iStack_8,iStack_34,iVar12,iVar8,ppiStack_48,
                   iStack_58,iStack_54,uVar5,uVar4,uStack_c,uStack_10,uStack_14,uStack_18);
    }
  }
  pppppppuVar10 = &ppppppuStack_4c;
  piVar3 = &iStack_58;
  ppiVar6 = &piStack_50;
  piVar14 = &iStack_54;
  piStack_50 = (int *)0x0;
  ppppppuStack_4c = (undefined4 *******)0x0;
  iStack_54 = 600;
  iStack_58 = 800;
  (**(code **)(*param_1 + 0x34))();
  if ((unaff_ESI != unaff_EBX && -1 < unaff_ESI - unaff_EBX) &&
     (_auStack_5c != unaff_EBP && -1 < _auStack_5c - unaff_EBP)) {
    (**(code **)(*param_1 + 0x10))(unaff_EBX,unaff_ESI,unaff_EBP,_auStack_5c);
  }
  (**(code **)(*param_1 + 8))(&stack0xffffff9c,&stack0xffffffa0,&stack0xffffff98,auStack_5c);
  iVar2 = unaff_EDI;
  ppiVar7 = ppiVar6;
  piVar9 = piVar3;
  pppppppuVar11 = pppppppuVar10;
  if (((char)((uint)piVar14 >> 0x18) != '\0') &&
     (cVar1 = (**(code **)(*param_1 + 0x14))(), iVar2 = iStack_44, ppiVar7 = ppiStack_48,
     piVar9 = piStack_50, pppppppuVar11 = (undefined4 *******)ppppppuStack_4c, cVar1 != '\0')) {
    if ((int)piStack_50 <= (int)piVar3) {
      piVar3 = piStack_50;
    }
    if ((int)pppppppuVar10 <= (int)ppppppuStack_4c) {
      pppppppuVar10 = (undefined4 *******)ppppppuStack_4c;
    }
    if ((int)ppiStack_48 <= (int)ppiVar6) {
      ppiVar6 = ppiStack_48;
    }
    iVar2 = unaff_EDI;
    ppiVar7 = ppiVar6;
    piVar9 = piVar3;
    pppppppuVar11 = pppppppuVar10;
    if (unaff_EDI <= iStack_44) {
      iVar2 = iStack_44;
    }
  }
  if ((char)((uint)piVar14 >> 0x10) != '\0') {
    return 0;
  }
  iVar2 = iVar2 - (int)ppiVar7;
  iVar12 = (int)pppppppuVar11 - (int)piVar9;
  ppiStack_28 = ppiVar7;
  if (iStack_24 == 1) {
    piVar3 = piVar9;
    iVar8 = iVar2;
    iVar13 = iVar12;
    FUN_00490920(ppiVar7,piVar9,iVar2,iVar12);
    FUN_004918d0(ppiVar7,piVar3,iVar8,iVar13);
  }
  else if ((iStack_24 < 2) || (3 < iStack_24)) goto LAB_00486e5c;
  ppiVar6 = ppiStack_28;
  FUN_00490920(ppiStack_28,piVar9,iVar2,iVar12);
  FUN_00491960(ppiVar6,piVar9,iVar2,iVar12);
LAB_00486e5c:
  (**(code **)(*param_1 + 0x2c))(0);
  return 0;
}
```

---

### Source: 0x0046dd30__FUN_0046dd30.c

```c

undefined4 __fastcall FUN_0046dd30(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined1 auStack_84 [132];
  
  iVar2 = (**(code **)(**(int **)(param_1 + 0x40) + 0x1c))(0x22);
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  iVar2 = FUN_00489940();
  if (iVar2 < 0) {
    return 0xffffffff;
  }
  iVar2 = FUN_00489950();
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  uVar3 = FUN_00587ece(iVar2);
  FUN_00461550();
  cVar1 = FUN_00462010(uVar3,auStack_84,0,0,&stack0xffffff7b);
  if ((cVar1 != '\0') && (iVar2 = FUN_004615f0(2), iVar2 != 0)) {
    iVar2 = -1;
    pcVar4 = &DAT_007cd850;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    if (iVar2 == -2) {
      FUN_00497940(s_Multi_Client_Password_Entry_005c6c70,0xffffffff);
      FUN_004988d0(s_Client_Password_Entry_005c6c58);
      goto LAB_0046ddfb;
    }
  }
  cVar1 = FUN_00462c00(uVar3,&DAT_007cd850);
  if (cVar1 != '\0') {
    *(undefined4 *)(param_1 + 0xe4) = 0x40800000;
  }
LAB_0046ddfb:
  FUN_004b0170();
  return 0xffffffff;
}
```

---

### Source: 0x004d99e0__FUN_004d99e0.c

```c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_004d99e0(int param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  undefined4 uStack_94;
  int iStack_90;
  char *pcStack_8c;
  char acStack_88 [8];
  char acStack_80 [127];
  undefined1 uStack_1;
  
  if (*(float *)(param_1 + 0x10) < DAT_0059e440) {
    return 1;
  }
  pcVar5 = (char *)0x0;
  *(float *)(param_1 + 0x10) = *(float *)(param_1 + 0x10) - (float)_DAT_008afe98;
  pcStack_8c = (char *)0x0;
  iVar2 = FUN_004c5840(0);
  if (iVar2 != 0) {
    iVar2 = FUN_005679c0(PTR_s_VenueName_005d4af8);
    if (iVar2 != 0) {
      pcVar5 = (char *)FUN_00567970();
    }
    iVar2 = FUN_005679c0(PTR_s_TrackName_005d4afc);
    if (iVar2 != 0) {
      pcStack_8c = (char *)FUN_00567970();
    }
    if (pcVar5 != (char *)0x0) {
      iVar2 = FUN_00423a00(pcVar5,&DAT_005ec4cc);
      if (iVar2 != 0) {
        iVar2 = (int)&DAT_005ec4cc - (int)pcVar5;
        do {
          cVar1 = *pcVar5;
          pcVar5[iVar2] = cVar1;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
      }
      _strncpy(acStack_80,&DAT_005ec4cc,0x7f);
      uStack_94 = 0x280;
      uStack_1 = 0;
      FUN_004d7e40(acStack_80,0x280,0x332,0xffffff,2,0,0x3f800000,0x3f800000);
    }
  }
  FUN_0058815f(acStack_88,&DAT_005ccef0,(int)DAT_005d4aec);
  iVar2 = 0;
  do {
    cVar1 = (&DAT_005ea438)[iVar2];
    acStack_80[iVar2] = cVar1;
    iVar2 = iVar2 + 1;
  } while (cVar1 != '\0');
  iStack_90 = 0x10;
  do {
    uVar3 = 0xffffffff;
    pcVar5 = acStack_88;
    do {
      pcVar7 = pcVar5;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar7 = pcVar5 + 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar7;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    iVar2 = -1;
    pcVar5 = acStack_80;
    do {
      pcVar6 = pcVar5;
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      pcVar6 = pcVar5 + 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar6;
    } while (cVar1 != '\0');
    pcVar5 = pcVar7 + -uVar3;
    pcVar7 = pcVar6 + -1;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      pcVar7 = pcVar7 + 4;
    }
    iStack_90 = iStack_90 + -1;
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar7 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      pcVar7 = pcVar7 + 1;
    }
    if (iStack_90 == 0) {
      FUN_004d7e40(acStack_80,uStack_94,0x35a,0xffffff,2,3,0x3f800000,0x3f800000);
      if (pcStack_8c != (char *)0x0) {
        iVar2 = FUN_00423a00(pcStack_8c,&DAT_005ec4cc);
        if (iVar2 != 0) {
          iVar2 = (int)&DAT_005ec4cc - (int)pcStack_8c;
          do {
            cVar1 = *pcStack_8c;
            pcStack_8c[iVar2] = cVar1;
            pcStack_8c = pcStack_8c + 1;
          } while (cVar1 != '\0');
        }
        _strncpy(acStack_80,&DAT_005ec4cc,0x7f);
        uStack_1 = 0;
        FUN_004d7e40(acStack_80,0x280,0x382,0xffffff,2,0,0x3f800000,0x3f800000);
      }
      return 0;
    }
  } while( true );
}
```

---

### Source: 0x0050d0c2__FUN_0050d0c2.c

```c

void FUN_0050d0c2(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  int iVar32;
  
  fVar3 = param_3[4];
  fVar1 = *param_3;
  fVar2 = param_3[1];
  fVar4 = param_3[5];
  fVar5 = param_3[8];
  fVar6 = param_3[9];
  fVar7 = param_3[0xc];
  fVar19 = fVar4 * fVar1 - fVar3 * fVar2;
  fVar8 = param_3[0xd];
  fVar9 = param_3[0xe];
  fVar10 = param_3[0xf];
  fVar18 = fVar6 * fVar1 - fVar5 * fVar2;
  fVar17 = fVar8 * fVar1 - fVar7 * fVar2;
  fVar20 = fVar6 * fVar3 - fVar5 * fVar4;
  fVar21 = fVar8 * fVar3 - fVar7 * fVar4;
  fVar22 = fVar8 * fVar5 - fVar7 * fVar6;
  fVar1 = param_3[2];
  fVar2 = param_3[3];
  fVar3 = param_3[6];
  fVar4 = param_3[7];
  fVar5 = param_3[10];
  fVar6 = param_3[0xb];
  fVar31 = fVar1 * fVar4 - fVar3 * fVar2;
  fVar30 = fVar1 * fVar6 - fVar5 * fVar2;
  fVar23 = fVar1 * fVar10 - fVar9 * fVar2;
  fVar11 = *param_3;
  fVar12 = param_3[4];
  fVar13 = param_3[8];
  fVar28 = fVar3 * fVar6 - fVar5 * fVar4;
  fVar14 = param_3[9];
  fVar29 = fVar3 * fVar10 - fVar9 * fVar4;
  fVar15 = param_3[0xc];
  fVar26 = fVar5 * fVar10 - fVar9 * fVar6;
  fVar7 = param_3[1];
  fVar8 = param_3[5];
  fVar16 = param_3[0xd];
  fVar27 = (fVar30 * fVar8 - fVar31 * fVar14) - fVar28 * fVar7;
  fVar24 = fVar31 * fVar16 + (fVar29 * fVar7 - fVar23 * fVar8);
  fVar25 = (fVar23 * fVar14 - fVar30 * fVar16) - fVar26 * fVar7;
  fVar7 = fVar28 * fVar16 + (fVar26 * fVar8 - fVar29 * fVar14);
  fVar8 = fVar7 * fVar11 + fVar25 * fVar12 + fVar24 * fVar13 + fVar27 * fVar15;
  if (param_2 != (float *)0x0) {
    *param_2 = fVar8;
  }
  fVar8 = 1.0 / fVar8;
  iVar32 = FUN_0058a88f((double)fVar8);
  if (iVar32 != 0) {
    *param_1 = fVar7 * fVar8;
    param_1[1] = fVar25 * fVar8;
    param_1[2] = fVar24 * fVar8;
    param_1[3] = fVar27 * fVar8;
    param_1[4] = ((fVar29 * fVar13 - fVar28 * fVar15) - fVar26 * fVar12) * fVar8;
    param_1[5] = (fVar30 * fVar15 + (fVar11 * fVar26 - fVar23 * fVar13)) * fVar8;
    param_1[6] = ((fVar23 * fVar12 - fVar31 * fVar15) - fVar29 * fVar11) * fVar8;
    param_1[7] = (fVar31 * fVar13 + (fVar28 * fVar11 - fVar30 * fVar12)) * fVar8;
    param_1[8] = (fVar20 * fVar10 + (fVar22 * fVar4 - fVar21 * fVar6)) * fVar8;
    param_1[9] = ((fVar17 * fVar6 - fVar18 * fVar10) - fVar22 * fVar2) * fVar8;
    param_1[10] = (fVar19 * fVar10 + (fVar21 * fVar2 - fVar17 * fVar4)) * fVar8;
    param_1[0xb] = ((fVar18 * fVar4 - fVar19 * fVar6) - fVar20 * fVar2) * fVar8;
    param_1[0xc] = ((fVar5 * fVar21 - fVar9 * fVar20) - fVar3 * fVar22) * fVar8;
    param_1[0xd] = (fVar9 * fVar18 + (fVar1 * fVar22 - fVar5 * fVar17)) * fVar8;
    param_1[0xe] = ((fVar3 * fVar17 - fVar9 * fVar19) - fVar1 * fVar21) * fVar8;
    param_1[0xf] = (fVar5 * fVar19 + (fVar1 * fVar20 - fVar3 * fVar18)) * fVar8;
  }
  return;
}
```

---

### Source: 0x00477830__FUN_00477830.c

```c

undefined4 __fastcall FUN_00477830(int param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  void *pvVar7;
  int iVar8;
  char *pcVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  char *pcVar13;
  char *pcVar14;
  char *pcVar15;
  undefined4 *puVar16;
  int iStack_150;
  char cStack_140;
  undefined4 uStack_13f;
  char acStack_101 [2];
  undefined4 uStack_ff;
  
  FUN_0048ebd0();
  piVar3 = *(int **)(param_1 + 0xf0);
  while (piVar3 != (int *)0x0) {
    piVar2 = (int *)piVar3[1];
    if (((char)piVar3[3] != '\0') && ((undefined4 *)*piVar3 != (undefined4 *)0x0)) {
      (*(code *)**(undefined4 **)*piVar3)(1);
    }
    FUN_00587bcf(piVar3);
    piVar3 = piVar2;
  }
  *(undefined4 *)(param_1 + 0xf0) = 0;
  *(undefined4 *)(param_1 + 0xf4) = 0;
  *(undefined4 *)(param_1 + 0xf8) = 0;
  *(undefined4 *)(param_1 + 0xfc) = 0;
  FUN_004c62c0();
  uVar4 = FUN_005681f0(s_Game_Filter_005c7130);
  FUN_004c6330(uVar4);
  iVar5 = FUN_005871f0();
  iStack_150 = 0;
  if (0 < iVar5) {
    do {
      iVar6 = FUN_004c6780(iStack_150);
      if (((iVar6 != 0) && (pvVar7 = operator_new(0x48), pvVar7 != (void *)0x0)) &&
         (iVar8 = FUN_004761c0(), iVar8 != 0)) {
        acStack_101[1] = DAT_005ea438;
        puVar16 = &uStack_ff;
        for (iVar10 = 0x3f; iVar10 != 0; iVar10 = iVar10 + -1) {
          *puVar16 = 0;
          puVar16 = puVar16 + 1;
        }
        *(undefined2 *)puVar16 = 0;
        *(undefined1 *)((int)puVar16 + 2) = 0;
        pcVar9 = (char *)(iVar6 + 4);
        iVar10 = 1 - (int)pcVar9;
        do {
          cVar1 = *pcVar9;
          pcVar9[(int)(acStack_101 + iVar10)] = cVar1;
          pcVar9 = pcVar9 + 1;
        } while (cVar1 != '\0');
        pcVar9 = acStack_101;
        uVar11 = 0xffffffff;
        do {
          pcVar9 = pcVar9 + 1;
          if (uVar11 == 0) break;
          uVar11 = uVar11 - 1;
        } while (*pcVar9 != '\0');
        if ((0 < (int)(~uVar11 - 1)) && (pcVar9 = acStack_101 + ~uVar11, acStack_101 + 1 <= pcVar9))
        {
          do {
            if (*pcVar9 == '\\') break;
            *pcVar9 = '\0';
            if (acStack_101 + 1 < pcVar9) {
              pcVar9 = pcVar9 + -1;
            }
          } while (acStack_101 + 1 <= pcVar9);
        }
        uVar11 = 0xffffffff;
        pcVar13 = (char *)(iVar6 + 0x104);
        pcVar9 = pcVar13;
        do {
          pcVar15 = pcVar9;
          if (uVar11 == 0) break;
          uVar11 = uVar11 - 1;
          pcVar15 = pcVar9 + 1;
          cVar1 = *pcVar9;
          pcVar9 = pcVar15;
        } while (cVar1 != '\0');
        uVar11 = ~uVar11;
        iVar10 = -1;
        pcVar9 = acStack_101 + 1;
        do {
          pcVar14 = pcVar9;
          if (iVar10 == 0) break;
          iVar10 = iVar10 + -1;
          pcVar14 = pcVar9 + 1;
          cVar1 = *pcVar9;
          pcVar9 = pcVar14;
        } while (cVar1 != '\0');
        pcVar9 = pcVar15 + -uVar11;
        pcVar15 = pcVar14 + -1;
        for (uVar12 = uVar11 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
          *(undefined4 *)pcVar15 = *(undefined4 *)pcVar9;
          pcVar9 = pcVar9 + 4;
          pcVar15 = pcVar15 + 4;
        }
        for (uVar11 = uVar11 & 3; uVar11 != 0; uVar11 = uVar11 - 1) {
          *pcVar15 = *pcVar9;
          pcVar9 = pcVar9 + 1;
          pcVar15 = pcVar15 + 1;
        }
        iVar10 = -1;
        pcVar9 = acStack_101 + 1;
        do {
          pcVar15 = pcVar9;
          if (iVar10 == 0) break;
          iVar10 = iVar10 + -1;
          pcVar15 = pcVar9 + 1;
          cVar1 = *pcVar9;
          pcVar9 = pcVar15;
        } while (cVar1 != '\0');
        *(undefined4 *)(pcVar15 + -1) = s_Track_bmp_005c7150._0_4_;
        *(undefined4 *)(pcVar15 + 3) = s_Track_bmp_005c7150._4_4_;
        *(undefined2 *)(pcVar15 + 7) = s_Track_bmp_005c7150._8_2_;
        iVar10 = FUN_00497ad0(acStack_101 + 1,0);
        if ((iVar10 != 0) || (iVar10 = FUN_00497ad0(s_DFCarIcon_bmp_005c6a04,0), iVar10 != 0)) {
          FUN_0048fc80(iVar10);
        }
        FUN_004c55b0(pcVar13);
        cStack_140 = DAT_005ea438;
        puVar16 = &uStack_13f;
        for (iVar10 = 0xf; iVar10 != 0; iVar10 = iVar10 + -1) {
          *puVar16 = 0;
          puVar16 = puVar16 + 1;
        }
        *(undefined2 *)puVar16 = 0;
        *(undefined1 *)((int)puVar16 + 2) = 0;
        FUN_004c5920(&cStack_140,0x3f);
        FUN_00566650(&cStack_140);
        FUN_00566650(pcVar13);
        *(int *)(iVar8 + 0x3c) = iVar6;
        FUN_0048f5d0(iVar8,1);
      }
      iStack_150 = iStack_150 + 1;
    } while (iStack_150 < iVar5);
  }
  FUN_00477ba0();
  FUN_0048f640();
  return 0;
}
```

---

### Source: 0x0046d6d0__FUN_0046d6d0.c

```c

undefined4 FUN_0046d6d0(void)

{
  int iVar1;
  undefined1 auStack_80 [128];
  
  if (DAT_005eb10c != (int *)0x0) {
    (**(code **)(*DAT_005eb10c + 0xc))();
  }
  FUN_004186a0();
  switch(DAT_007d0410) {
  case 1:
  case 2:
  case 3:
    FUN_00486aa0(s_SELECTCIRCUITPAGE_005c65ec);
    return 0xffffffff;
  case 4:
    FUN_004a0630();
    FUN_00486aa0(s_CH_RESUME_005c6bf8);
    return 0xffffffff;
  case 5:
    break;
  default:
    return 0;
  }
  iVar1 = FUN_00461cd0();
  if (iVar1 == 3) {
    FUN_00497940(s_MPCLIENTGRID_005c5f5c,0xffffffff);
    FUN_00461550();
    FUN_004627c0(auStack_80,0);
    FUN_00461900();
    iVar1 = (**(code **)(*DAT_007cd8c0 + 0x1c))(0x18);
    if (iVar1 != 0) {
      FUN_00477640();
      FUN_00477680();
    }
    DAT_005cc9e8 = 1;
    FUN_004b0170();
  }
  return 0xffffffff;
}
```

---

### Source: 0x005805c0__FUN_005805c0.c

```c

int __fastcall FUN_005805c0(int param_1)

{
  int *piVar1;
  char cVar2;
  DWORD DVar3;
  int iVar4;
  int iVar5;
  int iStack_8;
  
  iVar4 = param_1 + 0xb74;
  if ((*(HANDLE *)(param_1 + 0xb94) == (HANDLE)0x0) ||
     ((DVar3 = WaitForSingleObject(*(HANDLE *)(param_1 + 0xb94),*(DWORD *)(param_1 + 0xb98)),
      DVar3 != 0 && (DVar3 != 0x80)))) {
    iVar4 = 0;
  }
  iStack_8 = 0;
  FUN_004ba780();
  piVar1 = *(int **)(iVar4 + 0x18);
  if (piVar1 != (int *)0x0) {
    iStack_8 = *piVar1;
    *(undefined1 *)(piVar1 + 2) = 0;
    cVar2 = FUN_00583430(iStack_8,1);
    if (cVar2 == '\0') {
      iStack_8 = 0;
    }
  }
  if (iStack_8 == 0) {
    FUN_00582780();
    iStack_8 = FUN_00582b10();
  }
  if (*(HANDLE *)(param_1 + 0xb94) != (HANDLE)0x0) {
    ReleaseMutex(*(HANDLE *)(param_1 + 0xb94));
  }
  iVar4 = param_1 + 0xb48;
  if ((*(HANDLE *)(param_1 + 0xb68) == (HANDLE)0x0) ||
     ((DVar3 = WaitForSingleObject(*(HANDLE *)(param_1 + 0xb68),*(DWORD *)(param_1 + 0xb6c)),
      DVar3 != 0 && (DVar3 != 0x80)))) {
    iVar4 = 0;
  }
  piVar1 = *(int **)(iVar4 + 0x10);
  iVar5 = 0;
  *(int **)(iVar4 + 0x18) = piVar1;
  if (piVar1 != (int *)0x0) {
    iVar5 = *piVar1;
    *(undefined1 *)(piVar1 + 2) = 0;
    cVar2 = FUN_005832e0(iVar5,1);
    if (cVar2 == '\0') {
      iVar5 = 0;
    }
  }
  if (iVar5 == 0) {
    FUN_005823c0();
    FUN_004ba780();
    piVar1 = *(int **)(iVar4 + 0x18);
    if (piVar1 != (int *)0x0) {
      iVar5 = *piVar1;
      *(undefined1 *)(piVar1 + 2) = 0;
      cVar2 = FUN_005832e0(iVar5,1);
      if (cVar2 == '\0') {
        iVar5 = 0;
      }
    }
  }
  *(int *)(iStack_8 + 0x48) = iVar5;
  if (*(HANDLE *)(param_1 + 0xb68) != (HANDLE)0x0) {
    ReleaseMutex(*(HANDLE *)(param_1 + 0xb68));
  }
  return iStack_8;
}
```

---

### Source: 0x0050e3e0__FUN_0050e3e0.c

```c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0050e3e0(float *param_1,float *param_2)

{
  float fVar1;
  int iVar2;
  
  fVar1 = param_2[2] * param_2[2] + param_2[1] * param_2[1] + *param_2 * *param_2;
  iVar2 = FUN_0050c042(fVar1,0x3f800000);
  if (iVar2 == 0) {
    if (fVar1 <= (float)PTR_DAT_005ade40) {
      *param_1 = 0.0;
      param_1[1] = 0.0;
      param_1[2] = 0.0;
      fVar1 = 0.0;
    }
    else {
      fVar1 = _DAT_0059e43c / SQRT(fVar1);
      *param_1 = fVar1 * *param_2;
      param_1[1] = fVar1 * param_2[1];
      param_1[2] = fVar1 * param_2[2];
      fVar1 = fVar1 * param_2[3];
    }
    param_1[3] = fVar1;
  }
  else if (param_1 != param_2) {
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    param_1[2] = param_2[2];
    param_1[3] = param_2[3];
  }
  return;
}
```

---

### Source: 0x00407520__FUN_00407520.c

```c

/* WARNING: Removing unreachable block (ram,0x004076be) */

uint __thiscall FUN_00407520(int param_1,int *param_2,int param_3)

{
  bool bVar1;
  uint in_EAX;
  int iVar2;
  void *pvVar3;
  int *piVar4;
  int *piVar5;
  byte bStack_9;
  
  bStack_9 = 0;
  if (param_2 == (int *)0x0) {
    return in_EAX & 0xffffff00;
  }
  bVar1 = false;
  if (*param_2 != 0) {
    FUN_00566650(*param_2);
  }
  if (param_2[1] != 0) {
    FUN_005665b0(param_2[1]);
  }
  piVar4 = *(int **)(param_1 + 0x38);
  *(int **)(param_1 + 0x40) = piVar4;
  if ((piVar4 != (int *)0x0) && (piVar4 = (int *)*piVar4, piVar4 != (int *)0x0)) {
    while (*piVar4 != param_3) {
      if (*(int *)(param_1 + 0x40) != 0) {
        *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(*(int *)(param_1 + 0x40) + 4);
      }
      if ((*(undefined4 **)(param_1 + 0x40) == (undefined4 *)0x0) ||
         (piVar4 = (int *)**(undefined4 **)(param_1 + 0x40), piVar4 == (int *)0x0))
      goto LAB_004075a7;
    }
    bVar1 = true;
  }
LAB_004075a7:
  iVar2 = FUN_00588410(&DAT_005ea438,&DAT_005ea438);
  if ((((iVar2 != 0) && (!bVar1)) && (pvVar3 = operator_new(0x74), pvVar3 != (void *)0x0)) &&
     (piVar4 = (int *)FUN_004053e0(), piVar4 != (int *)0x0)) {
    iVar2 = FUN_00587db0(&DAT_005ea438,&DAT_005be828);
    piVar4[3] = iVar2;
    if (iVar2 != 0) {
      iVar2 = FUN_004080f0(piVar4);
      if (iVar2 == 0) {
        iVar2 = FUN_0059b758(piVar4[3]);
        piVar4[4] = iVar2;
        *piVar4 = param_3;
        FUN_00566650(&DAT_005ea438);
        piVar5 = operator_new(0xc);
        if (piVar5 == (int *)0x0) {
          piVar5 = (int *)0x0;
        }
        else {
          *piVar5 = (int)piVar4;
          piVar5[1] = 0;
          *(undefined1 *)(piVar5 + 2) = 1;
        }
        if (*(int *)(param_1 + 0x38) == 0) {
          *(int **)(param_1 + 0x38) = piVar5;
          *(int **)(param_1 + 0x40) = piVar5;
          *(int **)(param_1 + 0x3c) = piVar5;
          *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x44) + 1;
          bStack_9 = 1;
        }
        else {
          *(int **)(*(int *)(param_1 + 0x3c) + 4) = piVar5;
          *(int **)(param_1 + 0x3c) = piVar5;
          *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x44) + 1;
          bStack_9 = 1;
        }
        goto LAB_004076b5;
      }
      FUN_00587d02(piVar4[3]);
      piVar4[3] = 0;
    }
    FUN_00405410();
    FUN_00587bcf(piVar4);
  }
LAB_004076b5:
  return (uint)bStack_9;
}
```

---

### Source: 0x0046c8b0__FUN_0046c8b0.c

```c

undefined4 __fastcall FUN_0046c8b0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_8;
  undefined1 auStack_4 [4];
  
  FUN_00498880(auStack_4,&uStack_8);
  iVar1 = FUN_00489f40(uStack_8,1);
  if (-1 < iVar1) {
    uVar2 = FUN_0046c750(*(undefined1 *)(param_1 + 0x174),iVar1);
    FUN_0046c7b0(*(char *)(param_1 + 0x174) == '\0',uVar2,0xffffffff);
  }
  return 0;
}
```

---

### Source: 0x0050cbb6__FUN_0050cbb6.c

```c

void FUN_0050cbb6(float *param_1,float *param_2,float *param_3)

{
  int iVar1;
  float *pfVar2;
  float afStack_44 [16];
  
  if ((param_1 == param_2) || (pfVar2 = param_1, param_1 == param_3)) {
    pfVar2 = afStack_44;
  }
  *pfVar2 = param_3[4] * param_2[1] +
            param_2[2] * param_3[8] + *param_2 * *param_3 + param_2[3] * param_3[0xc];
  pfVar2[1] = param_3[1] * *param_2 +
              param_2[2] * param_3[9] + param_2[3] * param_3[0xd] + param_2[1] * param_3[5];
  pfVar2[2] = param_3[6] * param_2[1] +
              param_2[2] * param_3[10] + param_3[2] * *param_2 + param_2[3] * param_3[0xe];
  pfVar2[3] = param_3[7] * param_2[1] +
              *param_2 * param_3[3] + param_3[0xb] * param_2[2] + param_2[3] * param_3[0xf];
  pfVar2[4] = param_2[6] * param_3[8] +
              param_3[4] * param_2[5] + param_2[4] * *param_3 + param_2[7] * param_3[0xc];
  pfVar2[5] = param_3[1] * param_2[4] +
              param_3[5] * param_2[5] + param_2[7] * param_3[0xd] + param_2[6] * param_3[9];
  pfVar2[6] = param_2[6] * param_3[10] +
              param_3[2] * param_2[4] + param_2[7] * param_3[0xe] + param_3[6] * param_2[5];
  pfVar2[7] = param_2[4] * param_3[3] +
              param_2[6] * param_3[0xb] + param_2[7] * param_3[0xf] + param_3[7] * param_2[5];
  pfVar2[8] = param_2[10] * param_3[8] +
              param_3[4] * param_2[9] + param_2[8] * *param_3 + param_2[0xb] * param_3[0xc];
  pfVar2[9] = param_3[1] * param_2[8] +
              param_3[5] * param_2[9] + param_2[10] * param_3[9] + param_2[0xb] * param_3[0xd];
  pfVar2[10] = param_2[10] * param_3[10] +
               param_2[0xb] * param_3[0xe] + param_3[2] * param_2[8] + param_3[6] * param_2[9];
  pfVar2[0xb] = param_2[8] * param_3[3] +
                param_3[7] * param_2[9] + param_2[10] * param_3[0xb] + param_2[0xb] * param_3[0xf];
  pfVar2[0xc] = param_2[0xe] * param_3[8] +
                param_3[4] * param_2[0xd] + param_2[0xc] * *param_3 + param_2[0xf] * param_3[0xc];
  pfVar2[0xd] = param_3[1] * param_2[0xc] +
                param_3[5] * param_2[0xd] + param_2[0xe] * param_3[9] + param_2[0xf] * param_3[0xd];
  pfVar2[0xe] = param_2[0xe] * param_3[10] +
                param_2[0xf] * param_3[0xe] + param_3[2] * param_2[0xc] + param_3[6] * param_2[0xd];
  pfVar2[0xf] = param_2[0xc] * param_3[3] +
                param_3[7] * param_2[0xd] +
                param_2[0xe] * param_3[0xb] + param_2[0xf] * param_3[0xf];
  if (pfVar2 != param_1) {
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *param_1 = *pfVar2;
      pfVar2 = pfVar2 + 1;
      param_1 = param_1 + 1;
    }
  }
  return;
}
```

---

### Source: 0x0048b9c0__FUN_0048b9c0.c

```c

undefined4 __thiscall
FUN_0048b9c0(int *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
            undefined4 *param_5)

{
  char cVar1;
  undefined1 *puVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  char *pcVar11;
  undefined4 *puVar12;
  char *pcVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  int iStack_10c;
  undefined4 uStack_108;
  undefined1 auStack_104 [4];
  char cStack_100;
  undefined4 uStack_ff;
  undefined1 uStack_2;
  
  iVar10 = 0;
  if (param_1[0x32] != 0) {
    puVar2 = *(undefined1 **)(param_1[0x32] + 0x40);
    if (puVar2 == (undefined1 *)0x0) {
      puVar2 = &DAT_005ea438;
    }
    FUN_00498560(puVar2);
  }
  FUN_004983b0(&DAT_005cc218,&iStack_10c,auStack_104,1);
  piVar3 = (int *)FUN_00486460(0);
  if (piVar3 != (int *)0x0) {
    iVar7 = param_1[1];
    iVar5 = param_1[3];
    uVar15 = 0;
    uVar14 = 0;
    iVar8 = piVar3[3] - piVar3[2];
    iVar9 = piVar3[1] - *piVar3;
    uVar4 = FUN_00495150(iVar5,iVar7,iVar9,iVar8,0,0);
    FUN_00494a30(*(undefined4 *)(piVar3[8] + 0xc),*piVar3,piVar3[2],uVar4,iVar5,iVar7,iVar9,iVar8,
                 uVar14,uVar15);
  }
  pcVar11 = (char *)param_1[0xbc];
  cStack_100 = DAT_005ea438;
  puVar12 = &uStack_ff;
  for (iVar7 = 0x3f; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar12 = 0;
    puVar12 = puVar12 + 1;
  }
  *(undefined2 *)puVar12 = 0;
  *(undefined1 *)((int)puVar12 + 2) = 0;
  if (*(char *)((int)param_1 + 0xe2) == '\0') {
    _strncpy(&cStack_100,pcVar11,0xff);
  }
  else {
    iVar7 = 0;
    do {
      pcVar13 = &cStack_100 + iVar7;
      if (pcVar13[(int)pcVar11 - (int)&cStack_100] == '\0') break;
      iVar7 = iVar7 + 1;
      *pcVar13 = '*';
    } while (iVar7 < 0x100);
  }
  uStack_2 = 0;
  if (((char)param_1[0x38] != '\0') && (*(char *)((int)param_1 + 0xe1) != '\0')) {
    iVar7 = -1;
    pcVar11 = &cStack_100;
    do {
      pcVar13 = pcVar11;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      pcVar13 = pcVar11 + 1;
      cVar1 = *pcVar11;
      pcVar11 = pcVar13;
    } while (cVar1 != '\0');
    *(undefined2 *)(pcVar13 + -1) = DAT_005cc214;
  }
  uStack_108 = 0;
  iStack_10c = 0;
  pcVar11 = &cStack_100;
  FUN_004983b0(&cStack_100,&iStack_10c,&uStack_108,1);
  iVar7 = (**(code **)(*param_1 + 0x20))();
  iVar5 = (**(code **)(*param_1 + 0x18))();
  for (; (iVar7 - iVar5 < iStack_10c && (iVar10 < 0xff)); iVar10 = iVar10 + 1) {
    pcVar11 = pcVar11 + 1;
    FUN_004983b0(pcVar11,&iStack_10c,&uStack_108,1);
  }
  iVar10 = -1;
  pcVar13 = pcVar11;
  do {
    if (iVar10 == 0) break;
    iVar10 = iVar10 + -1;
    cVar1 = *pcVar13;
    pcVar13 = pcVar13 + 1;
  } while (cVar1 != '\0');
  if (iVar10 != -2) {
    uVar16 = 1;
    uVar4 = (**(code **)(*param_1 + 0x20))(1);
    uVar14 = (**(code **)(*param_1 + 0x18))(uVar4);
    uVar15 = (**(code **)(*param_1 + 0x24))(uVar14);
    uVar6 = (**(code **)(*param_1 + 0x1c))(uVar15);
    FUN_004981f0(pcVar11,uVar6,uVar15,uVar14,uVar4,uVar16);
    uVar4 = (**(code **)(*param_1 + 0x1c))();
    *param_2 = uVar4;
    uVar4 = (**(code **)(*param_1 + 0x24))();
    *param_3 = uVar4;
    uVar4 = (**(code **)(*param_1 + 0x18))();
    *param_4 = uVar4;
    uVar4 = (**(code **)(*param_1 + 0x20))();
    *param_5 = uVar4;
  }
  (**(code **)(*param_1 + 0x2c))(0);
  return 0;
}
```

---

### Source: 0x004062b0__FUN_004062b0.c

```c

/* WARNING: Removing unreachable block (ram,0x00406409) */

void __thiscall FUN_004062b0(int *param_1,undefined4 *param_2,int param_3,char param_4)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  byte *pbVar7;
  int *piVar8;
  bool bVar9;
  
  puVar5 = param_2;
  if (((param_2 != (undefined4 *)0x0) && (param_3 < 4)) && (0 < param_3)) {
    if (param_4 == '\0') {
      FUN_00406750();
      param_1 = param_1 + 7;
      iVar3 = 3;
      piVar8 = param_1;
      do {
        FUN_00566650(&DAT_005ea438);
        piVar8[-1] = -1;
        *piVar8 = -1;
        *(undefined1 *)(piVar8 + 1) = 0;
        piVar8 = piVar8 + 5;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      if (0 < param_3) {
        piVar8 = param_2 + 3;
        do {
          puVar4 = (undefined1 *)piVar8[-3];
          if (puVar4 == (undefined1 *)0x0) {
            puVar4 = &DAT_005ea438;
          }
          FUN_00566650(puVar4);
          param_1[-1] = piVar8[-1];
          *param_1 = *piVar8;
          *(char *)(param_1 + 1) = (char)piVar8[1];
          piVar8 = piVar8 + 5;
          param_1 = param_1 + 5;
          param_3 = param_3 + -1;
        } while (param_3 != 0);
      }
      FUN_00406790();
    }
    else {
      _param_4 = 0;
      FUN_00566650(&DAT_005ea438);
      param_2 = (undefined4 *)0x0;
      piVar8 = param_1 + 7;
      do {
        if (param_3 <= _param_4) break;
        pbVar7 = &DAT_005ea438;
        pbVar2 = (byte *)piVar8[-3];
        if (pbVar2 == (byte *)0x0) {
          pbVar2 = &DAT_005ea438;
        }
        do {
          bVar1 = *pbVar2;
          bVar9 = bVar1 < *pbVar7;
          if (bVar1 != *pbVar7) {
LAB_00406374:
            iVar3 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
            goto LAB_00406379;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar2[1];
          bVar9 = bVar1 < pbVar7[1];
          if (bVar1 != pbVar7[1]) goto LAB_00406374;
          pbVar2 = pbVar2 + 2;
          pbVar7 = pbVar7 + 2;
        } while (bVar1 != 0);
        iVar3 = 0;
LAB_00406379:
        puVar6 = puVar5;
        if (((iVar3 == 0) && (piVar8[-1] == -1)) && ((*piVar8 == -1 && ((char)piVar8[1] == '\0'))))
        {
          _param_4 = _param_4 + 1;
          puVar4 = (undefined1 *)*puVar5;
          puVar6 = puVar5 + 5;
          if (puVar4 == (undefined1 *)0x0) {
            puVar4 = &DAT_005ea438;
          }
          FUN_00566650(puVar4);
          piVar8[-1] = puVar5[2];
          *piVar8 = puVar5[3];
          *(undefined1 *)(piVar8 + 1) = *(undefined1 *)(puVar5 + 4);
        }
        param_2 = (undefined4 *)((int)param_2 + 1);
        piVar8 = piVar8 + 5;
        puVar5 = puVar6;
      } while ((int)param_2 < 3);
      if ((0 < _param_4) && (iVar3 = (**(code **)(*param_1 + 8))(), iVar3 == 0)) {
        FUN_00406790();
      }
    }
  }
  return;
}
```

---

### Source: 0x00477cb0__FUN_00477cb0.c

```c

undefined4 __fastcall FUN_00477cb0(int param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  char *pcVar4;
  int iVar5;
  void *pvVar6;
  undefined4 uVar7;
  uint uVar8;
  char *pcVar9;
  char acStack_180 [64];
  char acStack_140 [64];
  undefined1 auStack_100 [256];
  
  FUN_0048ebd0();
  piVar3 = *(int **)(param_1 + 0xf0);
  while (piVar3 != (int *)0x0) {
    piVar2 = (int *)piVar3[1];
    if (((char)piVar3[3] != '\0') && ((undefined4 *)*piVar3 != (undefined4 *)0x0)) {
      (*(code *)**(undefined4 **)*piVar3)(1);
    }
    FUN_00587bcf(piVar3);
    piVar3 = piVar2;
  }
  *(undefined4 *)(param_1 + 0xf0) = 0;
  *(undefined4 *)(param_1 + 0xf4) = 0;
  *(undefined4 *)(param_1 + 0xf8) = 0;
  *(undefined4 *)(param_1 + 0xfc) = 0;
  *(undefined4 *)(param_1 + 0x174) = 0;
  PTR_s_ProfileIcon_DFT_bmp_005c6658 = s_ProfileIcon_DFT_bmp_005c66f8;
  pcVar4 = DAT_005ec3f8;
  if (DAT_005ec3f8 == (char *)0x0) {
    pcVar4 = &DAT_005ea438;
  }
  iVar5 = -(int)pcVar4;
  do {
    cVar1 = *pcVar4;
    pcVar4[(int)(acStack_140 + iVar5)] = cVar1;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  FUN_00565f80(s___BMP_005c715c,1,acStack_140,1);
  FUN_00566380(0);
  pcVar4 = (char *)FUN_005662d0();
  do {
    if (pcVar4 == (char *)0x0) {
      FUN_00565eb0();
      FUN_0048f640();
      return 0;
    }
    uVar8 = 0xffffffff;
    pcVar9 = pcVar4;
    do {
      if (uVar8 == 0) break;
      uVar8 = uVar8 - 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    for (pcVar9 = pcVar4 + (~uVar8 - 1); pcVar4 < pcVar9; pcVar9 = pcVar9 + -1) {
      if (*pcVar9 == '\\') {
        pcVar9 = pcVar9 + 1;
        break;
      }
    }
    pcVar4 = pcVar9;
    do {
      cVar1 = *pcVar4;
      pcVar4[(int)(acStack_180 + -(int)pcVar9)] = cVar1;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    uVar8 = 0xffffffff;
    pcVar4 = acStack_180;
    do {
      if (uVar8 == 0) break;
      uVar8 = uVar8 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    pcVar4 = acStack_180 + (~uVar8 - 1);
    if (acStack_180 < pcVar4) {
      do {
        if (*pcVar4 == '.') {
          *pcVar4 = '\0';
          break;
        }
        pcVar4 = pcVar4 + -1;
      } while (acStack_180 < pcVar4);
    }
    FUN_0058815f(auStack_100,&DAT_005be860,acStack_140,pcVar9);
    iVar5 = FUN_00497ad0(auStack_100,0);
    if (iVar5 == 0) {
      FUN_00497ad0(s_ProfileIcon_DFT_bmp_005c66f8,0);
    }
    else {
      pvVar6 = operator_new(0x3c);
      if (pvVar6 == (void *)0x0) {
        uVar7 = 0;
      }
      else {
        uVar7 = FUN_0048fc50();
      }
      FUN_00566650(auStack_100);
      FUN_0048fc80(iVar5);
      FUN_00566650(acStack_180);
      FUN_0048f5d0(uVar7,1);
    }
    FUN_00565f20();
    pcVar4 = (char *)FUN_005662d0();
  } while( true );
}
```

---

### Source: 0x004d3740__FUN_004d3740.c

```c

undefined4 __fastcall FUN_004d3740(int param_1)

{
  undefined1 auStack_8 [4];
  int iStack_4;
  
  FUN_0054c150(auStack_8,0x800);
  FUN_004bc390(param_1);
  FUN_0054c150(&iStack_4,0x800);
  FUN_00424cd0(iStack_4 + 1,0);
  FUN_0054fae0(*(undefined4 *)(param_1 + 0x14));
  return 0;
}
```

---

### Source: 0x0050c647__FUN_0050c647.c

```c

void FUN_0050c647(void)

{
  FUN_0050fea7(1);
                    /* WARNING: Could not recover jumptable at 0x0050c652. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_005d7804)();
  return;
}
```

---

### Source: 0x004c9840__FUN_004c9840.c

```c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_004c9840(int param_1)

{
  float fVar1;
  undefined4 uVar2;
  float fVar3;
  undefined1 *puVar4;
  int *piVar5;
  int iVar6;
  int unaff_EDI;
  undefined4 uStack_218;
  undefined4 uStack_214;
  float fStack_210;
  undefined4 uStack_20c;
  undefined1 uStack_208;
  undefined1 auStack_200 [512];
  
  piVar5 = DAT_008ac4c4;
  if (DAT_008ac4c4 != (int *)0x0) {
    uStack_218 = 0;
    uStack_214 = 0xffffffff;
    FUN_00566650(&DAT_005ea438);
    fStack_210 = -NAN;
    uStack_20c = 0xffffffff;
    uStack_208 = 0;
    puVar4 = DAT_005ec3e0;
    if (DAT_005ec3e0 == (undefined1 *)0x0) {
      puVar4 = &DAT_005ea438;
    }
    FUN_0058815f(auStack_200,s__s_s_s_005c6784,puVar4,s_Ambient__005d3448,s_pithorn_wav_005d347c);
    FUN_00566650(auStack_200);
    fStack_210 = -NAN;
    uStack_20c = 0xffffffff;
    uStack_208 = 0;
    piVar5 = (int *)(**(code **)(*piVar5 + 0x5c))(&uStack_218,0,1);
    *(int **)(param_1 + 0x1c) = piVar5;
    if (piVar5 != (int *)0x0) {
      iVar6 = (**(code **)(*piVar5 + 0x14))();
      fVar3 = DAT_007cf578;
      uVar2 = _DAT_007cf554;
      if (iVar6 == 0) {
        iVar6 = *(int *)(param_1 + 0x1c);
        fStack_210 = DAT_007cf578;
        fVar1 = _DAT_0059e43c;
        if (_DAT_007cf530 < DAT_0059e440 == (_DAT_007cf530 == DAT_0059e440)) {
          fVar1 = _DAT_0059e43c / _DAT_007cf530;
        }
        *(float *)(iVar6 + 0x1c) = fVar1;
        *(float *)(iVar6 + 0x20) = _DAT_0059e43c - fVar1 * fVar3;
        *(undefined4 *)(iVar6 + 0x24) = uVar2;
      }
      else {
        if (*(undefined4 **)(param_1 + 0x1c) != (undefined4 *)0x0) {
          (**(code **)**(undefined4 **)(param_1 + 0x1c))(1);
        }
        *(undefined4 *)(param_1 + 0x1c) = 0;
      }
    }
    if (unaff_EDI != 0) {
      FUN_00587bcf(unaff_EDI);
    }
  }
  return 0;
}
```

---

### Source: 0x0048e3a0__FUN_0048e3a0.c

```c

undefined4 __fastcall FUN_0048e3a0(int param_1)

{
  int *piVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined4 uVar5;
  
  piVar1 = (int *)(param_1 + 0xe4);
  uVar5 = 0;
  if (*(int *)(param_1 + 0xe4) != 0) {
    FUN_00551f80(*(int *)(param_1 + 0xe4));
  }
  puVar2 = *(undefined1 **)(param_1 + 0xb0);
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  FUN_00566650(puVar2);
  puVar3 = operator_new(0x80);
  *puVar3 = 0;
  puVar2 = DAT_005ec3f0;
  if (DAT_005ec3f0 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  FUN_00566650(puVar2);
  puVar2 = *(undefined1 **)(param_1 + 0xb8);
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  FUN_005665b0(puVar2);
  puVar2 = puVar3;
  if (puVar3 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  iVar4 = FUN_00551f10(piVar1,puVar2,0,0);
  *(undefined4 *)(param_1 + 0xec) = 0;
  *(undefined4 *)(param_1 + 0xe8) = 0;
  if (iVar4 == 0) {
    iVar4 = *piVar1;
    *(undefined1 *)(param_1 + 0xf8) = 0;
    if (iVar4 != 0) {
      *(undefined4 *)(param_1 + 0xf0) = *(undefined4 *)(iVar4 + 0xc);
      *(undefined4 *)(param_1 + 0xf4) = *(undefined4 *)(iVar4 + 0x10);
      FUN_00551eb0(DAT_007cf2cc);
    }
  }
  else {
    *piVar1 = 0;
    uVar5 = 1;
  }
  if (puVar3 != (undefined1 *)0x0) {
    FUN_00587bcf(puVar3);
  }
  return uVar5;
}
```

---

### Source: 0x004b1b10__FUN_004b1b10.c

```c

uint __thiscall FUN_004b1b10(int param_1,undefined4 param_2)

{
  char cVar1;
  undefined1 *puVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  undefined1 auStack_100 [256];
  
  auStack_100[0] = 0;
  FUN_004a1a60(auStack_100,param_1 + 0x14);
  puVar2 = *(undefined1 **)(param_1 + 4);
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  FUN_00566c30(param_2,s__s___s__005cd13c,puVar2,auStack_100);
  pcVar3 = *(char **)(param_1 + 0xc);
  if (pcVar3 == (char *)0x0) {
    pcVar3 = &DAT_005ea438;
  }
  iVar5 = -1;
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if (iVar5 != -2) {
    FUN_00566c30(param_2,s_____s_005d23a8,*(undefined4 *)(param_1 + 0xc),
                 *(undefined4 *)(param_1 + 0x10));
  }
  uVar4 = FUN_00566c30(param_2,&DAT_005c30b4);
  return uVar4 & 0xffffff00;
}
```

---

### Source: 0x0050e19e__FUN_0050e19e.c

```c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0050e19e(float *param_1,float *param_2,float *param_3,float param_4)

{
  float fVar1;
  float *pfVar2;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  
  pfVar2 = param_2;
  fVar3 = (float10)1 - (float10)param_4;
  fVar5 = (float10)param_3[3] * (float10)param_2[3] +
          (float10)param_3[1] * (float10)param_2[1] +
          (float10)param_3[2] * (float10)param_2[2] + (float10)*param_2 * (float10)*param_3;
  if (fVar5 < (float10)DAT_0059e440) {
    param_2 = (float *)0xbf800000;
  }
  else {
    param_2 = (float *)0x3f800000;
  }
  fVar5 = (float10)(float)param_2 * fVar5;
  if ((float10)1 - fVar5 <= (float10)_DAT_005ac9c0) {
    fVar5 = (float10)param_4;
  }
  else {
    fVar4 = SQRT((float10)_DAT_0059e43c - fVar5 * fVar5);
    fVar5 = (float10)fpatan(fVar4,(float10)(float)fVar5);
    fVar1 = (float)((float10)1 / fVar4);
    fVar3 = (float10)fsin((float10)(float)fVar5 * fVar3);
    fVar3 = fVar3 * (float10)fVar1;
    fVar5 = (float10)fsin((float10)(float)fVar5 * (float10)param_4);
    fVar5 = fVar5 * (float10)fVar1;
  }
  fVar5 = fVar5 * (float10)(float)param_2;
  *param_1 = (float)(fVar5 * (float10)*param_3 + fVar3 * (float10)*pfVar2);
  param_1[1] = (float)(fVar3 * (float10)pfVar2[1] + fVar5 * (float10)param_3[1]);
  param_1[2] = (float)(fVar3 * (float10)pfVar2[2] + fVar5 * (float10)param_3[2]);
  param_1[3] = (float)(fVar3 * (float10)pfVar2[3] + fVar5 * (float10)param_3[3]);
  return;
}
```

---

### Source: 0x0050d85d__FUN_0050d85d.c

```c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0050d85d(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  
  fVar10 = *param_2 * _DAT_0059e800;
  fVar11 = param_2[1] * _DAT_0059e800;
  fVar12 = _DAT_0059e800 * param_2[2];
  fVar9 = fVar10 * param_2[3];
  fVar1 = param_2[3];
  fVar2 = param_2[3];
  fVar3 = *param_2;
  fVar4 = *param_2;
  fVar5 = *param_2;
  fVar6 = param_2[1];
  fVar7 = param_2[1];
  fVar8 = param_2[2];
  *param_1 = (1.0 - fVar11 * fVar6) - fVar12 * fVar8;
  param_1[1] = fVar11 * fVar4 + fVar12 * fVar2;
  param_1[2] = fVar12 * fVar5 - fVar11 * fVar1;
  param_1[3] = 0.0;
  param_1[4] = fVar11 * fVar4 - fVar12 * fVar2;
  fVar2 = 1.0 - fVar10 * fVar3;
  param_1[5] = fVar2 - fVar12 * fVar8;
  param_1[6] = fVar12 * fVar7 + fVar9;
  param_1[7] = 0.0;
  param_1[8] = fVar12 * fVar5 + fVar11 * fVar1;
  param_1[9] = fVar12 * fVar7 - fVar9;
  param_1[10] = fVar2 - fVar11 * fVar6;
  param_1[0xb] = 0.0;
  param_1[0xc] = 0.0;
  param_1[0xd] = 0.0;
  param_1[0xe] = 0.0;
  param_1[0xf] = 1.0;
  return;
}
```

---

### Source: 0x0050dd40__FUN_0050dd40.c

```c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0050dd40(float *param_1,float param_2,float param_3,float param_4)

{
  float fVar1;
  float fVar2;
  float10 fVar3;
  float fVar4;
  float fVar5;
  float10 fVar6;
  float10 fVar7;
  float10 fVar8;
  
  fVar3 = (float10)fcos((float10)(param_4 * _DAT_0059e450));
  fVar6 = (float10)fsin((float10)(param_4 * _DAT_0059e450));
  fVar1 = (float)fVar3;
  fVar2 = (float)fVar6;
  fVar3 = (float10)fcos((float10)(param_3 * _DAT_0059e450));
  fVar7 = (float10)fsin((float10)(param_3 * _DAT_0059e450));
  fVar6 = (float10)fcos((float10)(param_2 * _DAT_0059e450));
  fVar8 = (float10)fsin((float10)(param_2 * _DAT_0059e450));
  fVar4 = (float)fVar8 * (float)fVar3;
  fVar5 = (float)fVar6 * (float)fVar7;
  *param_1 = fVar4 * fVar2 + fVar1 * fVar5;
  param_1[1] = fVar4 * fVar1 - fVar5 * fVar2;
  fVar4 = (float)fVar6 * (float)fVar3;
  fVar5 = (float)fVar8 * (float)fVar7;
  param_1[2] = fVar4 * fVar2 - fVar5 * fVar1;
  param_1[3] = fVar4 * fVar1 + fVar5 * fVar2;
  return;
}
```

---

### Source: 0x0040bd10__FUN_0040bd10.c

```c

undefined4 __thiscall FUN_0040bd10(int param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int aiStack_1c [7];
  
  bVar1 = false;
  if ((param_2 != 0) && (*(int *)(param_1 + 0xc) != 0)) {
    FUN_0058ba36(param_2,0x80);
    FUN_005668b0();
    if (param_3 == 0) {
      FUN_00566a70(param_2,0,1,1);
    }
    else {
      FUN_00566940(param_2,0,1,1);
    }
    if (aiStack_1c[0] != 0) {
      iVar2 = 0;
      if (0 < *(int *)(param_1 + 0x10)) {
        bVar1 = true;
        iVar3 = 0;
        do {
          (**(code **)(*(int *)(*(int *)(param_1 + 0xc) + iVar3) + 8))(aiStack_1c,0);
          iVar2 = iVar2 + 1;
          iVar3 = iVar3 + 0xd0;
        } while (iVar2 < *(int *)(param_1 + 0x10));
      }
      FUN_00566b90();
      if (bVar1) {
        FUN_005668d0();
        return 0;
      }
    }
    FUN_005668d0();
  }
  return 1;
}
```

---

### Source: 0x0051cc8e__FUN_0051cc8e.c

```c

void FUN_0051cc8e(void)

{
  int iVar1;
  int in_EAX;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  int iStack_c;
  int iStack_8;
  
  iVar1 = *(int *)(in_EAX + 0x19c);
  uVar2 = (*(code *)**(undefined4 **)(in_EAX + 4))();
  *(undefined4 *)(iVar1 + 0x10) = uVar2;
  uVar2 = (*(code *)**(undefined4 **)(in_EAX + 4))();
  *(undefined4 *)(iVar1 + 0x14) = uVar2;
  uVar2 = (*(code *)**(undefined4 **)(in_EAX + 4))();
  *(undefined4 *)(iVar1 + 0x18) = uVar2;
  uVar2 = (*(code *)**(undefined4 **)(in_EAX + 4))();
  *(undefined4 *)(iVar1 + 0x1c) = uVar2;
  iVar3 = 0;
  puVar5 = &DAT_005b6900;
  iStack_c = -0xe25100;
  iStack_8 = -0xb2f480;
  iVar4 = 0x2c8d00;
  do {
    *(int *)(iVar3 + *(int *)(iVar1 + 0x10)) = iStack_8 >> 0x10;
    *(int *)(iVar3 + *(int *)(iVar1 + 0x14)) = iStack_c >> 0x10;
    *(undefined **)(iVar3 + *(int *)(iVar1 + 0x18)) = puVar5;
    *(int *)(iVar3 + *(int *)(iVar1 + 0x1c)) = iVar4;
    iVar4 = iVar4 + -0x581a;
    puVar5 = puVar5 + -0xb6d2;
    iVar3 = iVar3 + 4;
    iStack_c = iStack_c + 0x1c5a2;
    iStack_8 = iStack_8 + 0x166e9;
  } while (-0x2b34e7 < iVar4);
  return;
}
```

---

### Source: 0x0050df9b__FUN_0050df9b.c

```c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * FUN_0050df9b(float *param_1,float *param_2)

{
  float fVar1;
  int iVar2;
  float *extraout_ECX;
  
  fVar1 = param_2[3] * param_2[3] +
          param_2[2] * param_2[2] + param_2[1] * param_2[1] + *param_2 * *param_2;
  if (fVar1 <= _DAT_005ade44) {
    *param_1 = 0.0;
    param_1[1] = 0.0;
    param_1[2] = 0.0;
    fVar1 = 0.0;
  }
  else {
    *param_1 = -*param_2;
    param_1[1] = -param_2[1];
    param_1[2] = -param_2[2];
    param_1[3] = param_2[3];
    iVar2 = FUN_0050c042(fVar1,0x3f800000);
    if (iVar2 != 0) {
      return extraout_ECX;
    }
    fVar1 = 1.0 / fVar1;
    *extraout_ECX = fVar1 * *extraout_ECX;
    extraout_ECX[1] = fVar1 * extraout_ECX[1];
    extraout_ECX[2] = fVar1 * extraout_ECX[2];
    fVar1 = fVar1 * extraout_ECX[3];
    param_1 = extraout_ECX;
  }
  param_1[3] = fVar1;
  return param_1;
}
```

---

### Source: 0x0050e0d9__FUN_0050e0d9.c

```c

float * FUN_0050e0d9(float *param_1,float *param_2)

{
  float10 fVar1;
  float fVar2;
  int iVar3;
  float *extraout_ECX;
  float10 fVar4;
  
  fVar2 = SQRT(param_2[2] * param_2[2] + param_2[1] * param_2[1] + *param_2 * *param_2);
  fVar4 = (float10)fVar2;
  fVar1 = (float10)fcos(fVar4);
  fVar4 = (float10)fsin(fVar4);
  param_1[3] = (float)fVar1;
  iVar3 = FUN_0050c042((float)fVar4,0);
  if (iVar3 == 0) {
    fVar2 = (float)fVar4 / fVar2;
    *param_1 = fVar2 * *extraout_ECX;
    param_1[1] = fVar2 * extraout_ECX[1];
    param_1[2] = fVar2 * extraout_ECX[2];
  }
  else if (param_1 != extraout_ECX) {
    *param_1 = *extraout_ECX;
    param_1[1] = extraout_ECX[1];
    param_1[2] = extraout_ECX[2];
  }
  return param_1;
}
```

---

### Source: 0x00585ea0__FUN_00585ea0.c

```c

undefined4 * __fastcall FUN_00585ea0(undefined4 *param_1)

{
  HANDLE pvVar1;
  _SECURITY_ATTRIBUTES _Stack_c;
  
  *(undefined1 *)(param_1 + 2) = 0;
  param_1[3] = 0;
  *(undefined1 *)(param_1 + 5) = 0;
  param_1[4] = 0xffffffff;
  _Stack_c.nLength = 0xc;
  _Stack_c.lpSecurityDescriptor = (LPVOID)0x0;
  _Stack_c.bInheritHandle = 1;
  pvVar1 = CreateMutexA(&_Stack_c,0,(LPCSTR)0x0);
  param_1[3] = pvVar1;
  if (pvVar1 != (HANDLE)0x0) {
    *(undefined1 *)(param_1 + 5) = 1;
  }
  *(undefined1 *)(param_1 + 6) = 0;
  param_1[7] = 0;
  *(undefined1 *)(param_1 + 9) = 0;
  param_1[8] = 0xffffffff;
  _Stack_c.nLength = 0xc;
  _Stack_c.lpSecurityDescriptor = (LPVOID)0x0;
  _Stack_c.bInheritHandle = 1;
  pvVar1 = CreateMutexA(&_Stack_c,0,(LPCSTR)0x0);
  param_1[7] = pvVar1;
  if (pvVar1 != (HANDLE)0x0) {
    *(undefined1 *)(param_1 + 9) = 1;
  }
  *param_1 = 0;
  param_1[1] = 0;
  return param_1;
}
```

---

### Source: 0x0050e055__FUN_0050e055.c

```c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0050e055(float *param_1,float *param_2)

{
  float fVar1;
  int iVar2;
  float10 fVar3;
  float10 fVar4;
  
  if (param_2[3] < _DAT_0059e43c) {
    fVar3 = (float10)FUN_005894a0();
    fVar4 = (float10)fsin(fVar3);
    iVar2 = FUN_0050c042((float)fVar4,0);
    if (iVar2 == 0) {
      fVar1 = (float)fVar3 / (float)fVar4;
      *param_1 = fVar1 * *param_2;
      param_1[1] = fVar1 * param_2[1];
      param_1[2] = fVar1 * param_2[2];
      goto LAB_0050e0c9;
    }
  }
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
LAB_0050e0c9:
  param_1[3] = 0.0;
  return;
}
```

---

### Source: 0x0057e410__FUN_0057e410.c

```c

void FUN_0057e410(void)

{
  int iVar1;
  BOOL BVar2;
  tagMSG tStack_1c;
  
  iVar1 = PeekMessageA(&tStack_1c,(HWND)0x0,0,0,0);
  while ((iVar1 != 0 && (BVar2 = GetMessageA(&tStack_1c,(HWND)0x0,0,0), BVar2 != 0))) {
    TranslateMessage(&tStack_1c);
    DispatchMessageA(&tStack_1c);
    iVar1 = PeekMessageA(&tStack_1c,(HWND)0x0,0,0,0);
  }
  return;
}
```

---

### Source: 0x0057e860__FUN_0057e860.c

```c

void FUN_0057e860(undefined4 param_1)

{
  char cVar1;
  undefined2 uStack_10;
  u_short uStack_e;
  u_long uStack_c;
  
  uStack_10 = 2;
  uStack_c = htonl(0);
  uStack_e = htons(0);
  FUN_0057b9f0(&uStack_10);
  cVar1 = FUN_00586ca0();
  if (cVar1 != '\0') {
    FUN_0057d8d0(param_1,&uStack_10);
    return;
  }
  FUN_0057d6c0(param_1,&uStack_10);
  return;
}
```

---

### Source: 0x00459010__FUN_00459010.c

```c

void __fastcall FUN_00459010(int param_1)

{
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_c = 0;
  uStack_8 = 0;
  uStack_4 = 0;
  FUN_00456150(&uStack_c);
  *(undefined4 *)(param_1 + 0xbc) = 0;
  *(undefined1 *)(param_1 + 0xcc) = 0;
  *(undefined4 *)(param_1 + 0xac) = 0x3f800000;
  FUN_00456130(param_1 + 0x90);
  *(undefined1 *)(param_1 + 0xa0) = 1;
  return;
}
```

---

### Source: 0x0045cde0__FUN_0045cde0.c

```c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0045cde0(void)

{
  undefined1 auStack_8 [8];
  
  FUN_0045ce30();
  auStack_8[0] = 0;
  FUN_0058815f(auStack_8,s__1_3f_005c5bcc,(double)_DAT_0059f090);
  FUN_0045ce30();
  return;
}
```

---

### Source: 0x004f6b00__FUN_004f6b00.c

```c

void FUN_004f6b00(void)

{
  int *piVar1;
  undefined1 *puVar2;
  int iVar3;
  
  puVar2 = &DAT_008afc74;
  iVar3 = 0x2d;
  do {
    piVar1 = (int *)(puVar2 + -0x14);
    puVar2 = puVar2 + -0x14;
    if (*piVar1 != 0) {
      FUN_00587bcf(*piVar1);
    }
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}
```

---

### Source: 0x004f6b90__FUN_004f6b90.c

```c

void FUN_004f6b90(void)

{
  int *piVar1;
  undefined *puVar2;
  int iVar3;
  
  puVar2 = &DAT_008af8ec;
  iVar3 = 0x2d;
  do {
    piVar1 = (int *)(puVar2 + -0x14);
    puVar2 = puVar2 + -0x14;
    if (*piVar1 != 0) {
      FUN_00587bcf(*piVar1);
    }
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}
```

---

### Source: 0x0054c2a0__FUN_0054c2a0.c

```c

void FUN_0054c2a0(void)

{
  int iVar1;
  
  iVar1 = 0x100;
  do {
    FUN_0053b160();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}
```

---

### Source: 0x0050e313__FUN_0050e313.c

```c

void FUN_0050e313(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  FUN_0050fea7(1);
  (*pcRam005d7858)(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}
```

---

### Source: 0x0050c2b9__FUN_0050c2b9.c

```c

void FUN_0050c2b9(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  FUN_0050fea7(1);
  (*pcRam005d788c)(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}
```

---

### Source: 0x0054c300__FUN_0054c300.c

```c

void FUN_0054c300(void)

{
  int iVar1;
  
  iVar1 = 0x100;
  do {
    FUN_0053b160();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}
```

---

### Source: 0x0054ead0__FUN_0054ead0.c

```c

void FUN_0054ead0(void)

{
  int iVar1;
  
  iVar1 = 0x400;
  do {
    FUN_004b0170();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}
```

---

### Source: 0x005568e0__FUN_005568e0.c

```c

void FUN_005568e0(void)

{
  int iVar1;
  
  iVar1 = 0x200;
  do {
    FUN_004b0170();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}
```

---

### Source: 0x0051dfa8__FUN_0051dfa8.c

```c

void FUN_0051dfa8(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x1a4);
  *(undefined4 *)(param_1 + 0x74) = *(undefined4 *)(iVar1 + 0x10);
  FUN_0051d80a(*(undefined4 *)(iVar1 + 0x14));
  *(undefined1 *)(iVar1 + 0x1c) = 1;
  return;
}
```

---

### Source: 0x0058dd75__FUN_0058dd75.c

```c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0058dd75(undefined4 param_1,int param_2)

{
  ushort in_FPUStatusWord;
  float10 in_ST0;
  ushort unaff_retaddr;
  uint uStack_4;
  
  uStack_4 = (uint)((ulonglong)(double)in_ST0 >> 0x20);
  if ((uStack_4 & 0x7ff00000) == 0x7ff00000) {
    fscale(in_ST0,(float10)_DAT_005b8e24);
  }
  else if (((unaff_retaddr == 0x27f) || ((unaff_retaddr & 0x20) != 0)) ||
          ((in_FPUStatusWord & 0x20) == 0)) {
    return;
  }
  if (param_2 == 0x1d) {
    FUN_0058dc40();
    return;
  }
  __startOneArgErrorHandling();
  return;
}
```

---
