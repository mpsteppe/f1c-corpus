int __fastcall sub_5BC0E0(int a1, char a2)
{
  int result; // eax

  result = *(_DWORD *)(a1 + 60);
  if ( result < 20 )
  {
    *(_BYTE *)(result + a1 + 40) = a2;
    result = *(_DWORD *)(a1 + 60) + 1;
    *(_DWORD *)(a1 + 60) = result;
  }
  return result;
}
