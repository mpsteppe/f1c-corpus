int __thiscall sub_4D0510(void *this)
{
  _BYTE v3[4]; // [esp+14h] [ebp-8h] BYREF
  _BYTE v4[4]; // [esp+18h] [ebp-4h] BYREF

  sub_4DE540(v3, v4);
  (*(void (__thiscall **)(void *))(*(_DWORD *)this + 4))(this);
  (*(void (__thiscall **)(void *))(*(_DWORD *)this + 8))(this);
  (*(void (__thiscall **)(void *))(*(_DWORD *)this + 16))(this);
  return off_16C9340();
}
