// f1c  0x0045b200  size=228
int __stdcall sub_45B200(HINSTANCE a1, int a2, int a3, int a4)
{
  dword_7C56B0 = 1065571320;
  dword_7C56B4 = (int)aIlya1011;
  byte_7C56AD = 0;
  dword_7C56A0 = 3;
  hinst = a1;
  sub_423070(a3);
  sub_421CD0((const CHAR **)dword_5EC3D0, 0);
  sub_4D7A00(a3);
  sub_4A0D50(a3);
  sub_4B17F0(a3);
  sub_463160(a3);
  if ( !sub_42D370((char *)&dword_7C569C) && !sub_42D5D0(&dword_7C569C) )
  {
LABEL_3:
    if ( !sub_42D6B0(&dword_7C569C) )
    {
      while ( !sub_42D7A0(&dword_7C569C) )
      {
        if ( sub_42D8A0(&dword_7C569C) )
        {
          sub_42DA30(&dword_7C569C);
          if ( !sub_42D5D0(&dword_7C569C) )
            goto LABEL_3;
          break;
        }
      }
    }
  }
  sub_42DB20(&dword_7C569C);
  return 0;
}
