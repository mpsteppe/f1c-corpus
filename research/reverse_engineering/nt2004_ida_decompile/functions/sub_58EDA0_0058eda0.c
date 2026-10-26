int __cdecl sub_58EDA0(int a1, int a2, int *a3, int a4)
{
  int v4; // edx
  int v5; // eax
  int v6; // ebp
  int v8; // edi
  unsigned int v9; // esi
  int v10; // eax
  int v11; // ecx
  int v12; // ebx
  _DWORD *i; // [esp+10h] [ebp-10h]
  int v14; // [esp+14h] [ebp-Ch] BYREF
  int v15; // [esp+18h] [ebp-8h] BYREF
  int v16; // [esp+1Ch] [ebp-4h]

  v4 = a2;
  v5 = *(char *)(a2 + 4);
  v6 = 1;
  v16 = v5;
  if ( v5 > 4 )
    return 0;
  v8 = 0;
  if ( v5 > 0 )
  {
    for ( i = (_DWORD *)(a2 + 20); ; ++i )
    {
      v6 = 0;
      v9 = *(unsigned __int8 *)(v8 + a4);
      if ( v9 >= 0x20 )
        return v6;
      v10 = 1 << *(_BYTE *)(v8 + a4);
      v11 = *(unsigned __int8 *)(v8 + v4 + 8);
      if ( (v10 & *i) == 0 )
        return v6;
      if ( !*(_BYTE *)(v8 + v4 + 8) || v11 == 254 )
        goto LABEL_17;
      if ( v11 != 255 )
        break;
      v12 = *(unsigned __int8 *)(v8 + v4 + 16);
      if ( (v12 & 0x80u) == 0 )
      {
        v14 = *a3;
        if ( !sub_58D680((int)&v14, &v15) || v9 != *(unsigned __int8 *)(v15 + v12) )
          return v6;
        v4 = a2;
        v6 = 1;
      }
      else
      {
        if ( (v10
            & *(_DWORD *)((((*(unsigned __int8 *)(a1 + 4) >> 2) + 3) & 0xFFFFFFFC)
                        + a1
                        + ((4 * *(unsigned __int8 *)(a1 + 6) + 3) & 0xFFFFFFFC)
                        + 4 * (v12 & 0x7F)
                        + 8)) == 0 )
          return v6;
        v4 = a2;
        v6 = 1;
      }
LABEL_18:
      if ( ++v8 >= v16 )
        return v6;
    }
    if ( (v10 & a3[v11]) == 0 )
      return v6;
LABEL_17:
    v6 = 1;
    goto LABEL_18;
  }
  return v6;
}
