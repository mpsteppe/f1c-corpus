void __thiscall sub_4D0D50(char *this)
{
  unsigned int v2; // ecx
  int v3; // ecx
  int v4; // eax
  int v5; // ecx
  char *v6; // esi
  char *v7; // eax
  char *v8; // esi
  char *v9; // eax
  int v10; // eax
  double v11; // st7
  int v12; // edx
  double v13; // st7
  int v14; // eax
  double v15; // st7
  int v16; // edx
  double v17; // st7
  int v18; // eax
  int v19; // ecx
  int v20; // edx
  int v21; // eax
  double v22; // st7
  int v23; // eax
  double v24; // st7
  int v25; // edx
  double v26; // st7
  int v27; // eax
  int v28; // eax
  int v29; // ebp
  _DWORD *v30; // edi
  int v31; // ebx
  float *v32; // eax
  float *v33; // ecx
  int v34; // edx
  double v35; // st7
  signed int i; // eax
  int v37; // edx
  int v38; // ecx
  int v39; // edx
  __int16 v40; // cx
  char *v41; // ecx
  int v42; // ecx
  int v43; // edx
  unsigned __int8 *v44; // eax
  int v45; // edi
  int v46; // ebx
  int v47; // esi
  int v48; // ecx
  int v49; // ecx
  float v50; // [esp+0h] [ebp-34h]
  float v51; // [esp+0h] [ebp-34h]
  int v52; // [esp+18h] [ebp-1Ch]
  int v53; // [esp+18h] [ebp-1Ch]
  int v54; // [esp+18h] [ebp-1Ch]
  int v55; // [esp+18h] [ebp-1Ch]
  signed int v56; // [esp+18h] [ebp-1Ch]
  int v57; // [esp+18h] [ebp-1Ch]
  int v58; // [esp+18h] [ebp-1Ch]
  int v59; // [esp+18h] [ebp-1Ch]
  float v60; // [esp+18h] [ebp-1Ch]
  int v61; // [esp+18h] [ebp-1Ch]
  int v62; // [esp+18h] [ebp-1Ch]
  int v63; // [esp+1Ch] [ebp-18h] BYREF
  float v64; // [esp+20h] [ebp-14h]
  float v65; // [esp+24h] [ebp-10h]
  int v66; // [esp+28h] [ebp-Ch] BYREF
  float v67; // [esp+2Ch] [ebp-8h]
  float v68; // [esp+30h] [ebp-4h]

  v2 = *(_DWORD *)this;
  switch ( v2 >> 28 )
  {
    case 1u:
      switch ( this[2] & 0x3F )
      {
        case 0:
        case 7:
          v3 = v2 & 0x3F;
          if ( v3 < 49 && *((_DWORD *)&unk_62BF68 + 6326 * v3 + 4146) == 2 )
          {
            sub_465BE0(v3, (int)this);
            v4 = sub_4D0520((_DWORD *)this + 2);
            sub_4EED80(v4);
          }
          break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
          if ( dword_630030[6326 * (v2 & 0x3F)] == 2 )
            sub_417CB0(dword_6291D0, (int)this);
          break;
        default:
          return;
      }
      break;
    case 2u:
      switch ( this[2] & 0x3F )
      {
        case 0:
          v5 = v2 & 0x3F;
          if ( v5 < 48 )
          {
            v6 = (char *)&unk_62BF68 + 25304 * v5;
            sub_50DFE0(v6 + 1892);
            sub_526370(v6 + 92);
          }
          break;
        case 2:
          if ( (v2 & 0x3F) < 0x30 )
          {
            v7 = (char *)&unk_62BF68 + 25304 * (v2 & 0x3F);
            if ( *((_DWORD *)v7 + 4146) >= 2u )
            {
              if ( (v2 & 0xFFC0) == 0x180 )
              {
                this[14] = 0;
                *((_DWORD *)this + 4) = 0;
              }
              v8 = this + 8;
              v9 = v7 + 4688;
              *(_DWORD *)v9 = *(_DWORD *)v8;
              *((_DWORD *)v9 + 1) = *((_DWORD *)v8 + 1);
              *((_DWORD *)v9 + 2) = *((_DWORD *)v8 + 2);
              *((_DWORD *)v9 + 3) = *((_DWORD *)v8 + 3);
              *((_WORD *)v9 + 8) = *((_WORD *)v8 + 8);
            }
          }
          break;
        case 4:
          sub_52C320(this);
          break;
        case 5:
          sub_52A980(this);
          break;
        case 6:
          flt_7DAAF8 = (double)(unsigned __int8)this[8] * 0.0039215689;
          break;
        case 7:
          if ( (v2 & 0x3F) < 0x30 )
          {
            v10 = this[10];
            v11 = (double)this[8];
            v52 = this[9];
            v12 = this[11];
            *(float *)&v66 = v11 * 0.0078740157 + v11 * 0.0078740157;
            v13 = (double)v52;
            v53 = v10;
            v14 = this[12];
            v67 = v13 * 0.0078740157 * 1.5;
            v15 = (double)v53;
            v54 = v12;
            v16 = this[13];
            v68 = v15 * 0.0078740157 * 3.5;
            v17 = (double)v54;
            v55 = v14;
            v18 = *(_DWORD *)(this + 14);
            *(float *)&v63 = v17 * 0.0078740157;
            v64 = (double)v55 * 0.0078740157;
            v65 = (double)v16 * 0.0078740157;
            sub_50ECB0(v18, &v66, &v63);
          }
          break;
        case 8:
          if ( (v2 & 0x3F) < 0x30 )
            sub_50ED80(*((_DWORD *)this + 2));
          break;
        case 9:
          sub_4BA430();
          break;
        case 0xD:
          v19 = v2 & 0x3F;
          if ( v19 < 48 && (dword_632238[6326 * v19] & 2) != 0 && dword_7D73FC )
          {
            v20 = this[16];
            v56 = (*((_DWORD *)this + 3) & 0xFFC00000) + ((*((_DWORD *)this + 2) >> 10) & 0x3FF000);
            v21 = *((_DWORD *)this + 3) << 10;
            *(float *)&v63 = (double)(int)(*((_DWORD *)this + 2) << 10) * 0.000015258789;
            v22 = (double)v56;
            v57 = v21;
            v23 = this[17];
            v64 = v22 * 0.0000019073486;
            v24 = (double)v57;
            v58 = v20;
            v25 = this[18];
            v65 = v24 * 0.000015258789;
            v26 = (double)v58;
            v59 = v23;
            v27 = (unsigned __int8)this[19];
            *(float *)&v66 = v26 * 0.0078740157;
            v67 = (double)v59 * 0.0078740157;
            v68 = (double)v25 * 0.0078740157;
            v50 = (double)v27 * 0.0039215689;
            sub_4F4FA0((int)&v63, (int)&v66, v50, 0xFFFFFF, 0);
          }
          break;
        default:
          return;
      }
      break;
    case 3u:
      if ( (this[2] & 0x3F) == 6 && !byte_76617C )
      {
        v60 = (double)(unsigned __int8)this[8] * 0.0039215689;
        v28 = rand();
        sub_4F0220(v28 % 3 + 5, LODWORD(v60));
      }
      break;
    case 4u:
      switch ( this[2] & 0x3F )
      {
        case 7:
          v29 = 0;
          v61 = ((unsigned __int16)v2 >> 6) - 13;
          if ( v61 > 0 )
          {
            do
            {
              v30 = (_DWORD *)((char *)&unk_6310CC + 25304 * (unsigned __int8)this[v29 + 21]);
              v31 = v29 + 1;
              sub_4DEB20(v29 + 1);
              if ( this[20] )
                v30[13] = v31;
              if ( v29 <= 0 )
                v30[44] = 0;
              else
                v30[44] = (char *)&unk_62BF68 + 25304 * (unsigned __int8)this[v29 + 20];
              if ( v29 >= v61 - 1 )
                v30[45] = 0;
              else
                v30[45] = (char *)&unk_62BF68 + 25304 * (unsigned __int8)this[v29 + 22];
              if ( !v29 && *((float *)this + 2) > 0.0 )
              {
                v32 = (float *)(this + 8);
                v33 = (float *)(v30 + 34);
                v34 = 3;
                do
                {
                  v35 = *v32++;
                  *v33++ = v35;
                  --v34;
                }
                while ( v34 );
              }
              byte_7D7558[v29] = this[v29 + 21];
              ++v29;
            }
            while ( v31 < v61 );
          }
          sub_4197A0(&unk_629328, 1);
          break;
        case 8:
          v38 = v2 & 0x3F;
          if ( v38 < 49 )
          {
            v39 = *((_DWORD *)&unk_62BF68 + 6326 * v38 + 4146);
            if ( v39 == 2 || v39 == 3 )
            {
              if ( v38 == 48 )
              {
                if ( dword_7D7540 > 0 || dword_75CBB4 < 5 )
                  sub_4BBFC0(&unk_766220, *((__int16 *)this + 6));
              }
              else
              {
                v40 = *((_WORD *)this + 7);
                v51 = *((float *)this + 1);
                if ( v40 == -1 )
                  sub_4DD350(*((_DWORD *)this + 2), LODWORD(v51), *((__int16 *)this + 6), -1);
                else
                  sub_4DD490(*((float *)this + 2), v51, *((__int16 *)this + 6), v40);
              }
            }
          }
          break;
        case 9:
          if ( (unsigned __int16)v2 >> 6 == NumOfElements )
          {
            for ( i = 0; i < (int)NumOfElements; *(float *)(v37 + 20832) = (double)v62 * 0.0039215689 )
            {
              v37 = dword_75AAD0[i];
              v62 = (unsigned __int8)this[i++ + 8];
            }
          }
          break;
        case 0xA:
        case 0xB:
          sub_4FA7F0(this);
          break;
        case 0x14:
          if ( dword_7D5DA4 != 2 )
            sub_4FB180(this);
          break;
        case 0x15:
          sub_4FAF90(this);
          break;
        case 0x16:
          if ( (dword_75CBB4 == 5 || dword_75CBB4 == 6 || dword_75CBB4 == 7) && (dword_75CBAC & 1) == 0 )
            sub_4F99C0(&unk_7D7428, this[8], this[9]);
          break;
        case 0x17:
          sub_4DC900(this);
          break;
        case 0x18:
          sub_4DCA20(this[8]);
          break;
        case 0x1A:
        case 0x1B:
          sub_4DCA90(this);
          break;
        case 0x1C:
          sub_4DCCA0((char *)&unk_6310CC + 25304 * (v2 & 0x3F));
          break;
        case 0x21:
          byte_7D7528 = 1;
          break;
        case 0x22:
          byte_7D7528 = 0;
          break;
        case 0x25:
          if ( (dword_75CBAC & 1) == 0 )
            sub_4F8900(this);
          break;
        case 0x26:
          if ( (dword_75CBAC & 1) == 0 )
          {
            sub_42F950(&dword_75CBA8, 5);
            flt_7D74BC = *((float *)this + 1);
            sub_51F3D0(0, 8);
            sub_4DC260(*((float *)this + 1), -1);
            sub_45D270(&byte_764D68, aWithholdingGre, 1);
            sub_45D100(&byte_764D68, (int)aGreenFlag, 3, 16909060, 0);
            sub_41BA10(0, -1);
          }
          break;
        case 0x27:
          if ( (dword_75CBAC & 1) == 0 && this[8] == 1 )
            sub_41BCD0();
          break;
        case 0x28:
          byte_766222 = 1;
          sub_4BBF80(&unk_766220);
          break;
        case 0x29:
          if ( (dword_75CBAC & 1) != 0 && dword_75CBB0 == 6 )
            sub_4FADA0(v2 & 0x3F);
          break;
        case 0x2A:
          if ( (dword_75CBAC & 1) == 0 )
          {
            v42 = (unsigned __int16)v2 >> 6;
            if ( v42 )
            {
              v43 = -20 - (_DWORD)this;
              v44 = (unsigned __int8 *)(this + 21);
              v45 = -21 - (_DWORD)this;
              do
              {
                v46 = 6326 * *v44;
                v47 = (int)&(v44++)[v43];
                dword_6310F4[v46] = v47;
              }
              while ( (int)&v44[v45] < v42 );
            }
          }
          break;
        case 0x2B:
          v41 = (char *)&unk_62BF68 + 25304 * (v2 & 0x3F);
          *((_DWORD *)v41 + 5279) = *((_DWORD *)this + 2);
          if ( (dword_75CBAC & 1) != 0 )
            sub_4F7F20((int)v41, *((float *)this + 1));
          break;
        case 0x2C:
          if ( (dword_75CBAC & 1) != 0 )
            sub_4F81A0((char *)&unk_62BF68 + 25304 * (v2 & 0x3F));
          break;
        case 0x2D:
          if ( (dword_75CBAC & 1) != 0 )
            sub_4F8240((char *)&unk_62BF68 + 25304 * (v2 & 0x3F));
          break;
        case 0x2E:
          sub_465330(dword_764D70, 0);
          break;
        case 0x2F:
          sub_465330(dword_764D70, 1);
          break;
        default:
          return;
      }
      break;
    case 6u:
      if ( (this[2] & 0x3F) != 0 )
      {
        if ( (this[2] & 0x3F) == 1 )
        {
          v48 = v2 & 0x3F;
          if ( v48 < 48 )
            sub_4C1830((float *)&unk_630034 + 6326 * v48, (int)this);
        }
      }
      else
      {
        v49 = v2 & 0x3F;
        if ( v49 < 48 )
        {
          sub_5195F0((char *)&unk_62BF68 + 25304 * v49 + 84);
          sub_50ED40(*((_DWORD *)this + 2));
        }
      }
      break;
    default:
      return;
  }
}
