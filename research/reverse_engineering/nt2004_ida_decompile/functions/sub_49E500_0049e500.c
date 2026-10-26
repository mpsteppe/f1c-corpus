int __thiscall sub_49E500(int *this, int *a2, int *a3, int *a4, int *a5)
{
  int v6; // edi
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
  float v17; // ebx
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // edi
  int v22; // edx
  char **v23; // ebp
  int v24; // ebx
  int v25; // eax
  int v26; // edx
  int v27; // ebx
  int v28; // eax
  int v29; // eax
  int v30; // ebx
  int v31; // eax
  char **v32; // eax
  char *v33; // ebp
  char *v34; // eax
  const char *v35; // eax
  _DWORD *v36; // ecx
  char *v37; // eax
  char *v38; // eax
  int v39; // ebx
  int v40; // ebp
  int v41; // edi
  int v42; // eax
  char *v43; // ecx
  int v44; // eax
  int v45; // edi
  int v46; // eax
  char *v47; // ecx
  int v48; // eax
  int v49; // ebp
  int v50; // eax
  int v51; // eax
  int v52; // ebx
  int v53; // eax
  const char *v54; // eax
  char *v55; // eax
  char *v56; // eax
  char v57; // al
  int v58; // edi
  int v59; // ebx
  char *v60; // eax
  char *v61; // eax
  char *v62; // edx
  int v63; // eax
  int v64; // eax
  int v65; // eax
  int v66; // edx
  int v67; // eax
  char **v69; // [esp-18h] [ebp-38h]
  int v70; // [esp-14h] [ebp-34h]
  int v71; // [esp-10h] [ebp-30h]
  int v72; // [esp+10h] [ebp-10h] BYREF
  int v73; // [esp+14h] [ebp-Ch] BYREF
  int v74; // [esp+18h] [ebp-8h] BYREF
  int v75; // [esp+1Ch] [ebp-4h] BYREF

  v6 = sub_49CB60(this, 2);
  if ( v6 )
  {
    v7 = this[67];
    v8 = *this;
    v9 = this[3];
    v72 = v7;
    if ( (*(int (__thiscall **)(int *))(v8 + 4))(this) > v9 )
    {
      v10 = this[3];
      v7 += (*(int (__thiscall **)(int *))(*this + 4))(this) - v10;
      v72 = v7;
    }
    if ( v7 > 0 )
    {
      if ( !*((_BYTE *)this + 280) )
      {
        v11 = *this;
        v12 = this[3];
        *(float *)&v75 = 0.0;
        v13 = (*(int (__thiscall **)(int *))(v11 + 4))(this);
        v14 = *this;
        if ( v12 > v13 )
        {
          v74 = (*(int (__thiscall **)(int *))(v14 + 4))(this);
          v15 = *this;
          *(float *)&v73 = (float)v74;
        }
        else
        {
          *(float *)&v73 = COERCE_FLOAT((*(int (__thiscall **)(int *))(v14 + 4))(this));
          v15 = *this;
          *(float *)&v73 = (float)v73;
        }
        v74 = (*(int (__thiscall **)(int *))(v15 + 12))(this);
        if ( (double)v72 <= 1.0 )
          v16 = *(float *)&v75;
        else
          v16 = (double)this[67] / ((double)v74 - *(float *)&v73);
        v75 = this[4] - this[3];
        v7 = (__int64)((double)v75 * v16 + 0.5) - 2;
      }
      LODWORD(v17) = *(_DWORD *)(v6 + 12) - *(_DWORD *)(v6 + 8);
      v70 = this[1];
      v69 = (char **)this[3];
      v18 = sub_4AB570(&unk_765B00);
      sub_49CB80(*(char ***)(v6 + 28), *(_DWORD *)v6, *(_DWORD *)(v6 + 8), v18, v69, v70, v7, v17, 0, 0);
      v19 = this[1];
      *a2 = v19;
      *a3 = LODWORD(v17) + v19;
      v20 = this[3];
      *a4 = v20;
      *a5 = v7 + v20;
    }
  }
  (*(void (__thiscall **)(int *))(*this + 164))(this);
  v21 = sub_49CB60(this, 3);
  if ( v21 && *((_BYTE *)this + 280) )
  {
    v22 = *this;
    this[68] = *(_DWORD *)(v21 + 4) - *(_DWORD *)v21;
    this[69] = *(_DWORD *)(v21 + 12) - *(_DWORD *)(v21 + 8);
    v23 = (char **)(this[67] - this[68] / 2 + (*(int (__thiscall **)(int *))(v22 + 4))(this));
    v24 = this[69] - (*(int (__thiscall **)(int *))(*this + 16))(this);
    v25 = (*(int (__thiscall **)(int *))(*this + 8))(this);
    v26 = *this;
    v75 = (v24 + v25) / 2;
    v27 = (*(int (__thiscall **)(int *))(v26 + 8))(this) - v75;
    v71 = *(_DWORD *)(v21 + 4) - *(_DWORD *)v21;
    v75 = *(_DWORD *)(v21 + 12) - *(_DWORD *)(v21 + 8);
    v74 = v71;
    v28 = sub_4AB570(&unk_765B00);
    sub_49CB80(*(char ***)(v21 + 28), *(_DWORD *)v21, *(_DWORD *)(v21 + 8), v28, v23, v27, v71, *(float *)&v75, 0, 0);
    v29 = *a2;
    if ( *a2 >= v27 )
      v29 = v27;
    *a2 = v29;
    v30 = v75 + v27;
    v31 = *a3;
    if ( *a3 <= v30 )
      v31 = v30;
    *a3 = v31;
    v32 = (char **)*a4;
    if ( *a4 >= (int)v23 )
      v32 = v23;
    *a4 = (int)v32;
    v33 = (char *)v23 + v74;
    v34 = (char *)*a5;
    if ( *a5 <= (int)v33 )
      v34 = v33;
    *a5 = (int)v34;
  }
  v35 = (const char *)this[40];
  if ( !v35 )
    v35 = &byte_629120;
  if ( strlen(v35) )
  {
    if ( sub_49C9C0(this) )
    {
      v37 = sub_49C9C0(v36);
      sub_4AE350(v37);
    }
    v38 = (char *)this[40];
    if ( !v38 )
      v38 = &byte_629120;
    sub_4AE230(v38, (int)&v72, (int)&v73);
    v39 = this[3] + (this[4] - this[3]) / 2 - v72 / 2;
    v40 = this[1] - v73 - 1;
    if ( sub_49D770(this, 5) >= 0 )
    {
      v44 = sub_49D770(this, 5);
      v45 = v44 - v72;
      v46 = sub_49D7F0(this, 5);
      v47 = (char *)this[40];
      if ( !v47 )
        v47 = &byte_629120;
      sub_4AE150(v47, v46, v46, v45, v45 + v72);
    }
    else
    {
      v41 = sub_49D770(this, 2);
      v42 = sub_49D7F0(this, 2);
      v43 = (char *)this[40];
      if ( !v43 )
        v43 = &byte_629120;
      sub_4AE080(v43, v42, v42, v41, v41 + v72);
    }
    v48 = *a2;
    if ( *a2 >= v40 )
      v48 = v40;
    *a2 = v48;
    v49 = v73 + v40;
    v50 = *a3;
    if ( *a3 <= v49 )
      v50 = v49;
    *a3 = v50;
    v51 = *a4;
    if ( *a4 >= v39 )
      v51 = v39;
    *a4 = v51;
    v52 = v72 + v39;
    v53 = *a5;
    if ( *a5 <= v52 )
      v53 = v52;
    *a5 = v53;
  }
  v54 = (const char *)this[42];
  if ( !v54 )
    v54 = &byte_629120;
  if ( strlen(v54) )
  {
    v55 = sub_49C9E0(this);
    if ( v55 )
      sub_4AE350(v55);
    v56 = (char *)this[42];
    if ( !v56 )
      v56 = &byte_629120;
    sub_4AE230(v56, (int)&v72, (int)&v73);
    v57 = sub_49D870(this, 3, &v74, &v75);
    v58 = v75;
    v59 = v74;
    if ( v57 )
    {
      sub_49D870(this, 4, &v75, &v74);
      v60 = (char *)this[42];
      if ( !v60 )
        v60 = &byte_629120;
      sub_4ADFB0(v60, v58, v74, v59, v75);
    }
    else
    {
      v61 = (char *)this[42];
      if ( !v61 )
        v61 = &byte_629120;
      sub_4AE230(v61, (int)&v75, (int)&v74);
      v62 = (char *)this[42];
      if ( !v62 )
        v62 = &byte_629120;
      sub_4AE080(v62, this[1], this[1] + v74, this[4], this[4] + v75);
    }
    v63 = *a2;
    if ( *a2 >= v58 )
      v63 = v58;
    *a2 = v63;
    v64 = v58 + v73;
    if ( *a3 > v58 + v73 )
      v64 = *a3;
    *a3 = v64;
    v65 = *a4;
    if ( *a4 >= v59 )
      v65 = v59;
    v66 = v72;
    *a4 = v65;
    v67 = v59 + v66;
    if ( *a5 > v59 + v66 )
      v67 = *a5;
    *a5 = v67;
  }
  return 0;
}
