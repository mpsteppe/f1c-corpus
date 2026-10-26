int __thiscall sub_545930(_DWORD *this, int a2, int a3)
{
  int v4; // esi
  int v5; // eax
  int v6; // edx
  int v7; // ecx
  int v8; // edx
  int i; // ecx
  int j; // ecx

  v4 = 0;
  if ( OperatorNewNhMallocWrapper(56) )
    v5 = ObjectInitWithParameterLinking(a2, this[86]);
  else
    v5 = 0;
  v6 = this[87];
  if ( v6 )
  {
    if ( a3 && (v7 = *(_DWORD *)(a3 + 560)) != 0 )
    {
      v8 = *(_DWORD *)(v7 + 44);
      if ( !v8 )
      {
        *(_DWORD *)(v7 + 44) = v5;
        goto LABEL_16;
      }
      v4 = *(_DWORD *)(v7 + 44);
      for ( i = *(_DWORD *)(v8 + 52); i; i = *(_DWORD *)(i + 52) )
        v4 = i;
    }
    else
    {
      v4 = this[87];
      for ( j = *(_DWORD *)(v6 + 52); j; j = *(_DWORD *)(j + 52) )
        v4 = j;
    }
    *(_DWORD *)(v4 + 52) = v5;
    goto LABEL_16;
  }
  this[87] = v5;
LABEL_16:
  *(_DWORD *)(v5 + 48) = v4;
  *(_DWORD *)(v5 + 52) = 0;
  ++this[86];
  return 0;
}

