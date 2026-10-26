void __stdcall sub_54B470(int a1, int a2)
{
  if ( byte_B722CC )
  {
    sub_615860("ARCADE");
  }
  else
  {
    if ( dword_B72338 )
    {
      if ( dword_B72338 == 1 )
        sub_615860(&off_71EE7C);
      else
        sub_615860(&unk_71EE80);
    }
    else
    {
      sub_615860("ARC");
    }
    switch ( *(_DWORD *)dword_B72314 )
    {
      case 1:
        sub_615A50("PRACT");
        break;
      case 2:
        sub_615A50("QUICK");
        break;
      case 3:
        if ( byte_B722E4 )
          sub_615A50(&off_71EE64);
        else
          sub_615A50("WEEKEND");
        break;
      case 4:
        sub_615A50("CHAMP");
        break;
      case 5:
        sub_615A50("MULTI");
        break;
      case 7:
        sub_615A50("TIMET");
        break;
      default:
        break;
    }
  }
  sub_632041(a1, a2, "Game%s%s", WindowName, ".sve");
}
