int __thiscall sub_418DB0(int this)
{
  int v3; // ecx

  if ( dword_7688A0 && *(_BYTE *)(this + 8) )
  {
    if ( *(_BYTE *)(this + 16) )
    {
      sub_418E20();
      return 0;
    }
    if ( flt_7678BC > 0.0 && byte_75CBB8 != 1 )
    {
      v3 = *(_DWORD *)(this + 12);
      if ( v3 )
      {
        (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 24))(v3);
        if ( !(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 12) + 8))(*(_DWORD *)(this + 12)) )
          sub_58DC50(0);
      }
    }
  }
  return 0;
}
