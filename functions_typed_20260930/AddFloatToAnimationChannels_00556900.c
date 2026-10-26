int __thiscall sub_556900(_DWORD *this, float a2)
{
  int result; // eax
  int v3; // ecx

  for ( result = *(_DWORD *)(this[68] + 40); result; result = *(_DWORD *)(result + 92) )
  {
    v3 = *(_DWORD *)(result + 84);
    if ( (*(_DWORD *)(v3 + 24) & 0x400) != 0 )
      *(float *)(v3 + 56) = a2 + *(float *)(v3 + 56);
  }
  return result;
}

