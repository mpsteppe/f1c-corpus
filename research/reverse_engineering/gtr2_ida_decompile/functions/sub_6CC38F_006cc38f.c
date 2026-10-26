int __thiscall sub_6CC38F(_DWORD *this, int a2)
{
  int result; // eax
  int v4; // [esp+4h] [ebp-8h] BYREF
  int v5; // [esp+8h] [ebp-4h] BYREF

  result = sub_6CB0CE((int)this, 40);
  if ( result >= 0 )
  {
    result = (*(int (__thiscall **)(_DWORD *, _DWORD, int *, int *))(*this + 116))(
               this,
               *(_DWORD *)(this[5] + 4 * **(_DWORD **)(this[64] + 8)),
               &v4,
               &v5);
    if ( result >= 0 )
    {
      result = (*(int (__thiscall **)(_DWORD *, int, void *, int))(*this + 104))(
                 this,
                 v4 | (a2 != 0 ? 0xD000000 : 0),
                 &unk_E40000,
                 v5);
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
