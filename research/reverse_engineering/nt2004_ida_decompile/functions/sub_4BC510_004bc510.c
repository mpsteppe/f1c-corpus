char __thiscall sub_4BC510(_BYTE *this, int a2)
{
  _DWORD *v3; // eax

  LOBYTE(v3) = this[16];
  if ( (_BYTE)v3 && a2 )
  {
    v3 = operator new(0xCu);
    if ( v3 )
    {
      *v3 = a2;
      v3[1] = 0;
      *((_BYTE *)v3 + 8) = 0;
    }
    else
    {
      v3 = 0;
    }
    if ( *(_DWORD *)this )
    {
      *(_DWORD *)(*((_DWORD *)this + 1) + 4) = v3;
      *((_DWORD *)this + 1) = v3;
      ++*((_DWORD *)this + 3);
    }
    else
    {
      *(_DWORD *)this = v3;
      *((_DWORD *)this + 2) = v3;
      *((_DWORD *)this + 1) = v3;
      v3 = (_DWORD *)(*((_DWORD *)this + 3) + 1);
      *((_DWORD *)this + 3) = v3;
    }
  }
  return (char)v3;
}
