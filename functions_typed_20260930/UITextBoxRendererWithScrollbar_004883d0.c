int __thiscall sub_4883D0(int *this, int *a2, int *a3, int *a4, int *a5)
{
  _DWORD *v6; // edi
  int v7; // ebp
  int v8; // eax
  int v9; // ebx
  int v10; // ebx
  int v11; // eax
  int v12; // ebx
  int v13; // eax
  int v14; // edx
  int v15; // eax
  double v16; // st7
  int v17; // ebx
  int v18; // eax
  int v19; // eax
  int *v20; // edx
  int *v21; // ecx
  int v22; // eax
  int *v23; // edx
  _DWORD *v24; // edi
  int v25; // eax
  int v26; // ebp
  int v27; // ebx
  int v28; // eax
  int v29; // edx
  int v30; // ebx
  int v31; // eax
  int v32; // eax
  int v33; // ebx
  int v34; // eax
  int v35; // eax
  int v36; // edx
  int v37; // eax
  int v38; // ebp
  const char *v39; // eax
  _DWORD *v40; // ecx
  char *v41; // eax
  char *v42; // eax
  int v43; // ebx
  int v44; // edi
  int v45; // ebp
  int v46; // eax
  char *v47; // ecx
  int v48; // eax
  int v49; // ebp
  int v50; // eax
  char *v51; // ecx
  int *v52; // ebp
  int v53; // eax
  int *v54; // ecx
  int v55; // edi
  int v56; // eax
  int v57; // eax
  int v58; // ebx
  int v59; // eax
  const char *v60; // eax
  char *v61; // eax
  char *v62; // eax
  char v63; // al
  int v64; // edi
  int v65; // ebx
  char *v66; // eax
  char *v67; // eax
  char *v68; // edx
  int v69; // eax
  float v70; // ecx
  int *v71; // edx
  int v72; // eax
  int *v73; // ecx
  int v74; // eax
  int v75; // edx
  int v76; // eax
  int v78; // [esp-18h] [ebp-38h]
  int v79; // [esp-14h] [ebp-34h]
  int v80; // [esp-10h] [ebp-30h]
  int v81; // [esp+10h] [ebp-10h] BYREF
  float v82; // [esp+14h] [ebp-Ch] BYREF
  int v83; // [esp+18h] [ebp-8h] BYREF
  int v84; // [esp+1Ch] [ebp-4h] BYREF

  v6 = (_DWORD *)ConditionalDelegation_6460(this, 1);
  if ( v6 )
  {
    v7 = this[56];
    v8 = *this;
    v9 = this[3];
    v81 = v7;
    if ( (*(int (__thiscall **)(int *))(v8 + 24))(this) > v9 )
    {
      v10 = this[3];
      v7 += (*(int (__thiscall **)(int *))(*this + 24))(this) - v10;
      v81 = v7;
    }
    if ( v7 > 0 )
    {
      if ( !*((_BYTE *)this + 236) )
      {
        v11 = *this;
        v12 = this[3];
        *(float *)&v84 = 0.0;
        v13 = (*(int (__thiscall **)(int *))(v11 + 24))(this);
        v14 = *this;
        if ( v12 > v13 )
        {
          v83 = (*(int (__thiscall **)(int *))(v14 + 24))(this);
          v15 = *this;
          v82 = (float)v83;
        }
        else
        {
          v82 = COERCE_FLOAT((*(int (__thiscall **)(int *))(v14 + 24))(this));
          v15 = *this;
          v82 = (float)SLODWORD(v82);
        }
        v83 = (*(int (__thiscall **)(int *))(v15 + 32))(this);
        if ( (double)v81 <= 1.0 )
          v16 = *(float *)&v84;
        else
          v16 = (double)this[56] / ((double)v83 - v82);
        v84 = this[4] - this[3];
        v7 = CRTFtol(v16) - 2;
      }
      v17 = v6[3] - v6[2];
      v79 = this[1];
      v78 = this[3];
      v18 = GlobalAccessor_5150(&unk_7CDE00);
      F_10ParamForwarder(*(_DWORD *)(v6[8] + 12), *v6, v6[2], v18, v78, v79, v7, v17, 0, 0);
      v19 = this[1];
      v20 = a3;
      *a2 = v19;
      v21 = a4;
      *v20 = v17 + v19;
      v22 = this[3];
      v23 = a5;
      *v21 = v22;
      *v23 = v7 + v22;
    }
  }
  (*(void (__thiscall **)(int *))(*this + 172))(this);
  v24 = (_DWORD *)ConditionalDelegation_6460(this, 2);
  if ( v24 && *((_BYTE *)this + 236) )
  {
    v25 = *this;
    this[57] = v24[1] - *v24;
    this[58] = v24[3] - v24[2];
    v26 = this[56] - this[57] / 2 + (*(int (__thiscall **)(int *))(v25 + 24))(this);
    v27 = this[58] - (*(int (__thiscall **)(int *))(*this + 36))(this);
    v28 = (*(int (__thiscall **)(int *))(*this + 28))(this);
    v29 = *this;
    v84 = (v27 + v28) / 2;
    v30 = (*(int (__thiscall **)(int *))(v29 + 28))(this) - v84;
    v80 = v24[1] - *v24;
    v84 = v24[3] - v24[2];
    v83 = v80;
    v31 = GlobalAccessor_5150(&unk_7CDE00);
    F_10ParamForwarder(*(_DWORD *)(v24[8] + 12), *v24, v24[2], v31, v26, v30, v80, v84, 0, 0);
    v32 = *a2;
    if ( *a2 >= v30 )
      v32 = v30;
    *a2 = v32;
    v33 = v84 + v30;
    v34 = *a3;
    if ( *a3 <= v33 )
      v34 = v33;
    *a3 = v34;
    v35 = *a4;
    if ( *a4 >= v26 )
      v35 = v26;
    v36 = v83;
    *a4 = v35;
    v37 = *a5;
    v38 = v36 + v26;
    if ( *a5 <= v38 )
      v37 = v38;
    *a5 = v37;
  }
  v39 = (const char *)this[44];
  if ( !v39 )
    v39 = byte_5EA438;
  if ( strlen(v39) )
  {
    if ( UIStringAccessor_62c0(this) )
    {
      v41 = UIStringAccessor_62c0(v40);
      sub_498560(v41);
    }
    v42 = (char *)this[44];
    if ( !v42 )
      v42 = byte_5EA438;
    TextRenderToSurface(v42, &v81, &v82, 1);
    v43 = this[3] + (this[4] - this[3]) / 2 - v81 / 2;
    v44 = this[1] - LODWORD(v82) - 1;
    if ( sub_487060(this, 5) >= 0 )
    {
      v48 = sub_487060(this, 5);
      v49 = v48 - v81;
      v50 = sub_4870E0(this, 5);
      v51 = (char *)this[44];
      if ( !v51 )
        v51 = byte_5EA438;
      BitmapDrawWithAlpha(v51, v50, v50, v49, v49 + v81, 1);
    }
    else
    {
      v45 = sub_487060(this, 2);
      v46 = sub_4870E0(this, 2);
      v47 = (char *)this[44];
      if ( !v47 )
        v47 = byte_5EA438;
      BitmapDraw_81f0(v47, v46, v46, v45, v45 + v81, 1);
    }
    v52 = a2;
    v53 = *a2;
    if ( *a2 >= v44 )
      v53 = v44;
    v54 = a3;
    *a2 = v53;
    v55 = LODWORD(v82) + v44;
    v56 = *v54;
    if ( *v54 <= v55 )
      v56 = v55;
    *v54 = v56;
    v57 = *a4;
    if ( *a4 >= v43 )
      v57 = v43;
    *a4 = v57;
    v58 = v81 + v43;
    v59 = *a5;
    if ( *a5 <= v58 )
      v59 = v58;
    *a5 = v59;
  }
  else
  {
    v52 = a2;
  }
  v60 = (const char *)this[46];
  if ( !v60 )
    v60 = byte_5EA438;
  if ( strlen(v60) )
  {
    v61 = UIStringAccessor_62e0(this);
    if ( v61 )
      sub_498560(v61);
    v62 = (char *)this[46];
    if ( !v62 )
      v62 = byte_5EA438;
    TextRenderToSurface(v62, &v81, &v82, 1);
    v63 = UtilityFunction_7160(this, 3, &v83, &v84);
    v64 = v84;
    v65 = v83;
    if ( v63 )
    {
      UtilityFunction_7160(this, 4, &a2, &v84);
      v66 = (char *)this[46];
      if ( !v66 )
        v66 = byte_5EA438;
      BitmapDraw(v66, v64, v84, v65, a2, 1);
    }
    else
    {
      v67 = (char *)this[46];
      if ( !v67 )
        v67 = byte_5EA438;
      TextRenderToSurface(v67, &v84, &v83, 1);
      v68 = (char *)this[46];
      if ( !v68 )
        v68 = byte_5EA438;
      BitmapDraw_81f0(v68, this[1], this[1] + v83, this[4], this[4] + v84, 1);
      v52 = a2;
    }
    v69 = *v52;
    if ( *v52 >= v64 )
      v69 = v64;
    v70 = v82;
    v71 = a3;
    *v52 = v69;
    v72 = v64 + LODWORD(v70);
    if ( *v71 > v64 + LODWORD(v70) )
      v72 = *v71;
    v73 = a4;
    *v71 = v72;
    v74 = *v73;
    if ( *v73 >= v65 )
      v74 = v65;
    v75 = v81;
    *v73 = v74;
    v76 = v65 + v75;
    if ( *a5 > v65 + v75 )
      v76 = *a5;
    *a5 = v76;
  }
  return 0;
}

