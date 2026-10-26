int __stdcall sub_4EA1D0(int a1, int a2, const char *a3, int a4, const char *a5, const char *a6)
{
  int result; // eax
  char *v7; // eax
  int v8; // eax
  const CHAR *v9; // eax
  char *v10; // edi
  int v12; // eax
  int v13; // eax
  int v14; // ebx
  int v15; // eax
  void *Block; // [esp+0h] [ebp-128h]
  int v17; // [esp+4h] [ebp-124h]
  int v18; // [esp+Ch] [ebp-11Ch]
  int v19; // [esp+20h] [ebp-108h] BYREF
  char v20; // [esp+27h] [ebp-101h] BYREF
  char String1[125]; // [esp+28h] [ebp-100h] BYREF
  __int16 v22; // [esp+A5h] [ebp-83h]
  char v23; // [esp+A7h] [ebp-81h]
  char Buffer[128]; // [esp+A8h] [ebp-80h] BYREF

  result = dword_FB1D04;
  if ( dword_FB1D04 )
  {
    memset(String1, 0, sizeof(String1));
    v22 = 0;
    v23 = 0;
    v7 = dword_B6F708;
    v19 = 0;
    if ( !dword_B6F708 )
      v7 = (char *)WindowName;
    v8 = sub_539670(v7);
    if ( v8 )
    {
      v9 = *(const CHAR **)(v8 + 32);
      if ( !v9 )
        v9 = WindowName;
      sub_630FE0(String1, v9, 127);
      v23 = 0;
      sub_40D7E0(String1);
      v10 = &v20;
      while ( *++v10 )
        ;
      strcpy(v10, "_CPIT.GTR");
    }
    if ( _stricmp(String1, WindowName) )
      sub_5EE940((int)&v19, (char)String1, 0);
    if ( !a2 )
      goto LABEL_22;
    sprintf(Buffer, "%s.TGA", a3);
    v12 = sub_5E9100(Buffer, 1);
    *(_DWORD *)a2 = v12;
    if ( v12 )
      goto LABEL_19;
    if ( a5 )
    {
      sprintf(&String1[120], "%s.TGA", a5);
      v13 = sub_5E9100(&String1[120], 1);
      *(_DWORD *)a2 = v13;
      if ( v13 )
        goto LABEL_19;
      if ( a6 )
      {
        sprintf(&String1[112], "%s.TGA", a6);
        *(_DWORD *)a2 = sub_5E9100(&String1[112], 1);
      }
    }
    if ( !*(_DWORD *)a2 )
    {
LABEL_22:
      result = (int)Block;
      if ( Block )
        return sub_5EEA30(dword_FB1CE0, Block, 0);
      return result;
    }
LABEL_19:
    v14 = *(_DWORD *)(*(_DWORD *)a2 + 4);
    v18 = *(_DWORD *)(*(_DWORD *)a2 + 8);
    sub_4E5C80();
    sub_4E5D20(a1, 0, 0, v14, v18, 1);
    v15 = sub_4E5CD0();
    if ( v15 )
      sub_4E5E60(
        a1,
        v14 / 2,
        v17 / 2,
        (unsigned __int64)((double)*(int *)(v15 + 4) * *(float *)(a4 + 8)),
        (unsigned __int64)((double)*(int *)(v15 + 8) * *(float *)(a4 + 12)),
        1);
    *(_DWORD *)(a1 + 20) = *(_DWORD *)(a4 + 16);
    *(_DWORD *)(a1 + 24) = *(_DWORD *)(a4 + 20);
    goto LABEL_22;
  }
  return result;
}
