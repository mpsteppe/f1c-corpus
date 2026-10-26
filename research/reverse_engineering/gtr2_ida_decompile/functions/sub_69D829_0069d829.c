void __thiscall sub_69D829(int *this, int a2, int a3)
{
  double *v4; // esi
  bool v5; // zf
  int v7; // eax
  _DWORD *v8; // eax
  double *v9; // eax
  _DWORD *v10; // eax
  double *v11; // eax
  _DWORD *v12; // eax
  _DWORD *v13; // eax
  _DWORD *v14; // eax
  _DWORD *v15; // eax
  _DWORD *v16; // eax
  _DWORD *v17; // eax
  _DWORD *v18; // eax
  _DWORD *v19; // eax
  _DWORD *v20; // eax
  _DWORD *v21; // eax
  _DWORD *v22; // eax
  double *v23; // eax
  double *v24; // esi
  double *v25; // esi
  int v26; // ebx
  _DWORD *v27; // eax
  _DWORD *v28; // eax
  _DWORD *v29; // eax
  double *v30; // ebx
  _DWORD *v31; // eax
  _DWORD *v32; // eax
  _DWORD *v33; // eax
  _DWORD *v34; // eax
  _DWORD *v35; // eax
  _DWORD *v36; // eax
  _DWORD *v37; // esi
  int v38; // eax
  int v39; // eax
  int v40; // ebx
  int v41; // eax
  int v42; // ecx
  _DWORD *v43; // eax
  _DWORD *v44; // eax
  _DWORD *v45; // eax
  _DWORD *v46; // eax
  _DWORD *v47; // eax
  _DWORD *v48; // eax
  _DWORD *v49; // eax
  _DWORD *v50; // eax
  _DWORD *v51; // eax
  _DWORD *v52; // eax
  _DWORD *v53; // eax
  _DWORD *v54; // eax
  _DWORD *v55; // eax
  _DWORD *v56; // eax
  int v57; // eax
  double *v58; // eax
  _DWORD *v59; // eax
  _DWORD *v60; // eax
  int v61; // [esp-4h] [ebp-7Ch]
  int v62; // [esp-4h] [ebp-7Ch]
  int v63; // [esp+4h] [ebp-74h]
  double *v64; // [esp+8h] [ebp-70h]
  const char *v65; // [esp+8h] [ebp-70h]
  const char *v66; // [esp+8h] [ebp-70h]
  int v67; // [esp+8h] [ebp-70h]
  double *v68; // [esp+18h] [ebp-60h]
  double *v69; // [esp+1Ch] [ebp-5Ch]
  int v70; // [esp+20h] [ebp-58h]
  int v71; // [esp+24h] [ebp-54h]
  int v72; // [esp+28h] [ebp-50h]
  _DWORD v73[7]; // [esp+58h] [ebp-20h] BYREF
  int v74; // [esp+74h] [ebp-4h] BYREF
  int v75; // [esp+80h] [ebp+8h]
  int v76; // [esp+84h] [ebp+Ch]

  v4 = 0;
  v5 = this[17] == 0;
  v74 = 0;
  if ( v5 )
  {
    while ( a3 )
    {
      v7 = this[2];
      --a3;
      if ( !v7 )
      {
        sub_694C3A(this, 0, 0, "internal error: stack underflow");
        return;
      }
      *(&v68 + a3) = *(double **)(v7 + 8);
      this[2] = *(_DWORD *)(v7 + 12);
      *(_DWORD *)(v7 + 8) = 0;
      *(_DWORD *)(v7 + 12) = this[3];
      this[3] = v7;
    }
    switch ( a2 )
    {
      case 0:
        v8 = (_DWORD *)sub_65B229(32);
        if ( !v8 )
          goto LABEL_10;
        v9 = (double *)sub_67EF92(v8, 0, 0, 0, 0);
        goto LABEL_293;
      case 1:
        v10 = (_DWORD *)sub_65B229(32);
        if ( !v10 )
          goto LABEL_10;
        v9 = (double *)sub_67EF92(v10, this[20], this[21], this[22], (int)v68);
        goto LABEL_293;
      case 2:
      case 5:
      case 6:
      case 7:
      case 8:
      case 9:
      case 10:
      case 18:
      case 20:
      case 33:
      case 36:
      case 37:
      case 40:
      case 42:
      case 45:
      case 46:
      case 47:
      case 48:
      case 78:
      case 81:
      case 86:
      case 89:
      case 95:
      case 97:
      case 100:
      case 101:
      case 102:
      case 104:
      case 107:
      case 110:
      case 121:
      case 128:
      case 134:
      case 140:
      case 147:
      case 151:
      case 158:
      case 167:
      case 168:
      case 169:
      case 170:
      case 173:
      case 181:
      case 183:
      case 185:
      case 188:
      case 189:
      case 190:
      case 191:
      case 192:
      case 199:
      case 212:
      case 213:
      case 214:
      case 219:
      case 225:
      case 227:
      case 231:
      case 234:
      case 239:
      case 242:
      case 244:
      case 246:
      case 253:
      case 258:
      case 260:
      case 261:
      case 262:
      case 264:
      case 265:
      case 267:
      case 269:
      case 271:
      case 273:
      case 280:
      case 281:
      case 289:
        v4 = v68;
        goto LABEL_57;
      case 3:
      case 82:
      case 98:
      case 108:
      case 122:
      case 141:
      case 148:
      case 159:
      case 263:
        v11 = (double *)sub_67ECDC((int)v68, (int)v69);
        goto LABEL_16;
      case 4:
      case 44:
      case 74:
      case 88:
      case 92:
      case 94:
      case 103:
      case 116:
      case 117:
      case 120:
      case 136:
      case 143:
      case 150:
      case 154:
      case 160:
      case 179:
      case 182:
      case 184:
      case 204:
      case 257:
      case 279:
        goto LABEL_182;
      case 11:
      case 21:
      case 129:
        v4 = v68;
        sub_695030((int)this, (int)v68, (int)v69);
        goto LABEL_57;
      case 12:
        v12 = (_DWORD *)sub_65B229(28);
        if ( !v12 )
          goto LABEL_10;
        v9 = (double *)sub_67F1C5(v12, 2, 0, 0);
        goto LABEL_293;
      case 13:
        v13 = (_DWORD *)sub_65B229(28);
        if ( !v13 )
          goto LABEL_10;
        v9 = (double *)sub_67F1C5(v13, 64, 0, 0);
        goto LABEL_293;
      case 14:
        v14 = (_DWORD *)sub_65B229(28);
        if ( !v14 )
          goto LABEL_10;
        v9 = (double *)sub_67F1C5(v14, 1, 0, 0);
        goto LABEL_293;
      case 15:
        v15 = (_DWORD *)sub_65B229(28);
        if ( !v15 )
          goto LABEL_10;
        v9 = (double *)sub_67F1C5(v15, 4, 0, 0);
        goto LABEL_293;
      case 16:
        v16 = (_DWORD *)sub_65B229(28);
        if ( !v16 )
          goto LABEL_10;
        v9 = (double *)sub_67F1C5(v16, 256, 0, 0);
        goto LABEL_293;
      case 17:
        v17 = (_DWORD *)sub_65B229(28);
        if ( !v17 )
          goto LABEL_10;
        v9 = (double *)sub_67F1C5(v17, 8, 0, 0);
        goto LABEL_293;
      case 19:
        v18 = (_DWORD *)sub_65B229(28);
        if ( !v18 )
          goto LABEL_10;
        v9 = (double *)sub_67F1C5(v18, 0, (int)v68, 0);
        goto LABEL_293;
      case 22:
        v19 = (_DWORD *)sub_65B229(28);
        if ( !v19 )
          goto LABEL_10;
        v9 = (double *)sub_67F1C5(v19, 512, 0, 0);
        goto LABEL_293;
      case 23:
        v20 = (_DWORD *)sub_65B229(28);
        if ( !v20 )
          goto LABEL_10;
        v9 = (double *)sub_67F1C5(v20, 1024, 0, 0);
        goto LABEL_293;
      case 24:
        v21 = (_DWORD *)sub_65B229(28);
        if ( !v21 )
          goto LABEL_10;
        v9 = (double *)sub_67F1C5(v21, 2048, 0, 0);
        goto LABEL_293;
      case 25:
        v22 = (_DWORD *)sub_65B229(28);
        if ( !v22 )
          goto LABEL_40;
        v23 = (double *)sub_67F1C5(v22, 0, 0, (int)v68);
        goto LABEL_161;
      case 26:
        v4 = v68;
        *((_DWORD *)v68 + 6) = v69;
        goto LABEL_42;
      case 29:
        v4 = v68;
        sub_67F1C5(v73, 0, 0, *(_DWORD *)(*((_DWORD *)v68 + 2) + 24));
        sub_6982E4(this, (int)v73);
        goto LABEL_57;
      case 30:
        v24 = v68;
        v64 = v68;
        *((_DWORD *)v68 + 6) = *(_DWORD *)(*((_DWORD *)v69 + 2) + 24);
        sub_6982E4(this, (int)v64);
        *((_DWORD *)v24 + 6) = 0;
        goto LABEL_47;
      case 31:
        v9 = (double *)sub_69BE8D(this, (int)v68, (int)v69);
        goto LABEL_293;
      case 32:
        v25 = v68;
        v26 = sub_69BE8D(this, *(_DWORD *)(*((_DWORD *)v68 + 2) + 24), (int)v69);
        sub_694C92(this, v26);
        v11 = (double *)sub_67ECDC((int)v25, v26);
        goto LABEL_16;
      case 34:
        v27 = (_DWORD *)sub_65B229(20);
        if ( !v27 )
          goto LABEL_10;
        v65 = "TypeDefs";
        goto LABEL_52;
      case 35:
        v28 = (_DWORD *)sub_65B229(20);
        if ( !v28 )
          goto LABEL_10;
        v66 = "TypeDefs";
        goto LABEL_221;
      case 38:
        sub_69974C(this, 0, (const char **)v68 + 4, 0, 0, this[4], 1, &v74, 0);
        goto LABEL_56;
      case 39:
        v30 = v68 + 2;
        if ( sub_69974C(this, 0, (const char **)v68 + 4, 0, 0, this[4], 1, &v74, 0) )
        {
LABEL_56:
          v4 = (double *)v74;
        }
        else
        {
          v4 = (double *)v74;
          if ( v74 && *(_DWORD *)(v74 + 4) != 1 )
            sub_694B97((int)this, (int)v30, 3005, "invalid use of '%s'", *((const char **)v30 + 2));
        }
        goto LABEL_57;
      case 41:
        v4 = v69;
        sub_696C04(this, (int)v68, v69);
        goto LABEL_57;
      case 43:
        v9 = (double *)sub_69C1B4(this, (int)v68, v69);
        goto LABEL_293;
      case 49:
        v31 = (_DWORD *)sub_65B229(36);
        if ( !v31 )
          goto LABEL_10;
        v61 = 0;
        goto LABEL_70;
      case 50:
        v31 = (_DWORD *)sub_65B229(36);
        if ( !v31 )
          goto LABEL_10;
        v61 = 4;
        goto LABEL_70;
      case 51:
        v31 = (_DWORD *)sub_65B229(36);
        if ( !v31 )
          goto LABEL_10;
        v61 = 10;
        goto LABEL_70;
      case 52:
        v31 = (_DWORD *)sub_65B229(36);
        if ( !v31 )
          goto LABEL_10;
        v61 = 11;
        goto LABEL_70;
      case 53:
        v31 = (_DWORD *)sub_65B229(36);
        if ( !v31 )
          goto LABEL_10;
        v61 = 12;
LABEL_70:
        v9 = (double *)sub_67F2D4(v31, 0, v61, 1, 1, 0);
        goto LABEL_293;
      case 54:
        v32 = (_DWORD *)sub_65B229(36);
        if ( !v32 )
          goto LABEL_10;
        v9 = (double *)sub_67F2D4(v32, 1, 11, 1, 4, 0);
        goto LABEL_293;
      case 55:
        v9 = (double *)sub_69C085(this, (unsigned int)v68, v69);
        goto LABEL_293;
      case 56:
        v33 = (_DWORD *)sub_65B229(36);
        if ( !v33 )
          goto LABEL_10;
        v9 = (double *)sub_67F2D4(v33, 2, 11, 4, 4, 0);
        goto LABEL_293;
      case 57:
        v9 = (double *)sub_69C10B(this, (unsigned int)v68, v69, (_DWORD *)v70);
        goto LABEL_293;
      case 58:
        v34 = (_DWORD *)sub_65B229(36);
        if ( !v34 )
          goto LABEL_10;
        v62 = 14;
        goto LABEL_117;
      case 59:
        v34 = (_DWORD *)sub_65B229(36);
        if ( !v34 )
          goto LABEL_10;
        v62 = 15;
        goto LABEL_117;
      case 60:
        v34 = (_DWORD *)sub_65B229(36);
        if ( !v34 )
          goto LABEL_10;
        v62 = 16;
        goto LABEL_117;
      case 61:
        v34 = (_DWORD *)sub_65B229(36);
        if ( !v34 )
          goto LABEL_10;
        v62 = 17;
        goto LABEL_117;
      case 62:
        v34 = (_DWORD *)sub_65B229(36);
        if ( !v34 )
          goto LABEL_10;
        v62 = 18;
        goto LABEL_117;
      case 63:
        v34 = (_DWORD *)sub_65B229(36);
        if ( !v34 )
          goto LABEL_10;
        v62 = 19;
        goto LABEL_117;
      case 64:
        v34 = (_DWORD *)sub_65B229(36);
        if ( !v34 )
          goto LABEL_10;
        v62 = 20;
        goto LABEL_117;
      case 65:
        v34 = (_DWORD *)sub_65B229(36);
        if ( !v34 )
          goto LABEL_10;
        v62 = 21;
        goto LABEL_117;
      case 66:
        v34 = (_DWORD *)sub_65B229(36);
        if ( !v34 )
          goto LABEL_10;
        v62 = 22;
        goto LABEL_117;
      case 67:
        v34 = (_DWORD *)sub_65B229(36);
        if ( !v34 )
          goto LABEL_10;
        v62 = 23;
        goto LABEL_117;
      case 68:
        v34 = (_DWORD *)sub_65B229(36);
        if ( !v34 )
          goto LABEL_10;
        v62 = 24;
        goto LABEL_117;
      case 69:
        v34 = (_DWORD *)sub_65B229(36);
        if ( !v34 )
          goto LABEL_10;
        v62 = 25;
        goto LABEL_117;
      case 70:
        v34 = (_DWORD *)sub_65B229(36);
        if ( !v34 )
          goto LABEL_10;
        v62 = 26;
        goto LABEL_117;
      case 71:
        v34 = (_DWORD *)sub_65B229(36);
        if ( !v34 )
          goto LABEL_10;
        v62 = 27;
        goto LABEL_117;
      case 72:
        v34 = (_DWORD *)sub_65B229(36);
        if ( !v34 )
          goto LABEL_10;
        v62 = 28;
        goto LABEL_117;
      case 73:
        v34 = (_DWORD *)sub_65B229(36);
        if ( !v34 )
          goto LABEL_10;
        v62 = 29;
LABEL_117:
        v9 = (double *)sub_67F2D4(v34, 3, v62, 1, 1, 0);
        goto LABEL_293;
      case 75:
      case 93:
      case 118:
      case 137:
      case 144:
      case 155:
        goto LABEL_47;
      case 76:
        v9 = (double *)sub_69C03D(this, 0, (int)v68);
        goto LABEL_293;
      case 77:
        v9 = (double *)sub_69C03D(this, v70, (int)v68);
        goto LABEL_293;
      case 79:
        sub_696C04(this, (int)v68, *(_DWORD **)(*((_DWORD *)v68 + 2) + 24));
LABEL_47:
        v4 = v69;
        goto LABEL_57;
      case 80:
        v67 = 0;
        v63 = 1;
        goto LABEL_123;
      case 83:
      case 99:
      case 139:
      case 157:
        goto LABEL_124;
      case 84:
      case 85:
        v27 = (_DWORD *)sub_65B229(20);
        if ( !v27 )
          goto LABEL_10;
        v65 = "Semantics";
        goto LABEL_52;
      case 87:
        v9 = (double *)sub_67ECDC((int)v68, (int)v69);
        goto LABEL_293;
      case 90:
        v35 = (_DWORD *)sub_65B229(24);
        if ( !v35 )
          goto LABEL_10;
        v9 = (double *)sub_67F985(v35, 0, (int)v68);
        goto LABEL_293;
      case 91:
        v36 = (_DWORD *)sub_65B229(24);
        if ( !v36 )
          goto LABEL_10;
        v9 = (double *)sub_67F985(v36, (int)v68, (int)v69);
        goto LABEL_293;
      case 96:
        v67 = 0;
        v63 = 5;
        goto LABEL_123;
      case 105:
      case 123:
        v4 = v69;
        goto LABEL_135;
      case 106:
        v4 = (double *)sub_67ECDC((int)v68, (int)v69);
        goto LABEL_135;
      case 109:
        v9 = (double *)sub_69C924(this, (int)v68, (int)v69, v70, (_DWORD *)v71);
        goto LABEL_293;
      case 111:
        v27 = (_DWORD *)sub_65B229(20);
        if ( !v27 )
          goto LABEL_10;
        v65 = "VariableDim";
        goto LABEL_52;
      case 112:
        v28 = (_DWORD *)sub_65B229(20);
        if ( !v28 )
          goto LABEL_10;
        v66 = "VariableDim";
        goto LABEL_221;
      case 113:
        goto LABEL_156;
      case 114:
        if ( !v68 )
          goto LABEL_156;
        v37 = (_DWORD *)*((_DWORD *)v68 + 2);
        if ( !v37 )
          goto LABEL_156;
        v38 = v37[6];
        v37[7] = v69;
        *(_DWORD *)(v38 + 40) = v70;
        *(_DWORD *)(v38 + 60) = 1;
        v39 = this[4];
        v40 = v37[5] + 16;
        break;
      case 115:
        v4 = (double *)sub_69B988(this, (int)v69, v70, v71);
        sub_694C92(this, (int)v4);
LABEL_135:
        sub_694F7B(this);
        goto LABEL_57;
      case 119:
        v67 = this[7];
        v63 = 2;
        goto LABEL_123;
      case 124:
        v43 = (_DWORD *)sub_65B229(28);
        if ( v43 )
        {
          v23 = (double *)sub_67F1C5(v43, 16, 0, (int)v68);
LABEL_161:
          v4 = v23;
        }
        else
        {
LABEL_40:
          v4 = 0;
        }
        sub_694C92(this, (int)v4);
        goto LABEL_42;
      case 125:
        v4 = v68;
        *((_DWORD *)v68 + 6) = v69;
        if ( ((_BYTE)v4[2] & 0x70) == 0 )
          *((_DWORD *)v4 + 4) |= 0x10u;
LABEL_42:
        sub_6982E4(this, (int)v4);
        goto LABEL_57;
      case 130:
        v44 = (_DWORD *)sub_65B229(28);
        if ( !v44 )
          goto LABEL_10;
        v9 = (double *)sub_67F1C5(v44, 16, 0, 0);
        goto LABEL_293;
      case 131:
        v45 = (_DWORD *)sub_65B229(28);
        if ( !v45 )
          goto LABEL_10;
        v9 = (double *)sub_67F1C5(v45, 32, 0, 0);
        goto LABEL_293;
      case 132:
        v46 = (_DWORD *)sub_65B229(28);
        if ( !v46 )
          goto LABEL_10;
        v9 = (double *)sub_67F1C5(v46, 48, 0, 0);
        goto LABEL_293;
      case 133:
        v47 = (_DWORD *)sub_65B229(28);
        if ( !v47 )
          goto LABEL_10;
        v9 = (double *)sub_67F1C5(v47, 80, 0, 0);
        goto LABEL_293;
      case 135:
        v48 = (_DWORD *)sub_65B229(20);
        if ( v48 )
          v4 = (double *)sub_67ED1B(v48, 0, 0, (int)"Stmts");
        else
          v4 = 0;
        if ( sub_694C92(this, (int)v4) )
        {
          v49 = (_DWORD *)sub_65B229(48);
          if ( v49 )
            v50 = sub_67F0EF(v49, 3, (int)v68, v70, (int)v69);
          else
            v50 = 0;
          *((_DWORD *)v4 + 2) = v50;
          sub_694C92(this, (int)v50);
        }
        ++this[20];
        goto LABEL_57;
      case 138:
        sub_694CC7(this, 6, 0);
        goto LABEL_182;
      case 142:
        v51 = (_DWORD *)sub_65B229(20);
        if ( v51 )
          v4 = (double *)sub_67ED1B(v51, 0, 0, (int)"Passes");
        else
          v4 = 0;
        if ( !sub_694C92(this, (int)v4) )
          goto LABEL_57;
        v52 = (_DWORD *)sub_65B229(48);
        if ( !v52 )
          goto LABEL_197;
        v53 = sub_67F0EF(v52, 4, (int)v68, v70, (int)v69);
        goto LABEL_198;
      case 145:
        sub_694CC7(this, 7, 0);
        this[18] = 0;
LABEL_182:
        v4 = 0;
        goto LABEL_57;
      case 146:
        this[18] = 1;
LABEL_124:
        v4 = 0;
        goto LABEL_125;
      case 149:
        v54 = (_DWORD *)sub_65B229(20);
        if ( v54 )
          v4 = (double *)sub_67ED1B(v54, 0, 0, (int)"States");
        else
          v4 = 0;
        if ( !sub_694C92(this, (int)v4) )
          goto LABEL_57;
        v55 = (_DWORD *)sub_65B229(28);
        if ( v55 )
          v53 = sub_67F85E(v55, (int)v68, (int)v69, v71);
        else
LABEL_197:
          v53 = 0;
LABEL_198:
        *((_DWORD *)v4 + 2) = v53;
        sub_694C92(this, (int)v53);
        goto LABEL_57;
      case 152:
        this[18] = 1;
        goto LABEL_57;
      case 153:
        this[18] = 0;
        goto LABEL_57;
      case 156:
        v67 = 0;
        v63 = 3;
        goto LABEL_123;
      case 161:
      case 180:
        v11 = (double *)sub_695C26((int)v68);
        goto LABEL_16;
      case 162:
        v11 = (double *)sub_69C870((int)this, 0);
        goto LABEL_16;
      case 163:
        v11 = (double *)sub_69C870((int)this, v68);
        goto LABEL_16;
      case 164:
        v11 = (double *)sub_695D0B(this, (int)v68, (int)v69, 0, (int)v68);
        goto LABEL_16;
      case 165:
        v27 = (_DWORD *)sub_65B229(20);
        if ( !v27 )
          goto LABEL_10;
        v65 = "Stmts";
        goto LABEL_52;
      case 166:
        v11 = (double *)sub_695C88(this);
        goto LABEL_16;
      case 171:
      case 174:
        v11 = (double *)sub_695D0B(this, 0, (int)v68, 0, (int)v69);
        goto LABEL_16;
      case 172:
      case 175:
        v4 = (double *)sub_695D0B(this, (int)v69, v70, v71, v72);
LABEL_125:
        sub_696139(this);
        goto LABEL_57;
      case 176:
        v11 = (double *)sub_69AD06(this, (int)v68, (int)v69, 0);
        goto LABEL_16;
      case 177:
        v11 = (double *)sub_69AD06(this, (int)v68, (int)v69, v70);
        goto LABEL_16;
      case 178:
        v67 = 0;
        v63 = 4;
LABEL_123:
        v4 = 0;
        sub_694CC7(this, v63, v67);
        goto LABEL_57;
      case 186:
        v27 = (_DWORD *)sub_65B229(20);
        if ( !v27 )
          goto LABEL_10;
        v65 = "DwordExpr";
        goto LABEL_52;
      case 187:
        v28 = (_DWORD *)sub_65B229(20);
        if ( !v28 )
          goto LABEL_10;
        v66 = "DwordExpr";
LABEL_221:
        v9 = (double *)sub_67ED1B(v28, (int)v68, (int)v69, (int)v66);
        goto LABEL_293;
      case 193:
        v9 = (double *)sub_69741E(this, 0, 1, 1.0, this + 8);
        goto LABEL_293;
      case 194:
        v9 = (double *)sub_69741E(this, 0, 0, 0.0, this + 8);
        goto LABEL_293;
      case 195:
      case 196:
        v9 = (double *)sub_697536(this, v68);
        goto LABEL_293;
      case 197:
        v9 = (double *)sub_6975BA(this, (int)v68);
        goto LABEL_293;
      case 198:
        v9 = (double *)sub_699E09(this, (int)v68, 0);
        goto LABEL_293;
      case 200:
      case 201:
        v9 = (double *)sub_699F10(this, (int)v68, v69, 1, 1);
        goto LABEL_293;
      case 202:
        v9 = (double *)sub_69D249(this, (int)v68, (int)v69, 0);
        goto LABEL_293;
      case 203:
        v11 = (double *)sub_69585C(this, (int)v68);
        goto LABEL_16;
      case 205:
        v11 = (double *)sub_697C19(this, v69);
        goto LABEL_16;
      case 206:
      case 207:
        v11 = (double *)sub_697C19(this, v68);
        goto LABEL_16;
      case 208:
        v11 = (double *)sub_69D661(this, (int)v68, (int)v69, v70, 0);
        goto LABEL_16;
      case 209:
        v9 = (double *)sub_697D53(this, (int)v68);
        goto LABEL_293;
      case 210:
        v11 = (double *)sub_69D661(this, (int)v68, (int)v69, v70, 1);
        goto LABEL_16;
      case 211:
        v9 = (double *)sub_697E2D(this, (int)v68);
        goto LABEL_293;
      case 215:
        v9 = (double *)sub_69C22D(this, v68, (int)v69);
        goto LABEL_293;
      case 216:
        v9 = (double *)sub_697788(this, v68, (int)v69);
        goto LABEL_293;
      case 217:
        v9 = (double *)sub_69C457((char *)this, 33, v68, 0, 1);
        goto LABEL_293;
      case 218:
        v9 = (double *)sub_69C457((char *)this, 34, v68, 0, 1);
        goto LABEL_293;
      case 220:
        v9 = (double *)sub_69C457((char *)this, 2, v68, 0, 1);
        goto LABEL_293;
      case 221:
        v9 = (double *)sub_69C457((char *)this, 3, v68, 0, 1);
        goto LABEL_293;
      case 222:
        v9 = (double *)sub_69C457((char *)this, 4, v68, 0, 1);
        goto LABEL_293;
      case 223:
        v9 = (double *)sub_69C457((char *)this, 5, v68, 0, 1);
        goto LABEL_293;
      case 224:
        v9 = (double *)sub_69C457((char *)this, 6, v68, 0, 1);
        goto LABEL_293;
      case 226:
        v9 = (double *)sub_699F10(this, (int)v68, v69, 0, 1);
        goto LABEL_293;
      case 228:
        v9 = (double *)sub_69C457((char *)this, 7, v68, v69, 1);
        goto LABEL_293;
      case 229:
        v9 = (double *)sub_69C457((char *)this, 8, v68, v69, 1);
        goto LABEL_293;
      case 230:
        v9 = (double *)sub_69C457((char *)this, 9, v68, v69, 1);
        goto LABEL_293;
      case 232:
        v9 = (double *)sub_69C457((char *)this, 10, v68, v69, 1);
        goto LABEL_293;
      case 233:
        v9 = (double *)sub_69C457((char *)this, 11, v68, v69, 1);
        goto LABEL_293;
      case 235:
        v9 = (double *)sub_69C457((char *)this, 12, v68, v69, 1);
        goto LABEL_293;
      case 236:
        v9 = (double *)sub_69C457((char *)this, 13, v68, v69, 1);
        goto LABEL_293;
      case 237:
        v9 = (double *)sub_69C457((char *)this, 14, v68, v69, 1);
        goto LABEL_293;
      case 238:
        v9 = (double *)sub_69C457((char *)this, 15, v68, v69, 1);
        goto LABEL_293;
      case 240:
        v9 = (double *)sub_69C457((char *)this, 16, v68, v69, 1);
        goto LABEL_293;
      case 241:
        v9 = (double *)sub_69C457((char *)this, 17, v68, v69, 1);
        goto LABEL_293;
      case 243:
        v9 = (double *)sub_69C457((char *)this, 18, v68, v69, 1);
        goto LABEL_293;
      case 245:
        v9 = (double *)sub_69C457((char *)this, 19, v68, v69, 1);
        goto LABEL_293;
      case 247:
        v9 = (double *)sub_69C457((char *)this, 21, v68, v69, 1);
        goto LABEL_293;
      case 248:
        v9 = (double *)sub_69C457((char *)this, 28, v68, v69, 1);
        goto LABEL_293;
      case 249:
        v9 = (double *)sub_69C457((char *)this, 29, v68, v69, 1);
        goto LABEL_293;
      case 250:
        v9 = (double *)sub_69C457((char *)this, 30, v68, v69, 1);
        goto LABEL_293;
      case 251:
        v9 = (double *)sub_69C457((char *)this, 31, v68, v69, 1);
        goto LABEL_293;
      case 252:
        v9 = (double *)sub_69C457((char *)this, 32, v68, v69, 1);
        goto LABEL_293;
      case 254:
        v9 = (double *)sub_69A139(this, v68, v69, (_DWORD *)v70);
        goto LABEL_293;
      case 255:
        v27 = (_DWORD *)sub_65B229(20);
        if ( !v27 )
          goto LABEL_10;
        v65 = "Arguments";
        goto LABEL_52;
      case 256:
        v56 = (_DWORD *)sub_65B229(20);
        if ( v56 )
          v4 = (double *)sub_67ED1B(v56, (int)v69, 0, (int)"Arguments");
        else
          v4 = 0;
        if ( !sub_694C92(this, (int)v4) )
          goto LABEL_57;
        v11 = (double *)sub_67ECDC((int)v68, (int)v4);
        goto LABEL_16;
      case 259:
        v27 = (_DWORD *)sub_65B229(20);
        if ( !v27 )
          goto LABEL_10;
        v65 = "Value";
LABEL_52:
        v9 = (double *)sub_67ED1B(v27, (int)v68, 0, (int)v65);
        goto LABEL_293;
      case 266:
        v57 = this[4];
        if ( v57 && *(_DWORD *)(v57 + 16) == 7 )
        {
          v58 = v69;
          if ( !v69 )
            v58 = v68;
          sub_694BED(
            (int)this,
            (int)(v58 + 6),
            (const char *)0xC09,
            "comma expression used where an initializer list may have been intended");
        }
        v9 = (double *)sub_69C457((char *)this, 1, v69, v68, 0);
        goto LABEL_293;
      case 268:
        v4 = v68;
        *((_DWORD *)v68 + 6) = -*((_DWORD *)v68 + 6);
        goto LABEL_57;
      case 270:
        v4 = v68;
        v68[3] = -v68[3];
        goto LABEL_57;
      case 272:
        v11 = (double *)sub_695F7A((_DWORD **)this, v68, v69);
        goto LABEL_16;
      case 274:
      case 275:
      case 276:
      case 282:
      case 283:
      case 284:
      case 285:
      case 286:
      case 287:
      case 288:
      case 291:
      case 292:
      case 293:
        v59 = (_DWORD *)sub_65B229(48);
        if ( v59 )
        {
          v9 = (double *)sub_67EF22(v59, this + 8);
LABEL_293:
          v4 = v9;
        }
        else
        {
LABEL_10:
          v4 = 0;
        }
        sub_694C92(this, (int)v4);
        goto LABEL_57;
      case 277:
      case 278:
        v4 = v68;
        this[7] = *((_DWORD *)v68 + 6);
        goto LABEL_57;
      case 290:
        v11 = (double *)sub_696069((_DWORD **)this, v68, v69);
        goto LABEL_16;
      case 294:
        v11 = (double *)sub_695E26((_DWORD **)this);
        goto LABEL_16;
      case 295:
        v11 = (double *)sub_695E41(this, 0);
        goto LABEL_16;
      case 296:
        v11 = (double *)sub_695E41(this, 1);
LABEL_16:
        v4 = v11;
        goto LABEL_57;
      default:
        sub_694C3A(this, 0, 0, "internal error: unhandled production");
        goto LABEL_57;
    }
    while ( 1 )
    {
      v76 = v39;
      if ( !v39 )
        break;
      v41 = sub_694E5E(v40, v39);
      v75 = v41;
      if ( v41 )
      {
        while ( 1 )
        {
          v42 = *(_DWORD *)(v41 + 8);
          if ( v42 )
          {
            if ( *(_DWORD *)(v42 + 4) == 6 && *(_DWORD *)(v42 + 36) == v37[9] )
              break;
          }
          v41 = *(_DWORD *)(v41 + 12);
          v75 = v41;
          if ( !v41 )
            goto LABEL_150;
        }
        if ( *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v41 + 8) + 24) + 60) )
        {
          sub_694B97((int)this, v40, 3069, "'%s' already has a body", *(const char **)(v40 + 8));
          v41 = v75;
        }
        *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v41 + 8) + 24) + 60) = 1;
        break;
      }
LABEL_150:
      v39 = *(_DWORD *)(v76 + 32);
    }
LABEL_156:
    v4 = v68;
    sub_696139(this);
    this[6] = 0;
LABEL_57:
    if ( !this[17] )
    {
      v29 = (_DWORD *)this[3];
      if ( v29 )
      {
        this[3] = v29[3];
        v29[2] = v4;
        v29[3] = this[2];
      }
      else
      {
        v60 = (_DWORD *)sub_65B229(20);
        if ( v60 )
          v29 = sub_67ED1B(v60, (int)v4, this[2], (int)"Stack");
        else
          v29 = 0;
        if ( !v29 )
        {
          sub_694C3A(this, 0, 0, "internal error: out of memory");
          return;
        }
      }
      this[2] = (int)v29;
    }
  }
}
