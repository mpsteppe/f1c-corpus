void __thiscall sub_4F8240(_DWORD *this, _DWORD *a2)
{
  _DWORD *v3; // ecx
  int v4; // [esp+0h] [ebp-10h]

  if ( a2 )
  {
    if ( (dword_75CBAC & 1) != 0 || !sub_4EED40(a2) )
    {
      if ( (unsigned __int8)sub_4F8410(a2) )
      {
        sub_4F81A0(this, a2);
        sub_4F7F20(this, a2, 3.4028235e38);
      }
    }
    else
    {
      v3 = (_DWORD *)dword_7D3C44;
      if ( dword_79FC40 < 1023 )
      {
        ++dword_79FC40;
        dword_7D3C44 += 208;
      }
      *(float *)&v4 = dbl_7DA9D0;
      sub_4D0D00(v3, 4, 45, 0, a2[6312], v4, 3);
    }
  }
}
