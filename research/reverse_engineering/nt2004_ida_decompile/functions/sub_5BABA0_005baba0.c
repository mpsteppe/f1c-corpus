signed int __fastcall sub_5BABA0(int a1, const char *a2)
{
  int v3; // edi
  signed int result; // eax

  v3 = *(_DWORD *)(a1 + 2048);
  result = strlen(a2) + 1;
  if ( result > 2048 - v3 )
    result = 2048 - v3;
  if ( result )
  {
    qmemcpy((void *)(a1 + *(_DWORD *)(a1 + 2048)), a2, result);
    result += *(_DWORD *)(a1 + 2048);
    *(_DWORD *)(a1 + 2048) = result;
    *(_BYTE *)(result + a1 - 1) = 0;
  }
  return result;
}
