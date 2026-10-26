int __thiscall sub_6A32C7(_DWORD *this, int a2)
{
  unsigned int v2; // edx
  unsigned int v3; // edi
  int v4; // esi
  _DWORD *v5; // eax
  unsigned int v6; // ecx
  int v7; // ecx
  int v8; // edx
  unsigned int i; // eax
  _DWORD v11[4]; // [esp+Ch] [ebp-14h] BYREF
  int v12; // [esp+1Ch] [ebp-4h]

  v12 = 0;
  memset(v11, 0, sizeof(v11));
  v2 = *(_DWORD *)(a2 + 12);
  v3 = 0;
  if ( v2 )
  {
    v4 = this[5];
    v5 = *(_DWORD **)(a2 + 16);
    while ( 1 )
    {
      v6 = *(_DWORD *)(*(_DWORD *)(v4 + 4 * *v5) + 16);
      if ( v6 > 3 )
        return 0;
      ++v3;
      ++v5;
      v11[v6] = 1;
      if ( v3 >= v2 )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    v7 = 0;
    v8 = 1;
    for ( i = 0; i < 3; ++i )
    {
      if ( v11[i] )
        v8 = 0;
      else
        v7 = 1;
    }
    if ( v7 )
    {
      if ( !v8 )
        return 1;
    }
    return v12;
  }
}
