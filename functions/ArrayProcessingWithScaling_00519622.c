int __usercall sub_519622@<eax>(_DWORD *a1@<esi>)
{
  int result; // eax
  int v2; // ebx
  _DWORD *v3; // edi
  int v4; // eax
  _DWORD *v5; // edx
  int v6; // [esp+4h] [ebp-Ch]
  int v7; // [esp+4h] [ebp-Ch]
  unsigned int v8; // [esp+8h] [ebp-8h]
  int v9; // [esp+Ch] [ebp-4h]

  v9 = 0;
  result = a1[49];
  v2 = a1[96];
  if ( (int)a1[8] > 0 )
  {
    v3 = (_DWORD *)(result + 12);
    do
    {
      v6 = *v3 * v3[6] / a1[69];
      v8 = v3[8] % (unsigned int)(*v3 * v3[6]);
      if ( !v8 )
        v8 = *v3 * v3[6];
      if ( !v9 )
        *(_DWORD *)(v2 + 72) = (int)(v8 - 1) / v6 + 1;
      if ( 2 * v6 > 0 )
      {
        v4 = *(_DWORD *)(*(_DWORD *)(v2 + 4 * *(_DWORD *)(v2 + 64) + 56) + 4 * v9) + 4 * v8;
        v5 = (_DWORD *)v4;
        v7 = 2 * v6;
        do
        {
          *v5++ = *(_DWORD *)(v4 - 4);
          --v7;
        }
        while ( v7 );
      }
      result = ++v9;
      v3 += 21;
    }
    while ( v9 < a1[8] );
  }
  return result;
}
