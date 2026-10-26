_DWORD *__thiscall sub_503DE0(void *this)
{
  _DWORD *result; // eax
  _DWORD *v2; // eax
  _DWORD *v3; // esi
  _DWORD *v4; // eax
  _DWORD *v5; // esi
  _DWORD *v6; // eax
  _DWORD *v7; // esi

  result = 0;
  switch ( (unsigned int)this )
  {
    case 0u:
      v2 = operator new(0x40u);
      v3 = v2;
      if ( !v2 )
        goto LABEL_10;
      *v2 = &off_5EA960;
      v2[1] = 2;
      *((_BYTE *)v2 + 8) = 1;
      v2[3] = 0;
      sub_506720(v2 + 6);
      *v3 = &off_5EA944;
      result = v3;
      break;
    case 1u:
      result = operator new(0x14u);
      if ( !result )
        goto LABEL_10;
      result[3] = 0;
      result[1] = 1;
      *((_BYTE *)result + 8) = 1;
      *result = &off_5EA928;
      break;
    case 2u:
      v4 = operator new(0x48u);
      v5 = v4;
      if ( !v4 )
        goto LABEL_10;
      *v4 = &off_5EA960;
      v4[1] = 0;
      *((_BYTE *)v4 + 8) = 1;
      v4[3] = 0;
      sub_506720(v4 + 4);
      *v5 = &off_5EA90C;
      result = v5;
      break;
    case 4u:
      v6 = operator new(0x230u);
      v7 = v6;
      if ( v6 )
      {
        v6[1] = 1;
        *((_BYTE *)v6 + 8) = 1;
        *v6 = &off_5EA960;
        v6[3] = 0;
        sub_506720(v6 + 60);
        sub_506720(v7 + 70);
        sub_506720(v7 + 80);
        sub_506720(v7 + 90);
        sub_506720(v7 + 100);
        sub_506720(v7 + 110);
        sub_506720(v7 + 120);
        sub_506720(v7 + 130);
        *v7 = &off_5EA8F0;
        result = v7;
      }
      else
      {
LABEL_10:
        result = 0;
      }
      break;
    default:
      return result;
  }
  return result;
}
