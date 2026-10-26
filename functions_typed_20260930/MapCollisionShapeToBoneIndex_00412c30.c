int __stdcall sub_412C30(int a1, int a2, int a3, char a4)
{
  int result; // eax
  int v5; // edx

  result = -1;
  if ( !a2 )
  {
    switch ( a3 )
    {
      case 1:
        v5 = 189 - (a4 != 0);
        goto LABEL_22;
      case 2:
        v5 = 187 - (a4 != 0);
        goto LABEL_22;
      case 3:
        v5 = 185 - (a4 != 0);
        goto LABEL_22;
      case 4:
        v5 = 183 - (a4 != 0);
        goto LABEL_22;
      case 5:
        v5 = 181 - (a4 != 0);
        goto LABEL_22;
      case 6:
        v5 = 179 - (a4 != 0);
        goto LABEL_22;
      case 7:
        v5 = 177 - (a4 != 0);
        goto LABEL_22;
      case 8:
        v5 = 175 - (a4 != 0);
        goto LABEL_22;
      case 9:
        v5 = 173 - (a4 != 0);
        goto LABEL_22;
      case 10:
        v5 = 171 - (a4 != 0);
        goto LABEL_22;
      case 11:
        v5 = 169 - (a4 != 0);
        goto LABEL_22;
      case 12:
        v5 = 167 - (a4 != 0);
        goto LABEL_22;
      case 15:
        v5 = 165 - (a4 != 0);
        goto LABEL_22;
      case 20:
        v5 = 163 - (a4 != 0);
        goto LABEL_22;
      case 25:
        v5 = 161 - (a4 != 0);
        goto LABEL_22;
      case 30:
        v5 = 159 - (a4 != 0);
        goto LABEL_22;
      case 35:
        v5 = 157 - (a4 != 0);
        goto LABEL_22;
      case 40:
        v5 = 155 - (a4 != 0);
        goto LABEL_22;
      case 50:
        v5 = 153 - (a4 != 0);
LABEL_22:
        if ( v5 >= 0 )
        {
          *(_DWORD *)(a1 + 8) = v5;
          *(_DWORD *)(a1 + 12) = sub_414180(0);
          result = 1;
        }
        break;
      default:
        return result;
    }
  }
  return result;
}

