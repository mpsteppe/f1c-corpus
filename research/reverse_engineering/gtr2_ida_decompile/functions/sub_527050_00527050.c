_DWORD *__thiscall sub_527050(int this)
{
  _DWORD *result; // eax

  sub_526340();
  sub_526220();
  sub_525950((int *)(this + 1744));
  sub_526070();
  *(_BYTE *)(this + 1760) = 0;
  *(_DWORD *)(this + 2890596) = -1;
  *(_DWORD *)(this + 2890600) = -1;
  sub_617E70(this + 2892312);
  *(_DWORD *)(this + 2892392) = -23693671;
  *(_DWORD *)(this + 2892852) = 0;
  *(_DWORD *)(this + 2892856) = 0;
  *(_DWORD *)(this + 2892948) = 0;
  *(_DWORD *)(this + 2892952) = 0;
  *(_DWORD *)(this + 2892956) = 0;
  *(_DWORD *)(this + 2892972) = 5;
  result = sub_5267E0((_DWORD *)this);
  if ( *(_DWORD *)(this + 2892916) == 1 )
  {
    result = *(_DWORD **)(this + 2892932);
    *(_DWORD *)(this + 2892928) = 0;
    if ( result != (_DWORD *)10922 )
    {
      if ( result )
        j_j__free(*(void **)(this + 2892936));
      *(_DWORD *)(this + 2892932) = 10922;
      result = operator new(0x3FFF0u);
      *(_DWORD *)(this + 2892936) = result;
    }
  }
  return result;
}
