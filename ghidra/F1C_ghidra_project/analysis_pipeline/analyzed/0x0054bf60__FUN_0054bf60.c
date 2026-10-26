// Function: FUN_0054bf60 @ 0054bf60
// Size (bytes): 201


void __thiscall FUN_0054bf60(int param_1,int param_2,int param_3,float param_4,float param_5)

{
  int iVar1;
  float *pfVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  for (iVar1 = *(int *)(param_1 + 0x204); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x10)) {
    iVar5 = 0;
    if (0 < *(int *)(iVar1 + 0x118)) {
      piVar3 = (int *)(*(int *)(iVar1 + 0x11c) + 8);
      do {
        if (piVar3[-1] == param_2) {
          if (param_3 == 0) {
            iVar4 = 0;
            if (0 < *piVar3) {
              pfVar2 = (float *)(piVar3[1] + 0x24);
              do {
                iVar4 = iVar4 + 1;
                pfVar2[-1] = param_4 + pfVar2[-1];
                *pfVar2 = param_5 + *pfVar2;
                pfVar2 = pfVar2 + 0xc;
              } while (iVar4 < *piVar3);
            }
          }
          else if ((param_3 == 1) && (iVar4 = 0, 0 < *piVar3)) {
            pfVar2 = (float *)(piVar3[1] + 0x2c);
            do {
              iVar4 = iVar4 + 1;
              pfVar2[-1] = param_4 + pfVar2[-1];
              *pfVar2 = param_5 + *pfVar2;
              pfVar2 = pfVar2 + 0xc;
            } while (iVar4 < *piVar3);
          }
          piVar3[0xc] = piVar3[0xc] | 0x800;
        }
        piVar3 = piVar3 + 0x10;
        iVar5 = iVar5 + 1;
      } while (iVar5 < *(int *)(iVar1 + 0x118));
    }
  }
  return;
}


