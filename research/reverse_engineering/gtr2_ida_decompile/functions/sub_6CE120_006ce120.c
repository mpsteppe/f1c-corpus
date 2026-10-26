_DWORD *__usercall sub_6CE120@<eax>(_DWORD *result@<eax>)
{
  _DWORD *v1; // ebx
  int v2; // edi
  unsigned int v3; // esi
  int v4; // ecx
  int v5; // edx
  int v6; // ecx
  _DWORD *v7; // eax
  int v8; // [esp+4h] [ebp-14h]
  _DWORD *v9; // [esp+8h] [ebp-10h]
  int v10; // [esp+Ch] [ebp-Ch]
  int v11; // [esp+10h] [ebp-8h]
  int v12; // [esp+14h] [ebp-4h]

  v10 = result[107];
  v12 = 0;
  v8 = result[9];
  if ( v8 > 0 )
  {
    v11 = result[80];
    v9 = (_DWORD *)(result[107] + 4 * *(_DWORD *)(result[107] + 64) + 56);
    v1 = (_DWORD *)(result[55] + 12);
    do
    {
      v2 = *v1 * v1[6] / v11;
      v3 = v1[8] % (unsigned int)(*v1 * v1[6]);
      if ( !v3 )
        v3 = *v1 * v1[6];
      v4 = v12;
      if ( !v12 )
        *(_DWORD *)(v10 + 72) = (int)(v3 - 1) / v2 + 1;
      v5 = 2 * v2;
      if ( 2 * v2 > 0 )
      {
        v6 = *(_DWORD *)(*v9 + 4 * v12) + 4 * v3;
        v7 = (_DWORD *)v6;
        do
        {
          *v7++ = *(_DWORD *)(v6 - 4);
          --v5;
        }
        while ( v5 );
        v4 = v12;
      }
      result = (_DWORD *)v8;
      v1 += 21;
      v12 = v4 + 1;
    }
    while ( v4 + 1 < v8 );
  }
  return result;
}
