int __thiscall sub_5B5490(int *this, int a2, int a3, int a4, int a5, const char *a6)
{
  int v8; // ebp
  unsigned int v9; // esi
  _DWORD *v10; // eax
  int v11; // eax
  int v12; // eax
  _BYTE *v13; // esi
  int v14; // eax
  bool v15; // zf
  int v16; // ebx
  _BYTE *v17; // eax
  int v18; // edx
  unsigned __int16 v19; // dx
  _BYTE *v20; // esi
  unsigned __int16 v21; // dx
  _BYTE *v22; // esi
  char v23; // dl
  _BYTE *v24; // eax
  _BYTE *v25; // esi
  char v26; // dl
  _BYTE *v27; // esi
  _BYTE *v28; // eax
  unsigned int v29; // eax
  unsigned int v30; // edx
  char *v31; // ebx
  int v32; // [esp-4h] [ebp-26Ch]
  int v34; // [esp+10h] [ebp-258h]
  int v35; // [esp+10h] [ebp-258h]
  int v36; // [esp+10h] [ebp-258h]
  int v37; // [esp+10h] [ebp-258h]
  int v38; // [esp+10h] [ebp-258h]
  _DWORD *v39; // [esp+14h] [ebp-254h]
  FILE *Stream; // [esp+18h] [ebp-250h]
  _BYTE *v41; // [esp+1Ch] [ebp-24Ch]
  char *v42; // [esp+20h] [ebp-248h]
  __int16 v43; // [esp+28h] [ebp-240h] BYREF
  int v44; // [esp+2Ah] [ebp-23Eh]
  __int16 v45; // [esp+2Eh] [ebp-23Ah]
  __int16 v46; // [esp+30h] [ebp-238h]
  int v47; // [esp+32h] [ebp-236h]
  _DWORD v48[3]; // [esp+36h] [ebp-232h] BYREF
  __int16 v49; // [esp+42h] [ebp-226h]
  __int16 v50; // [esp+44h] [ebp-224h]
  int v51; // [esp+46h] [ebp-222h]
  int v52; // [esp+4Ah] [ebp-21Eh]
  int v53; // [esp+4Eh] [ebp-21Ah]
  int v54; // [esp+52h] [ebp-216h]
  int v55; // [esp+56h] [ebp-212h]
  int v56; // [esp+5Ah] [ebp-20Eh]
  char Buffer[256]; // [esp+68h] [ebp-200h] BYREF
  char Format[256]; // [esp+168h] [ebp-100h] BYREF

  v32 = dword_7FEEAC++;
  if ( a6 )
    sprintf(Buffer, "%sGRAB_%.3d.BMP", a6, v32);
  else
    sprintf(Buffer, "GRAB_%.3d.BMP", v32);
  Stream = fopen(Buffer, aWb);
  if ( Stream )
  {
    v8 = a5 * a4;
    v9 = a5 * ((a4 + 3) & 0xFFFFFFFC);
    v41 = operator new(3 * a5 * a4);
    v42 = (char *)operator new(3 * v9);
    v53 = 3700;
    v54 = 3700;
    v43 = 19778;
    v44 = 3 * v9 + 54;
    v45 = 0;
    v46 = 0;
    v47 = 54;
    v48[0] = 40;
    v48[1] = a4;
    v48[2] = a5;
    v49 = 1;
    v50 = 24;
    v51 = 0;
    v52 = 0;
    v55 = 0;
    v56 = 0;
    sub_5BF5A6(&v43, 1u, 0xEu, Stream);
    sub_5BF5A6(v48, 1u, 0x28u, Stream);
    v10 = operator new(0x40u);
    if ( v10 )
    {
      v39 = sub_59F160(v10);
      v11 = sub_59F580(v39, a4, a5, this[12], 17);
    }
    else
    {
      v39 = 0;
      v11 = sub_59F580(0, a4, a5, this[12], 17);
    }
    if ( v11 )
    {
      sub_591C60((int)this, -1, aErrorAllocatin_0);
      return -1;
    }
    else
    {
      sub_59FDC0(this, a2, a3, (int)v39, 0, 0, a4, a5, -2, 0);
      v12 = v39[14];
      v13 = v41;
      if ( (v12 & 1) != 0 )
      {
        v14 = 1;
      }
      else
      {
        v15 = (v12 & 2) == 0;
        v14 = 2;
        if ( v15 )
          v14 = 3 * a5 * a4;
      }
      v16 = 0;
      v17 = (_BYTE *)sub_59FD80(v39, v14 | 0x100, 0);
      *v39 = v17;
      v18 = this[12];
      switch ( v18 )
      {
        case 5:
          if ( v8 > 0 )
          {
            v34 = a5 * a4;
            do
            {
              *v13 = 8 * *v17;
              v19 = *(_WORD *)v17;
              v20 = v13 + 1;
              v17 += 2;
              *v20++ = (v19 >> 2) & 0xF8;
              *v20 = (*((unsigned __int16 *)v17 - 1) >> 7) & 0xF8;
              v13 = v20 + 1;
              if ( ++v16 == a4 )
              {
                v16 = 0;
                v17 += 2 * ((v39[10] - 2 * a4) >> 1);
              }
              --v34;
            }
            while ( v34 );
          }
          break;
        case 6:
          if ( v8 > 0 )
          {
            v35 = a5 * a4;
            do
            {
              *v13 = 8 * *v17;
              v21 = *(_WORD *)v17;
              v22 = v13 + 1;
              v17 += 2;
              *v22++ = (v21 >> 3) & 0xFC;
              *v22 = *(v17 - 1) & 0xF8;
              v13 = v22 + 1;
              if ( ++v16 == a4 )
              {
                v16 = 0;
                v17 += 2 * ((v39[10] - 2 * a4) >> 1);
              }
              --v35;
            }
            while ( v35 );
          }
          break;
        case 7:
          if ( v8 > 0 )
          {
            v36 = a5 * a4;
            do
            {
              *v13 = *v17;
              v23 = v17[1];
              v24 = v17 + 1;
              v25 = v13 + 2;
              *(v25 - 1) = v23;
              v13 = v25 + 1;
              *(v13 - 1) = v24[1];
              v17 = v24 + 2;
              if ( ++v16 == a4 )
              {
                v16 = 0;
                v17 += v39[10] - 3 * a4;
              }
              --v36;
            }
            while ( v36 );
          }
          break;
        default:
          if ( v18 == 8 && v8 > 0 )
          {
            v37 = a5 * a4;
            do
            {
              *v13 = *v17;
              v26 = v17[1];
              v27 = v13 + 1;
              v28 = v17 + 1;
              *v27++ = v26;
              *v27 = v28[1];
              v13 = v27 + 1;
              v17 = v28 + 3;
              if ( ++v16 == a4 )
              {
                v16 = 0;
                v17 += v39[10] - 4 * a4;
              }
              --v37;
            }
            while ( v37 );
          }
          break;
      }
      sub_59FDA0(v39, 0, 0);
      *v39 = 0;
      sub_59FA90(v39);
      j_nullsub_6(v39);
      sub_5BE8AE();
      v29 = 3 * a4;
      v30 = 0;
      if ( a5 > 0 )
      {
        v31 = &v41[3 * a4 * (a5 - 1)];
        v38 = a5;
        do
        {
          qmemcpy(&v42[v30], v31, v29);
          v31 -= v29;
          v30 = (v29 + v30 + 3) & 0xFFFFFFFC;
          --v38;
        }
        while ( v38 );
      }
      sub_5BF5A6(v42, 1u, 3 * a5 * a4, Stream);
      fclose(Stream);
      sub_5BE8AE();
      sub_5BE8AE();
      return 0;
    }
  }
  else
  {
    sprintf(Format, "Error opening bitmap file %s", Buffer);
    sub_591C60((int)this, -1, Format);
    return -1;
  }
}
