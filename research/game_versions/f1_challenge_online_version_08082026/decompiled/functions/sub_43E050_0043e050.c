LPVOID __thiscall sub_43E050(int this, int a2)
{
  int v3; // ebp
  double v4; // st7
  int v5; // edi
  char *v6; // eax
  int v7; // edi
  char *v8; // eax
  char *v9; // eax
  LPVOID result; // eax
  __int64 v11; // [esp-18h] [ebp-37A0h]
  LPVOID v12[3]; // [esp+4h] [ebp-3784h] BYREF
  LPVOID v13; // [esp+10h] [ebp-3778h]
  LPVOID v14; // [esp+18h] [ebp-3770h]
  LPVOID v15; // [esp+20h] [ebp-3768h]
  LPVOID v16; // [esp+28h] [ebp-3760h]
  char *v17; // [esp+30h] [ebp-3758h]
  char v18[104]; // [esp+1A6Ch] [ebp-1D1Ch] BYREF
  LPVOID v19; // [esp+1AD4h] [ebp-1CB4h]
  _DWORD v20[235]; // [esp+33DCh] [ebp-3ACh] BYREF

  *(_DWORD *)(this + 7936) = a2;
  v3 = sub_567740(512);
  *(_DWORD *)(this + 96) = 0;
  *(_DWORD *)(this + 100) = 0;
  *(double *)(this + 104) = 1.0 / (double)(400 >> dword_7CE958);
  v4 = (double)(400 >> dword_7CE958) * 0.8;
  dbl_5E5238 = v4 * v4;
  dbl_5E5240 = v4 + v4;
  sub_42E320(v18);
  sub_4F34E0(v12);
  v5 = 1060 * *(_DWORD *)(a2 + 18584);
  v6 = *(char **)(v5 + dword_8AC394 + 8);
  v7 = dword_8AC394 + v5;
  if ( !v6 )
    v6 = &byte_5EA438;
  sub_4F4270(v6, v18, 0);
  sub_4F4270(a2 + 18324, v18, 1);
  v8 = v17;
  if ( !v17 )
    v8 = &byte_5EA438;
  sub_438DA0((_DWORD *)this, (int)v8);
  sub_439210(this, (int)v18, (int)v12);
  HIDWORD(v11) = v12;
  LODWORD(v11) = v18;
  sub_43C250(this, v11);
  sub_438CC0(this);
  v9 = *(char **)(v7 + 16);
  if ( !v9 )
    v9 = &byte_5EA438;
  sub_438F00((int *)this, (int)v9, (float *)(v7 + 56));
  if ( v3 != 512 )
    sub_567780(v3);
  if ( v17 )
    sub_587BCF(v17);
  if ( v16 )
    sub_587BCF(v16);
  if ( v15 )
    sub_587BCF(v15);
  if ( v14 )
    sub_587BCF(v14);
  if ( v13 )
    sub_587BCF(v13);
  if ( v12[0] )
    sub_587BCF(v12[0]);
  sub_42DDD0(v20);
  result = v19;
  if ( v19 )
    return (LPVOID)sub_587BCF(v19);
  return result;
}
