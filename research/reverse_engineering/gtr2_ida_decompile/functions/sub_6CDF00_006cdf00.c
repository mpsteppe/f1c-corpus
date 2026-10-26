_DWORD *__thiscall sub_6CDF00(_DWORD *this)
{
  _DWORD *result; // eax
  int v2; // edx
  int v3; // ebx
  _DWORD *v4; // ecx
  _DWORD *v5; // edx
  int v6; // esi
  int v7; // eax
  char *v8; // edx
  int v9; // edi
  _DWORD *v10; // ecx
  _DWORD *v11; // edx
  int v12; // esi
  _DWORD *v13; // esi
  _DWORD *v14; // edx
  int v15; // ebx
  char *v16; // ecx
  char *v17; // ecx
  bool v18; // zf
  int v19; // [esp+8h] [ebp-20h]
  int v20; // [esp+Ch] [ebp-1Ch]
  int v21; // [esp+10h] [ebp-18h]
  int v22; // [esp+14h] [ebp-14h]
  int v23; // [esp+14h] [ebp-14h]
  _DWORD *v24; // [esp+18h] [ebp-10h]
  int *v25; // [esp+1Ch] [ebp-Ch]
  _DWORD *v26; // [esp+20h] [ebp-8h]
  char *v27; // [esp+24h] [ebp-4h]

  result = (_DWORD *)this[107];
  v2 = this[55];
  v3 = this[80];
  v21 = v3;
  v20 = this[9];
  if ( v20 > 0 )
  {
    v4 = (_DWORD *)result[15];
    v25 = result + 2;
    v5 = (_DWORD *)(v2 + 12);
    v6 = result[14] - (_DWORD)v4;
    v24 = v5;
    v26 = v4;
    v19 = v6;
    while ( 1 )
    {
      v7 = *v5 * v5[6] / v3;
      v8 = *(char **)((char *)v4 + v6);
      v9 = *v25;
      v10 = (_DWORD *)*v4;
      v27 = v8;
      if ( v7 * (v3 + 2) > 0 )
      {
        v11 = v10;
        v22 = v7 * (v3 + 2);
        do
        {
          v12 = *(_DWORD *)((char *)v11 + v9 - (_DWORD)v10);
          *v11 = v12;
          *(_DWORD *)((char *)v11++ + v27 - (char *)v10) = v12;
          --v22;
        }
        while ( v22 );
        v8 = v27;
        v3 = v21;
      }
      if ( 2 * v7 > 0 )
      {
        v13 = &v10[v3 * v7];
        v14 = (_DWORD *)(v9 + 4 * v7 * (v3 - 2));
        v15 = v9 - (_DWORD)v10;
        v16 = (char *)v10 - v9;
        v23 = 2 * v7;
        do
        {
          *(_DWORD *)((char *)v14 + (_DWORD)v16) = *(_DWORD *)((char *)v13 + v15);
          *v13++ = *v14++;
          --v23;
        }
        while ( v23 );
        v8 = v27;
        v3 = v21;
      }
      if ( v7 > 0 )
      {
        v17 = &v8[-4 * v7];
        do
        {
          *(_DWORD *)v17 = *(_DWORD *)v8;
          v17 += 4;
          --v7;
        }
        while ( v7 );
      }
      result = (_DWORD *)(v20 - 1);
      v18 = v20 == 1;
      ++v26;
      ++v25;
      v24 += 21;
      --v20;
      if ( v18 )
        break;
      v6 = v19;
      v4 = v26;
      v5 = v24;
    }
  }
  return result;
}
