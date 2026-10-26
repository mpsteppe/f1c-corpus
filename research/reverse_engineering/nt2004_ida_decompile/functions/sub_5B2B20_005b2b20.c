int __thiscall sub_5B2B20(_DWORD *this, const char *a2, _DWORD *a3, _DWORD *a4)
{
  float *v4; // ebx
  _DWORD *v6; // eax
  char *v7; // esi
  char *v8; // esi
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
  bool v19; // zf
  int v20; // ecx
  int v21; // ecx
  unsigned int v22; // ecx
  int v23; // ecx
  unsigned int v24; // ecx
  int v25; // ecx
  unsigned int v26; // ecx
  int v27; // ecx
  unsigned int v28; // ecx
  int v29; // ecx
  unsigned int v30; // ecx
  int v31; // eax
  char *v33; // [esp+10h] [ebp-348h]
  int v35; // [esp+18h] [ebp-340h] BYREF
  char *v36; // [esp+1Ch] [ebp-33Ch] BYREF
  int v37; // [esp+20h] [ebp-338h]
  int v38; // [esp+24h] [ebp-334h]
  int v39; // [esp+28h] [ebp-330h]
  int v40; // [esp+2Ch] [ebp-32Ch] BYREF
  float v41; // [esp+30h] [ebp-328h] BYREF
  float v42; // [esp+34h] [ebp-324h] BYREF
  int v43; // [esp+38h] [ebp-320h] BYREF
  int v44; // [esp+3Ch] [ebp-31Ch] BYREF
  int v45; // [esp+40h] [ebp-318h] BYREF
  float v46; // [esp+44h] [ebp-314h] BYREF
  int v47; // [esp+48h] [ebp-310h] BYREF
  float v48; // [esp+4Ch] [ebp-30Ch] BYREF
  float v49; // [esp+50h] [ebp-308h] BYREF
  int v50; // [esp+54h] [ebp-304h]
  char v51[256]; // [esp+58h] [ebp-300h] BYREF
  char String[256]; // [esp+158h] [ebp-200h] BYREF
  char v53[256]; // [esp+258h] [ebp-100h] BYREF

  v4 = 0;
  v37 = 0;
  v44 = 0;
  v39 = 0;
  v40 = 0;
  v50 = 0;
  v36 = 0;
  InterlockedDecrement(&dword_7E8E1C);
  sub_598180(0);
  v6 = operator new(0x240u);
  if ( v6 )
    v7 = (char *)sub_59D4D0(v6);
  else
    v7 = 0;
  v33 = v7;
  *((_DWORD *)v7 + 15) = 0;
  *((_DWORD *)v7 + 16) = a3;
  *((_DWORD *)v7 + 141) = this;
  v46 = 0.0;
  v49 = 0.0;
  v41 = 0.0;
  v43 = 0;
  v45 = 0;
  v47 = 0;
  v42 = -1.0;
  v48 = -1.0;
  if ( a3 )
    *((_DWORD *)v7 + 15) = 8;
  if ( sub_5B1A10(a4) == 1 )
  {
LABEL_125:
    v31 = *((_DWORD *)v7 + 129);
    if ( v31 )
    {
      do
      {
        *(_DWORD *)(v31 + 252) = *((_DWORD *)v7 + 20);
        v31 = *(_DWORD *)(v31 + 16);
      }
      while ( v31 );
      if ( a3 )
        sub_59E690(a3, v7, 0);
      else
        sub_5974A0(this, v7);
    }
    else
    {
      sub_59D650(v7);
      sub_59D5F0(v7);
      sub_5BE8AE();
    }
    if ( v39 )
      sub_59E170((int)v7, v47, v45, v43, v41, v49, v46);
    return 0;
  }
  while ( 1 )
  {
    if ( *a4 == 3 )
    {
LABEL_124:
      v7 = v33;
      goto LABEL_125;
    }
    if ( *a4 == 2 )
      goto LABEL_123;
    if ( sub_5B1EA0((int)a4, aVisgroups, &v44, 0, 0, 0) )
      break;
    v8 = v33;
LABEL_13:
    if ( sub_5B1DC0((int)a4, aInstance, String, 0) && sub_5B2B20(String, v8, a4) )
      return -1;
    if ( sub_5B1DC0((int)a4, aMeshfile, String, 0) )
    {
      if ( sub_59D610(v8, a2, (int)String) )
        return -1;
      v4 = (float *)*((_DWORD *)v8 + 129);
      for ( i = (float *)*((_DWORD *)v4 + 4); i; i = (float *)*((_DWORD *)i + 4) )
        v4 = i;
    }
    if ( sub_5B1DC0((int)a4, aAnimfile, String, 0) )
    {
      if ( sub_5ADC80(this, &v36, String, 0) == -1 )
        return -1;
      v38 = 0;
      if ( sub_5B1DC0((int)a4, aAutostart, v51, 0) && !strcmp(v51, aTrue) )
        v38 = 1;
      v4 = (float *)*((_DWORD *)v33 + 129);
      if ( v4 )
      {
        v10 = v38;
        while ( !sub_5AD950(v4, (int)v36) )
        {
          if ( v10 )
            sub_5ADB80(v4, v36 + 28);
          v4 = (float *)*((_DWORD *)v4 + 4);
          if ( !v4 )
            goto LABEL_34;
        }
        return -1;
      }
      if ( sub_59E7D0(v33, (int)v36) )
        return -1;
      if ( v38 )
        sub_5AD860(*((_DWORD *)v33 + 133));
    }
LABEL_34:
    if ( sub_5B1F50((int)a4, aLodin, &v42, 0, 0, 0) )
      sub_59BE80(v4, v42, -1.0);
    if ( sub_5B1F50((int)a4, aLodout, &v48, 0, 0, 0) )
      sub_59BE80(v4, -1.0, v48);
    if ( sub_5B1EA0((int)a4, aZbias, &v40, 0, 0, 0) )
      sub_59BEC0(v4, v40);
    if ( sub_5B1DC0((int)a4, aHattarget, v51, 0) )
    {
      v11 = *((_DWORD *)v4 + 5);
      if ( !strcmp(v51, aTrue) )
        v12 = v11 | 0x100;
      else
        v12 = v11 & 0xFFFFFEFF;
      *((_DWORD *)v4 + 5) = v12;
    }
    if ( sub_5B1DC0((int)a4, aColltarget, v51, 0) )
    {
      v13 = *((_DWORD *)v4 + 5);
      if ( !strcmp(v51, aTrue) )
        v14 = v13 | 0x40;
      else
        v14 = v13 & 0xFFFFFFBF;
      *((_DWORD *)v4 + 5) = v14;
    }
    if ( sub_5B1DC0((int)a4, aSpheretarget, v51, 0) )
    {
      v15 = *((_DWORD *)v4 + 5);
      if ( !strcmp(v51, aTrue) )
        v16 = v15 | 0x80;
      else
        v16 = v15 & 0xFFFFFF7F;
      *((_DWORD *)v4 + 5) = v16;
    }
    if ( sub_5B1DC0((int)a4, aZbuffer, v51, 0) )
    {
      v17 = *((_DWORD *)v4 + 5);
      if ( !strcmp(v51, aTrue) )
        v18 = v17 & 0xFFFFDFFF;
      else
        v18 = v17 | 0x2000;
      *((_DWORD *)v4 + 5) = v18;
    }
    if ( sub_5B1DC0((int)a4, aShadowcaster, v51, 0) && !strcmp(v51, aTrue) && !v37 )
    {
      if ( sub_59F020(v33, (int)v4, (int)a3) )
        return -1;
      v37 = 1;
    }
    if ( sub_5B1DC0((int)a4, aShadowobject, v51, 0) && !strcmp(v51, aTrue) && !v37 )
    {
      if ( sub_59F020(v33, (int)v4, (int)a3) )
        return -1;
      *((_DWORD *)v4 + 5) |= 0x2000000u;
      v37 = 1;
    }
    if ( sub_5B1DC0((int)a4, aShadowreceiver, v51, 0) )
    {
      if ( !strcmp(v51, aTrue) )
      {
        v19 = v50 == 0;
        *((_DWORD *)v4 + 5) |= 0x4000u;
        if ( v19 )
        {
          v20 = this[82] + 1;
          v50 = 1;
          this[82] = v20;
        }
      }
      else
      {
        *((_DWORD *)v4 + 5) &= ~0x4000u;
      }
    }
    if ( sub_5B1DC0((int)a4, aReflector, v51, 0) )
    {
      if ( !strcmp(v51, aTrue) )
      {
        *((_DWORD *)v4 + 5) |= 0x20000u;
        ++this[96];
      }
      else
      {
        *((_DWORD *)v4 + 5) &= ~0x20000u;
      }
    }
    if ( sub_5B1DC0((int)a4, aMorphtarget, v51, 0) && !strcmp(v51, aTrue) )
      *((_DWORD *)v4 + 5) |= 0x200000u;
    sub_5B1DC0((int)a4, aLightobject, v51, 0);
    if ( sub_5B1F50((int)a4, off_6110A4, (float *)&v47, (float *)&v45, (float *)&v43, 0) )
      v39 = 1;
    if ( sub_5B1F50((int)a4, aOrient, &v41, &v49, &v46, 0) )
      v39 = 1;
    if ( sub_5B1DC0((int)a4, aMoveable, v51, 0) )
    {
      v21 = *((_DWORD *)v33 + 15);
      if ( !strcmp(v51, aTrue) )
        v22 = v21 | 0x10;
      else
        v22 = v21 & 0xFFFFFFEF;
      *((_DWORD *)v33 + 15) = v22;
    }
    if ( sub_5B1DC0((int)a4, aStamp, v51, 0) )
    {
      v23 = *((_DWORD *)v33 + 15);
      if ( !strcmp(v51, aTrue) )
        v24 = v23 | 0x110;
      else
        v24 = v23 & 0xFFFFFEFF;
      *((_DWORD *)v33 + 15) = v24;
    }
    if ( sub_5B1DC0((int)a4, aBillboard, v51, 0) )
    {
      v25 = *((_DWORD *)v33 + 15);
      if ( !strcmp(v51, aTrue) )
        v26 = v25 | 0x2010;
      else
        v26 = v25 & 0xFFFFDFFF;
      *((_DWORD *)v33 + 15) = v26;
    }
    if ( sub_5B1DC0((int)a4, aRender, v51, 0) )
    {
      v27 = *((_DWORD *)v33 + 15);
      if ( !strcmp(v51, aTrue) )
        v28 = v27 & 0xFFFFFFFB;
      else
        v28 = v27 | 4;
      *((_DWORD *)v33 + 15) = v28;
    }
    if ( sub_5B1DC0((int)a4, aChange, v51, 0) )
    {
      v29 = *((_DWORD *)v33 + 15);
      if ( !strcmp(v51, aTrue) )
        v30 = v29 & 0xFFFFFDFF;
      else
        v30 = v29 | 0x200;
      *((_DWORD *)v33 + 15) = v30;
    }
    if ( sub_5B1EA0((int)a4, aSpecial1, &v35, 0, 0, 0) )
      sub_59EED0(v33, v35, 2048);
    if ( sub_5B1EA0((int)a4, aSpecial2, &v35, 0, 0, 0) )
      sub_59EED0(v33, v35, 4096);
    if ( sub_5B1EA0((int)a4, aPlanes, &v35, 0, 0, 0) )
      *((_DWORD *)v33 + 20) = v35;
    if ( sub_5B1DC0((int)a4, aActor, v51, 0) )
      sub_5B17B0(this, (int)v33, v51, 0);
    if ( sub_5B1DC0((int)a4, aHatactor, v51, 0) )
      sub_5B17B0(this, (int)v33, v51, 1);
    if ( sub_5B1DC0((int)a4, aResponse, v51, v53) )
      sub_5B1850(this, (int)v33, v51, v53);
LABEL_123:
    if ( sub_5B1A10(a4) == 1 )
      goto LABEL_124;
  }
  if ( (v44 & dword_7E8E10) == v44 )
  {
    v8 = v33;
    *((_DWORD *)v33 + 14) = v44;
    goto LABEL_13;
  }
  if ( sub_5B1A10(a4) != 1 )
  {
    while ( *a4 != 3 && sub_5B1A10(a4) != 1 )
      ;
  }
  sub_59D5F0(v33);
  sub_5BE8AE();
  return 0;
}
