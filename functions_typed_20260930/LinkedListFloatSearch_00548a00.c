int __thiscall sub_548A00(_DWORD *this, float a2)
{
  int v2; // ecx

  v2 = this[11];
  if ( !v2 )
    return 0;
  while ( *(float *)(v2 + 8) != a2 )
  {
    v2 = *(_DWORD *)(v2 + 20);
    if ( !v2 )
      return 0;
  }
  return v2;
}

