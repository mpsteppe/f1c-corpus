char **sub_4203F0()
{
  char **result; // eax
  char **v1; // esi
  char *v2; // ecx
  int v3; // eax
  int v4; // esi
  int v5; // edi
  int v6; // eax
  int v7; // ebx
  int v8; // eax
  _DWORD v9[8]; // [esp+4h] [ebp-20h] BYREF

  result = (char **)BestLapEntrantFinder(0, 0);
  v1 = result;
  if ( result )
  {
    v2 = *result;
    if ( !*result )
      v2 = &byte_5EA438;
    v3 = BestLapEntrantFinder((int)v2, 1);
    v4 = (int)v1[102];
    v5 = *(_DWORD *)(v3 + 408);
    v6 = LinkedListDereference(&dword_7D2DB0);
    v7 = FlagsGetter(v6);
    v8 = LinkedListDereference(&dword_7D2DB0);
    result = (char **)(v5 + 10 * (SceneOrderReader(v8) - v7));
    if ( (int)result >= v4
      && ((int)result < v4 + 1
       || (int)result < v4 + 2
       || (int)result < v4 + 3
       || (int)result < v4 + 4
       || (int)result < v4 + 6) )
    {
      return (char **)StructInitWithSentinelValues(v9);
    }
  }
  return result;
}

