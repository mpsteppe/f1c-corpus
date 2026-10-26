int __thiscall sub_4A0590(void *this)
{
  int v1; // esi
  int result; // eax
  int v4; // eax
  int v5; // eax

  v1 = dword_7C56A4;
  result = 1;
  switch ( dword_7C56A4 )
  {
    case 1:
      v4 = 2;
      goto LABEL_8;
    case 2:
      v4 = 3;
      goto LABEL_8;
    case 3:
      v4 = 4;
      goto LABEL_8;
    case 4:
      v4 = 5;
      goto LABEL_8;
    case 5:
      v4 = 6;
      goto LABEL_8;
    case 6:
      v4 = 7;
LABEL_8:
      sub_42CF10(&dword_7C569C, v4);
      if ( dword_7D0410 != 4 )
        return 0;
      v5 = sub_4C2850(&unk_7D2DB0);
      if ( !v5 )
        return 0;
      if ( v1 == 7 )
      {
        sub_4A09A0(this);
        return 0;
      }
      else
      {
        sub_4C15A0(v5);
        return 0;
      }
    default:
      return result;
  }
}
