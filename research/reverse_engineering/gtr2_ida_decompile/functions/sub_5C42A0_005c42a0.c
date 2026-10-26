int __thiscall sub_5C42A0(void *this)
{
  void *v2; // edi
  void (__thiscall ***v3)(_DWORD, int); // ecx
  int v6; // [esp+0h] [ebp-14h]

  *(_DWORD *)this = &off_729DD4;
  if ( *((_DWORD *)this + 9) )
  {
    sub_5D2650();
    v2 = (void *)*((_DWORD *)this + 9);
    if ( v2 )
    {
      sub_5D1ED0(*((_DWORD *)this + 9));
      j__free(v2);
    }
    *((_DWORD *)this + 9) = 0;
  }
  if ( *((_DWORD *)this + 6) )
  {
    do
    {
      v3 = *(void (__thiscall ****)(_DWORD, int))(*((_DWORD *)this + 8) + 4 * *((_DWORD *)this + 6) - 4);
      if ( v3 )
        (**v3)(v3, 1);
    }
    while ( (*((_DWORD *)this + 6))-- != 1 );
  }
  sub_4F14D0(v6);
  sub_5A8D10(*((void **)this + 8));
  return sub_5D1740(this);
}
