int __thiscall sub_5F5AD0(int this, int a2)
{
  double v3; // st7
  int v4; // eax
  double v5; // st7
  int result; // eax
  LARGE_INTEGER Frequency; // [esp+Ch] [ebp-8h] BYREF

  *(_DWORD *)this = a2;
  if ( a2 == 1 )
  {
    if ( QueryPerformanceFrequency(&Frequency) )
    {
      v3 = (double)Frequency.HighPart * 4294967296.0 + (double)Frequency.LowPart;
LABEL_6:
      *(double *)(this + 8) = 1.0 / v3;
    }
  }
  else if ( a2 == 2 )
  {
    v3 = (double)*((int *)dword_FB2774 + 66) * 1000000.0;
    goto LABEL_6;
  }
  sub_5F5760((double *)this, (LONG *)(this + 44), (DWORD *)(this + 40), 0);
  v4 = *(_DWORD *)(this + 40);
  v5 = *(double *)(this + 8) * 4294967296.0;
  *(_DWORD *)(this + 48) = v4;
  *(_DWORD *)(this + 64) = v4;
  *(double *)(this + 16) = v5;
  *(_DWORD *)(this + 88) = v4;
  result = *(_DWORD *)(this + 44);
  *(double *)(this + 24) = 0.0;
  *(_DWORD *)(this + 52) = result;
  *(_DWORD *)(this + 68) = result;
  *(_DWORD *)(this + 92) = result;
  *(_DWORD *)(this + 56) = 0;
  *(_DWORD *)(this + 60) = 0;
  return result;
}
