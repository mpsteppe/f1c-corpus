int __thiscall sub_6CCD65(_DWORD *this)
{
  int result; // eax
  int v3; // [esp+4h] [ebp-8h] BYREF
  int v4; // [esp+8h] [ebp-4h] BYREF

  result = sub_6CB0CE((int)this, 38);
  if ( result >= 0 )
  {
    result = (*(int (__thiscall **)(_DWORD *, _DWORD, int *, int *))(*this + 116))(
               this,
               *(_DWORD *)(this[5] + 4 * **(_DWORD **)(this[64] + 8)),
               &v3,
               &v4);
    if ( result >= 0 )
    {
      result = (*(int (__thiscall **)(_DWORD *, int, void *, int))(*this + 104))(this, v3, &unk_E40000, v4);
      if ( result >= 0 )
      {
        result = (*(int (__thiscall **)(_DWORD *))(*this + 96))(this);
        if ( result >= 0 )
        {
          result = sub_6C64E6(this);
          if ( result >= 0 )
            return 0;
        }
      }
    }
  }
  return result;
}
