char __thiscall sub_4D78B0(_DWORD *this)
{
  const char *v2; // ecx
  char *v3; // eax
  char *v4; // edi
  CHAR v5; // cl
  int v6; // eax
  char v8; // [esp+7h] [ebp-229h]
  float v9; // [esp+8h] [ebp-228h]
  float v10; // [esp+Ch] [ebp-224h]
  float v11; // [esp+10h] [ebp-220h]
  int v12[7]; // [esp+14h] [ebp-21Ch] BYREF
  char Source[512]; // [esp+30h] [ebp-200h] BYREF

  v9 = *(float *)(dword_75AACC + 20960);
  v8 = 0;
  if ( v9 == -1.0 || v9 <= 0.0 )
    return 0;
  v2 = (const char *)this[231];
  v10 = *(float *)(dword_75AACC + 20984);
  v11 = v10 + v9;
  if ( !v2 )
    v2 = &byte_629120;
  strcpy(Source, v2);
  v3 = &Source[strlen(Source)];
  if ( v3 > Source )
  {
    while ( *v3 != 46 )
    {
      if ( --v3 <= Source )
        goto LABEL_10;
    }
    *v3 = 0;
  }
LABEL_10:
  *(_WORD *)&Source[strlen(Source)] = *(_WORD *)word_5FBEBC;
  if ( sub_41F230(dword_62A170, aHotLap, Destination) )
  {
    strncpy(Destination, aHotLap, 0x1FFu);
    byte_62A37B = 0;
  }
  strcat(Source, Destination);
  v4 = &Source[strlen(Source) + 1];
  v5 = aVcr[4];
  *(_DWORD *)--v4 = *(_DWORD *)aVcr;
  v4[4] = v5;
  sub_57A080(v12);
  switch ( this[327] )
  {
    case 0:
      v6 = 0;
      break;
    case 1:
      v6 = 1;
      break;
    case 2:
      v6 = 2;
      break;
    case 3:
      v6 = 3;
      break;
    default:
      v6 = 4;
      break;
  }
  if ( (unsigned __int8)sub_57A110(Source, v6, 0, 1) )
  {
    if ( sub_41F230(dword_62A170, aSavingHotLap, Destination) )
    {
      strncpy(Destination, aSavingHotLap, 0x1FFu);
      byte_62A37B = 0;
    }
    sub_4BA730(Destination, 1065353216, 1);
    if ( sub_4D63D0((int)this, (int)v12, v10, v11, 1) )
    {
      if ( sub_4D7750(this, (int)(this + 221), (int)v12, v10, v11) )
        v8 = 1;
    }
    sub_57A360(v12);
  }
  sub_57A0A0(v12);
  return v8;
}
