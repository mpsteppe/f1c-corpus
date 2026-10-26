int __thiscall sub_54130E(_DWORD *this)
{
  _DWORD *v1; // ebx
  _DWORD *v2; // eax
  _DWORD *v3; // ecx
  char *v5; // edx
  char *v6; // ebx
  unsigned int v7; // [esp+8h] [ebp-10h]
  unsigned int i; // [esp+Ch] [ebp-Ch]
  _DWORD *v9; // [esp+10h] [ebp-8h]
  unsigned int v10; // [esp+14h] [ebp-4h]

  v1 = this;
  v2 = (_DWORD *)this[1];
  v3 = (_DWORD *)*this;
  v9 = v1;
  if ( v2[1] != v3[1] )
    return -2147467259;
  if ( v3[4] )
    return -2147467259;
  if ( v2[1046] != v3[1046] )
    return -2147467259;
  v7 = v2[1047];
  if ( v7 != v3[1047] || v2[1048] != v3[1048] )
    return -2147467259;
  if ( !v2[3] )
    return sub_5401AB(v1);
  if ( v2[5] && v2 + 12 != v3 + 12 && memcmp(v2 + 12, v3 + 12, 0x400u) )
    return -2147467259;
  v10 = 0;
  if ( v2[1048] )
  {
    while ( 1 )
    {
      v5 = (char *)(v2[6] + v10 * v2[1045]);
      v6 = (char *)(*(_DWORD *)(*v9 + 24) + v10 * *(_DWORD *)(*v1 + 4180));
      for ( i = 0; i < v7; v7 = v2[1047] )
      {
        qmemcpy(v5, v6, v2[1049]);
        v2 = (_DWORD *)v9[1];
        v6 += *(_DWORD *)(*v9 + 4176);
        v5 += v2[1044];
        ++i;
      }
      ++v10;
      v2 = (_DWORD *)v9[1];
      if ( v10 >= v2[1048] )
        break;
      v1 = v9;
    }
  }
  return 0;
}
