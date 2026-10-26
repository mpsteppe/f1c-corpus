void __stdcall sub_41BB40(int a1, int a2)
{
  if ( dword_7688A0
    && flt_7678BC != 0.0
    && byte_6292D8
    && sub_4633A0(&unk_764D70) != 1
    && (unsigned __int8)sub_4EED40(a1) )
  {
    if ( a2 < 0 )
    {
      sub_419550(0);
      if ( byte_7D758C )
      {
        sub_4F83B0(a1);
        sub_419550(0);
      }
    }
    else
    {
      sub_419550(dword_632210[6326 * a2]);
    }
  }
}
