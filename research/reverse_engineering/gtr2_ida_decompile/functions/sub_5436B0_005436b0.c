bool __thiscall sub_5436B0(int this, int a2)
{
  int v3; // edi
  int v4; // esi

  if ( *(_DWORD *)(this + 4) != *(_DWORD *)(a2 + 4)
    || sub_542540((float *)(this + 12), (float *)(a2 + 12))
    || sub_542540((float *)(this + 24), (float *)(a2 + 24))
    || sub_542540((float *)(this + 36), (float *)(a2 + 36))
    || *(float *)(this + 76) != *(float *)(a2 + 76)
    || *(float *)(this + 80) != *(float *)(a2 + 80)
    || *(float *)(this + 84) != *(float *)(a2 + 84)
    || *(float *)(this + 48) != *(float *)(a2 + 48)
    || *(float *)(this + 52) != *(float *)(a2 + 52)
    || *(float *)(this + 56) != *(float *)(a2 + 56)
    || *(float *)(this + 60) != *(float *)(a2 + 60) )
  {
    return 0;
  }
  v3 = *(_DWORD *)(a2 + 88);
  v4 = *(_DWORD *)(this + 88);
  return *(_DWORD *)v4 == *(_DWORD *)v3
      && !strcmp((const char *)(v4 + 56), (const char *)(v3 + 56))
      && *(_DWORD *)(v4 + 312) == *(_DWORD *)(v3 + 312)
      && *(_DWORD *)(v4 + 316) == *(_DWORD *)(v3 + 316)
      && *(_DWORD *)(v4 + 320) == *(_DWORD *)(v3 + 320)
      && *(_DWORD *)(v4 + 328) == *(_DWORD *)(v3 + 328)
      && *(_DWORD *)(v4 + 332) == *(_DWORD *)(v3 + 332)
      && *(_DWORD *)(v4 + 336) == *(_DWORD *)(v3 + 336)
      && !strcmp((const char *)(v4 + 340), (const char *)(v3 + 340))
      && !strcmp((const char *)(v4 + 372), (const char *)(v3 + 372));
}
