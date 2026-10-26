int __thiscall sub_530050(_DWORD *this, char *a2, _DWORD *a3, int a4, int a5, __int16 *a6)
{
  float *v9; // edi
  int v10; // ecx
  int v11; // esi
  unsigned __int32 v12; // eax
  unsigned __int32 v13; // eax
  unsigned __int32 v14; // eax
  unsigned __int32 v15; // eax
  int v16; // ecx
  int v17; // esi
  unsigned __int8 *v18; // eax
  int v19; // ecx
  int result; // eax
  __int16 v21; // [esp+8h] [ebp-18h]
  char *v22; // [esp+Ch] [ebp-14h]
  int v23; // [esp+14h] [ebp-Ch]
  int v24; // [esp+18h] [ebp-8h]
  float *v25; // [esp+1Ch] [ebp-4h]
  int v26; // [esp+28h] [ebp+8h]
  int v27; // [esp+28h] [ebp+8h]
  float v28; // [esp+2Ch] [ebp+Ch]

  v24 = 0;
  if ( (int)this[2350] > 0 )
  {
    v25 = (float *)(a3 + 64);
    do
    {
      v23 = 0;
      v21 = *a6;
      if ( (int)this[2355] > 0 )
      {
        v9 = v25;
        do
        {
          v10 = *a2++;
          v22 = a2;
          if ( v10 )
          {
            v11 = a6[2 * v10];
            v26 = a6[2 * v10 + 1];
            if ( v26 >= 0 )
            {
              v15 = dword_5B4788[v11]
                  & (_byteswap_ulong(*(_DWORD *)(this[2345] + ((int)this[2346] >> 3))) >> -(char)(v11 + (this[2346] & 7)));
              v16 = v11 + this[2346];
              v17 = *(char *)(a4 + a5);
              this[2346] = v16;
              v18 = (unsigned __int8 *)(3 * v15 + dword_5DA738[v26]);
              v19 = v17 + (*v18++ << 6);
              *(v9 - 64) = flt_5B10A4[v19];
              *v9 = flt_5B10A4[64 * *v18 + v17];
              v9[64] = flt_5B10A4[64 * v18[1] + v17];
              a4 += 3;
              a2 = v22;
            }
            else
            {
              v28 = flt_5B10A4[64 * v11 + *(char *)(a4 + a5)];
              v12 = dword_5B4788[v11]
                  & (_byteswap_ulong(*(_DWORD *)(((int)this[2346] >> 3) + this[2345])) >> -(char)(v11 + (this[2346] & 7)));
              this[2346] += v11;
              *(v9 - 64) = (double)(int)(v26 + v12) * v28;
              v13 = dword_5B4788[v11]
                  & (_byteswap_ulong(*(_DWORD *)(((int)this[2346] >> 3) + this[2345])) >> -(char)(v11 + (this[2346] & 7)));
              this[2346] += v11;
              *v9 = (double)(int)(v26 + v13) * v28;
              v14 = dword_5B4788[v11]
                  & (_byteswap_ulong(*(_DWORD *)(((int)this[2346] >> 3) + this[2345])) >> -(char)(v11 + (this[2346] & 7)));
              this[2346] += v11;
              v27 = v26 + v14;
              a4 += 3;
              a2 = v22;
              v9[64] = (double)v27 * v28;
            }
          }
          else
          {
            v9[64] = 0.0;
            *v9 = 0.0;
            *(v9 - 64) = 0.0;
          }
          v9 += 32;
          ++v23;
        }
        while ( v23 < this[2355] );
      }
      ++v24;
      ++v25;
      a6 += 2 * (1 << v21);
    }
    while ( v24 < this[2350] );
  }
  switch ( this[2350] )
  {
    case 0:
      a3[128] = 0;
      a3[64] = 0;
      *a3 = 0;
      goto LABEL_14;
    case 1:
LABEL_14:
      a3[129] = 0;
      a3[65] = 0;
      a3[1] = 0;
      goto LABEL_15;
    case 2:
LABEL_15:
      a3[130] = 0;
      a3[66] = 0;
      a3[2] = 0;
      goto LABEL_16;
    case 3:
LABEL_16:
      a3[131] = 0;
      a3[67] = 0;
      a3[3] = 0;
      goto LABEL_17;
    case 4:
LABEL_17:
      a3[132] = 0;
      a3[68] = 0;
      a3[4] = 0;
      goto LABEL_18;
    case 5:
LABEL_18:
      a3[133] = 0;
      a3[69] = 0;
      a3[5] = 0;
      goto LABEL_19;
    case 6:
LABEL_19:
      a3[134] = 0;
      a3[70] = 0;
      a3[6] = 0;
      goto LABEL_20;
    case 7:
LABEL_20:
      a3[135] = 0;
      a3[71] = 0;
      a3[7] = 0;
      goto LABEL_21;
    case 8:
LABEL_21:
      a3[136] = 0;
      a3[72] = 0;
      a3[8] = 0;
      goto LABEL_22;
    case 9:
LABEL_22:
      a3[137] = 0;
      a3[73] = 0;
      a3[9] = 0;
      goto LABEL_23;
    case 0xA:
LABEL_23:
      a3[138] = 0;
      a3[74] = 0;
      a3[10] = 0;
      goto LABEL_24;
    case 0xB:
LABEL_24:
      a3[139] = 0;
      a3[75] = 0;
      a3[11] = 0;
      goto LABEL_25;
    case 0xC:
LABEL_25:
      a3[140] = 0;
      a3[76] = 0;
      a3[12] = 0;
      goto LABEL_26;
    case 0xD:
LABEL_26:
      a3[141] = 0;
      a3[77] = 0;
      a3[13] = 0;
      goto LABEL_27;
    case 0xE:
LABEL_27:
      a3[142] = 0;
      a3[78] = 0;
      a3[14] = 0;
      goto LABEL_28;
    case 0xF:
LABEL_28:
      a3[143] = 0;
      a3[79] = 0;
      a3[15] = 0;
      goto LABEL_29;
    case 0x10:
LABEL_29:
      a3[144] = 0;
      a3[80] = 0;
      a3[16] = 0;
      goto LABEL_30;
    case 0x11:
LABEL_30:
      a3[145] = 0;
      a3[81] = 0;
      a3[17] = 0;
      goto LABEL_31;
    case 0x12:
LABEL_31:
      a3[146] = 0;
      a3[82] = 0;
      a3[18] = 0;
      goto LABEL_32;
    case 0x13:
LABEL_32:
      a3[147] = 0;
      a3[83] = 0;
      a3[19] = 0;
      goto LABEL_33;
    case 0x14:
LABEL_33:
      a3[148] = 0;
      a3[84] = 0;
      a3[20] = 0;
      goto LABEL_34;
    case 0x15:
LABEL_34:
      a3[149] = 0;
      a3[85] = 0;
      a3[21] = 0;
      goto LABEL_35;
    case 0x16:
LABEL_35:
      a3[150] = 0;
      a3[86] = 0;
      a3[22] = 0;
      goto LABEL_36;
    case 0x17:
LABEL_36:
      a3[151] = 0;
      a3[87] = 0;
      a3[23] = 0;
      goto LABEL_37;
    case 0x18:
LABEL_37:
      a3[152] = 0;
      a3[88] = 0;
      a3[24] = 0;
      goto LABEL_38;
    case 0x19:
LABEL_38:
      a3[153] = 0;
      a3[89] = 0;
      a3[25] = 0;
      goto LABEL_39;
    case 0x1A:
LABEL_39:
      a3[154] = 0;
      a3[90] = 0;
      a3[26] = 0;
      goto LABEL_40;
    case 0x1B:
LABEL_40:
      a3[155] = 0;
      a3[91] = 0;
      a3[27] = 0;
      goto LABEL_41;
    case 0x1C:
LABEL_41:
      a3[156] = 0;
      a3[92] = 0;
      a3[28] = 0;
      goto LABEL_42;
    case 0x1D:
LABEL_42:
      a3[157] = 0;
      a3[93] = 0;
      a3[29] = 0;
      goto LABEL_43;
    case 0x1E:
LABEL_43:
      a3[158] = 0;
      a3[94] = 0;
      a3[30] = 0;
      break;
    case 0x1F:
      break;
  }
  a3[159] = 0;
  a3[95] = 0;
  a3[31] = 0;
  result = this[2355];
  if ( result == 2 )
  {
    switch ( this[2350] )
    {
      case 0:
        a3[160] = 0;
        a3[96] = 0;
        a3[32] = 0;
        goto LABEL_47;
      case 1:
LABEL_47:
        a3[161] = 0;
        a3[97] = 0;
        a3[33] = 0;
        goto LABEL_48;
      case 2:
LABEL_48:
        a3[162] = 0;
        a3[98] = 0;
        a3[34] = 0;
        goto LABEL_49;
      case 3:
LABEL_49:
        a3[163] = 0;
        a3[99] = 0;
        a3[35] = 0;
        goto LABEL_50;
      case 4:
LABEL_50:
        a3[164] = 0;
        a3[100] = 0;
        a3[36] = 0;
        goto LABEL_51;
      case 5:
LABEL_51:
        a3[165] = 0;
        a3[101] = 0;
        a3[37] = 0;
        goto LABEL_52;
      case 6:
LABEL_52:
        a3[166] = 0;
        a3[102] = 0;
        a3[38] = 0;
        goto LABEL_53;
      case 7:
LABEL_53:
        a3[167] = 0;
        a3[103] = 0;
        a3[39] = 0;
        goto LABEL_54;
      case 8:
LABEL_54:
        a3[168] = 0;
        a3[104] = 0;
        a3[40] = 0;
        goto LABEL_55;
      case 9:
LABEL_55:
        a3[169] = 0;
        a3[105] = 0;
        a3[41] = 0;
        goto LABEL_56;
      case 0xA:
LABEL_56:
        a3[170] = 0;
        a3[106] = 0;
        a3[42] = 0;
        goto LABEL_57;
      case 0xB:
LABEL_57:
        a3[171] = 0;
        a3[107] = 0;
        a3[43] = 0;
        goto LABEL_58;
      case 0xC:
LABEL_58:
        a3[172] = 0;
        a3[108] = 0;
        a3[44] = 0;
        goto LABEL_59;
      case 0xD:
LABEL_59:
        a3[173] = 0;
        a3[109] = 0;
        a3[45] = 0;
        goto LABEL_60;
      case 0xE:
LABEL_60:
        a3[174] = 0;
        a3[110] = 0;
        a3[46] = 0;
        goto LABEL_61;
      case 0xF:
LABEL_61:
        a3[175] = 0;
        a3[111] = 0;
        a3[47] = 0;
        goto LABEL_62;
      case 0x10:
LABEL_62:
        a3[176] = 0;
        a3[112] = 0;
        a3[48] = 0;
        goto LABEL_63;
      case 0x11:
LABEL_63:
        a3[177] = 0;
        a3[113] = 0;
        a3[49] = 0;
        goto LABEL_64;
      case 0x12:
LABEL_64:
        a3[178] = 0;
        a3[114] = 0;
        a3[50] = 0;
        goto LABEL_65;
      case 0x13:
LABEL_65:
        a3[179] = 0;
        a3[115] = 0;
        a3[51] = 0;
        goto LABEL_66;
      case 0x14:
LABEL_66:
        a3[180] = 0;
        a3[116] = 0;
        a3[52] = 0;
        goto LABEL_67;
      case 0x15:
LABEL_67:
        a3[181] = 0;
        a3[117] = 0;
        a3[53] = 0;
        goto LABEL_68;
      case 0x16:
LABEL_68:
        a3[182] = 0;
        a3[118] = 0;
        a3[54] = 0;
        goto LABEL_69;
      case 0x17:
LABEL_69:
        a3[183] = 0;
        a3[119] = 0;
        a3[55] = 0;
        goto LABEL_70;
      case 0x18:
LABEL_70:
        a3[184] = 0;
        a3[120] = 0;
        a3[56] = 0;
        goto LABEL_71;
      case 0x19:
LABEL_71:
        a3[185] = 0;
        a3[121] = 0;
        a3[57] = 0;
        goto LABEL_72;
      case 0x1A:
LABEL_72:
        a3[186] = 0;
        a3[122] = 0;
        a3[58] = 0;
        goto LABEL_73;
      case 0x1B:
LABEL_73:
        a3[187] = 0;
        a3[123] = 0;
        a3[59] = 0;
        goto LABEL_74;
      case 0x1C:
LABEL_74:
        a3[188] = 0;
        a3[124] = 0;
        a3[60] = 0;
        goto LABEL_75;
      case 0x1D:
LABEL_75:
        a3[189] = 0;
        a3[125] = 0;
        a3[61] = 0;
        goto LABEL_76;
      case 0x1E:
LABEL_76:
        a3[190] = 0;
        a3[126] = 0;
        a3[62] = 0;
        break;
      case 0x1F:
        break;
    }
    a3[191] = 0;
    a3[127] = 0;
    a3[63] = 0;
  }
  return result;
}

