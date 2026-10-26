bool sub_49BAD0()
{
  float v1; // [esp+4h] [ebp-4h]

  v1 = DistanceProjectionCalc(dword_7C54E0 + 12);
  return RingBufferAccessWithWrap(v1) == 2 || IndexedFloatArrayLookup(v1) == 2;
}

