void __thiscall sub_419120(float *this, int *a2, int a3, int a4)
{
  char *v5; // esi
  unsigned __int8 v7; // c0
  unsigned __int8 v8; // c3
  double v9; // st7
  double v10; // st7
  int v11; // [esp-1Ch] [ebp-4Ch]
  int v12; // [esp-18h] [ebp-48h]
  float v13[8]; // [esp+10h] [ebp-20h] BYREF

  if ( dword_7D0308 && flt_7CF3C8 != 0.0 && dword_7C56A8 != 8 && LODWORD(this[a2[4645] + 108]) != a4 && a3 != a4 )
  {
    sub_4144D0(v13);
    if ( dword_7C56A4 == 7 )
    {
      if ( *(_DWORD *)(dword_7C54E8 + 18580) == a2[4645] )
      {
        if ( a4 != 1 )
        {
          if ( a4 < a3 )
          {
            v5 = (char *)&unk_5EC6D8 + 18624 * sub_4D1B50(a4);
            if ( !v5[13388] && !*((_DWORD *)v5 + 4121) && a2[4111] >= 1 )
            {
              if ( v7 | v8 )
              {
                if ( dbl_8AFEA0 - 2.0 > this[a2[4645] + 319] )
                {
                  v9 = flt_8AAE74[(unsigned __int8)dword_8AAE70++];
                  if ( v9 < 0.75 )
                  {
                    sub_4189F0(flt_5EA618, 259);
                    sub_4189F0(flt_5EA618, 120);
                    v10 = flt_8AAE74[(unsigned __int8)dword_8AAE70++];
                    if ( v10 >= 0.25 )
                      sub_4144F0(v13, 120, a4, -1, -1, -1, -2.0, -2.0);
                    else
                      sub_4144F0(v13, 259, *((_DWORD *)v5 + 4647), -1, -1, -1, -2.0, -2.0);
                  }
                }
              }
            }
          }
          goto LABEL_24;
        }
        sub_4189F0(flt_5EA618, 259);
        sub_4189F0(flt_5EA618, 120);
        v12 = 1;
        v11 = 120;
      }
      else
      {
        if ( a4 != 1 || a2[4111] <= 0 )
          goto LABEL_24;
        v12 = a2[4647];
        v11 = 198;
      }
      sub_4144F0(v13, v11, v12, -1, -1, -1, -2.0, -2.0);
    }
LABEL_24:
    if ( LODWORD(v13[0]) != -1 )
    {
      sub_418560(flt_5EA618, v13);
      LODWORD(this[a2[4645] + 108]) = a4;
    }
  }
}
