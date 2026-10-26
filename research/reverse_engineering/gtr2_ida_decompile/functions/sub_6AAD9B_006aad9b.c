int __thiscall sub_6AAD9B(_DWORD *this)
{
  int v2; // edi
  int v3; // eax
  int result; // eax
  _DWORD *v5; // edi
  int v6; // [esp+Ch] [ebp-10h] BYREF
  int v7; // [esp+10h] [ebp-Ch] BYREF
  int v8; // [esp+14h] [ebp-8h]
  int v9; // [esp+18h] [ebp-4h] BYREF

  v2 = *(_DWORD *)this[64] & 0xFFFFF;
  v3 = (unsigned __int16)this[50];
  v8 = v2;
  if ( v3 == 260 )
  {
    result = sub_6CB0CE(66);
    if ( result < 0 )
      return result;
    result = (*(int (__thiscall **)(_DWORD *, _DWORD, int *, _DWORD, _DWORD))(*this + 108))(
               this,
               *(_DWORD *)(this[5] + 4 * **(_DWORD **)(this[64] + 16)),
               &v9,
               0,
               0);
    if ( result < 0 )
      return result;
    result = (*(int (__thiscall **)(_DWORD *, int, int, _DWORD))(*this + 100))(this, v9, 983040, 0);
    if ( result < 0 )
      return result;
    v5 = (_DWORD *)(*(_DWORD *)(this[64] + 8) + 4 * v2);
    result = (*(int (__thiscall **)(_DWORD *, _DWORD, int *, int *))(*this + 116))(
               this,
               *(_DWORD *)(this[5] + 4 * *v5),
               &v9,
               &v7);
    if ( result < 0 )
      return result;
    result = (*(int (__thiscall **)(_DWORD *, _DWORD *, int, int, int *))(*this + 120))(this, v5, v8, 983040, &v6);
    if ( result < 0 )
      return result;
    result = (*(int (__thiscall **)(_DWORD *, int, int, int))(*this + 104))(this, v9, v6, v7);
    if ( result < 0 )
      return result;
    result = (*(int (__thiscall **)(_DWORD *))(*this + 96))(this);
    if ( result < 0 )
      return result;
    result = sub_6C64E6(this);
    if ( result < 0 )
      return result;
    return 0;
  }
  result = sub_6CB0CE(66);
  if ( result >= 0 )
  {
    result = (*(int (__thiscall **)(_DWORD *, _DWORD, int *, _DWORD, _DWORD))(*this + 108))(
               this,
               *(_DWORD *)(this[5] + 4 * **(_DWORD **)(this[64] + 16)),
               &v9,
               0,
               0);
    if ( result >= 0 )
    {
      result = (*(int (__thiscall **)(_DWORD *, int, int, _DWORD))(*this + 100))(this, v9, 983040, 0);
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
