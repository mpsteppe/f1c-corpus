int __thiscall sub_551FD0(_DWORD *this, int a2, int a3, int a4, int a5, const char *a6)
{
  int v7; // ebp
  unsigned int v8; // esi
  _DWORD *v9; // eax
  int v10; // eax
  int v11; // eax
  _BYTE *v12; // esi
  int v13; // eax
  bool v14; // zf
  int v15; // ebx
  _BYTE *v16; // eax
  int v17; // edx
  unsigned __int16 v18; // dx
  _BYTE *v19; // esi
  unsigned __int16 v20; // dx
  _BYTE *v21; // esi
  char v22; // dl
  _BYTE *v23; // eax
  _BYTE *v24; // esi
  char v25; // dl
  _BYTE *v26; // esi
  _BYTE *v27; // eax
  unsigned int v28; // eax
  unsigned int v29; // edx
  char *v30; // ebx
  int v31; // [esp-4h] [ebp-26Ch]
  int v33; // [esp+10h] [ebp-258h]
  int v34; // [esp+10h] [ebp-258h]
  int v35; // [esp+10h] [ebp-258h]
  int v36; // [esp+10h] [ebp-258h]
  int v37; // [esp+10h] [ebp-258h]
  _DWORD *v38; // [esp+14h] [ebp-254h]
  int v39; // [esp+18h] [ebp-250h]
  _BYTE *v40; // [esp+1Ch] [ebp-24Ch]
  char *v41; // [esp+20h] [ebp-248h]
  __int16 v42; // [esp+28h] [ebp-240h] BYREF
  int v43; // [esp+2Ah] [ebp-23Eh]
  __int16 v44; // [esp+2Eh] [ebp-23Ah]
  __int16 v45; // [esp+30h] [ebp-238h]
  int v46; // [esp+32h] [ebp-236h]
  _DWORD v47[3]; // [esp+36h] [ebp-232h] BYREF
  __int16 v48; // [esp+42h] [ebp-226h]
  __int16 v49; // [esp+44h] [ebp-224h]
  int v50; // [esp+46h] [ebp-222h]
  int v51; // [esp+4Ah] [ebp-21Eh]
  int v52; // [esp+4Eh] [ebp-21Ah]
  int v53; // [esp+52h] [ebp-216h]
  int v54; // [esp+56h] [ebp-212h]
  int v55; // [esp+5Ah] [ebp-20Eh]
  char v56[256]; // [esp+68h] [ebp-200h] BYREF
  char v57[256]; // [esp+168h] [ebp-100h] BYREF

  v31 = dword_8CBF48++;
  if ( a6 )
    StringFormatWithBufferOverflowCheck(v56, "%sGRAB_%.3d.BMP", a6, v31);
  else
    StringFormatWithBufferOverflowCheck(v56, "GRAB_%.3d.BMP", v31);
  v39 = sub_587DB0(v56, &unk_5C2AB0);
  if ( v39 )
  {
    v7 = a5 * a4;
    v8 = a5 * ((a4 + 3) & 0xFFFFFFFC);
    v40 = (_BYTE *)OperatorNewNhMallocWrapper(3 * a5 * a4);
    v41 = (char *)OperatorNewNhMallocWrapper(3 * v8);
    v52 = 3700;
    v53 = 3700;
    v42 = 19778;
    v43 = 3 * v8 + 54;
    v44 = 0;
    v45 = 0;
    v46 = 54;
    v47[0] = 40;
    v47[1] = a4;
    v47[2] = a5;
    v48 = 1;
    v49 = 24;
    v50 = 0;
    v51 = 0;
    v54 = 0;
    v55 = 0;
    FileReadWrapperWithLock(&v42, 1, 14, v39);
    FileReadWrapperWithLock(v47, 1, 40, v39);
    v9 = (_DWORD *)OperatorNewNhMallocWrapper(60);
    if ( v9 )
    {
      v38 = AudioEmitterCreate(v9);
      v10 = UtilityFunction_2950(v38, a4, a5, this[12], 17);
    }
    else
    {
      v38 = 0;
      v10 = UtilityFunction_2950(0, a4, a5, this[12], 17);
    }
    if ( v10 )
    {
      sub_53C590(-1, aErrorAllocatin_0);
      return -1;
    }
    else
    {
      ClippedRenderRegion(this, a2, a3, v38, 0, 0, a4, a5, -2, 0);
      v11 = v38[6];
      v12 = v40;
      if ( (v11 & 1) != 0 )
      {
        v13 = 1;
      }
      else
      {
        v14 = (v11 & 2) == 0;
        v13 = 2;
        if ( v14 )
          v13 = 3 * a5 * a4;
      }
      v15 = 0;
      v16 = (_BYTE *)ThunkWithArgReorder(v38, v13 | 0x100, 0);
      *v38 = v16;
      v17 = this[12];
      switch ( v17 )
      {
        case 5:
          if ( v7 > 0 )
          {
            v33 = a5 * a4;
            do
            {
              *v12 = 8 * *v16;
              v18 = *(_WORD *)v16;
              v19 = v12 + 1;
              v16 += 2;
              *v19++ = (v18 >> 2) & 0xF8;
              *v19 = (*((unsigned __int16 *)v16 - 1) >> 7) & 0xF8;
              v12 = v19 + 1;
              if ( ++v15 == a4 )
              {
                v15 = 0;
                v16 += 2 * ((v38[10] - 2 * a4) >> 1);
              }
              --v33;
            }
            while ( v33 );
          }
          break;
        case 6:
          if ( v7 > 0 )
          {
            v34 = a5 * a4;
            do
            {
              *v12 = 8 * *v16;
              v20 = *(_WORD *)v16;
              v21 = v12 + 1;
              v16 += 2;
              *v21++ = (v20 >> 3) & 0xFC;
              *v21 = *(v16 - 1) & 0xF8;
              v12 = v21 + 1;
              if ( ++v15 == a4 )
              {
                v15 = 0;
                v16 += 2 * ((v38[10] - 2 * a4) >> 1);
              }
              --v34;
            }
            while ( v34 );
          }
          break;
        case 7:
          if ( v7 > 0 )
          {
            v35 = a5 * a4;
            do
            {
              *v12 = *v16;
              v22 = v16[1];
              v23 = v16 + 1;
              v24 = v12 + 2;
              *(v24 - 1) = v22;
              v12 = v24 + 1;
              *(v12 - 1) = v23[1];
              v16 = v23 + 2;
              if ( ++v15 == a4 )
              {
                v15 = 0;
                v16 += v38[10] - 3 * a4;
              }
              --v35;
            }
            while ( v35 );
          }
          break;
        default:
          if ( v17 == 8 && v7 > 0 )
          {
            v36 = a5 * a4;
            do
            {
              *v12 = *v16;
              v25 = v16[1];
              v26 = v12 + 1;
              v27 = v16 + 1;
              *v26++ = v25;
              *v26 = v27[1];
              v12 = v26 + 1;
              v16 = v27 + 3;
              if ( ++v15 == a4 )
              {
                v15 = 0;
                v16 += v38[10] - 4 * a4;
              }
              --v36;
            }
            while ( v36 );
          }
          break;
      }
      ArgumentReorderWrapper_3230(v38, 0, 0);
      *v38 = 0;
      sub_542E50(v38);
      EmptyStub_7470(v38);
      FreeWrapper_7bcf(v38);
      v28 = 3 * a4;
      v29 = 0;
      if ( a5 > 0 )
      {
        v30 = &v40[3 * a4 * (a5 - 1)];
        v37 = a5;
        do
        {
          qmemcpy(&v41[v29], v30, v28);
          v30 -= v28;
          v29 = (v28 + v29 + 3) & 0xFFFFFFFC;
          --v37;
        }
        while ( v37 );
      }
      FileReadWrapperWithLock(v41, 1, 3 * a5 * a4, v39);
      FileCloseWithLock(v39);
      FreeWrapper_7bcf(v40);
      FreeWrapper_7bcf(v41);
      return 0;
    }
  }
  else
  {
    StringFormatWithBufferOverflowCheck(v57, "Error opening bitmap file %s", v56);
    sub_53C590(-1, v57);
    return -1;
  }
}
