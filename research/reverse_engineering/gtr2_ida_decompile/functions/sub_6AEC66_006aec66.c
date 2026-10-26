int __thiscall sub_6AEC66(_DWORD *this, int a2)
{
  int result; // eax
  char *v4; // eax

  if ( this[86] )
    return 0;
  result = sub_6CB0CE(&byte_200001F);
  if ( result >= 0 )
  {
    v4 = *(char **)(a2 + 60);
    if ( v4 == (char *)0x200000 )
    {
      result = sub_6C9357(-1879048192);
    }
    else if ( v4 == (char *)0x400000 )
    {
      result = sub_6C9357(-1610612736);
    }
    else
    {
      if ( v4 != &byte_800000 )
      {
        sub_686791((int)this, 0, 4814, "internal error: unexpected Alias on texture declaration");
        return -2147467259;
      }
      result = sub_6C9357(-1744830464);
    }
    if ( result >= 0 )
    {
      result = (*(int (__thiscall **)(_DWORD *, unsigned int, int, _DWORD))(*this + 100))(
                 this,
                 *(_DWORD *)(a2 + 12) & 0x7FF | 0xA0000800,
                 983040,
                 0);
      if ( result >= 0 )
      {
        result = sub_6C64E6(this);
        if ( result >= 0 )
          return 0;
      }
    }
  }
  return result;
}
