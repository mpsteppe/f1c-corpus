void __thiscall sub_643D90(void *this)
{
  int i; // edi
  void (__thiscall ***v3)(_DWORD, int); // ecx
  int v4; // [esp+0h] [ebp-8h]

  for ( i = 0; i < *(_DWORD *)this; ++i )
  {
    v3 = *(void (__thiscall ****)(_DWORD, int))(*((_DWORD *)this + 2) + 4 * i);
    if ( v3 )
      (**v3)(v3, 1);
  }
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  sub_4F14D0(v4);
  sub_5A8D10(*((void **)this + 2));
  *((_DWORD *)this + 2) = 0;
}
