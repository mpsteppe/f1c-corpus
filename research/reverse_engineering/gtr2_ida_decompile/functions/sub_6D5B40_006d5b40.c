int __stdcall sub_6D5B40(_DWORD *a1, int a2)
{
  _DWORD *v3; // esi
  int *v4; // eax
  int v5; // ecx
  int v6; // edx
  int v7; // eax
  int i; // ebx
  _DWORD *v9; // eax
  int v10; // edi
  int v11; // ecx
  int v12; // edx
  int v14; // [esp+10h] [ebp+8h]

  v3 = (_DWORD *)a1[93];
  v14 = a1[84];
  v4 = (int *)a1[6];
  v5 = *v4;
  v6 = v4[1];
  v7 = a1[50];
  v3[4] = v5;
  v3[5] = v6;
  if ( v7 && !v3[17] )
    sub_6D56F0(v3, v3[18]);
  for ( i = 0; i < a1[70]; ++i )
    sub_6D5530((int)v3, **(__int16 **)(a2 + 4 * i) >> v14, 1);
  v9 = (_DWORD *)a1[6];
  v10 = a1[50];
  v11 = v3[5];
  *v9 = v3[4];
  v9[1] = v11;
  if ( v10 )
  {
    if ( !v3[17] )
    {
      v12 = ((unsigned __int8)v3[18] + 1) & 7;
      v3[17] = v10;
      v3[18] = v12;
    }
    --v3[17];
  }
  return 1;
}
