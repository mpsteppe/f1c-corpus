char __thiscall sub_584230(int *this, _DWORD *a2)
{
  unsigned __int16 *v3; // ecx
  int v4; // eax
  int v5; // edi
  int v6; // edx
  int v7; // edi
  int v8; // eax
  int v9; // edx
  int v10; // eax
  char *v11; // edi
  int v12; // eax
  char v13; // cl
  int v14; // eax
  int v15; // edi
  int v16; // eax
  int v17; // eax
  float *v18; // ebp
  int v19; // eax
  __int16 v20; // bp
  int v21; // edi
  int v22; // edi
  int v23; // eax
  DWORD v24; // eax
  int v25; // eax
  int v26; // eax
  int v27; // edx
  int v28; // edi
  int v29; // eax
  int v30; // eax
  int v31; // edi
  int v32; // edx
  int v33; // eax
  double v34; // st7
  int v35; // edi
  int v36; // eax
  int v37; // eax
  int v38; // eax
  int v39; // eax
  int v40; // edi
  int v42; // [esp+12h] [ebp-6F0h]
  int v43; // [esp+16h] [ebp-6ECh]
  char v44; // [esp+2Dh] [ebp-6D5h] BYREF
  _DWORD *v45; // [esp+2Eh] [ebp-6D4h] BYREF
  int v46; // [esp+32h] [ebp-6D0h] BYREF
  double v47; // [esp+36h] [ebp-6CCh] BYREF
  const char *v48; // [esp+3Eh] [ebp-6C4h] BYREF
  char v49; // [esp+45h] [ebp-6BDh]
  int v50; // [esp+46h] [ebp-6BCh] BYREF
  char v51; // [esp+4Dh] [ebp-6B5h] BYREF
  char v52[64]; // [esp+4Eh] [ebp-6B4h] BYREF
  int v53; // [esp+8Eh] [ebp-674h] BYREF
  double v54; // [esp+92h] [ebp-670h]
  unsigned __int8 v55; // [esp+9Ah] [ebp-668h]
  int v56; // [esp+9Bh] [ebp-667h] BYREF
  _BYTE v57[80]; // [esp+19Ah] [ebp-568h] BYREF
  int v58; // [esp+1EAh] [ebp-518h] BYREF
  _DWORD v59[2]; // [esp+1EEh] [ebp-514h] BYREF
  unsigned __int8 v60; // [esp+1F6h] [ebp-50Ch]
  _BYTE v61[255]; // [esp+1F7h] [ebp-50Bh] BYREF
  _BYTE v62[1024]; // [esp+2F6h] [ebp-40Ch] BYREF
  int v63; // [esp+6FEh] [ebp-4h]

  v3 = (unsigned __int16 *)(a2[7] + 4 * a2[14]);
  v49 = 1;
  v46 = 0;
  v45 = 0;
  v4 = *v3;
  LODWORD(v47) = v3[1];
  v50 = LODWORD(v47) + v4 - 1;
  if ( LODWORD(v47) )
  {
    do
    {
      sub_585E80(v50 - (_DWORD)v45, &v48, &v44);
      if ( ((unsigned __int8)v44 & v48[a2[5]]) != 0 )
        v46 |= 1 << (char)v45;
      v45 = (_DWORD *)((char *)v45 + 1);
    }
    while ( (unsigned int)v45 < LODWORD(v47) );
  }
  switch ( v46 )
  {
    case 1:
      if ( (*(unsigned __int8 (__thiscall **)(int *))(*this + 64))(this) )
      {
        if ( (unsigned __int8)sub_585220(0, 0) )
        {
          v5 = sub_586A90(a2);
          if ( sub_57A0C0((_BYTE *)v5, (int)(this + 11)) )
          {
            v6 = *this;
            v45 = 0;
            LODWORD(v47) = 0;
            v44 = 0;
            if ( (*(unsigned __int8 (__thiscall **)(int *, _DWORD **, double *))(v6 + 120))(this, &v45, &v47) )
            {
              (*(void (__thiscall **)(int *, _DWORD *))(*this + 196))(this, v45);
              v45[1] = *(_DWORD *)(v5 + 48);
              v7 = (*(int (__thiscall **)(int *))(*this + 88))(this);
              sub_586800(0, 2, 0, 1, -1);
              v8 = (*(int (__thiscall **)(_DWORD *))(*v45 + 12))(v45);
              v46 = 0;
              v62[0] = 0;
              v9 = *v45;
              v63 = 0;
              (*(void (__thiscall **)(_DWORD *, _BYTE *, int, int *))(v9 + 16))(v45, v62, v8, &v46);
              sub_586A00(v62, v46);
              if ( (*(unsigned __int8 (__thiscall **)(int *, int))*this)(this, v7) )
                v44 = 1;
              (*(void (__thiscall **)(int *, _DWORD *))(*this + 124))(this, v45);
              (*(void (__thiscall **)(int *, int))(*this + 92))(this, v7);
              v52[0] = 0;
              v10 = *this;
              LOBYTE(v63) = 1;
              if ( !(*(unsigned __int8 (__thiscall **)(int *, char *, int))(v10 + 4))(this, v52, 64) )
                strcpy(v52, aUnknownNode);
              if ( !v44 )
              {
                v11 = &v52[strlen(v52) + 1];
                v12 = dword_5E6384;
                v13 = byte_5E6388;
                *(_DWORD *)--v11 = dword_5E6380;
                *((_DWORD *)v11 + 1) = v12;
                v11[8] = v13;
              }
              v14 = sub_585CC0(this);
              (*(void (__thiscall **)(int, char *))(*(_DWORD *)v14 + 28))(v14, v52);
              nullsub_3();
            }
          }
        }
      }
      return v49;
    case 2:
      v15 = (*(int (__thiscall **)(int *))(*this + 132))(this);
      v16 = *this;
      v45 = 0;
      LODWORD(v47) = 0;
      (*(void (__thiscall **)(int *, _DWORD **, double *))(v16 + 120))(this, &v45, &v47);
      v17 = sub_586A80(a2);
      v62[0] = 0;
      v63 = 2;
      v48 = 0;
      sub_586A10(v62, v17, &v48);
      v50 = 0;
      (*(void (__thiscall **)(_DWORD *, _BYTE *, int *))(*v45 + 20))(v45, v62, &v50);
      v18 = (float *)(v45 + 1);
      *v18 = (sub_584F90(this) - *v18) * 0.5;
      LOBYTE(v63) = 3;
      strcpy(v52, aUnknownAddress);
      (*(void (__thiscall **)(int *, char *, int))(*this + 4))(this, v52, 32);
      v19 = sub_585CC0(this);
      (*(void (__thiscall **)(int, int, char *, int))(*(_DWORD *)v19 + 12))(v19, v15, &v52[4], v46);
      nullsub_3();
      (*(void (__thiscall **)(int *, int))(*this + 52))(this, v46);
      return v49;
    case 3:
      if ( !(unsigned __int8)sub_585220(&v44, &v51) )
      {
        v20 = 4 - (v44 != 0);
LABEL_20:
        v21 = (*(int (__thiscall **)(int *))(*this + 88))(this);
        sub_586800(0, 5, 1, 1, -1);
        LOWORD(v47) = v20;
        sub_586A00(&v47, 2);
        (*(void (__thiscall **)(int *, int))*this)(this, v21);
        return v49;
      }
      v48 = (const char *)sub_585020(this);
      if ( strlen(v48) )
      {
        LODWORD(v47) = 0;
        sub_587DD0(v52, byte_5EA438, 16);
        v52[16] = 0;
        sub_586A10(v52, 17, &v47);
        if ( strcmp(v48, v52) )
        {
          v20 = 5;
          goto LABEL_20;
        }
      }
      v22 = (*(int (__thiscall **)(int *))(*this + 88))(this);
      sub_586800(0, 4, 1, 1, -1);
      (*(void (__thiscall **)(int *, _DWORD **, int, _DWORD))(*this + 144))(this, &v45, 1, 0);
      sub_585870(v45, 1);
      (*(void (__thiscall **)(int *, _DWORD *))(*this + 140))(this, v45);
      LOWORD(v47) = (_WORD)v45;
      sub_586A00(&v47, 2);
      (*(void (__thiscall **)(_DWORD, _DWORD *))(**(_DWORD **)(v22 + 72) + 12))(*(_DWORD *)(v22 + 72), v45);
      sub_585380(v22);
      return v49;
    case 4:
      LOWORD(v46) = 0;
      if ( !sub_586A10(&v46, 2, 0) )
      {
        sub_5857C0((unsigned __int16)v46);
        (*(void (__thiscall **)(int *, _DWORD))(*this + 152))(this, (unsigned __int16)v46);
      }
      v63 = 4;
      strcpy(v52, aAddedNode);
      if ( !(*(unsigned __int8 (__thiscall **)(int *, char *, int))(*this + 4))(this, v52, 64) )
        strcpy(v52, aUnknownNode);
      v23 = sub_585CC0(this);
      (*(void (__thiscall **)(int, int, char *))(*(_DWORD *)v23 + 16))(v23, 1, v52);
      nullsub_3();
      sub_585CD0(3);
      return v49;
    case 5:
      sub_585CD0(0);
      LODWORD(v47) = 0;
      LOWORD(v46) = sub_586A10(&v46, 2, &v47) != 0;
      v24 = WaitForSingleObject((HANDLE)this[390], 5u);
      if ( v24 != 258 && v24 != -1 )
        this[369] = (unsigned __int16)v46;
      if ( this[390] )
        ReleaseMutex((HANDLE)this[390]);
      v63 = 5;
      strcpy(v52, aHst);
      if ( !(*(unsigned __int8 (__thiscall **)(int *, char *, int))(*this + 4))(this, v52, 64) )
        strcpy(v52, aUnknownNode);
      v25 = sub_585CC0(this);
      (*(void (__thiscall **)(int, _DWORD, char *))(*(_DWORD *)v25 + 16))(v25, 0, v52);
      nullsub_3();
      return v49;
    case 6:
      return v49;
    case 7:
      if ( (*(unsigned __int8 (__thiscall **)(int *, double *))(*this + 8))(this, &v47) )
        (*(void (__thiscall **)(int *, _DWORD))(*this + 148))(this, LODWORD(v47));
      return v49;
    case 8:
      v62[0] = 0;
      v63 = 6;
      while ( 1 )
      {
        LODWORD(v47) = 0;
        v26 = sub_586A10(v62, 768, &v47);
        if ( !v26 )
          break;
        if ( v26 != 4 )
          return v49;
      }
      LOBYTE(v46) = 0;
      LOBYTE(v45) = 0;
      if ( sub_585D20(this) == 4 )
        LOBYTE(v45) = 1;
      else
        LOBYTE(v46) = 1;
      (*(void (__thiscall **)(int *, _BYTE *, _DWORD *, int))(*this + 176))(this, v62, v45, v46);
      return v49;
    case 9:
      LODWORD(v47) = 0;
      if ( !sub_586A10(&v48, 4, &v47) )
        (*(void (__thiscall **)(int *, const char *))(*this + 148))(this, v48);
      return v49;
    case 10:
      v27 = *this;
      v45 = 0;
      LODWORD(v47) = 0;
      if ( (*(unsigned __int8 (__thiscall **)(int *, _DWORD **, double *))(v27 + 120))(this, &v45, &v47) )
      {
        v48 = 0;
        v28 = *v45;
        v29 = sub_586A90(a2);
        (*(void (__thiscall **)(_DWORD *, int, const char **))(v28 + 20))(v45, v29, &v48);
        (*(void (__thiscall **)(int *, _DWORD *))(*this + 192))(this, v45);
        v30 = sub_585CC0(this);
        (*(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)v30 + 40))(v30, v45);
        nullsub_3();
        (*(void (__thiscall **)(int *, _DWORD *))(*this + 124))(this, v45);
      }
      return v49;
    case 11:
      v31 = (*(int (__thiscall **)(int *))(*this + 88))(this);
      sub_586800(0, 12, 0, 2, -1);
      v46 = -1082130432;
      sub_586A10(&v46, 4, 0);
      sub_586A00(&v46, 4);
      (*(void (__thiscall **)(int *, int))*this)(this, v31);
      (*(void (__thiscall **)(int *, int))(*this + 92))(this, v31);
      v57[0] = 0;
      v63 = 7;
      v52[0] = 0;
      v32 = *this;
      LOBYTE(v63) = 8;
      (*(void (__thiscall **)(int *, char *, int))(v32 + 4))(this, v52, 64);
      sub_58815F(v57, "Ping Request from %s", v52);
      v33 = sub_585CC0(this);
      (*(void (__thiscall **)(int, _BYTE *, _DWORD))(*(_DWORD *)v33 + 24))(v33, v57, 0);
      nullsub_3();
      return v49;
    case 12:
      v46 = -1082130432;
      sub_586A10(&v46, 4, 0);
      v34 = sub_584F90(this);
      v35 = *this;
      v36 = sub_587BDC(v34);
      (*(void (__thiscall **)(int *, int))(v35 + 20))(this, v36 / 2);
      return v49;
    case 13:
      v43 = a2[1];
      v42 = sub_586A80(a2);
      v37 = sub_586A90(a2);
      sub_587930(v37, v42, v43);
      return v49;
    case 14:
      sub_586A10(&v47, 4, 0);
      v59[0] = 0x20000000;
      v59[1] = -942485805;
      v58 = LODWORD(v47);
      v60 = -1;
      v38 = sub_585CC0(this);
      v44 = (*(int (__thiscall **)(int, _DWORD, _DWORD *, _BYTE *, const char **))(*(_DWORD *)v38 + 8))(
              v38,
              a2[1],
              v59,
              v61,
              &v48);
      nullsub_3();
      if ( v44 )
      {
        v39 = *this;
        v60 = (unsigned __int8)v48;
        v40 = (*(int (__thiscall **)(int *))(v39 + 88))(this);
        sub_586800(0, 15, 0, 3, -1);
        sub_586A00(&v58, v60 + 13);
        (*(void (__thiscall **)(int *, int))*this)(this, v40);
        (*(void (__thiscall **)(int *, int))(*this + 92))(this, v40);
      }
      return v49;
    case 15:
      v53 = -1;
      v54 = -9.999999680285692e37;
      v55 = 0;
      sub_586A10(&v53, 268, 0);
      v47 = sub_584F90(this);
      sub_583700((char *)this + 1616, v53, v47, v54, &v56, v55);
      return v49;
    default:
      return 0;
  }
}
