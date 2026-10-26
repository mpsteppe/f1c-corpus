int __thiscall sub_5F7B60(_DWORD *this, int a2, unsigned int a3)
{
  _DWORD *v3; // ecx
  _DWORD *v5; // edi
  int v6; // eax
  _DWORD *v7; // edi
  int v8; // eax
  int v9; // [esp-4h] [ebp-Ch]

  if ( a3 >= 8 )
    return 0;
  if ( !a2 )
  {
    v9 = a3;
    v3 = this + 135;
    return sub_5F6B50(v3, v9);
  }
  if ( a2 != 1 )
  {
    if ( a2 == 2 )
    {
      v7 = this + 135;
      v8 = sub_5F6B50(this + 135, a3);
      v9 = a3;
      v3 = v7;
      if ( !*(_DWORD *)(v8 + 372) )
        return sub_5F6B50(v3, v9);
      return *(_DWORD *)(sub_5F6B50(v7, a3) + 372);
    }
    return 0;
  }
  v5 = this + 135;
  v6 = sub_5F6B50(this + 135, a3);
  v9 = a3;
  v3 = v5;
  if ( !*(_DWORD *)(v6 + 368) )
    return sub_5F6B50(v3, v9);
  return *(_DWORD *)(sub_5F6B50(v5, a3) + 368);
}
