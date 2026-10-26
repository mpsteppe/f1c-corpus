int __thiscall sub_4CDC40(_BYTE *this)
{
  int v3; // [esp+4h] [ebp-8h] BYREF
  int v4; // [esp+8h] [ebp-4h] BYREF

  sub_4DE540(&v4, &v3);
  if ( this[100]
    || !(*(int (__thiscall **)(_BYTE *, int, int))(*(_DWORD *)this + 20))(this, v4, v3)
    || (*(int (__thiscall **)(_BYTE *))(*(_DWORD *)this + 148))(this) )
  {
    return -1;
  }
  sub_4CD5A0(this, 0);
  return 0;
}
