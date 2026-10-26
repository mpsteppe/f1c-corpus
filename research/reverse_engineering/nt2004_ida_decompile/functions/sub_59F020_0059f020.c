int __thiscall sub_59F020(_DWORD *this, int a2, int a3)
{
  int v4; // eax
  int v5; // eax
  int v6; // ecx
  int j; // eax
  int v9; // esi
  _DWORD *v10; // eax
  _DWORD *v11; // esi
  _DWORD *v12; // edi
  int i; // eax
  _DWORD *v14; // eax
  int v15; // [esp-8h] [ebp-Ch]

  if ( operator new(0x3Cu) )
    v4 = sub_5B8210(a2, 0);
  else
    v4 = 0;
  v15 = this[141];
  this[140] = v4;
  if ( sub_5B8280(v15, 0) )
    return 0;
  if ( !a3 )
  {
    v9 = *(_DWORD *)(this[141] + 360);
    if ( v9 )
    {
      for ( i = *(_DWORD *)(v9 + 4); i; i = *(_DWORD *)(i + 4) )
        v9 = i;
      v14 = operator new(8u);
      v12 = v14;
      if ( v14 )
      {
        sub_5918B0(v14);
        *v12 = 0;
        v12[1] = 0;
      }
      else
      {
        v12 = 0;
      }
      *(_DWORD *)(v9 + 4) = v12;
    }
    else
    {
      v10 = operator new(8u);
      v11 = v10;
      if ( v10 )
      {
        sub_5918B0(v10);
        *v11 = 0;
        v11[1] = 0;
      }
      else
      {
        v11 = 0;
      }
      *(_DWORD *)(this[141] + 360) = v11;
      v12 = *(_DWORD **)(this[141] + 360);
    }
    *v12 = this[140];
    ++*(_DWORD *)(this[141] + 356);
    return 0;
  }
  v5 = *(_DWORD *)(a3 + 560);
  if ( !v5 )
    return 0;
  v6 = *(_DWORD *)(v5 + 48);
  if ( v6 )
  {
    for ( j = *(_DWORD *)(v6 + 56); j; j = *(_DWORD *)(j + 56) )
      v6 = j;
    *(_DWORD *)(v6 + 56) = this[140];
    return 0;
  }
  else
  {
    *(_DWORD *)(v5 + 48) = this[140];
    return 0;
  }
}
