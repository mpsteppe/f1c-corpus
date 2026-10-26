int __thiscall sub_4D2E50(int this)
{
  double v2; // st7
  double v3; // st7
  int v4; // eax
  char v5; // cl
  int i; // edi
  int v7; // ecx
  int v8; // ebp
  int v9; // ebx
  int v10; // edi
  int v11; // eax
  char v12; // cl
  int result; // eax
  double v14; // st7
  float v15; // [esp+10h] [ebp-58h]
  float v16; // [esp+10h] [ebp-58h]
  float v17; // [esp+14h] [ebp-54h]
  float v18; // [esp+14h] [ebp-54h]
  float v19; // [esp+14h] [ebp-54h]
  _BYTE v20[80]; // [esp+18h] [ebp-50h] BYREF

  if ( dword_7C56A4 > 0 )
  {
    if ( dword_7C56A4 <= 6 )
    {
      sub_41A500(*(float *)(this + 180));
      if ( dword_7C56A8 )
      {
        if ( dword_7C56A8 == 5 )
        {
          if ( dbl_8AFEA0 >= *(float *)(this + 180) )
          {
            sub_42D140(&dword_7C569C, 8u);
            sub_4D0EC0((_DWORD *)(this + 244), 2);
            sub_41A6B0();
          }
        }
        else if ( dword_7C56A8 == 7 )
        {
          v2 = dbl_8AFE98 + *(float *)(this + 180);
LABEL_84:
          *(float *)(this + 180) = v2;
        }
      }
      else if ( dbl_8AFEA0 >= *(float *)(this + 176) )
      {
        sub_42D140(&dword_7C569C, 5u);
LABEL_7:
        sub_4D0EC0((_DWORD *)(this + 244), 1);
      }
    }
    else if ( dword_7C56A4 == 7 )
    {
      switch ( dword_7C56A8 )
      {
        case 0:
          if ( dbl_8AFEA0 >= *(float *)(this + 176) )
          {
            sub_42D140(&dword_7C569C, 1u);
            goto LABEL_7;
          }
          break;
        case 1:
          if ( dbl_8AFEA0 >= *(float *)(this + 180) )
          {
            sub_45BDF0(&dword_7CD204);
            if ( !dword_7CED8C )
              goto LABEL_39;
            sub_42D140(&dword_7C569C, 2u);
            v2 = *(float *)(this + 180) + 300.0;
            goto LABEL_84;
          }
          v15 = *(float *)(this + 180) - dbl_8AFEA0;
          if ( v15 < 240.0 )
          {
            if ( v15 < 180.0 )
            {
              if ( v15 < 120.0 )
              {
                if ( v15 < 60.0 )
                  sub_4D1CD0((_DWORD *)this, 1);
                else
                  sub_4D1CD0((_DWORD *)this, 2);
              }
              else
              {
                sub_4D1CD0((_DWORD *)this, 3);
              }
            }
            else
            {
              sub_4D1CD0((_DWORD *)this, 4);
            }
          }
          else
          {
            sub_4D1CD0((_DWORD *)this, 5);
          }
          if ( v15 < 15.0 && !dword_7CED8C )
            sub_4D2E20((int **)this);
          v3 = (double)dword_7CEC30 + *(float *)(this + 176) - dbl_8AFEA0;
          v17 = v3;
          if ( v3 >= 0.0 )
          {
            if ( byte_7CEC78 )
            {
              if ( sub_423A00(byte_5EC4C0, aTimeUntilPitCl, byte_5EC4CC) )
              {
                v4 = 0;
                do
                {
                  v5 = aTimeUntilPitCl[v4];
                  byte_5EC4CC[v4++] = v5;
                }
                while ( v5 );
              }
              sub_4D11D0(v17, byte_5EC4CC);
            }
          }
          else
          {
            sub_4D0EC0((_DWORD *)(this + 244), 2);
            if ( v17 > -0.5 )
              sub_45BDF0(&dword_7CD204);
            if ( byte_7CEC78 )
              sub_4D11D0(v15, 0);
          }
          break;
        case 2:
          if ( !*(_BYTE *)(this + 194) )
          {
            sub_40CDE0(&dword_5EA510, 5, 1);
            *(_BYTE *)(this + 194) = 1;
          }
          if ( *(_DWORD *)this == 2 )
            sub_40DD80((_DWORD **)this);
          sub_40DE60((int *)this);
          if ( dbl_8AFEA0 >= *(float *)(this + 180) )
          {
            *(_BYTE *)(this + 194) = 0;
LABEL_39:
            if ( dword_7CEE88 )
            {
              sub_42D140(&dword_7C569C, 3u);
            }
            else
            {
              *(_DWORD *)(this + 216) = 2139095039;
              *(_DWORD *)(this + 176) = 2139095039;
              *(_BYTE *)(this + 194) = 0;
              sub_42D140(&dword_7C569C, 4u);
            }
          }
          break;
        case 3:
          if ( dword_7C54E8 )
            sub_4BC9B0((int *)(dword_7C54E8 + 16436), 0, 1);
          sub_4D1CD0((_DWORD *)this, 0);
          sub_40E170(this);
          break;
        case 4:
          if ( !*(_BYTE *)(this + 194) )
          {
            sub_40E170(this);
            sub_40D100(&dword_5EA510);
            *(_BYTE *)(this + 194) = 1;
          }
          if ( dbl_8AFEA0 < *(float *)(this + 176) )
          {
            if ( sub_461DB0(dword_7CD25C) )
              sub_45BDE0((_DWORD **)&dword_7CD204, a0001, 0);
            v16 = dbl_8AFEA0;
            if ( *(float *)(this + 216) + 4.0 > v16 )
            {
              if ( *(float *)(this + 216) + 3.0 > v16 )
              {
                if ( *(float *)(this + 216) + 2.0 > v16 )
                {
                  if ( *(float *)(this + 216) + 1.0 > v16 )
                  {
                    if ( *(float *)(this + 216) > (double)v16 )
                    {
                      sub_4D1CD0((_DWORD *)this, 0);
                      if ( sub_461DB0(dword_7CD25C) && 33.5 - dbl_8AFEA0 > 0.0 )
                      {
                        v18 = 33.5 - dbl_8AFEA0;
                        sub_4D11D0(v18, 0);
                      }
                    }
                    else
                    {
                      sub_4D1CD0((_DWORD *)this, 1);
                    }
                  }
                  else
                  {
                    sub_4D1CD0((_DWORD *)this, 2);
                  }
                }
                else
                {
                  sub_4D1CD0((_DWORD *)this, 3);
                }
              }
              else
              {
                sub_4D1CD0((_DWORD *)this, 4);
              }
            }
            else
            {
              sub_4D1CD0((_DWORD *)this, 5);
            }
          }
          else
          {
            sub_4D2210();
            sub_4D1CD0((_DWORD *)this, 0);
            sub_42D140(&dword_7C569C, 5u);
          }
          break;
        case 5:
          if ( *(_DWORD *)(this + 244) == 2 )
          {
            for ( i = 0; i < dword_5C329C; ++i )
            {
              if ( *(_DWORD *)(dword_7C54F0[i] + 16448) == 1 )
                sub_4D0EC0((_DWORD *)(this + 244), 1);
            }
          }
          if ( dword_7CEBF4 > 0 )
          {
            v19 = *(float *)(this + 180) - dbl_8AFEA0 + 0.5;
            v7 = (int)v19;
            if ( v7 >= 0 && !(v7 % dword_7CEBF4) )
            {
              v8 = v7 / 3600;
              v9 = v7 % 3600 / 60;
              v10 = v7 % 3600 % 60;
              if ( sub_423A00(byte_5EC4C0, aTimeRemaining, byte_5EC4CC) )
              {
                v11 = 0;
                do
                {
                  v12 = aTimeRemaining[v11];
                  byte_5EC4CC[v11++] = v12;
                }
                while ( v12 );
              }
              sub_58815F(v20, "%s %d:%02d:%02d", byte_5EC4CC, v8, v9, v10);
              sub_45BD10(&dword_7CD204, (int)v20, 3, 16909060);
            }
          }
          break;
        default:
          break;
      }
    }
  }
  result = *(_DWORD *)(this + 244);
  if ( result != 2 )
  {
    if ( *(_BYTE *)(this + 260) && (v14 = dbl_8AFEA0, sub_58957A(dbl_8AFEA0), v14 > 0.5) )
      return sub_4D0EC0((_DWORD *)(this + 244), 4);
    else
      return sub_4D0EC0((_DWORD *)(this + 244), 1);
  }
  return result;
}
