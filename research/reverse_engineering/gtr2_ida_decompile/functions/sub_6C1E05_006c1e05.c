int __thiscall sub_6C1E05(int this)
{
  int *v2; // ecx
  int v3; // eax
  int result; // eax
  int v5; // ecx
  int v6; // edx
  int v7; // ebx
  _DWORD *v8; // ecx
  int v9; // edi
  int v10; // edx
  int v11; // ebx
  int v12; // edi
  int v13; // eax
  double *v14; // eax
  _BYTE v15[32]; // [esp+14h] [ebp-FCh] BYREF
  _DWORD v16[32]; // [esp+34h] [ebp-DCh]
  char v17[64]; // [esp+B4h] [ebp-5Ch] BYREF
  int v18[4]; // [esp+F4h] [ebp-1Ch] BYREF
  int v19; // [esp+104h] [ebp-Ch]
  double *v20; // [esp+108h] [ebp-8h]
  unsigned int v21; // [esp+10Ch] [ebp-4h] BYREF

  v2 = *(int **)(this + 256);
  v3 = *v2 & 0xFFFFF;
  v21 = 0;
  v18[0] = 0;
  v18[1] = 1;
  v18[2] = 2;
  v18[3] = 3;
  if ( v3 != 1 )
    return 1;
  result = sub_6BB35B((_DWORD *)this, v2, dword_7463F0, v17, &v21, (int)v15, v18, 1u, 1);
  if ( result == 1 )
  {
    result = sub_6BB35B((_DWORD *)this, *(int **)(this + 256), dword_746450, v17, &v21, (int)v15, v18, 1u, 1);
    if ( result == 1 )
    {
      result = sub_6BB35B((_DWORD *)this, *(int **)(this + 256), dword_7464B0, v17, &v21, (int)v15, v18, 1u, 1);
      if ( result == 1 )
        result = sub_6BB35B((_DWORD *)this, *(int **)(this + 256), dword_746510, v17, &v21, (int)v15, v18, 1u, 1);
    }
  }
  if ( !result )
  {
    v5 = *(_DWORD *)(*(_DWORD *)(this + 256) + 8);
    v6 = *(_DWORD *)(this + 20);
    v21 = 0;
    v7 = *(_DWORD *)(this + 16);
    v8 = (_DWORD *)(v5 + 4);
    do
    {
      v9 = *(_DWORD *)(v6 + 4 * *v8);
      if ( (*(_BYTE *)(*(_DWORD *)(v7 + 4 * *(_DWORD *)(v9 + 4)) + 5) & 1) == 0
        || *(double *)(v9 + 32) != 0.0
        || *(_DWORD *)(v9 + 8) != -1 )
      {
        return 1;
      }
      ++v21;
      ++v8;
    }
    while ( !v21 );
    v10 = *(_DWORD *)(v6 + 4 * v16[0]);
    v21 = 0;
    if ( *(_DWORD *)(v10 + 8) == -1 )
      v21 = (*(_BYTE *)(*(_DWORD *)(v7 + 4 * *(_DWORD *)(v10 + 4)) + 5) & 1) != 0;
    v11 = 0;
    while ( 1 )
    {
      *(_DWORD *)(v11 * 4 + *(_DWORD *)(*(_DWORD *)(this + 256) + 8)) = *(_DWORD *)&v15[v11 * 4 + 16];
      v12 = *(_DWORD *)(*(_DWORD *)(this + 20) + 4 * v16[v11]);
      v13 = sub_681AAA(
              (void *)this,
              *(_DWORD *)(v12 + 4),
              *(_DWORD *)(v12 + 12),
              *(_DWORD *)(v12 + 16),
              *(double *)(v12 + 32));
      v19 = v13;
      if ( v13 == -1 )
        break;
      v20 = *(double **)(*(_DWORD *)(this + 20) + 4 * v13);
      sub_6815D6(v20, v12);
      v14 = v20;
      if ( v21 )
      {
        v20[4] = v20[4] * -1.0;
      }
      else
      {
        if ( *((_DWORD *)v20 + 14) == -1 )
          *((_DWORD *)v20 + 14) = v16[v11];
        *((_DWORD *)v14 + 15) ^= 0x80000u;
      }
      *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 256) + 8) + v11 * 4 + 4) = v19;
      if ( (unsigned int)++v11 >= 1 )
        return 0;
    }
    return -2147024882;
  }
  return result;
}
