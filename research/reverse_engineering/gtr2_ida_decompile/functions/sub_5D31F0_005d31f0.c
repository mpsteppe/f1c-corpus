void __thiscall sub_5D31F0(void *this)
{
  void (__thiscall ***v2)(_DWORD, int); // ecx
  int v3; // [esp+0h] [ebp-18h]
  int v4; // [esp+0h] [ebp-18h]

  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  sub_4F14D0(v3);
  sub_5A8D10(*((void **)this + 2));
  v2 = (void (__thiscall ***)(_DWORD, int))*((_DWORD *)this + 3);
  *((_DWORD *)this + 2) = 0;
  *((_BYTE *)this + 30) = 0;
  if ( v2 )
    (**v2)(v2, 1);
  sub_4F14D0(v4);
  sub_5A8D10(*((void **)this + 2));
}
