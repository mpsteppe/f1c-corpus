int __stdcall sub_4D8A30(int a1)
{
  int v1; // edi
  int v2; // esi

  v1 = 1;
  switch ( a1 )
  {
    case 0:
      goto LABEL_10;
    case 1:
      v2 = dword_8AD398;
      goto LABEL_7;
    case 2:
      v2 = dword_8AD39C;
      goto LABEL_7;
    case 3:
      v2 = dword_8AD3A0;
      goto LABEL_7;
    case 4:
      v2 = dword_8AD3A4;
      goto LABEL_7;
    case 5:
      v2 = LODWORD(flt_8AD3A8);
      QuadRenderWithColor(flt_8AD3A8);
LABEL_7:
      if ( v2 && dword_8B8DC8 )
      {
        sub_553700(dword_8B8DC8);
LABEL_10:
        v1 = 0;
      }
      break;
    default:
      return v1;
  }
  return v1;
}

