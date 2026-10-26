int __thiscall sub_4757A0(void *this)
{
  int v3; // [esp+4h] [ebp-8h] BYREF
  int v4; // [esp+8h] [ebp-4h] BYREF

  v4 = 0;
  v3 = 0;
  sub_4AE870(&v4, &v3);
  if ( sub_4A50D0(this) && (unsigned __int8)sub_4A4680(v4, v3) )
  {
    sub_475980(this);
    (*(void (__thiscall **)(void *, _DWORD))(*(_DWORD *)this + 40))(this, 0);
  }
  return 0;
}
