int *__cdecl sub_592787(int *a1)
{
  int v1; // esi
  int v2; // ebx
  _DWORD *v3; // eax
  _DWORD *v4; // edi
  int v6; // eax
  int *v7; // ecx
  int v8; // eax
  int v9; // esi
  int v10; // edx
  int *v11; // edi
  int v12; // esi
  int v13; // eax
  _DWORD *i; // ebx
  int v15; // edx
  int v16; // eax
  int v17; // esi

  v1 = *a1;
  v2 = 0;
  v3 = sub_58E0C7();
  v4 = v3;
  if ( v1 < 0 )
    return 0;
  if ( v3[16] || (v6 = sub_58A935(36), v4[16] = v6, v7 = (int *)&unk_8D4080, v6) )
    v7 = (int *)v4[16];
  v8 = v1 / 126230400;
  v9 = v1 % 126230400;
  v10 = 4 * v8 + 70;
  if ( v9 >= 31536000 )
  {
    v9 -= 31536000;
    v10 = 4 * v8 + 71;
    if ( v9 >= 31536000 )
    {
      v9 -= 31536000;
      v10 = 4 * v8 + 72;
      if ( v9 < 31622400 )
      {
        v2 = 1;
      }
      else
      {
        v10 = 4 * v8 + 73;
        v9 -= 31622400;
      }
    }
  }
  v7[5] = v10;
  v11 = dword_5E9AD4;
  v7[7] = v9 / 86400;
  v12 = v9 % 86400;
  if ( !v2 )
    v11 = dword_5E9B08;
  v13 = 1;
  for ( i = v11 + 1; *i < v7[7]; ++i )
    ++v13;
  v15 = v7[7];
  v16 = v13 - 1;
  v7[4] = v16;
  v7[3] = v15 - v11[v16];
  v7[6] = (*a1 / 86400 + 4) % 7;
  v7[2] = v12 / 3600;
  v17 = v12 % 3600;
  v7[1] = v17 / 60;
  v7[8] = 0;
  *v7 = v17 % 60;
  return v7;
}
