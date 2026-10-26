int __usercall sub_413F90@<eax>(_DWORD *a1@<ecx>, _DWORD *a2@<esi>)
{
  int v3; // eax
  char *v4; // edi
  CHAR *v6; // eax
  int v7; // edx
  CHAR v8; // cl
  unsigned int v9; // eax
  char *v10; // edi
  int v12; // eax
  int v14; // [esp-4h] [ebp-210h]
  _DWORD *v15; // [esp+0h] [ebp-20Ch] BYREF
  char v16[7]; // [esp+4h] [ebp-208h] BYREF
  char v17; // [esp+Bh] [ebp-201h] BYREF
  _BYTE v18[512]; // [esp+Ch] [ebp-200h] BYREF

  if ( !a1[8] )
  {
    if ( operator new(0x54u) )
      v3 = sub_40E080();
    else
      v3 = 0;
    a1[8] = v3;
  }
  sub_501410(&byte_B6F530, v18, 512);
  v4 = (char *)&v15 + 3;
  while ( *++v4 )
    ;
  strcpy(v4, "carviews.cam");
  if ( (*(int (__thiscall **)(_DWORD, char *, int, _DWORD *))(*(_DWORD *)a1[8] + 4))(a1[8], v16, v14, v15) )
  {
    v6 = dword_91CB00;
    if ( !dword_91CB00 )
      v6 = (CHAR *)WindowName;
    v7 = v18 - v6;
    do
    {
      v8 = *v6;
      v6[v7] = *v6;
      ++v6;
    }
    while ( v8 );
    v9 = strlen(aDefviewsCam) + 1;
    v10 = &v17;
    while ( *++v10 )
      ;
    v15 = a2;
    qmemcpy(v10, aDefviewsCam, v9);
    v12 = (*(int (__thiscall **)(_DWORD, _BYTE *))(*(_DWORD *)a1[8] + 4))(a1[8], v18);
    a2 = v15;
    if ( v12 )
      sub_40F4E0((_DWORD *)a1[8]);
  }
  sub_413790(a1, a2);
  return 0;
}
