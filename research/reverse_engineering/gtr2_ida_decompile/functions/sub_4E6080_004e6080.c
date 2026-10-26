void __stdcall sub_4E6080(float a1, int a2, float a3)
{
  float v3; // esi
  int v4; // edi
  double v5; // st7
  int v6; // esi
  int v7; // ecx
  float v8; // [esp+4h] [ebp-4h]

  v3 = a1;
  if ( LODWORD(a1) <= 6 )
  {
    v4 = LODWORD(a3);
    if ( a3 != 0.0 )
    {
      v8 = flt_B6F0DC[LODWORD(a1)];
      a1 = 0.0;
      a3 = flt_B6F0F8[LODWORD(v3)];
      switch ( LODWORD(v3) )
      {
        case 0:
          a1 = sub_4E4DE0();
          break;
        case 1:
          a1 = *((float *)dword_91E07C + 4307) * 9.549296585513721;
          break;
        case 2:
          a1 = dbl_B68348 - 273.16;
          break;
        case 3:
          a1 = dbl_B68308 - 273.16;
          break;
        case 4:
          a1 = dbl_B68330;
          break;
        case 5:
          a1 = sub_44A300(&dbl_B66040);
          break;
        case 6:
          a1 = *((float *)dword_91E07C + 4299);
          break;
        default:
          break;
      }
      if ( a3 > 0.0 )
      {
        switch ( LODWORD(v3) )
        {
          case 2:
          case 3:
            v5 = (a1 - -40.0) * 1.8 - 40.0;
            goto LABEL_15;
          case 4:
          case 5:
            v5 = a1 * 0.14503774;
LABEL_15:
            a1 = v5;
            break;
          default:
            break;
        }
        sub_401760(&a1, v8, a3);
        v6 = a2;
        v7 = a2;
        *(float *)(a2 + 32) = a3 - v8;
        *(float *)(v7 + 28) = a1 - v8;
        sub_4E4420(v7);
        sub_5E77B0(v4, 4, 8);
        if ( *(_DWORD *)(v6 + 4) )
          sub_5EDDD0(v4, 0);
      }
    }
  }
}
