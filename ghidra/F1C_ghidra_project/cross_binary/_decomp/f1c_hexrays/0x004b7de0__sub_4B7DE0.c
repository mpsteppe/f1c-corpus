// f1c  0x004b7de0  size=543
char __thiscall sub_4B7DE0(_DWORD *this)
{
  char v2; // bl
  const char *v3; // ecx
  char *v4; // eax
  int v5; // eax
  char v6; // cl
  char *v7; // edi
  CHAR v8; // cl
  int v9; // eax
  int v10; // edx
  int v11; // eax
  char v12; // cl
  float v14; // [esp+Ch] [ebp-228h]
  float v15; // [esp+10h] [ebp-224h]
  float v16; // [esp+14h] [ebp-220h]
  int v17[7]; // [esp+18h] [ebp-21Ch] BYREF
  char v18[512]; // [esp+34h] [ebp-200h] BYREF

  v2 = 0;
  v14 = *(float *)(dword_7C54E8 + 16540);
  if ( v14 != -1.0 && v14 > 0.0 )
  {
    v3 = (const char *)this[451];
    v15 = *(float *)(dword_7C54E8 + 16564);
    v16 = v15 + v14;
    if ( !v3 )
      v3 = byte_5EA438;
    strcpy(v18, v3);
    v4 = &v18[strlen(v18)];
    if ( v4 > v18 )
    {
      while ( *v4 != 46 )
      {
        if ( --v4 <= v18 )
          goto LABEL_10;
      }
      *v4 = 0;
    }
LABEL_10:
    *(_WORD *)&v18[strlen(v18)] = word_5C32D8;
    if ( sub_423A00(byte_5EC4C0, aHotLap, byte_5EC4CC) )
    {
      v5 = 0;
      do
      {
        v6 = aHotLap[v5];
        byte_5EC4CC[v5++] = v6;
      }
      while ( v6 );
    }
    strcat(v18, byte_5EC4CC);
    v7 = &v18[strlen(v18) + 1];
    v8 = FileName[4];
    *(_DWORD *)--v7 = *(_DWORD *)FileName;
    v7[4] = v8;
    sub_5668B0(v17);
    switch ( this[617] )
    {
      case 0:
        v9 = 0;
        break;
      case 1:
        v9 = 1;
        break;
      case 2:
        v9 = 2;
        break;
      case 3:
        v9 = 3;
        break;
      default:
        v9 = 4;
        break;
    }
    if ( (unsigned __int8)sub_566940(v18, v9, 0, 1) )
    {
      if ( sub_423A00(byte_5EC4C0, aSavingHotlap, byte_5EC4CC) )
      {
        v11 = 0;
        do
        {
          v12 = aSavingHotlap[v11];
          byte_5EC4CC[v11++] = v12;
        }
        while ( v12 );
      }
      sub_4A0E70((int)&unk_7CE24D, v10, byte_5EC4CC);
      if ( !sub_4B6A10((int)this, (int)v17, v15, v16)
        || (v2 = 1, !sub_4B7C80(this, (int)(this + 441), (int)v17, v15, v16)) )
      {
        v2 = 0;
      }
      sub_566B90(v17);
    }
    sub_5668D0(v17);
  }
  return v2;
}
