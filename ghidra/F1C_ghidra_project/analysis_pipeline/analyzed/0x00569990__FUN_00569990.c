// Function: FUN_00569990 @ 00569990
// Size (bytes): 139


void __thiscall
FUN_00569990(int param_1,double *param_2,undefined4 param_3,undefined1 param_4,undefined4 param_5,
            undefined4 param_6)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double *pdVar7;
  
  pdVar7 = (double *)(*(int *)(param_1 + 0x23c) * 0x58 + *(int *)(param_1 + 0x240));
  *(int *)(param_1 + 0x23c) = *(int *)(param_1 + 0x23c) + 1;
  dVar4 = *param_2 - *(double *)(param_1 + 4);
  dVar6 = param_2[1] - *(double *)(param_1 + 0xc);
  dVar5 = param_2[2] - *(double *)(param_1 + 0x14);
  *pdVar7 = dVar4 * *(double *)(param_1 + 0x1c) +
            dVar6 * *(double *)(param_1 + 0x34) + dVar5 * *(double *)(param_1 + 0x4c);
  pdVar7[1] = dVar4 * *(double *)(param_1 + 0x24) +
              dVar6 * *(double *)(param_1 + 0x3c) + dVar5 * *(double *)(param_1 + 0x54);
  dVar1 = *(double *)(param_1 + 0x5c);
  dVar2 = *(double *)(param_1 + 0x44);
  dVar3 = *(double *)(param_1 + 0x2c);
  *(undefined4 *)(pdVar7 + 6) = param_3;
  *(undefined1 *)((int)pdVar7 + 0x34) = param_4;
  pdVar7[2] = dVar4 * dVar3 + dVar6 * dVar2 + dVar5 * dVar1;
  *(undefined4 *)(pdVar7 + 7) = param_5;
  *(undefined4 *)((int)pdVar7 + 0x3c) = param_6;
  return;
}


