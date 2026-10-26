int __thiscall sub_4B4D40(_DWORD **this)
{
  char *v2; // eax
  int v4; // [esp+10h] [ebp-104h]
  char v5[256]; // [esp+14h] [ebp-100h] BYREF

  if ( sub_4CE170(this) )
  {
    sub_4ABA50();
    if ( (*(int (__thiscall **)(_DWORD *, int))(*this[12] + 28))(this[12], 52) )
    {
      sub_4D0AC0(v4);
      v2 = sub_41D840(&byte_91CC38, "Reading Setup Information...");
      sub_4D93B0(v2, 0, 0, 0, 0, 0, -1, -1, -1, -1);
    }
    CGarageOnline::GetFileDetails((CGarageOnline *)dword_B6CBB4, v5);
  }
  return 0;
}
