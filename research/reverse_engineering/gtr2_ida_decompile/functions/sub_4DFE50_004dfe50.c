void __usercall sub_4DFE50(int a1@<ecx>, int a2@<esi>)
{
  int v3; // eax
  const CHAR *v4; // edx
  int v5; // esi
  int v6; // ebx
  double v7; // st7
  int v8; // ebp
  float v9; // eax
  int v10; // [esp-30h] [ebp-40h]
  int v11; // [esp-2Ch] [ebp-3Ch]
  int v12; // [esp-28h] [ebp-38h]

  if ( *(float *)(a1 + 272) > 0.2 && *(_DWORD *)(a1 + 388) )
  {
    v3 = sub_4DFAA0((_DWORD *)a1, a1, a2, 0, 0);
    if ( !v3 )
      goto LABEL_8;
    v4 = *(const CHAR **)(a1 + 372);
    if ( !v4 )
      v4 = WindowName;
    if ( (*(unsigned __int8 (__thiscall **)(int, const CHAR *))(*(_DWORD *)v3 + 108))(v3, v4) == 1 )
      v5 = *(_DWORD *)(a1 + 388);
    else
LABEL_8:
      v5 = sub_4DF040((void *)a1, (int)"NoDropIcon0000.bmp");
    if ( v5 )
    {
      v6 = *(_DWORD *)(v5 + 20);
      v7 = (double)*(int *)dword_903EB8 * 0.00125;
      v8 = *(_DWORD *)(v5 + 24);
      v12 = (unsigned __int64)((double)*(int *)(a1 + 92) * v7);
      v11 = (unsigned __int64)((double)(*(_DWORD *)(a1 + 88) - v6) * v7);
      v10 = sub_4DDFE0();
      v9 = COERCE_FLOAT(sub_4E3DF0(v5));
      sub_4DDC20(
        v9,
        0,
        0,
        v6,
        v8,
        v10,
        v11,
        v12,
        (unsigned __int64)((double)v6 * v7),
        (unsigned __int64)((double)v8 * v7),
        -1,
        -1,
        -1,
        -1);
    }
  }
}
