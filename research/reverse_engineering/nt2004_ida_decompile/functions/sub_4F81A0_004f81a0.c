void __thiscall sub_4F81A0(_DWORD *this, _DWORD *a2)
{
  _DWORD *v3; // ecx
  int v4; // [esp+0h] [ebp-10h]

  if ( a2 )
  {
    if ( (dword_75CBAC & 1) == 0 && sub_4EED40(a2) )
    {
      if ( dword_79FC40 >= 1023 )
      {
        v3 = (_DWORD *)dword_7D3C44;
      }
      else
      {
        ++dword_79FC40;
        v3 = (_DWORD *)dword_7D3C44;
        dword_7D3C44 += 208;
      }
      *(float *)&v4 = dbl_7DA9D0;
      sub_4D0D00(v3, 4, 44, 0, a2[6312], v4, 3);
    }
    if ( !sub_4F7DF0(this + 98, a2[6312]) )
      sub_4F7DF0(this + 1, a2[6312]);
  }
}
