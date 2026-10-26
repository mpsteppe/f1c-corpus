int __stdcall sub_45AC60(_DWORD *a1)
{
  int v1; // edx
  int v2; // eax
  int v3; // ecx
  int v4; // eax
  _DWORD v6[3]; // [esp+10h] [ebp-2C0h]
  _DWORD v7[6]; // [esp+1Ch] [ebp-2B4h]
  double v8; // [esp+34h] [ebp-29Ch]
  double v9[3]; // [esp+3Ch] [ebp-294h] BYREF
  unsigned int v10; // [esp+54h] [ebp-27Ch]
  unsigned int v11; // [esp+58h] [ebp-278h]
  __int16 v12; // [esp+5Ch] [ebp-274h]
  char v13; // [esp+60h] [ebp-270h] BYREF
  char v14; // [esp+C8h] [ebp-208h] BYREF
  double v15; // [esp+E0h] [ebp-1F0h]
  char v16; // [esp+130h] [ebp-1A0h] BYREF
  char v17; // [esp+198h] [ebp-138h] BYREF
  double v18; // [esp+1B0h] [ebp-120h]
  char v19; // [esp+200h] [ebp-D0h] BYREF
  char v20; // [esp+268h] [ebp-68h] BYREF
  double v21; // [esp+280h] [ebp-50h]

  if ( (*(int (__thiscall **)(_DWORD *, double *, int))(*a1 + 28))(a1, v9, 34) == 34 )
  {
    sub_458700();
    v15 = v9[0];
    v7[1] = &v14;
    v18 = v9[1];
    v7[2] = &v16;
    v21 = v9[2];
    v7[4] = &v19;
    v7[5] = &v20;
    v7[0] = &v13;
    v7[3] = &v17;
    WORD1(v8) = v12;
    v6[0] = v10 & 0x1FFFFF;
    v6[1] = (v10 >> 21) + ((v11 & 0x3FF) << 11);
    v6[2] = v11 >> 10;
    v1 = 0;
    while ( 1 )
    {
      v2 = v6[v1];
      v3 = v7[2 * v1];
      if ( v2 < 0 || v2 >= a1[29] )
        break;
      v4 = a1[30] + 24 * v2;
      *(_DWORD *)v3 = *(_DWORD *)v4;
      *(double *)(v3 + 24) = *(double *)(v4 + 8);
      ++v1;
      *(_DWORD *)(v3 + 16) = *(_DWORD *)(v4 + 16);
      if ( v1 >= 3 )
        return sub_45A530();
    }
  }
  return -1;
}
