int sub_69EB7F()
{
  int v0; // eax
  int v1; // esi
  int v2; // ecx
  unsigned int v3; // ecx
  unsigned int v4; // ecx
  int v5; // eax
  unsigned int v6; // ecx
  unsigned int v7; // ecx
  int v8; // esi
  int result; // eax
  __int16 *v10; // eax
  int v11; // edx
  int v12; // ecx
  bool v13; // zf
  int v14; // esi
  int v15; // ecx
  unsigned int v16; // ecx
  unsigned int v17; // ecx
  int v18; // eax
  __int16 *i; // ecx
  unsigned int v20; // eax
  int v21; // [esp+20h] [ebp-8h]

  v0 = -1;
  v1 = 0;
  dword_FBAA28 = 0;
  dword_FBAA24 = 0;
  dword_FBAA1C = (int)&word_FBA628;
  dword_FBAA18 = (int)&unk_FB9E58;
  word_FBA628 = 0;
LABEL_2:
  for ( dword_FBAA20 = -1; ; v0 = dword_FBAA20 )
  {
    while ( 1 )
    {
LABEL_3:
      v2 = word_915B10[v1];
      if ( word_915B10[v1] )
        goto LABEL_17;
      if ( v0 < 0 )
      {
        v0 = sub_69AE2D((_DWORD *)dword_FBAA30);
        dword_FBAA20 = v0;
        if ( v0 < 0 )
        {
          v0 = 0;
          dword_FBAA20 = 0;
        }
      }
      if ( !word_915FC0[v1] )
        break;
      v3 = v0 + word_915FC0[v1];
      if ( v3 > 0xD88 )
        break;
      v4 = v3;
      if ( word_918350[v4] != v0 )
        break;
      v5 = dword_FBAA1C;
      if ( dword_FBAA1C >= (unsigned int)&word_FBAA0E )
        goto LABEL_47;
      v1 = word_916838[v4];
      dword_FBAA1C += 2;
      *(_WORD *)(v5 + 2) = v1;
      dword_FBAA18 += 4;
      *(_DWORD *)dword_FBAA18 = dword_FBAA10;
      v0 = -1;
      dword_FBAA20 = -1;
      if ( dword_FBAA24 > 0 )
        --dword_FBAA24;
    }
    if ( word_916388[v1] )
    {
      v6 = v0 + word_916388[v1];
      if ( v6 <= 0xD88 )
      {
        v7 = v6;
        if ( word_918350[v7] == v0 )
          break;
      }
    }
    if ( !dword_FBAA24 )
    {
      sub_694A67(dword_FBAA30, "syntax error");
      ++dword_FBAA28;
      v0 = dword_FBAA20;
    }
    if ( dword_FBAA24 >= 3 )
    {
      if ( v0 )
      {
        v0 = -1;
        goto LABEL_2;
      }
      return 1;
    }
    dword_FBAA24 = 3;
    for ( i = (__int16 *)dword_FBAA1C; ; dword_FBAA1C = (int)i )
    {
      if ( word_915FC0[*i] )
      {
        v20 = word_915FC0[*i] + 256;
        if ( v20 <= 0xD88 && word_918350[v20] == 256 )
          break;
      }
      if ( i <= &word_FBA628 )
        return 1;
      --i;
      dword_FBAA18 -= 4;
    }
    if ( i >= &word_FBAA0E )
    {
LABEL_47:
      sub_694A67(dword_FBAA30, "yacc stack overflow");
      return 1;
    }
    v1 = word_916838[v20];
    dword_FBAA1C = (int)(i + 1);
    i[1] = v1;
    v18 = dword_FBAA10;
LABEL_44:
    dword_FBAA18 += 4;
    *(_DWORD *)dword_FBAA18 = v18;
  }
  v2 = word_916838[v7];
LABEL_17:
  v8 = word_9158C0[v2];
  v21 = v2;
  dword_FBAA14 = *(_DWORD *)(dword_FBAA18 - 4 * v8 + 4);
  switch ( v2 )
  {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
    case 34:
    case 35:
    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
    case 41:
    case 42:
    case 43:
    case 44:
    case 45:
    case 46:
    case 47:
    case 48:
    case 49:
    case 50:
    case 51:
    case 52:
    case 53:
    case 54:
    case 55:
    case 56:
    case 57:
    case 58:
    case 59:
    case 60:
    case 61:
    case 62:
    case 63:
    case 64:
    case 65:
    case 66:
    case 67:
    case 68:
    case 69:
    case 70:
    case 71:
    case 72:
    case 73:
    case 74:
    case 75:
    case 76:
    case 77:
    case 78:
    case 79:
    case 80:
    case 81:
    case 82:
    case 83:
    case 84:
    case 85:
    case 86:
    case 87:
    case 88:
    case 89:
    case 90:
    case 91:
    case 92:
    case 93:
    case 94:
    case 95:
    case 96:
    case 97:
    case 98:
    case 99:
    case 100:
    case 101:
    case 102:
    case 103:
    case 104:
    case 105:
    case 106:
    case 107:
    case 108:
    case 109:
    case 110:
    case 111:
    case 112:
    case 113:
    case 114:
    case 115:
    case 116:
    case 117:
    case 118:
    case 119:
    case 120:
    case 121:
    case 122:
    case 123:
    case 124:
    case 125:
    case 126:
    case 127:
    case 128:
    case 129:
    case 130:
    case 131:
    case 132:
    case 133:
    case 134:
    case 135:
    case 136:
    case 137:
    case 138:
    case 139:
    case 140:
    case 141:
    case 142:
    case 143:
    case 144:
    case 145:
    case 146:
    case 147:
    case 148:
    case 149:
    case 150:
    case 151:
    case 152:
    case 153:
    case 154:
    case 155:
    case 156:
    case 157:
    case 158:
    case 159:
    case 160:
    case 161:
    case 162:
    case 163:
    case 164:
    case 165:
    case 166:
    case 167:
    case 168:
    case 169:
    case 170:
    case 171:
    case 172:
    case 173:
    case 174:
    case 175:
    case 176:
    case 177:
    case 178:
    case 179:
    case 180:
    case 181:
    case 182:
    case 183:
    case 184:
    case 185:
    case 186:
    case 187:
    case 188:
    case 189:
    case 190:
    case 191:
    case 192:
    case 193:
    case 194:
    case 195:
    case 196:
    case 197:
    case 198:
    case 199:
    case 200:
    case 201:
    case 202:
    case 203:
    case 204:
    case 205:
    case 206:
    case 207:
    case 208:
    case 209:
    case 210:
    case 211:
    case 212:
    case 213:
    case 214:
    case 215:
    case 216:
    case 217:
    case 218:
    case 219:
    case 220:
    case 221:
    case 222:
    case 223:
    case 224:
    case 225:
    case 226:
    case 227:
    case 228:
    case 229:
    case 230:
    case 231:
    case 232:
    case 233:
    case 234:
    case 235:
    case 236:
    case 237:
    case 238:
    case 239:
    case 240:
    case 241:
    case 242:
    case 243:
    case 244:
    case 245:
    case 246:
    case 247:
    case 248:
    case 249:
    case 250:
    case 251:
    case 252:
    case 253:
    case 254:
    case 255:
    case 256:
    case 257:
    case 258:
    case 259:
    case 260:
    case 261:
    case 262:
    case 263:
    case 264:
    case 265:
    case 266:
    case 267:
    case 268:
    case 269:
    case 270:
    case 271:
    case 272:
    case 273:
    case 274:
    case 275:
    case 276:
    case 277:
    case 278:
    case 279:
    case 280:
    case 281:
    case 282:
    case 283:
    case 284:
    case 285:
    case 286:
    case 287:
    case 288:
    case 289:
    case 290:
    case 291:
    case 292:
    case 293:
      result = off_16C92D4();
      break;
    default:
      v10 = (__int16 *)(dword_FBAA1C - 2 * v8);
      dword_FBAA1C = (int)v10;
      v11 = *v10;
      dword_FBAA18 -= 4 * v8;
      v12 = word_915670[v2];
      if ( v11 || word_915670[v21] )
      {
        v14 = v12;
        v15 = word_916750[v12];
        if ( v15 && (v16 = v11 + v15, v16 <= 0xD88) && (v17 = v16, word_918350[v17] == v11) )
          v1 = word_916838[v17];
        else
          v1 = word_915ED8[v14];
        if ( v10 < &word_FBAA0E )
        {
          dword_FBAA1C = (int)(v10 + 1);
          v10[1] = v1;
          v18 = dword_FBAA14;
          goto LABEL_44;
        }
        goto LABEL_47;
      }
      dword_FBAA1C = (int)(v10 + 1);
      v1 = 40;
      v10[1] = 40;
      dword_FBAA18 += 4;
      *(_DWORD *)dword_FBAA18 = dword_FBAA14;
      v0 = dword_FBAA20;
      v13 = dword_FBAA20 == 0;
      if ( dword_FBAA20 < 0 )
      {
        v0 = sub_69AE2D((_DWORD *)dword_FBAA30);
        v13 = v0 == 0;
        dword_FBAA20 = v0;
        if ( v0 < 0 )
        {
          v0 = 0;
          dword_FBAA20 = 0;
          v13 = 1;
        }
      }
      if ( !v13 )
        goto LABEL_3;
      result = 0;
      break;
  }
  return result;
}
