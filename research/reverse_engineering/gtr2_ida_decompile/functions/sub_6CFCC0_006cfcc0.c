int __stdcall sub_6CFCC0(int *a1)
{
  _DWORD *v2; // edi
  int v3; // eax
  unsigned int v4; // ebx
  int result; // eax
  _DWORD *v6; // eax
  _DWORD *v7; // edx
  _DWORD *v8; // ecx
  int v9; // edx
  _DWORD *v10; // [esp+Ch] [ebp-8h]
  int v11; // [esp+10h] [ebp-4h]
  int *v12; // [esp+1Ch] [ebp+8h]
  int v13; // [esp+1Ch] [ebp+8h]

  v2 = (_DWORD *)a1[112];
  if ( a1[101] || a1[102] != 63 || a1[103] || a1[104] )
  {
    v3 = *a1;
    *(_DWORD *)(v3 + 20) = 122;
    (*(void (__stdcall **)(int *, int))(v3 + 4))(a1, -1);
  }
  v11 = 0;
  if ( a1[83] > 0 )
  {
    v10 = v2 + 5;
    v12 = a1 + 84;
    do
    {
      v4 = *(_DWORD *)(*v12 + 24);
      sub_6CF3E0(a1, 1u, *(_DWORD *)(*v12 + 20), &v2[*(_DWORD *)(*v12 + 20) + 10]);
      sub_6CF3E0(a1, 0, v4, &v2[v4 + 14]);
      *v10++ = 0;
      ++v11;
      ++v12;
    }
    while ( v11 < a1[83] );
  }
  result = 0;
  if ( a1[90] > 0 )
  {
    v6 = v2 + 48;
    v7 = a1 + 91;
    v13 = a1[90];
    do
    {
      v8 = (_DWORD *)a1[*v7 + 84];
      *(v6 - 30) = v2[v8[5] + 10];
      *(v6 - 20) = v2[v8[6] + 14];
      if ( v8[12] )
      {
        *(v6 - 10) = 1;
        *v6 = v8[9] > 1;
      }
      else
      {
        *v6 = 0;
        *(v6 - 10) = 0;
      }
      ++v7;
      ++v6;
      --v13;
    }
    while ( v13 );
    result = 0;
  }
  v9 = a1[70];
  v2[4] = 0;
  v2[3] = 0;
  v2[2] = 0;
  v2[9] = v9;
  return result;
}
