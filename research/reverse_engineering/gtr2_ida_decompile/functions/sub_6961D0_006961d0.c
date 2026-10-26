int __thiscall sub_6961D0(_DWORD *this, int a2, int a3)
{
  int v4; // eax
  int result; // eax
  int v6; // edi
  int i; // eax
  int v8; // ecx
  int v9; // eax
  int v10; // ecx
  _DWORD *v11; // eax
  _DWORD *v12; // edi
  int v13; // eax

  v4 = this[4];
  if ( v4 )
  {
    v6 = *(_DWORD *)(a2 + 20) + 16;
    for ( i = sub_694E5E(v6, v4); i; i = *(_DWORD *)(i + 12) )
    {
      v8 = *(_DWORD *)(i + 8);
      if ( !*(_DWORD *)(v8 + 44) && (*(_DWORD *)(a2 + 16) != 2 || *(_DWORD *)(v8 + 16) != 2) )
      {
        if ( !a3 || !sub_67ECA2((int (__thiscall ***)(_DWORD, int))a2, *(_DWORD *)(i + 8)) )
        {
          sub_694B97((int)this, v6, 3003, "redefinition of '%s'", *(_DWORD *)(v6 + 8));
          return -2147467259;
        }
        return 0;
      }
    }
    v9 = this[4];
    v10 = *(_DWORD *)(v9 + 32);
    if ( v10 && *(_DWORD *)(v9 + 16) == 3 && *(_DWORD *)(v10 + 16) == 2 && sub_694E5E(v6, *(_DWORD *)(v9 + 32)) )
    {
      sub_694B97((int)this, v6, 3036, "redefinition of formal parameter '%s'", *(_DWORD *)(v6 + 8));
      return -2147467259;
    }
    v11 = (_DWORD *)sub_65B229(20);
    v12 = 0;
    if ( v11 )
      v12 = sub_67ED1B(v11, 0, 0, (int)"Stmts");
    if ( !v12 )
      return -2147024882;
    v13 = sub_67ECC3(a2);
    v12[2] = v13;
    if ( !v13 )
      return -2147024882;
    *(_DWORD *)(v13 + 32) = *(_DWORD *)(this[4] + 20);
    *(_DWORD *)(a2 + 32) = *(_DWORD *)(v12[2] + 32);
    *(_DWORD *)(v12[2] + 36) = this[19];
    *(_DWORD *)(a2 + 36) = *(_DWORD *)(v12[2] + 36);
    ++this[19];
    v12[3] = *(_DWORD *)(this[4] + 24);
    *(_DWORD *)(this[4] + 24) = v12;
    result = sub_694D2B(this[4], v12[2]);
    if ( result >= 0 )
      return 0;
  }
  else
  {
    sub_694C3A(this, 0, 0, "internal error: scope missing");
    return -2147467259;
  }
  return result;
}
