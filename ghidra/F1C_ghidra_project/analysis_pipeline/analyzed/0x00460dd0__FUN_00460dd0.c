// Function: FUN_00460dd0 @ 00460dd0
// Size (bytes): 189


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00460dd0(int param_1)

{
  float fVar1;
  char cVar2;
  float *pfVar3;
  undefined *puVar4;
  int iVar5;
  undefined4 uVar6;
  float local_4;
  
  iVar5 = 0;
  puVar4 = &DAT_005ec6d8;
  pfVar3 = (float *)(param_1 + 0x1a3d4);
  do {
    if (*(int *)(puVar4 + 13000) == 2) {
      cVar2 = FUN_0045cbf0(iVar5,&local_4);
      fVar1 = *pfVar3 / DAT_007d108c;
      if ((_DAT_0059e800 < fVar1) || (cVar2 != '\0')) {
        FUN_004c7a70(0);
        if ((_DAT_0059e4dc < fVar1) || ((float)_DAT_0059ea60 < ABS(local_4))) {
          uVar6 = 0;
        }
        else {
          uVar6 = 1;
        }
      }
      else {
        FUN_004c7a70(1);
        uVar6 = 1;
      }
      FUN_004c7aa0(uVar6);
    }
    puVar4 = puVar4 + 0x48c0;
    iVar5 = iVar5 + 1;
    pfVar3 = pfVar3 + 1;
  } while ((int)puVar4 < 0x7c54d8);
  return;
}


