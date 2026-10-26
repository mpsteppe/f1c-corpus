int __stdcall sub_49F530(unsigned int a1, int a2, int a3)
{
  double v5; // st7
  int result; // eax
  int v7; // [esp+0h] [ebp-Ch]
  float v8; // [esp+10h] [ebp+4h]
  float v9; // [esp+18h] [ebp+Ch]

  if ( a1 <= 4 && a3 )
  {
    switch ( a1 )
    {
      case 0u:
        v8 = 0.0;
        v9 = 10000.0;
        v5 = sub_49B8D0();
        goto LABEL_9;
      case 1u:
        v8 = 120.0;
        v5 = dbl_7C91B4 - 273.16;
        v9 = 280.0;
        goto LABEL_9;
      case 2u:
        v8 = 120.0;
        v5 = dbl_7C9174 - 273.16;
        v9 = 280.0;
        goto LABEL_9;
      case 3u:
        v5 = dbl_7C919C;
        v8 = -3.0;
        v9 = 100.0;
        goto LABEL_9;
      case 4u:
        v8 = 0.0;
        v9 = 12.0;
        v5 = sub_447BB0(&dbl_7C7428);
LABEL_9:
        switch ( a1 )
        {
          case 1u:
          case 2u:
            v5 = (v5 - -40.0) * 1.8 - 40.0;
            break;
          case 3u:
          case 4u:
            v5 = v5 * 0.14503774;
            break;
          default:
            break;
        }
        if ( v5 >= v8 )
        {
          if ( v5 > v9 )
            v5 = v9;
        }
        else
        {
          v5 = v8;
        }
        *(float *)(a2 + 32) = v9 - v8;
        *(float *)&v7 = v5 - v8;
        sub_49ED00((_DWORD *)a2, v7);
        sub_49ED10((_DWORD *)a2, a3);
        result = sub_49ED20((_DWORD *)a2, a3);
        break;
      default:
        return result;
    }
  }
  return result;
}
