char __thiscall sub_45D8D0(unsigned __int8 *this, char *FileName, _DWORD *a3, char a4)
{
  char v5; // bl
  char *v6; // ecx
  char *v7; // ecx
  char *v8; // ecx
  char *v9; // ecx
  char *v10; // ecx
  char *v11; // ecx
  int v13; // [esp+10h] [ebp-39FCh] BYREF
  LPVOID v14[3]; // [esp+14h] [ebp-39F8h] BYREF
  char *v15; // [esp+20h] [ebp-39ECh]
  char *v16; // [esp+28h] [ebp-39E4h]
  char *v17; // [esp+30h] [ebp-39DCh]
  char *v18; // [esp+38h] [ebp-39D4h]
  char *v19; // [esp+40h] [ebp-39CCh]
  char v20[104]; // [esp+1CECh] [ebp-1D20h] BYREF
  LPVOID v21; // [esp+1D54h] [ebp-1CB8h]
  _DWORD v22[236]; // [esp+365Ch] [ebp-3B0h] BYREF

  v5 = 1;
  sub_430BC0(v20);
  sub_5208C0(v14);
  sub_521740((char)FileName, (int)v20, 2);
  *a3 = 0;
  if ( (unsigned __int8)sub_57B490(FileName, this[1], (int)&v13) )
    *a3 += v13;
  else
    v5 = 0;
  if ( a4 )
  {
    v6 = (char *)v14[0];
    if ( !v14[0] )
      v6 = &byte_629120;
    if ( (unsigned __int8)sub_57B490(v6, this[1], (int)&v13) )
      *a3 += v13;
    else
      v5 = 0;
    *a3 += v14[2];
  }
  v7 = v15;
  if ( !v15 )
    v7 = &byte_629120;
  if ( (unsigned __int8)sub_57B490(v7, this[1], (int)&v13) )
    *a3 += v13;
  else
    v5 = 0;
  v8 = v16;
  if ( !v16 )
    v8 = &byte_629120;
  if ( (unsigned __int8)sub_57B490(v8, this[1], (int)&v13) )
    *a3 += v13;
  else
    v5 = 0;
  v9 = v17;
  if ( !v17 )
    v9 = &byte_629120;
  if ( (unsigned __int8)sub_57B490(v9, this[1], (int)&v13) )
    *a3 += v13;
  else
    v5 = 0;
  v10 = v19;
  if ( !v19 )
    v10 = &byte_629120;
  if ( (unsigned __int8)sub_57B490(v10, this[1], (int)&v13) )
    *a3 += v13;
  else
    v5 = 0;
  v11 = v18;
  if ( !v18 )
    v11 = &byte_629120;
  if ( (unsigned __int8)sub_57B490(v11, this[1], (int)&v13) )
    *a3 += v13;
  else
    v5 = 0;
  if ( v19 )
    sub_5BE8AE(v19);
  if ( v18 )
    sub_5BE8AE(v18);
  if ( v17 )
    sub_5BE8AE(v17);
  if ( v16 )
    sub_5BE8AE(v16);
  if ( v15 )
    sub_5BE8AE(v15);
  if ( v14[0] )
    sub_5BE8AE(v14[0]);
  sub_430670(v22);
  if ( v21 )
    sub_5BE8AE(v21);
  return v5;
}
