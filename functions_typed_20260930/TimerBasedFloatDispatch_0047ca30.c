int __thiscall TimerBasedFloatDispatch(int *this)
{
  float v2; // [esp+0h] [ebp-8h]

  v2 = ShortComputation_89d0(this);
  CollisionSystemInit(v2);
  return 0;
}

