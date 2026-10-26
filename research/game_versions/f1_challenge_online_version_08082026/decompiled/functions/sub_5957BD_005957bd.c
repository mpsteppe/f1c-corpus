int __cdecl sub_5957BD(_DWORD *a1)
{
  int v1; // eax
  int result; // eax

  ++dword_8D3EC8;
  v1 = sub_58A935(4096);
  a1[2] = v1;
  if ( v1 )
  {
    a1[3] |= 8u;
    a1[6] = 4096;
  }
  else
  {
    a1[3] |= 4u;
    a1[2] = a1 + 5;
    a1[6] = 2;
  }
  result = a1[2];
  a1[1] = 0;
  *a1 = result;
  return result;
}
