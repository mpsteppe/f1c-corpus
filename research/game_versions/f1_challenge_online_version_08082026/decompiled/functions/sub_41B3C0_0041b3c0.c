void __thiscall sub_41B3C0(_DWORD *this, int a2, int a3, float a4, int a5, int a6)
{
  double v6; // st7
  int v7; // edi
  int v8; // esi
  bool v9; // bl
  int v10; // edi
  float v11; // [esp+10h] [ebp-28h]
  float v13[8]; // [esp+18h] [ebp-20h] BYREF

  if ( dword_7D0308 && flt_7CF3C8 != 0.0 && !*(_BYTE *)(dword_7C54E8 + 13388) && dword_7C56A8 != 8 )
  {
    if ( a4 >= 0.0 )
    {
      if ( a4 > (double)flt_5EA3FC )
        a4 = flt_5EA3FC;
    }
    else
    {
      a4 = 0.0;
    }
    sub_4144D0(v13);
    v6 = sub_4F0050(dword_7C54E8 + 12);
    v11 = v6;
    v7 = sub_4D7C10(a4);
    v8 = sub_4D7C10(v11);
    v9 = v8 == v7;
    switch ( a2 )
    {
      case 0:
        if ( this[v7 + 316] != 2 )
          goto LABEL_67;
        if ( sub_4D1AD0(v7) )
          goto LABEL_67;
        this[v7 + 316] = 0;
        if ( dword_7C56A4 != 7 || dword_7C56A8 == 5 )
          goto LABEL_67;
        if ( !v7 )
        {
          if ( v8 == 1 )
            goto LABEL_67;
          if ( sub_4189B0(flt_5EA618, 138) )
          {
            sub_4189F0(flt_5EA618, 138);
            if ( !v8 )
              goto LABEL_37;
          }
          else
          {
            if ( (unsigned __int8)sub_4189F0(flt_5EA618, 138) )
              goto LABEL_67;
            if ( !v8 )
              goto LABEL_37;
          }
          sub_4144F0(v13, 137, -1, -1, -1, -1, -2.0, -2.0);
LABEL_67:
          if ( LODWORD(v13[0]) != -1 )
            sub_418560(flt_5EA618, v13);
          return;
        }
        v10 = v7 - 1;
        if ( v10 )
        {
          if ( v10 != 1 || !v8 )
            goto LABEL_67;
          if ( sub_4189B0(flt_5EA618, 136) )
          {
            sub_4189F0(flt_5EA618, 136);
            if ( v9 )
            {
LABEL_37:
              sub_4144F0(v13, 126, -1, -1, -1, -1, -2.0, -2.0);
              goto LABEL_67;
            }
          }
          else
          {
            if ( (unsigned __int8)sub_4189F0(flt_5EA618, 136) )
              goto LABEL_67;
            if ( v9 )
              goto LABEL_37;
          }
          sub_4144F0(v13, 135, -1, -1, -1, -1, -2.0, -2.0);
          goto LABEL_67;
        }
        if ( v8 == 2 )
          goto LABEL_67;
        if ( sub_4189B0(flt_5EA618, 134) )
        {
          sub_4189F0(flt_5EA618, 134);
          if ( v9 )
            goto LABEL_37;
        }
        else
        {
          if ( (unsigned __int8)sub_4189F0(flt_5EA618, 134) )
            goto LABEL_67;
          if ( v9 )
            goto LABEL_37;
        }
        sub_4144F0(v13, 133, -1, -1, -1, -1, -2.0, -2.0);
        goto LABEL_67;
      case 2:
        if ( v8 != v7 || (v6 = v11 + 50.0, v6 < a4) )
        {
          if ( v7 )
          {
            if ( v7 == 1 )
            {
              if ( v8 != 2 )
              {
                if ( v8 || (sub_4D7CF0(v11, 0), v6 >= 0.89999998) )
                {
                  sub_418A20(flt_5EA618, 133);
                  sub_418A20(flt_5EA618, 136);
                  sub_4189F0(flt_5EA618, 134);
                  sub_4144F0(v13, 134, -1, -1, -1, -1, -2.0, -2.0);
                }
              }
            }
            else if ( v7 == 2 )
            {
              if ( v8 )
              {
                if ( v8 != 1 || (sub_4D7CF0(v11, 0), v6 >= 0.89999998) )
                {
                  sub_418A20(flt_5EA618, 135);
                  sub_418A20(flt_5EA618, 138);
                  sub_4189F0(flt_5EA618, 136);
                  sub_4144F0(v13, 136, -1, -1, -1, -1, -2.0, -2.0);
                }
              }
            }
          }
          else if ( v8 != 1 )
          {
            if ( v8 != 2 || (sub_4D7CF0(v11, 0), v6 >= 0.89999998) )
            {
              sub_418A20(flt_5EA618, 137);
              sub_418A20(flt_5EA618, 134);
              sub_4189F0(flt_5EA618, 138);
              sub_4144F0(v13, 138, -1, -1, -1, -1, -2.0, -2.0);
            }
          }
        }
        if ( LODWORD(v13[0]) == -1 )
          return;
        this[v7 + 316] = 2;
        goto LABEL_67;
      case 3:
        sub_4144F0(v13, 131, -1, -1, -1, -1, -2.0, -2.0);
        goto LABEL_67;
      case 5:
        if ( dword_7C54E8 && dword_7C54E8 == a5 )
        {
          switch ( a6 )
          {
            case 1:
              sub_4144F0(v13, 123, -1, -1, -1, -1, -2.0, -2.0);
              break;
            case 2:
              sub_418A20(flt_5EA618, 123);
              sub_4144F0(v13, 124, -1, -1, -1, -1, -2.0, -2.0);
              break;
            case 3:
              sub_418A20(flt_5EA618, 123);
              sub_418A20(flt_5EA618, 124);
              sub_4144F0(v13, 125, -1, -1, -1, -1, -2.0, -2.0);
              break;
          }
        }
        goto LABEL_67;
      default:
        goto LABEL_67;
    }
  }
}
