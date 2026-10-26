// Function: FUN_00548ad0 @ 00548ad0
// Strings:  [Reflection mapper requires render target, REFVIEW, No reflection map stages in material]


undefined4 __thiscall FUN_00548ad0(undefined4 *param_1,int param_2,int param_3)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 local_100 [256];
  
  if (*(int *)(param_3 + 0xa4) != 0) {
    iVar1 = *(int *)(param_3 + 0xa8);
    iVar4 = 0;
    if (0 < *(int *)(param_3 + 0xa4)) {
      do {
        if ((*(uint *)(iVar1 + 0x60) & 0x800000) != 0) {
          if ((*(byte *)(iVar1 + 0x40) & 2) == 0) {
            FUN_0058815f(local_100,s_Reflection_mapper_requires_rende_005dbe94);
            goto LAB_00548b49;
          }
          if (param_2 == 2) {
            param_1[1] = *(undefined4 *)(iVar1 + 0x8c);
            param_1[3] = 0;
            pvVar2 = operator_new(0x1bc);
            if (pvVar2 == (void *)0x0) {
              uVar3 = 0;
            }
            else {
              uVar3 = FUN_005418b0();
            }
            *param_1 = uVar3;
            FUN_0058815f(local_100,s_REFVIEW_005dbec0);
            FUN_005418e0(local_100);
            FUN_005423c0(0x3f800000,0x447a0000);
            FUN_005423e0(0,0,0);
            FUN_00542050(0x403de732,0x403de732,1);
            FUN_00542560(*(undefined4 *)(param_1[1] + 0x54));
            FUN_00541ca0(1);
            return 0;
          }
          param_1[5] = 0;
          param_1[6] = 0;
        }
        iVar1 = iVar1 + 0x94;
        iVar4 = iVar4 + 1;
      } while (iVar4 < *(int *)(param_3 + 0xa4));
    }
    FUN_0058815f(local_100,s_No_reflection_map_stages_in_mate_005dbec8);
LAB_00548b49:
    FUN_0053c590(0xffffffff,local_100);
  }
  return 0xffffffff;
}


