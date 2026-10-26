int __thiscall sub_5518A0(_DWORD *this, char **a2, const char *a3, char a4)
{
  _DWORD *v4; // esi
  int v5; // edi
  _DWORD *v6; // eax
  char *v7; // ebp
  int v9; // eax
  int i; // eax

  v4 = this;
  v5 = 0;
  v6 = (_DWORD *)OperatorNewNhMallocWrapper(52);
  if ( v6 )
    v7 = (char *)StructZeroInitWithUnitVector(v6);
  else
    v7 = 0;
  if ( sub_5508A0(v7, a3) )
  {
    if ( v7 )
    {
      EmptyStub_7470(v7);
      FreeWrapper_7bcf(v7);
    }
    if ( a2 )
      *a2 = 0;
    return -1;
  }
  else if ( (a4 & 1) != 0 || (v5 = v4[70]) == 0 )
  {
LABEL_15:
    v9 = v4[70];
    if ( v9 )
    {
      v5 = v4[70];
      for ( i = *(_DWORD *)(v9 + 48); i; i = *(_DWORD *)(i + 48) )
        v5 = i;
      *(_DWORD *)(v5 + 48) = v7;
    }
    else
    {
      v4[70] = v7;
    }
    *((_DWORD *)v7 + 11) = v5;
    *((_DWORD *)v7 + 12) = 0;
    if ( a2 )
      *a2 = v7;
    return 0;
  }
  else
  {
    while ( strcmp((const char *)(v5 + 28), v7 + 28) )
    {
      v5 = *(_DWORD *)(v5 + 48);
      if ( !v5 )
      {
        v4 = this;
        goto LABEL_15;
      }
    }
    CallWrapperReturning0();
    if ( v7 )
    {
      EmptyStub_7470(v7);
      FreeWrapper_7bcf(v7);
    }
    if ( a2 )
      *a2 = (char *)v5;
    return -2;
  }
}
