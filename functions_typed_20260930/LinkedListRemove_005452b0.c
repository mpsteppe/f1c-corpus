int __thiscall sub_5452B0(_DWORD *this, int a2)
{
  int result; // eax
  int v3; // edx
  int v4; // edx

  result = a2;
  v3 = *(_DWORD *)(a2 + 72);
  if ( v3 )
    *(_DWORD *)(v3 + 76) = *(_DWORD *)(a2 + 76);
  v4 = *(_DWORD *)(a2 + 76);
  if ( v4 )
    *(_DWORD *)(v4 + 72) = *(_DWORD *)(a2 + 72);
  if ( this[66] == a2 )
  {
    result = *(_DWORD *)(a2 + 76);
    this[66] = result;
  }
  return result;
}

