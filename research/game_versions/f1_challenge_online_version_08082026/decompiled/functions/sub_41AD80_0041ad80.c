void __thiscall sub_41AD80(float *this, int a2, int a3, float a4)
{
  float *v5; // edx
  int v6; // eax
  double v7; // st7
  double v8; // st7
  int v9; // [esp-18h] [ebp-40h]
  int v10; // [esp-14h] [ebp-3Ch]
  float v11[8]; // [esp+8h] [ebp-20h] BYREF
  float v12; // [esp+2Ch] [ebp+4h]
  int v13; // [esp+2Ch] [ebp+4h]
  float v14; // [esp+34h] [ebp+Ch]

  if ( dword_7D0308 )
  {
    if ( flt_7CF3C8 != 0.0 && dword_7C56A8 != 8 )
    {
      v5 = &this[*(_DWORD *)(a2 + 18580) + 319];
      if ( dbl_8AFEA0 - 2.0 > *v5 && dbl_8AFEA0 - 2.0 > this[*(_DWORD *)(a3 + 18580) + 319] && a4 > 1250.0 )
      {
        v12 = dbl_8AFEA0;
        *v5 = v12;
        this[*(_DWORD *)(a2 + 18580) + 423] = a4;
        LODWORD(this[*(_DWORD *)(a2 + 18580) + 527]) = a3;
        this[*(_DWORD *)(a3 + 18580) + 319] = dbl_8AFEA0;
        this[*(_DWORD *)(a3 + 18580) + 423] = a4;
        LODWORD(this[*(_DWORD *)(a3 + 18580) + 527]) = a2;
        *(float *)&v13 = sub_4F0050(a2 + 12);
        v14 = sub_4F0050(a3 + 12);
        sub_4144D0(v11);
        v6 = *(_DWORD *)(dword_7C54E8 + 18580);
        if ( v6 == *(_DWORD *)(a2 + 18580) )
        {
          if ( v14 < (double)*(float *)&v13 )
            sub_4144F0(v11, 114, *(_DWORD *)(a3 + 18588), -1, -1, -1, -2.0, -2.0);
          else
            sub_4144F0(v11, 115, *(_DWORD *)(a3 + 18588), -1, -1, -1, -2.0, -2.0);
          goto LABEL_23;
        }
        if ( v6 == *(_DWORD *)(a3 + 18580) )
        {
          if ( v14 < (double)*(float *)&v13 )
            sub_4144F0(v11, 115, *(_DWORD *)(a2 + 18588), -1, -1, -1, -2.0, -2.0);
          else
            sub_4144F0(v11, 114, *(_DWORD *)(a2 + 18588), -1, -1, -1, -2.0, -2.0);
          goto LABEL_23;
        }
        if ( v14 < (double)*(float *)&v13 )
        {
          v8 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
          if ( v8 > 0.0 )
          {
            sub_4144F0(v11, 225, *(_DWORD *)(a3 + 18588), *(_DWORD *)(a2 + 18588), -1, -1, -2.0, -2.0);
            goto LABEL_23;
          }
          v10 = *(_DWORD *)(a3 + 18588);
          v9 = *(_DWORD *)(a2 + 18588);
        }
        else
        {
          v7 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
          if ( v7 > 0.0 )
          {
            sub_4144F0(v11, 225, *(_DWORD *)(a2 + 18588), *(_DWORD *)(a3 + 18588), -1, -1, -2.0, -2.0);
LABEL_23:
            sub_418560(flt_5EA618, v11);
            return;
          }
          v10 = *(_DWORD *)(a2 + 18588);
          v9 = *(_DWORD *)(a3 + 18588);
        }
        sub_4144F0(v11, 226, v9, v10, -1, -1, -2.0, -2.0);
        goto LABEL_23;
      }
    }
  }
}
