int __usercall sub_49D990@<eax>(int a1@<ecx>, int a2@<esi>)
{
  CHAR *v2; // eax
  int v3; // esi
  CHAR v4; // dl
  const char *v5; // eax
  const char *v6; // edx
  unsigned int v7; // eax
  char *v8; // edi
  char v11; // [esp-1h] [ebp-81h] BYREF
  _BYTE v12[128]; // [esp+0h] [ebp-80h] BYREF

  v2 = (CHAR *)dword_91CAD0;
  if ( !dword_91CAD0 )
    v2 = (CHAR *)WindowName;
  v11 = HIBYTE(a2);
  v3 = v12 - v2;
  do
  {
    v4 = *v2;
    v2[v3] = *v2;
    ++v2;
  }
  while ( v4 );
  v5 = *(const char **)(a1 + 168);
  if ( !v5 )
    v5 = WindowName;
  v6 = v5;
  v7 = strlen(v5) + 1;
  v8 = &v11;
  while ( *++v8 )
    ;
  qmemcpy(v8, v6, v7);
  sub_590B70(&unk_FB1E98, v12, 1);
  return 0;
}
