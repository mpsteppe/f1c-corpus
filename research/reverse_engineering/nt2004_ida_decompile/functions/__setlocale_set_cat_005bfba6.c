char *__cdecl _setlocale_set_cat(LPVOID lpMem, char *Destination)
{
  size_t v3; // eax
  char Str[132]; // [esp+Ch] [ebp-A4h] BYREF
  _BYTE v6[8]; // [esp+90h] [ebp-20h] BYREF
  int v7; // [esp+98h] [ebp-18h] BYREF
  int v8; // [esp+9Ch] [ebp-14h]
  _WORD Src[4]; // [esp+A0h] [ebp-10h] BYREF
  void *v10; // [esp+A8h] [ebp-8h]
  UINT v11; // [esp+ACh] [ebp-4h]
  char *lpMema; // [esp+B8h] [ebp+8h]
  char *Destinationa; // [esp+BCh] [ebp+Ch]

  if ( !_expandlocale(Destination, Str, Src, &v7) )
    return 0;
  v3 = strlen(Str);
  Destinationa = (char *)malloc(v3 + 1);
  if ( !Destinationa )
    return 0;
  lpMema = (&dword_6251B4)[3 * (_DWORD)lpMem];
  v8 = dword_7FF1E0[(_DWORD)lpMem];
  v10 = (void *)(6 * (_DWORD)lpMem + 8385060);
  memcpy_0(v6, v10, 6u);
  v11 = CodePage;
  (&dword_6251B4)[3 * (_DWORD)lpMem] = strcpy(Destinationa, Str);
  dword_7FF1E0[(_DWORD)lpMem] = Src[0];
  memcpy_0(v10, Src, 6u);
  if ( lpMem == (LPVOID)2 )
    CodePage = v7;
  if ( lpMem == (LPVOID)1 )
    dword_7FF1FC = v7;
  if ( (*(&funcs_5BFC77 + 3 * (_DWORD)lpMem))() )
  {
    (&dword_6251B4)[3 * (_DWORD)lpMem] = lpMema;
    sub_5C1B88(Destinationa);
    dword_7FF1E0[(_DWORD)lpMem] = v8;
    CodePage = v11;
    return 0;
  }
  if ( lpMema != (char *)&unk_6250A0 )
    sub_5C1B88(lpMema);
  return (&dword_6251B4)[3 * (_DWORD)lpMem];
}
