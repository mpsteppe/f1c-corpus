int __cdecl sub_588C7A(LPVOID a1, LPVOID lpMem)
{
  int v3; // eax
  _BYTE v5[132]; // [esp+Ch] [ebp-A4h] BYREF
  _BYTE v6[8]; // [esp+90h] [ebp-20h] BYREF
  int v7; // [esp+98h] [ebp-18h] BYREF
  int v8; // [esp+9Ch] [ebp-14h]
  _WORD v9[4]; // [esp+A0h] [ebp-10h] BYREF
  int v10; // [esp+A8h] [ebp-8h]
  UINT v11; // [esp+ACh] [ebp-4h]
  void *v12; // [esp+B8h] [ebp+8h]
  void *lpMema; // [esp+BCh] [ebp+Ch]

  if ( !sub_588E4E(lpMem, v5, v9, &v7) )
    return 0;
  v3 = Strlen(v5);
  lpMema = (void *)MallocWrapperForNhMalloc(v3 + 1);
  if ( !lpMema )
    return 0;
  v12 = *(&dword_5E64F4 + 3 * (_DWORD)a1);
  v8 = dword_8D3F30[(_DWORD)a1];
  v10 = 6 * (_DWORD)a1 + 9256820;
  MemoryCopy_cc00(v6, v10, 6);
  v11 = CodePage;
  *(&dword_5E64F4 + 3 * (_DWORD)a1) = (LPVOID)sub_58FCA0(lpMema);
  dword_8D3F30[(_DWORD)a1] = v9[0];
  MemoryCopy_cc00(v10, v9, 6);
  if ( a1 == (LPVOID)2 )
    CodePage = v7;
  if ( a1 == (LPVOID)1 )
    dword_8D3F4C = v7;
  if ( (*(&funcs_588D4B + 3 * (_DWORD)a1))() )
  {
    *(&dword_5E64F4 + 3 * (_DWORD)a1) = v12;
    sub_58AA6F(lpMema);
    dword_8D3F30[(_DWORD)a1] = v8;
    CodePage = v11;
    return 0;
  }
  if ( v12 != &unk_5E63E0 )
    sub_58AA6F(v12);
  return (int)*(&dword_5E64F4 + 3 * (_DWORD)a1);
}
