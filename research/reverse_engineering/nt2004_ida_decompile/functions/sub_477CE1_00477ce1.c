int __usercall sub_477CE1@<eax>(_DWORD *a1@<ecx>, int _EDI@<edi>, int a3@<esi>, double a4@<st0>)
{
  int result; // eax
  int i; // esi
  _DWORD *v7; // ebx
  char v8; // al
  LPVOID *v9; // ebp
  int v10; // esi
  CHAR *v11; // eax
  char String[80]; // [esp+0h] [ebp-50h] BYREF

  __asm { rcr     byte ptr dword_76AD28[edi], 7Ch }
  *(_WORD *)(a3 - 62) = (__int16)a4;
  result = sub_49FEC0(a1);
  for ( i = a1[13]; i; result = sub_5BE8AE(v7) )
  {
    v7 = (_DWORD *)i;
    v8 = *(_BYTE *)(i + 8);
    i = *(_DWORD *)(i + 4);
    if ( v8 )
    {
      v9 = (LPVOID *)*v7;
      if ( *v7 )
      {
        if ( *v9 )
          sub_5BE8AE(*v9);
        sub_5BE8AE(v9);
      }
    }
  }
  v10 = 0;
  a1[13] = 0;
  a1[14] = 0;
  a1[15] = 0;
  for ( a1[16] = 0; v10 < dword_769E78; ++v10 )
  {
    v11 = sub_457C50(&ppvOut, v10);
    sub_49D5B0(v11, -1);
    sub_477BC0(v10, String, 1);
    result = dword_769E78;
  }
  return result;
}
