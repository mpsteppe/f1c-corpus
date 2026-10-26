int __stdcall sub_485C10(int a1)
{
  int v1; // ecx
  bool v2; // cc
  int v3; // eax
  int v5; // [esp-4h] [ebp-8h]

  if ( a1 )
  {
    if ( a1 == 1 )
    {
      switch ( *(_DWORD *)dword_7689CC )
      {
        case 1:
          goto LABEL_4;
        case 3:
          *(_DWORD *)dword_7689CC = 1;
          sub_4CF410(dword_7689D8);
          break;
        case 4:
          v5 = dword_7689D8;
          goto LABEL_25;
        case 5:
          *(_DWORD *)dword_7689CC = 4;
          sub_4CF410(dword_7689D8);
          break;
        default:
          v5 = dword_7689D8;
          goto LABEL_25;
      }
    }
  }
  else
  {
    switch ( *(_DWORD *)dword_7689CC )
    {
      case 1:
        v1 = dword_7689D8;
        *(_DWORD *)dword_7689CC = 3;
        if ( dword_7689D4 <= 3 )
        {
          v2 = dword_7689D8 < 3;
          goto LABEL_7;
        }
        *(_DWORD *)dword_7689CC = dword_7689D4;
        break;
      case 3:
        v1 = dword_7689D8;
        *(_DWORD *)dword_7689CC = 4;
        if ( dword_7689D4 <= 4 )
        {
          v2 = dword_7689D8 < 4;
          goto LABEL_7;
        }
        *(_DWORD *)dword_7689CC = dword_7689D4;
        break;
      case 4:
LABEL_4:
        v1 = dword_7689D8;
        *(_DWORD *)dword_7689CC = 5;
        if ( dword_7689D4 <= 5 )
        {
          v2 = dword_7689D8 < 5;
LABEL_7:
          if ( v2 )
            *(_DWORD *)dword_7689CC = v1;
        }
        else
        {
          *(_DWORD *)dword_7689CC = dword_7689D4;
        }
        break;
      case 5:
        *(_DWORD *)dword_7689CC = 1;
        if ( dword_7689D4 <= 1 )
        {
          if ( dword_7689D8 < 1 )
            *(_DWORD *)dword_7689CC = dword_7689D8;
        }
        else
        {
          *(_DWORD *)dword_7689CC = dword_7689D4;
        }
        break;
      default:
        v5 = dword_7689D8;
LABEL_25:
        *(_DWORD *)dword_7689CC = 3;
        sub_4CF410(v5);
        break;
    }
  }
  v3 = sub_49D690(*(_DWORD *)dword_7689CC);
  return sub_578600(v3);
}
