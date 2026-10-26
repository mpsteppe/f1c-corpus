void __thiscall sub_419690(_DWORD *this, int a2, int a3, int a4)
{
  int v5; // edi
  int v6; // esi
  int v7; // eax
  int v8; // eax
  float v9[8]; // [esp+Ch] [ebp-20h] BYREF

  if ( dword_7D0308 && flt_7CF3C8 != 0.0 && dword_7C56A8 != 8 )
  {
    sub_4144D0(v9);
    v5 = 5;
    if ( dword_7C56A4 == 5 )
    {
      v6 = a3;
      if ( !a2 )
      {
        this[a3 + 108] = 1;
        if ( a3 == *(_DWORD *)(dword_7C54E8 + 18580) )
        {
          v8 = a3 == a4 ? 10 : 16;
        }
        else
        {
          if ( dword_7D0410 == 5 )
            return;
          v8 = a3 == a4 ? 3 : 33;
        }
        v5 = v8;
        sub_418A20(flt_5EA618, 10);
        sub_418A20(flt_5EA618, 16);
        sub_418A20(flt_5EA618, 3);
        sub_418A20(flt_5EA618, 33);
        goto LABEL_26;
      }
      if ( a2 == 1 )
      {
        if ( a3 != *(_DWORD *)(dword_7C54E8 + 18580) && dword_5F0714[4656 * a3] > 0 && dword_7D0410 != 5 )
        {
          sub_418A20(flt_5EA618, 4);
          v5 = 4;
          goto LABEL_26;
        }
      }
      else if ( a2 == 2 && a3 != *(_DWORD *)(dword_7C54E8 + 18580) && dword_5F0714[4656 * a3] > 0 && dword_7D0410 != 5 )
      {
        sub_418A20(flt_5EA618, 5);
        goto LABEL_26;
      }
    }
    else if ( dword_7C56A4 == 7 && !a2 )
    {
      v6 = a3;
      v7 = dword_5F0714[4656 * a3];
      if ( v7 > 1 && v7 < dword_8ACF8C - 1 )
      {
        v5 = a3 != *(_DWORD *)(dword_7C54E8 + 18580) ? 262 : 72;
        sub_418A20(flt_5EA618, 72);
        sub_418A20(flt_5EA618, 262);
LABEL_26:
        sub_4144F0(v9, v5, dword_5F0F74[4656 * v6], -1, -1, -1, -2.0, -2.0);
        sub_418560(flt_5EA618, v9);
      }
    }
  }
}
