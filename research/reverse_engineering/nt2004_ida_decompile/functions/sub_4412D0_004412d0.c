LPVOID __thiscall sub_4412D0(int this, int a2)
{
  int v3; // ebp
  double v4; // st7
  int v5; // edi
  CHAR *v6; // eax
  int v7; // edi
  CHAR *v8; // eax
  char *v9; // eax
  LPVOID result; // eax
  __int64 v11; // [esp-18h] [ebp-3A14h]
  LPVOID v12[3]; // [esp+4h] [ebp-39F8h] BYREF
  LPVOID v13; // [esp+10h] [ebp-39ECh]
  LPVOID v14; // [esp+18h] [ebp-39E4h]
  LPVOID v15; // [esp+20h] [ebp-39DCh]
  LPVOID v16; // [esp+28h] [ebp-39D4h]
  CHAR *v17; // [esp+30h] [ebp-39CCh]
  char v18[104]; // [esp+1CDCh] [ebp-1D20h] BYREF
  LPVOID v19; // [esp+1D44h] [ebp-1CB8h]
  _DWORD v20[236]; // [esp+364Ch] [ebp-3B0h] BYREF

  *(_DWORD *)(this + 8620) = a2;
  v3 = sub_579ED0(512);
  *(_DWORD *)(this + 128) = 0;
  *(_DWORD *)(this + 132) = 0;
  *(double *)(this + 136) = 1.0 / (double)(320 >> dword_766AA4[0]);
  v4 = (double)(320 >> dword_766AA4[0]) * 0.8;
  dbl_61B430 = v4 * v4;
  dbl_61B438 = v4 + v4;
  sub_440D30((_DWORD *)this);
  sub_430BC0(v18);
  sub_5208C0(v12);
  v5 = 1232 * *(_DWORD *)(a2 + 25252);
  v6 = *(CHAR **)(v5 + dword_7D6A5C + 8);
  v7 = dword_7D6A5C + v5;
  if ( !v6 )
    v6 = &byte_629120;
  sub_521740((char)v6, (int)v18, 0);
  sub_521740(a2 + 32, (int)v18, 1);
  v8 = v17;
  if ( !v17 )
    v8 = &byte_629120;
  sub_43B6B0((_DWORD *)this, (int)v8);
  sub_43BB20(this, (int)v18, (int)v12);
  HIDWORD(v11) = v12;
  LODWORD(v11) = v18;
  sub_43EC40(this, v11);
  sub_43B590(this);
  v9 = *(char **)(v7 + 16);
  if ( !v9 )
    v9 = &byte_629120;
  sub_43B810((int *)this, v9, (float *)(v7 + 64));
  if ( v3 != 512 )
    sub_579F10(v3);
  if ( v17 )
    sub_5BE8AE(v17);
  if ( v16 )
    sub_5BE8AE(v16);
  if ( v15 )
    sub_5BE8AE(v15);
  if ( v14 )
    sub_5BE8AE(v14);
  if ( v13 )
    sub_5BE8AE(v13);
  if ( v12[0] )
    sub_5BE8AE(v12[0]);
  sub_430670(v20);
  result = v19;
  if ( v19 )
    return (LPVOID)sub_5BE8AE(v19);
  return result;
}
