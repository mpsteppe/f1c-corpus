int __cdecl sub_587ECE(unsigned __int8 *a1)
{
  int v3; // esi
  unsigned __int8 *v4; // edi
  int v5; // ebp
  int v6; // ebx
  int result; // eax

  while ( cbMultiByte <= 1 ? off_5E69C8[0][*a1] & 8 : sub_58C674(*a1, 8) )
    ++a1;
  v3 = *a1;
  v4 = a1 + 1;
  v5 = v3;
  if ( v3 == 45 || v3 == 43 )
    v3 = *v4++;
  v6 = 0;
  while ( cbMultiByte <= 1 ? off_5E69C8[0][v3] & 4 : sub_58C674(v3, 4) )
  {
    v6 = v3 + 10 * v6 - 48;
    v3 = *v4++;
  }
  result = v6;
  if ( v5 == 45 )
    return -v6;
  return result;
}
