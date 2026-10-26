float *__thiscall sub_4F0E20(void *this)
{
  _DWORD *v1; // ecx
  _DWORD *v2; // ecx
  float *v3; // esi
  float *result; // eax
  float *v5; // eax
  float *v6; // eax
  float *v7; // ecx
  float *v8; // ecx
  float *v9; // eax

  result = 0;
  switch ( (unsigned int)this )
  {
    case 1u:
      v5 = (float *)operator new(0x2Cu);
      if ( !v5 )
        goto LABEL_10;
      sub_4F0430(v5, 1.0);
      v1[7] = 0;
      v1[8] = 0;
      v1[9] = 0;
      v1[10] = 0;
      *v1 = &off_5EA7C8;
      return (float *)v1;
    case 2u:
      v6 = (float *)operator new(0x28u);
      if ( !v6 )
        goto LABEL_10;
      sub_4F0430(v6, 1.0);
      *v2 = &off_5EA7D8;
      v2[7] = 0;
      v2[8] = 0;
      v2[9] = 0;
      return (float *)v2;
    case 3u:
    case 4u:
      goto LABEL_10;
    case 5u:
      v7 = (float *)operator new(0x1Cu);
      if ( !v7 )
        goto LABEL_10;
      sub_4F0430(v7, 0.050000001);
      *(_DWORD *)v8 = &off_5EA7F8;
      result = v8;
      break;
    case 6u:
      v9 = (float *)operator new(0x24u);
      if ( v9 )
      {
        v3 = v9;
        sub_4F0430(v9, 5.0);
        *(_DWORD *)v3 = &off_5EA7E8;
        rand();
        v3[7] = 0.0;
        v3[8] = 0.0;
        result = v3;
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
