char __thiscall sub_5742A0(int *this, _DWORD *a2)
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
  int v35; // eax
  int v36; // eax
  int v37; // eax
  int v38; // edi
  int v40; // [esp+12h] [ebp-6F0h]
  int v41; // [esp+16h] [ebp-6ECh]
  char v42; // [esp+2Dh] [ebp-6D5h] BYREF
  _DWORD *v43; // [esp+2Eh] [ebp-6D4h] BYREF
  float v44; // [esp+32h] [ebp-6D0h] BYREF
  double v45; // [esp+36h] [ebp-6CCh] BYREF
  const char *v46; // [esp+3Eh] [ebp-6C4h] BYREF
  char v47; // [esp+45h] [ebp-6BDh]
  int v48; // [esp+46h] [ebp-6BCh] BYREF
  char v49; // [esp+4Dh] [ebp-6B5h] BYREF
  char Destination[64]; // [esp+4Eh] [ebp-6B4h] BYREF
  int v51; // [esp+8Eh] [ebp-674h] BYREF
  double v52; // [esp+92h] [ebp-670h]
  unsigned __int8 v53; // [esp+9Ah] [ebp-668h]
  int v54; // [esp+9Bh] [ebp-667h] BYREF
  char Buffer[80]; // [esp+19Ah] [ebp-568h] BYREF
  int v56; // [esp+1EAh] [ebp-518h] BYREF
  _DWORD v57[2]; // [esp+1EEh] [ebp-514h] BYREF
  unsigned __int8 v58; // [esp+1F6h] [ebp-50Ch]
  _BYTE v59[255]; // [esp+1F7h] [ebp-50Bh] BYREF
  _BYTE v60[1024]; // [esp+2F6h] [ebp-40Ch] BYREF
  int v61; // [esp+6FEh] [ebp-4h]

  v3 = (unsigned __int16 *)(a2[7] + 4 * a2[14]);
  v47 = 1;
  v44 = 0.0;
  v43 = 0;
  v4 = *v3;
  LODWORD(v45) = v3[1];
  v48 = LODWORD(v45) + v4 - 1;
  if ( LODWORD(v45) )
  {
    do
    {
      sub_575EF0(v48 - (_DWORD)v43, &v46, &v42);
      if ( ((unsigned __int8)v42 & v46[a2[5]]) != 0 )
        LODWORD(v44) |= 1 << (char)v43;
      v43 = (_DWORD *)((char *)v43 + 1);
    }
    while ( (unsigned int)v43 < LODWORD(v45) );
  }
  switch ( LODWORD(v44) )
  {
    case 1:
      if ( (*(unsigned __int8 (__thiscall **)(int *))(*this + 64))(this) )
      {
        if ( (unsigned __int8)sub_575290(0, 0) )
        {
          v5 = sub_576B20(a2);
          if ( sub_569DF0((_BYTE *)v5, (int)(this + 11)) )
          {
            v6 = *this;
            v43 = 0;
            LODWORD(v45) = 0;
            v42 = 0;
            if ( (*(unsigned __int8 (__thiscall **)(int *, _DWORD **, double *))(v6 + 120))(this, &v43, &v45) )
            {
              (*(void (__thiscall **)(int *, _DWORD *))(*this + 196))(this, v43);
              v43[1] = *(_DWORD *)(v5 + 48);
              v7 = (*(int (__thiscall **)(int *))(*this + 88))(this);
              sub_576880(0, 2, 0, 1, -1);
              v8 = (*(int (__thiscall **)(_DWORD *))(*v43 + 12))(v43);
              v44 = 0.0;
              v60[0] = 0;
              v9 = *v43;
              v61 = 0;
              (*(void (__thiscall **)(_DWORD *, _BYTE *, int, float *))(v9 + 16))(v43, v60, v8, &v44);
              sub_576A80(v60, LODWORD(v44));
              if ( (*(unsigned __int8 (__thiscall **)(int *, int))*this)(this, v7) )
                v42 = 1;
              (*(void (__thiscall **)(int *, _DWORD *))(*this + 124))(this, v43);
              (*(void (__thiscall **)(int *, int))(*this + 92))(this, v7);
              Destination[0] = 0;
              v10 = *this;
              LOBYTE(v61) = 1;
              if ( !(*(unsigned __int8 (__thiscall **)(int *, char *, int))(v10 + 4))(this, Destination, 64) )
                strcpy(Destination, aUnknownNode);
              if ( !v42 )
              {
                v11 = &Destination[strlen(Destination) + 1];
                v12 = dword_61B24C;
                v13 = byte_61B250;
                *(_DWORD *)--v11 = dword_61B248;
                *((_DWORD *)v11 + 1) = v12;
                v11[8] = v13;
              }
              v14 = sub_575D30(this);
              (*(void (__thiscall **)(int, char *))(*(_DWORD *)v14 + 28))(v14, Destination);
              nullsub_6(this);
            }
          }
        }
      }
      return v47;
    case 2:
      v15 = (*(int (__thiscall **)(int *))(*this + 132))(this);
      v16 = *this;
      v43 = 0;
      LODWORD(v45) = 0;
      (*(void (__thiscall **)(int *, _DWORD **, double *))(v16 + 120))(this, &v43, &v45);
      v17 = sub_576B10(a2);
      v60[0] = 0;
      v61 = 2;
      v46 = 0;
      sub_576A90(v60, v17, &v46);
      v48 = 0;
      (*(void (__thiscall **)(_DWORD *, _BYTE *, int *))(*v43 + 20))(v43, v60, &v48);
      v18 = (float *)(v43 + 1);
      *v18 = (sub_575000(this) - *v18) * 0.5;
      LOBYTE(v61) = 3;
      strcpy(Destination, aUnknownAddress);
      (*(void (__thiscall **)(int *, char *, int))(*this + 4))(this, Destination, 32);
      v19 = sub_575D30(this);
      (*(void (__thiscall **)(int, int, char *, _DWORD *))(*(_DWORD *)v19 + 12))(v19, v15, Destination, v43);
      nullsub_6(this);
      (*(void (__thiscall **)(int *, _DWORD *))(*this + 52))(this, v43);
      return v47;
    case 3:
      if ( !(unsigned __int8)sub_575290(&v42, &v49) )
      {
        v20 = 4 - (v42 != 0);
LABEL_20:
        v21 = (*(int (__thiscall **)(int *))(*this + 88))(this);
        sub_576880(0, 5, 1, 1, -1);
        LOWORD(v45) = v20;
        sub_576A80(&v45, 2);
        (*(void (__thiscall **)(int *, int))*this)(this, v21);
        return v47;
      }
      v46 = (const char *)sub_575090(this);
      if ( strlen(v46) )
      {
        LODWORD(v45) = 0;
        strncpy(Destination, &byte_629120, 0x10u);
        Destination[16] = 0;
        sub_576A90(Destination, 17, &v45);
        if ( strcmp(v46, Destination) )
        {
          v20 = 5;
          goto LABEL_20;
        }
      }
      v22 = (*(int (__thiscall **)(int *))(*this + 88))(this);
      sub_576880(0, 4, 1, 1, -1);
      (*(void (__thiscall **)(int *, _DWORD **, int, _DWORD))(*this + 144))(this, &v43, 1, 0);
      sub_5758E0(v43, 1);
      (*(void (__thiscall **)(int *, _DWORD *))(*this + 140))(this, v43);
      LOWORD(v45) = (_WORD)v43;
      sub_576A80(&v45, 2);
      (*(void (__thiscall **)(_DWORD, _DWORD *))(**(_DWORD **)(v22 + 72) + 12))(*(_DWORD *)(v22 + 72), v43);
      sub_5753F0(v22);
      return v47;
    case 4:
      LOWORD(v44) = 0;
      if ( !sub_576A90(&v44, 2, 0) )
      {
        sub_575830(LOWORD(v44));
        (*(void (__thiscall **)(int *, _DWORD))(*this + 152))(this, LOWORD(v44));
      }
      v61 = 4;
      strcpy(Destination, aAddedNode);
      if ( !(*(unsigned __int8 (__thiscall **)(int *, char *, int))(*this + 4))(this, Destination, 64) )
        strcpy(Destination, aUnknownNode);
      v23 = sub_575D30(this);
      (*(void (__thiscall **)(int, int, char *))(*(_DWORD *)v23 + 16))(v23, 1, Destination);
      nullsub_6(this);
      sub_575D40(3);
      return v47;
    case 5:
      sub_575D40(0);
      LODWORD(v45) = 0;
      LOWORD(v44) = sub_576A90(&v44, 2, &v45) != 0;
      v24 = WaitForSingleObject((HANDLE)this[390], 5u);
      if ( v24 != 258 && v24 != -1 )
        this[369] = LOWORD(v44);
      if ( this[390] )
        ReleaseMutex((HANDLE)this[390]);
      v61 = 5;
      strcpy(Destination, (const char *)&off_61B228);
      if ( !(*(unsigned __int8 (__thiscall **)(int *, char *, int))(*this + 4))(this, Destination, 64) )
        strcpy(Destination, aUnknownNode);
      v25 = sub_575D30(this);
      (*(void (__thiscall **)(int, _DWORD, char *))(*(_DWORD *)v25 + 16))(v25, 0, Destination);
      nullsub_6(this);
      return v47;
    case 6:
      return v47;
    case 7:
      if ( (*(unsigned __int8 (__thiscall **)(int *, double *))(*this + 8))(this, &v45) )
        (*(void (__thiscall **)(int *, _DWORD))(*this + 148))(this, LODWORD(v45));
      return v47;
    case 8:
      v60[0] = 0;
      v61 = 6;
      while ( 1 )
      {
        LODWORD(v45) = 0;
        v26 = sub_576A90(v60, 768, &v45);
        if ( !v26 )
          break;
        if ( v26 != 4 )
          return v47;
      }
      LOBYTE(v44) = 0;
      LOBYTE(v43) = 0;
      if ( sub_575D90(this) == 4 )
        LOBYTE(v43) = 1;
      else
        LOBYTE(v44) = 1;
      (*(void (__thiscall **)(int *, _BYTE *, _DWORD *, float))(*this + 176))(
        this,
        v60,
        v43,
        COERCE_FLOAT(LODWORD(v44)));
      return v47;
    case 9:
      LODWORD(v45) = 0;
      if ( !sub_576A90(&v46, 4, &v45) )
        (*(void (__thiscall **)(int *, const char *))(*this + 148))(this, v46);
      return v47;
    case 0xA:
      v27 = *this;
      v43 = 0;
      LODWORD(v45) = 0;
      if ( (*(unsigned __int8 (__thiscall **)(int *, _DWORD **, double *))(v27 + 120))(this, &v43, &v45) )
      {
        v46 = 0;
        v28 = *v43;
        v29 = sub_576B20(a2);
        (*(void (__thiscall **)(_DWORD *, int, const char **))(v28 + 20))(v43, v29, &v46);
        (*(void (__thiscall **)(int *, _DWORD *))(*this + 192))(this, v43);
        v30 = sub_575D30(this);
        (*(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)v30 + 40))(v30, v43);
        nullsub_6(this);
        (*(void (__thiscall **)(int *, _DWORD *))(*this + 124))(this, v43);
      }
      return v47;
    case 0xB:
      v31 = (*(int (__thiscall **)(int *))(*this + 88))(this);
      sub_576880(0, 12, 0, 2, -1);
      v44 = -1.0;
      sub_576A90(&v44, 4, 0);
      sub_576A80(&v44, 4);
      (*(void (__thiscall **)(int *, int))*this)(this, v31);
      (*(void (__thiscall **)(int *, int))(*this + 92))(this, v31);
      Buffer[0] = 0;
      v61 = 7;
      Destination[0] = 0;
      v32 = *this;
      LOBYTE(v61) = 8;
      (*(void (__thiscall **)(int *, char *, int))(v32 + 4))(this, Destination, 64);
      sprintf(Buffer, "Ping Request from %s", Destination);
      v33 = sub_575D30(this);
      (*(void (__thiscall **)(int, char *, _DWORD))(*(_DWORD *)v33 + 24))(v33, Buffer, 0);
      nullsub_6(this);
      return v47;
    case 0xC:
      v44 = -1.0;
      sub_576A90(&v44, 4, 0);
      v34 = sub_575000(this);
      (*(void (__thiscall **)(int *, int))(*this + 20))(this, (int)(__int64)((v34 - v44) * 1000.0) / 2);
      return v47;
    case 0xD:
      v41 = a2[1];
      v40 = sub_576B10(a2);
      v35 = sub_576B20(a2);
      sub_5779D0(v35, v40, v41);
      return v47;
    case 0xE:
      sub_576A90(&v45, 4, 0);
      v57[0] = 0x20000000;
      v57[1] = -942485805;
      v56 = LODWORD(v45);
      v58 = -1;
      v36 = sub_575D30(this);
      v42 = (*(int (__thiscall **)(int, _DWORD, _DWORD *, _BYTE *, const char **))(*(_DWORD *)v36 + 8))(
              v36,
              a2[1],
              v57,
              v59,
              &v46);
      nullsub_6(this);
      if ( v42 )
      {
        v37 = *this;
        v58 = (unsigned __int8)v46;
        v38 = (*(int (__thiscall **)(int *))(v37 + 88))(this);
        sub_576880(0, 15, 0, 3, -1);
        sub_576A80(&v56, v58 + 13);
        (*(void (__thiscall **)(int *, int))*this)(this, v38);
        (*(void (__thiscall **)(int *, int))(*this + 92))(this, v38);
      }
      return v47;
    case 0xF:
      v51 = -1;
      v52 = -9.999999680285692e37;
      v53 = 0;
      sub_576A90(&v51, 268, 0);
      v45 = sub_575000(this);
      sub_573770((char *)this + 1616, v51, v45, v52, &v54, v53);
      return v47;
    default:
      return 0;
  }
}
