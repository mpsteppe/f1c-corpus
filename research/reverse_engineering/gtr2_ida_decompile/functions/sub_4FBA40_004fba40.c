int __thiscall sub_4FBA40(void *this, int *a2, char *String1, int a4, int a5)
{
  int v5; // ebp
  int v6; // ebx
  int v7; // eax
  int result; // eax
  char v9; // bl
  char *v10; // esi
  int v11; // eax
  const char *v12; // [esp-1Ch] [ebp-520h]
  _BYTE *v13; // [esp-18h] [ebp-51Ch]
  int v14; // [esp-14h] [ebp-518h]
  const char *v15; // [esp-10h] [ebp-514h]
  char *v16; // [esp-Ch] [ebp-510h]
  int v17; // [esp-8h] [ebp-50Ch]
  const char *v18; // [esp-4h] [ebp-508h]
  char v19[4]; // [esp+0h] [ebp-504h] BYREF
  float v20[2]; // [esp+4h] [ebp-500h] BYREF
  _BYTE v21[61]; // [esp+Ch] [ebp-4F8h] BYREF
  __int16 v22; // [esp+49h] [ebp-4BBh]
  char v23; // [esp+4Bh] [ebp-4B9h]
  char v24; // [esp+58h] [ebp-4ACh] BYREF
  char v25[12]; // [esp+98h] [ebp-46Ch] BYREF
  _BYTE v26[40]; // [esp+A4h] [ebp-460h] BYREF
  _BYTE v27[12]; // [esp+CCh] [ebp-438h] BYREF
  _BYTE v28[12]; // [esp+D8h] [ebp-42Ch] BYREF
  _BYTE v29[500]; // [esp+E4h] [ebp-420h] BYREF
  _BYTE v30[20]; // [esp+2D8h] [ebp-22Ch] BYREF
  int v31; // [esp+2ECh] [ebp-218h]
  char v32; // [esp+2F0h] [ebp-214h]
  int v33; // [esp+2F8h] [ebp-20Ch]
  _DWORD v34[2]; // [esp+2FCh] [ebp-208h] BYREF
  _DWORD v35[128]; // [esp+304h] [ebp-200h] BYREF

  *(_DWORD *)&v21[28] = this;
  if ( !_stricmp(String1, "LFTIRE") )
  {
    v5 = 0;
  }
  else if ( !_stricmp(String1, "RFTIRE") )
  {
    v5 = 1;
  }
  else if ( !_stricmp(String1, "LRTIRE") )
  {
    v5 = 2;
  }
  else
  {
    v5 = _stricmp(String1, "RRTIRE") != 0 ? -1 : 3;
  }
  v6 = (int)a2;
  memset(v35, 0, sizeof(v35));
  *(_DWORD *)v21 = 512;
  v31 = 0;
  v34[1] = 0;
  v33 = 0;
  v34[0] = 0;
  v7 = *a2;
  v32 = 1;
  result = (*(int (__thiscall **)(int *, _DWORD *, int))(v7 + 36))(a2, v35, 512);
  if ( result )
  {
    while ( 1 )
    {
      result = sub_612EB0(v29);
      if ( result )
        goto LABEL_25;
      if ( !strcmp((const char *)v34, "}") )
        return result;
      v20[0] = 0.0;
      *(float *)v19 = COERCE_FLOAT(v26);
      v18 = "INSTANCE";
      if ( sub_6137E0(v29) )
        sub_4FBA40(v6, v25, v35[126], v35[127]);
      if ( v5 == -1 )
        goto LABEL_25;
      v17 = 0;
      v16 = &v24;
      v15 = "MESHFILE";
      if ( !sub_6137E0(v28) )
        goto LABEL_25;
      v20[0] = -1.0;
      *(float *)v19 = -1.0;
      sub_6134B0("LODIN", (int)v20, 0, 0, 0, 0, 0, 0, 0);
      sub_6134B0("LODOUT", (int)v19, 0, 0, 0, 0, 0, 0, 0);
      if ( *(float *)&v35[124] < (double)v20[0] || *(float *)&v35[124] >= (double)*(float *)v19 )
        goto LABEL_25;
      memset(v21, 0, sizeof(v21));
      v14 = 0;
      v22 = 0;
      v13 = v21;
      v12 = "SHADOWOBJECT";
      v23 = 0;
      if ( !sub_6137E0(v27) || _stricmp(v19, "TRUE") )
        break;
      v9 = 1;
      if ( dword_B71278 >= 2 )
        goto LABEL_20;
LABEL_24:
      v6 = v35[118];
LABEL_25:
      result = (*(int (__thiscall **)(int, _BYTE *, int, const char *, _BYTE *, int, const char *, char *, int, const char *))(*(_DWORD *)v6 + 36))(
                 v6,
                 v30,
                 512,
                 v12,
                 v13,
                 v14,
                 v15,
                 v16,
                 v17,
                 v18);
      if ( !result )
        return result;
    }
    v9 = 0;
LABEL_20:
    v10 = (char *)operator new(0x88u);
    if ( v10 )
    {
      strcpy(v10, &v21[52]);
      if ( !sub_616480(v10, ".GMT") )
        strcat(v10, ".GMT");
      v11 = v35[120];
      v10[64] = 0;
      v10[128] = v9;
      *((_DWORD *)v10 + 33) = *(_DWORD *)(v11 + 4 * v5);
      *(_DWORD *)(v11 + 4 * v5) = v10;
    }
    goto LABEL_24;
  }
  return result;
}
