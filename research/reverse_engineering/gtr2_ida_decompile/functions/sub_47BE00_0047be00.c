int __usercall sub_47BE00@<eax>(int *a1@<ecx>, const char *a2@<ebx>)
{
  int result; // eax
  float v4; // [esp+0h] [ebp-8h]

  result = *(_DWORD *)(*a1 + 113328);
  if ( result )
  {
    sub_476C60();
    v4 = dbl_FB1D10;
    sub_47B550(*a1, a2, v4);
    result = *a1;
  }
  *(_BYTE *)(*a1 + 2112) = 0;
  return result;
}
