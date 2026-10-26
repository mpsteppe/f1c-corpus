int __thiscall sub_55A910(_DWORD *this, const char *a2, int a3, _DWORD *a4)
{
  float *v4; // ebx
  _DWORD *v5; // eax
  _DWORD *v6; // esi
  _DWORD *v7; // edi
  int v8; // esi
  float *i; // eax
  int v10; // esi
  int v11; // eax
  unsigned int v12; // eax
  int v13; // eax
  unsigned int v14; // eax
  int v15; // eax
  unsigned int v16; // eax
  int v17; // eax
  unsigned int v18; // eax
  int v19; // ecx
  unsigned int v20; // ecx
  int v21; // ecx
  unsigned int v22; // ecx
  int v23; // ecx
  unsigned int v24; // ecx
  int v25; // ecx
  unsigned int v26; // ecx
  int v27; // ecx
  unsigned int v28; // ecx
  int v29; // eax
  int v31; // [esp+10h] [ebp-340h]
  int v33; // [esp+18h] [ebp-338h] BYREF
  char *v34; // [esp+1Ch] [ebp-334h] BYREF
  int v35; // [esp+20h] [ebp-330h]
  int v36; // [esp+24h] [ebp-32Ch]
  int v37; // [esp+28h] [ebp-328h]
  float v38; // [esp+2Ch] [ebp-324h] BYREF
  int v39; // [esp+30h] [ebp-320h] BYREF
  float v40; // [esp+34h] [ebp-31Ch] BYREF
  int v41; // [esp+38h] [ebp-318h] BYREF
  float v42; // [esp+3Ch] [ebp-314h] BYREF
  int v43; // [esp+40h] [ebp-310h] BYREF
  float v44; // [esp+44h] [ebp-30Ch] BYREF
  float v45; // [esp+48h] [ebp-308h] BYREF
  int v46; // [esp+4Ch] [ebp-304h] BYREF
  char v47[256]; // [esp+50h] [ebp-300h] BYREF
  char v48[256]; // [esp+150h] [ebp-200h] BYREF
  char v49[256]; // [esp+250h] [ebp-100h] BYREF

  v4 = 0;
  v35 = 0;
  v46 = 0;
  v37 = 0;
  v34 = 0;
  InterlockedDecrement(&dword_8B8EE8);
  sub_545F50(0);
  v5 = (_DWORD *)sub_587C03(572);
  if ( v5 )
    v6 = sub_54A600(v5);
  else
    v6 = 0;
  v7 = (_DWORD *)a3;
  v31 = (int)v6;
  v6[15] = 0;
  v6[16] = a3;
  v42 = 0.0;
  v45 = 0.0;
  v44 = 0.0;
  v39 = 0;
  v41 = 0;
  v43 = 0;
  v40 = -1.0;
  v38 = -1.0;
  if ( a3 )
    v6[15] = 8;
  if ( sub_559A70(a4) == 1 )
  {
LABEL_122:
    v29 = v6[129];
    if ( v29 )
    {
      do
      {
        *(_DWORD *)(v29 + 252) = v6[20];
        v29 = *(_DWORD *)(v29 + 16);
      }
      while ( v29 );
      if ( v7 )
        sub_54BA00(v7, v6, 0);
      else
        sub_545250(this, v6);
    }
    else
    {
      sub_54A770(v6);
      sub_54A710();
      sub_587BCF(v6);
    }
    if ( v37 )
      sub_54B4D0((int)v6, v43, v41, v39, v44, v45, v42);
    return 0;
  }
  while ( 1 )
  {
    if ( *a4 == 3 )
    {
LABEL_121:
      v6 = (_DWORD *)v31;
      v7 = (_DWORD *)a3;
      goto LABEL_122;
    }
    if ( *a4 == 2 )
      goto LABEL_120;
    if ( sub_559F00(a4, (int)aVisgroups, &v46, 0, 0, 0) )
      break;
    v8 = v31;
LABEL_13:
    if ( sub_559E20((int)a4, (int)aInstance, v48, 0) && sub_55A910(v48, v8, a4) )
      return -1;
    if ( sub_559E20((int)a4, (int)aMeshfile, v48, 0) )
    {
      if ( sub_54A730((char *)v8, a2, (int)v48) )
        return -1;
      v4 = *(float **)(v8 + 516);
      for ( i = (float *)*((_DWORD *)v4 + 4); i; i = (float *)*((_DWORD *)i + 4) )
        v4 = i;
    }
    if ( sub_559E20((int)a4, (int)aAnimfile, v48, 0) )
    {
      if ( sub_5518A0(this, &v34, v48, 0) == -1 )
        return -1;
      v36 = 0;
      if ( sub_559E20((int)a4, (int)aAutostart, v47, 0) && !strcmp(v47, aTrue) )
        v36 = 1;
      v4 = *(float **)(v31 + 516);
      if ( v4 )
      {
        v10 = v36;
        while ( !sub_551560(v4, (int)v34) )
        {
          if ( v10 )
            sub_551790(v4, v34 + 28);
          v4 = (float *)*((_DWORD *)v4 + 4);
          if ( !v4 )
            goto LABEL_34;
        }
        return -1;
      }
      if ( sub_54BB40((_DWORD *)v31, (int)v34) )
        return -1;
      if ( v36 )
        sub_551480(*(_DWORD **)(v31 + 532));
    }
LABEL_34:
    if ( sub_559FB0(a4, (int)aLodin, &v40, 0, 0, 0) )
      sub_54D4E0(v4, v40, -1.0);
    if ( sub_559FB0(a4, (int)aLodout, &v38, 0, 0, 0) )
      sub_54D4E0(v4, -1.0, v38);
    if ( sub_559E20((int)a4, (int)aHattarget, v47, 0) )
    {
      v11 = *((_DWORD *)v4 + 5);
      if ( !strcmp(v47, aTrue) )
        v12 = v11 | 0x100;
      else
        v12 = v11 & 0xFFFFFEFF;
      *((_DWORD *)v4 + 5) = v12;
    }
    if ( sub_559E20((int)a4, (int)aColltarget, v47, 0) )
    {
      v13 = *((_DWORD *)v4 + 5);
      if ( !strcmp(v47, aTrue) )
        v14 = v13 | 0x40;
      else
        v14 = v13 & 0xFFFFFFBF;
      *((_DWORD *)v4 + 5) = v14;
    }
    if ( sub_559E20((int)a4, (int)aSpheretarget, v47, 0) )
    {
      v15 = *((_DWORD *)v4 + 5);
      if ( !strcmp(v47, aTrue) )
        v16 = v15 | 0x80;
      else
        v16 = v15 & 0xFFFFFF7F;
      *((_DWORD *)v4 + 5) = v16;
    }
    if ( sub_559E20((int)a4, (int)aZbuffer, v47, 0) )
    {
      v17 = *((_DWORD *)v4 + 5);
      if ( !strcmp(v47, aTrue) )
        v18 = v17 & 0xFFFFDFFF;
      else
        v18 = v17 | 0x2000;
      *((_DWORD *)v4 + 5) = v18;
    }
    if ( sub_559E20((int)a4, (int)aShadowcaster, v47, 0) && !strcmp(v47, aTrue) && !v35 )
    {
      if ( sub_545930(this, (int)v4, a3) )
        return -1;
      v35 = 1;
    }
    if ( sub_559E20((int)a4, (int)aShadowobject, v47, 0) && !strcmp(v47, aTrue) && !v35 )
    {
      if ( sub_545930(this, (int)v4, a3) )
        return -1;
      *((_DWORD *)v4 + 5) |= 0x2000000u;
      v35 = 1;
    }
    if ( sub_559E20((int)a4, (int)aShadowreceiver, v47, 0) )
    {
      if ( !strcmp(v47, aTrue) )
      {
        *((_DWORD *)v4 + 5) |= 0x4000u;
        ++this[79];
      }
      else
      {
        *((_DWORD *)v4 + 5) &= ~0x4000u;
      }
    }
    if ( sub_559E20((int)a4, (int)aReflector, v47, 0) )
    {
      if ( !strcmp(v47, aTrue) )
      {
        *((_DWORD *)v4 + 5) |= 0x20000u;
        ++this[93];
      }
      else
      {
        *((_DWORD *)v4 + 5) &= ~0x20000u;
      }
    }
    if ( sub_559E20((int)a4, (int)aMorphtarget, v47, 0) && !strcmp(v47, aTrue) )
      *((_DWORD *)v4 + 5) |= 0x200000u;
    sub_559E20((int)a4, (int)aLightobject, v47, 0);
    if ( sub_559FB0(a4, (int)&off_5DC230, (float *)&v43, (float *)&v41, (float *)&v39, 0) )
      v37 = 1;
    if ( sub_559FB0(a4, (int)aOrient, &v44, &v45, &v42, 0) )
      v37 = 1;
    if ( sub_559E20((int)a4, (int)aMoveable, v47, 0) )
    {
      v19 = *(_DWORD *)(v31 + 60);
      if ( !strcmp(v47, aTrue) )
        v20 = v19 | 0x10;
      else
        v20 = v19 & 0xFFFFFFEF;
      *(_DWORD *)(v31 + 60) = v20;
    }
    if ( sub_559E20((int)a4, (int)aStamp, v47, 0) )
    {
      v21 = *(_DWORD *)(v31 + 60);
      if ( !strcmp(v47, aTrue) )
        v22 = v21 | 0x110;
      else
        v22 = v21 & 0xFFFFFEFF;
      *(_DWORD *)(v31 + 60) = v22;
    }
    if ( sub_559E20((int)a4, (int)aBillboard, v47, 0) )
    {
      v23 = *(_DWORD *)(v31 + 60);
      if ( !strcmp(v47, aTrue) )
        v24 = v23 | 0x2010;
      else
        v24 = v23 & 0xFFFFDFFF;
      *(_DWORD *)(v31 + 60) = v24;
    }
    if ( sub_559E20((int)a4, (int)aRender, v47, 0) )
    {
      v25 = *(_DWORD *)(v31 + 60);
      if ( !strcmp(v47, aTrue) )
        v26 = v25 & 0xFFFFFFFB;
      else
        v26 = v25 | 4;
      *(_DWORD *)(v31 + 60) = v26;
    }
    if ( sub_559E20((int)a4, (int)aChange, v47, 0) )
    {
      v27 = *(_DWORD *)(v31 + 60);
      if ( !strcmp(v47, aTrue) )
        v28 = v27 & 0xFFFFFDFF;
      else
        v28 = v27 | 0x200;
      *(_DWORD *)(v31 + 60) = v28;
    }
    if ( sub_559F00(a4, (int)aSpecial1, &v33, 0, 0, 0) )
      sub_54C110((_DWORD *)v31, v33, 2048);
    if ( sub_559F00(a4, (int)aSpecial2, &v33, 0, 0, 0) )
      sub_54C110((_DWORD *)v31, v33, 4096);
    if ( sub_559F00(a4, (int)aPlanes, &v33, 0, 0, 0) )
      *(_DWORD *)(v31 + 80) = v33;
    if ( sub_559E20((int)a4, (int)aActor, v47, 0) )
      sub_559820(v31, v47, 0);
    if ( sub_559E20((int)a4, (int)aHatactor, v47, 0) )
      sub_559820(v31, v47, 1);
    if ( sub_559E20((int)a4, (int)aResponse, v47, v49) )
      sub_5598B0(v31, v47, v49);
LABEL_120:
    if ( sub_559A70(a4) == 1 )
      goto LABEL_121;
  }
  if ( (v46 & dword_8B8EE0) == v46 )
  {
    v8 = v31;
    *(_DWORD *)(v31 + 56) = v46;
    goto LABEL_13;
  }
  if ( sub_559A70(a4) != 1 )
  {
    while ( *a4 != 3 && sub_559A70(a4) != 1 )
      ;
  }
  sub_54A710();
  sub_587BCF((LPVOID)v31);
  return 0;
}
