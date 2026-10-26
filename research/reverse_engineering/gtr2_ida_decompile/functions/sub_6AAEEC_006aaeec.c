int __thiscall sub_6AAEEC(_DWORD *this)
{
  int v2; // eax
  int v3; // edi
  int v4; // ebx
  int result; // eax
  _DWORD *v6; // edi
  _BYTE v7[4]; // [esp+Ch] [ebp-14h] BYREF
  int v8; // [esp+10h] [ebp-10h] BYREF
  int v9; // [esp+14h] [ebp-Ch] BYREF
  int v10; // [esp+18h] [ebp-8h] BYREF
  int v11; // [esp+1Ch] [ebp-4h] BYREF

  v2 = this[64];
  v3 = *(_DWORD *)(this[5] + 4 * **(_DWORD **)(v2 + 16));
  v4 = *(_DWORD *)v2 & 0xFFFFF;
  if ( (unsigned __int16)this[50] == 260 )
  {
    result = sub_6CB0CE(64);
    if ( result < 0 )
      return result;
    result = (*(int (__thiscall **)(_DWORD *, int, int *, _DWORD, int *))(*this + 108))(this, v3, &v11, 0, &v10);
    if ( result < 0 )
      return result;
    result = (*(int (__thiscall **)(_DWORD *, _DWORD, int, int *, int))(*this + 112))(
               this,
               *(_DWORD *)(this[64] + 16),
               v4,
               &v9,
               v10);
    if ( result < 0 )
      return result;
    result = (*(int (__thiscall **)(_DWORD *, int, int, _DWORD))(*this + 100))(this, v11, 458752, 0);
    if ( result < 0 )
      return result;
    v6 = *(_DWORD **)(this[64] + 8);
    result = (*(int (__thiscall **)(_DWORD *, _DWORD, int *, int *))(*this + 116))(
               this,
               *(_DWORD *)(this[5] + 4 * *v6),
               &v11,
               &v8);
    if ( result < 0 )
      return result;
    result = (*(int (__thiscall **)(_DWORD *, _DWORD *, int, int, _BYTE *))(*this + 120))(this, v6, v4, v9, v7);
    if ( result < 0 )
      return result;
    result = (*(int (__thiscall **)(_DWORD *, int, void *, int))(*this + 104))(this, v11, &unk_E40000, v8);
  }
  else
  {
    result = sub_6CB0CE(64);
    if ( result < 0 )
      return result;
    result = (*(int (__thiscall **)(_DWORD *, int, int *, _DWORD, int *))(*this + 108))(this, v3, &v11, 0, &v10);
    if ( result < 0 )
      return result;
    result = (*(int (__thiscall **)(_DWORD *, _DWORD, int, int *, int))(*this + 112))(
               this,
               *(_DWORD *)(this[64] + 16),
               v4,
               &v9,
               v10);
    if ( result < 0 )
      return result;
    result = (*(int (__thiscall **)(_DWORD *, int, int, _DWORD))(*this + 100))(this, v11, 983040, 0);
  }
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
  return result;
}
