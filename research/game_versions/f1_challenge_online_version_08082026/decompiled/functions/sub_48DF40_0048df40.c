int __thiscall sub_48DF40(_DWORD *this)
{
  int v2; // eax
  int v3; // edi
  int v4; // eax
  int v6; // [esp+8h] [ebp-8h] BYREF
  int v7; // [esp+Ch] [ebp-4h] BYREF

  sub_498880(&v6, &v7);
  v2 = sub_486720(this);
  v3 = v2;
  if ( v2 && v2 != 6 && v2 != 7 )
    goto LABEL_9;
  v4 = v6;
  if ( v6 > this[67] && v6 < this[68] && v7 > this[71] && v7 < this[72] )
  {
    (*(void (__thiscall **)(_DWORD *, int))(*this + 64))(this, 3);
LABEL_9:
    v4 = v6;
  }
  if ( (v3 == 3 || v3 == 8 || v3 == 9) && v4 > this[67] && v4 < this[68] && v7 > this[71] && v7 < this[72] )
    (*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 64))(this, 0);
  return 0;
}
