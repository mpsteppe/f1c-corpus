// f1c  0x0041c0f0  size=714
void __thiscall sub_41C0F0(_DWORD *this, int a2)
{
  int v3; // esi
  int v4; // ebx
  int *i; // eax
  int v6; // edi
  int v7; // ecx
  int v8; // eax
  int v9; // eax
  double v10; // st7
  int v11; // [esp+Ch] [ebp-24h]
  float v12[8]; // [esp+10h] [ebp-20h] BYREF
  int v13; // [esp+34h] [ebp+4h]

  if ( dword_7D0308 )
  {
    if ( flt_7CF3C8 != 0.0 )
    {
      v3 = a2 + 1;
      v4 = 0;
      v11 = a2 + 1;
      if ( dword_5C329C )
      {
        for ( i = dword_5F0738; *i != v3; i += 4656 )
        {
          if ( ++v4 >= (unsigned int)dword_5C329C )
            return;
        }
        v6 = 397;
        sub_4144D0(v12);
        v13 = a2 + 1;
        if ( dword_7D0410 != 2 )
        {
          if ( this[v4] == 1 )
          {
            if ( v3 == 1 )
            {
              v6 = 516;
            }
            else
            {
              v10 = (double)v11 / (double)dword_5C329C;
              if ( v10 >= 0.5 || v3 > 6 )
              {
                if ( v10 <= 2.0 || v3 <= 10 )
                {
                  if ( (double)dword_5C329C * 0.6666666666666666 > (double)v11 && dword_5C329C > 11 )
                    v6 = 518;
                }
                else
                {
                  v6 = 519;
                }
              }
              else
              {
                v6 = 517;
              }
            }
          }
          else if ( this[v4] == 2 )
          {
            v9 = *(_DWORD *)(dword_7C54E8 + 16480);
            if ( v3 >= v9 )
            {
              if ( v3 != v9 + 1 || v3 % 2 )
                v6 = (v3 - v9 - 1 > 3) + 524;
              else
                v6 = 523;
            }
            else if ( v3 == v9 - 1 && v3 % 2 )
            {
              v6 = 523;
            }
            else
            {
              v6 = (v9 - v3 - 1 > 3) + 521;
            }
          }
          else if ( this[v4] == 3 && dword_7D0410 == 4 )
          {
            v7 = dword_7C54E8;
            v8 = *(_DWORD *)(dword_7C54E8 + 16480);
            if ( v3 >= v8 )
            {
              if ( v3 != v8 + 1 || (v7 = v3 % 2) != 0 )
                v6 = (v3 >= v8 + 3) + 528;
              else
                v6 = 531;
            }
            else if ( v3 == v8 - 1 && (v7 = v3 % 2) != 0 )
            {
              v6 = 531;
            }
            else
            {
              v7 = (v3 + 3 <= v8) + 534;
              v6 = v7;
            }
            if ( sub_5884ED(v7) % 2 == 1 )
            {
              v13 = *(_DWORD *)(dword_7C54E8 + 18588);
              switch ( v6 )
              {
                case 528:
                  v6 = 526;
                  break;
                case 529:
                  v6 = 527;
                  break;
                case 531:
                  v6 = 530;
                  break;
                case 534:
                  v6 = 532;
                  break;
                case 535:
                  v6 = 533;
                  break;
                default:
                  v13 = v3;
                  break;
              }
            }
          }
        }
        sub_4144F0(v12, v6, dword_5F0F74[4656 * v4], v13, -1, -1, -2.0, -2.0);
        sub_418560(flt_5EA618, v12);
      }
    }
  }
}
