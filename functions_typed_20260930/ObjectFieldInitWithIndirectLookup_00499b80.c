int __thiscall sub_499B80(_DWORD *this, int a2)
{
  int result; // eax
  int v3; // edx

  result = a2;
  v3 = 0;
  this[8] = a2;
  *this = 0;
  this[2] = 0;
  if ( a2 )
  {
    this[1] = *(_DWORD *)(*(_DWORD *)(a2 + 12) + 28);
    result = *(_DWORD *)(a2 + 12);
    v3 = *(_DWORD *)(result + 32);
  }
  else
  {
    this[1] = 0;
  }
  this[3] = v3;
  return result;
}

