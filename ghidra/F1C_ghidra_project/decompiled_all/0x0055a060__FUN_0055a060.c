// Function: FUN_0055a060 @ 0055a060
// Strings:  [CLEAR, CENTER, CLIPPLANES, COLOR, SEPARATESURFACE, BGMAP, ORIENT]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0055a060(undefined4 param_1,int param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  int local_260;
  float local_25c;
  float local_258;
  float local_254;
  float local_250;
  float local_24c;
  float local_248;
  float local_244;
  int local_240;
  undefined4 local_23c;
  undefined4 local_238;
  int local_234;
  undefined4 local_230 [2];
  undefined4 local_228;
  undefined4 local_224;
  undefined4 local_220;
  float local_21c;
  float local_218;
  float local_214;
  undefined4 local_210;
  float local_20c;
  float local_208;
  undefined4 local_204;
  char local_200 [256];
  undefined1 local_100 [256];
  
  local_234 = 0;
  local_240 = 0;
  iVar1 = FUN_00544e90(&local_260,param_1);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  local_230[0] = 0;
  local_228 = 0;
  local_220 = 0;
  local_244 = 0.0;
  local_24c = 0.0;
  local_248 = 0.0;
  local_250 = 0.0;
  local_254 = 0.0;
  local_25c = 0.0;
  local_258 = 0.0;
  local_224 = 0x48;
  local_23c = 0x48;
  local_238 = 0x48;
  uVar2 = 0x20;
  iVar1 = FUN_00559a70();
  if (iVar1 != 1) {
    do {
      if (*param_3 == 3) break;
      if (*param_3 != 2) {
        iVar1 = FUN_00559e20(&DAT_005dc234,param_1,0);
        if ((iVar1 != 0) && (iVar1 = FUN_0055a060(param_1,local_260,param_3), iVar1 != 0)) {
          return 0xffffffff;
        }
        FUN_00559fb0(&DAT_005dc230,&local_248,&local_24c,&local_244,0);
        FUN_00559fb0(&DAT_005c57fc,&local_208,&local_21c,0,0);
        FUN_00559f00(s_COLOR_005c57f4,&local_238,&local_23c,&local_224,0);
        FUN_00559fb0(s_CLIPPLANES_005c57e8,&local_204,&local_210,0,0);
        iVar1 = FUN_00559fb0(s_ORIENT_005dc228,&local_220,&local_228,local_230,0);
        if (iVar1 != 0) {
          local_240 = 1;
        }
        iVar1 = FUN_00559fb0(&DAT_005dc224,&local_20c,&local_214,&local_218,0);
        if (iVar1 != 0) {
          local_240 = 2;
        }
        iVar1 = FUN_00559fb0(&DAT_005c57d0,&local_258,&local_25c,0,0);
        if (iVar1 != 0) {
          if (local_258 < (float)_DAT_0059e420 != (local_258 == (float)_DAT_0059e420)) {
            local_258 = (float)DAT_008b8dd4 * local_258;
          }
          if (local_25c < (float)_DAT_0059e420 != (local_25c == (float)_DAT_0059e420)) {
            local_25c = (float)DAT_008b8dd8 * local_25c;
          }
        }
        iVar1 = FUN_00559fb0(s_CENTER_005c57c8,&local_254,&local_250,0,0);
        if (iVar1 != 0) {
          if (local_254 < (float)_DAT_0059e420 != (local_254 == (float)_DAT_0059e420)) {
            local_254 = (float)DAT_008b8dd4 * local_254;
          }
          if (local_250 < (float)_DAT_0059e420 != (local_250 == (float)_DAT_0059e420)) {
            local_250 = (float)DAT_008b8dd8 * local_250;
          }
        }
        iVar1 = FUN_00559e20(s_CLEAR_005c57a0,local_200,0);
        if (iVar1 != 0) {
          iVar1 = 5;
          bVar5 = true;
          pcVar3 = local_200;
          pcVar4 = &DAT_005c596c;
          do {
            if (iVar1 == 0) break;
            iVar1 = iVar1 + -1;
            bVar5 = *pcVar3 == *pcVar4;
            pcVar3 = pcVar3 + 1;
            pcVar4 = pcVar4 + 1;
          } while (bVar5);
          if (bVar5) {
            uVar2 = uVar2 | 2;
          }
          else {
            uVar2 = uVar2 & 0xfffffffd;
          }
        }
        iVar1 = FUN_00559e20(s_BGMAP_005dc21c,local_100,0);
        if (iVar1 != 0) {
          local_234 = 1;
        }
        FUN_00559e20(s_SEPARATESURFACE_005dc20c,local_200,0);
      }
      iVar1 = FUN_00559a70();
    } while (iVar1 != 1);
    if ((local_234 != 0) && (iVar1 = FUN_0053cb20(local_260 + 0x1a0,local_100,0,1), iVar1 != 0)) {
      return 0xffffffff;
    }
  }
  FUN_00542050(local_208 * _DAT_0059e65c,local_21c * _DAT_0059e65c,0);
  FUN_00542200(local_254 - local_258 * _DAT_0059e450,local_250 - local_25c * _DAT_0059e450,local_258
               ,local_25c,0);
  FUN_005423c0(local_204,local_210);
  FUN_005423e0(local_238,local_23c,local_224);
  *(uint *)(local_260 + 0x80) = uVar2;
  if (local_240 == 2) {
    FUN_00541d10(-local_248,-local_24c,-local_244);
    FUN_00541f60(-(local_20c + local_248),-(local_214 + local_24c),-(local_218 + local_244));
  }
  else {
    FUN_00541cd0(local_248,local_24c,local_244,local_220,local_228,local_230[0]);
  }
  if (param_2 != 0) {
    FUN_005419d0(local_260);
    return 0;
  }
  FUN_00545030(local_260);
  return 0;
}


