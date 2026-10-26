int __thiscall sub_486200(int this)
{
  sub_46FAE0((_DWORD *)this, 0);
  *(_BYTE *)(this + 864) = 0;
  *(_DWORD *)this = &off_5DABD0;
  *(_DWORD *)(this + 840) = &dword_768498;
  *(_DWORD *)(this + 844) = 1;
  *(_DWORD *)(this + 848) = 0;
  *(_DWORD *)(this + 852) = 1;
  *(_DWORD *)(this + 856) = 1;
  *(_DWORD *)(this + 860) = 336;
  sub_49D5B0(aPlayer, -1);
  sub_49D5B0(aPoleSitter, -1);
  return this;
}
