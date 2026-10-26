int __thiscall sub_4A3860(void *this)
{
  void *v3; // [esp-8h] [ebp-Ch]

  if ( (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090, 13) )
  {
    v3 = this;
    sub_4A0FF0();
  }
  if ( (*(int (__thiscall **)(int, int, void *))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090, 14, v3) )
    sub_4A0FF0();
  return 0;
}
