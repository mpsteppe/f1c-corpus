int __thiscall sub_50F6B0(int this, int a2, float a3)
{
  int v4; // edx
  int v5; // eax
  int v6; // ecx
  int v7; // eax
  double v8; // st7
  float v9; // ecx
  bool v10; // c0
  bool v11; // c3
  float v12; // eax
  bool v13; // zf
  float v14; // eax
  float v15; // eax

  v4 = *(_DWORD *)(this + 10296);
  *(_DWORD *)(this + 10284) = a2;
  v5 = *(_DWORD *)(this + 10292);
  v6 = *(_DWORD *)(this + 10284);
  if ( v6 >= v5 )
  {
    if ( v6 > v4 )
      *(_DWORD *)(this + 10284) = v4;
  }
  else
  {
    *(_DWORD *)(this + 10284) = v5;
  }
  v7 = *(_DWORD *)(this + 10284);
  if ( v7 != 1 )
  {
    switch ( v7 )
    {
      case 2:
        *(_DWORD *)(this + 21284) = 1;
        *(_DWORD *)(this + 21288) = 1;
        *(_DWORD *)(this + 21260) = 2;
        v12 = a3;
        v13 = LODWORD(a3) == 1;
        *(_DWORD *)(this + 21256) = 1;
        *(_DWORD *)(this + 21200) = 1;
        *(_DWORD *)(this + 21204) = 4;
        *(_DWORD *)(this + 21228) = 1;
        *(_DWORD *)(this + 21232) = 3;
        *(_DWORD *)(this + 21312) = 1;
        *(_DWORD *)(this + 21316) = 13;
        *(_DWORD *)(this + 21340) = 1;
        *(_DWORD *)(this + 21344) = 14;
        if ( v13 )
        {
          *(_DWORD *)(this + 21204) = 4;
          *(_DWORD *)(this + 21200) = 1;
          *(_DWORD *)(this + 21228) = 1;
          *(_DWORD *)(this + 21232) = 12;
          a3 = 1.0;
          sub_409B80((float *)(this + 17976), &a3);
          a3 = 1.0;
          sub_409B80((float *)(this + 18408), &a3);
          return off_16C9524(a2, LODWORD(a3));
        }
        if ( LODWORD(v12) != 2 )
          return off_16C9524(a2, LODWORD(a3));
        *(_DWORD *)(this + 21232) = 5;
        break;
      case 3:
        v14 = a3;
        v13 = LODWORD(a3) == 1;
        *(_DWORD *)(this + 21284) = 1;
        *(_DWORD *)(this + 21288) = 40;
        *(_DWORD *)(this + 21256) = 1;
        *(_DWORD *)(this + 21260) = 41;
        *(_DWORD *)(this + 21200) = 1;
        *(_DWORD *)(this + 21204) = 43;
        *(_DWORD *)(this + 21228) = 1;
        *(_DWORD *)(this + 21232) = 42;
        *(_DWORD *)(this + 21312) = 1;
        *(_DWORD *)(this + 21316) = 52;
        *(_DWORD *)(this + 21340) = 1;
        *(_DWORD *)(this + 21344) = 53;
        if ( v13 )
        {
          *(_DWORD *)(this + 21204) = 43;
          *(_DWORD *)(this + 21200) = 1;
          *(_DWORD *)(this + 21228) = 1;
          *(_DWORD *)(this + 21232) = 51;
          a3 = 1.0;
          sub_409B80((float *)(this + 18840), &a3);
          a3 = 1.0;
          sub_409B80((float *)(this + 19272), &a3);
          return off_16C9524(a2, LODWORD(a3));
        }
        if ( LODWORD(v14) != 2 )
          return off_16C9524(a2, LODWORD(a3));
        *(_DWORD *)(this + 21232) = 44;
        break;
      case 4:
        v15 = a3;
        v13 = LODWORD(a3) == 1;
        *(_DWORD *)(this + 21284) = 1;
        *(_DWORD *)(this + 21288) = 140;
        *(_DWORD *)(this + 21256) = 1;
        *(_DWORD *)(this + 21260) = 141;
        *(_DWORD *)(this + 21200) = 1;
        *(_DWORD *)(this + 21204) = 143;
        *(_DWORD *)(this + 21228) = 1;
        *(_DWORD *)(this + 21232) = 142;
        *(_DWORD *)(this + 21312) = 1;
        *(_DWORD *)(this + 21316) = 152;
        *(_DWORD *)(this + 21340) = 1;
        *(_DWORD *)(this + 21344) = 153;
        if ( v13 )
        {
          *(_DWORD *)(this + 21204) = 143;
          *(_DWORD *)(this + 21200) = 1;
          *(_DWORD *)(this + 21228) = 1;
          *(_DWORD *)(this + 21232) = 151;
          a3 = 1.0;
          sub_409B80((float *)(this + 19704), &a3);
          a3 = 1.0;
          sub_409B80((float *)(this + 20136), &a3);
          return off_16C9524(a2, LODWORD(a3));
        }
        if ( LODWORD(v15) != 2 )
          return off_16C9524(a2, LODWORD(a3));
        *(_DWORD *)(this + 21232) = 144;
        break;
      default:
        return off_16C9524(a2, LODWORD(a3));
    }
    *(_DWORD *)(this + 21228) = 1;
    return off_16C9524(a2, LODWORD(a3));
  }
  *(_DWORD *)(this + 21284) = 0;
  *(_DWORD *)(this + 21288) = 52;
  *(_DWORD *)(this + 21256) = 0;
  *(_DWORD *)(this + 21260) = 51;
  *(_DWORD *)(this + 21200) = 0;
  *(_DWORD *)(this + 21204) = 30;
  *(_DWORD *)(this + 21228) = 0;
  *(_DWORD *)(this + 21232) = 44;
  *(_DWORD *)(this + 21312) = 0;
  *(_DWORD *)(this + 21316) = 56;
  *(_DWORD *)(this + 21340) = 0;
  *(_DWORD *)(this + 21344) = 184;
  v8 = *(float *)(this + 1756);
  v9 = *(float *)(this + 1760);
  *(_DWORD *)(this + 1748) = 1058642330;
  v10 = v8 < *(float *)(this + 1748);
  v11 = v8 == *(float *)(this + 1748);
  a3 = v9;
  if ( v10 || v11 )
  {
    if ( *(float *)(this + 1748) > (double)a3 )
      *(float *)(this + 1748) = a3;
  }
  else
  {
    *(float *)(this + 1748) = v8;
  }
  return off_16C9524(a2, LODWORD(a3));
}
