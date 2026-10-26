int __thiscall sub_4F6B60(_DWORD *this)
{
  int result; // eax
  int v3; // edi
  int v4; // ebx

  result = this[4];
  v3 = 0;
  if ( result > 0 )
  {
    v4 = 0;
    do
    {
      sub_4F2B80((_DWORD *)(v4 + this[5]));
      result = this[4];
      ++v3;
      v4 += 116;
    }
    while ( v3 < result );
  }
  return result;
}
