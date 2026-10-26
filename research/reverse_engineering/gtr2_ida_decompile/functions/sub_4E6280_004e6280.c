// bad sp value at call has been detected, the output may be wrong!
char __thiscall sub_4E6280(_DWORD *this)
{
  int v2; // eax
  int v3; // eax
  char *v4; // eax
  int v6; // [esp-4h] [ebp-34h]
  int v7; // [esp+0h] [ebp-30h]
  int v8; // [esp+4h] [ebp-2Ch] BYREF
  int v9; // [esp+8h] [ebp-28h] BYREF
  int v10; // [esp+Ch] [ebp-24h]
  int v11; // [esp+10h] [ebp-20h]
  int v12; // [esp+14h] [ebp-1Ch]
  int v13; // [esp+18h] [ebp-18h]

  if ( dword_B6B7A4 && dword_91BF28 == dword_91BF40 && *(_DWORD *)(dword_91BF40 + 52) == 1 )
  {
    v2 = *this + 1;
    if ( *this )
    {
      if ( *this == 4 || v2 >= 6 )
        v2 = 0;
    }
    else
    {
      v2 = 2;
    }
    sub_4E5FC0(this, v2);
  }
  v3 = *this;
  if ( *this == 1 )
  {
    if ( dword_B6B880 || (dword_B698E8 & 1) != 0 && (byte_B69AB4 & 2) != 0 )
    {
      LOBYTE(v3) = sub_4E6020(this, 1);
    }
    else if ( dword_B6B8AC || (v13 = 1, v12 = 208, (unsigned __int8)sub_40DE70()) )
    {
      LOBYTE(v3) = sub_4E6020(this, 0);
    }
    else if ( dword_B6B8D8 || (v11 = 1, v10 = 205, (unsigned __int8)sub_40DE70()) )
    {
      LOBYTE(v3) = sub_4FF5B0(dword_91E084 + 14824, this[1]);
    }
    else if ( dword_B6B904 || (v9 = 1, v8 = 203, (unsigned __int8)sub_40DE70()) )
    {
      LOBYTE(v3) = sub_4FF620(dword_91E084 + 14824, this[1]);
    }
    else if ( (unsigned __int8)sub_40DE70() || (LOBYTE(v3) = sub_40DE70(), (_BYTE)v3) )
    {
      sub_4E5FC0(this, 0);
      LOBYTE(v3) = sub_4735A0();
      if ( !(_BYTE)v3 )
        LOBYTE(v3) = sub_4304C0();
    }
  }
  else if ( v3 == 5 )
  {
    LOBYTE(v3) = byte_FAEA91;
    if ( byte_FAEA91 )
    {
      if ( dword_B6B854
        || (v13 = 1, v12 = 28, (unsigned __int8)sub_40DE70())
        || (v11 = 1, v10 = 156, (unsigned __int8)sub_40DE70()) )
      {
        v3 = this[2];
        this[3] = v3;
        if ( v3 > 100 )
        {
          if ( v3 > 400 )
          {
            v3 -= 401;
            switch ( v3 )
            {
              case 0:
              case 100:
LABEL_56:
                sub_4EA8F0(&unk_B6F134);
                if ( byte_B70918 == 1 )
                {
                  sub_540AC0(2.0);
                  sub_540850(-1.0);
                  sub_5407F0(&unk_BE1D30);
                  sub_540A50(2.0);
                  sub_540850(-1.0);
                }
                goto LABEL_45;
              case 1:
              case 102:
LABEL_54:
                byte_B699B4 = 2;
                byte_B699BC = 2;
                dword_B6F11C = 1;
                break;
              case 2:
              case 103:
LABEL_58:
                if ( dword_BE1204 == 1 )
                {
                  if ( byte_B6413C )
                    sub_590060();
                  sub_4E5FC0(this, 0);
                  sub_529B40(&dword_BE1204);
                  LOBYTE(v3) = sub_4E5FC0(this, 5);
                }
                break;
              case 3:
              case 104:
LABEL_62:
                LOBYTE(v3) = byte_FAEA91;
                if ( byte_FAEA91 )
                  byte_FAEA91 = 0;
                break;
              case 99:
                goto LABEL_43;
              case 101:
LABEL_64:
                v4 = sub_41D840(&byte_91CC38, "Saving Game");
                sub_4730C0((int **)&dword_B6CB98, v4, 3, (int)&byte_1020304, 0x40000000);
                LOBYTE(v3) = sub_54C580(&unk_BE27B0, v10, v11, v12, v13);
                break;
              default:
                return v3;
            }
          }
          else if ( v3 == 400 )
          {
LABEL_43:
            if ( byte_B6413C )
              sub_590060();
LABEL_45:
            LOBYTE(v3) = sub_4E5FC0(this, 0);
            byte_B699B4 = 2;
            byte_B699BC = 2;
          }
          else
          {
            v3 -= 101;
            switch ( v3 )
            {
              case 0:
              case 101:
              case 201:
                sub_42A890();
                LOBYTE(v3) = sub_5401B0(&unk_BE1D30);
                goto LABEL_54;
              case 1:
              case 102:
              case 202:
                goto LABEL_43;
              case 99:
              case 199:
                goto LABEL_49;
              case 100:
              case 200:
                goto LABEL_58;
              default:
                return v3;
            }
          }
        }
        else if ( v3 == 100 )
        {
LABEL_49:
          LOBYTE(v3) = sub_42A6D0(byte_91DC48);
          if ( (_BYTE)v3 == 1 )
          {
            LOBYTE(v3) = byte_B6413C;
            if ( byte_B6413C )
              LOBYTE(v3) = sub_590060();
            byte_B699B4 = 2;
            byte_B699BC = 2;
          }
        }
        else
        {
          switch ( v3 )
          {
            case 0:
            case 5:
              goto LABEL_43;
            case 1:
              goto LABEL_56;
            case 2:
              goto LABEL_64;
            case 3:
              goto LABEL_54;
            case 4:
              goto LABEL_58;
            case 6:
              goto LABEL_62;
            default:
              return v3;
          }
        }
      }
      else if ( dword_B6B880 || (v9 = 1, v8 = 200, (unsigned __int8)sub_40DE70()) )
      {
        LOBYTE(v3) = sub_4E46F0();
      }
      else if ( dword_B6B8AC || (v7 = 1, v6 = 208, LOBYTE(v3) = sub_40DE70(), (_BYTE)v3) )
      {
        sub_5665A0(&v9, &v8, 0, v6);
        v3 = this[2] + 1;
        this[2] = v3;
        if ( v3 >= v7 )
          this[2] = v8;
      }
    }
  }
  return v3;
}
