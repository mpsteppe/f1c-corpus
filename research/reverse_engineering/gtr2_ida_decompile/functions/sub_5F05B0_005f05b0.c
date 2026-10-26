int __thiscall sub_5F05B0(void *this, char *a2, int a3, int a4)
{
  int result; // eax

  result = sub_5F04C0(this, a2);
  if ( result )
  {
    *(_DWORD *)(result + 152) = a3;
    *(_DWORD *)(result + 156) = a4;
  }
  return result;
}
