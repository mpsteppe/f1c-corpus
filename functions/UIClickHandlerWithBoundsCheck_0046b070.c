int __thiscall sub_46B070(void *this)
{
  int v2; // eax
  int v3; // eax
  int v5; // [esp+4h] [ebp-8h] BYREF
  _BYTE v6[4]; // [esp+8h] [ebp-4h] BYREF

  dword_7CFF84 = 0;
  DualFieldRead(&v5, v6);
  v2 = (*(int (__thiscall **)(void *))(*(_DWORD *)this + 24))(this);
  if ( v5 < v2 )
  {
    v3 = (*(int (__thiscall **)(void *))(*(_DWORD *)this + 32))(this);
    if ( v5 < v3 )
      KeyBindingUIPressKeyOrController(1, 1);
  }
  return 0;
}
