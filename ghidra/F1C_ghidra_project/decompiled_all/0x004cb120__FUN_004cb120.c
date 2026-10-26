// Function: FUN_004cb120 @ 004cb120
// Strings:  [D:\dev\F1_1999_2002\Source\specialfx.cpp, D:\dev\F1_1999_2002\Source\specialfx.cpp, CUBE Error: %s, Could not create %d-particle system using MTS:%s or BMP:%s with flags 0x%08x, Reaction%02d]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004cb120(undefined4 *param_1,char param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  char cVar5;
  int *piVar6;
  void *pvVar7;
  int iVar8;
  uint uVar9;
  float *pfVar10;
  uint uVar11;
  int *piVar12;
  float *pfVar13;
  int iVar14;
  undefined1 local_100 [256];
  
  _DAT_005d348c = _DAT_007cf974 * _DAT_007cf974;
  _DAT_005d3488 = DAT_007cf998;
  _DAT_005d3490 = _DAT_007cf974 + DAT_007cf998;
  _DAT_005d3494 = _DAT_005d3490 * _DAT_005acea4;
  if (param_2 != '\0') {
    iVar8 = 4 - DAT_007cf8a8;
    param_1[2] = iVar8;
    if (DAT_007cf8a8 == 0) {
      param_1[0x16] = 0;
      param_1[0x19] = 0;
    }
    else {
      param_1[0x16] = (int)param_1[0x16] >> ((byte)iVar8 & 0x1f);
    }
  }
  if (0 < (int)param_1[0x16]) {
    FUN_0058815f(param_1[0x14],s_Reaction_02d_005d37d8,*param_1);
    *(undefined4 *)(param_1[0x14] + 0x24) = param_1[0x16];
    *(undefined4 *)(param_1[0x14] + 0x28) = param_1[3];
    *(undefined4 *)(param_1[0x14] + 0x2c) = param_1[4];
    *(undefined4 *)(param_1[0x14] + 0x30) = param_1[5];
    iVar8 = FUN_00559200(param_1 + 0x15,param_1[0x14]);
    if (iVar8 == 0) {
      iVar8 = param_1[0x16];
      piVar6 = operator_new(iVar8 * 0x6c + 4);
      if (piVar6 == (int *)0x0) {
        piVar12 = (int *)0x0;
      }
      else {
        piVar12 = piVar6 + 1;
        *piVar6 = iVar8;
        if (-1 < iVar8 + -1) {
          do {
            FUN_004c9d50();
            iVar8 = iVar8 + -1;
          } while (iVar8 != 0);
        }
      }
      param_1[0x17] = piVar12;
      fVar2 = DAT_0059e440;
      param_1[0x18] = 0;
      fVar1 = DAT_0059e440;
      if (fVar2 < (float)param_1[0xc]) {
        fVar1 = _DAT_0059e43c / (float)param_1[0xc];
      }
      param_1[0x10] = fVar1;
      param_1[0x19] = 0;
      pvVar7 = operator_new(param_1[0x16] << 2);
      param_1[0x1a] = pvVar7;
      if (0 < (int)param_1[0x16]) {
        iVar8 = 0;
        iVar14 = 0;
        do {
          *(int *)(param_1[0x17] + iVar8) = iVar14;
          *(undefined4 *)(param_1[0x17] + 4 + iVar8) = 0xffffffff;
          FUN_004c9d60(param_1[0xc],param_1[0xd],param_1[0xe],param_1[0xf]);
          *(undefined4 *)(param_1[0x1a] + iVar14 * 4) = 0;
          iVar14 = iVar14 + 1;
          iVar8 = iVar8 + 0x6c;
        } while (iVar14 < (int)param_1[0x16]);
      }
      if (param_1[1] == 0xd) {
        DAT_008acedc = 0;
        pfVar13 = (float *)&DAT_008acaa4;
        do {
          do {
            uVar9 = DAT_008aae70 & 0xff;
            DAT_008aae70 = DAT_008aae70 + 1;
            fVar1 = *(float *)(&DAT_008ab274 + uVar9 * 4) * _DAT_0059e8ec;
            uVar9 = FUN_004b3c60();
            fVar2 = ((float)(uVar9 & 0x1ffff) * _DAT_005acea0 - _DAT_0059e43c) * _DAT_0059e8ec;
          } while (_DAT_0059e920 <= fVar1 * fVar1 + fVar2 * fVar2);
          *pfVar13 = fVar2;
          pfVar13[-1] = fVar1;
          pfVar13 = pfVar13 + 2;
        } while ((int)pfVar13 < 0x8acea4);
        pfVar13 = (float *)&DAT_008ac828;
        uVar9 = DAT_008aae70;
        do {
          fVar1 = *(float *)(&DAT_008ab274 + (uVar9 & 0xff) * 4);
          fVar2 = *(float *)(&DAT_008ab274 + (uVar9 + 1 & 0xff) * 4);
          fVar3 = *(float *)(&DAT_008ab274 + (uVar9 + 2 & 0xff) * 4);
          *pfVar13 = fVar1;
          pfVar13[-2] = fVar3;
          pfVar13[-1] = fVar2;
          uVar11 = uVar9 + 3;
          fVar4 = fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3;
          if (fVar4 == DAT_0059e440) {
            pfVar13[-2] = 0.0;
            pfVar13[-1] = 1.0;
            *pfVar13 = 0.0;
          }
          else {
            fVar4 = _DAT_0059e43c / SQRT(fVar4);
            pfVar13[-2] = fVar3 * fVar4;
            pfVar13[-1] = fVar2 * fVar4;
            *pfVar13 = fVar4 * fVar1;
          }
          uVar9 = uVar9 + 4;
          pfVar10 = pfVar13 + 10;
          DAT_008aae70 = uVar9;
          pfVar13[1] = _DAT_005ace9c -
                       *(float *)(&DAT_008aae74 + (uVar11 & 0xff) * 4) * _DAT_0059e478;
          pfVar13 = pfVar10;
        } while ((int)pfVar10 < 0x8acaa8);
      }
    }
    else {
      FUN_0053c5b0(0,local_100);
      cVar5 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_speci_005d3624,0x369);
      if (cVar5 != '\0') {
        iVar8 = param_1[0x14];
        FUN_004d7aa0(&DAT_008ad25c,s_Could_not_create__d_particle_sys_005d3788,
                     *(undefined4 *)(iVar8 + 0x24),iVar8 + 0x38,iVar8 + 0x70,
                     *(undefined4 *)(iVar8 + 0x20));
      }
      cVar5 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_speci_005d3624,0x36c);
      if (cVar5 != '\0') {
        FUN_004d7aa0(&DAT_008ad25c,s_CUBE_Error___s_005d3778,local_100);
        return;
      }
    }
  }
  return;
}


