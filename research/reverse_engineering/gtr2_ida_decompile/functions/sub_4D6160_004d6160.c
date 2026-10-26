int __thiscall sub_4D6160(int *this, int a2, int a3, int a4, int a5)
{
  int *v6; // edi
  int v7; // ebp
  int v8; // eax
  int v9; // ebx
  int v10; // eax
  int v11; // edx
  int v12; // ebx
  int v13; // ebx
  int v14; // eax
  int v15; // ebx
  int v16; // eax
  int v17; // edx
  int v18; // eax
  double v19; // st7
  int v20; // edx
  int v21; // ebx
  int v22; // ebx
  int v23; // eax
  int v24; // eax
  _DWORD *v25; // edx
  _DWORD *v26; // ecx
  int v27; // eax
  float v28; // edx
  int *v29; // edi
  int v30; // eax
  int v31; // ebp
  int v32; // ebx
  int v33; // eax
  int v34; // edx
  int v35; // eax
  int v36; // edx
  int v37; // ebx
  int v38; // eax
  int v39; // ecx
  int v40; // eax
  int v41; // eax
  unsigned int v42; // edx
  signed int v43; // eax
  signed int v44; // ebx
  int v45; // eax
  int v46; // ebp
  int v47; // eax
  const char *v48; // eax
  int v49; // eax
  const CHAR **v50; // eax
  const CHAR *v51; // eax
  const CHAR *v52; // eax
  int v53; // ebp
  int v54; // edi
  int v55; // ebx
  int v56; // eax
  int v57; // ebx
  int v58; // eax
  const CHAR *v59; // ecx
  int v60; // eax
  int v61; // edi
  int v62; // eax
  int *v63; // ebx
  int v64; // eax
  int v65; // ebp
  int *v66; // ecx
  int v67; // eax
  const char *v68; // eax
  _DWORD *v69; // ecx
  const CHAR *v70; // eax
  const CHAR *v71; // eax
  char v72; // al
  int v73; // edi
  int v74; // ebp
  const CHAR *v75; // eax
  const CHAR *v76; // eax
  int v77; // eax
  char *v78; // eax
  int v79; // eax
  char *v80; // eax
  int *v82; // [esp+0h] [ebp-C0h]
  char *v83; // [esp+4h] [ebp-BCh]
  int *v84; // [esp+10h] [ebp-B0h]
  int *v85; // [esp+14h] [ebp-ACh]
  int v86; // [esp+18h] [ebp-A8h]
  char **v87; // [esp+18h] [ebp-A8h]
  char **v88; // [esp+20h] [ebp-A0h]
  int v89; // [esp+24h] [ebp-9Ch] BYREF
  int v90; // [esp+28h] [ebp-98h] BYREF
  int v91; // [esp+2Ch] [ebp-94h] BYREF
  int v92; // [esp+30h] [ebp-90h] BYREF
  int v93; // [esp+34h] [ebp-8Ch] BYREF
  int v94; // [esp+38h] [ebp-88h] BYREF
  int v96; // [esp+44h] [ebp-7Ch]
  int *v97; // [esp+48h] [ebp-78h]
  int *v98; // [esp+4Ch] [ebp-74h]
  int *v99; // [esp+50h] [ebp-70h]
  int *v100; // [esp+54h] [ebp-6Ch] BYREF
  char v101[8]; // [esp+58h] [ebp-68h] BYREF
  int v102; // [esp+60h] [ebp-60h]
  int v103; // [esp+64h] [ebp-5Ch]
  int v104; // [esp+68h] [ebp-58h]
  unsigned int v105; // [esp+6Ch] [ebp-54h]
  int *v106; // [esp+74h] [ebp-4Ch]
  signed int *v107; // [esp+78h] [ebp-48h]
  int *v108; // [esp+7Ch] [ebp-44h]
  int *v109; // [esp+80h] [ebp-40h]
  int v110; // [esp+8Ch] [ebp-34h]
  int v111; // [esp+90h] [ebp-30h]
  int v112; // [esp+94h] [ebp-2Ch]
  _DWORD *v113; // [esp+9Ch] [ebp-24h]
  _DWORD *v114; // [esp+A0h] [ebp-20h]
  _DWORD *v115; // [esp+A4h] [ebp-1Ch]
  float v116; // [esp+A8h] [ebp-18h]
  int v117; // [esp+ACh] [ebp-14h]
  int v118; // [esp+B0h] [ebp-10h]
  int v119; // [esp+B4h] [ebp-Ch]
  float v120; // [esp+B8h] [ebp-8h]
  int v121; // [esp+BCh] [ebp-4h]

  if ( this[61] )
  {
    v6 = (int *)sub_4E29F0(2);
    if ( v6 )
    {
      if ( *((_BYTE *)this + 280) )
      {
        v7 = this[67];
        v8 = *this;
        v9 = this[3];
        v119 = v7;
        v10 = (*(int (__thiscall **)(int *))(v8 + 4))(this) <= v9
            ? this[3]
            : (*(int (__thiscall **)(int *))(*this + 4))(this);
        v11 = *this;
        v117 = v10;
        v12 = v6[3] - v6[2] - (*(int (__thiscall **)(int *))(v11 + 16))(this);
        v13 = (v12 + (*(int (__thiscall **)(int *))(*this + 8))(this)) / 2;
        v121 = (*(int (__thiscall **)(int *))(*this + 8))(this) - v13;
        if ( v7 > 0 )
        {
          if ( !*((_BYTE *)this + 280) )
          {
            v14 = *this;
            v15 = this[3];
            v120 = 0.0;
            v16 = (*(int (__thiscall **)(int *))(v14 + 4))(this);
            v17 = *this;
            if ( v15 > v16 )
            {
              v118 = (*(int (__thiscall **)(int *))(v17 + 4))(this);
              v18 = *this;
              v116 = (float)v118;
            }
            else
            {
              v116 = COERCE_FLOAT((*(int (__thiscall **)(int *))(v17 + 4))(this));
              v18 = *this;
              v116 = (float)SLODWORD(v116);
            }
            v118 = (*(int (__thiscall **)(int *))(v18 + 12))(this);
            if ( (double)v119 <= 1.0 )
              v19 = v120;
            else
              v19 = (double)this[67] / ((double)v118 - v116);
            LODWORD(v120) = this[4] - this[3];
            v7 = (unsigned __int64)((double)SLODWORD(v120) * v19 + 0.5) - 2;
          }
          v20 = v6[2];
          v21 = v6[3];
          v112 = 0;
          v111 = 0;
          v22 = v21 - v20;
          v110 = v22;
          v23 = sub_4DDFE0(&unk_B6E2A0, v121);
          sub_4D5E10(this, v6[7], *v6, v6[2], v23, v117, v121, v7);
          v24 = this[1];
          v25 = v114;
          *v113 = v24;
          v26 = v115;
          *v25 = v22 + v24;
          v27 = this[3];
          v28 = v116;
          *v26 = v27;
          *(_DWORD *)LODWORD(v28) = v7 + v27;
        }
      }
    }
  }
  (*(void (__thiscall **)(int *))(*this + 164))(this);
  if ( this[61] )
  {
    v29 = (int *)sub_4E29F0(3);
    if ( v29 )
    {
      if ( *((_BYTE *)this + 280) )
      {
        v30 = *this;
        this[68] = v29[1] - *v29;
        this[69] = v29[3] - v29[2];
        v31 = this[67] - this[68] / 2 + (*(int (__thiscall **)(int *))(v30 + 4))(this);
        v32 = this[69] - (*(int (__thiscall **)(int *))(*this + 16))(this);
        v33 = (*(int (__thiscall **)(int *))(*this + 8))(this);
        v34 = *this;
        v112 = (v32 + v33) / 2;
        v35 = (*(int (__thiscall **)(int *))(v34 + 8))(this);
        v36 = v29[2];
        v37 = v35 - v112;
        v38 = v29[1] - *v29;
        v39 = v29[3];
        v105 = 0;
        v104 = 0;
        v103 = v39 - v36;
        v102 = v38;
        v112 = v39 - v36;
        v111 = v38;
        v40 = sub_4DDFE0(&unk_B6E2A0, v36);
        sub_4D5E10(this, v29[7], *v29, v29[2], v40, v31, v37, v102);
        v41 = *v106;
        if ( *v106 >= v37 )
          v41 = v37;
        v42 = v105;
        *v106 = v41;
        v43 = *v107;
        v44 = v42 + v37;
        if ( *v107 <= v44 )
          v43 = v44;
        *v107 = v43;
        v45 = *v108;
        if ( *v108 >= v31 )
          v45 = v31;
        *v108 = v45;
        v46 = v104 + v31;
        v47 = *v109;
        if ( *v109 <= v46 )
          v47 = v46;
        *v109 = v47;
      }
    }
  }
  v48 = (const char *)this[40];
  if ( !v48 )
    v48 = WindowName;
  v105 = strlen(v48);
  if ( !v105 )
  {
    v63 = v108;
    goto LABEL_56;
  }
  v49 = this[61];
  if ( !*((_BYTE *)this + 280) )
  {
    v50 = (const CHAR **)(v49 + 88);
    goto LABEL_36;
  }
  if ( v49 )
  {
    v50 = (const CHAR **)(v49 + 64);
LABEL_36:
    v105 = (unsigned int)v50;
    v51 = *v50;
    if ( !v51 )
      v51 = WindowName;
    sub_4DF1B0(this[12], v51);
  }
  v52 = (const CHAR *)this[40];
  if ( !v52 )
    v52 = WindowName;
  sub_4E08C0(this[12], v52, &v100, v101, 1, v96);
  v53 = this[3] + (this[4] - this[3]) / 2 - v96 / 2;
  v54 = this[1] - (_DWORD)v97 - 1;
  if ( sub_4CFCC0(this, 5) >= 0 )
  {
    v57 = sub_4CFCC0(this, 5) - v96;
    v58 = sub_4CFD30(this, 5);
    v59 = (const CHAR *)this[40];
    if ( !v59 )
      v59 = WindowName;
    sub_4E07F0(this[12], v59, v58, v58, v57, v57 + v96, 1);
  }
  else
  {
    v55 = sub_4CFCC0(this, 2);
    v56 = sub_4CFD30(this, 2);
    v92 = 1;
    v91 = v55 + v96;
    v90 = v55;
    v89 = v56;
    v88 = (char **)v56;
    sub_4E0730(this[12]);
  }
  v60 = *v97;
  if ( *v97 >= v54 )
    v60 = v54;
  *v97 = v60;
  v61 = v92 + v54;
  v62 = *v98;
  if ( *v98 <= v61 )
    v62 = v61;
  v63 = v99;
  *v98 = v62;
  v64 = *v63;
  if ( *v63 >= v53 )
    v64 = v53;
  v65 = v91 + v53;
  v66 = v100;
  *v63 = v64;
  v67 = *v66;
  if ( *v66 <= v65 )
    v67 = v65;
  *v66 = v67;
LABEL_56:
  v68 = (const char *)this[42];
  if ( !v68 )
    v68 = WindowName;
  if ( strlen(v68) )
  {
    v69 = (_DWORD *)this[61];
    if ( v69 )
    {
      v70 = (const CHAR *)v69[18];
      if ( !v70 )
        v70 = WindowName;
    }
    else
    {
      v70 = 0;
    }
    if ( *((_BYTE *)this + 281) )
    {
      if ( v69 )
      {
        v70 = (const CHAR *)v69[20];
        if ( !v70 )
          v70 = WindowName;
      }
      else
      {
        v70 = 0;
      }
    }
    if ( !*((_BYTE *)this + 280) )
    {
      v70 = (const CHAR *)v69[22];
      if ( v70 )
        goto LABEL_72;
      v70 = WindowName;
    }
    if ( !v70 )
    {
LABEL_73:
      v71 = (const CHAR *)this[42];
      if ( !v71 )
        v71 = WindowName;
      sub_4E08C0(this[12], v71, &v92, &v93, 1, v86);
      v83 = (char *)&v91;
      v72 = sub_4CFDA0(3, (int)&v90);
      v73 = v90;
      v74 = v89;
      if ( v72 )
      {
        v82 = &v90;
        sub_4CFDA0(4, (int)&v94);
        v75 = (const CHAR *)this[42];
        if ( !v75 )
          v75 = WindowName;
        sub_4E0680(this[12], v75, v73, v89, v89, v93, 1);
      }
      else
      {
        v76 = (const CHAR *)this[42];
        if ( !v76 )
          v76 = WindowName;
        sub_4E08C0(this[12], v76, &v90, &v89, 1, &v91);
        sub_4E0730(this[12]);
        v63 = v84;
      }
      v77 = *v85;
      if ( *v85 >= v73 )
        v77 = v73;
      *v85 = v77;
      v78 = &v83[v73];
      if ( (int)*v87 > (int)&v83[v73] )
        v78 = *v87;
      *v87 = v78;
      v79 = *v63;
      if ( *v63 >= v74 )
        v79 = v74;
      *v63 = v79;
      v80 = (char *)v82 + v74;
      if ( (int)*v88 > (int)((char *)v82 + v74) )
        v80 = *v88;
      *v88 = v80;
      return 0;
    }
LABEL_72:
    sub_4DF1B0(this[12], v70);
    goto LABEL_73;
  }
  return 0;
}
