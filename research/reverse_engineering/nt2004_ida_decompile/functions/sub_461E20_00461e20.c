void __thiscall sub_461E20(int this, char a2)
{
  int v3; // esi
  __int16 v4; // ax
  char *v5; // eax
  int v6; // eax
  int v7; // esi
  char *v8; // eax
  const char *v9; // edx
  const char *v10; // ecx
  char *v11; // eax
  const char *v12; // eax
  char *v13; // eax
  char v14; // al
  char *v15; // edi
  char v16; // al
  float v17; // [esp+0h] [ebp-350h]
  int v18; // [esp+18h] [ebp-338h] BYREF
  int v19; // [esp+1Ch] [ebp-334h]
  float v20; // [esp+20h] [ebp-330h]
  unsigned int v21; // [esp+24h] [ebp-32Ch] BYREF
  __int16 v22; // [esp+2Ch] [ebp-324h]
  __int16 v23; // [esp+2Eh] [ebp-322h]
  int v24; // [esp+30h] [ebp-320h]
  int v25; // [esp+34h] [ebp-31Ch]
  int v26; // [esp+38h] [ebp-318h]
  char Destination[184]; // [esp+3Ch] [ebp-314h] BYREF
  _BYTE v28[32]; // [esp+F4h] [ebp-25Ch] BYREF
  _BYTE v29[60]; // [esp+114h] [ebp-23Ch] BYREF
  char Buffer[509]; // [esp+150h] [ebp-200h] BYREF
  __int16 v31; // [esp+34Dh] [ebp-3h]
  char v32; // [esp+34Fh] [ebp-1h]

  sub_45D890((_BYTE *)(this + 30092), *(_BYTE *)(this + 30112), *(_BYTE *)(this + 30113));
  if ( *(_BYTE *)(this + 33) && *(float *)(this + 36) < 0.0 )
  {
    sub_462C80(v28);
    if ( !(unsigned __int8)sub_464BD0(v28) || (v3 = dword_7D6B58 + 400 * dword_7D6B54, v3 == sub_4E8DA0(v29)) )
    {
      v17 = dbl_7DA9D0;
      sub_4D0D00(4, 36, 16, 0, LODWORD(v17), 3);
      v4 = sub_461DF0(*(_BYTE *)(this + 30112), *(_BYTE *)(this + 30113));
      v20 = dbl_7DA9D0;
      v22 = v4;
      v19 = (int)v20;
      v23 = ((v19 & 0xFFFC) << 6) + (unsigned __int8)rand();
      v5 = dword_7665D8;
      if ( !dword_7665D8 )
        v5 = &byte_629120;
      v6 = sub_4E7790(v5);
      v7 = v6;
      if ( !v6 )
        goto LABEL_25;
      v8 = *(char **)(v6 + 8);
      if ( !v8 )
        v8 = &byte_629120;
      if ( sub_45D8D0((unsigned __int8 *)(this + 30092), v8, &v18, 1) )
      {
        v24 = v18;
        if ( a2 )
        {
          v9 = *(const char **)(v7 + 8);
          if ( !v9 )
            v9 = &byte_629120;
          v10 = &v9[strlen(v9)];
          if ( v10 > v9 )
          {
            while ( *v10 != 92 )
            {
              if ( --v10 <= v9 )
                goto LABEL_19;
            }
            ++v10;
          }
LABEL_19:
          strncpy(Destination, v10, 0x3Fu);
          Destination[63] = 0;
          v11 = &Destination[strlen(Destination)];
          if ( v11 > Destination )
          {
            while ( *v11 != 46 )
            {
              if ( --v11 <= Destination )
                goto LABEL_24;
            }
            *v11 = 0;
          }
LABEL_24:
          v21 = v21 & 0xFFFF003F | ((strlen(Destination) + 17) << 6);
        }
      }
      else
      {
LABEL_25:
        v24 = 0;
      }
      Buffer[0] = byte_629120;
      memset(&Buffer[1], 0, 0x1FCu);
      v31 = 0;
      v32 = 0;
      sub_4F6A10(Buffer, 512);
      if ( sub_45D8A0((unsigned __int8 *)(this + 30092), Buffer, &v18) )
        v25 = dword_7D741C + v18 + 305986170;
      else
        v25 = 0;
      v12 = dword_766578;
      if ( !dword_766578 )
        v12 = &byte_629120;
      strncpy(Buffer, v12, 0x1FFu);
      v32 = 0;
      v13 = &Buffer[strlen(Buffer)];
      if ( v13 > Buffer )
      {
        while ( *v13 != 46 )
        {
          if ( --v13 <= Buffer )
            goto LABEL_36;
        }
        *v13 = 0;
      }
LABEL_36:
      v14 = byte_5FFC78;
      v15 = &Buffer[strlen(Buffer)];
      *(_DWORD *)v15 = dword_5FFC74;
      v15[4] = v14;
      v16 = sub_45DBD0((unsigned __int8 *)(this + 30092), Buffer, &v18);
      v26 = v16 != 0 ? v18 : 0;
      sub_463A40(&v21, 2, -1, -1);
    }
    nullsub_6(v28);
  }
}
