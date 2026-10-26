int __thiscall SeasonScoringInfoUpdater(_DWORD *this)
{
  int result; // eax
  int v3; // eax
  int v4; // ecx
  int v5; // edx
  int v6; // ebx
  int v7; // esi
  int v8; // edi
  _DWORD *v9; // eax
  unsigned __int8 *v10; // eax
  int v11; // [esp+8h] [ebp-4h]

  result = ScoringGateCheck();
  if ( !(_BYTE)result || dword_8AB6E4 == 2 )
    return result;
  v3 = dword_8AC490 + 396 * dword_8AC48C;
  if ( v3 )
    v4 = TrackSceneNodeAdd(this, v3 + 4);
  else
    v4 = v11;
  if ( !v4 )
    goto LABEL_11;
  *(_DWORD *)(v4 + 16) += *(_DWORD *)(dword_7C54E8 + 16444);
  v5 = dword_7C54E8;
  if ( *(float *)(dword_7C54E8 + 16540) > 0.0
    && (*(float *)(dword_7C54E8 + 16540) < (double)*(float *)(v4 + 20) || *(float *)(v4 + 20) <= 0.0) )
  {
    *(float *)(v4 + 20) = *(float *)(dword_7C54E8 + 16540);
LABEL_11:
    v5 = dword_7C54E8;
  }
  result = Accumulator(this, *(_DWORD *)(v5 + 16444));
  if ( dword_7C56A4 == 7 )
  {
    v6 = *(_DWORD *)(dword_7C54E8 + 16480);
    MovingAverageFilterWithClamp((int)this, v6);
    if ( v6 == 1 )
      SimpleCounterIncrement(this);
    result = dword_7D0410;
    if ( dword_7D0410 == 4 || dword_7D0410 == 3 )
    {
      v7 = dword_7C54E8;
      v8 = 0;
      if ( *(_DWORD *)(dword_7C54E8 + 16484) != 3
        && *(_DWORD *)(v7 + 16444) >= (int)CRTFtol((double)dword_8ACF8C * 0.89999998)
        && AudioChannelStop(dword_8AD3B4, aSeasonscoringi) )
      {
        v9 = (_DWORD *)NullCheckWrapper(v6 - 1);
        if ( v9 )
        {
          v10 = (unsigned __int8 *)DataEntryAccessor(v9);
          v8 = sub_587ECE(v10);
        }
      }
      return ArithmeticComparison_2c00(this, v8);
    }
  }
  return result;
}
