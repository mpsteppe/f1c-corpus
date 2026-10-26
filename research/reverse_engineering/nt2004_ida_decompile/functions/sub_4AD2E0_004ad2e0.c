int __thiscall sub_4AD2E0(_DWORD *this, int a2)
{
  _DWORD *v3; // eax

  ++this[11];
  sub_4AEF70(this);
  sub_4AF100(1);
  if ( a2 )
  {
    v3 = operator new(0x10u);
    if ( v3 )
    {
      *v3 = a2;
      v3[1] = 0;
      v3[2] = 0;
      *((_BYTE *)v3 + 12) = 1;
    }
    else
    {
      v3 = 0;
    }
    if ( !this[1] )
    {
      this[1] = v3;
      this[3] = v3;
      this[2] = v3;
      ++this[4];
      return a2;
    }
    *(_DWORD *)(this[2] + 4) = v3;
    v3[2] = this[2];
    this[2] = v3;
    ++this[4];
  }
  return a2;
}
