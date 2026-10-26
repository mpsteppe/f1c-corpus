int __thiscall sub_6CC45D(_DWORD *this)
{
  int result; // eax
  unsigned int v3; // eax
  unsigned int v4; // ecx
  int v5; // [esp+4h] [ebp-18h] BYREF
  int v6; // [esp+8h] [ebp-14h] BYREF
  int v7; // [esp+Ch] [ebp-10h] BYREF
  int v8; // [esp+10h] [ebp-Ch] BYREF
  int v9; // [esp+14h] [ebp-8h] BYREF
  unsigned int v10; // [esp+18h] [ebp-4h] BYREF

  result = sub_6CB0CE((int)this, 1);
  if ( result >= 0 )
  {
    result = (*(int (__thiscall **)(_DWORD *, _DWORD, unsigned int *, int *, int *))(*this + 108))(
               this,
               *(_DWORD *)(this[5] + 4 * **(_DWORD **)(this[64] + 16)),
               &v10,
               &v5,
               &v6);
    if ( result >= 0 )
    {
      result = (*(int (__thiscall **)(_DWORD *, _DWORD, _DWORD, int *, int))(*this + 112))(
                 this,
                 *(_DWORD *)(this[64] + 16),
                 *(_DWORD *)(this[64] + 12),
                 &v9,
                 v6);
      if ( result >= 0 )
      {
        result = (*(int (__thiscall **)(_DWORD *, unsigned int, int, int))(*this + 100))(this, v10, v9, v5);
        if ( result >= 0 )
        {
          result = (*(int (__thiscall **)(_DWORD *, _DWORD, unsigned int *, int *))(*this + 116))(
                     this,
                     *(_DWORD *)(this[5] + 4 * **(_DWORD **)(this[64] + 8)),
                     &v10,
                     &v8);
          if ( result >= 0 )
          {
            result = (*(int (__thiscall **)(_DWORD *, _DWORD, _DWORD, int, int *))(*this + 120))(
                       this,
                       *(_DWORD *)(this[64] + 8),
                       *(_DWORD *)(this[64] + 12),
                       v9,
                       &v7);
            if ( result >= 0 )
            {
              v3 = v10;
              if ( (v10 & 0xB000000) != 0 )
              {
                v4 = v7 | 0xC000000;
                v3 = v10 & 0xF4FFFFFF;
              }
              else
              {
                v4 = (unsigned int)&dword_1000000 | v7;
              }
              result = (*(int (__thiscall **)(_DWORD *, unsigned int, unsigned int, int))(*this + 104))(
                         this,
                         v3,
                         v4,
                         v8);
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
  }
  return result;
}
