int __thiscall sub_4E8C30(_DWORD *this, int a2)
{
  char *v2; // eax
  int v4; // edi
  int v5; // eax
  int v6; // ecx
  _DWORD *v7; // ebx
  int v8; // esi
  _DWORD *v9; // edi
  int v10; // edx
  int v11; // esi
  _DWORD *v12; // edi
  const char *v13; // ecx
  int v14; // eax
  const char *v15; // ecx
  int v16; // eax
  const char *v17; // ecx
  int v18; // eax
  const char *v19; // ecx
  int v20; // eax
  const char *v21; // ecx
  int v22; // eax
  const char *v23; // ecx
  int v24; // eax
  const char *v25; // ecx
  int v26; // eax
  const char *v27; // ecx
  char *v28; // eax
  int v29; // eax
  const CHAR *v30; // eax
  char *v31; // eax
  char *v32; // edi
  int v34; // ebx
  void *Block; // [esp+Ch] [ebp-208h] BYREF
  int v37; // [esp+10h] [ebp-204h]
  char v38[128]; // [esp+14h] [ebp-200h] BYREF
  char v39[127]; // [esp+94h] [ebp-180h] BYREF
  char v40; // [esp+113h] [ebp-101h] BYREF
  char String1[128]; // [esp+114h] [ebp-100h] BYREF
  char Buffer[128]; // [esp+194h] [ebp-80h] BYREF

  v2 = dword_B6F708;
  v37 = 0;
  if ( !dword_B6F708 )
    v2 = (char *)WindowName;
  v4 = sub_539670(v2);
  if ( !v4 )
    v4 = dword_BE1BD8;
  if ( !dword_FB1D04 )
    return 0;
  if ( a2 )
    sprintf(Buffer, "%s%d.TGA", off_75B27C[0], a2 + 1);
  else
    sprintf(Buffer, "%s.TGA", off_75B27C[0]);
  v5 = sub_5E9100(Buffer, 1);
  this[3] = v5;
  if ( v5 )
    v37 = 0;
  v6 = *(_DWORD *)(288 * a2 + v4 + 580);
  v7 = (_DWORD *)(288 * a2 + v4);
  this[14] = v6;
  this[85] = v7[146];
  this[86] = v7[147];
  v8 = 0;
  if ( v6 > 0 )
  {
    v9 = this + 15;
    do
    {
      if ( a2 )
        sprintf(v38, "RPMBAR%d_%d", v8, a2 + 1);
      else
        sprintf(v38, "RPMBAR%d", v8);
      *v9 = sub_5E9690(v38, 0, 0);
      ++v8;
      ++v9;
    }
    while ( v8 < this[14] );
  }
  v10 = v7[148];
  this[87] = v10;
  this[96] = v7[149];
  v11 = 0;
  this[97] = v7[150];
  if ( v10 > 0 )
  {
    v12 = this + 88;
    do
    {
      if ( a2 )
        sprintf(v38, "RPMLIGHT%d_%d", v11, a2 + 1);
      else
        sprintf(v38, "RPMLIGHT%d", v11);
      *v12 = sub_5E9690(v38, 0, 0);
      ++v11;
      ++v12;
    }
    while ( v11 < this[87] );
  }
  this[98] = sub_5DA9A0(v7 + 129, 0);
  qmemcpy(this + 99, v7 + 151, 0x28u);
  qmemcpy(this + 109, v7 + 161, 0x28u);
  qmemcpy(this + 119, v7 + 171, 0x28u);
  qmemcpy(this + 129, v7 + 181, 0x28u);
  if ( v7[191] == 7 )
  {
    this[139] = 1;
    this[140] = v7[192];
    this[141] = v7[193];
    this[142] = v7[194];
    this[143] = v7[195];
    this[144] = v7[196];
    this[145] = v7[197];
  }
  this[146] = v7[198];
  v13 = off_75B258[0];
  this[147] = v7[199];
  this[148] = v7[200];
  if ( a2 )
    sprintf(v38, "%s%d", v13, a2 + 1);
  else
    sprintf(v38, "%s", v13);
  v14 = sub_5E9690(v38, 0, 0);
  v15 = off_75B25C[0];
  this[6] = v14;
  if ( a2 )
    sprintf(v38, "%s%d", v15, a2 + 1);
  else
    sprintf(v38, "%s", v15);
  v16 = sub_5E9690(v38, 0, 0);
  v17 = off_75B260[0];
  this[7] = v16;
  if ( a2 )
    sprintf(v38, "%s%d", v17, a2 + 1);
  else
    sprintf(v38, "%s", v17);
  v18 = sub_5E9690(v38, 0, 0);
  v19 = off_75B264[0];
  this[8] = v18;
  if ( a2 )
    sprintf(v38, "%s%d", v19, a2 + 1);
  else
    sprintf(v38, "%s", v19);
  v20 = sub_5E9690(v38, 0, 0);
  v21 = off_75B268[0];
  this[9] = v20;
  if ( a2 )
    sprintf(v38, "%s%d", v21, a2 + 1);
  else
    sprintf(v38, "%s", v21);
  v22 = sub_5E9690(v38, 0, 0);
  v23 = off_75B26C[0];
  this[11] = v22;
  if ( a2 )
    sprintf(v38, "%s%d", v23, a2 + 1);
  else
    sprintf(v38, "%s", v23);
  v24 = sub_5E9690(v38, 0, 0);
  v25 = off_75B270[0];
  this[12] = v24;
  if ( a2 )
    sprintf(v38, "%s%d", v25, a2 + 1);
  else
    sprintf(v38, "%s", v25);
  v26 = sub_5E9690(v38, 0, 0);
  v27 = off_75B274[0];
  this[13] = v26;
  if ( a2 )
    sprintf(v38, "%s%d", v27, a2 + 1);
  else
    sprintf(v38, "%s", v27);
  this[10] = sub_5E9690(v38, 0, 0);
  v28 = dword_B6F708;
  Block = 0;
  if ( !dword_B6F708 )
    v28 = (char *)WindowName;
  v29 = sub_539670(v28);
  if ( v29 )
  {
    v30 = *(const CHAR **)(v29 + 32);
    if ( !v30 )
      v30 = WindowName;
    sub_630FE0(String1, v30, 127);
    String1[127] = 0;
    v31 = &String1[strlen(String1)];
    if ( v31 > String1 )
    {
      while ( *v31 != 46 )
      {
        if ( --v31 <= String1 )
          goto LABEL_59;
      }
      *v31 = 0;
    }
LABEL_59:
    v32 = &v40;
    while ( *++v32 )
      ;
    strcpy(v32, "_CPIT.GTR");
  }
  if ( _stricmp(String1, WindowName) )
    sub_5EE940((int)&Block, (char)String1, 0);
  if ( !Block )
    return v37;
  if ( a2 )
    sprintf(v39, "%s%d.BMP", off_75B254[0], a2 + 1);
  else
    sprintf(v39, "%s.BMP", off_75B254[0]);
  sub_5F0D70(dword_FB1CE0, v39, 16, this);
  v34 = 1;
  if ( *this )
    v34 = v37;
  if ( a2 )
    sprintf(v39, "%s%d.BMP", off_75B250[0], a2 + 1);
  else
    sprintf(v39, "%s.BMP", off_75B250[0]);
  sub_5F0D70(dword_FB1CE0, v39, 16, this + 1);
  if ( !this[1] )
    v34 = 1;
  if ( a2 )
    sprintf(v39, "%s%d.BMP", off_75B24C[0], a2 + 1);
  else
    sprintf(v39, "%s.BMP", off_75B24C[0]);
  sub_5F0D70(dword_FB1CE0, v39, 16, this + 2);
  if ( !this[2] )
    v34 = 1;
  if ( this[3] )
  {
    if ( a2 )
      sprintf(Buffer, "%s%d.TGA", off_75B27C[0], a2 + 1);
    else
      sprintf(Buffer, "%s.TGA", off_75B27C[0]);
    sub_5E7E80(dword_FB1CE0, (int)(this + 4), (char)Buffer, *(_DWORD *)(this[3] + 24), 1);
    if ( !this[4] )
      v34 = 1;
    if ( a2 )
      sprintf(Buffer, "%s%d.TGA", off_75B280[0], a2 + 1);
    else
      sprintf(Buffer, "%s.TGA", off_75B280[0]);
    sub_5E7E80(dword_FB1CE0, (int)(this + 5), (char)Buffer, *(_DWORD *)(this[3] + 24), 1);
    if ( !this[5] )
      v34 = 1;
  }
  sub_5EEA30(dword_FB1CE0, Block, 0);
  return v34;
}
