int __fastcall sub_5BAB40(int a1, int a2)
{
  int result; // eax

  result = *(_DWORD *)(a1 + 256);
  if ( result < 254 && a2 >= 1 && a2 <= 254 )
  {
    *(_BYTE *)(result + a1) = a2;
    result = *(_DWORD *)(a1 + 256) + 1;
    *(_DWORD *)(a1 + 256) = result;
  }
  return result;
}
