int __thiscall sub_4AC330(_DWORD *this)
{
  int result; // eax
  int v2; // edx

  result = this[5];
  if ( result )
  {
    if ( *(_DWORD *)(result + 88) )
    {
      result = this[6];
      v2 = *(_DWORD *)(result + 92);
      this[6] = v2;
      *(_DWORD *)(v2 + 88) = 0;
      *(_DWORD *)(result + 88) = 0;
      *(_DWORD *)(result + 92) = 0;
    }
  }
  return result;
}
