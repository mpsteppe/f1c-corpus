int __thiscall sub_562E30(float *this, int a2)
{
  int v2; // edi
  int v3; // esi

  v2 = 1;
  switch ( a2 )
  {
    case 0:
      return 0;
    case 1:
      v3 = dword_FAE930;
      goto LABEL_14;
    case 2:
      v3 = dword_FAE934;
      goto LABEL_14;
    case 3:
      v3 = dword_FAE938;
      goto LABEL_14;
    case 4:
      v3 = dword_FAE93C;
      goto LABEL_14;
    case 5:
      v3 = dword_FAE944;
      goto LABEL_14;
    case 6:
      v3 = dword_FAE940;
      goto LABEL_14;
    case 7:
      v3 = dword_FAE948;
      goto LABEL_14;
    case 8:
      v3 = LODWORD(flt_FAE950);
      sub_5629C0(this, SLODWORD(flt_FAE950));
      goto LABEL_14;
    case 9:
      v3 = dword_FAE960;
      goto LABEL_14;
    case 10:
      v3 = dword_FAE94C;
      goto LABEL_14;
    case 11:
      if ( byte_BE1209 != 1 )
        return v2;
      v3 = dword_FAE96C;
LABEL_14:
      if ( !v3 || !dword_FB2790 )
        return v2;
      if ( a2 == 9 && sub_521050(&dword_BE120C) )
        return 0;
      sub_5EDDD0(dword_FB2790, 0);
      return 0;
    default:
      return v2;
  }
}
