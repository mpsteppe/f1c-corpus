int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
  dword_75CBBC = 1065369993;
  dword_75CBC0 = (int)aIjhLam;
  byte_75CBB9 = 0;
  dword_75CBAC = 3;
  hinst = hInstance;
  sub_41E800(lpCmdLine);
  sub_41D2B0((int)&unk_62A060, 0);
  sub_500F40(lpCmdLine);
  sub_4BA610(lpCmdLine);
  sub_4CE990(lpCmdLine);
  sub_464C60(&unk_764D70, lpCmdLine);
  if ( !sub_42FCC0(&dword_75CBA8) && !sub_42FDA0(&dword_75CBA8) )
  {
LABEL_3:
    if ( !sub_42FE80(&dword_75CBA8) )
    {
      while ( !sub_42FFB0(&dword_75CBA8) )
      {
        if ( sub_4300E0(&dword_75CBA8) )
        {
          sub_4302B0(&dword_75CBA8);
          if ( !sub_42FDA0(&dword_75CBA8) )
            goto LABEL_3;
          break;
        }
      }
    }
  }
  sub_4303B0(&dword_75CBA8);
  return 0;
}
