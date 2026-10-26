int __thiscall sub_4DB420(char *this)
{
  int result; // eax
  char *v2; // ecx
  int v3; // eax
  int v4; // esi

  result = 0;
  if ( this )
  {
    v2 = this - 1;
    if ( v2 )
    {
      if ( v2 != (char *)1 )
        return result;
      result = sub_587C03(24);
      if ( result )
      {
        *(_DWORD *)(result + 4) = 0;
        *(_BYTE *)(result + 8) = 0;
        *(_DWORD *)(result + 12) = 0;
        *(_DWORD *)(result + 16) = 0;
        *(_DWORD *)(result + 20) = -1;
        *(_DWORD *)result = &off_5AD0C0;
        return result;
      }
    }
    else
    {
      result = sub_587C03(24);
      if ( result )
      {
        *(_DWORD *)(result + 4) = 0;
        *(_BYTE *)(result + 8) = 0;
        *(_DWORD *)(result + 12) = 0;
        *(_DWORD *)(result + 16) = 0;
        *(_DWORD *)(result + 20) = -1;
        *(_DWORD *)result = &off_5AD0A4;
        return result;
      }
    }
  }
  else
  {
    v3 = sub_587C03(24);
    v4 = v3;
    if ( v3 )
    {
      *(_DWORD *)(v3 + 4) = 0;
      *(_BYTE *)(v3 + 8) = 0;
      *(_DWORD *)(v3 + 12) = 0;
      *(_DWORD *)(v3 + 16) = 0;
      *(_DWORD *)(v3 + 20) = -1;
      *(_DWORD *)v3 = &off_5AD088;
      sub_566650(aInstantReplay_0);
      return v4;
    }
  }
  return 0;
}
