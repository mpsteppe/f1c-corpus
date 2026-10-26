char __thiscall sub_4B3400(char *this)
{
  unsigned int v2; // ecx
  char *v3; // eax
  int v4; // eax
  char *v5; // esi
  char *v6; // ebp
  int v7; // eax
  double v8; // st7
  int v9; // edx
  double v10; // st7
  int v11; // eax
  double v12; // st7
  int v13; // edx
  double v14; // st7
  int v15; // eax
  int v16; // ecx
  int v17; // eax
  int v18; // edx
  int v19; // edi
  char *v20; // esi
  int v21; // ebx
  float *v22; // eax
  float *v23; // ecx
  int v24; // edx
  double v25; // st7
  float *v26; // ecx
  int v28; // [esp+18h] [ebp-1Ch]
  int v29; // [esp+18h] [ebp-1Ch]
  int v30; // [esp+18h] [ebp-1Ch]
  int v31; // [esp+18h] [ebp-1Ch]
  float v32; // [esp+18h] [ebp-1Ch]
  int v33; // [esp+18h] [ebp-1Ch]
  float v34[3]; // [esp+1Ch] [ebp-18h] BYREF
  float v35[3]; // [esp+28h] [ebp-Ch] BYREF

  v2 = *(_DWORD *)this;
  v3 = (char *)((v2 >> 29) - 1);
  switch ( v2 >> 29 )
  {
    case 1u:
      v3 = (char *)((v2 >> 18) & 0x3F);
      switch ( (unsigned int)v3 )
      {
        case 0u:
        case 7u:
          if ( (unsigned __int8)v2 < 0x68u && *((_DWORD *)&unk_5EC6D8 + 4656 * (unsigned __int8)v2 + 3250) == 2 )
          {
            sub_463D10((unsigned __int8)v2, (int)this);
            v4 = sub_4B2B00((_DWORD *)this + 2);
            LOBYTE(v3) = sub_4C7BF0(v4);
          }
          break;
        case 1u:
        case 2u:
        case 3u:
        case 4u:
        case 5u:
        case 6u:
          if ( dword_5EF9A0[4656 * (unsigned __int8)v2] == 2 )
            LOBYTE(v3) = sub_410BC0(dword_5EA560, (int)this);
          break;
        default:
          return (char)v3;
      }
      break;
    case 2u:
      v3 = (char *)((v2 >> 18) & 0x3F);
      switch ( (unsigned int)v3 )
      {
        case 0u:
          if ( (unsigned __int8)v2 < 0x68u )
          {
            v5 = (char *)&unk_5EC6D8 + 18624 * (unsigned __int8)v2;
            sub_4E2C70(v5 + 1776);
            LOBYTE(v3) = sub_4F8A70(v5 + 20);
          }
          break;
        case 2u:
          LOBYTE(v3) = v2;
          if ( (unsigned __int8)v2 < 0x68u )
          {
            v3 = (char *)&unk_5EC6D8 + 18624 * (unsigned __int8)v2;
            if ( *((_DWORD *)v3 + 3250) >= 2u )
            {
              if ( (v2 & 0x3FF00) == 0x600 )
              {
                this[14] = 0;
                *((_DWORD *)this + 4) = 0;
              }
              v6 = this + 8;
              v3 += 4136;
              *(_DWORD *)v3 = *(_DWORD *)v6;
              *((_DWORD *)v3 + 1) = *((_DWORD *)v6 + 1);
              *((_DWORD *)v3 + 2) = *((_DWORD *)v6 + 2);
              *((_DWORD *)v3 + 3) = *((_DWORD *)v6 + 3);
              *((_WORD *)v3 + 8) = *((_WORD *)v6 + 8);
            }
          }
          break;
        case 4u:
          LOBYTE(v3) = sub_4FE060(this);
          break;
        case 5u:
          LOBYTE(v3) = sub_4FC700(this);
          break;
        case 6u:
          flt_8AFEDC = (double)(unsigned __int8)this[8] * 0.0039215689;
          break;
        case 7u:
          if ( (unsigned __int8)v2 < 0x68u )
          {
            v7 = this[10];
            v8 = (double)this[8];
            v28 = this[9];
            v9 = this[11];
            v35[0] = v8 * 0.0078740157 + v8 * 0.0078740157;
            v10 = (double)v28;
            v29 = v7;
            v11 = this[12];
            v35[1] = v10 * 0.0078740157 * 1.5;
            v12 = (double)v29;
            v30 = v9;
            v13 = this[13];
            v35[2] = v12 * 0.0078740157 * 3.5;
            v14 = (double)v30;
            v31 = v11;
            v15 = *(_DWORD *)(this + 14);
            v34[0] = v14 * 0.0078740157;
            v34[1] = (double)v31 * 0.0078740157;
            v34[2] = (double)v13 * 0.0078740157;
            LOBYTE(v3) = sub_4E3940(v15, v35, v34);
          }
          break;
        case 8u:
          if ( (unsigned __int8)v2 < 0x68u )
            LOBYTE(v3) = sub_4E3A10(*((_DWORD *)this + 2));
          break;
        default:
          return (char)v3;
      }
      break;
    case 3u:
      v16 = ((v2 >> 18) & 0x3F) - 6;
      if ( v16 )
      {
        if ( v16 == 1 )
        {
          LOBYTE(v3) = sub_4C81A0(&flt_8AC4B0);
          flt_8AC4B0 = *((float *)this + 1);
        }
      }
      else
      {
        LOBYTE(v3) = byte_7CE254;
        if ( !byte_7CE254 )
        {
          v32 = (double)(unsigned __int8)this[8] * 0.0039215689;
          v17 = sub_5884ED(0);
          LOBYTE(v3) = sub_4C8DE0(v17 % 3 + 5, LODWORD(v32));
        }
      }
      break;
    case 4u:
      v18 = (v2 >> 18) & 0x3F;
      LOBYTE(v3) = v18 - 6;
      switch ( v18 )
      {
        case 7:
          v19 = 0;
          v33 = ((v2 >> 8) & 0x3FF) - 12;
          if ( v33 > 0 )
          {
            do
            {
              v20 = (char *)&unk_5F070C + 18624 * (unsigned __int8)this[v19 + 20];
              v21 = v19 + 1;
              sub_4BC2F0(v19 + 1);
              if ( v19 <= 0 )
                *((_DWORD *)v20 + 39) = 0;
              else
                *((_DWORD *)v20 + 39) = (char *)&unk_5EC6D8 + 18624 * (unsigned __int8)this[v19 + 19];
              if ( v19 >= v33 - 1 )
                *((_DWORD *)v20 + 40) = 0;
              else
                *((_DWORD *)v20 + 40) = (char *)&unk_5EC6D8 + 18624 * (unsigned __int8)this[v19 + 21];
              if ( !v19 && *((float *)this + 2) > 0.0 )
              {
                v22 = (float *)(this + 8);
                v23 = (float *)(v20 + 116);
                v24 = 3;
                do
                {
                  v25 = *v22++;
                  *v23++ = v25;
                  --v24;
                }
                while ( v24 );
              }
              byte_8AD008[v19] = this[v19 + 20];
              LOBYTE(v3) = v33;
              ++v19;
            }
            while ( v21 < v33 );
          }
          break;
        case 8:
          if ( (unsigned __int8)v2 < 0x68u )
          {
            v3 = (char *)*((_DWORD *)&unk_5EC6D8 + 4656 * (unsigned __int8)v2 + 3250);
            if ( v3 == (char *)2 || v3 == (char *)3 )
              LOBYTE(v3) = sub_4BC4E0(
                             *((float *)this + 2),
                             *((float *)this + 1),
                             *((__int16 *)this + 6),
                             *((__int16 *)this + 7));
          }
          break;
        case 10:
        case 11:
          LOBYTE(v3) = sub_4D1A50(this);
          break;
        case 20:
          if ( dword_8AB6E4 != 2 )
            LOBYTE(v3) = sub_4D23D0(this);
          break;
        case 21:
          LOBYTE(v3) = sub_4D22C0(this);
          break;
        case 23:
          LOBYTE(v3) = sub_4BBED0(this);
          break;
        case 24:
          LOBYTE(v3) = sub_4BBF70((char *)&unk_5F070C + 18624 * (unsigned __int8)v2);
          break;
        case 26:
        case 27:
          LOBYTE(v3) = sub_4BBFC0(this);
          break;
        case 28:
          dword_5F073C[4656 * (unsigned __int8)v2] = 3;
          break;
        case 33:
          byte_8ACFE4 = 1;
          break;
        case 34:
          byte_8ACFE4 = 0;
          break;
        default:
          return (char)v3;
      }
      break;
    case 6u:
      v3 = (char *)((v2 >> 18) & 0x3F);
      if ( v3 )
      {
        if ( !--v3 )
        {
          v26 = (float *)((char *)&unk_5EC6D8 + 18624 * (unsigned __int8)v2);
          if ( *((_DWORD *)v26 + 3250) == 2 )
            LOBYTE(v3) = sub_4A5D10(v26 + 3251, (int)this);
        }
      }
      else if ( (unsigned __int8)v2 < 0x68u )
      {
        sub_4ED030((char *)&unk_5EC6D8 + 18624 * (unsigned __int8)v2 + 12);
        LOBYTE(v3) = sub_4E39D0(*((_DWORD *)this + 2));
      }
      break;
    default:
      return (char)v3;
  }
  return (char)v3;
}
