char __thiscall sub_4B87C0(int this)
{
  bool *v3; // edi
  int v4; // esi
  int v5; // ebp
  double v6; // st7
  float v7; // [esp+0h] [ebp-18h]
  int *v8; // [esp+8h] [ebp-10h]
  _DWORD *v9; // [esp+Ch] [ebp-Ch]
  float v10; // [esp+Ch] [ebp-Ch]
  int v11; // [esp+14h] [ebp-4h] BYREF

  QueuePop((int *)this);
  if ( *(float *)(this + 3892) - *(float *)(this + 3888) <= 0.0 )
    return 0;
  *(_DWORD *)(this + 3904) = ResourceLookupDispatcher(this + 1764);
  *(_BYTE *)(this + 3969) = 1;
  v11 = dword_5C329C;
  if ( dword_5C329C > 0 )
  {
    v9 = (_DWORD *)(this + 1844);
    v3 = (bool *)(this + 2364);
    v8 = dword_7C54F0;
    do
    {
      v4 = *v8;
      v5 = *v8 + 1776;
      MultiObjectRemove(*(float *)(this + 3888));
      EffectDataTableInitialization(v5);
      *v9 = *(_DWORD *)(v4 + 13000);
      *(v3 - 104) = *(_BYTE *)(v4 + 4189);
      *v3 = (*(_DWORD *)(v4 + 18620) & 2) != 0;
      SessionStateTransition(3, 0);
      ++v8;
      ++v3;
      ++v9;
    }
    while ( (int)&v3[-2364 - this] < v11 );
  }
  v7 = dbl_8AFEA0;
  AngleClampWrap(this, v7);
  ConditionalIndexSetter(0);
  *(_BYTE *)(this + 3968) = 1;
  v10 = 0.0;
  ReciprocalWithSignCheck((int)&flt_5EA4E8, 0.75);
  if ( 0.0 < 0.75 )
  {
    do
    {
      v11 = 1;
      StateTriggerCheck(&v11);
      v6 = dbl_8AFE90 + v10;
      v10 = v6;
    }
    while ( v6 < 0.75 );
  }
  return 1;
}

