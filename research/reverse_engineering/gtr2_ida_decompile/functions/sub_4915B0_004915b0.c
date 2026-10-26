int __thiscall sub_4915B0(void *this)
{
  int v2; // eax
  int v4; // [esp+4h] [ebp-8h] BYREF
  _BYTE v5[4]; // [esp+8h] [ebp-4h] BYREF

  sub_4DE540(&v4, v5);
  v2 = (*(int (__thiscall **)(void *))(*(_DWORD *)this + 4))(this);
  if ( v4 < v2 )
    (*(void (__thiscall **)(void *))(*(_DWORD *)this + 12))(this);
  return 0;
}
