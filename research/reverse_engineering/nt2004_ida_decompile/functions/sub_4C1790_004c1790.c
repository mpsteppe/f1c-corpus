void __thiscall sub_4C1790(float *this, int a2)
{
  int v3; // edi

  if ( a2 != *((_DWORD *)this + 207) )
  {
    *((_DWORD *)this + 207) = a2;
    this[208] = dbl_7DA9D0;
    if ( !sub_463490(dword_764D70) || sub_4634D0(dword_764D70) || *(int *)(*(_DWORD *)this + 25248) < 48 )
    {
      v3 = dword_7D3C44;
      if ( dword_79FC40 < 1023 )
      {
        ++dword_79FC40;
        dword_7D3C44 += 208;
      }
      sub_4D0D00(6, 1, 1, *((_DWORD *)this + 1), *((_DWORD *)this + 208), 0);
      *(_BYTE *)(v3 + 8) = a2;
    }
  }
}
