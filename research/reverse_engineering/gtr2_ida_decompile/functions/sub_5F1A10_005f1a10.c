int __thiscall sub_5F1A10(_DWORD *this, int a2)
{
  int v4; // [esp+14h] [ebp-Ch] BYREF
  int v5; // [esp+18h] [ebp-8h] BYREF
  _BYTE v6[4]; // [esp+1Ch] [ebp-4h] BYREF

  (*(void (__thiscall **)(_DWORD *, int *, _DWORD, _DWORD))(*this + 168))(this, &v4, this[2356], 0);
  (*(void (__thiscall **)(_DWORD *, int, int *, _BYTE *))(*this + 172))(this, v4, &v5, v6);
  if ( a2 != 1 )
    return 255;
  if ( v5 == 32 )
    return (*(int (__thiscall **)(_DWORD *))(*this + 288))(this);
  if ( v5 != 16 )
    return 255;
  return (*(int (__thiscall **)(_DWORD *))(*this + 284))(this);
}
