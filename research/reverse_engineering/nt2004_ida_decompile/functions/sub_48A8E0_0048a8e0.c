int __thiscall sub_48A8E0(_DWORD *this)
{
  switch ( this[67] )
  {
    case '\'':
      sub_4BA060(&byte_766124);
      dword_608F60 = -1;
      sub_465910(dword_764D70, 0);
      break;
    case '(':
LABEL_6:
      sub_419200((int)byte_6292D0);
      sub_4B9790(1);
      return -1;
    case ')':
      if ( byte_75CBC8 )
      {
        sub_49D430(aBacktomainsetu);
        return -1;
      }
      goto LABEL_6;
  }
  return 0;
}
