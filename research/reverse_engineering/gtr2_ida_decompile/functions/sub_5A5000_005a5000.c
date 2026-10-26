char __thiscall sub_5A5000(int *this, _DWORD *a2)
{
  bool v3; // al
  int v4; // edi
  int v5; // edx
  int v6; // edi
  int v7; // eax
  int v8; // eax
  char *v9; // edi
  int v12; // eax
  int v13; // ebp
  int v14; // eax
  int v15; // eax
  double v16; // st7
  __int16 v17; // bp
  int v18; // edi
  int v19; // edi
  int v20; // edx
  int *v21; // ecx
  int v22; // edx
  _DWORD *v23; // eax
  int v24; // edx
  int v25; // eax
  int v26; // edx
  int v27; // ebx
  int v28; // eax
  int v29; // ebp
  int v30; // edx
  double v31; // st7
  int v32; // eax
  int v33; // ecx
  int v34; // edx
  int v35; // edx
  int v36; // edi
  double v37; // st7
  char v38; // [esp+1h] [ebp-5F1h]
  char v39; // [esp+5h] [ebp-5EDh]
  int v40; // [esp+6h] [ebp-5ECh]
  _DWORD v41[5]; // [esp+Eh] [ebp-5E4h] BYREF
  float *v42; // [esp+22h] [ebp-5D0h] BYREF
  int v43; // [esp+26h] [ebp-5CCh] BYREF
  int v44; // [esp+2Ah] [ebp-5C8h]
  int v45; // [esp+2Eh] [ebp-5C4h] BYREF
  int v46; // [esp+32h] [ebp-5C0h] BYREF
  int v47; // [esp+36h] [ebp-5BCh] BYREF
  int v48; // [esp+3Ah] [ebp-5B8h] BYREF
  char v49; // [esp+41h] [ebp-5B1h] BYREF
  float v50[11]; // [esp+42h] [ebp-5B0h] BYREF
  _BYTE v51[36]; // [esp+6Eh] [ebp-584h] BYREF
  int v52; // [esp+92h] [ebp-560h] BYREF
  double v53; // [esp+9Ah] [ebp-558h] BYREF
  unsigned __int8 v54; // [esp+A2h] [ebp-550h]
  int v55[54]; // [esp+A3h] [ebp-54Fh] BYREF
  char Buffer[72]; // [esp+17Eh] [ebp-474h] BYREF
  _BYTE v57[12]; // [esp+1C6h] [ebp-42Ch] BYREF
  _BYTE v58[24]; // [esp+1D2h] [ebp-420h] BYREF
  _BYTE v59[8]; // [esp+1EAh] [ebp-408h] BYREF
  _BYTE v60[1024]; // [esp+1F2h] [ebp-400h] BYREF

  v42 = (float *)a2[14];
  HIBYTE(v50[1]) = 1;
  switch ( sub_5A3D10(a2 + 5, (int)v42) )
  {
    case 1:
      if ( !(*(unsigned __int8 (__thiscall **)(int *))(*this + 64))(this) )
        return v49;
      v3 = (*(int (__thiscall **)(int *))(*this + 164))(this) < this[25];
      if ( !*((_BYTE *)this + 97) )
        return v49;
      if ( !v3 )
        return v49;
      v4 = sub_5A6A10(a2);
      if ( !sub_59BB10((_BYTE *)v4, (int)(this + 12)) )
        return v49;
      v5 = *this;
      v47 = 0;
      v50[2] = 0.0;
      v49 = 0;
      if ( !(*(unsigned __int8 (__thiscall **)(int *, int *, float *))(v5 + 120))(this, &v47, &v50[2]) )
        return v49;
      (*(void (__thiscall **)(int *, int))(*this + 200))(this, v45);
      *(_DWORD *)(v44 + 4) = *(_DWORD *)(v4 + 48);
      v6 = (*(int (__thiscall **)(int *))(*this + 88))(this);
      sub_5A6B10(v6, 0, 2, 0, 1, -1);
      v7 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)v41[2] + 12))(v41[2]);
      v42 = 0;
      v58[0] = 0;
      (*(void (__thiscall **)(_DWORD, _BYTE *, int, float **))(*(_DWORD *)v41[2] + 16))(v41[2], v58, v7, &v42);
      sub_5A6970(v57, v41[2]);
      if ( (*(unsigned __int8 (__thiscall **)(int *, int))*this)(this, v6) )
        HIBYTE(v41[0]) = 1;
      (*(void (__thiscall **)(int *, int))(*this + 124))(this, v40);
      (*(void (__thiscall **)(int *, int))(*this + 92))(this, v6);
      v8 = *this;
      LOBYTE(v41[3]) = 0;
      if ( !(*(unsigned __int8 (__thiscall **)(int *, _DWORD *, int))(v8 + 4))(this, &v41[3], 64) )
        strcpy((char *)&v41[1], "Unknown Node");
      if ( !v38 )
      {
        v9 = (char *)v41 + 3;
        while ( *++v9 )
          ;
        strcpy(v9, "--FAILED");
      }
      (*(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)this[31] + 28))(this[31], &v41[1]);
      return v39;
    case 2:
      v12 = (*(int (__thiscall **)(int *))(*this + 132))(this);
      v42 = &v50[2];
      v13 = v12;
      v14 = *this;
      v41[4] = &v47;
      v47 = 0;
      v50[2] = 0.0;
      (*(void (__thiscall **)(int *))(v14 + 120))(this);
      v15 = sub_5A6A00(a2);
      v59[0] = 0;
      v48 = 0;
      sub_5A6980(v59, v15, &v48);
      v46 = 0;
      (*(void (__thiscall **)(int, _BYTE *, int *))(*(_DWORD *)v45 + 20))(v45, v59, &v46);
      v16 = sub_5A3EA0(this) - *(float *)(v43 + 4);
      v41[1] = 32;
      *(float *)(v43 + 4) = v16 * 0.5;
      qmemcpy(v50, "Unknown Addr", 12);
      LODWORD(v50[3]) = &unk_737365;
      (*(void (__thiscall **)(int *, float *))(*this + 4))(this, v50);
      (*(void (__thiscall **)(int, int, int *, _DWORD))(*(_DWORD *)this[31] + 12))(this[31], v13, &v48, v41[4]);
      (*(void (__thiscall **)(int *, _DWORD))(*this + 52))(this, v41[1]);
      return HIBYTE(v41[4]);
    case 3:
      if ( !sub_5A3C50(this, &v49, (bool *)&v50[3] + 3) )
      {
        v17 = 4 - (v49 != 0);
LABEL_19:
        v18 = (*(int (__thiscall **)(int *))(*this + 88))(this);
        sub_5A6B10(v18, 0, 5, 1, 1, -1);
        LOWORD(v43) = v17;
        sub_5A6970(&v43, 2);
        (*(void (__thiscall **)(int *, int))*this)(this, v18);
        return HIBYTE(v45);
      }
      v48 = strlen((const char *)this + 104);
      if ( v48 )
      {
        v42 = (float *)WindowName;
        v48 = 0;
        sub_59C1B0();
        sub_5A6980(&v50[3], 17, &v47);
        if ( strcmp((const char *)this + 104, (const char *)&v50[3]) )
        {
          v17 = 5;
          goto LABEL_19;
        }
      }
      v19 = (*(int (__thiscall **)(int *, float *))(*this + 88))(this, v42);
      sub_5A6B10(v19, 0, 4, 1, 1, -1);
      (*(void (__thiscall **)(int *, _DWORD *, int, _DWORD))(*this + 144))(this, &v41[4], 1, 0);
      sub_5A4A00((char *)this, v41[1], 1);
      (*(void (__thiscall **)(int *, _DWORD))(*this + 140))(this, v41[1]);
      LOWORD(v41[1]) = v41[0];
      sub_5A6970(&v41[1], 2);
      (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(v19 + 72) + 12))(*(_DWORD *)(v19 + 72), v41[0]);
      sub_5A47C0(this, v19);
      return HIBYTE(v41[3]);
    case 4:
      LOWORD(v47) = 0;
      if ( !sub_5A6980(&v47, 2, 0) )
      {
        sub_5A4180(this, (unsigned __int16)v47);
        (*(void (__thiscall **)(int *, _DWORD))(*this + 152))(this, (unsigned __int16)v46);
      }
      strcpy((char *)&v50[2], "Added Node");
      v41[3] = 64;
      v20 = *this;
      v41[2] = &v50[2];
      if ( !(*(unsigned __int8 (__thiscall **)(int *))(v20 + 4))(this) )
        strcpy((char *)v50, "Unknown Node");
      v21 = (int *)this[31];
      v22 = *v21;
      v41[1] = v50;
      v41[0] = 1;
      (*(void (__thiscall **)(int *))(v22 + 16))(v21);
      sub_5A42E0(this, 3, 1, (int)v50, v41[2]);
      return HIBYTE(v44);
    case 5:
      sub_5A42E0(this, 0, v43, v44, v45);
      v47 = 0;
      LOWORD(v46) = sub_5A6980(&v46, 2, &v47) != 0;
      v41[4] = 5;
      v23 = (_DWORD *)sub_5A3D80();
      if ( v23 )
        *v23 = (unsigned __int16)v45;
      sub_59C330();
      v24 = *this;
      strcpy((char *)&v50[2], "HST");
      if ( !(*(unsigned __int8 (__thiscall **)(int *, float *, int, _DWORD))(v24 + 4))(this, &v50[2], 64, v41[4]) )
        strcpy((char *)v50, "Unknown Node");
      (*(void (__thiscall **)(int, _DWORD, float *))(*(_DWORD *)this[31] + 16))(this[31], 0, v50);
      return HIBYTE(v45);
    case 6:
      return v49;
    case 7:
      if ( !(*(unsigned __int8 (__thiscall **)(int *, int *))(*this + 8))(this, &v48) )
        return v49;
      (*(void (__thiscall **)(int *, int))(*this + 148))(this, v47);
      return v49;
    case 8:
      v60[0] = 0;
      while ( 1 )
      {
        v48 = 0;
        v25 = sub_5A6980(v60, 768, &v48);
        if ( !v25 )
          break;
        if ( v25 != 4 )
          return HIBYTE(v50[1]);
      }
      LOBYTE(v50[0]) = 0;
      LOBYTE(v47) = 0;
      if ( sub_5A4330(this) == 4 )
        LOBYTE(v47) = 1;
      else
        LOBYTE(v50[0]) = 1;
      (*(void (__thiscall **)(int *, _BYTE *, int, _DWORD))(*this + 180))(this, v60, v47, LODWORD(v50[0]));
      return HIBYTE(v48);
    case 9:
      v48 = 0;
      if ( sub_5A6980(&v50[2], 4, &v48) )
        return v49;
      (*(void (__thiscall **)(int *, _DWORD))(*this + 148))(this, LODWORD(v50[2]));
      return HIBYTE(v50[0]);
    case 10:
      v26 = *this;
      v42 = (float *)&v48;
      v41[4] = &v47;
      v47 = 0;
      v48 = 0;
      if ( !(*(unsigned __int8 (__thiscall **)(int *))(v26 + 120))(this) )
        return v49;
      v50[0] = 0.0;
      v27 = *(_DWORD *)v45;
      v41[3] = v50;
      v28 = sub_5A6A10(a2);
      (*(void (__thiscall **)(int, int))(v27 + 20))(v45, v28);
      (*(void (__thiscall **)(int *, int))(*this + 196))(this, v43);
      (*(void (__thiscall **)(int, float *))(*(_DWORD *)this[31] + 40))(this[31], v42);
      (*(void (__thiscall **)(int *, _DWORD))(*this + 124))(this, v41[4]);
      return HIBYTE(v44);
    case 11:
      v29 = (*(int (__thiscall **)(int *))(*this + 88))(this);
      sub_5A6B10(v29, 0, 12, 0, 2, -1);
      v45 = -1082130432;
      sub_5A6980(&v45, 4, 0);
      sub_5A6970(&v45, 4);
      (*(void (__thiscall **)(int *, int))*this)(this, v29);
      (*(void (__thiscall **)(int *, int))(*this + 92))(this, v29);
      v30 = *this;
      Buffer[8] = 0;
      LOBYTE(v47) = 0;
      (*(void (__thiscall **)(int *, int *, int))(v30 + 4))(this, &v47, 64);
      sprintf(Buffer, "Ping Request from %s", (const char *)&v45);
      (*(void (__thiscall **)(int, char *, _DWORD))(*(_DWORD *)this[31] + 24))(this[31], Buffer, 0);
      return HIBYTE(v41[3]);
    case 12:
      v50[0] = -1.0;
      sub_5A6980(v50, 4, 0);
      v31 = sub_5A3EA0(this);
      (*(void (__thiscall **)(int *, int))(*this + 20))(this, (int)(unsigned __int64)((v31 - v50[0]) * 1000.0) / 2);
      return HIBYTE(v50[0]);
    case 13:
      v42 = (float *)a2[1];
      v41[4] = sub_5A6A00(a2);
      v32 = sub_5A6A10(a2);
      sub_5A7330(v32, v41[4], v42);
      return HIBYTE(v50[1]);
    case 14:
      sub_5A6980(&v48, 4, 0);
      v53 = -9.999999680285692e37;
      v33 = this[31];
      v52 = v48;
      v42 = &v50[2];
      v41[4] = v55;
      v41[3] = &v53;
      v34 = a2[1];
      v54 = -1;
      if ( !(*(unsigned __int8 (__thiscall **)(int, int, double *, int *, float *))(*(_DWORD *)v33 + 8))(
              v33,
              v34,
              &v53,
              v55,
              &v50[2]) )
        return v49;
      v35 = *this;
      LOBYTE(v52) = v48;
      v36 = (*(int (__thiscall **)(int *))(v35 + 88))(this);
      sub_5A6B10(v36, 0, 15, 0, 3, -1);
      sub_5A6970(v51, v51[16] + 17);
      (*(void (__thiscall **)(int *, int))*this)(this, v36);
      (*(void (__thiscall **)(int *, int))(*this + 92))(this, v36);
      return HIBYTE(v41[3]);
    case 15:
      v53 = -9.999999680285692e37;
      v52 = -1;
      v54 = 0;
      sub_5A6980(&v52, 272, 0);
      v37 = sub_5A3EA0(this);
      sub_5A3B50((double *)this + 204, v52, v37, v53, v55, v54);
      return HIBYTE(v50[1]);
    default:
      HIBYTE(v50[1]) = 0;
      return v49;
  }
}
