int __cdecl sub_50F632(_DWORD *a1, int a2, int a3)
{
  int v3; // edx
  int v4; // ecx
  _DWORD *v5; // eax
  int result; // eax

  a1[1] = 0;
  if ( a2 != 61 )
  {
    *(_DWORD *)(*a1 + 20) = 10;
    *(_DWORD *)(*a1 + 24) = 61;
    *(_DWORD *)(*a1 + 28) = a2;
    (*(void (__cdecl **)(_DWORD *))*a1)(a1);
  }
  if ( a3 != 424 )
  {
    *(_DWORD *)(*a1 + 20) = 19;
    *(_DWORD *)(*a1 + 24) = 424;
    *(_DWORD *)(*a1 + 28) = a3;
    (*(void (__cdecl **)(_DWORD *))*a1)(a1);
  }
  v3 = *a1;
  memset(a1, 0, 0x1A8u);
  *a1 = v3;
  *((_BYTE *)a1 + 12) = 1;
  RenderVTableObjectInit(a1);
  a1[2] = 0;
  a1[5] = 0;
  a1[36] = 0;
  a1[37] = 0;
  a1[38] = 0;
  a1[39] = 0;
  v4 = 4;
  v5 = a1 + 44;
  do
  {
    *(v5 - 4) = 0;
    *v5++ = 0;
    --v4;
  }
  while ( v4 );
  sub_5115EE(a1);
  result = DirectorCameraObjectSetup(a1);
  if ( byte_5D79DC == 2 )
  {
    result = EFLAGSRegisterCheck();
    byte_5D79DC = result;
  }
  a1[4] = 200;
  return result;
}
