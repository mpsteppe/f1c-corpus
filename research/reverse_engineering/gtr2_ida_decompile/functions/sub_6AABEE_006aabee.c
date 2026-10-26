int __thiscall sub_6AABEE(_DWORD *this)
{
  int v2; // edi
  int result; // eax
  _DWORD *v4; // ebx
  int v5; // [esp+Ch] [ebp-Ch] BYREF
  int v6; // [esp+10h] [ebp-8h] BYREF
  int v7; // [esp+14h] [ebp-4h] BYREF

  v2 = *(_DWORD *)this[64] & 0xFFFFF;
  result = sub_6CB0CE(66);
  if ( result >= 0 )
  {
    result = (*(int (__thiscall **)(_DWORD *, _DWORD, int *, _DWORD, _DWORD))(*this + 108))(
               this,
               *(_DWORD *)(this[5] + 4 * **(_DWORD **)(this[64] + 16)),
               &v7,
               0,
               0);
    if ( result >= 0 )
    {
      result = (*(int (__thiscall **)(_DWORD *, int, int, _DWORD))(*this + 100))(this, v7, 983040, 0);
      if ( result >= 0 )
      {
        v4 = (_DWORD *)(*(_DWORD *)(this[64] + 8) + 4 * v2);
        result = (*(int (__thiscall **)(_DWORD *, _DWORD, int *, int *))(*this + 116))(
                   this,
                   *(_DWORD *)(this[5] + 4 * *v4),
                   &v7,
                   &v6);
        if ( result >= 0 )
        {
          result = (*(int (__thiscall **)(_DWORD *, _DWORD *, int, int, int *))(*this + 120))(this, v4, v2, 983040, &v5);
          if ( result >= 0 )
          {
            result = (*(int (__thiscall **)(_DWORD *, int, int, int))(*this + 104))(this, v7, v5 | 0x9000000, v6);
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
      }
    }
  }
  return result;
}
