void __thiscall sub_5688F0(
        int this,
        int a2,
        int a3,
        int a4,
        float a5,
        _DWORD *a6,
        float a7,
        float a8,
        const CHAR *a9,
        char a10)
{
  _DWORD *v10; // esi
  int v11; // eax
  int v12; // ecx
  int v13; // eax
  int v14; // eax
  int v15; // esi
  int v16; // edi
  int v17; // ebx
  int v18; // eax
  int v19; // eax
  int v20; // edx
  bool v21; // dl
  int v22; // edx
  int v23; // eax
  int v24; // esi
  int v25; // edx
  int v26; // ecx
  int v27; // eax
  int v28; // ecx
  int v29; // eax
  int v30; // edx
  char v31; // cl
  int v32; // eax
  char v33; // cl
  char *v34; // eax
  int v35; // edx
  char v36; // cl
  int v37; // eax
  int v38; // edx
  int v39; // [esp+0h] [ebp-18Ch]
  float v40; // [esp+4h] [ebp-188h]
  int *v41; // [esp+14h] [ebp-178h]
  int v42; // [esp+18h] [ebp-174h]
  int v43; // [esp+1Ch] [ebp-170h]
  int v44; // [esp+28h] [ebp-164h]
  _DWORD *v45; // [esp+2Ch] [ebp-160h]
  int v46; // [esp+30h] [ebp-15Ch]
  int v47; // [esp+34h] [ebp-158h]
  int v48; // [esp+38h] [ebp-154h] BYREF
  int v49; // [esp+3Ch] [ebp-150h]
  int v50; // [esp+40h] [ebp-14Ch] BYREF
  int v51; // [esp+44h] [ebp-148h] BYREF
  int v52; // [esp+48h] [ebp-144h]
  int v53; // [esp+4Ch] [ebp-140h]
  int v54; // [esp+50h] [ebp-13Ch] BYREF
  int v55; // [esp+54h] [ebp-138h]
  int v56; // [esp+58h] [ebp-134h]
  int v57; // [esp+5Ch] [ebp-130h]
  int v58; // [esp+60h] [ebp-12Ch] BYREF
  int v59; // [esp+64h] [ebp-128h]
  int v60; // [esp+68h] [ebp-124h]
  int v61; // [esp+6Ch] [ebp-120h]
  int v62; // [esp+70h] [ebp-11Ch] BYREF
  int v63; // [esp+74h] [ebp-118h]
  int v64; // [esp+78h] [ebp-114h]
  _BYTE v65[13]; // [esp+7Ch] [ebp-110h] BYREF
  __int16 v66; // [esp+89h] [ebp-103h]
  char v67; // [esp+8Bh] [ebp-101h]
  char v68[125]; // [esp+8Ch] [ebp-100h] BYREF
  __int16 v69; // [esp+109h] [ebp-83h]
  char v70; // [esp+10Bh] [ebp-81h]
  _BYTE v71[125]; // [esp+10Ch] [ebp-80h] BYREF
  __int16 v72; // [esp+189h] [ebp-3h]
  char v73; // [esp+18Bh] [ebp-1h]
  int savedregs; // [esp+18Ch] [ebp+0h] BYREF
  int v75; // [esp+198h] [ebp+Ch]
  int v76; // [esp+19Ch] [ebp+10h]

  v10 = (_DWORD *)this;
  v45 = (_DWORD *)this;
  if ( a2 )
  {
    memset(v68, 0, sizeof(v68));
    v69 = 0;
    v70 = 0;
    if ( !a9 )
    {
      a9 = *(const CHAR **)(this + 40);
      if ( !a9 )
        a9 = WindowName;
    }
    if ( a7 > 0.0 )
      *(float *)(this + 56) = a7;
    if ( a8 > 0.0 )
      *(float *)(this + 60) = a8;
    sub_630FE0(v68, a2, 127);
    v11 = v10[2];
    v12 = v10[3];
    v49 = v11 + v10[5];
    v53 = v12 + v10[6];
    v52 = v11;
    v70 = 0;
    v64 = v12;
    v75 = v11 + a3;
    v76 = v12 + a4;
    if ( v68[0] )
    {
      while ( 1 )
      {
        v13 = v10[15];
        v59 = v10[14];
        v57 = v13;
        v14 = sub_5F04C0(dword_FB1CE0, (int)a9);
        v15 = v14;
        v16 = 0;
        v17 = 0;
        v50 = 0;
        v51 = 0;
        if ( v14 )
        {
          v18 = *(_DWORD *)(v14 + 152);
          v61 = *(_DWORD *)(v15 + 156);
          v42 = 1;
          v56 = v18;
          v19 = v57;
          v41 = &v50;
          *(_DWORD *)(v15 + 152) = v59;
          *(_DWORD *)(v15 + 156) = v19;
          sub_5F0380(v68, &v51, v41, v42);
          v20 = v61;
          *(_DWORD *)(v15 + 152) = v56;
          *(_DWORD *)(v15 + 156) = v20;
          v16 = v50;
          v17 = v51;
        }
        sub_5679B0(v75, v76, v17, v16, a6, &v54, &v58);
        v44 = v54 + v17;
        v55 = v58 + v16;
        v21 = v58 >= v64 && v58 + v16 <= v53;
        if ( v54 >= v52 && v54 + v17 <= v49 && (!a10 || v21) )
          break;
        if ( a10 && (v58 < v64 || v55 > v53) || v17 <= 0 )
          return;
        *(_DWORD *)&v65[5] = 0;
        *(_DWORD *)&v65[9] = 0;
        v66 = 0;
        v67 = 0;
        strcpy(v65, "AbCd");
        v22 = v45[14];
        v63 = v45[15];
        v60 = v22;
        v23 = sub_5F04C0(dword_FB1CE0, (int)a9);
        v24 = v23;
        v62 = 0;
        v48 = 0;
        if ( v23 )
        {
          v25 = *(_DWORD *)(v23 + 156);
          v47 = *(_DWORD *)(v23 + 152);
          v26 = v63;
          v42 = 1;
          v46 = v25;
          *(_DWORD *)(v23 + 152) = v60;
          v41 = &v62;
          *(_DWORD *)(v23 + 156) = v26;
          sub_5F0380(v65, &v48, v41, v42);
          v27 = v46;
          *(_DWORD *)(v24 + 152) = v47;
          *(_DWORD *)(v24 + 156) = v27;
        }
        v28 = v48 / 4;
        if ( v48 / 4 >= 1 )
        {
          if ( v28 > 1000 )
            v28 = 1000;
        }
        else
        {
          v28 = 1;
        }
        if ( v54 >= v52 )
        {
          v37 = (v44 - v49) / v28;
          if ( v37 >= 1 )
          {
            if ( v37 > 1000 )
              v37 = 1000;
          }
          else
          {
            v37 = 1;
          }
          if ( v37 >= (int)strlen(v68) )
            return;
          v68[strlen(v68) - v37] = 0;
        }
        else
        {
          v29 = (v52 - v54) / v28;
          v30 = v29;
          if ( v29 >= 1 )
          {
            if ( v29 > 1000 )
              v30 = 1000;
          }
          else
          {
            v30 = 1;
          }
          if ( v30 >= &v68[strlen(v68) + 1] - &v68[1] )
            return;
          v71[0] = v31;
          memset(&v71[1], 0, 0x7Cu);
          v72 = 0;
          v73 = 0;
          v32 = 0;
          do
          {
            v33 = v68[v32];
            v71[v32++] = v33;
          }
          while ( v33 );
          v34 = &v71[v30];
          v35 = v68 - &v71[v30];
          do
          {
            v36 = *v34;
            v34[v35] = *v34;
            ++v34;
          }
          while ( v36 );
        }
        if ( !v68[0] )
          return;
        v10 = v45;
      }
      v38 = v45[14];
      v46 = v45[15];
      v44 = dword_903EBC;
      v47 = v38;
      v40 = (double)v76 / (double)dword_903EBC;
      *(float *)&v39 = (double)v75 / (double)*(int *)dword_903EB8;
      sub_5680F0((int)a9, (int)v68, (int)&savedregs, v39, (float *)LODWORD(v40), a5, *(float *)&a6, v38, v46, 0, v43);
    }
  }
}
