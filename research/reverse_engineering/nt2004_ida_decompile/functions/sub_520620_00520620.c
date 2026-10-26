void __thiscall sub_520620(char *this, int a2, int a3, char *String2)
{
  double *v4; // esi
  double *v5; // ebx
  double *v6; // ebp

  v4 = (double *)&this[24 * a3];
  v5 = v4 + 2;
  v6 = v4 + 1;
  if ( sub_578450(String2, (int)v4, (int)(v4 + 1), (int)(v4 + 2), 0) )
  {
    switch ( a3 )
    {
      case 0:
        if ( *v4 > 0.0 && dword_75CBA8 != 5 )
        {
          if ( sub_500F90(&unk_7D7920, 1, aDDevNascar2004_25, 398) )
            sub_500FE0((int)&unk_7D7920, aXForceAppliedW);
        }
        break;
      case 1:
        if ( *v4 < 0.0 && dword_75CBA8 != 5 && sub_500F90(&unk_7D7920, 1, aDDevNascar2004_25, 403) )
          sub_500FE0((int)&unk_7D7920, aXForceAppliedW_0);
        break;
      case 2:
        if ( *v6 > 0.0 && dword_75CBA8 != 5 && sub_500F90(&unk_7D7920, 1, aDDevNascar2004_25, 408) )
          sub_500FE0((int)&unk_7D7920, aYForceAppliedW);
        break;
      case 3:
        if ( *v6 < 0.0 && dword_75CBA8 != 5 && sub_500F90(&unk_7D7920, 1, aDDevNascar2004_25, 413) )
          sub_500FE0((int)&unk_7D7920, aYForceAppliedW_0);
        break;
      case 4:
        if ( *v5 > 0.0 && dword_75CBA8 != 5 && sub_500F90(&unk_7D7920, 1, aDDevNascar2004_25, 418) )
          sub_500FE0((int)&unk_7D7920, aZForceAppliedW);
        break;
      case 5:
        if ( *v5 < 0.0 && dword_75CBA8 != 5 && sub_500F90(&unk_7D7920, 1, aDDevNascar2004_25, 423) )
          sub_500FE0((int)&unk_7D7920, aZForceAppliedW_0);
        break;
      default:
        return;
    }
  }
}
