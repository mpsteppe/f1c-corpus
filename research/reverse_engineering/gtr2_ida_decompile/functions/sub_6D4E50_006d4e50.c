int __userpurge sub_6D4E50@<eax>(int a1@<eax>, int a2@<ecx>, int *a3, __int16 *a4, _DWORD *a5)
{
  int v6; // eax
  int v7; // esi
  int v8; // eax
  int v9; // edi
  int *v10; // ebx
  int result; // eax
  unsigned int v12; // ecx
  int v13; // eax
  int v14; // esi
  int v15; // eax

  v6 = *a4 - a2;
  if ( v6 < 0 )
    v6 = a2 - *a4;
  v7 = 0;
  if ( v6 )
  {
    do
    {
      v6 >>= 1;
      ++v7;
    }
    while ( v6 );
    if ( v7 > 11 )
    {
      v8 = *a3;
      *(_DWORD *)(v8 + 20) = 6;
      (*(void (__stdcall **)(int *))v8)(a3);
    }
  }
  ++*(_DWORD *)(a1 + 4 * v7);
  v9 = 0;
  v10 = (int *)&unk_744A74;
  do
  {
    result = a4[*v10];
    if ( a4[*v10] )
    {
      if ( v9 > 15 )
      {
        v12 = ((unsigned int)(v9 - 16) >> 4) + 1;
        v9 += -16 * v12;
        a5[240] += v12;
      }
      if ( result < 0 )
        result = -result;
      v13 = result >> 1;
      v14 = 1;
      if ( v13 )
      {
        do
        {
          v13 >>= 1;
          ++v14;
        }
        while ( v13 );
        if ( v14 > 10 )
        {
          v15 = *a3;
          *(_DWORD *)(v15 + 20) = 6;
          (*(void (__stdcall **)(int *))v15)(a3);
        }
      }
      result = (int)&a5[16 * v9 + v14];
      ++*(_DWORD *)result;
      v9 = 0;
    }
    else
    {
      ++v9;
    }
    ++v10;
  }
  while ( (int)v10 < (int)dword_744B70 );
  if ( v9 > 0 )
  {
    result = (int)a5;
    ++*a5;
  }
  return result;
}
