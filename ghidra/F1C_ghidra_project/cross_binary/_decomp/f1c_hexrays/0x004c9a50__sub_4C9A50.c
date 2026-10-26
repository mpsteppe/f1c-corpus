// f1c  0x004c9a50  size=163
float *__thiscall sub_4C9A50(void *this)
{
  _DWORD *v1; // ecx
  _DWORD *v2; // ecx
  float *v3; // esi
  int v4; // ecx
  float *result; // eax
  float *v6; // eax
  float *v7; // eax
  float *v8; // ecx
  float *v9; // ecx
  float *v10; // eax
  float *v11; // ecx
  float *v12; // ecx

  result = 0;
  switch ( (unsigned int)this )
  {
    case 1u:
      v6 = (float *)sub_587C03(44);
      if ( !v6 )
        goto LABEL_12;
      sub_4C8F10(v6, 1.0);
      v1[7] = 0;
      v1[8] = 0;
      v1[9] = 0;
      v1[10] = 0;
      *v1 = &off_5ACE3C;
      return (float *)v1;
    case 2u:
      v7 = (float *)sub_587C03(40);
      if ( !v7 )
        goto LABEL_12;
      sub_4C8F10(v7, 1.0);
      *v2 = &off_5ACE4C;
      v2[7] = 0;
      v2[8] = 0;
      v2[9] = 0;
      return (float *)v2;
    case 3u:
    case 4u:
      goto LABEL_12;
    case 5u:
      v8 = (float *)sub_587C03(28);
      if ( !v8 )
        goto LABEL_12;
      sub_4C8F10(v8, 0.050000001);
      *(_DWORD *)v9 = &off_5ACE7C;
      result = v9;
      break;
    case 6u:
      v10 = (float *)sub_587C03(36);
      if ( !v10 )
        goto LABEL_12;
      v3 = v10;
      sub_4C8F10(v10, 5.0);
      *(_DWORD *)v3 = &off_5ACE5C;
      sub_5884ED(v4);
      v3[7] = 0.0;
      v3[8] = 0.0;
      result = v3;
      break;
    case 7u:
      v11 = (float *)sub_587C03(32);
      if ( v11 )
      {
        sub_4C8F10(v11, 1.7014117e38);
        *(_DWORD *)v12 = &off_5ACE6C;
        v12[7] = 0.0;
        result = v12;
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
