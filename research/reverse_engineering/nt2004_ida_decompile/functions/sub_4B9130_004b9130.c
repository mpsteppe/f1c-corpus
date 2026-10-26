int __thiscall sub_4B9130(void *this, char a2)
{
  switch ( *(_DWORD *)dword_7689CC )
  {
    case 1:
    case 2:
    case 3:
    case 8:
      sub_4BA5F0(1);
      if ( dword_7655CC )
        sub_4AD720((_DWORD *)dword_7655CC, a2003SlplyrMoni, 1);
      break;
    case 4:
      sub_4BA5F0(1);
      if ( dword_7655CC )
        sub_4AD720((_DWORD *)dword_7655CC, a2003Championsh, 1);
      break;
    case 5:
    case 7:
      sub_4BA5F0(1);
      break;
    case 6:
      sub_4BA5F0(0);
      break;
    default:
      break;
  }
  sub_4BA060(this);
  if ( a2 && dword_7655CC )
    sub_4AC980((_DWORD *)dword_7655CC);
  sub_4F01D0(1);
  sub_419110(byte_6292D0);
  sub_430DC0(&byte_75CBC8);
  return 0;
}
