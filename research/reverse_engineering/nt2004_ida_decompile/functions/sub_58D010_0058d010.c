int __cdecl sub_58D010(int a1)
{
  int v1; // edx
  int v2; // ecx
  int result; // eax
  _BYTE *v4; // ecx

  v1 = *(unsigned __int8 *)(a1 + 5);
  v2 = *(_BYTE *)(a1 + 4) & 0xF;
  result = ((v1 * (v2 + 2) + 15) & 0xFFFFFFFC) + a1;
  v4 = (_BYTE *)(result + 4 * v2);
  if ( *v4 )
  {
    result = (v1 + 7) / 8;
    if ( result >= 1 )
    {
      result = 0;
      memset(v4 + 1, 0, (v1 + 7) / 8);
    }
  }
  return result;
}
