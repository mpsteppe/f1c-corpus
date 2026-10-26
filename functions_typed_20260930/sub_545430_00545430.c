int __stdcall sub_545430(int *a1, int a2, int a3)
{
  int v3; // eax
  int v4; // esi

  v3 = OperatorNewNhMallocWrapper(112);
  if ( v3 && (v4 = StructInitWithFloatDefaults_d230(v3)) != 0 )
  {
    if ( StringCopyWithFlagUnion(a2, a3) )
    {
      return -1;
    }
    else
    {
      DrawableObjectNodeManager(v4, a3);
      if ( a1 )
        *a1 = v4;
      return 0;
    }
  }
  else
  {
    sub_53C590(-1, aCouldNotCreate);
    return -1;
  }
}

