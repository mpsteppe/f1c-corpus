int __thiscall sub_5D6B40(void *this)
{
  int v3; // [esp+0h] [ebp-18h]
  int v4; // [esp+0h] [ebp-18h]

  *(_DWORD *)this = &off_72B630;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  sub_4F14D0(v3);
  sub_5A8D10(*((void **)this + 5));
  *((_DWORD *)this + 5) = 0;
  sub_4F14D0(v4);
  sub_5A8D10(*((void **)this + 5));
  return ((int (__thiscall *)(void *))byte_5D1B70)(this);
}
