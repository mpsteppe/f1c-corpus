int __thiscall sub_5061D0(int *this, const char *a2, const char *ArgList, const char *a4, int a5, int a6)
{
  int v6; // ebx
  int v7; // esi
  int v8; // edx
  const char *v9; // ecx
  const char *v10; // eax
  char *v11; // edx
  char v12; // cl
  char *v13; // eax
  int i; // esi
  int v15; // eax
  int v18; // [esp+10h] [ebp-208h] BYREF
  int v19; // [esp+14h] [ebp-204h] BYREF
  char v20[253]; // [esp+18h] [ebp-200h] BYREF
  __int16 v21; // [esp+115h] [ebp-103h]
  char v22; // [esp+117h] [ebp-101h]
  char v23[253]; // [esp+118h] [ebp-100h] BYREF
  __int16 v24; // [esp+215h] [ebp-3h]
  char v25; // [esp+217h] [ebp-1h]

  v20[0] = byte_629120;
  memset(&v20[1], 0, 0xFCu);
  v21 = 0;
  v6 = 0;
  v18 = 0;
  v22 = 0;
  sub_506530(this);
  if ( !a2 || !ArgList || !a4 )
    return v6;
  if ( a6 )
    sub_5924D0(dword_7DA988, (int)&v18, a6);
  v7 = dword_7DA9B8;
  if ( dword_7DA9B8 )
  {
    if ( sub_597350(this, a2, ArgList, 16) )
    {
      sub_591C90(0, v20);
      if ( sub_500F90(&unk_7D7920, 1, aDDevNascar2004_23, 498) )
        sub_500FE0((int)&unk_7D7920, "Error loading animated instance %s: %s", ArgList, v20);
      goto LABEL_40;
    }
    v23[0] = byte_629120;
    memset(&v23[1], 0, 0xFCu);
    v8 = *this;
    v24 = 0;
    v19 = 0;
    v25 = 0;
    sub_5974A0(v8);
    if ( sub_596220(v7) )
    {
      if ( sub_500F90(&unk_7D7920, 1, aDDevNascar2004_23, 513) )
        sub_500FE0((int)&unk_7D7920, aErrorLoadingAn_0);
      goto LABEL_40;
    }
    if ( sub_5ADC80(&v19, a4, 1) == -1 )
    {
      sub_591C90(0, v20);
      if ( sub_500F90(&unk_7D7920, 1, aDDevNascar2004_23, 523) )
        sub_500FE0((int)&unk_7D7920, "Error loading animation file %s: %s", a4, v20);
      goto LABEL_40;
    }
    v9 = &a4[strlen(a4)];
    if ( v9 > a4 )
    {
      while ( *v9 != 92 )
      {
        if ( --v9 <= a4 )
          goto LABEL_21;
      }
      ++v9;
    }
LABEL_21:
    v10 = v9;
    v11 = (char *)(v23 - v9);
    do
    {
      v12 = *v10;
      v10[(_DWORD)v11] = *v10;
      ++v10;
    }
    while ( v12 );
    v13 = &v23[strlen(v23)];
    if ( v13 > v23 )
    {
      while ( *v13 != 46 )
      {
        if ( --v13 <= v23 )
          goto LABEL_28;
      }
      *v13 = 0;
    }
LABEL_28:
    for ( i = sub_59EFF0(0); i; i = *(_DWORD *)(i + 16) )
    {
      if ( sub_5AD950(v19) )
      {
        sub_591C90(0, v20);
        if ( sub_500F90(&unk_7D7920, 1, aDDevNascar2004_23, 540) )
          sub_500FE0((int)&unk_7D7920, "Error registering animation %s: %s", a4, v20);
        v6 = 1;
      }
    }
    if ( !sub_59EFF0(0) )
    {
      if ( sub_500F90(&unk_7D7920, 1, aDDevNascar2004_23, 549) )
        goto LABEL_39;
      goto LABEL_40;
    }
    v15 = sub_5ADC10(v23);
    this[1] = v15;
    if ( !v15 )
    {
      if ( sub_500F90(&unk_7D7920, 1, aDDevNascar2004_23, 559) )
LABEL_39:
        sub_500FE0((int)&unk_7D7920, "Error obtaining mesh animation for animated instance: %s", a2);
LABEL_40:
      v6 = 1;
    }
  }
  if ( v18 )
    sub_592750(v18);
  if ( v6 )
    sub_506530(this);
  return v6;
}
