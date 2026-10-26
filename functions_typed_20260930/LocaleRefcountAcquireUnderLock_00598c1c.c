_DWORD *__thiscall sub_598C1C(_DWORD *this)
{
  _BYTE v3[4]; // [esp+4h] [ebp-4h] BYREF

  *this = sub_59AAB9();
  sub_59A54D(v3);
  CounterIncrementThreadSafe(dword_8D4650);
  sub_59A5E9(v3);
  return this;
}

