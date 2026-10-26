int __stdcall sub_5022D0(int a1)
{
  int v1; // edi
  int v2; // esi

  v1 = 1;
  switch ( a1 )
  {
    case 0:
      goto LABEL_10;
    case 1:
      v2 = dword_7D79E0;
      goto LABEL_7;
    case 2:
      v2 = dword_7D79E4;
      goto LABEL_7;
    case 3:
      v2 = dword_7D79E8;
      goto LABEL_7;
    case 4:
      v2 = dword_7D79EC;
      goto LABEL_7;
    case 5:
      v2 = LODWORD(flt_7D79F0);
      sub_502840(flt_7D79F0);
LABEL_7:
      if ( v2 && dword_7E8CDC )
      {
        sub_5A1870(dword_7E8CDC);
LABEL_10:
        v1 = 0;
      }
      break;
    default:
      return v1;
  }
  return v1;
}
