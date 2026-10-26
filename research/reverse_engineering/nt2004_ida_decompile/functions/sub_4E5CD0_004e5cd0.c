char __thiscall sub_4E5CD0(int *this)
{
  _DWORD *v2; // eax
  _DWORD *v3; // esi
  _DWORD *v4; // eax

  if ( sub_4E5CB0(this) == 2 )
    sub_4E5120(this);
  v2 = operator new(0x7904u);
  if ( v2 )
    v3 = sub_4E3DE0(v2);
  else
    v3 = 0;
  sub_4E4250((int)v3);
  if ( v3 )
  {
    v4 = operator new(0xCu);
    if ( v4 )
    {
      *v4 = v3;
      v4[1] = 0;
      *((_BYTE *)v4 + 8) = 1;
    }
    else
    {
      v4 = 0;
    }
    if ( !*this )
    {
      *this = (int)v4;
      this[2] = (int)v4;
      this[1] = (int)v4;
      ++this[3];
      return 0;
    }
    *(_DWORD *)(this[1] + 4) = v4;
    this[1] = (int)v4;
    ++this[3];
  }
  return 0;
}
