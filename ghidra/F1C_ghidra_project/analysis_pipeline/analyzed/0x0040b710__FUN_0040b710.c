// Function: FUN_0040b710 @ 0040b710
// Size (bytes): 313


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0040b710(int param_1)

{
  int iVar1;
  float unaff_EBP;
  undefined4 unaff_ESI;
  int *piVar2;
  undefined4 unaff_EDI;
  float10 fVar3;
  int *local_48;
  int local_24 [3];
  undefined1 local_18 [12];
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  piVar2 = (int *)(*(int *)(param_1 + 0x14) * 0xd0 + *(int *)(param_1 + 0xc));
  if (*(int *)(param_1 + 4) != 0) {
    local_48 = local_24;
    FUN_004e1fd0(local_18);
    local_c = *(undefined4 *)(DAT_007c54e0 + 0x58);
    local_8 = *(undefined4 *)(DAT_007c54e0 + 0x5c);
    local_4 = *(undefined4 *)(DAT_007c54e0 + 0x60);
    iVar1 = *piVar2;
    local_48 = (int *)0x40b772;
    fVar3 = (float10)FUN_0040c780();
    local_48 = (int *)(float)fVar3;
    fVar3 = (float10)FUN_004084a0();
    (**(code **)(iVar1 + 0x18))(local_18,local_24,&local_c,(float)fVar3);
    local_24[0] = piVar2[5];
    FUN_00541cd0(piVar2[3],piVar2[4],local_24[0],piVar2[6],piVar2[7],piVar2[8]);
    FUN_00456060(&stack0xffffffbc,&local_48);
    FUN_00456080(&stack0xffffffc4,&stack0xffffffc0);
    FUN_00542050(unaff_EBP * _DAT_0059e65c,(float)local_48 * _DAT_0059e65c,0);
    FUN_005423c0(unaff_ESI,unaff_EDI);
    FUN_00542680(piVar2[0x12]);
  }
  return;
}


