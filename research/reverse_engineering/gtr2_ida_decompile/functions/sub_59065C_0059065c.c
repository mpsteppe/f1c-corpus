// local variable allocation has failed, the output may be wrong!
// positive sp value has been detected, the output may be wrong!
int __userpurge sub_59065C@<eax>(char a1@<cl>, int a2@<ebp>, int a3, int a4, int a5, char a6, __int16 a7)
{
  int v8; // edi
  unsigned int v9; // edx
  int v10; // esi
  const CHAR *v11; // eax
  int v12; // edx
  CHAR v13; // cl
  char *v14; // eax
  unsigned int v15; // eax
  char v16; // cl
  char *v17; // edi
  unsigned int v19; // esi
  char v20; // al
  char *v21; // edi
  char *v23; // edi
  float X; // [esp+4h] [ebp-18h]
  float Xa; // [esp+4h] [ebp-18h]
  float v28; // [esp+14h] [ebp-8h]
  float v29; // [esp+18h] [ebp-4h]
  int retaddr; // [esp+1Ch] [ebp+0h]
  int v31; // [esp+20h] [ebp+4h]

  if ( sub_473630(&dword_B6CBA8) )
    return 0;
  v8 = *((_DWORD *)dword_FB2790 + 2);
  v9 = (int)((unsigned __int64)(1717986919LL * *((int *)dword_FB2790 + 1)) >> 32) >> 2;
  v10 = *((_DWORD *)dword_FB2790 + 1) / 10;
  a4 = *((_DWORD *)dword_FB2790 + 1);
  a5 = v8;
  v31 = v9 + (v9 >> 31);
  if ( a1 )
  {
    v11 = dword_B6F68C;
    if ( !dword_B6F68C )
      v11 = WindowName;
    v12 = &a6 - v11;
    do
    {
      v13 = *v11;
      v11[v12] = *v11;
      ++v11;
    }
    while ( v13 );
    v14 = &a6 + strlen(&a6);
    if ( v14 > &a6 )
    {
      while ( *v14 != 46 )
      {
        if ( --v14 <= &a6 )
          goto LABEL_12;
      }
      *v14 = 0;
    }
LABEL_12:
    dword_FB1EF0 = -999;
    v15 = strlen(&a6);
    if ( *(&a6 + v15) != 92 )
    {
      do
        v16 = *((_BYTE *)&a5 + v15-- + 3);
      while ( v16 != 92 );
    }
    *((_BYTE *)&a7 + v15 + 1) = 0;
    v28 = sub_5529A0(dword_FADD40);
    if ( byte_FADD28 )
      v28 = sub_54B400(dword_BE27B0);
    LOBYTE(STACK[0x148]) = 0;
    memset(&STACK[0x149], 0, 0xFCu);
    LOWORD(STACK[0x245]) = 0;
    LOBYTE(STACK[0x247]) = 0;
    if ( v28 != -1.0 && !(unsigned __int8)sub_4735A0() )
    {
      sub_53A560(v28, &STACK[0x128], 32);
      sub_632041(&STACK[0x148], 255, "%s%s_LOD.jpg", (const char *)&a5, (const char *)&STACK[0x128]);
    }
    v17 = (char *)&a4 + 3;
    while ( *++v17 )
      ;
    strcpy(v17, "_LOD.jpg");
    if ( sub_5E7E80(dword_FB1CE0, (int)&flt_FB1EEC, (char)&STACK[0x148], 0, 1)
      && sub_5E7E80(dword_FB1CE0, (int)&flt_FB1EEC, (char)&a5, 0, 1)
      && sub_5E7E80(dword_FB1CE0, (int)&flt_FB1EEC, (char)"df_LOD.bmp", 0, 1) )
    {
      flt_FB1EEC = 0.0;
    }
    v19 = strlen((const char *)&a5);
    if ( *((_BYTE *)&a5 + v19) != 92 )
    {
      do
        v20 = *((_BYTE *)&a4 + v19-- + 3);
      while ( v20 != 92 );
    }
    *(&a6 + v19 + 1) = 0;
    v21 = (char *)&a4 + 3;
    while ( *++v21 )
      ;
    strcpy(v21, "_LOD_2.jpg");
    if ( !sub_5E7E80(dword_FB1CE0, (int)&flt_FB1EE8, (char)&a5, 0, 1) )
      goto LABEL_35;
    *(&a6 + v19) = 0;
    v23 = (char *)&a4 + 3;
    while ( *++v23 )
      ;
    strcpy(v23, "_LOD_2.jpg");
    if ( sub_5E7E80(dword_FB1CE0, (int)&flt_FB1EE8, (char)&a5, 0, 1)
      && sub_5E7E80(dword_FB1CE0, (int)&flt_FB1EE8, (char)"df_LOD2.bmp", 0, 1) )
    {
      v8 = a4;
      v10 = retaddr;
      flt_FB1EE8 = 0.0;
    }
    else
    {
LABEL_35:
      if ( LODWORD(flt_FB1EE8) )
      {
        X = (double)*(int *)(LODWORD(flt_FB1EE8) + 8) * (double)v31 / (double)*(int *)(LODWORD(flt_FB1EE8) + 4);
        dword_903ED0 = sub_4015C0(X);
      }
      v8 = a4;
      v10 = retaddr;
    }
  }
  if ( floor((double)dword_757C10 * 1.5 + 113.0) * 0.0099999998 > *(float *)(a2 + 8) )
  {
    v29 = (double)(v31 - v10) * (*(float *)(a2 + 8) * 100.0);
    Xa = v29 / floor((double)dword_757C10 * 1.5 + 113.0);
    sub_4015C0(Xa);
    return ((int (__stdcall *)(int))off_16C94D8)(v31);
  }
  else
  {
    if ( LODWORD(flt_FB1EE8) )
    {
      sub_4DDC20(
        flt_FB1EE8,
        0,
        0,
        *(_DWORD *)(LODWORD(flt_FB1EE8) + 4),
        *(_DWORD *)(LODWORD(flt_FB1EE8) + 8),
        (int)dword_FB2790,
        0,
        v8 - dword_903ED0 + 1,
        *((_DWORD *)dword_FB2790 + 1),
        dword_903ED0 - 1,
        -1,
        -1,
        -1,
        -1);
      sub_4DDA20();
      sub_5E7F70(dword_FB1CE0, SLODWORD(flt_FB1EE8));
      flt_FB1EE8 = 0.0;
    }
    if ( LODWORD(flt_FB1EEC) )
    {
      sub_5E7F70(dword_FB1CE0, SLODWORD(flt_FB1EEC));
      flt_FB1EEC = 0.0;
    }
    sub_540160(0);
    return 0;
  }
}
