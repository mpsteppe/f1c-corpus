// f1c  0x0051a794  size=234
char __cdecl sub_51A794(unsigned __int8 **a1, int a2, int a3, int a4)
{
  unsigned __int8 *v4; // ebx
  unsigned __int8 *v5; // edi
  unsigned __int8 **v6; // eax
  int v7; // ecx
  unsigned __int8 **v8; // eax
  unsigned __int8 *v9; // ecx

  v4 = a1[1];
  v5 = *a1;
  while ( 1 )
  {
    if ( a3 >= 25 )
    {
LABEL_20:
      a1[3] = (unsigned __int8 *)a2;
      a1[6] = (unsigned __int8 *)a3;
      *a1 = v5;
      a1[1] = v4;
      return 1;
    }
    if ( a1[2] )
      goto LABEL_14;
    if ( !v4 )
      break;
LABEL_6:
    v7 = *v5;
    --v4;
    ++v5;
    if ( v7 != 255 )
      goto LABEL_18;
    do
    {
      if ( !v4 )
      {
        if ( !(*(unsigned __int8 (__cdecl **)(unsigned __int8 *))(*((_DWORD *)a1[7] + 5) + 12))(a1[7]) )
          return 0;
        v8 = (unsigned __int8 **)*((_DWORD *)a1[7] + 5);
        v5 = *v8;
        v4 = v8[1];
      }
      v9 = (unsigned __int8 *)*v5;
      --v4;
      ++v5;
    }
    while ( v9 == (unsigned __int8 *)255 );
    if ( !v9 )
    {
      v7 = 255;
      goto LABEL_18;
    }
    a1[2] = v9;
LABEL_14:
    if ( a3 >= a4 )
      goto LABEL_20;
    if ( !*a1[8] )
    {
      *(_DWORD *)(*(_DWORD *)a1[7] + 20) = 113;
      (*(void (__cdecl **)(unsigned __int8 *, int))(*(_DWORD *)a1[7] + 4))(a1[7], -1);
      *a1[8] = 1;
    }
    v7 = 0;
LABEL_18:
    a3 += 8;
    a2 = v7 | (a2 << 8);
  }
  if ( (*(unsigned __int8 (__cdecl **)(unsigned __int8 *))(*((_DWORD *)a1[7] + 5) + 12))(a1[7]) )
  {
    v6 = (unsigned __int8 **)*((_DWORD *)a1[7] + 5);
    v5 = *v6;
    v4 = v6[1];
    goto LABEL_6;
  }
  return 0;
}
