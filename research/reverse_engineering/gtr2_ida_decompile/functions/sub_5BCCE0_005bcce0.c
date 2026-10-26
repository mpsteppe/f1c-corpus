void __thiscall sub_5BCCE0(void *this)
{
  int i; // esi
  int v3; // [esp+0h] [ebp-8h]

  for ( i = 0; i < *(_DWORD *)this; ++i )
    (**(void (__thiscall ***)(int, _DWORD))(*((_DWORD *)this + 2) + 8 * i))(*((_DWORD *)this + 2) + 8 * i, 0);
  sub_4F14D0(v3);
  sub_5A8D10(*((void **)this + 2));
}
