// positive sp value has been detected, the output may be wrong!
void __thiscall sub_51B2F0(unsigned __int8 *this)
{
  unsigned int v2; // ecx
  char *v3; // esi
  char *v4; // eax
  float v5; // eax
  float v6; // edx
  double v7; // st7
  float v8; // eax
  char *v9; // edi
  double v10; // st7
  int v11; // edx
  double v12; // st7
  int v13; // eax
  float v14; // edx
  int v15; // eax
  int v16; // ecx
  double v17; // st7
  float v18; // edx
  double v19; // st7
  float v20; // ecx
  int v21; // edx
  int v22; // eax
  double v23; // st7
  int v24; // ecx
  int v25; // eax
  int v26; // eax
  int v27; // eax
  int v28; // ebp
  _DWORD *v29; // edi
  int v30; // ebx
  int v31; // ecx
  char *v32; // ecx
  int v33; // ecx
  unsigned __int8 *v34; // eax
  int v35; // edx
  int v36; // edi
  int v37; // esi
  char *v38; // edi
  int v39; // [esp-8h] [ebp-54h]
  float v40; // [esp-8h] [ebp-54h]
  int v41; // [esp+4h] [ebp-48h]
  int v42; // [esp+8h] [ebp-44h]
  float v43; // [esp+10h] [ebp-3Ch] BYREF
  float v44; // [esp+14h] [ebp-38h] BYREF
  int v45; // [esp+18h] [ebp-34h] BYREF
  int v46; // [esp+1Ch] [ebp-30h] BYREF
  float v47[3]; // [esp+20h] [ebp-2Ch] BYREF
  float v48; // [esp+2Ch] [ebp-20h] BYREF
  float v49; // [esp+30h] [ebp-1Ch]
  int v50; // [esp+34h] [ebp-18h]
  float v51; // [esp+38h] [ebp-14h] BYREF
  float v52; // [esp+3Ch] [ebp-10h]
  int v53; // [esp+40h] [ebp-Ch]

  v2 = *(_DWORD *)this;
  switch ( v2 >> 29 )
  {
    case 1u:
      switch ( (v2 >> 18) & 0x3F )
      {
        case 0u:
        case 7u:
          if ( (unsigned __int8)v2 < 0x69u && *((_DWORD *)&unk_9204A0 + 5654 * (unsigned __int8)v2 + 3705) == 2 )
          {
            sub_475BC0((unsigned __int8)v2, (int)this);
            sub_53E370((*((_DWORD *)this + 3) >> 28) & 7);
          }
          break;
        case 1u:
        case 2u:
        case 3u:
        case 4u:
        case 5u:
        case 6u:
          if ( dword_923E84[5654 * (unsigned __int8)v2] == 2 )
            sub_419E80(&dword_91BF88, (int)this);
          break;
        default:
          return;
      }
      break;
    case 2u:
      switch ( (v2 >> 18) & 0x3F )
      {
        case 0u:
          if ( (unsigned __int8)v2 < 0x68u )
          {
            v3 = (char *)&unk_9204A0 + 22616 * (unsigned __int8)v2;
            ((void (__thiscall *)(char *))sub_56B9C0)(v3 + 2704);
            ((void (__thiscall *)(char *))sub_58C8C0)(v3 + 24);
          }
          break;
        case 2u:
          if ( (unsigned __int8)v2 < 0x68u )
          {
            v4 = (char *)&unk_9204A0 + 22616 * (unsigned __int8)v2;
            if ( *((_DWORD *)v4 + 3705) >= 2u )
            {
              if ( (v2 & 0x3FF00) == 0x600 )
              {
                this[14] = 0;
                *((_DWORD *)this + 4) = 0;
              }
              sub_51A380(v4 + 2704, (int)(this + 8));
            }
          }
          break;
        case 4u:
          sub_5938D0(this);
          break;
        case 5u:
          sub_5933F0(this);
          break;
        case 6u:
          flt_FB1F10 = (double)this[8] * 0.0039215689;
          break;
        case 7u:
          if ( (unsigned __int8)v2 < 0x68u )
          {
            LODWORD(v5) = (char)this[9];
            LODWORD(v43) = (char)this[8];
            LODWORD(v6) = (char)this[10];
            v7 = (double)SLODWORD(v43);
            v43 = v5;
            LODWORD(v8) = (char)this[11];
            v9 = (char *)&unk_9204A0 + 22616 * (unsigned __int8)v2;
            v48 = v7 * 0.0078740157 + v7 * 0.0078740157;
            v10 = (double)SLODWORD(v43);
            v43 = v6;
            v11 = (char)this[12];
            v49 = v10 * 0.0078740157 * 1.5;
            v12 = (double)SLODWORD(v43);
            v43 = v8;
            v13 = (char)this[13];
            *(float *)&v50 = v12 * 0.0078740157 * 3.5;
            v47[0] = (double)SLODWORD(v43) * 0.0078740157;
            v43 = *(float *)&v13;
            v39 = *(_DWORD *)(this + 14);
            v47[1] = (double)v11 * 0.0078740157;
            v47[2] = (double)v13 * 0.0078740157;
            sub_570D50(v39, &v48, v47);
            LODWORD(v14) = (char)this[19];
            v15 = (char)this[20];
            LODWORD(v43) = (char)this[18];
            v16 = (char)this[21];
            v17 = (double)SLODWORD(v43);
            v43 = v14;
            v18 = *(float *)(this + 14);
            v51 = v17 * 0.0078740157;
            v19 = (double)SLODWORD(v43);
            v43 = *(float *)&v15;
            v52 = v19 * 0.0078740157;
            *(float *)&v53 = (double)v15 * 0.0078740157;
            sub_56BCC0((int)(v9 + 16), (int)&v48, (int)v47, (int)&v51, v18, v16);
          }
          break;
        case 8u:
          if ( (unsigned __int8)v2 < 0x68u )
            ((void (__thiscall *)(char *, _DWORD))sub_570E60)(
              (char *)&unk_920F30 + 22616 * (unsigned __int8)v2,
              *((_DWORD *)this + 2));
          break;
        case 9u:
          if ( (unsigned __int8)v2 < 0x69u && (dword_925CD4[5654 * (unsigned __int8)v2] & 2) != 0 && dword_BE2758 )
          {
            LODWORD(v43) = *((_DWORD *)this + 2) << 10;
            v48 = (double)SLODWORD(v43) * 0.000015258789;
            v49 = sub_416490((_DWORD *)this + 2);
            LODWORD(v20) = (char)this[16];
            v21 = (char)this[17];
            LODWORD(v43) = *((_DWORD *)this + 3) << 10;
            v22 = (char)this[18];
            v23 = (double)SLODWORD(v43);
            v43 = v20;
            v24 = this[19];
            *(float *)&v50 = v23 * 0.000015258789;
            v51 = (double)SLODWORD(v43) * 0.0078740157;
            v52 = (double)v21 * 0.0078740157;
            v43 = *(float *)&v24;
            *(float *)&v53 = (double)v22 * 0.0078740157;
            v40 = (double)v24 * 0.0039215689;
            sub_544F00((int)&v48, (int)&v51, v40, (int)byte_FFFFFF, 0);
          }
          break;
        default:
          return;
      }
      break;
    case 3u:
      v25 = (v2 >> 18) & 0x3F;
      if ( v25 )
      {
        v26 = v25 - 1;
        if ( v26 )
        {
          if ( v26 == 1 )
          {
            ((void (__thiscall *)(int *))sub_5403F0)(&dword_BE1D20);
            dword_BE1D20 = *((_DWORD *)this + 1);
          }
        }
        else if ( !byte_B6F118 )
        {
          v43 = (double)this[8] * 0.0039215689;
          v27 = rand();
          sub_540E90(&unk_BE1D30, v27 % 3 + 5, LODWORD(v43));
        }
      }
      else if ( (unsigned __int8)v2 < 0x69u && dword_923E84[5654 * (unsigned __int8)v2] == 3 )
      {
        sub_519F40((unsigned __int16 *)this + 4, &v46, &v45, &v44, &v43);
        sub_58C630(v46);
      }
      break;
    case 4u:
      switch ( (v2 >> 18) & 0x3F )
      {
        case 7u:
          v28 = 0;
          v46 = ((v2 >> 8) & 0x3FF) - 12;
          if ( v46 > 0 )
          {
            do
            {
              v29 = (_DWORD *)((char *)&unk_924FE8 + 22616 * this[v28 + 20]);
              v30 = v28 + 1;
              sub_52C360(v28 + 1);
              if ( v28 <= 0 )
                v29[56] = 0;
              else
                v29[56] = (char *)&unk_9204A0 + 22616 * this[v28 + 19];
              v31 = v45;
              if ( v28 >= v45 - 1 )
                v29[57] = 0;
              else
                v29[57] = (char *)&unk_9204A0 + 22616 * this[v28 + 21];
              if ( !v28 && *((float *)this + 2) > 0.0 )
              {
                v29[44] = *((_DWORD *)this + 2);
                v29[45] = *((_DWORD *)this + 3);
                v29[46] = *((_DWORD *)this + 4);
              }
              byte_FADEB0[v28] = this[v28 + 20];
              ++v28;
            }
            while ( v30 < v31 );
          }
          break;
        case 8u:
          if ( (unsigned __int8)v2 < 0x69u && *((int *)&unk_9204A0 + 5654 * (unsigned __int8)v2 + 3705) >= 2 )
          {
            if ( (unsigned __int8)v2 == 104 )
            {
              if ( dword_FADE9C > 0 || dword_B64134 < 5 )
                ((void (__thiscall *)(char *, _DWORD))sub_52B420)(&byte_9034D0, *((__int16 *)this + 6));
            }
            else
            {
              sub_52D970(*((_DWORD *)this + 2), *((_DWORD *)this + 1), *((__int16 *)this + 6), *((__int16 *)this + 7));
            }
          }
          break;
        case 0xAu:
        case 0xBu:
          ((void (__thiscall *)(void *, unsigned __int8 *))sub_5554C0)(&unk_FADD40, this);
          break;
        case 0x12u:
          if ( dword_BE1204 != 2 )
            sub_551CB0(this);
          break;
        case 0x13u:
          if ( dword_BE1204 != 2 )
            sub_551B80(this);
          break;
        case 0x14u:
          if ( dword_BE1204 != 2 )
            dword_FADE30 = *((_DWORD *)this + 2);
          break;
        case 0x15u:
          if ( dword_BE1204 != 2
            && (dword_B64134 == 5 || dword_B64134 == 6 || dword_B64134 == 7)
            && (dword_B640C4 & 1) == 0 )
          {
            ((void (__thiscall *)(void *, _DWORD, _DWORD))sub_5500B0)(&unk_FADD40, (char)this[8], (char)this[9]);
          }
          break;
        case 0x16u:
          if ( dword_BE1204 != 2 )
            sub_52BD80(this);
          break;
        case 0x17u:
          if ( dword_BE1204 != 2 )
            sub_52BE40(v41, v42);
          break;
        case 0x18u:
        case 0x19u:
          if ( dword_BE1204 != 2 )
            sub_52BE90(this);
          break;
        case 0x1Au:
          if ( dword_BE1204 != 2 )
            ((void (__thiscall *)(char *))sub_52BFE0)((char *)&unk_924FE8 + 22616 * (unsigned __int8)v2);
          break;
        case 0x1Du:
          byte_FADE88 = 1;
          break;
        case 0x1Eu:
          byte_FADE88 = 0;
          break;
        case 0x21u:
          if ( (dword_B640C4 & 1) == 0 && dword_BE1204 != 2 )
            ((void (__thiscall *)(char *, unsigned __int8 *))sub_54F590)(&byte_FADF20, this);
          break;
        case 0x22u:
          if ( (dword_B640C4 & 1) == 0 && dword_BE1204 != 2 )
            sub_52B190(1);
          break;
        case 0x23u:
          if ( (dword_B640C4 & 1) == 0 && dword_BE1204 != 2 )
            sub_52B190(0);
          break;
        case 0x24u:
          if ( dword_BE1204 != 2 )
          {
            byte_9034D2 = 1;
            ((void (__thiscall *)(char *))sub_52B3E0)(&byte_9034D0);
          }
          break;
        case 0x25u:
          if ( (dword_B640C4 & 1) != 0 && *(_DWORD *)dword_B640C8 == 5 )
            ((void (__thiscall *)(void *, _DWORD))sub_5518F0)(&unk_FADD40, (unsigned __int8)v2);
          break;
        case 0x26u:
          if ( (dword_B640C4 & 1) == 0 )
          {
            v33 = (v2 >> 8) & 0x3FF;
            if ( v33 )
            {
              v34 = this + 20;
              v35 = -19 - (_DWORD)this;
              do
              {
                v36 = 5654 * *v34;
                v37 = (int)&(v34++)[v35];
                --v33;
                dword_925014[v36] = v37;
              }
              while ( v33 );
            }
          }
          break;
        case 0x27u:
          v32 = (char *)&unk_9204A0 + 22616 * (unsigned __int8)v2;
          *((_DWORD *)v32 + 4888) = *((_DWORD *)this + 2);
          if ( (dword_B640C4 & 1) != 0 )
            sub_552CA0(v32, *((_DWORD *)this + 1));
          break;
        case 0x28u:
          if ( (dword_B640C4 & 1) != 0 && dword_BE1204 != 2 )
            ((void (__thiscall *)(char *, char *))sub_54F160)(
              &byte_FADF20,
              (char *)&unk_9204A0 + 22616 * (unsigned __int8)v2);
          break;
        case 0x29u:
          if ( (dword_B640C4 & 1) != 0 && dword_BE1204 != 2 )
            sub_552F80((char *)&unk_9204A0 + 22616 * (unsigned __int8)v2);
          break;
        case 0x2Au:
        case 0x2Bu:
          sub_475B30();
          break;
        default:
          return;
      }
      break;
    case 6u:
      switch ( (v2 >> 18) & 0x3F )
      {
        case 0u:
          if ( (unsigned __int8)v2 < 0x68u )
          {
            v38 = (char *)&unk_9204A0 + 22616 * (unsigned __int8)v2;
            ((void (__thiscall *)(char *))sub_57BCB0)(v38 + 16);
            ((void (__thiscall *)(char *, _DWORD))sub_570DE0)(v38 + 2704, *((_DWORD *)this + 2));
          }
          break;
        case 1u:
          if ( (unsigned __int8)v2 < 0x68u )
            ((void (__thiscall *)(char *))sub_57BDB0)((char *)&unk_9204B0 + 22616 * (unsigned __int8)v2);
          break;
        case 2u:
          if ( (unsigned __int8)v2 < 0x68u )
            ((void (__thiscall *)(char *))sub_57BE70)((char *)&unk_9204B0 + 22616 * (unsigned __int8)v2);
          break;
        case 3u:
          if ( (unsigned __int8)v2 < 0x68u )
            ((void (__thiscall *)(char *))sub_576A50)((char *)&unk_9204B0 + 22616 * (unsigned __int8)v2);
          break;
        case 4u:
          if ( (unsigned __int8)v2 < 0x68u )
            ((void (__thiscall *)(char *))sub_576AA0)((char *)&unk_9204B0 + 22616 * (unsigned __int8)v2);
          break;
        case 5u:
          if ( *((_DWORD *)&unk_9204A0 + 5654 * (unsigned __int8)v2 + 3705) == 2 )
            sub_4FD580();
          break;
        case 6u:
          if ( sub_4FB7D0((_DWORD *)&unk_9204A0 + 5654 * (unsigned __int8)v2 + 3706) )
            sub_4F1D00();
          break;
        case 7u:
          if ( sub_4FB7D0((_DWORD *)&unk_9204A0 + 5654 * (unsigned __int8)v2 + 3706) )
            sub_4F3F00();
          break;
        default:
          return;
      }
      break;
    default:
      return;
  }
}
