void __userpurge sub_4E1950(int a1@<ecx>, int a2@<ebp>, int a3@<edi>, int a4@<esi>, const char *a5, char a6)
{
  int v6; // ebx
  char v7; // al
  char v8; // cl
  int v9; // esi
  const char *v10; // eax
  int v11; // edx
  int v12; // ebx
  int v13; // edi
  int v14; // ebp
  float v15; // eax
  int v16; // esi
  unsigned int v17; // ecx
  int v18; // esi
  int v19; // edi
  int v20; // ebx
  int v21; // ebp
  double v22; // st7
  double v23; // st7
  int v24; // eax
  int v25; // esi
  int v26; // [esp+0h] [ebp-3DCh]
  int v27; // [esp+4h] [ebp-3D8h]
  float v28; // [esp+8h] [ebp-3D4h]
  int v30; // [esp+18h] [ebp-3C4h]
  void *Block; // [esp+1Ch] [ebp-3C0h]
  float Blocka; // [esp+1Ch] [ebp-3C0h]
  int v33; // [esp+20h] [ebp-3BCh] BYREF
  int v34; // [esp+24h] [ebp-3B8h] BYREF
  int v35; // [esp+28h] [ebp-3B4h] BYREF
  int v36[2]; // [esp+2Ch] [ebp-3B0h] BYREF
  _BYTE *v37; // [esp+34h] [ebp-3A8h]
  int v38; // [esp+38h] [ebp-3A4h]
  int v39; // [esp+3Ch] [ebp-3A0h] BYREF
  _BYTE v40[16]; // [esp+40h] [ebp-39Ch] BYREF
  int v41; // [esp+50h] [ebp-38Ch]
  int v42; // [esp+54h] [ebp-388h]
  int v43; // [esp+70h] [ebp-36Ch]
  unsigned int v44[7]; // [esp+74h] [ebp-368h] BYREF
  char v45[64]; // [esp+90h] [ebp-34Ch] BYREF
  char v46[192]; // [esp+D0h] [ebp-30Ch] BYREF
  _BYTE v47[32]; // [esp+190h] [ebp-24Ch] BYREF
  char Buffer[509]; // [esp+1B0h] [ebp-22Ch] BYREF
  __int16 v49; // [esp+3ADh] [ebp-2Fh]
  char v50; // [esp+3AFh] [ebp-2Dh]

  v6 = a1;
  v7 = *(_BYTE *)(a1 + 1456);
  v43 = a1;
  if ( !v7 )
  {
    v42 = a4;
    *(_BYTE *)(a1 + 1456) = 1;
    if ( !a5 )
      goto LABEL_39;
    v44[0] = strlen(a5);
    if ( !v44[0] )
      goto LABEL_39;
    v46[0] = v8;
    sub_630FE0(v46, a5, 255);
    Buffer[31] = 0;
    if ( !a6 && sub_4E1520(v6, 0) == -1 )
      goto LABEL_39;
    v41 = a3;
    v9 = sub_4E0080((void *)v6, (int)"Savingreplay0000.tga", 0, 0, 1, 0, 0, 0, 0);
    if ( !v9 )
    {
      memset(Buffer, 0, sizeof(Buffer));
      v49 = 0;
      v50 = 0;
      v10 = *(const char **)dword_91CAB0;
      v39 = 0;
      if ( !*(_DWORD *)dword_91CAB0 )
        v10 = WindowName;
      sprintf(Buffer, "%s%s", v10, "uiassets.GTR");
      sub_5EE940((int)&v39, (char)Buffer, 0);
      v9 = sub_4E0080((void *)v6, (int)"Savingreplay0000.tga", 0, 0, 1, 0, 0, 0, 0);
      if ( Block )
        sub_5EEA30(dword_FB1CE0, Block, 0);
    }
    *(float *)&v33 = (double)*(int *)dword_903EB8 * 0.00125;
    *(float *)&v35 = (double)dword_903EBC * 0.0016666667;
    if ( v9 )
    {
      v11 = *(int *)(v9 + 24);
      v34 = *(int *)(v9 + 20);
      Blocka = *(float *)&v11;
      v12 = (unsigned __int64)((double)v34 * *(float *)&v33);
      v13 = *(_DWORD *)dword_903EB8 / 2 - v12 / 2;
      v38 = (unsigned __int64)((double)v11 * *(float *)&v35);
      v14 = dword_903EBC / 2 - v38 / 2;
      v36[0] = sub_4DDFE0();
      if ( sub_4E3DF0(v9) && sub_4E3DF0(v9) )
      {
        v15 = COERCE_FLOAT(sub_4E3DF0(v9));
        sub_4DDC20(v15, 0, 0, v34, SLODWORD(Blocka), v36[0], v13, v14, v12, v38, -1, -1, -1, -1);
      }
      v16 = sub_5F04C0(dword_FB1CE0, (int)"FTFU30WH");
      if ( v16 || (v16 = *(_DWORD *)(*(_DWORD *)(v36[1] + 364) + 16)) != 0 )
      {
        sub_5F0380(v45, v36, &v39, 0);
        Blocka = 1.0;
        if ( v36[0] > 530 )
          Blocka = 0.5;
        if ( v36[0] <= 960 )
        {
          *(float *)&v27 = Blocka * *(float *)&v35;
          *(float *)&v26 = Blocka * *(float *)&v33;
          sub_5680F0(v16 + 20, (int)v45, 1057300152, 0.5, NAN, 8, v26, v27, 0);
        }
        else
        {
          sub_630FE0(v47, v45, 255);
          Buffer[223] = 0;
          v17 = strlen(v45) >> 1;
          if ( v17 < strlen(v45) )
          {
            while ( v47[v17] != 32 )
            {
              if ( ++v17 >= strlen(v45) )
                goto LABEL_25;
            }
            v37 = &v47[v17 + 1];
            v47[v17] = 0;
          }
LABEL_25:
          v18 = v16 + 20;
          *(float *)&v38 = Blocka * *(float *)&v35;
          v19 = v38;
          *(float *)&v34 = Blocka * *(float *)&v33;
          sub_5680F0(v18, (int)v47, 1057300152, 0.48500001, NAN, 8, v34, v38, 0);
          sub_5680F0(v18, (int)v37, 1057300152, 0.51499999, NAN, 8, v34, v19, 0);
        }
      }
      sub_4DDA20();
      if ( !Buffer[496] )
        sub_520350(&unk_BE1198, 2, 2, 1036831949, 1);
    }
    else
    {
      v36[0] = *(_DWORD *)(*(_DWORD *)(v6 + 364) + 16);
      if ( !v36[0] )
      {
LABEL_39:
        *(_BYTE *)(v6 + 1456) = 0;
        return;
      }
      *(float *)&v33 = 0.0;
      *(float *)&v35 = 0.0;
      sub_5F0380(v45, &v33, &v35, 1);
      v20 = 400 - v33 / 2;
      v37 = (_BYTE *)(300 - v35 / 2);
      v21 = sub_4DDFE0();
      sub_617DB0(v40, a2);
      *(_DWORD *)&Buffer[488] = 0;
      sub_617DF0(1);
      sub_617E70(v40);
      do
      {
        v22 = sub_617F80(v40);
        *(float *)&v34 = v22;
        v23 = v22 * 2.2222223;
        Blocka = v23;
        if ( v23 >= 0.0 )
        {
          if ( Blocka > 1.0 )
            Blocka = 1.0;
          v24 = sub_499940((int)byte_FFFFFF, 526344, Blocka);
        }
        else
        {
          Blocka = 0.0;
          v24 = sub_499940((int)byte_FFFFFF, 526344, 0.0);
        }
        v25 = (unsigned __int64)((double)v33 * Blocka) + 8;
        sub_4DD980(
          &unk_B6E2A0,
          v21,
          400 - v25 / 2,
          300 - (int)((unsigned __int64)((double)v35 * Blocka) + 8) / 2,
          v25,
          (unsigned __int64)((double)v35 * Blocka) + 8,
          v24);
        sub_4DDA20();
      }
      while ( v28 <= 0.44999999 );
      sub_5F0DD0(v44, v20, v30, v21, 0);
      *(_DWORD *)&Buffer[460] = -1;
      nullsub_7(&v34);
    }
    v6 = LODWORD(Blocka);
    goto LABEL_39;
  }
}
