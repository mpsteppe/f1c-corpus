int __thiscall sub_562F30(_DWORD *this, int a2)
{
  char *v2; // eax
  int v3; // eax
  const CHAR *v4; // eax
  char *v5; // eax
  char *v6; // edi
  const char *v8; // ecx
  const char *v9; // eax
  int *v10; // edi
  const char *v11; // ecx
  const char *v12; // eax
  const char *v13; // ecx
  const char *v14; // eax
  const char *v15; // ecx
  const char *v16; // eax
  const char *v17; // ecx
  const char *v18; // eax
  _DWORD *v19; // eax
  char *v20; // eax
  const char *v21; // ecx
  const char *v22; // eax
  int result; // eax
  const char *v24; // ecx
  const char *v25; // eax
  const char *v26; // ecx
  const char *v27; // eax
  float v28; // [esp+24h] [ebp-124h]
  void *Block; // [esp+3Ch] [ebp-10Ch] BYREF
  void *v30; // [esp+40h] [ebp-108h] BYREF
  _DWORD *v31; // [esp+44h] [ebp-104h]
  char v32[127]; // [esp+48h] [ebp-100h] BYREF
  char v33; // [esp+C7h] [ebp-81h] BYREF
  char Buffer[125]; // [esp+C8h] [ebp-80h] BYREF
  __int16 v35; // [esp+145h] [ebp-3h]
  char v36; // [esp+147h] [ebp-1h]

  memset(Buffer, 0, sizeof(Buffer));
  v35 = 0;
  v36 = 0;
  v2 = dword_B6F708;
  v31 = this;
  v30 = 0;
  Block = 0;
  if ( !dword_B6F708 )
    v2 = (char *)WindowName;
  v3 = sub_539670(v2);
  if ( v3 )
  {
    v4 = *(const CHAR **)(v3 + 32);
    if ( !v4 )
      v4 = WindowName;
    sub_630FE0(Buffer, v4, 127);
    v36 = 0;
    v5 = &Buffer[strlen(Buffer)];
    if ( v5 > Buffer )
    {
      while ( *v5 != 46 )
      {
        if ( --v5 <= Buffer )
          goto LABEL_11;
      }
      *v5 = 0;
    }
LABEL_11:
    v6 = &v33;
    while ( *++v6 )
      ;
    strcpy(v6, "_CPIT.GTR");
    sub_5EE940((int)&v30, (char)Buffer, 0);
  }
  v8 = (const char *)dword_91CAE8;
  if ( !dword_91CAE8 )
    v8 = WindowName;
  v9 = *(const char **)dword_91CA70;
  if ( !*(_DWORD *)dword_91CA70 )
    v9 = WindowName;
  sprintf(Buffer, "%s%s%s", v9, v8, "STEX.GTR");
  sub_5EE940((int)&Block, (char)Buffer, 0);
  sub_561D80(a2);
  switch ( a2 )
  {
    case 1:
      v10 = &dword_FAE930;
      goto LABEL_58;
    case 2:
      v10 = &dword_FAE934;
      goto LABEL_58;
    case 3:
      v11 = (const char *)dword_91CAE8;
      v10 = &dword_FAE938;
      if ( !dword_91CAE8 )
        v11 = WindowName;
      v12 = *(const char **)dword_91CA70;
      if ( !*(_DWORD *)dword_91CA70 )
        v12 = WindowName;
      sprintf(v32, "%s%s%s", v12, v11, "MOTECHUD.DDS");
      if ( sub_5E4940(dword_FB1CE0, &dword_FAE954, v32, 0, 0, 0, 1) )
      {
        sub_5E4BF0(dword_FB1CE0, dword_FAE954);
        dword_FAE954 = 0;
      }
      goto LABEL_58;
    case 4:
      v13 = (const char *)dword_91CAE8;
      v10 = &dword_FAE93C;
      if ( !dword_91CAE8 )
        v13 = WindowName;
      v14 = *(const char **)dword_91CA70;
      if ( !*(_DWORD *)dword_91CA70 )
        v14 = WindowName;
      sprintf(v32, "%s%s%s", v14, v13, "DIALHUD.DDS");
      if ( sub_5E4940(dword_FB1CE0, &dword_FAE958, v32, 0, 0, 0, 1) )
      {
        sub_5E4BF0(dword_FB1CE0, dword_FAE958);
        dword_FAE958 = 0;
      }
      goto LABEL_58;
    case 5:
      v10 = &dword_FAE944;
      goto LABEL_58;
    case 6:
      v15 = (const char *)dword_91CAE8;
      v10 = &dword_FAE940;
      if ( !dword_91CAE8 )
        v15 = WindowName;
      v16 = *(const char **)dword_91CA70;
      if ( !*(_DWORD *)dword_91CA70 )
        v16 = WindowName;
      sprintf(v32, "%s%s%s", v16, v15, "DIALHUDMIN.DDS");
      if ( sub_5E4940(dword_FB1CE0, &dword_FAE95C, v32, 0, 0, 0, 1) )
      {
        sub_5E4BF0(dword_FB1CE0, dword_FAE95C);
        dword_FAE95C = 0;
      }
      goto LABEL_58;
    case 7:
      v26 = (const char *)dword_91CAE8;
      v10 = &dword_FAE948;
      if ( !dword_91CAE8 )
        v26 = WindowName;
      v27 = *(const char **)dword_91CA70;
      if ( !*(_DWORD *)dword_91CA70 )
        v27 = WindowName;
      sprintf(v32, "%s%s%s", v27, v26, "PITMENU.DDS");
      if ( sub_5E4940(dword_FB1CE0, &dword_FAE974, v32, 0, 0, 0, 1) )
      {
        sub_5E4BF0(dword_FB1CE0, dword_FAE974);
        dword_FAE974 = 0;
      }
      goto LABEL_58;
    case 8:
      v10 = (int *)&flt_FAE950;
      goto LABEL_58;
    case 9:
      v28 = 1010.0;
      if ( sub_53A250(0) )
      {
        v19 = (_DWORD *)sub_616630("Pit Board Location");
        if ( v19 )
        {
          v20 = sub_48D380(v19);
          if ( v20 )
          {
            if ( !strcmp(v20, "Left") )
              v28 = 10.0;
          }
        }
      }
      v31[60] = (unsigned __int64)v28;
      v21 = (const char *)dword_91CAE8;
      if ( !dword_91CAE8 )
        v21 = WindowName;
      v22 = *(const char **)dword_91CA70;
      if ( !*(_DWORD *)dword_91CA70 )
        v22 = WindowName;
      sprintf(v32, "%s%s%s", v22, v21, "PITBOARD.DDS");
      if ( sub_5E4940(dword_FB1CE0, &dword_FAE964, v32, 0, 0, 0, 1) )
      {
        sub_5E4BF0(dword_FB1CE0, dword_FAE964);
        dword_FAE964 = 0;
      }
      v10 = (int *)1;
      goto LABEL_58;
    case 10:
      v24 = (const char *)dword_91CAE8;
      v10 = &dword_FAE94C;
      if ( !dword_91CAE8 )
        v24 = WindowName;
      v25 = *(const char **)dword_91CA70;
      if ( !*(_DWORD *)dword_91CA70 )
        v25 = WindowName;
      sprintf(v32, "%s%s%s", v25, v24, "ESCMENU.DDS");
      if ( sub_5E4940(dword_FB1CE0, &dword_FAE968, v32, 0, 0, 0, 1) )
      {
        sub_5E4BF0(dword_FB1CE0, dword_FAE968);
        dword_FAE968 = 0;
      }
      goto LABEL_58;
    case 11:
      v17 = (const char *)dword_91CAE8;
      v10 = &dword_FAE96C;
      if ( !dword_91CAE8 )
        v17 = WindowName;
      v18 = *(const char **)dword_91CA70;
      if ( !*(_DWORD *)dword_91CA70 )
        v18 = WindowName;
      sprintf(v32, "%s%s%s", v18, v17, "REPLAY.DDS");
      if ( sub_5E4940(dword_FB1CE0, &dword_FAE970, v32, 0, 0, 0, 1) )
      {
        sub_5E4BF0(dword_FB1CE0, dword_FAE970);
        dword_FAE970 = 0;
      }
LABEL_58:
      if ( *v10 )
        goto LABEL_73;
      result = off_16C933C(a2);
      break;
    default:
LABEL_73:
      if ( Block )
        sub_5EEA30(dword_FB1CE0, Block, 0);
      if ( v30 )
        sub_5EEA30(dword_FB1CE0, v30, 0);
      result = 1;
      break;
  }
  return result;
}
