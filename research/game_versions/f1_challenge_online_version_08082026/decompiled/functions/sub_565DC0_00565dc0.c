_DWORD *__thiscall sub_565DC0(_DWORD *this)
{
  int v2; // eax

  v2 = sub_587C03(548);
  if ( v2 )
  {
    *(_DWORD *)v2 = 0;
    *(_DWORD *)(v2 + 4) = 0;
    *(_DWORD *)(v2 + 8) = 0;
    *(_DWORD *)(v2 + 12) = 0;
    *(_BYTE *)(v2 + 16) = 0;
    *(_DWORD *)(v2 + 528) = 0;
    *(_DWORD *)(v2 + 532) = -1;
    *(_BYTE *)(v2 + 16) = 0;
    *(_BYTE *)(v2 + 536) = 0;
    *(_DWORD *)(v2 + 540) = 0;
    *(_DWORD *)(v2 + 544) = 0;
    *this = v2;
  }
  else
  {
    *this = 0;
  }
  return this;
}
