char __thiscall sub_4919C0(_DWORD *this, __int16 a2, __int16 a3, __int16 a4, __int16 a5)
{
  int v6; // edi
  _DWORD *v7; // esi
  char result; // al
  int v9; // eax

  v6 = sub_490940(a2, a3, a4, a5);
  v7 = (_DWORD *)(*this + 12);
  result = 0;
  if ( v6 )
  {
    v9 = sub_587C03(12);
    if ( v9 )
    {
      *(_DWORD *)v9 = v6;
      *(_DWORD *)(v9 + 4) = 0;
      *(_BYTE *)(v9 + 8) = 0;
    }
    else
    {
      v9 = 0;
    }
    if ( *v7 )
    {
      *(_DWORD *)(v7[1] + 4) = v9;
    }
    else
    {
      *v7 = v9;
      v7[2] = v9;
    }
    v7[1] = v9;
    ++v7[3];
    return 1;
  }
  return result;
}
