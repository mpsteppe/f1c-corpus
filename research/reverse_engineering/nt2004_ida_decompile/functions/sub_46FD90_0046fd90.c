int __thiscall sub_46FD90(_DWORD *this)
{
  int result; // eax
  int *v3; // edx
  int v4; // ecx
  bool v5; // cc
  int v6; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  int v10; // eax
  int v11; // ecx

  result = (int)sub_46FBE0(this);
  v3 = (int *)this[210];
  if ( v3 )
  {
    result = this[215] - 454;
    switch ( this[215] )
    {
      case 0x1C6:
        v6 = dword_62A158;
        if ( dword_62A158 >= 0 )
        {
          if ( dword_62A158 > 3 )
            v6 = 3;
        }
        else
        {
          v6 = 0;
        }
        v7 = v6 + 1;
        if ( v6 + 1 > 4 )
          v7 = 4;
        result = 0;
        switch ( v7 )
        {
          case 1:
          case 2:
            goto LABEL_34;
          case 3:
            goto LABEL_35;
          case 4:
            goto LABEL_26;
          default:
            goto LABEL_37;
        }
        goto LABEL_37;
      case 0x1C8:
      case 0x1CF:
        goto LABEL_40;
      case 0x1C9:
        v8 = dword_62A158;
        if ( dword_62A158 >= 0 )
        {
          if ( dword_62A158 > 3 )
            v8 = 3;
        }
        else
        {
          v8 = 0;
        }
        v9 = v8 + 1;
        if ( v8 + 1 > 4 )
          v9 = 4;
        result = 0;
        switch ( v9 )
        {
          case 1:
          case 2:
            goto LABEL_34;
          case 3:
            goto LABEL_35;
          case 4:
LABEL_26:
            result = 3;
            break;
          default:
            goto LABEL_37;
        }
        goto LABEL_37;
      case 0x1CB:
        v10 = dword_62A158;
        if ( dword_62A158 >= 0 )
        {
          if ( dword_62A158 > 3 )
            v10 = 3;
        }
        else
        {
          v10 = 0;
        }
        v11 = v10 + 1;
        if ( v10 + 1 > 4 )
          v11 = 4;
        result = 0;
        switch ( v11 )
        {
          case 1:
          case 2:
LABEL_34:
            result = 1;
            break;
          case 3:
          case 4:
LABEL_35:
            result = 2;
            break;
          default:
            goto LABEL_37;
        }
        goto LABEL_37;
      case 0x1F2:
        result = dword_62A15C;
        v4 = 100;
        if ( dword_62A14C < 249 )
        {
          if ( dword_62A15C == 1 )
          {
            result = 0;
          }
          else if ( dword_62A15C > 2 )
          {
            result = 2;
          }
        }
        switch ( result )
        {
          case 0:
          case 1:
          case 2:
            result = *v3;
            v5 = *v3 <= 2;
            break;
          case 3:
            v4 = 3;
            goto LABEL_11;
          default:
LABEL_11:
            v5 = *v3 <= v4;
            break;
        }
        goto LABEL_38;
      default:
        result = dword_62A158;
LABEL_37:
        v5 = *v3 <= result;
LABEL_38:
        if ( v5 )
          goto LABEL_40;
        this[207] = 2;
        break;
    }
  }
  else
  {
LABEL_40:
    this[207] = 0;
  }
  return result;
}
