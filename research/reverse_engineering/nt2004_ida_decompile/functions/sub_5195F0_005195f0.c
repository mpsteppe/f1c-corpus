void __thiscall sub_5195F0(int this)
{
  _DWORD *v2; // edi

  v2 = (_DWORD *)(this + 1808);
  sub_50AEE0((_DWORD *)(this + 1808), this + 3364);
  sub_50AEE0(v2, (int)(v2 + 406));
  sub_4C0B10((_DWORD *)(this + 16504), 0);
  if ( *(_DWORD *)(this + 19720) == 1 )
    *(_DWORD *)(this + 19720) = 0;
  if ( *(float *)(this + 18952) != *(float *)(this + 18964) )
    *(float *)(this + 18952) = (*(float *)(this + 18964) + *(float *)(this + 18952)) * 0.5;
  if ( *(_DWORD *)(this + 3432) && !*(_BYTE *)(this + 3496) )
    *(_DWORD *)(this + 18956) = *(_DWORD *)(this + 18972);
  else
    *(_DWORD *)(this + 18956) = *(_DWORD *)(this + 18968);
  sub_513830(this, 0);
  if ( !*(_DWORD *)(this + 16500) )
    sub_441DD0((int)&dbl_75E930);
}
