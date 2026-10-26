void __thiscall sub_5BE700(void **this)
{
  void (__thiscall ***v2)(_DWORD, int); // ecx
  bool v3; // zf
  void (__thiscall ***v4)(_DWORD, int); // ecx
  int v5; // [esp+0h] [ebp-18h]
  int v6; // [esp+0h] [ebp-18h]
  int v7; // [esp+0h] [ebp-18h]

  sub_4F14D0(v5);
  sub_5A8D10(this[11]);
  if ( *this )
  {
    do
    {
      v2 = (void (__thiscall ***)(_DWORD, int))*((_DWORD *)this[2] + (_DWORD)*this - 1);
      if ( v2 )
        (**v2)(v2, 1);
      v3 = *this == (void *)1;
      *this = (char *)*this - 1;
    }
    while ( !v3 );
  }
  if ( this[3] )
  {
    do
    {
      v4 = (void (__thiscall ***)(_DWORD, int))*((_DWORD *)this[5] + (_DWORD)this[3] - 1);
      if ( v4 )
        (**v4)(v4, 1);
      v3 = this[3] == (void *)1;
      this[3] = (char *)this[3] - 1;
    }
    while ( !v3 );
  }
  *((_BYTE *)this + 33) = 0;
  sub_4F14D0(v6);
  sub_5A8D10(this[5]);
  sub_4F14D0(v7);
  sub_5A8D10(this[2]);
}
