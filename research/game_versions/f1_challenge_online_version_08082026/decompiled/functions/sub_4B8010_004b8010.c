bool sub_4B8010()
{
  bool v0; // bl
  const CHAR *v1; // esi
  int v2; // eax
  bool v3; // bl
  LPCSTR lpFileName[2]; // [esp+8h] [ebp-8h] BYREF

  v0 = 0;
  lpFileName[0] = 0;
  lpFileName[1] = (LPCSTR)-1;
  sub_4B9830(lpFileName);
  v1 = lpFileName[0];
  if ( !lpFileName[0] )
    v1 = byte_5EA438;
  v2 = sub_587DB0(v1, aRb);
  if ( v2 )
  {
    sub_587D02(v2);
    sub_58BA36(v1, 128);
    v0 = sub_58986E(v1) == 0;
  }
  v3 = !v0;
  if ( lpFileName[0] )
    sub_587BCF((LPVOID)lpFileName[0]);
  return v3;
}
