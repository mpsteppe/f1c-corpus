float *__thiscall sub_541AC0(void *this)
{
  _DWORD *v1; // ecx
  _DWORD *v2; // ecx
  float *v3; // esi
  float *v4; // ecx
  float *v5; // ecx
  float *result; // eax
  float *v7; // eax
  float *v8; // eax
  float *v9; // eax
  float *v10; // eax
  float *v11; // eax

  result = 0;
  switch ( (unsigned int)this )
  {
    case 1u:
      v7 = (float *)operator new(0x2Cu);
      if ( !v7 )
        goto LABEL_12;
      sub_5415D0(v7, 1.0);
      v1[7] = 0;
      v1[8] = 0;
      v1[9] = 0;
      v1[10] = 0;
      *v1 = &off_71E644;
      return (float *)v1;
    case 2u:
      v8 = (float *)operator new(0x28u);
      if ( !v8 )
        goto LABEL_12;
      sub_5415D0(v8, 1.0);
      *v2 = &off_71E654;
      v2[7] = 0;
      v2[8] = 0;
      v2[9] = 0;
      return (float *)v2;
    case 3u:
    case 4u:
      goto LABEL_12;
    case 5u:
      v9 = (float *)operator new(0x1Cu);
      if ( !v9 )
        goto LABEL_12;
      sub_5415D0(v9, 0.050000001);
      *(_DWORD *)v5 = &off_71E684;
      result = v5;
      break;
    case 6u:
      v10 = (float *)operator new(0x24u);
      if ( !v10 )
        goto LABEL_12;
      v3 = v10;
      sub_5415D0(v10, 5.0);
      *(_DWORD *)v3 = &off_71E664;
      rand();
      v3[7] = 0.0;
      v3[8] = 0.0;
      result = v3;
      break;
    case 7u:
      v11 = (float *)operator new(0x20u);
      if ( v11 )
      {
        sub_5415D0(v11, 1.7014117e38);
        *(_DWORD *)v4 = &off_71E674;
        v4[7] = 0.0;
        result = v4;
      }
      else
      {
LABEL_12:
        result = 0;
      }
      break;
    default:
      return result;
  }
  return result;
}
