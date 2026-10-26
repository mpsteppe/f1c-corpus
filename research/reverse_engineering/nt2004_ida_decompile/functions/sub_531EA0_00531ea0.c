int __thiscall sub_531EA0(_DWORD *this, int a2, _BYTE *a3, _WORD *a4, char *a5, __int16 *a6)
{
  _WORD *v9; // ebx
  _BYTE *v10; // ecx
  int v11; // eax
  int v12; // esi
  unsigned __int32 v13; // eax
  unsigned __int32 v14; // eax
  unsigned __int32 v15; // eax
  int v16; // eax
  unsigned __int32 v17; // eax
  int v18; // ecx
  unsigned __int8 *v19; // eax
  int v20; // eax
  int v21; // esi
  unsigned __int32 v22; // eax
  unsigned __int32 v23; // eax
  unsigned __int32 v24; // eax
  int v25; // eax
  unsigned __int32 v26; // eax
  int v27; // ecx
  unsigned __int8 *v28; // eax
  int result; // eax
  __int16 v30; // [esp+8h] [ebp-10h]
  int v31; // [esp+10h] [ebp-8h]
  _BYTE *v32; // [esp+14h] [ebp-4h]
  int v33; // [esp+24h] [ebp+Ch]
  int v34; // [esp+24h] [ebp+Ch]
  int v35; // [esp+28h] [ebp+10h]
  int v36; // [esp+28h] [ebp+10h]
  int v37; // [esp+28h] [ebp+10h]
  int v38; // [esp+28h] [ebp+10h]

  v31 = 0;
  if ( (int)this[2350] > 0 )
  {
    v9 = a4 + 64;
    while ( 1 )
    {
      v10 = a3 + 1;
      v32 = v10;
      v30 = *a6;
      v11 = (char)*(v10 - 1);
      if ( *(v10 - 1) )
        break;
      v9[64] = 0;
      *v9 = 0;
      *(v9 - 64) = 0;
LABEL_12:
      if ( this[2355] != 2 )
        goto LABEL_21;
      v20 = (char)*v10;
      v32 = v10 + 1;
      if ( *v10 )
      {
        v21 = a6[2 * v20];
        v34 = a6[2 * v20 + 1];
        if ( v34 < 0 )
        {
          v37 = *(_DWORD *)(a2 + 4 * (*a5 + (v21 << 6)));
          v22 = dword_5EE360[v21]
              & (_byteswap_ulong(*(_DWORD *)(((int)this[2346] >> 3) + this[2345])) >> -(char)(v21 + (this[2346] & 7)));
          this[2346] += v21;
          *(v9 - 32) = (int)(v37 * (v34 + v22)) >> 12;
          v23 = dword_5EE360[v21]
              & (_byteswap_ulong(*(_DWORD *)(((int)this[2346] >> 3) + this[2345])) >> -(char)(v21 + (this[2346] & 7)));
          this[2346] += v21;
          v9[32] = (int)(v37 * (v34 + v23)) >> 12;
          v24 = dword_5EE360[v21]
              & (_byteswap_ulong(*(_DWORD *)(((int)this[2346] >> 3) + this[2345])) >> -(char)(v21 + (this[2346] & 7)));
          this[2346] += v21;
          v25 = v37 * (v34 + v24);
          goto LABEL_18;
        }
        v38 = *a5;
        v26 = dword_5EE360[v21]
            & (_byteswap_ulong(*(_DWORD *)(((int)this[2346] >> 3) + this[2345])) >> -(char)(v21 + (this[2346] & 7)));
        this[2346] += v21;
        v27 = dword_615940[v34];
        v28 = (unsigned __int8 *)(v27 + 2 * v26 + v26);
        if ( v27 )
        {
          *(v9 - 32) = *(int *)(a2 + 4 * (v38 + (*v28 << 6))) >> 12;
          v9[32] = *(int *)(a2 + 4 * (v38 + (v28[1] << 6))) >> 12;
          v25 = *(_DWORD *)(a2 + 4 * (v38 + (v28[2] << 6)));
LABEL_18:
          v9[96] = v25 >> 12;
        }
        a5 += 3;
        goto LABEL_21;
      }
      v9[96] = 0;
      v9[32] = 0;
      *(v9 - 32) = 0;
LABEL_21:
      ++v9;
      ++v31;
      a6 += 2 * (1 << v30);
      if ( v31 >= this[2350] )
        goto LABEL_22;
      a3 = v32;
    }
    v12 = a6[2 * v11];
    v33 = a6[2 * v11 + 1];
    if ( v33 >= 0 )
    {
      v36 = *a5;
      v17 = dword_5EE360[v12]
          & (_byteswap_ulong(*(_DWORD *)(((int)this[2346] >> 3) + this[2345])) >> -(char)(v12 + (this[2346] & 7)));
      this[2346] += v12;
      v18 = dword_615940[v33];
      v19 = (unsigned __int8 *)(v18 + 2 * v17 + v17);
      if ( !v18 )
      {
LABEL_10:
        v10 = v32;
        a5 += 3;
        goto LABEL_12;
      }
      *(v9 - 64) = *(int *)(a2 + 4 * (v36 + (*v19 << 6))) >> 12;
      *v9 = *(int *)(a2 + 4 * (v36 + (v19[1] << 6))) >> 12;
      v16 = *(_DWORD *)(a2 + 4 * (v36 + (v19[2] << 6)));
    }
    else
    {
      v35 = *(_DWORD *)(a2 + 4 * (*a5 + (v12 << 6)));
      v13 = dword_5EE360[v12]
          & (_byteswap_ulong(*(_DWORD *)(((int)this[2346] >> 3) + this[2345])) >> -(char)(v12 + (this[2346] & 7)));
      this[2346] += v12;
      *(v9 - 64) = (int)(v35 * (v33 + v13)) >> 12;
      v14 = dword_5EE360[v12]
          & (_byteswap_ulong(*(_DWORD *)(((int)this[2346] >> 3) + this[2345])) >> -(char)(v12 + (this[2346] & 7)));
      this[2346] += v12;
      *v9 = (int)(v35 * (v33 + v14)) >> 12;
      v15 = dword_5EE360[v12]
          & (_byteswap_ulong(*(_DWORD *)(((int)this[2346] >> 3) + this[2345])) >> -(char)(v12 + (this[2346] & 7)));
      this[2346] += v12;
      v16 = v35 * (v33 + v15);
    }
    v9[64] = v16 >> 12;
    goto LABEL_10;
  }
LABEL_22:
  switch ( this[2350] )
  {
    case 0:
      a4[128] = 0;
      a4[64] = 0;
      *a4 = 0;
      goto LABEL_24;
    case 1:
LABEL_24:
      a4[129] = 0;
      a4[65] = 0;
      a4[1] = 0;
      goto LABEL_25;
    case 2:
LABEL_25:
      a4[130] = 0;
      a4[66] = 0;
      a4[2] = 0;
      goto LABEL_26;
    case 3:
LABEL_26:
      a4[131] = 0;
      a4[67] = 0;
      a4[3] = 0;
      goto LABEL_27;
    case 4:
LABEL_27:
      a4[132] = 0;
      a4[68] = 0;
      a4[4] = 0;
      goto LABEL_28;
    case 5:
LABEL_28:
      a4[133] = 0;
      a4[69] = 0;
      a4[5] = 0;
      goto LABEL_29;
    case 6:
LABEL_29:
      a4[134] = 0;
      a4[70] = 0;
      a4[6] = 0;
      goto LABEL_30;
    case 7:
LABEL_30:
      a4[135] = 0;
      a4[71] = 0;
      a4[7] = 0;
      goto LABEL_31;
    case 8:
LABEL_31:
      a4[136] = 0;
      a4[72] = 0;
      a4[8] = 0;
      goto LABEL_32;
    case 9:
LABEL_32:
      a4[137] = 0;
      a4[73] = 0;
      a4[9] = 0;
      goto LABEL_33;
    case 0xA:
LABEL_33:
      a4[138] = 0;
      a4[74] = 0;
      a4[10] = 0;
      goto LABEL_34;
    case 0xB:
LABEL_34:
      a4[139] = 0;
      a4[75] = 0;
      a4[11] = 0;
      goto LABEL_35;
    case 0xC:
LABEL_35:
      a4[140] = 0;
      a4[76] = 0;
      a4[12] = 0;
      goto LABEL_36;
    case 0xD:
LABEL_36:
      a4[141] = 0;
      a4[77] = 0;
      a4[13] = 0;
      goto LABEL_37;
    case 0xE:
LABEL_37:
      a4[142] = 0;
      a4[78] = 0;
      a4[14] = 0;
      goto LABEL_38;
    case 0xF:
LABEL_38:
      a4[143] = 0;
      a4[79] = 0;
      a4[15] = 0;
      goto LABEL_39;
    case 0x10:
LABEL_39:
      a4[144] = 0;
      a4[80] = 0;
      a4[16] = 0;
      goto LABEL_40;
    case 0x11:
LABEL_40:
      a4[145] = 0;
      a4[81] = 0;
      a4[17] = 0;
      goto LABEL_41;
    case 0x12:
LABEL_41:
      a4[146] = 0;
      a4[82] = 0;
      a4[18] = 0;
      goto LABEL_42;
    case 0x13:
LABEL_42:
      a4[147] = 0;
      a4[83] = 0;
      a4[19] = 0;
      goto LABEL_43;
    case 0x14:
LABEL_43:
      a4[148] = 0;
      a4[84] = 0;
      a4[20] = 0;
      goto LABEL_44;
    case 0x15:
LABEL_44:
      a4[149] = 0;
      a4[85] = 0;
      a4[21] = 0;
      goto LABEL_45;
    case 0x16:
LABEL_45:
      a4[150] = 0;
      a4[86] = 0;
      a4[22] = 0;
      goto LABEL_46;
    case 0x17:
LABEL_46:
      a4[151] = 0;
      a4[87] = 0;
      a4[23] = 0;
      goto LABEL_47;
    case 0x18:
LABEL_47:
      a4[152] = 0;
      a4[88] = 0;
      a4[24] = 0;
      goto LABEL_48;
    case 0x19:
LABEL_48:
      a4[153] = 0;
      a4[89] = 0;
      a4[25] = 0;
      goto LABEL_49;
    case 0x1A:
LABEL_49:
      a4[154] = 0;
      a4[90] = 0;
      a4[26] = 0;
      goto LABEL_50;
    case 0x1B:
LABEL_50:
      a4[155] = 0;
      a4[91] = 0;
      a4[27] = 0;
      goto LABEL_51;
    case 0x1C:
LABEL_51:
      a4[156] = 0;
      a4[92] = 0;
      a4[28] = 0;
      goto LABEL_52;
    case 0x1D:
LABEL_52:
      a4[157] = 0;
      a4[93] = 0;
      a4[29] = 0;
      goto LABEL_53;
    case 0x1E:
LABEL_53:
      a4[158] = 0;
      a4[94] = 0;
      a4[30] = 0;
      break;
    case 0x1F:
      break;
  }
  a4[159] = 0;
  a4[95] = 0;
  a4[31] = 0;
  result = this[2355];
  if ( result == 2 )
  {
    switch ( this[2350] )
    {
      case 0:
        a4[160] = 0;
        a4[96] = 0;
        a4[32] = 0;
        goto LABEL_57;
      case 1:
LABEL_57:
        a4[161] = 0;
        a4[97] = 0;
        a4[33] = 0;
        goto LABEL_58;
      case 2:
LABEL_58:
        a4[162] = 0;
        a4[98] = 0;
        a4[34] = 0;
        goto LABEL_59;
      case 3:
LABEL_59:
        a4[163] = 0;
        a4[99] = 0;
        a4[35] = 0;
        goto LABEL_60;
      case 4:
LABEL_60:
        a4[164] = 0;
        a4[100] = 0;
        a4[36] = 0;
        goto LABEL_61;
      case 5:
LABEL_61:
        a4[165] = 0;
        a4[101] = 0;
        a4[37] = 0;
        goto LABEL_62;
      case 6:
LABEL_62:
        a4[166] = 0;
        a4[102] = 0;
        a4[38] = 0;
        goto LABEL_63;
      case 7:
LABEL_63:
        a4[167] = 0;
        a4[103] = 0;
        a4[39] = 0;
        goto LABEL_64;
      case 8:
LABEL_64:
        a4[168] = 0;
        a4[104] = 0;
        a4[40] = 0;
        goto LABEL_65;
      case 9:
LABEL_65:
        a4[169] = 0;
        a4[105] = 0;
        a4[41] = 0;
        goto LABEL_66;
      case 0xA:
LABEL_66:
        a4[170] = 0;
        a4[106] = 0;
        a4[42] = 0;
        goto LABEL_67;
      case 0xB:
LABEL_67:
        a4[171] = 0;
        a4[107] = 0;
        a4[43] = 0;
        goto LABEL_68;
      case 0xC:
LABEL_68:
        a4[172] = 0;
        a4[108] = 0;
        a4[44] = 0;
        goto LABEL_69;
      case 0xD:
LABEL_69:
        a4[173] = 0;
        a4[109] = 0;
        a4[45] = 0;
        goto LABEL_70;
      case 0xE:
LABEL_70:
        a4[174] = 0;
        a4[110] = 0;
        a4[46] = 0;
        goto LABEL_71;
      case 0xF:
LABEL_71:
        a4[175] = 0;
        a4[111] = 0;
        a4[47] = 0;
        goto LABEL_72;
      case 0x10:
LABEL_72:
        a4[176] = 0;
        a4[112] = 0;
        a4[48] = 0;
        goto LABEL_73;
      case 0x11:
LABEL_73:
        a4[177] = 0;
        a4[113] = 0;
        a4[49] = 0;
        goto LABEL_74;
      case 0x12:
LABEL_74:
        a4[178] = 0;
        a4[114] = 0;
        a4[50] = 0;
        goto LABEL_75;
      case 0x13:
LABEL_75:
        a4[179] = 0;
        a4[115] = 0;
        a4[51] = 0;
        goto LABEL_76;
      case 0x14:
LABEL_76:
        a4[180] = 0;
        a4[116] = 0;
        a4[52] = 0;
        goto LABEL_77;
      case 0x15:
LABEL_77:
        a4[181] = 0;
        a4[117] = 0;
        a4[53] = 0;
        goto LABEL_78;
      case 0x16:
LABEL_78:
        a4[182] = 0;
        a4[118] = 0;
        a4[54] = 0;
        goto LABEL_79;
      case 0x17:
LABEL_79:
        a4[183] = 0;
        a4[119] = 0;
        a4[55] = 0;
        goto LABEL_80;
      case 0x18:
LABEL_80:
        a4[184] = 0;
        a4[120] = 0;
        a4[56] = 0;
        goto LABEL_81;
      case 0x19:
LABEL_81:
        a4[185] = 0;
        a4[121] = 0;
        a4[57] = 0;
        goto LABEL_82;
      case 0x1A:
LABEL_82:
        a4[186] = 0;
        a4[122] = 0;
        a4[58] = 0;
        goto LABEL_83;
      case 0x1B:
LABEL_83:
        a4[187] = 0;
        a4[123] = 0;
        a4[59] = 0;
        goto LABEL_84;
      case 0x1C:
LABEL_84:
        a4[188] = 0;
        a4[124] = 0;
        a4[60] = 0;
        goto LABEL_85;
      case 0x1D:
LABEL_85:
        a4[189] = 0;
        a4[125] = 0;
        a4[61] = 0;
        goto LABEL_86;
      case 0x1E:
LABEL_86:
        a4[190] = 0;
        a4[126] = 0;
        a4[62] = 0;
        break;
      case 0x1F:
        break;
    }
    a4[191] = 0;
    a4[127] = 0;
    a4[63] = 0;
  }
  return result;
}
