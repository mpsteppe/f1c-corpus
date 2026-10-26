int __userpurge sub_5E12E0@<eax>(float *a1@<ecx>, float *a2@<ebp>, char *a3, _DWORD *a4, int *a5)
{
  int *v6; // ebx
  char *v7; // eax
  int v8; // esi
  int v9; // eax
  void **v10; // eax
  float v11; // eax
  unsigned int v12; // eax
  float v13; // eax
  unsigned int v14; // eax
  float v15; // eax
  unsigned int v16; // eax
  float v17; // ecx
  unsigned int v18; // eax
  float v19; // ecx
  unsigned int v20; // eax
  float v21; // ecx
  unsigned int v22; // eax
  float v23; // eax
  unsigned int v24; // eax
  int v25; // edx
  int v26; // edx
  int v27; // esi
  float v29; // edx
  int v30; // ecx
  int v31; // edx
  int v32; // ecx
  int v33; // edx
  int v34; // eax
  int v35; // edi
  int v36; // ebp
  int v37; // eax
  unsigned int v38; // eax
  int v39; // eax
  unsigned int v40; // eax
  int v41; // eax
  unsigned int v42; // eax
  int v43; // eax
  unsigned int v44; // eax
  int *v45; // eax
  int v46; // eax
  int v47; // ecx
  int v48; // eax
  int *v49; // eax
  _DWORD *v50; // eax
  float v51; // [esp+10h] [ebp-370h]
  char v52; // [esp+27h] [ebp-359h]
  int v54; // [esp+2Ch] [ebp-354h] BYREF
  int v55; // [esp+30h] [ebp-350h] BYREF
  int v56; // [esp+34h] [ebp-34Ch] BYREF
  int v57; // [esp+38h] [ebp-348h] BYREF
  float v58; // [esp+3Ch] [ebp-344h] BYREF
  float v59; // [esp+40h] [ebp-340h] BYREF
  float v60; // [esp+44h] [ebp-33Ch] BYREF
  int v61; // [esp+48h] [ebp-338h] BYREF
  int v62; // [esp+4Ch] [ebp-334h]
  char *v63; // [esp+50h] [ebp-330h] BYREF
  char *EndPtr; // [esp+54h] [ebp-32Ch] BYREF
  char *v65; // [esp+58h] [ebp-328h] BYREF
  char *v66; // [esp+5Ch] [ebp-324h] BYREF
  char *v67; // [esp+60h] [ebp-320h] BYREF
  char *v68; // [esp+64h] [ebp-31Ch] BYREF
  float v69; // [esp+68h] [ebp-318h] BYREF
  int v70; // [esp+6Ch] [ebp-314h]
  char *v71; // [esp+70h] [ebp-310h] BYREF
  char ArgList[256]; // [esp+74h] [ebp-30Ch] BYREF
  char String[256]; // [esp+174h] [ebp-20Ch] BYREF
  char v74[256]; // [esp+274h] [ebp-10Ch] BYREF
  int v75; // [esp+37Ch] [ebp-4h]

  v6 = 0;
  v62 = 6;
  v52 = 0;
  v7 = (char *)operator new(0x28Cu);
  v63 = v7;
  v75 = 0;
  if ( v7 )
    v6 = sub_5DB7E0((int *)v7);
  v75 = -1;
  v6[156] = (int)a4;
  v6[155] = (int)a1;
  v60 = 0.0;
  v58 = 0.0;
  v59 = 0.0;
  v55 = 0;
  v57 = 0;
  v56 = 0;
  if ( sub_5DF750(a5) != 1 )
  {
    while ( *a5 != 3 )
    {
      if ( *a5 != 2 )
      {
        v8 = (int)a5;
        if ( sub_5DEF70() )
        {
          EndPtr = (char *)(a5[515] + 1);
          v9 = strtol(EndPtr, &EndPtr, 10);
          if ( (v9 & dword_FB2318) != v9 )
          {
            if ( sub_5DF750(a5) != 1 )
            {
              while ( *a5 != 3 && sub_5DF750(a5) != 1 )
                ;
            }
            goto LABEL_163;
          }
          v6[1] = v9;
        }
        if ( sub_5DF240((int)a5, "INSTANCE", String, 0, 0, 0, 0, 0, 0, 0) && sub_5E12E0(String, v6, a5)
          || sub_5DF240((int)a5, "LIGHT", String, 0, 0, 0, 0, 0, 0, 0) && sub_5DFD60(a1, (int)String, (int)v6, a5)
          || sub_5DF240((int)a5, "PROJECTOR", String, 0, 0, 0, 0, 0, 0, 0) && sub_5E0AB0(a1, (char)String, (int)v6, a5) )
        {
          return -1;
        }
        if ( sub_5DF240((int)a5, "MESHFILE", String, 0, 0, 0, 0, 0, 0, 0) )
        {
          v52 = 0;
          if ( sub_5DCC20((char *)v6, (int)a2, a3, String, 0, 0) )
            return -1;
          v10 = (void **)v6[134];
          v6[135] = (int)v10;
          if ( v10 )
            a2 = (float *)*v10;
          else
            a2 = 0;
          if ( sub_5DEF70() )
          {
            v68 = (char *)(a5[515] + 1);
            a2[60] = strtod(v68, &v68);
          }
          if ( sub_5DEF70() )
          {
            v71 = (char *)(a5[515] + 1);
            a2[61] = strtod(v71, &v71);
          }
          if ( sub_5DEF70() )
          {
            v67 = (char *)(a5[515] + 1);
            v70 = strtol(v67, &v67, 10);
            v51 = (float)v70;
            sub_5EB330(v51);
          }
          if ( sub_5DF240((int)a5, "VISIBLE", ArgList, 0, 0, 0, 0, 0, 0, 0) )
          {
            v11 = *a2;
            v8 = (int)a5;
            if ( !strcmp(ArgList, "TRUE") )
              v12 = LODWORD(v11) & 0xFEFFFFFF;
            else
              v12 = (unsigned int)&dword_1000000 | LODWORD(v11);
            *(_DWORD *)a2 = v12;
          }
          if ( sub_5DF240(v8, "RENDER", ArgList, 0, 0, 0, 0, 0, 0, 0) )
          {
            v13 = *a2;
            v8 = (int)a5;
            if ( !strcmp(ArgList, "TRUE") )
              v14 = LODWORD(v13) & 0xFEFFFFFF;
            else
              v14 = (unsigned int)&dword_1000000 | LODWORD(v13);
            *(_DWORD *)a2 = v14;
          }
          if ( sub_5DF240(v8, "DEFORMABLE", ArgList, 0, 0, 0, 0, 0, 0, 0) )
          {
            v15 = *a2;
            v8 = (int)a5;
            if ( !strcmp(ArgList, "TRUE") )
              v16 = LODWORD(v15) | 0x20000000;
            else
              v16 = LODWORD(v15) & 0xDFFFFFFF;
            *(_DWORD *)a2 = v16;
          }
          if ( sub_5DF240(v8, "HATTARGET", ArgList, 0, 0, 0, 0, 0, 0, 0) )
          {
            v8 = (int)a5;
            v17 = *a2;
            if ( !strcmp(ArgList, "TRUE") )
            {
              *(_DWORD *)a2 = LODWORD(v17) | 0x400000;
              v18 = *v6 | 0x10000;
            }
            else
            {
              *(_DWORD *)a2 = LODWORD(v17) & 0xFFBFFFFF;
              v18 = *v6 & 0xFFFEFFFF;
            }
            *v6 = v18;
          }
          if ( sub_5DF240(v8, "COLLTARGET", ArgList, 0, 0, 0, 0, 0, 0, 0) )
          {
            v8 = (int)a5;
            v19 = *a2;
            if ( !strcmp(ArgList, "TRUE") )
            {
              *(_DWORD *)a2 = LODWORD(v19) | 0x100000;
              v20 = *v6 | 0x20000;
            }
            else
            {
              *(_DWORD *)a2 = LODWORD(v19) & 0xFFEFFFFF;
              v20 = *v6 & 0xFFFDFFFF;
            }
            *v6 = v20;
          }
          if ( sub_5DF240(v8, "SPHERETARGET", ArgList, 0, 0, 0, 0, 0, 0, 0) )
          {
            v8 = (int)a5;
            v21 = *a2;
            if ( !strcmp(ArgList, "TRUE") )
            {
              *(_DWORD *)a2 = LODWORD(v21) | 0x200000;
              v22 = *v6 | 0x40000;
            }
            else
            {
              *(_DWORD *)a2 = LODWORD(v21) & 0xFFDFFFFF;
              v22 = *v6 & 0xFFFBFFFF;
            }
            *v6 = v22;
          }
          if ( sub_5DF240(v8, "ZBUFFER", ArgList, 0, 0, 0, 0, 0, 0, 0) )
          {
            v23 = *a2;
            v8 = (int)a5;
            if ( !strcmp(ArgList, "TRUE") )
              v24 = LODWORD(v23) & 0xFFFFFFEF;
            else
              v24 = LODWORD(v23) | 0x10;
            *(_DWORD *)a2 = v24;
          }
          if ( sub_5DF0E0(v8, "SHADOWCASTER", ArgList, v74, &v54, &v61, String)
            && (!strcmp(ArgList, "TRUE") || !strcmp(ArgList, "STATIC") || !strcmp(ArgList, "DYNAMIC")) )
          {
            v25 = 0;
            if ( !strcmp(v74, "TEXTURE") )
              v25 = 1024;
            if ( !strcmp(ArgList, "DYNAMIC") )
              v25 |= 0x4000u;
            if ( ((*(_DWORD *)a1 & 0x10000) != 0 && (*v6 & 0x10) == 0
               || (*(_DWORD *)a1 & 0x20000) != 0 && (*(_BYTE *)v6 & 0x10) != 0)
              && a1[71] > 0.0
              && sub_5DB470(
                   v6,
                   (int)a2,
                   (int)a4,
                   (unsigned __int64)((double)v54 * a1[71]),
                   (unsigned __int64)((double)v61 * a1[71]),
                   v25)
              || String[0] && *((_DWORD *)a2 + 116) && sub_5E6040(String) )
            {
              return -1;
            }
          }
          if ( sub_5DF0E0((int)a5, "SHADOWOBJECT", ArgList, v74, &v54, &v61, String)
            && (!strcmp(ArgList, "TRUE") || !strcmp(ArgList, "STATIC") || !strcmp(ArgList, "DYNAMIC")) )
          {
            v26 = 0;
            if ( !strcmp(v74, "TEXTURE") )
              v26 = 1024;
            if ( !strcmp(ArgList, "DYNAMIC") )
              v26 |= 0x4000u;
            v27 = *(_DWORD *)a1;
            if ( (*(_DWORD *)a1 & 0x10000000) != 0 )
              v26 |= 0x10000000u;
            if ( (v27 & 0x10000) != 0 && (*v6 & 0x10) == 0 || (v27 & 0x20000) != 0 && (*(_BYTE *)v6 & 0x10) != 0 )
            {
              if ( a1[71] > 0.0
                && sub_5DB470(
                     v6,
                     (int)a2,
                     (int)a4,
                     (unsigned __int64)((double)v54 * a1[71]),
                     (unsigned __int64)((double)v61 * a1[71]),
                     v26) )
              {
                return -1;
              }
              *(_DWORD *)a2 |= 0x200u;
              if ( String[0] )
              {
                if ( *((_DWORD *)a2 + 116) && sub_5E6040(String) )
                  return -1;
              }
            }
            else if ( (*(_DWORD *)a2 & 0x100000) != 0 )
            {
              *(_DWORD *)a2 |= (unsigned int)&dword_1000000;
            }
            else
            {
              v52 = 1;
            }
          }
          if ( sub_5DF240((int)a5, "SHADOWRECEIVER", ArgList, v74, 0, 0, 0, 0, 0, 0)
            && (*(_DWORD *)a1 & 0xF0000) != 0
            && !strcmp(ArgList, "TRUE") )
          {
            v52 = 0;
            if ( !strcmp(ArgList, "TEXTURE") )
              *(_DWORD *)a2 |= (unsigned int)&byte_800000;
            if ( (*(_BYTE *)v6 & 0x10) != 0 )
              sub_5E6BC0(v6, a2);
            else
              sub_5E6B60(v6, a2);
          }
          if ( sub_5DF240((int)a5, "REFLECT", ArgList, 0, 0, 0, 0, 0, 0, 0) )
          {
            v29 = *a2;
            if ( !strcmp(ArgList, "TRUE") )
            {
              *(_DWORD *)a2 = LODWORD(v29) | 0x8000000;
              *v6 |= 0x20u;
              v30 = 0;
              if ( *((int *)a2 + 90) > 0 )
              {
                v31 = 0;
                do
                {
                  *(_DWORD *)(v31 + *((_DWORD *)a2 + 91)) |= 0x400000u;
                  ++v30;
                  v31 += 108;
                }
                while ( v30 < *((_DWORD *)a2 + 90) );
              }
            }
            else
            {
              *(_DWORD *)a2 = LODWORD(v29) & 0xF7FFFFFF;
              *v6 &= ~0x20u;
              v32 = 0;
              if ( *((int *)a2 + 90) > 0 )
              {
                v33 = 0;
                do
                {
                  *(_DWORD *)(v33 + *((_DWORD *)a2 + 91)) &= ~0x400000u;
                  ++v32;
                  v33 += 108;
                }
                while ( v32 < *((_DWORD *)a2 + 90) );
              }
            }
          }
          if ( v52 )
          {
            sub_5EC660(a2);
            sub_5DB7B0(v6, a2);
          }
        }
        else
        {
          v34 = sub_5DF630((int)&off_6F1B20, (int)&v56, (int)&v57, (int)&v55, 0);
          v35 = v56;
          v36 = v57;
          if ( v34 )
            sub_5DB2B0(v6, v56, v57, v55, v59, v58, v60);
          if ( sub_5DF630((int)"ORIENT", (int)&v59, (int)&v58, (int)&v60, 0) )
            sub_5DB2B0(v6, v35, v36, v55, v59, v58, v60);
          if ( sub_5DF240((int)a5, "MOVEABLE", ArgList, 0, 0, 0, 0, 0, 0, 0) )
          {
            v37 = *v6;
            if ( !strcmp(ArgList, "TRUE") )
              v38 = v37 | 0x10;
            else
              v38 = v37 & 0xFFFFFFEF;
            *v6 = v38;
          }
          a2 = (float *)a5;
          if ( sub_5DF240((int)a5, "STAMP", ArgList, 0, 0, 0, 0, 0, 0, 0) )
          {
            v39 = *v6;
            if ( !strcmp(ArgList, "TRUE") )
              v40 = v39 | 0x110;
            else
              v40 = v39 & 0xFFFFFEFF;
            *v6 = v40;
          }
          if ( sub_5DF240((int)a5, "BILLBOARD", ArgList, 0, 0, 0, 0, 0, 0, 0) )
          {
            v41 = *v6;
            if ( !strcmp(ArgList, "TRUE") )
              v42 = v41 | 0x2010;
            else
              v42 = v41 & 0xFFFFDFFF;
            *v6 = v42;
          }
          if ( sub_5DF240((int)a5, "RENDER", ArgList, 0, 0, 0, 0, 0, 0, 0) )
          {
            v43 = *v6;
            if ( !strcmp(ArgList, "TRUE") )
              v44 = v43 & 0xFFFFFFFB;
            else
              v44 = v43 | 4;
            *v6 = v44;
          }
          if ( sub_5DF630((int)"REFLECTPLANE", (int)&v56, (int)&v57, (int)&v55, (int)&v69) )
            sub_5DB3C0((float *)v6, *(float *)&v56, *(float *)&v57, *(float *)&v55, v69);
          if ( sub_5DEF70() )
          {
            v65 = (char *)(a5[515] + 1);
            v54 = strtol(v65, &v65, 10);
            v62 = v54;
          }
          if ( sub_5DEF70() )
          {
            v66 = (char *)(a5[515] + 1);
            v54 = strtol(v66, &v66, 10);
            sub_5DB5B0(v6, v54, 2048);
          }
          if ( sub_5DEF70() )
          {
            v63 = (char *)(a5[515] + 1);
            v54 = strtol(v63, &v63, 10);
            sub_5DB5B0(v6, v54, 4096);
          }
          if ( sub_5DF240((int)a5, "ACTOR", ArgList, 0, 0, 0, 0, 0, 0, 0) )
            sub_5FE010((int)a1, (int)v6, (char)ArgList);
          if ( sub_5DF240((int)a5, "RESPONSE", ArgList, v74, 0, 0, 0, 0, 0, 0) )
            sub_5FE2C0((int)a1, (int)v6, (char)ArgList, (char)v74);
        }
      }
      if ( sub_5DF750(a5) == 1 )
        break;
    }
    if ( v52 && !v6[136] )
    {
      sub_5DBB20();
LABEL_163:
      sub_5DBA90(v6);
      j__free(v6);
      return 0;
    }
  }
  v45 = (int *)v6[133];
  v6[135] = (int)v45;
  if ( v45 )
  {
    v46 = *v45;
    if ( v46 )
    {
      v47 = v62;
      do
      {
        *(_DWORD *)(v46 + 248) = v47;
        v48 = v6[135];
        if ( !v48 )
          break;
        v49 = *(int **)(v48 + 4);
        v6[135] = (int)v49;
        if ( !v49 )
          break;
        v46 = *v49;
      }
      while ( v46 );
    }
  }
  if ( a4 )
    sub_5DAC60(a4, (unsigned int *)v6, 0);
  else
    sub_5DB5F0(v6);
  if ( !v6[156] )
  {
    v50 = (_DWORD *)v6[157];
    v6[159] = (int)v50;
    if ( v50 )
    {
      if ( *v50 )
        *v6 |= 8u;
    }
  }
  return 0;
}
