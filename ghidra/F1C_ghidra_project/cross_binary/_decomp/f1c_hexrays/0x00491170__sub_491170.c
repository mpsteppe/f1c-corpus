// f1c  0x00491170  size=260
char __stdcall sub_491170(int a1, int a2)
{
  __int16 **v2; // eax
  __int16 *v3; // esi
  int v4; // eax
  __int16 **v5; // eax
  _DWORD *v7; // esi
  char v8; // bl
  _DWORD *v9; // edi
  void *v10; // ecx

  v2 = *(__int16 ***)a1;
  *(_DWORD *)(a1 + 8) = *(_DWORD *)a1;
  if ( !v2 )
    return 0;
  v3 = *v2;
  if ( !*v2 )
    return 0;
  while ( 1 )
  {
    if ( (unsigned __int8)sub_4915A0(*v3, v3[1], v3[2], v3[3]) )
      return 1;
    if ( (unsigned __int8)sub_491680(*v3, v3[1], v3[2], v3[3]) )
      break;
    v4 = *(_DWORD *)(a1 + 8);
    if ( v4 )
    {
      v5 = *(__int16 ***)(v4 + 4);
      *(_DWORD *)(a1 + 8) = v5;
      if ( v5 )
      {
        v3 = *v5;
        if ( *v5 )
          continue;
      }
    }
    return 0;
  }
  v7 = (_DWORD *)sub_491350(*v3, v3[1], v3[2], v3[3]);
  v8 = 1;
  v9 = v7;
  if ( v7 )
  {
    while ( (unsigned __int8)sub_491170(a1, v9) )
    {
      v9 = (_DWORD *)v9[3];
      if ( !v9 )
      {
        v8 = 1;
        goto LABEL_15;
      }
    }
    v8 = 0;
    do
    {
LABEL_15:
      v10 = v7;
      v7 = (_DWORD *)v7[3];
      sub_490AA0(v10);
    }
    while ( v7 );
  }
  return v8;
}
