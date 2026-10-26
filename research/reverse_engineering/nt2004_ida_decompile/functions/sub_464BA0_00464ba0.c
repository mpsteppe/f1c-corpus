int __thiscall sub_464BA0(int *this)
{
  int v1; // ecx
  int result; // eax

  v1 = *this;
  result = *(_DWORD *)(v1 + 640);
  if ( result >= 2 && result <= 3 )
    *(_DWORD *)(v1 + 640) = 0;
  return result;
}
