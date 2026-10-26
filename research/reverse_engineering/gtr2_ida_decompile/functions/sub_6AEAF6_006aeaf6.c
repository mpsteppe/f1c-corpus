int __thiscall sub_6AEAF6(_DWORD *this)
{
  int *v2; // eax
  int v3; // esi
  int *v4; // ebx
  int v5; // edx
  char *v6; // ecx
  int v7; // esi
  int v8; // eax
  int v9; // edx
  int v10; // ecx
  int result; // eax
  int v12; // eax
  int v13; // ecx
  unsigned int v14; // edx
  int v15; // ecx
  _DWORD v16[4]; // [esp+Ch] [ebp-34h] BYREF
  _DWORD v17[4]; // [esp+1Ch] [ebp-24h] BYREF
  int i; // [esp+2Ch] [ebp-14h]
  char *v19; // [esp+30h] [ebp-10h]
  int *v20; // [esp+34h] [ebp-Ch]
  unsigned int v21; // [esp+38h] [ebp-8h]
  unsigned int v22; // [esp+3Ch] [ebp-4h]

  v2 = (int *)this[64];
  v3 = *v2;
  v4 = (int *)v2[2];
  v5 = *v4;
  v22 = v2[3];
  v6 = (char *)v2[4];
  v7 = v3 & 0xFFFFF;
  v20 = &v4[v7];
  v8 = this[5];
  v21 = *(_DWORD *)(v8 + 4 * v5);
  v9 = *v20;
  v19 = v6;
  v10 = *(_DWORD *)(v8 + 4 * *(_DWORD *)v6);
  i = *(_DWORD *)(v8 + 4 * v9);
  if ( (*(_DWORD *)(v10 + 4) != *(_DWORD *)(v21 + 4) || *(_DWORD *)(v10 + 12) != *(_DWORD *)(v21 + 12))
    && (*(_DWORD *)(v10 + 4) != *(_DWORD *)(i + 4) || *(_DWORD *)(v10 + 12) != *(_DWORD *)(i + 12)) )
  {
    return sub_6CB29C(10, v19, v22, v4, v20, 0, v7, 0, 0, 0, 0);
  }
  result = (*(int (__thiscall **)(_DWORD *, _DWORD, _DWORD *, int, _DWORD, _DWORD))(*this + 128))(
             this,
             this[63],
             v16,
             4,
             0,
             0);
  if ( result >= 0 )
  {
    v21 = 0;
    if ( v22 )
    {
      v12 = this[5];
      v13 = v19 - (char *)v17;
      for ( i = v19 - (char *)v17; ; v13 = i )
      {
        v14 = v21;
        v15 = v16[*(_DWORD *)(*(_DWORD *)(v12 + 4 * *(_DWORD *)((char *)&v17[v21++] + v13)) + 16)];
        v17[v14] = v15;
        if ( v21 >= v22 )
          break;
      }
    }
    sub_6CB29C(2, v17, v22, v4, v20, 0, v7, 0, &dword_1000000, 0, 0);
    return sub_6CB29C(88, v19, v22, v17, v20, v4, v7, 0, 0, 0, 0);
  }
  return result;
}
